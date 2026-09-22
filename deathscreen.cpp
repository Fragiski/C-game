#include "deathscreen.h"
#include <sgg/graphics.h>
#include "gamestate.h"
#include "util.h"

void DeathScreen::init() {
    SETCOLOR(m_brush_deathBG.fill_color, 1.0f, 1.0f, 1.0f);
    m_brush_deathBG.fill_opacity = 0.3f;
    m_brush_deathBG.outline_opacity = 0.0f;
    m_brush_deathBG.texture = "assets\\black.png";

    SETCOLOR(m_brush_deathTXT.fill_color, 1.0f, 1.0f, 1.0f);
    m_brush_deathTXT.fill_opacity = 1.0f;
    m_brush_deathTXT.outline_opacity = 0.0f;
    m_brush_deathTXT.texture = "assets\\deathTXT.png";
}

void DeathScreen::draw() {
    graphics::drawRect(m_state->m_canvas_width / 2.0f, m_state->m_canvas_height / 2.0f,
        m_state->m_canvas_width, m_state->m_canvas_height, m_brush_deathBG);

    graphics::drawRect(m_state->m_canvas_width / 2.0f, m_state->m_canvas_height / 2.0f,
        m_state->m_canvas_width, m_state->m_canvas_height, m_brush_deathTXT);
}

void DeathScreen::update(float dt) {
    if (graphics::getKeyState(graphics::SCANCODE_SPACE)) {
        m_state->getPlayer()->respawn();
    }
}
