#pragma once
#include <string>
#include "sgg/graphics.h"
#include "level.h"
#include "level1.h"
#include "level2.h"
#include "level3.h"

class GameState {
private:
    std::string m_asset_path = "assets\\";

    static GameState* m_instance; // Singleton instance

    GameState();

    int current_level = 0; // Current game level
    class Player* m_player = 0;
    class DeathScreen* death_screen = 0;

public:
    class EndScreen* end_screen = 0;
    class Level* m_current_level = 0;
    graphics::Brush m_brush_bkgnd;
    graphics::Brush m_brush_health;
    float m_global_offset_x = 0.0f;
    float m_global_offset_y = 0.0f;

    const float m_canvas_width = 8.0f;
    const float m_canvas_height = 8.0f;

    static GameState* getInstance();
    void setLevel(int level);
    int getLevel() const;
    bool init();
    void draw();
    void update(float dt);
    Level* createLevel(int i);

    float getCanvasWidth() {
        return m_canvas_width; 
    }

    float getCanvasHeight() {
        return m_canvas_height; 

    }

    ~GameState();

    std::string getFullAssetPath(const std::string& asset) const;
    std::string getAssetDir();

    class Player* getPlayer() { return m_player; }
};
