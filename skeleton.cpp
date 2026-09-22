#include "skeleton.h"
#include "gamestate.h"
#include "util.h"
#include "box.h"
#include <sgg/graphics.h>
#include <chrono>

void Skeleton::init() {
    
    SETCOLOR(m_brush_skeleton.fill_color, 1.0f, 1.0f, 1.0f);
    m_brush_skeleton.fill_opacity = 1.0f;
    m_brush_skeleton.outline_opacity = 0.0f;

    loadAnimationsFramesS();
    setAnimationS("idle");
    animationTimerS.start();
}

void Skeleton::loadAnimationsFramesS() {
    Sanimations["idle"] = {
        "assets/Skeleton/Idle/tile000.png",
        "assets/Skeleton/Idle/tile001.png",
        "assets/Skeleton/Idle/tile002.png",
        "assets/Skeleton/Idle/tile003.png",
        "assets/Skeleton/Idle/tile004.png",
        "assets/Skeleton/Idle/tile005.png"
    };
    Sanimations["walking"] = {
        "assets/Skeleton/Walk/tile000.png",
        "assets/Skeleton/Walk/tile001.png",
        "assets/Skeleton/Walk/tile002.png",
        "assets/Skeleton/Walk/tile003.png"
    };
}

void Skeleton::setAnimationS(const std::string& animationName) {
    if (ScurrentAnimation != animationName && Sanimations.count(animationName)) {
        ScurrentAnimation = animationName;

        if (animationName == "idle") {
            animationTimerS = Timer(0.5f, Timer::TIMER_LOOPING);
        }
        else if (animationName == "walking") {
            animationTimerS = Timer(0.5f, Timer::TIMER_LOOPING);
        }

        animationTimerS.start();
    }
}


void Skeleton::updateAnimationS() {
    if (!ScurrentAnimation.empty() && Sanimations.count(ScurrentAnimation)) {
        const auto& frames = Sanimations[ScurrentAnimation];
        size_t frameCount = frames.size();

        if (frameCount > 0) {

            float normalizedTime = animationTimerS;

           currentFrameS = static_cast<int>(normalizedTime * frameCount) % frameCount;
        }
    }
}

void Skeleton::draw() {
    float x = m_pos_x + m_state->m_global_offset_x;
    float y = m_pos_y + m_state->m_global_offset_y;
    
    if (!ScurrentAnimation.empty() && Sanimations.count(ScurrentAnimation)) {
        const auto& frames = Sanimations[ScurrentAnimation];
        if (currentFrameS >= 0 && currentFrameS < frames.size()) {
            m_brush_skeleton.texture = frames[currentFrameS];
            graphics::drawRect(x, y, m_size, m_size, m_brush_skeleton);
        }
    }
}

void Skeleton::update(float dt) {
    float delta_time = dt / 1000.0f; // Convert to seconds

    float player_x = m_state->getPlayer()->m_pos_x;
    float player_y = m_state->getPlayer()->m_pos_y;

    float dx = fabs(player_x - m_pos_x);
    float dy = fabs(player_y - m_pos_y);
    
    if (dx <= m_detectionRange && dy <= m_detectionRange) {
        if (!m_playerDetected) {
            m_playerDetected = true;
            m_delayElapsed = false;
            m_detectionTime = std::chrono::steady_clock::now();
        }
    }
    else {
        if (!(ScurrentAnimation == "idle")) {
            setAnimationS("idle");
        }
        m_playerDetected = false;
        m_delayElapsed = false;
    }

    if (m_playerDetected && !m_delayElapsed) {
        auto now = std::chrono::steady_clock::now();
        auto elapsed = std::chrono::duration<float>(now - m_detectionTime).count();
        if (elapsed >= 0.2f) {
            m_delayElapsed = true;
        }
    }

    if (m_playerDetected && m_delayElapsed) {
        if (m_patrolLeft) {
            m_pos_x -= m_speed * delta_time;
            if (m_pos_x <= m_patrolStart) {
                m_patrolLeft = false;
            }
        }
        else {
            m_pos_x += m_speed * delta_time;
            if (m_pos_x >= m_patrolEnd) {
                m_patrolLeft = true;
            }
        }
        setAnimationS("walking");
    }

    updateAnimationS();
    GameObject::update(dt);
}
