#include "settingscreen.h"
#include <sgg/graphics.h>
#include "gamestate.h"
#include "util.h"

void SettingScreen::init() {
    SETCOLOR(m_brush_settingBG.fill_color, 1.0f, 1.0f, 1.0f);
    m_brush_settingBG.fill_opacity = 1.0f;
    m_brush_settingBG.outline_opacity = 0.0f;
    m_brush_settingBG.texture = "assets\\settings.png";
}

void SettingScreen::draw() {
    graphics::drawRect(m_state->m_canvas_width / 2.0f, m_state->m_canvas_height / 2.0f,
        m_state->m_canvas_width, m_state->m_canvas_height, m_brush_settingBG);
}

void SettingScreen::update(float dt) {
    if (graphics::getKeyState(graphics::SCANCODE_B)) {
        m_state->setLevel(0);
    }
}
