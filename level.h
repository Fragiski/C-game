#pragma once
#include "gameobject.h"
#include "sgg/graphics.h"
#include <list>
#include <vector>
#include <string>
#include "player.h"
#include "box.h"
#include "cherry.h"
#include "bomb.h"


class Level : public GameObject {

    graphics::Brush m_block_brush;
    graphics::Brush m_cherries_brush;

    virtual std::string getBlockTexture(int i) const = 0;
    virtual std::string getBkgndTexture() const = 0;
    void drawblockBase(int i, bool f);

    virtual void loadLevelSpecificBlocks() = 0;
    virtual void loadPlayerCoords() = 0;

protected:

    std::list<GameObject*> m_dynamic_objects;

    std::vector<Box> m_blocks;
    std::vector<std::string> m_block_names;
    const float m_block_size = 1.0f;

    std::vector<Cherry*> m_cherries;
    virtual void FallingBombs() {} ;

public:

    float player_x = 0.0f;
    float player_y = 0.0f;
    float m_accel_v = 9.0f;

    void drawCherryCount();
    
    void drawBomb(int i);
    std::vector<Bomb> bombs;
    virtual void checkEndLevel() = 0;
    virtual void checkOutOfBounds() = 0;
    virtual void checkCollisions() = 0;
    virtual void loadLevelSpecificCherries() = 0;
    static int m_cherryCount;

    explicit Level(const std::string& name);

    void init() override;
    void draw() override;
    void update(float dt) override;

    virtual ~Level();
};