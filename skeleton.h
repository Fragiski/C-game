#pragma once
#include "box.h"
#include "gameobject.h"
#include <sgg/graphics.h>
#include <map>
#include "timer.h"
#include <chrono>

class Skeleton : public GameObject, public Box {
	float m_speed = 1.5f;
	float m_patrolStart = 0.0f;
	float m_patrolEnd = 0.0f;
	bool m_patrolLeft = true;
	float m_detectionRange = 3.5f;
	bool m_playerDetected = false;
	std::chrono::time_point<std::chrono::steady_clock> m_detectionTime;
	bool m_delayElapsed = false;

	const float m_size = 1.0f;
	graphics::Brush m_brush_skeleton;

	Timer animationTimerS;
	int currentFrameS = 0;
	std::map<std::string, std::vector<std::string>> Sanimations;
	std::string ScurrentAnimation;

	void loadAnimationsFramesS();

public:

	inline void setPosition(float x, float y) {
		m_pos_x = x;
		m_pos_y = y;
	}

	void setPatrolRange(float start, float end) {
		m_patrolStart = start;
		m_patrolEnd = end;
	}

	Skeleton(const std::string& name) : GameObject(name) {}
	
	void init() override;
	void draw() override;
	void update(float dt) override;

	void setAnimationS(const std::string& animationName);
	void updateAnimationS();
};