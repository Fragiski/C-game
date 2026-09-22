#pragma once
#include "gameobject.h"
#include "box.h"
#include "timer.h"
#include <vector>
#include <string>
#include <map>
#include <sgg/graphics.h>

class Cherry : public GameObject, public Box {
    std::map<std::string, std::vector<std::string>> Canimations; // Animation sets
    std::string CcurrentAnimation;                               // Current animation key
    int Cm_currentFrame = 0;                                     // Current frame index
    Timer Cm_animationTimer;                                     // Timer to manage frame transitions

    void loadCherryFrames();

public:
    Cherry(const Box& box);

    void init() override;                                       // Initialize the cherry
    void update(float dt) override;
    void draw() override;                                       // Render the cherry

    void setAnimation(const std::string& animationName);   // Set the current animation
    void updateAnimation();                                // Update the animation

    graphics::Brush m_brush_cherry;
};