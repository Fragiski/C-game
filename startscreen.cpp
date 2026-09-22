#include "startscreen.h"
#include <sgg/graphics.h>
#include "gamestate.h"
#include "util.h"
#include "settingscreen.h"

void StartScreen::init() {
    SETCOLOR(m_brush_start.fill_color, 1.0f, 1.0f, 1.0f);
    m_brush_start.fill_opacity = 1.0f;
    m_brush_start.outline_opacity = 0.0f;
    m_brush_start.texture = "assets\\start.png";
}

void StartScreen::draw() {
    graphics::drawRect(m_state->m_canvas_width / 2.0f, m_state->m_canvas_height / 2.0f,
        m_state->m_canvas_width, m_state->m_canvas_height, m_brush_start);
}

void StartScreen::update(float dt) {
    if (graphics::getKeyState(graphics::SCANCODE_SPACE)) {
        m_state->setLevel(1);
        GameState::getInstance()->init();
    }
    else if (graphics::getKeyState(graphics::SCANCODE_T)) {
        m_state->setLevel(-1);
    }
}
