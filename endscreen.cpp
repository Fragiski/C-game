#include "endscreen.h"
#include <sgg/graphics.h>
#include "gamestate.h"
#include "util.h"

void EndScreen::init() {
    SETCOLOR(m_brush_endBG.fill_color, 1.0f, 1.0f, 1.0f);
    m_brush_endBG.fill_opacity = 1.0f;
    m_brush_endBG.outline_opacity = 0.0f;
    m_brush_endBG.texture = "assets\\bg_lvl3.png";

    SETCOLOR(m_brush_endBLACK.fill_color, 1.0f, 1.0f, 1.0f);
    m_brush_endBLACK.fill_opacity = 0.3f;
    m_brush_endBLACK.outline_opacity = 0.0f;
    m_brush_endBLACK.texture = "assets\\black.png";

    SETCOLOR(m_brush_endTXT.fill_color, 1.0f, 1.0f, 1.0f);
    m_brush_endTXT.fill_opacity = 1.0f;
    m_brush_endTXT.outline_opacity = 0.0f;
    m_brush_endTXT.texture = "assets\\EndTXT.png";
}

void EndScreen::draw() {
    graphics::drawRect(m_state->m_canvas_width / 2.0f, m_state->m_canvas_height / 2.0f,
        m_state->m_canvas_width, m_state->m_canvas_height, m_brush_endBG);

    graphics::drawRect(m_state->m_canvas_width / 2.0f, m_state->m_canvas_height / 2.0f,
        m_state->m_canvas_width, m_state->m_canvas_height, m_brush_endBLACK);

    graphics::drawRect(m_state->m_canvas_width / 2.0f, m_state->m_canvas_height / 2.0f,
        m_state->m_canvas_width, m_state->m_canvas_height, m_brush_endTXT);
}

void EndScreen::update(float dt) {
}
