#include "level3.h"
#include "gamestate.h"
#include "math.h"
#include "skeleton.h"

Level3::Level3(const std::string& name) : Level(name)
{
}

Level3::~Level3()
{

    for (const auto& p_gob : m_dynamic_objects)
        if (p_gob) delete p_gob;
}

void Level3::loadPlayerCoords() {
    player_x = m_state->m_canvas_width / 2.0f;
    player_y = m_state->m_canvas_height / 2.0f + 2.0f;
    m_accel_v = 6.4f;
}

void Level3::loadLevelSpecificBlocks() {

    m_blocks.clear();
    m_block_names.clear();

    //skellies
    Skeleton* skeleton1 = new Skeleton("Skeleton1");
    skeleton1->setPosition(10.0f * m_block_size, 6.0f * m_block_size);
    skeleton1->setPatrolRange(8.0f * m_block_size, 11.0f * m_block_size);
    skeleton1->init();
    m_dynamic_objects.push_back(skeleton1);

    Skeleton* skeleton2 = new Skeleton("Skeleton2");
    skeleton2->setPosition(13.0f * m_block_size, 6.0f * m_block_size);
    skeleton2->setPatrolRange(12.0f * m_block_size, 15.0f * m_block_size);
    skeleton2->init();
    m_dynamic_objects.push_back(skeleton2);

    Skeleton* skeleton3 = new Skeleton("Skeleton3");
    skeleton3->setPosition(21.5f * m_block_size, 6.0f * m_block_size);
    skeleton3->setPatrolRange(20.0f * m_block_size, 22.0f * m_block_size);
    skeleton3->init();
    m_dynamic_objects.push_back(skeleton3);

    Skeleton* skeleton4 = new Skeleton("Skeleton4");
    skeleton4->setPosition(27.5f * m_block_size, 3.0f * m_block_size);
    skeleton4->setPatrolRange(26.0f * m_block_size, 28.0f * m_block_size);
    skeleton4->init();
    m_dynamic_objects.push_back(skeleton4);

    Skeleton* skeleton5 = new Skeleton("Skeleton5");
    skeleton5->setPosition(39.0f * m_block_size, 6.0f * m_block_size);
    skeleton5->setPatrolRange(39.0f * m_block_size, 42.0f * m_block_size);
    skeleton5->init();
    m_dynamic_objects.push_back(skeleton5);

    Skeleton* skeleton6 = new Skeleton("Skeleton6");
    skeleton6->setPosition(56.0f * m_block_size, 4.0f * m_block_size);
    skeleton6->setPatrolRange(55.0f * m_block_size, 58.0f * m_block_size);
    skeleton6->init();
    m_dynamic_objects.push_back(skeleton6);

    Skeleton* skeleton7 = new Skeleton("Skeleton7");
    skeleton7->setPosition(68.0f * m_block_size, 4.0f * m_block_size);
    skeleton7->setPatrolRange(66.0f * m_block_size, 68.0f * m_block_size);
    skeleton7->init();
    m_dynamic_objects.push_back(skeleton7);

    Skeleton* skeleton8 = new Skeleton("Skeleton8");
    skeleton8->setPosition(73.0f * m_block_size, 1.0f * m_block_size);
    skeleton8->setPatrolRange(73.0f * m_block_size, 76.0f * m_block_size);
    skeleton8->init();
    m_dynamic_objects.push_back(skeleton8);

    Skeleton* skeleton9 = new Skeleton("Skeleton9");
    skeleton9->setPosition(76.0f * m_block_size, 1.0f * m_block_size);
    skeleton9->setPatrolRange(73.0f * m_block_size, 76.0f * m_block_size);
    skeleton9->init();
    m_dynamic_objects.push_back(skeleton9);

    //Cave thing ccfalse
    m_blocks.push_back(Box(4 * m_block_size, 6 * m_block_size, 1 * m_block_size, 1 * m_block_size, false));
    m_block_names.push_back("tiles\\Tile (5)_d.png");
    m_blocks.push_back(Box(5 * m_block_size, 6 * m_block_size, 1 * m_block_size, 1 * m_block_size, false));
    m_block_names.push_back("tiles\\Tile (5)_d.png");
    m_blocks.push_back(Box(6 * m_block_size, 6 * m_block_size, 1 * m_block_size, 1 * m_block_size, false));
    m_block_names.push_back("tiles\\Tile (5)_d.png");
    m_blocks.push_back(Box(6 * m_block_size, 5 * m_block_size, 1 * m_block_size, 1 * m_block_size, false));
    m_block_names.push_back("tiles\\Tile (5)_d.png");
    m_blocks.push_back(Box(7 * m_block_size, 6 * m_block_size, 1 * m_block_size, 1 * m_block_size, false));
    m_block_names.push_back("tiles\\Tile (5)_d.png");
    m_blocks.push_back(Box(7 * m_block_size, 5 * m_block_size, 1 * m_block_size, 1 * m_block_size, false));
    m_block_names.push_back("tiles\\Tile (5)_d.png");
    m_blocks.push_back(Box(8 * m_block_size, 5 * m_block_size, 1 * m_block_size, 1 * m_block_size, false));
    m_block_names.push_back("tiles\\Tile (5)_d.png");
    m_blocks.push_back(Box(8 * m_block_size, 6 * m_block_size, 1 * m_block_size, 1 * m_block_size, false));
    m_block_names.push_back("tiles\\Tile (5)_d.png");
    m_blocks.push_back(Box(9 * m_block_size, 4 * m_block_size, 1 * m_block_size, 1 * m_block_size, false));
    m_block_names.push_back("tiles\\Tile (5)_d.png");
    m_blocks.push_back(Box(9 * m_block_size, 5 * m_block_size, 1 * m_block_size, 1 * m_block_size, false));
    m_block_names.push_back("tiles\\Tile (5)_d.png");
    m_blocks.push_back(Box(9 * m_block_size, 6 * m_block_size, 1 * m_block_size, 1 * m_block_size, false));
    m_block_names.push_back("tiles\\Tile (6)_d.png");
    m_blocks.push_back(Box(10 * m_block_size, 3 * m_block_size, 1 * m_block_size, 1 * m_block_size, false));
    m_block_names.push_back("tiles\\Tile (5)_d.png");
    m_blocks.push_back(Box(10 * m_block_size, 4 * m_block_size, 1 * m_block_size, 1 * m_block_size, false));
    m_block_names.push_back("tiles\\Tile (5)_d.png");
    m_blocks.push_back(Box(10 * m_block_size, 5 * m_block_size, 1 * m_block_size, 1 * m_block_size, false));
    m_block_names.push_back("tiles\\Tile (13)_d.png");
    m_blocks.push_back(Box(11 * m_block_size, 3 * m_block_size, 1 * m_block_size, 1 * m_block_size, false));
    m_block_names.push_back("tiles\\Tile (6)_d.png");
    m_blocks.push_back(Box(11 * m_block_size, 4 * m_block_size, 1 * m_block_size, 1 * m_block_size, false));
    m_block_names.push_back("tiles\\Tile (13)_d.png");

    //decos
    m_blocks.push_back(Box(11 * m_block_size, 5.9f * m_block_size, 1 * m_block_size, 1 * m_block_size, false));
    m_block_names.push_back("objects\\ArrowSign.png");
    m_blocks.push_back(Box(10.8f * m_block_size, 6.3f * m_block_size, 1 * m_block_size, 0.5f * m_block_size, false));
    m_block_names.push_back("objects\\Bush (1).png");
    
    //Cave thing cctrue
    m_blocks.push_back(Box(4 * m_block_size, -1 * m_block_size, 1 * m_block_size, 1 * m_block_size, true));
    m_block_names.push_back("tiles\\Tile (5).png");
    m_blocks.push_back(Box(5 * m_block_size, -1 * m_block_size, 1 * m_block_size, 1 * m_block_size, true));
    m_block_names.push_back("tiles\\Tile (5).png");
    m_blocks.push_back(Box(6 * m_block_size, -1 * m_block_size, 1 * m_block_size, 1 * m_block_size, true));
    m_block_names.push_back("tiles\\Tile (5).png");
    m_blocks.push_back(Box(7 * m_block_size, -1 * m_block_size, 1 * m_block_size, 1 * m_block_size, true));
    m_block_names.push_back("tiles\\Tile (5).png");
    m_blocks.push_back(Box(8 * m_block_size, -1 * m_block_size, 1 * m_block_size, 1 * m_block_size, true));
    m_block_names.push_back("tiles\\Tile (5).png");
    m_blocks.push_back(Box(9 * m_block_size, -1 * m_block_size, 1 * m_block_size, 1 * m_block_size, true));
    m_block_names.push_back("tiles\\Tile (5).png");
    m_blocks.push_back(Box(10 * m_block_size, -1 * m_block_size, 1 * m_block_size, 1 * m_block_size, true));
    m_block_names.push_back("tiles\\Tile (5).png");
    m_blocks.push_back(Box(11 * m_block_size, -1* m_block_size, 1 * m_block_size, 1 * m_block_size, true));
    m_block_names.push_back("tiles\\Tile (5).png");
    m_blocks.push_back(Box(12 * m_block_size, -1 * m_block_size, 1 * m_block_size, 1 * m_block_size, true));
    m_block_names.push_back("tiles\\Tile (5).png");
    m_blocks.push_back(Box(13 * m_block_size, -1 * m_block_size, 1 * m_block_size, 1 * m_block_size, true));
    m_block_names.push_back("tiles\\Tile (6).png");
    m_blocks.push_back(Box(3 * m_block_size, 0 * m_block_size, 1 * m_block_size, 1 * m_block_size, true));
    m_block_names.push_back("tiles\\Tile (5).png");
    m_blocks.push_back(Box(2 * m_block_size, 0 * m_block_size, 1 * m_block_size, 1 * m_block_size, true));
    m_block_names.push_back("tiles\\Tile (5).png");
    m_blocks.push_back(Box(4 * m_block_size, 0 * m_block_size, 1 * m_block_size, 1 * m_block_size, true));
    m_block_names.push_back("tiles\\Tile (5).png");
    m_blocks.push_back(Box(5 * m_block_size, 0 * m_block_size, 1 * m_block_size, 1 * m_block_size, true));
    m_block_names.push_back("tiles\\Tile (5).png");
    m_blocks.push_back(Box(6 * m_block_size, 0 * m_block_size, 1 * m_block_size, 1 * m_block_size, true));
    m_block_names.push_back("tiles\\Tile (5).png");
    m_blocks.push_back(Box(7 * m_block_size, 0 * m_block_size, 1 * m_block_size, 1 * m_block_size, true));
    m_block_names.push_back("tiles\\Tile (5).png");
    m_blocks.push_back(Box(8 * m_block_size, 0 * m_block_size, 1 * m_block_size, 1 * m_block_size, true));
    m_block_names.push_back("tiles\\Tile (5).png");
    m_blocks.push_back(Box(9 * m_block_size, 0 * m_block_size, 1 * m_block_size, 1 * m_block_size, true));
    m_block_names.push_back("tiles\\Tile (5).png");
    m_blocks.push_back(Box(10 * m_block_size, 0 * m_block_size, 1 * m_block_size, 1 * m_block_size, true));
    m_block_names.push_back("tiles\\Tile (5).png");
    m_blocks.push_back(Box(11 * m_block_size, 0 * m_block_size, 1 * m_block_size, 1 * m_block_size, true));
    m_block_names.push_back("tiles\\Tile (5).png");
    m_blocks.push_back(Box(12 * m_block_size, 0 * m_block_size, 1 * m_block_size, 1 * m_block_size, true));
    m_block_names.push_back("tiles\\Tile (5).png");
    m_blocks.push_back(Box(13 * m_block_size, 0 * m_block_size, 1 * m_block_size, 1 * m_block_size, true));
    m_block_names.push_back("tiles\\Tile (6).png");
    m_blocks.push_back(Box(3 * m_block_size, 6 * m_block_size, 1 * m_block_size, 1 * m_block_size, true));
    m_block_names.push_back("tiles\\Tile (5).png");
    m_blocks.push_back(Box(3 * m_block_size, 5 * m_block_size, 1 * m_block_size, 1 * m_block_size, true));
    m_block_names.push_back("tiles\\Tile (5).png");
    m_blocks.push_back(Box(4 * m_block_size, 5 * m_block_size, 1 * m_block_size, 1 * m_block_size, true));
    m_block_names.push_back("tiles\\Tile (5).png");
    m_blocks.push_back(Box(5 * m_block_size, 5 * m_block_size, 1 * m_block_size, 1 * m_block_size, true));
    m_block_names.push_back("tiles\\Tile (5).png");
    m_blocks.push_back(Box(5 * m_block_size, 4 * m_block_size, 1 * m_block_size, 1 * m_block_size, true));
    m_block_names.push_back("tiles\\Tile (5).png");
    m_blocks.push_back(Box(6 * m_block_size, 4 * m_block_size, 1 * m_block_size, 1 * m_block_size, true));
    m_block_names.push_back("tiles\\Tile (5).png");
    m_blocks.push_back(Box(7 * m_block_size, 4 * m_block_size, 1 * m_block_size, 1 * m_block_size, true));
    m_block_names.push_back("tiles\\Tile (5).png");
    m_blocks.push_back(Box(8 * m_block_size, 4 * m_block_size, 1 * m_block_size, 1 * m_block_size, true));
    m_block_names.push_back("tiles\\Tile (5).png");
    m_blocks.push_back(Box(8 * m_block_size, 3 * m_block_size, 1 * m_block_size, 1 * m_block_size, true));
    m_block_names.push_back("tiles\\Tile (5).png");
    m_blocks.push_back(Box(9 * m_block_size, 3 * m_block_size, 1 * m_block_size, 1 * m_block_size, true));
    m_block_names.push_back("tiles\\Tile (5).png");
    m_blocks.push_back(Box(9 * m_block_size, 2 * m_block_size, 1 * m_block_size, 1 * m_block_size, true));
    m_block_names.push_back("tiles\\Tile (5).png");
    m_blocks.push_back(Box(10 * m_block_size, 2 * m_block_size, 1 * m_block_size, 1 * m_block_size, true));
    m_block_names.push_back("tiles\\Tile (5).png");
    m_blocks.push_back(Box(11 * m_block_size, 2 * m_block_size, 1 * m_block_size, 1 * m_block_size, true));
    m_block_names.push_back("tiles\\Tile (5).png");
    m_blocks.push_back(Box(12 * m_block_size, 2 * m_block_size, 1 * m_block_size, 1 * m_block_size, true));
    m_block_names.push_back("tiles\\Tile (13).png");
    m_blocks.push_back(Box(13 * m_block_size, 1 * m_block_size, 1 * m_block_size, 1 * m_block_size, true));
    m_block_names.push_back("tiles\\Tile (13).png");
    m_blocks.push_back(Box(3 * m_block_size, 8 * m_block_size, 1 * m_block_size, 1 * m_block_size, true));
    m_block_names.push_back("tiles\\Tile (5).png");
    m_blocks.push_back(Box(2 * m_block_size, 8 * m_block_size, 1 * m_block_size, 1 * m_block_size, true));
    m_block_names.push_back("tiles\\Tile (5).png");
    m_blocks.push_back(Box(1 * m_block_size, 8 * m_block_size, 1 * m_block_size, 1 * m_block_size, true));
    m_block_names.push_back("tiles\\Tile (5).png");
    m_blocks.push_back(Box(0 * m_block_size, 8 * m_block_size, 1 * m_block_size, 1 * m_block_size, true));
    m_block_names.push_back("tiles\\Tile (5).png");
    m_blocks.push_back(Box(3 * m_block_size, 9 * m_block_size, 1 * m_block_size, 1 * m_block_size, true));
    m_block_names.push_back("tiles\\Tile (5).png");
    m_blocks.push_back(Box(2 * m_block_size, 9 * m_block_size, 1 * m_block_size, 1 * m_block_size, true));
    m_block_names.push_back("tiles\\Tile (5).png");
    m_blocks.push_back(Box(1 * m_block_size, 9 * m_block_size, 1 * m_block_size, 1 * m_block_size, true));
    m_block_names.push_back("tiles\\Tile (5).png");
    m_blocks.push_back(Box(0 * m_block_size, 9 * m_block_size, 1 * m_block_size, 1 * m_block_size, true));
    m_block_names.push_back("tiles\\Tile (5).png");
    m_blocks.push_back(Box(3 * m_block_size, 6 * m_block_size, 1 * m_block_size, 1 * m_block_size, true));
    m_block_names.push_back("tiles\\Tile (5).png");
    m_blocks.push_back(Box(2 * m_block_size, 6 * m_block_size, 1 * m_block_size, 1 * m_block_size, true));
    m_block_names.push_back("tiles\\Tile (5).png");
    m_blocks.push_back(Box(1 * m_block_size, 6 * m_block_size, 1 * m_block_size, 1 * m_block_size, true));
    m_block_names.push_back("tiles\\Tile (5).png");
    m_blocks.push_back(Box(0 * m_block_size, 6 * m_block_size, 1 * m_block_size, 1 * m_block_size, true));
    m_block_names.push_back("tiles\\Tile (5).png");
    m_blocks.push_back(Box(3 * m_block_size, 5 * m_block_size, 1 * m_block_size, 1 * m_block_size, true));
    m_block_names.push_back("tiles\\Tile (5).png");
    m_blocks.push_back(Box(2 * m_block_size, 5 * m_block_size, 1 * m_block_size, 1 * m_block_size, true));
    m_block_names.push_back("tiles\\Tile (5).png");
    m_blocks.push_back(Box(1 * m_block_size, 5 * m_block_size, 1 * m_block_size, 1 * m_block_size, true));
    m_block_names.push_back("tiles\\Tile (5).png");
    m_blocks.push_back(Box(0 * m_block_size, 5 * m_block_size, 1 * m_block_size, 1 * m_block_size, true));
    m_block_names.push_back("tiles\\Tile (5).png");
    m_blocks.push_back(Box(4 * m_block_size, 4 * m_block_size, 1 * m_block_size, 1 * m_block_size, true));
    m_block_names.push_back("tiles\\Tile (5).png");
    m_blocks.push_back(Box(3 * m_block_size, 4 * m_block_size, 1 * m_block_size, 1 * m_block_size, true));
    m_block_names.push_back("tiles\\Tile (5).png");
    m_blocks.push_back(Box(2 * m_block_size, 4 * m_block_size, 1 * m_block_size, 1 * m_block_size, true));
    m_block_names.push_back("tiles\\Tile (5).png");
    m_blocks.push_back(Box(1 * m_block_size, 4 * m_block_size, 1 * m_block_size, 1 * m_block_size, true));
    m_block_names.push_back("tiles\\Tile (5).png");
    m_blocks.push_back(Box(0 * m_block_size, 4 * m_block_size, 1 * m_block_size, 1 * m_block_size, true));
    m_block_names.push_back("tiles\\Tile (5).png");
    m_blocks.push_back(Box(7 * m_block_size, 3 * m_block_size, 1 * m_block_size, 1 * m_block_size, true));
    m_block_names.push_back("tiles\\Tile (5).png");
    m_blocks.push_back(Box(6 * m_block_size, 3 * m_block_size, 1 * m_block_size, 1 * m_block_size, true));
    m_block_names.push_back("tiles\\Tile (5).png");
    m_blocks.push_back(Box(5 * m_block_size, 3 * m_block_size, 1 * m_block_size, 1 * m_block_size, true));
    m_block_names.push_back("tiles\\Tile (5).png");
    m_blocks.push_back(Box(4 * m_block_size, 3 * m_block_size, 1 * m_block_size, 1 * m_block_size, true));
    m_block_names.push_back("tiles\\Tile (5).png");
    m_blocks.push_back(Box(3 * m_block_size, 3 * m_block_size, 1 * m_block_size, 1 * m_block_size, true));
    m_block_names.push_back("tiles\\Tile (5).png");
    m_blocks.push_back(Box(2 * m_block_size, 3 * m_block_size, 1 * m_block_size, 1 * m_block_size, true));
    m_block_names.push_back("tiles\\Tile (5).png");
    m_blocks.push_back(Box(1 * m_block_size, 3 * m_block_size, 1 * m_block_size, 1 * m_block_size, true));
    m_block_names.push_back("tiles\\Tile (5).png");
    m_blocks.push_back(Box(0 * m_block_size, 3 * m_block_size, 1 * m_block_size, 1 * m_block_size, true));
    m_block_names.push_back("tiles\\Tile (5).png");
    m_blocks.push_back(Box(9 * m_block_size, 2 * m_block_size, 1 * m_block_size, 1 * m_block_size, true));
    m_block_names.push_back("tiles\\Tile (5).png");
    m_blocks.push_back(Box(8 * m_block_size, 2 * m_block_size, 1 * m_block_size, 1 * m_block_size, true));
    m_block_names.push_back("tiles\\Tile (5).png");
    m_blocks.push_back(Box(7 * m_block_size, 2 * m_block_size, 1 * m_block_size, 1 * m_block_size, true));
    m_block_names.push_back("tiles\\Tile (5).png");
    m_blocks.push_back(Box(6 * m_block_size, 2 * m_block_size, 1 * m_block_size, 1 * m_block_size, true));
    m_block_names.push_back("tiles\\Tile (5).png");
    m_blocks.push_back(Box(5 * m_block_size, 2 * m_block_size, 1 * m_block_size, 1 * m_block_size, true));
    m_block_names.push_back("tiles\\Tile (5).png");
    m_blocks.push_back(Box(4 * m_block_size, 2 * m_block_size, 1 * m_block_size, 1 * m_block_size, true));
    m_block_names.push_back("tiles\\Tile (5).png");
    m_blocks.push_back(Box(3 * m_block_size, 2 * m_block_size, 1 * m_block_size, 1 * m_block_size, true));
    m_block_names.push_back("tiles\\Tile (5).png");
    m_blocks.push_back(Box(2 * m_block_size, 2 * m_block_size, 1 * m_block_size, 1 * m_block_size, true));
    m_block_names.push_back("tiles\\Tile (5).png");
    m_blocks.push_back(Box(1 * m_block_size, 2 * m_block_size, 1 * m_block_size, 1 * m_block_size, true));
    m_block_names.push_back("tiles\\Tile (5).png");
    m_blocks.push_back(Box(0 * m_block_size, 2 * m_block_size, 1 * m_block_size, 1 * m_block_size, true));
    m_block_names.push_back("tiles\\Tile (5).png");
    m_blocks.push_back(Box(12 * m_block_size, 1 * m_block_size, 1 * m_block_size, 1 * m_block_size, true));
    m_block_names.push_back("tiles\\Tile (5).png");
    m_blocks.push_back(Box(11 * m_block_size, 1 * m_block_size, 1 * m_block_size, 1 * m_block_size, true));
    m_block_names.push_back("tiles\\Tile (5).png");
    m_blocks.push_back(Box(10 * m_block_size, 1 * m_block_size, 1 * m_block_size, 1 * m_block_size, true));
    m_block_names.push_back("tiles\\Tile (5).png");
    m_blocks.push_back(Box(9 * m_block_size, 1 * m_block_size, 1 * m_block_size, 1 * m_block_size, true));
    m_block_names.push_back("tiles\\Tile (5).png");
    m_blocks.push_back(Box(8 * m_block_size, 1 * m_block_size, 1 * m_block_size, 1 * m_block_size, true));
    m_block_names.push_back("tiles\\Tile (5).png");
    m_blocks.push_back(Box(7 * m_block_size, 1 * m_block_size, 1 * m_block_size, 1 * m_block_size, true));
    m_block_names.push_back("tiles\\Tile (5).png");
    m_blocks.push_back(Box(6 * m_block_size, 1 * m_block_size, 1 * m_block_size, 1 * m_block_size, true));
    m_block_names.push_back("tiles\\Tile (5).png");
    m_blocks.push_back(Box(5 * m_block_size, 1 * m_block_size, 1 * m_block_size, 1 * m_block_size, true));
    m_block_names.push_back("tiles\\Tile (5).png");
    m_blocks.push_back(Box(4 * m_block_size, 1 * m_block_size, 1 * m_block_size, 1 * m_block_size, true));
    m_block_names.push_back("tiles\\Tile (5).png");
    m_blocks.push_back(Box(3 * m_block_size, 1 * m_block_size, 1 * m_block_size, 1 * m_block_size, true));
    m_block_names.push_back("tiles\\Tile (5).png");
    m_blocks.push_back(Box(2 * m_block_size, 1 * m_block_size, 1 * m_block_size, 1 * m_block_size, true));
    m_block_names.push_back("tiles\\Tile (5).png");
    m_blocks.push_back(Box(1 * m_block_size, 1 * m_block_size, 1 * m_block_size, 1 * m_block_size, true));
    m_block_names.push_back("tiles\\Tile (5).png");
    m_blocks.push_back(Box(0 * m_block_size, 1 * m_block_size, 1 * m_block_size, 1 * m_block_size, true));
    m_block_names.push_back("tiles\\Tile (5).png");

    //structure1
    m_blocks.push_back(Box(17 * m_block_size, 6 * m_block_size, 1 * m_block_size, 1 * m_block_size, true));
    m_block_names.push_back("tiles\\Tile (1).png");
    m_blocks.push_back(Box(18 * m_block_size, 6 * m_block_size, 1 * m_block_size, 1 * m_block_size, true));
    m_block_names.push_back("tiles\\Tile (2).png");
    m_blocks.push_back(Box(19 * m_block_size, 6 * m_block_size, 1 * m_block_size, 1 * m_block_size, true));
    m_block_names.push_back("tiles\\Tile (3).png");
    m_blocks.push_back(Box(18 * m_block_size, 5 * m_block_size, 1 * m_block_size, 1 * m_block_size, true));
    m_block_names.push_back("crate.png");

    //str2
    m_blocks.push_back(Box(23 * m_block_size, 6 * m_block_size, 1 * m_block_size, 1 * m_block_size, true));
    m_block_names.push_back("tiles\\Tile (1).png");
    m_blocks.push_back(Box(24 * m_block_size, 6 * m_block_size, 1 * m_block_size, 1 * m_block_size, true));
    m_block_names.push_back("tiles\\Tile (3).png");
    m_blocks.push_back(Box(24 * m_block_size, 5 * m_block_size, 1 * m_block_size, 1 * m_block_size, true));
    m_block_names.push_back("tiles\\Tile (3).png");

    //platform1
    m_blocks.push_back(Box(26 * m_block_size, 4 * m_block_size, 1 * m_block_size, 1 * m_block_size, true));
    m_block_names.push_back("tiles\\Tile (14).png");
    m_blocks.push_back(Box(27 * m_block_size, 4 * m_block_size, 1 * m_block_size, 1 * m_block_size, true));
    m_block_names.push_back("tiles\\Tile (15).png");
    m_blocks.push_back(Box(28 * m_block_size, 4 * m_block_size, 1 * m_block_size, 1 * m_block_size, true));
    m_block_names.push_back("tiles\\Tile (16).png");

    //small platforms1
    m_blocks.push_back(Box(32 * m_block_size, 3 * m_block_size, 1 * m_block_size, 1 * m_block_size, true));
    m_block_names.push_back("tiles\\Tile (14).png");
    m_blocks.push_back(Box(33 * m_block_size, 3 * m_block_size, 1 * m_block_size, 1 * m_block_size, true));
    m_block_names.push_back("tiles\\Tile (16).png");

    m_blocks.push_back(Box(36 * m_block_size, 5 * m_block_size, 1 * m_block_size, 1 * m_block_size, true));
    m_block_names.push_back("tiles\\Tile (14).png");
    m_blocks.push_back(Box(37 * m_block_size, 5 * m_block_size, 1 * m_block_size, 1 * m_block_size, true));
    m_block_names.push_back("tiles\\Tile (16).png");
    
    //water part1
    m_blocks.push_back(Box(24 * m_block_size, 7 * m_block_size, 1 * m_block_size, 1 * m_block_size, false));
    m_block_names.push_back("water_bw1.png");
    m_blocks.push_back(Box(25 * m_block_size, 7 * m_block_size, 1 * m_block_size, 1 * m_block_size, false));
    m_block_names.push_back("water_bw1.png");
    m_blocks.push_back(Box(26 * m_block_size, 7 * m_block_size, 1 * m_block_size, 1 * m_block_size, false));
    m_block_names.push_back("water_bw1.png");
    m_blocks.push_back(Box(27 * m_block_size, 7 * m_block_size, 1 * m_block_size, 1 * m_block_size, false));
    m_block_names.push_back("water_bw1.png");
    m_blocks.push_back(Box(28 * m_block_size, 7 * m_block_size, 1 * m_block_size, 1 * m_block_size, false));
    m_block_names.push_back("water_bw1.png");
    m_blocks.push_back(Box(29 * m_block_size, 7 * m_block_size, 1 * m_block_size, 1 * m_block_size, false));
    m_block_names.push_back("water_bw1.png");
    m_blocks.push_back(Box(24 * m_block_size, 8 * m_block_size, 1 * m_block_size, 1 * m_block_size, true));
    m_block_names.push_back("water_bw2.png");
    m_blocks.push_back(Box(25 * m_block_size, 8 * m_block_size, 1 * m_block_size, 1 * m_block_size, true));
    m_block_names.push_back("water_bw2.png");
    m_blocks.push_back(Box(26 * m_block_size, 8 * m_block_size, 1 * m_block_size, 1 * m_block_size, true));
    m_block_names.push_back("water_bw2.png");
    m_blocks.push_back(Box(27 * m_block_size, 8 * m_block_size, 1 * m_block_size, 1 * m_block_size, true));
    m_block_names.push_back("water_bw2.png");
    m_blocks.push_back(Box(28 * m_block_size, 8 * m_block_size, 1 * m_block_size, 1 * m_block_size, true));
    m_block_names.push_back("water_bw2.png");
    m_blocks.push_back(Box(29 * m_block_size, 8 * m_block_size, 1 * m_block_size, 1 * m_block_size, true));
    m_block_names.push_back("water_bw2.png");
    m_blocks.push_back(Box(24 * m_block_size, 9 * m_block_size, 1 * m_block_size, 1 * m_block_size, true));
    m_block_names.push_back("water_bw2.png");
    m_blocks.push_back(Box(25 * m_block_size, 9 * m_block_size, 1 * m_block_size, 1 * m_block_size, true));
    m_block_names.push_back("water_bw2.png");
    m_blocks.push_back(Box(26 * m_block_size, 9 * m_block_size, 1 * m_block_size, 1 * m_block_size, true));
    m_block_names.push_back("water_bw2.png");
    m_blocks.push_back(Box(27 * m_block_size, 9 * m_block_size, 1 * m_block_size, 1 * m_block_size, true));
    m_block_names.push_back("water_bw2.png");
    m_blocks.push_back(Box(28 * m_block_size, 9 * m_block_size, 1 * m_block_size, 1 * m_block_size, true));
    m_block_names.push_back("water_bw2.png");
    m_blocks.push_back(Box(29 * m_block_size, 9 * m_block_size, 1 * m_block_size, 1 * m_block_size, true));
    m_block_names.push_back("water_bw2.png");
    m_blocks.push_back(Box(30 * m_block_size, 7 * m_block_size, 1 * m_block_size, 1 * m_block_size, false));
    m_block_names.push_back("water_bw1.png");
    m_blocks.push_back(Box(31 * m_block_size, 7 * m_block_size, 1 * m_block_size, 1 * m_block_size, false));
    m_block_names.push_back("water_bw1.png");
    m_blocks.push_back(Box(32 * m_block_size, 7 * m_block_size, 1 * m_block_size, 1 * m_block_size, false));
    m_block_names.push_back("water_bw1.png");
    m_blocks.push_back(Box(33 * m_block_size, 7 * m_block_size, 1 * m_block_size, 1 * m_block_size, false));
    m_block_names.push_back("water_bw1.png");
    m_blocks.push_back(Box(34 * m_block_size, 7 * m_block_size, 1 * m_block_size, 1 * m_block_size, false));
    m_block_names.push_back("water_bw1.png");
    m_blocks.push_back(Box(35 * m_block_size, 7 * m_block_size, 1 * m_block_size, 1 * m_block_size, false));
    m_block_names.push_back("water_bw1.png");
    m_blocks.push_back(Box(30 * m_block_size, 8 * m_block_size, 1 * m_block_size, 1 * m_block_size, true));
    m_block_names.push_back("water_bw2.png");
    m_blocks.push_back(Box(31 * m_block_size, 8 * m_block_size, 1 * m_block_size, 1 * m_block_size, true));
    m_block_names.push_back("water_bw2.png");
    m_blocks.push_back(Box(32 * m_block_size, 8 * m_block_size, 1 * m_block_size, 1 * m_block_size, true));
    m_block_names.push_back("water_bw2.png");
    m_blocks.push_back(Box(33 * m_block_size, 8 * m_block_size, 1 * m_block_size, 1 * m_block_size, true));
    m_block_names.push_back("water_bw2.png");
    m_blocks.push_back(Box(34 * m_block_size, 8 * m_block_size, 1 * m_block_size, 1 * m_block_size, true));
    m_block_names.push_back("water_bw2.png");
    m_blocks.push_back(Box(35 * m_block_size, 8 * m_block_size, 1 * m_block_size, 1 * m_block_size, true));
    m_block_names.push_back("water_bw2.png");
    m_blocks.push_back(Box(30 * m_block_size, 9 * m_block_size, 1 * m_block_size, 1 * m_block_size, true));
    m_block_names.push_back("water_bw2.png");
    m_blocks.push_back(Box(31 * m_block_size, 9 * m_block_size, 1 * m_block_size, 1 * m_block_size, true));
    m_block_names.push_back("water_bw2.png");
    m_blocks.push_back(Box(32 * m_block_size, 9 * m_block_size, 1 * m_block_size, 1 * m_block_size, true));
    m_block_names.push_back("water_bw2.png");
    m_blocks.push_back(Box(33 * m_block_size, 9 * m_block_size, 1 * m_block_size, 1 * m_block_size, true));
    m_block_names.push_back("water_bw2.png");
    m_blocks.push_back(Box(34 * m_block_size, 9 * m_block_size, 1 * m_block_size, 1 * m_block_size, true));
    m_block_names.push_back("water_bw2.png");
    m_blocks.push_back(Box(35 * m_block_size, 9 * m_block_size, 1 * m_block_size, 1 * m_block_size, true));
    m_block_names.push_back("water_bw2.png");
    m_blocks.push_back(Box(36 * m_block_size, 7 * m_block_size, 1 * m_block_size, 1 * m_block_size, false));
    m_block_names.push_back("water_bw1.png");
    m_blocks.push_back(Box(37 * m_block_size, 7 * m_block_size, 1 * m_block_size, 1 * m_block_size, false));
    m_block_names.push_back("water_bw1.png");
    m_blocks.push_back(Box(38 * m_block_size, 7 * m_block_size, 1 * m_block_size, 1 * m_block_size, false));
    m_block_names.push_back("water_bw1.png");
    m_blocks.push_back(Box(36 * m_block_size, 8 * m_block_size, 1 * m_block_size, 1 * m_block_size, true));
    m_block_names.push_back("water_bw2.png");
    m_blocks.push_back(Box(37 * m_block_size, 8 * m_block_size, 1 * m_block_size, 1 * m_block_size, true));
    m_block_names.push_back("water_bw2.png");
    m_blocks.push_back(Box(38 * m_block_size, 8 * m_block_size, 1 * m_block_size, 1 * m_block_size, true));
    m_block_names.push_back("water_bw2.png");
    m_blocks.push_back(Box(36 * m_block_size, 9 * m_block_size, 1 * m_block_size, 1 * m_block_size, true));
    m_block_names.push_back("water_bw2.png");
    m_blocks.push_back(Box(37 * m_block_size, 9 * m_block_size, 1 * m_block_size, 1 * m_block_size, true));
    m_block_names.push_back("water_bw2.png");
    m_blocks.push_back(Box(38 * m_block_size, 9 * m_block_size, 1 * m_block_size, 1 * m_block_size, true));
    m_block_names.push_back("water_bw2.png");
    m_blocks.push_back(Box(39 * m_block_size, 7 * m_block_size, 1 * m_block_size, 1 * m_block_size, true));
    m_block_names.push_back("water_bw1.png");
    m_blocks.push_back(Box(39 * m_block_size, 8 * m_block_size, 1 * m_block_size, 1 * m_block_size, true));
    m_block_names.push_back("water_bw1.png");
    m_blocks.push_back(Box(39 * m_block_size, 9 * m_block_size, 1 * m_block_size, 1 * m_block_size, true));
    m_block_names.push_back("water_bw2.png");
    
    //1st ground layer1
    m_blocks.push_back(Box(0 * m_block_size, 7 * m_block_size, 1 * m_block_size, 1 * m_block_size, true));
    m_block_names.push_back("tiles\\Tile (5).png");
    m_blocks.push_back(Box(1 * m_block_size, 7 * m_block_size, 1 * m_block_size, 1 * m_block_size, true));
    m_block_names.push_back("tiles\\Tile (5).png");
    m_blocks.push_back(Box(2 * m_block_size, 7 * m_block_size, 1 * m_block_size, 1 * m_block_size, true));
    m_block_names.push_back("tiles\\Tile (5).png");
    m_blocks.push_back(Box(3 * m_block_size, 7 * m_block_size, 1 * m_block_size, 1 * m_block_size, true));
    m_block_names.push_back("tiles\\Tile (5).png");
    m_blocks.push_back(Box(4 * m_block_size, 7 * m_block_size, 1 * m_block_size, 1 * m_block_size, true));
    m_block_names.push_back("tiles\\Tile (5).png");
    m_blocks.push_back(Box(5 * m_block_size, 7 * m_block_size, 1 * m_block_size, 1 * m_block_size, true));
    m_block_names.push_back("tiles\\Tile (5).png");
    m_blocks.push_back(Box(6 * m_block_size, 7 * m_block_size, 1 * m_block_size, 1 * m_block_size, true));
    m_block_names.push_back("tiles\\Tile (11).png");
    m_blocks.push_back(Box(7 * m_block_size, 7 * m_block_size, 1 * m_block_size, 1 * m_block_size, true));
    m_block_names.push_back("tiles\\Tile (2).png");
    m_blocks.push_back(Box(8 * m_block_size, 7 * m_block_size, 1 * m_block_size, 1 * m_block_size, true));
    m_block_names.push_back("tiles\\Tile (2).png");
    m_blocks.push_back(Box(9 * m_block_size, 7 * m_block_size, 1 * m_block_size, 1 * m_block_size, true));
    m_block_names.push_back("tiles\\Tile (2).png");
    m_blocks.push_back(Box(10 * m_block_size, 7 * m_block_size, 1 * m_block_size, 1 * m_block_size, true));
    m_block_names.push_back("tiles\\Tile (2).png");
    m_blocks.push_back(Box(11 * m_block_size, 7 * m_block_size, 1 * m_block_size, 1 * m_block_size, true));
    m_block_names.push_back("tiles\\Tile (2).png");
    m_blocks.push_back(Box(12 * m_block_size, 7 * m_block_size, 1 * m_block_size, 1 * m_block_size, true));
    m_block_names.push_back("tiles\\Tile (2).png");
    m_blocks.push_back(Box(13 * m_block_size, 7 * m_block_size, 1 * m_block_size, 1 * m_block_size, true));
    m_block_names.push_back("tiles\\Tile (2).png");
    m_blocks.push_back(Box(14 * m_block_size, 7 * m_block_size, 1 * m_block_size, 1 * m_block_size, true));
    m_block_names.push_back("tiles\\Tile (2).png");
    m_blocks.push_back(Box(15 * m_block_size, 7 * m_block_size, 1 * m_block_size, 1 * m_block_size, true));
    m_block_names.push_back("tiles\\Tile (2).png");
    m_blocks.push_back(Box(16 * m_block_size, 7 * m_block_size, 1 * m_block_size, 1 * m_block_size, true));
    m_block_names.push_back("tiles\\Tile (2).png");
    m_blocks.push_back(Box(17 * m_block_size, 7 * m_block_size, 1 * m_block_size, 1 * m_block_size, true));
    m_block_names.push_back("tiles\\Tile (2).png");
    m_blocks.push_back(Box(18 * m_block_size, 7 * m_block_size, 1 * m_block_size, 1 * m_block_size, true));
    m_block_names.push_back("tiles\\Tile (2).png");
    m_blocks.push_back(Box(19 * m_block_size, 7 * m_block_size, 1 * m_block_size, 1 * m_block_size, true));
    m_block_names.push_back("tiles\\Tile (2).png");
    m_blocks.push_back(Box(20 * m_block_size, 7 * m_block_size, 1 * m_block_size, 1 * m_block_size, true));
    m_block_names.push_back("tiles\\Tile (2).png");
    m_blocks.push_back(Box(21 * m_block_size, 7 * m_block_size, 1 * m_block_size, 1 * m_block_size, true));
    m_block_names.push_back("tiles\\Tile (2).png");
    m_blocks.push_back(Box(22 * m_block_size, 7 * m_block_size, 1 * m_block_size, 1 * m_block_size, true));
    m_block_names.push_back("tiles\\Tile (2).png");
    m_blocks.push_back(Box(23 * m_block_size, 7 * m_block_size, 1 * m_block_size, 1 * m_block_size, true));
    m_block_names.push_back("tiles\\Tile (2).png");
    m_blocks.push_back(Box(24 * m_block_size, 7 * m_block_size, 1 * m_block_size, 1 * m_block_size, true));
    m_block_names.push_back("tiles\\Tile (3).png");

    //1st ground layer2
    m_blocks.push_back(Box(4 * m_block_size, 8 * m_block_size, 1 * m_block_size, 1 * m_block_size, true));
    m_block_names.push_back("tiles\\Tile (5).png");
    m_blocks.push_back(Box(5 * m_block_size, 8 * m_block_size, 1 * m_block_size, 1 * m_block_size, true));
    m_block_names.push_back("tiles\\Tile (5).png");
    m_blocks.push_back(Box(6 * m_block_size, 8 * m_block_size, 1 * m_block_size, 1 * m_block_size, true));
    m_block_names.push_back("tiles\\Tile (5).png");
    m_blocks.push_back(Box(7 * m_block_size, 8 * m_block_size, 1 * m_block_size, 1 * m_block_size, true));
    m_block_names.push_back("tiles\\Tile (5).png");
    m_blocks.push_back(Box(8 * m_block_size, 8 * m_block_size, 1 * m_block_size, 1 * m_block_size, true));
    m_block_names.push_back("tiles\\Tile (5).png");
    m_blocks.push_back(Box(9 * m_block_size, 8 * m_block_size, 1 * m_block_size, 1 * m_block_size, true));
    m_block_names.push_back("tiles\\Tile (5).png");
    m_blocks.push_back(Box(10 * m_block_size, 8 * m_block_size, 1 * m_block_size, 1 * m_block_size, true));
    m_block_names.push_back("tiles\\Tile (5).png");
    m_blocks.push_back(Box(11 * m_block_size, 8 * m_block_size, 1 * m_block_size, 1 * m_block_size, true));
    m_block_names.push_back("tiles\\Tile (5).png");
    m_blocks.push_back(Box(12 * m_block_size, 8 * m_block_size, 1 * m_block_size, 1 * m_block_size, true));
    m_block_names.push_back("tiles\\Tile (5).png");
    m_blocks.push_back(Box(13 * m_block_size, 8 * m_block_size, 1 * m_block_size, 1 * m_block_size, true));
    m_block_names.push_back("tiles\\Tile (5).png");
    m_blocks.push_back(Box(14 * m_block_size, 8 * m_block_size, 1 * m_block_size, 1 * m_block_size, true));
    m_block_names.push_back("tiles\\Tile (5).png");
    m_blocks.push_back(Box(15 * m_block_size, 8 * m_block_size, 1 * m_block_size, 1 * m_block_size, true));
    m_block_names.push_back("tiles\\Tile (5).png");
    m_blocks.push_back(Box(16 * m_block_size, 8 * m_block_size, 1 * m_block_size, 1 * m_block_size, true));
    m_block_names.push_back("tiles\\Tile (5).png");
    m_blocks.push_back(Box(17 * m_block_size, 8 * m_block_size, 1 * m_block_size, 1 * m_block_size, true));
    m_block_names.push_back("tiles\\Tile (5).png");
    m_blocks.push_back(Box(18 * m_block_size, 8 * m_block_size, 1 * m_block_size, 1 * m_block_size, true));
    m_block_names.push_back("tiles\\Tile (5).png");
    m_blocks.push_back(Box(19 * m_block_size, 8 * m_block_size, 1 * m_block_size, 1 * m_block_size, true));
    m_block_names.push_back("tiles\\Tile (5).png");
    m_blocks.push_back(Box(20 * m_block_size, 8 * m_block_size, 1 * m_block_size, 1 * m_block_size, true));
    m_block_names.push_back("tiles\\Tile (5).png");
    m_blocks.push_back(Box(21 * m_block_size, 8 * m_block_size, 1 * m_block_size, 1 * m_block_size, true));
    m_block_names.push_back("tiles\\Tile (5).png");
    m_blocks.push_back(Box(22 * m_block_size, 8 * m_block_size, 1 * m_block_size, 1 * m_block_size, true));
    m_block_names.push_back("tiles\\Tile (5).png");
    m_blocks.push_back(Box(23 * m_block_size, 8 * m_block_size, 1 * m_block_size, 1 * m_block_size, true));
    m_block_names.push_back("tiles\\Tile (5).png");
    m_blocks.push_back(Box(24 * m_block_size, 8 * m_block_size, 1 * m_block_size, 1 * m_block_size, true));
    m_block_names.push_back("tiles\\Tile (6).png");

    //1st ground layer3
    m_blocks.push_back(Box(4 * m_block_size, 9 * m_block_size, 1 * m_block_size, 1 * m_block_size, true));
    m_block_names.push_back("tiles\\Tile (5).png");
    m_blocks.push_back(Box(5 * m_block_size, 9 * m_block_size, 1 * m_block_size, 1 * m_block_size, true));
    m_block_names.push_back("tiles\\Tile (5).png");
    m_blocks.push_back(Box(6 * m_block_size, 9 * m_block_size, 1 * m_block_size, 1 * m_block_size, true));
    m_block_names.push_back("tiles\\Tile (5).png");
    m_blocks.push_back(Box(7 * m_block_size, 9 * m_block_size, 1 * m_block_size, 1 * m_block_size, true));
    m_block_names.push_back("tiles\\Tile (5).png");
    m_blocks.push_back(Box(8 * m_block_size, 9 * m_block_size, 1 * m_block_size, 1 * m_block_size, true));
    m_block_names.push_back("tiles\\Tile (5).png");
    m_blocks.push_back(Box(9 * m_block_size, 9 * m_block_size, 1 * m_block_size, 1 * m_block_size, true));
    m_block_names.push_back("tiles\\Tile (5).png");
    m_blocks.push_back(Box(10 * m_block_size, 9 * m_block_size, 1 * m_block_size, 1 * m_block_size, true));
    m_block_names.push_back("tiles\\Tile (5).png");
    m_blocks.push_back(Box(11 * m_block_size, 9 * m_block_size, 1 * m_block_size, 1 * m_block_size, true));
    m_block_names.push_back("tiles\\Tile (5).png");
    m_blocks.push_back(Box(12 * m_block_size, 9 * m_block_size, 1 * m_block_size, 1 * m_block_size, true));
    m_block_names.push_back("tiles\\Tile (5).png");
    m_blocks.push_back(Box(13 * m_block_size, 9 * m_block_size, 1 * m_block_size, 1 * m_block_size, true));
    m_block_names.push_back("tiles\\Tile (5).png");
    m_blocks.push_back(Box(14 * m_block_size, 9 * m_block_size, 1 * m_block_size, 1 * m_block_size, true));
    m_block_names.push_back("tiles\\Tile (5).png");
    m_blocks.push_back(Box(15 * m_block_size, 9 * m_block_size, 1 * m_block_size, 1 * m_block_size, true));
    m_block_names.push_back("tiles\\Tile (5).png");
    m_blocks.push_back(Box(16 * m_block_size, 9 * m_block_size, 1 * m_block_size, 1 * m_block_size, true));
    m_block_names.push_back("tiles\\Tile (5).png");
    m_blocks.push_back(Box(17 * m_block_size, 9 * m_block_size, 1 * m_block_size, 1 * m_block_size, true));
    m_block_names.push_back("tiles\\Tile (5).png");
    m_blocks.push_back(Box(18 * m_block_size, 9 * m_block_size, 1 * m_block_size, 1 * m_block_size, true));
    m_block_names.push_back("tiles\\Tile (5).png");
    m_blocks.push_back(Box(19 * m_block_size, 9 * m_block_size, 1 * m_block_size, 1 * m_block_size, true));
    m_block_names.push_back("tiles\\Tile (5).png");
    m_blocks.push_back(Box(20 * m_block_size, 9 * m_block_size, 1 * m_block_size, 1 * m_block_size, true));
    m_block_names.push_back("tiles\\Tile (5).png");
    m_blocks.push_back(Box(21 * m_block_size, 9 * m_block_size, 1 * m_block_size, 1 * m_block_size, true));
    m_block_names.push_back("tiles\\Tile (5).png");
    m_blocks.push_back(Box(22 * m_block_size, 9 * m_block_size, 1 * m_block_size, 1 * m_block_size, true));
    m_block_names.push_back("tiles\\Tile (5).png");
    m_blocks.push_back(Box(23 * m_block_size, 9 * m_block_size, 1 * m_block_size, 1 * m_block_size, true));
    m_block_names.push_back("tiles\\Tile (5).png");
    m_blocks.push_back(Box(24 * m_block_size, 9 * m_block_size, 1 * m_block_size, 1 * m_block_size, true));
    m_block_names.push_back("tiles\\Tile (6).png");

    //water part2
    m_blocks.push_back(Box(42 * m_block_size, 7 * m_block_size, 1 * m_block_size, 1 * m_block_size, false));
    m_block_names.push_back("water_bw1.png");
    m_blocks.push_back(Box(42 * m_block_size, 8 * m_block_size, 1 * m_block_size, 1 * m_block_size, true));
    m_block_names.push_back("water_bw2.png");
    m_blocks.push_back(Box(42 * m_block_size, 9 * m_block_size, 1 * m_block_size, 1 * m_block_size, true));
    m_block_names.push_back("water_bw2.png");
    m_blocks.push_back(Box(43 * m_block_size, 7 * m_block_size, 1 * m_block_size, 1 * m_block_size, false));
    m_block_names.push_back("water_bw1.png");
    m_blocks.push_back(Box(43 * m_block_size, 8 * m_block_size, 1 * m_block_size, 1 * m_block_size, true));
    m_block_names.push_back("water_bw2.png");
    m_blocks.push_back(Box(43 * m_block_size, 9 * m_block_size, 1 * m_block_size, 1 * m_block_size, true));
    m_block_names.push_back("water_bw2.png");
    m_blocks.push_back(Box(44 * m_block_size, 7 * m_block_size, 1 * m_block_size, 1 * m_block_size, false));
    m_block_names.push_back("water_bw1.png");
    m_blocks.push_back(Box(44 * m_block_size, 8 * m_block_size, 1 * m_block_size, 1 * m_block_size, true));
    m_block_names.push_back("water_bw2.png");
    m_blocks.push_back(Box(44 * m_block_size, 9 * m_block_size, 1 * m_block_size, 1 * m_block_size, true));
    m_block_names.push_back("water_bw2.png");
    m_blocks.push_back(Box(45 * m_block_size, 7 * m_block_size, 1 * m_block_size, 1 * m_block_size, false));
    m_block_names.push_back("water_bw1.png");
    m_blocks.push_back(Box(45 * m_block_size, 8 * m_block_size, 1 * m_block_size, 1 * m_block_size, true));
    m_block_names.push_back("water_bw2.png");
    m_blocks.push_back(Box(45 * m_block_size, 9 * m_block_size, 1 * m_block_size, 1 * m_block_size, true));
    m_block_names.push_back("water_bw2.png");
    
    //small ground1
    m_blocks.push_back(Box(39 * m_block_size, 7 * m_block_size, 1 * m_block_size, 1 * m_block_size, true));
    m_block_names.push_back("tiles\\Tile (1).png");
    m_blocks.push_back(Box(39 * m_block_size, 8 * m_block_size, 1 * m_block_size, 1 * m_block_size, true));
    m_block_names.push_back("tiles\\Tile (4).png");
    m_blocks.push_back(Box(39 * m_block_size, 9 * m_block_size, 1 * m_block_size, 1 * m_block_size, true));
    m_block_names.push_back("tiles\\Tile (4).png");
    m_blocks.push_back(Box(40 * m_block_size, 7 * m_block_size, 1 * m_block_size, 1 * m_block_size, true));
    m_block_names.push_back("tiles\\Tile (2).png");
    m_blocks.push_back(Box(40 * m_block_size, 8 * m_block_size, 1 * m_block_size, 1 * m_block_size, true));
    m_block_names.push_back("tiles\\Tile (5).png");
    m_blocks.push_back(Box(40 * m_block_size, 9 * m_block_size, 1 * m_block_size, 1 * m_block_size, true));
    m_block_names.push_back("tiles\\Tile (5).png");
    m_blocks.push_back(Box(41 * m_block_size, 7 * m_block_size, 1 * m_block_size, 1 * m_block_size, true));
    m_block_names.push_back("tiles\\Tile (2).png");
    m_blocks.push_back(Box(41 * m_block_size, 8 * m_block_size, 1 * m_block_size, 1 * m_block_size, true));
    m_block_names.push_back("tiles\\Tile (5).png");
    m_blocks.push_back(Box(41 * m_block_size, 9 * m_block_size, 1 * m_block_size, 1 * m_block_size, true));
    m_block_names.push_back("tiles\\Tile (5).png");
    m_blocks.push_back(Box(42 * m_block_size, 7 * m_block_size, 1 * m_block_size, 1 * m_block_size, true));
    m_block_names.push_back("tiles\\Tile (3).png");
    m_blocks.push_back(Box(42 * m_block_size, 8 * m_block_size, 1 * m_block_size, 1 * m_block_size, true));
    m_block_names.push_back("tiles\\Tile (6).png");
    m_blocks.push_back(Box(42 * m_block_size, 9 * m_block_size, 1 * m_block_size, 1 * m_block_size, true));
    m_block_names.push_back("tiles\\Tile (6).png");

    //water part2
    m_blocks.push_back(Box(46 * m_block_size, 7 * m_block_size, 1 * m_block_size, 1 * m_block_size, false));
    m_block_names.push_back("water_bw1.png");
    m_blocks.push_back(Box(46 * m_block_size, 8 * m_block_size, 1 * m_block_size, 1 * m_block_size, true));
    m_block_names.push_back("water_bw2.png");
    m_blocks.push_back(Box(46 * m_block_size, 9 * m_block_size, 1 * m_block_size, 1 * m_block_size, true));
    m_block_names.push_back("water_bw2.png");
    m_blocks.push_back(Box(47 * m_block_size, 7 * m_block_size, 1 * m_block_size, 1 * m_block_size, false));
    m_block_names.push_back("water_bw1.png");
    m_blocks.push_back(Box(47 * m_block_size, 8 * m_block_size, 1 * m_block_size, 1 * m_block_size, true));
    m_block_names.push_back("water_bw2.png");
    m_blocks.push_back(Box(47 * m_block_size, 9 * m_block_size, 1 * m_block_size, 1 * m_block_size, true));
    m_block_names.push_back("water_bw2.png");
    m_blocks.push_back(Box(48 * m_block_size, 7 * m_block_size, 1 * m_block_size, 1 * m_block_size, false));
    m_block_names.push_back("water_bw1.png");
    m_blocks.push_back(Box(48 * m_block_size, 8 * m_block_size, 1 * m_block_size, 1 * m_block_size, true));
    m_block_names.push_back("water_bw2.png");
    m_blocks.push_back(Box(48 * m_block_size, 9 * m_block_size, 1 * m_block_size, 1 * m_block_size, true));
    m_block_names.push_back("water_bw2.png");
    
    //small ground2
    m_blocks.push_back(Box(45 * m_block_size, 7 * m_block_size, 1 * m_block_size, 1 * m_block_size, true));
    m_block_names.push_back("tiles\\Tile (1).png");
    m_blocks.push_back(Box(45 * m_block_size, 8 * m_block_size, 1 * m_block_size, 1 * m_block_size, true));
    m_block_names.push_back("tiles\\Tile (4).png");
    m_blocks.push_back(Box(45 * m_block_size, 9 * m_block_size, 1 * m_block_size, 1 * m_block_size, true));
    m_block_names.push_back("tiles\\Tile (4).png");
    m_blocks.push_back(Box(45.5f * m_block_size, 6 * m_block_size, 1 * m_block_size, 1 * m_block_size, true));
    m_block_names.push_back("crate.png");
    m_blocks.push_back(Box(46 * m_block_size, 7 * m_block_size, 1 * m_block_size, 1 * m_block_size, true));
    m_block_names.push_back("tiles\\Tile (3).png");
    m_blocks.push_back(Box(46 * m_block_size, 8 * m_block_size, 1 * m_block_size, 1 * m_block_size, true));
    m_block_names.push_back("tiles\\Tile (6).png");
    m_blocks.push_back(Box(46 * m_block_size, 9 * m_block_size, 1 * m_block_size, 1 * m_block_size, true));
    m_block_names.push_back("tiles\\Tile (6).png");

    //small ground3
    m_blocks.push_back(Box(49 * m_block_size, 7 * m_block_size, 1 * m_block_size, 1 * m_block_size, true));
    m_block_names.push_back("tiles\\Tile (2).png");
    m_blocks.push_back(Box(49 * m_block_size, 8 * m_block_size, 1 * m_block_size, 1 * m_block_size, true));
    m_block_names.push_back("tiles\\Tile (5).png");
    m_blocks.push_back(Box(49 * m_block_size, 9 * m_block_size, 1 * m_block_size, 1 * m_block_size, true));
    m_block_names.push_back("tiles\\Tile (5).png");

    //small platforms2
    m_blocks.push_back(Box(51 * m_block_size, 6 * m_block_size, 1 * m_block_size, 1 * m_block_size, true));
    m_block_names.push_back("tiles\\Tile (14).png");
    m_blocks.push_back(Box(52 * m_block_size, 6 * m_block_size, 1 * m_block_size, 1 * m_block_size, true));
    m_block_names.push_back("tiles\\Tile (16).png");

    m_blocks.push_back(Box(55 * m_block_size, 5 * m_block_size, 1 * m_block_size, 1 * m_block_size, true));
    m_block_names.push_back("tiles\\Tile (14).png");
    m_blocks.push_back(Box(56 * m_block_size, 5 * m_block_size, 1 * m_block_size, 1 * m_block_size, true));
    m_block_names.push_back("tiles\\Tile (15).png");
    m_blocks.push_back(Box(57 * m_block_size, 5 * m_block_size, 1 * m_block_size, 1 * m_block_size, true));
    m_block_names.push_back("tiles\\Tile (15).png");
    m_blocks.push_back(Box(58 * m_block_size, 5 * m_block_size, 1 * m_block_size, 1 * m_block_size, true));
    m_block_names.push_back("tiles\\Tile (15).png");

        //water in platform
        m_blocks.push_back(Box(59 * m_block_size, 5 * m_block_size, 1 * m_block_size, 1 * m_block_size, false));
        m_block_names.push_back("water_bw1.png");
        m_blocks.push_back(Box(59 * m_block_size, 6 * m_block_size, 1 * m_block_size, 1 * m_block_size, true));
        m_block_names.push_back("water_bw2.png");
        m_blocks.push_back(Box(59 * m_block_size, 7 * m_block_size, 1 * m_block_size, 1 * m_block_size, true));
        m_block_names.push_back("water_bw2.png");
        m_blocks.push_back(Box(60 * m_block_size, 5 * m_block_size, 1 * m_block_size, 1 * m_block_size, false));
        m_block_names.push_back("water_bw1.png");
        m_blocks.push_back(Box(60 * m_block_size, 6 * m_block_size, 1 * m_block_size, 1 * m_block_size, true));
        m_block_names.push_back("water_bw2.png");
        m_blocks.push_back(Box(60 * m_block_size, 7 * m_block_size, 1 * m_block_size, 1 * m_block_size, true));
        m_block_names.push_back("water_bw2.png");
        m_blocks.push_back(Box(64 * m_block_size, 5 * m_block_size, 1 * m_block_size, 1 * m_block_size, false));
        m_block_names.push_back("water_bw1.png");
        m_blocks.push_back(Box(64 * m_block_size, 6 * m_block_size, 1 * m_block_size, 1 * m_block_size, true));
        m_block_names.push_back("water_bw2.png");
        m_blocks.push_back(Box(64 * m_block_size, 7 * m_block_size, 1 * m_block_size, 1 * m_block_size, true));
        m_block_names.push_back("water_bw2.png");
        m_blocks.push_back(Box(65 * m_block_size, 5 * m_block_size, 1 * m_block_size, 1 * m_block_size, false));
        m_block_names.push_back("water_bw1.png");
        m_blocks.push_back(Box(65 * m_block_size, 6 * m_block_size, 1 * m_block_size, 1 * m_block_size, true));
        m_block_names.push_back("water_bw2.png");
        m_blocks.push_back(Box(65 * m_block_size, 7 * m_block_size, 1 * m_block_size, 1 * m_block_size, true));
        m_block_names.push_back("water_bw2.png");

    m_blocks.push_back(Box(61 * m_block_size, 5 * m_block_size, 1 * m_block_size, 1 * m_block_size, true));
    m_block_names.push_back("tiles\\Tile (15).png");
    m_blocks.push_back(Box(61.5f * m_block_size, 4 * m_block_size, 1 * m_block_size, 1 * m_block_size, true));
    m_block_names.push_back("crate.png");
    m_blocks.push_back(Box(62 * m_block_size, 3 * m_block_size, 1 * m_block_size, 1 * m_block_size, true));
    m_block_names.push_back("crate.png");
    m_blocks.push_back(Box(62.5f * m_block_size, 4 * m_block_size, 1 * m_block_size, 1 * m_block_size, true));
    m_block_names.push_back("crate.png");
    m_blocks.push_back(Box(62 * m_block_size, 5 * m_block_size, 1 * m_block_size, 1 * m_block_size, true));
    m_block_names.push_back("tiles\\Tile (15).png");
    m_blocks.push_back(Box(63 * m_block_size, 5 * m_block_size, 1 * m_block_size, 1 * m_block_size, true));
    m_block_names.push_back("tiles\\Tile (15).png");
    m_blocks.push_back(Box(66 * m_block_size, 5 * m_block_size, 1 * m_block_size, 1 * m_block_size, true));
    m_block_names.push_back("tiles\\Tile (15).png");
    m_blocks.push_back(Box(67 * m_block_size, 5 * m_block_size, 1 * m_block_size, 1 * m_block_size, true));
    m_block_names.push_back("tiles\\Tile (15).png");
    m_blocks.push_back(Box(68 * m_block_size, 5 * m_block_size, 1 * m_block_size, 1 * m_block_size, true));
    m_block_names.push_back("tiles\\Tile (16).png");

    m_blocks.push_back(Box(71 * m_block_size, 3 * m_block_size, 1 * m_block_size, 1 * m_block_size, true));
    m_block_names.push_back("tiles\\Tile (14).png");
    m_blocks.push_back(Box(72 * m_block_size, 3 * m_block_size, 1 * m_block_size, 1 * m_block_size, true));
    m_block_names.push_back("tiles\\Tile (16).png");

    m_blocks.push_back(Box(73 * m_block_size, 2 * m_block_size, 1 * m_block_size, 1 * m_block_size, true));
    m_block_names.push_back("tiles\\Tile (14).png");
    m_blocks.push_back(Box(74 * m_block_size, 2 * m_block_size, 1 * m_block_size, 1 * m_block_size, true));
    m_block_names.push_back("tiles\\Tile (15).png");
    m_blocks.push_back(Box(75 * m_block_size, 2 * m_block_size, 1 * m_block_size, 1 * m_block_size, true));
    m_block_names.push_back("tiles\\Tile (15).png");
    m_blocks.push_back(Box(76 * m_block_size, 2 * m_block_size, 1 * m_block_size, 1 * m_block_size, true));
    m_block_names.push_back("tiles\\Tile (16).png");

    m_blocks.push_back(Box(70 * m_block_size, 0 * m_block_size, 1 * m_block_size, 1 * m_block_size, true));
    m_block_names.push_back("tiles\\Tile (14).png");
    m_blocks.push_back(Box(71 * m_block_size, 0 * m_block_size, 1 * m_block_size, 1 * m_block_size, true));
    m_block_names.push_back("tiles\\Tile (16).png");

    m_blocks.push_back(Box(79 * m_block_size, 1 * m_block_size, 1 * m_block_size, 1 * m_block_size, true));
    m_block_names.push_back("tiles\\Tile (14).png");
    m_blocks.push_back(Box(80 * m_block_size, 1 * m_block_size, 1 * m_block_size, 1 * m_block_size, true));
    m_block_names.push_back("tiles\\Tile (16).png");

    m_blocks.push_back(Box(69 * m_block_size, -2 * m_block_size, 1 * m_block_size, 1 * m_block_size, false));
    m_block_names.push_back("portal.png");

}

