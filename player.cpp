#include "player.h"
#include <sgg/graphics.h>
#include "gamestate.h"
#include "util.h"
#include "level.h"
#include "timer.h"
#include <chrono>

void Player::init() {
    m_pos_x = m_state->m_current_level->player_x;
    m_pos_y = m_state->m_current_level->player_y;
    m_width /= 2.0f;
    m_accel_vertical = m_state->m_current_level->m_accel_v;

    m_state->m_global_offset_x = m_state->getCanvasWidth() / 2.0f - m_pos_x;
    m_state->m_global_offset_y = m_state->getCanvasHeight() / 2.0f - m_pos_y + 1.0f;

    SETCOLOR(m_brush_player.fill_color, 1.0f, 1.0f, 1.0f);
    m_brush_player.fill_opacity = 1.0f;
    m_brush_player.outline_opacity = 0.0f;

    loadAnimationsFrames();
    setAnimation("idle");
    animationTimer.start();
}

void Player::loadAnimationsFrames() {
    animations["idle"] = {
        m_state->getFullAssetPath("diego-idle0.png"),
        m_state->getFullAssetPath("diego-idle1.png")
    };
    animations["idleback"] = {
        m_state->getFullAssetPath("diego-idleback0.png"),
        m_state->getFullAssetPath("diego-idleback1.png")
    };
    animations["walking"] = {
        m_state->getFullAssetPath("diego-walk0.png"),
        m_state->getFullAssetPath("diego-walk1.png"),
        m_state->getFullAssetPath("diego-walk2.png"),
        m_state->getFullAssetPath("diego-walk3.png"),
        m_state->getFullAssetPath("diego-walk4.png"),
        m_state->getFullAssetPath("diego-walk5.png")
    };
    animations["walkingback"] = {
        m_state->getFullAssetPath("diego-walkback0.png"),
        m_state->getFullAssetPath("diego-walkback1.png"),
        m_state->getFullAssetPath("diego-walkback2.png"),
        m_state->getFullAssetPath("diego-walkback3.png"),
        m_state->getFullAssetPath("diego-walkback4.png"),
        m_state->getFullAssetPath("diego-walkback5.png"),
    };
    animations["jumping"] = { //ousiastika ena icon apla gia na ta xoume ola sta animations 
        m_state->getFullAssetPath("diego-jump1.png")
    };
    animations["jumpingback"] = { //omoiws
        m_state->getFullAssetPath("diego-jumpback1.png")
    };
    animations["dead"] = {
        m_state->getFullAssetPath("diego-dead1.png"),
        m_state->getFullAssetPath("diego-dead2.png")
    };
}

void Player::setAnimation(const std::string& animationName) {
    if (currentAnimation != animationName && animations.count(animationName)) {
        currentAnimation = animationName;

        if (animationName == "idle") {
            animationTimer = Timer(2.0f, Timer::TIMER_LOOPING);
        }
        if (animationName == "idleback") {
            animationTimer = Timer(2.0f, Timer::TIMER_LOOPING);
        }
        else if (animationName == "walking") {
            animationTimer = Timer(0.5f, Timer::TIMER_LOOPING);
        }
        else if (animationName == "walkingback") {
            animationTimer = Timer(0.5f, Timer::TIMER_LOOPING);
        }
        else if (animationName == "dead") {
            animationTimer = Timer(1.0f, Timer::TIMER_LOOPING);
        }
        animationTimer.start();
    }
}


void Player::updateAnimation() {
    if (!currentAnimation.empty() && animations.count(currentAnimation)) {
        const auto& frames = animations[currentAnimation];
        size_t frameCount = frames.size();

        if (frameCount > 0) {
            float normalizedTime = animationTimer;

            currentFrame = static_cast<int>(normalizedTime * frameCount) % frameCount;
        }
    }
}

void Player::takeDamage() {
    auto now = std::chrono::steady_clock::now();
    if (!invulnerable || std::chrono::duration<float>(now - lastDamageTime).count() >= 1.0f) {
        graphics::playSound("assets\\oof.mp3", 1.0f);
        health -= 1;
        lastDamageTime = now;
        invulnerable = true;
    }
}

