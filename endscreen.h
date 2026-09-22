#pragma once
#include "player.h"

class EndScreen : public GameObject {
public:
	EndScreen(const std::string& name) {}; // Constructor

	void init() override;                // Override init
	void draw() override;                // Override draw
	void update(float dt) override;      // Override update

	graphics::Brush m_brush_endBG;
	graphics::Brush m_brush_endBLACK;
	graphics::Brush m_brush_endTXT;
};