void Level3::loadLevelSpecificCherries() {
    m_cherries.clear();

    m_cherries.push_back(new Cherry(Box(9.0f, 6.0f, 0.5f, 0.5f, false)));
    m_cherries.push_back(new Cherry(Box(15.0f, 6.0f, 0.5f, 0.5f, false)));
    m_cherries.push_back(new Cherry(Box(18.0f, 3.0f, 0.5f, 0.5f, false)));
    m_cherries.push_back(new Cherry(Box(18.0f, 2.0f, 0.5f, 0.5f, false)));
    m_cherries.push_back(new Cherry(Box(21.0f, 6.0f, 0.5f, 0.5f, false)));
    m_cherries.push_back(new Cherry(Box(24.0f, 4.0f, 0.5f, 0.5f, false)));
    m_cherries.push_back(new Cherry(Box(27.0f, 3.0f, 0.5f, 0.5f, false)));
    m_cherries.push_back(new Cherry(Box(32.5f, 2.0f, 0.5f, 0.5f, false)));
    m_cherries.push_back(new Cherry(Box(36.5f, 4.0f, 0.5f, 0.5f, false)));
    m_cherries.push_back(new Cherry(Box(36.5f, 3.0f, 0.5f, 0.5f, false)));
    m_cherries.push_back(new Cherry(Box(36.5f, 2.0f, 0.5f, 0.5f, false)));
    m_cherries.push_back(new Cherry(Box(40.0f, 6.0f, 0.5f, 0.5f, false)));
    m_cherries.push_back(new Cherry(Box(41.0f, 6.0f, 0.5f, 0.5f, false)));
    m_cherries.push_back(new Cherry(Box(45.5f, 5.0f, 0.5f, 0.5f, false)));
    m_cherries.push_back(new Cherry(Box(51.5f, 5.0f, 0.5f, 0.5f, false)));
    m_cherries.push_back(new Cherry(Box(58.0f, 4.0f, 0.5f, 0.5f, false)));
    m_cherries.push_back(new Cherry(Box(62.0f, 1.0f, 0.5f, 0.5f, false)));
    m_cherries.push_back(new Cherry(Box(62.0f, 0.0f, 0.5f, 0.5f, false)));
    m_cherries.push_back(new Cherry(Box(67.0f, 4.0f, 0.5f, 0.5f, false)));
    m_cherries.push_back(new Cherry(Box(71.5f, 2.0f, 0.5f, 0.5f, false)));
    m_cherries.push_back(new Cherry(Box(74.0f, 1.0f, 0.5f, 0.5f, false)));
    m_cherries.push_back(new Cherry(Box(75.0f, 1.0f, 0.5f, 0.5f, false)));
    m_cherries.push_back(new Cherry(Box(70.5f, -1.0f, 0.5f, 0.5f, false)));
    m_cherries.push_back(new Cherry(Box(79.5f, 0.0f, 0.5f, 0.5f, false)));


    for (const auto& cherry : m_cherries) {
        cherry->init();
    }

}

