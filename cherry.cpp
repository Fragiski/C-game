#include "cherry.h"
#include "box.h"
#include "gamestate.h" 

Cherry::Cherry(const Box& box)
    : Box(box), Cm_animationTimer(0.2f, Timer::TIMER_LOOPING) {
    loadCherryFrames();
}

void Cherry::loadCherryFrames() {

    Canimations["idle"] = {
            m_state->getFullAssetPath("cherry1.png"),
            m_state->getFullAssetPath("cherry2.png"),
            m_state->getFullAssetPath("cherry3.png"),
            m_state->getFullAssetPath("cherry4.png"),
            m_state->getFullAssetPath("cherry5.png"),
            m_state->getFullAssetPath("cherry6.png"),
            m_state->getFullAssetPath("cherry7.png")
    };

}

void Cherry::init() {

    m_brush_cherry.outline_opacity = 0.0f;
    setAnimation("idle");


    if (!Canimations["idle"].empty()) {
        m_brush_cherry.texture = Canimations["idle"][0];
    }

    Cm_animationTimer.start();
}

void Cherry::setAnimation(const std::string& animationName) {
    if (CcurrentAnimation != animationName && Canimations.count(animationName)) {
        CcurrentAnimation = animationName;

        if (animationName == "idle") {
            Cm_animationTimer = Timer(2.0f, Timer::TIMER_LOOPING);
        }

        Cm_animationTimer.start();
    }
}

void Cherry::updateAnimation() {
    if (!CcurrentAnimation.empty() && Canimations.count(CcurrentAnimation)) {
        const auto& frames = Canimations[CcurrentAnimation];
        size_t frameCount = frames.size();

        if (frameCount > 0) {
            float normalizedTime = Cm_animationTimer;

            Cm_currentFrame = static_cast<int>(normalizedTime * frameCount) % frameCount;
            m_brush_cherry.texture = frames[Cm_currentFrame];
        }
    }
}

void Cherry::draw() {
    float x = m_pos_x + m_state->m_global_offset_x;
    float y = m_pos_y + m_state->m_global_offset_y;

    graphics::drawRect(x, y, m_width * 2.0f, m_height * 2.0f, m_brush_cherry);
}

void Cherry::update(float dt) {

    updateAnimation();

}
