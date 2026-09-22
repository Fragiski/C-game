#pragma once
#include "gameobject.h"
#include <sgg/graphics.h>


class StartScreen : public GameObject {
public:
    StartScreen(const std::string& name) {}; // Constructor
    graphics::Brush m_brush_start;

    void init() override;                // Override init
    void draw() override;                // Override draw
    void update(float dt) override;      // Override update
};
