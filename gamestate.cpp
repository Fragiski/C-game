#include "gamestate.h"
#include "player.h"
#include "level.h"
#include <thread>
#include <chrono>
#include "level1.h"
#include "level2.h"
#include "level3.h"
#include "deathscreen.h"
#include "endscreen.h"
#include "settingscreen.h"

GameState* GameState::m_instance = nullptr;

GameState::GameState()
{

}

bool GameState::init()
{	
	m_current_level = createLevel(current_level);
	m_current_level->init();
	m_current_level->m_cherryCount = 0;

	if (current_level == 1) {

		m_player = new Player("Player");

		death_screen = new DeathScreen("Death Screen");
		death_screen->init();

		end_screen = new EndScreen("Death Screen");
		end_screen->init();

		graphics::preloadBitmaps(getAssetDir());
		graphics::setFont(m_asset_path + "OpenSans-Regular.ttf");
	}

	m_player->init();
	m_instance->getPlayer()->health = 3;

	return true;
}

void GameState::draw() {

	if (!m_current_level) {
		return;
	}

	m_current_level->draw();
	if (!(m_instance->getLevel() == 4))
		m_current_level->drawCherryCount();

	if (m_instance->getPlayer()->isDead) {
		death_screen->draw();
	}

	if (m_instance->getLevel() == 4) {
		end_screen->draw();
	}
}

void GameState::update(float dt)
{
	const float MAX_DT = 100.0f;

	if (dt > MAX_DT) {
		return;
	}

	if (!m_current_level)
		return;

	if (m_instance->getPlayer()->health == 3) {
		m_brush_health.texture = getFullAssetPath("health3.png");
	}
	else if (m_instance->getPlayer()->health == 2) {
		m_brush_health.texture = getFullAssetPath("health2.png");
	}
	else if (m_instance->getPlayer()->health == 1) {
		m_brush_health.texture = getFullAssetPath("health1.png");
	}
	else {
		m_brush_health.texture = getFullAssetPath("health0.png");
	}

	if (m_instance->getPlayer()->isDead) {
		death_screen->update(dt);
	}

	m_current_level->checkEndLevel();
	m_current_level->checkOutOfBounds();

	m_current_level->update(dt);
}

Level* GameState::createLevel(int levelNumber) {
	switch (levelNumber) {
	case 1:
		return new Level1("lvl1");
	case 2:
		return new Level2("lvl2");
	case 3:
		return new Level3("lvl3");
	default:
		return nullptr;
	}
}

GameState* GameState::getInstance() {
	
	if (m_instance == nullptr) {
		m_instance = new GameState();
	}

    return m_instance;
}

void GameState::setLevel(int level) {
    current_level = level;
}

int GameState::getLevel() const {
    return current_level;
}

GameState::~GameState()
{
	if (m_player)
		delete m_player;
	if (m_current_level)
		delete m_current_level;
}

std::string GameState::getAssetDir()
{
	return m_asset_path;
}

std::string GameState::getFullAssetPath(const std::string& asset) const
{
    return m_asset_path + asset;
}