void Level3::checkCollisions() {
    bool groundCollision = false;
    int index = 0;

    for (auto& box : m_blocks) {
        float offset = 0.0f;
        index++;

        if (!groundCollision && box.canCollide && (offset = m_state->getPlayer()->intersectDown(box)) != 0.0f) {
            m_state->getPlayer()->m_pos_y += offset;
            m_state->getPlayer()->m_vy = 0.0f;
            groundCollision = true;
            if (m_block_names[index] == "water_bw2.png" && !m_state->getPlayer()->isDead) {
                
                m_state->getPlayer()->health -= 2;
                m_state->getPlayer()->takeDamage();

                m_state->getPlayer()->m_pos_y += offset;
                m_state->getPlayer()->m_vy = 0.0f;
            }
        }

        if (!groundCollision && box.canCollide && (offset = m_state->getPlayer()->intersectUp(box)) != 0.0f) {
            m_state->getPlayer()->m_pos_y += offset;
            m_state->getPlayer()->m_vy = 0.0f;
            m_state->getPlayer()->ceilingCol = true;
        }
    }

    for (auto& box : m_blocks) {
        float offset = 0.0f;
        if (box.canCollide && (offset = m_state->getPlayer()->intersectSideways(box)) != 0.0f) {
            {
                m_state->getPlayer()->m_pos_x += offset;
                m_state->getPlayer()->m_vx = 0.0f;
            }
        }
    }

    for (auto& dynamic : m_dynamic_objects) {
        Skeleton* skeleton = dynamic_cast<Skeleton*>(dynamic);
        if (skeleton && m_state->getPlayer()->intersect(*skeleton)) {
            m_state->getPlayer()->takeDamage();
        }
    }

    for (auto it = m_cherries.begin(); it != m_cherries.end(); ) {
        if (m_state->getPlayer()->intersect(*static_cast<Box*>(*it))) {

            graphics::playSound("assets/cherry sound.wav", 0.8f);

            m_cherryCount++;

            it = m_cherries.erase(it);
        }
        else {
            ++it;
        }
    }
}

void Level3::checkEndLevel() {
    if (m_state->getPlayer()->m_pos_x >= 69 && m_state->getPlayer()->m_pos_x <= 70 && m_state->getPlayer()->m_pos_y <= -2
        && m_cherryCount == 24) {
        m_state->setLevel(4);
    }
}

void Level3::checkOutOfBounds() {
    if (m_state->getPlayer()->m_pos_x >= 85 || m_state->getPlayer()->m_pos_y >= 8) {
        m_state->getPlayer()->health = 0;
    }
}

std::string Level3::getBlockTexture(int i) const {
    return m_state->getFullAssetPath(m_block_names[i]);
}

std::string Level3::getBkgndTexture() const {
    return m_state->getFullAssetPath("bg_lvl3.png");
}