void Player::respawn() {
    isDead = false;
    m_pos_x = m_state->m_current_level->player_x;
    m_pos_y = m_state->m_current_level->player_y;
    m_vx = 0.0f;
    m_vy = 0.0f;
    health = 3;
    m_state->m_current_level->m_cherryCount = 0;
    m_state->m_current_level->loadLevelSpecificCherries();
}

void Player::draw() {
    if (!currentAnimation.empty() && animations.count(currentAnimation)) {
        const auto& frames = animations[currentAnimation];
        if (currentFrame >= 0 && currentFrame < frames.size()) {
            m_brush_player.texture = frames[currentFrame];
            if (!invulnerable && !isDead) {
                SETCOLOR(m_brush_player.fill_color, 1.0f, 1.0f, 1.0f);
            }
            else if (!isDead) {
                SETCOLOR(m_brush_player.fill_color, 1.0f, 0.0f, 0.0f);
            }
            graphics::drawRect(m_state->m_canvas_width / 2.0f, m_state->m_canvas_height / 2.0f + 1.0f, m_size * 1.35f, m_size * 1.35f, m_brush_player);
        }
    }
}

void Player::movePlayer(float dt) {
    ceilingCol = false;

    GameState::getInstance()->m_current_level->checkCollisions();
    
    float delta_time = dt / 1000.0f;

    float move = 0.0f;

    if (graphics::getKeyState(graphics::SCANCODE_A) && !isDead) {
        move -= 1.0f;
        setAnimation("walkingback");
    }
    if (graphics::getKeyState(graphics::SCANCODE_D) && !isDead) {
        move += 1.0f;
        setAnimation("walking");
    }

    m_vx = std::min(m_max_velocity, m_vx + delta_time * move * m_accel_horizontal);
    m_vx = std::max(-m_max_velocity, m_vx);
    m_vx -= 0.2f * m_vx / (0.1f + fabs(m_vx)); // epivradinsh

    if (fabs(m_vx) < 0.01f)
        m_vx = 0.0f;
    m_pos_x += delta_time * m_vx;

    //jump
    if (m_vy == 0.0f && !ceilingCol && !isDead)
        m_vy -= graphics::getKeyState(graphics::SCANCODE_W) ? m_accel_vertical : 0.0f;
    else if (!isDead) {
        if (currentAnimation == "walking" || currentAnimation == "idle") {
            setAnimation("jumping");
        }
        else if (currentAnimation == "walkingback" || currentAnimation == "idleback") {
            setAnimation("jumpingback");
        }
    }
    if (currentAnimation == "jumping" && graphics::getKeyState(graphics::SCANCODE_A)) {
        setAnimation("jumpingback");
    }
    else if (currentAnimation == "jumpingback" && graphics::getKeyState(graphics::SCANCODE_D)) {
        setAnimation("jumping");
    }
    
    m_vy += delta_time * m_gravity;

    m_pos_y += m_vy * delta_time;

    if (!graphics::getKeyState(graphics::SCANCODE_A) &&
        !graphics::getKeyState(graphics::SCANCODE_D) &&
        !graphics::getKeyState(graphics::SCANCODE_W) &&
        !ceilingCol && !isDead) {
        if (!(currentAnimation == "jumpingback") && (!(currentAnimation == "walkingback")) && !(currentAnimation == "idleback")) {
            setAnimation("idle");
        }
        else {
            setAnimation("idleback");
        }
    }
}

void Player::updateCooldown() {
    if (invulnerable) {
        auto now = std::chrono::steady_clock::now();
        if (std::chrono::duration<float>(now - lastDamageTime).count() >= 1.0f) {
            invulnerable = false;
        }
    }
}

void Player::update(float dt) {

    if (health <= 0) {
        isDead = true;
        if (!(currentAnimation == ("dead"))) {
            setAnimation("dead");
            SETCOLOR(m_brush_player.fill_color, 1.0f, 1.0f, 1.0f);
            m_brush_player.fill_opacity = 1.0f;
        }
    }
    
    movePlayer(dt);
    updateCooldown();
    updateAnimation();

    m_state->m_global_offset_x = m_state->getCanvasWidth() / 2.0f - m_pos_x;
    m_state->m_global_offset_y = m_state->getCanvasHeight() / 2.0f - m_pos_y + 1.0f;

    GameObject::update(dt);
}