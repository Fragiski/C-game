#pragma once
#include "player.h"

class SettingScreen : public GameObject {
public:
	SettingScreen(const std::string& name) {}; // Constructor

	void init() override;                // Override init
	void draw() override;                // Override draw
	void update(float dt) override;      // Override update

	graphics::Brush m_brush_settingBG;
};