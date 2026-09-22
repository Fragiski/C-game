#include "level.h"
#include "util.h"
#include <cstdio>
#include "player.h"
#include "gamestate.h"
#include "box.h"
#include "bomb.h"

void Level::init() {

    SETCOLOR(m_state->m_brush_bkgnd.fill_color, 1.0f, 1.0f, 1.0f);
    m_state->m_brush_bkgnd.outline_opacity = 0.0f;
    SETCOLOR(m_state->m_brush_health.fill_color, 1.0f, 1.0f, 1.0f);
    m_state->m_brush_health.outline_opacity = 0.0f;

    loadLevelSpecificBlocks();
    loadLevelSpecificCherries();
    loadPlayerCoords();
}

void Level::drawblockBase(int i, bool cctrue) {
    if (i < m_blocks.size() && i < m_block_names.size()) {
        if ((cctrue && m_blocks[i].canCollide) || (!cctrue && !m_blocks[i].canCollide)) {
            m_block_brush.outline_opacity = 0.0f;

            float x = m_blocks[i].m_pos_x + m_state->m_global_offset_x;
            float y = m_blocks[i].m_pos_y + m_state->m_global_offset_y;
            float w = m_blocks[i].m_width;
            float h = m_blocks[i].m_height;

            m_block_brush.texture = getBlockTexture(i);
            m_state->m_brush_bkgnd.texture = getBkgndTexture();

            graphics::drawRect(x, y, w, h, m_block_brush);
        }
    }
}

int Level::m_cherryCount = 0;

void Level::drawCherryCount() {
    float iconSize = 1.0f;

    graphics::Brush iconBrush;
    iconBrush.texture = m_state->getFullAssetPath("cherry1.png");

    iconBrush.outline_opacity = 0.0f;
    graphics::drawRect(m_state->m_canvas_width / 2.0f + 3.4f, m_state->m_canvas_height / 2.0f + 3.4f, iconSize, iconSize, iconBrush);

    graphics::Brush textBrush;
    SETCOLOR(textBrush.fill_color, 1.0f, 1.0f, 1.0f);
    textBrush.fill_opacity = 1.0f;
    textBrush.outline_opacity = 0.0f;

    std::string countText = std::to_string(m_cherryCount);

    graphics::drawText(m_state->m_canvas_width / 2.0f + 2.5f, m_state->m_canvas_height / 2.0f + 3.5f, 0.5f, countText, textBrush);
}

void Level::drawBomb(int i)
{
    bombs[i].draw();
    bombs[i].update(graphics::getDeltaTime());
}

void Level::draw() {
    graphics::drawRect(m_state->m_canvas_width / 2.0f + 10.0f + m_state->m_global_offset_x / 6.0f, m_state->m_canvas_height / 2.0f + m_state->m_global_offset_y / 2.5f,
        m_state->m_canvas_width * 4.0f, m_state->m_canvas_height  *  2.0f, m_state->m_brush_bkgnd);

    for (int i = 0; i < m_blocks.size(); i++) { // sxediash blocks

        drawblockBase(i, false);
    }
    
    m_state->getPlayer()->draw();

    for (const auto& p_gob : m_dynamic_objects)
        if (p_gob) p_gob->draw();

    for (const auto& cherry : m_cherries) {
        cherry->draw();
    }

    for (int i = 0; i < m_blocks.size(); i++) { // sxediash blocks

        drawblockBase(i, true);
    }

    if (m_state->getLevel() == 2) {
        for (int i = 0; i < bombs.size(); i++) {

            drawBomb(i);

        }
    }

    graphics::drawRect(m_state->m_canvas_width / 2.0f, m_state->m_canvas_height / 2.0f, m_state->m_canvas_width, m_state->m_canvas_height,
        m_state->m_brush_health);
}

float spawnTimer = 0.0f;

void Level::update(float dt) {
    
    if (m_state->getPlayer()->isActive())
        m_state->getPlayer()->update(dt);

    for (const auto& dynamic : m_dynamic_objects) {
        dynamic->update(dt);
    }

    for (const auto& cherry : m_cherries) {
        if (cherry) {
            cherry->update(dt);
        }
    }

    if (m_state->getLevel() == 2) {

        FallingBombs();
        spawnTimer += dt;
        if (spawnTimer > 100000) {
            FallingBombs();
            spawnTimer = 0.0f;
        }
    }

    GameObject::update(dt);

    if (graphics::getKeyState(graphics::SCANCODE_0)) {
        m_state->setLevel(2);
        GameState::getInstance()->init();
    }

    if (graphics::getKeyState(graphics::SCANCODE_1)) {
        m_state->setLevel(3);
        GameState::getInstance()->init();
    }
}

Level::Level(const std::string& name) : GameObject(name)
{
}

Level::~Level()
{

    for (auto p_gob : m_dynamic_objects)
        if (p_gob) delete p_gob;
}
