#include "box.h"
#include "bomb.h"
#include "gameobject.h"
#include "gamestate.h"
#include "sgg/graphics.h"
#include "level2.h"
#include <random>
#include <string>
#include <iostream>
using namespace std;



Bomb::Bomb(float x, float y, float width, float height, bool cc)
    :Box(x, y, width, height, cc)
{

}

void Bomb::init()
{
    m_brush_bomb.outline_opacity = 0;
    setAnimationBomb("start");        // Default to idle animation
    animationTimerBomb.start();      // Start the animation timer
}

void Bomb::loadAnimationsFramesBomb() {
    animationsBomb["start"] = {
        "assets\\bomb1.png",
        "assets\\bomb2.png",
        "assets\\bomb3.png",
        "assets\\bomb4.png",
        "assets\\bomb5.png",
        "assets\\bomb6.png",
        "assets\\bomb7.png",
        "assets\\bomb8.png",
        "assets\\bomb9.png",
        "assets\\bomb10.png",
        "assets\\bomb12.png",
        "assets\\bomb13.png",
        "assets\\bomb14.png",
        "assets\\bomb15.png",
        "assets\\bomb16.png",
        "assets\\bomb17.png",
        "assets\\bomb18.png",
        "assets\\bomb19.png",
        "assets\\bomb20.png"

    };
    

}

void Bomb::setAnimationBomb(const std::string& animationNameBomb) {
    if (currentAnimationBomb != animationNameBomb && animationsBomb.count(animationNameBomb)) {


        currentAnimationBomb = animationNameBomb;

        // Set the timer period based on the animation
        if (animationNameBomb == "start") {
            animationTimerBomb = Timer(2.0f, Timer::TIMER_LOOPING); // 2 seconds per cycle
        }
       


        animationTimerBomb.start(); // Restart the timer for the new animation
    }
}

void Bomb::updateAnimationBomb() {

    if (!currentAnimationBomb.empty() && animationsBomb.count(currentAnimationBomb)) {
        const auto& frames = animationsBomb[currentAnimationBomb];
        size_t frameCount = frames.size();

        if (frameCount > 0) {
            // Use the normalized timer value to calculate the current frame
            float normalizedTime = animationTimerBomb; // Normalized value [0.0, 1.0]
            currentFrameBomb = static_cast<int>(normalizedTime * frameCount) % frameCount;


        }

    }

}

void Bomb::draw()
{

    m_brush_bomb.outline_opacity = 0.0f;
    if (!currentAnimationBomb.empty() && animationsBomb.count(currentAnimationBomb)) {
        const auto& frames = animationsBomb[currentAnimationBomb];
        if (currentFrameBomb >= 0 && currentFrameBomb < frames.size()) {
            m_brush_bomb.texture = frames[currentFrameBomb];



            graphics::drawRect(m_pos_x + GameState::getInstance()->m_global_offset_x, m_pos_y + GameState::getInstance()->m_global_offset_y, m_width, m_height, m_brush_bomb);


        }

    }



}

// Update bomb's position 
void Bomb::update(float deltaTime)
{

    m_pos_y += deltaTime * 0.005f;
    updateAnimationBomb();


}



