#include "level1.h"
#include "gamestate.h"

Level1::Level1(const std::string& name) : Level(name)
{
}

Level1::~Level1()
{

    for (const auto& p_gob : m_dynamic_objects)
        if (p_gob) delete p_gob;
}

void Level1::loadPlayerCoords() {
    player_x = m_state->m_canvas_width / 2.0f;
    player_y = m_state->m_canvas_height / 2.0f + 1.0f;
}

void Level1::loadLevelSpecificCherries() {
    m_cherries.clear();

    m_cherries.push_back(new Cherry(Box(7.0f, 9.0f, 0.5f, 0.5f, false)));
    m_cherries.push_back(new Cherry(Box(10.0f, 4.0f, 0.5f, 0.5f, false)));
    m_cherries.push_back(new Cherry(Box(12.0f, 4.0f, 0.5f, 0.5f, false)));
    m_cherries.push_back(new Cherry(Box(13.5f, 6.0f, 0.5f, 0.5f, false)));

    //cherry above crate
    m_cherries.push_back(new Cherry(Box(23.0f, 7.0f, 0.5f, 0.5f, false)));

    //cherries small platforms above water
    m_cherries.push_back(new Cherry(Box(27.25f, 7.0f, 0.5f, 0.5f, false)));
    m_cherries.push_back(new Cherry(Box(28.75f, 5.0f, 0.5f, 0.5f, false)));
    m_cherries.push_back(new Cherry(Box(30.25f, 7.0f, 0.5f, 0.5f, false)));
    m_cherries.push_back(new Cherry(Box(31.75f, 5.0f, 0.5f, 0.5f, false)));
    m_cherries.push_back(new Cherry(Box(33.25f, 7.0f, 0.5f, 0.5f, false)));
    m_cherries.push_back(new Cherry(Box(34.75f, 5.0f, 0.5f, 0.5f, false)));
    m_cherries.push_back(new Cherry(Box(36.25f, 7.0f, 0.5f, 0.5f, false)));
    m_cherries.push_back(new Cherry(Box(37.75f, 5.0f, 0.5f, 0.5f, false)));
    m_cherries.push_back(new Cherry(Box(39.25f, 7.0f, 0.5f, 0.5f, false)));

    //cherries above very big platform
    m_cherries.push_back(new Cherry(Box(53.0f, 3.8f, 0.5f, 0.5f, false)));
    m_cherries.push_back(new Cherry(Box(54.0f, 4.0f, 0.5f, 0.5f, false)));
    m_cherries.push_back(new Cherry(Box(55.0f, 4.0f, 0.5f, 0.5f, false)));
    m_cherries.push_back(new Cherry(Box(56.0f, 4.0f, 0.5f, 0.5f, false)));
    m_cherries.push_back(new Cherry(Box(57.0f, 4.0f, 0.5f, 0.5f, false)));
    m_cherries.push_back(new Cherry(Box(58.0f, 4.0f, 0.5f, 0.5f, false)));
    m_cherries.push_back(new Cherry(Box(59.0f, 4.0f, 0.5f, 0.5f, false)));
    m_cherries.push_back(new Cherry(Box(60.0f, 4.0f, 0.5f, 0.5f, false)));
    m_cherries.push_back(new Cherry(Box(61.0f, 3.8f, 0.5f, 0.5f, false)));

    //cherries between crystals
    m_cherries.push_back(new Cherry(Box(70.0f, 9.0f, 0.5f, 0.5f, false)));
    m_cherries.push_back(new Cherry(Box(72.0f, 9.0f, 0.5f, 0.5f, false)));

    //cherries above trees
    m_cherries.push_back(new Cherry(Box(78.0f, 3.0f, 0.5f, 0.5f, false)));
    m_cherries.push_back(new Cherry(Box(79.0f, 3.0f, 0.5f, 0.5f, false)));
    m_cherries.push_back(new Cherry(Box(80.0f, 3.0f, 0.5f, 0.5f, false)));
    m_cherries.push_back(new Cherry(Box(81.0f, 3.0f, 0.5f, 0.5f, false)));
    m_cherries.push_back(new Cherry(Box(82.0f, 3.0f, 0.5f, 0.5f, false)));

    m_cherries.push_back(new Cherry(Box(86.0f, 7.0f, 0.5f, 0.5f, false)));

    //cherries before igloo
    m_cherries.push_back(new Cherry(Box(89.0f, 8.0f, 0.5f, 0.5f, false)));
    m_cherries.push_back(new Cherry(Box(90.0f, 9.0f, 0.5f, 0.5f, false)));
    m_cherries.push_back(new Cherry(Box(91.0f, 8.0f, 0.5f, 0.5f, false)));
    m_cherries.push_back(new Cherry(Box(92.0f, 9.0f, 0.5f, 0.5f, false)));
    m_cherries.push_back(new Cherry(Box(93.0f, 8.0f, 0.5f, 0.5f, false)));
    m_cherries.push_back(new Cherry(Box(94.0f, 9.0f, 0.5f, 0.5f, false)));
    m_cherries.push_back(new Cherry(Box(95.0f, 8.0f, 0.5f, 0.5f, false)));
    m_cherries.push_back(new Cherry(Box(96.0f, 9.0f, 0.5f, 0.5f, false)));
    m_cherries.push_back(new Cherry(Box(97.0f, 8.0f, 0.5f, 0.5f, false)));
    m_cherries.push_back(new Cherry(Box(98.0f, 9.0f, 0.5f, 0.5f, false)));

    // Call `init` for each cherry
    for (auto& cherry : m_cherries) {
        cherry->init(); // Explicitly call init
    }
}

void Level1::loadLevelSpecificBlocks() {

    m_blocks.clear();
    m_block_names.clear();

    // blocks behind player
    for (int i = -3; i < 0; i++) { // x positions from -3 to -1
        for (int j = 5; j < 11; j++) { // y positions from 5 to 10
            m_blocks.push_back(Box(i * m_block_size, j * m_block_size, 1 * m_block_size, 1 * m_block_size, true));
            m_block_names.push_back("Icebox.png");
        }
    }
    for (int i = -3; i < 1; i++) {
        m_blocks.push_back(Box(i * m_block_size, 11 * m_block_size, 1 * m_block_size, 1 * m_block_size, true));
        m_block_names.push_back(i == -3 ? "19.png" : "20.png");
        m_blocks.push_back(Box(i * m_block_size, 12 * m_block_size, 1 * m_block_size, 1 * m_block_size, true));
        m_block_names.push_back("5.png");
        m_blocks.push_back(Box(i * m_block_size, 13 * m_block_size, 1 * m_block_size, 1 * m_block_size, true));
        m_block_names.push_back("5.png");
        m_blocks.push_back(Box(i * m_block_size, 14 * m_block_size, 1 * m_block_size, 1 * m_block_size, true));
        m_block_names.push_back("9.png");
    }

    //1st block of land

    for (int i = 1; i < 8; i++) {
        m_blocks.push_back(Box(i * m_block_size, 11 * m_block_size, 1 * m_block_size, 1 * m_block_size, true));
        m_block_names.push_back((i == 0) ? "20.png" : "2.png");
        m_blocks.push_back(Box(i * m_block_size, 11 * m_block_size, 1 * m_block_size, 1 * m_block_size, true));
        m_block_names.push_back((i == 7) ? "7.png" : "2.png");
        m_blocks.push_back(Box(i * m_block_size, 12 * m_block_size, 1 * m_block_size, 1 * m_block_size, true));
        m_block_names.push_back("5.png");
        m_blocks.push_back(Box(i * m_block_size, 13 * m_block_size, 1 * m_block_size, 1 * m_block_size, true));
        m_block_names.push_back("5.png");
        m_blocks.push_back(Box(i * m_block_size, 14 * m_block_size, 1 * m_block_size, 1 * m_block_size, true));
        m_block_names.push_back("9.png");
    }
    m_blocks.push_back(Box(4 * m_block_size, 9 * m_block_size, 2 * m_block_size, 3 * m_block_size, false));
    m_block_names.push_back("Tree_1.png");

    //Iceblocks above
    for (int j = -1; j < 11; j++) {
        m_blocks.push_back(Box(0 * m_block_size, j * m_block_size, 1 * m_block_size, 1 * m_block_size, true));
        m_block_names.push_back("Icebox.png");
    }

    for (int j = -1; j < 10; j++) {
        m_blocks.push_back(Box(1 * m_block_size, j * m_block_size, 1 * m_block_size, 1 * m_block_size, true));
        m_block_names.push_back("Icebox.png");
    }

    for (int j = -1; j < 9; j++) {
        m_blocks.push_back(Box(2 * m_block_size, j * m_block_size, 1 * m_block_size, 1 * m_block_size, true));
        m_block_names.push_back("Icebox.png");
    }

    for (int j = -1; j < 8; j++) {
        m_blocks.push_back(Box(3 * m_block_size, j * m_block_size, 1 * m_block_size, 1 * m_block_size, true));
        m_block_names.push_back("Icebox.png");
    }

    for (int j = -1; j < 7; j++) {
        m_blocks.push_back(Box(4 * m_block_size, j * m_block_size, 1 * m_block_size, 1 * m_block_size, true));
        m_block_names.push_back("Icebox.png");
    }

    for (int j = -1; j < 6; j++) {
        m_blocks.push_back(Box(5 * m_block_size, j * m_block_size, 1 * m_block_size, 1 * m_block_size, true));
        m_block_names.push_back("Icebox.png");
    }

    for (int j = -1; j < 5; j++) {
        m_blocks.push_back(Box(6 * m_block_size, j * m_block_size, 1 * m_block_size, 1 * m_block_size, true));
        m_block_names.push_back("Icebox.png");
    }

    for (int j = -1; j < 4; j++) {
        m_blocks.push_back(Box(7 * m_block_size, j * m_block_size, 1 * m_block_size, 1 * m_block_size, true));
        m_block_names.push_back("Icebox.png");
    }

    // 1st water

    for (int i = 8; i < 20; i++) {
        m_blocks.push_back(Box(i * m_block_size, 11 * m_block_size, 1 * m_block_size, 1 * m_block_size, true));
        m_block_names.push_back("17.png");
        for (int j = 12; j < 15; j++) {
            m_blocks.push_back(Box(i * m_block_size, j * m_block_size, 1 * m_block_size, 1 * m_block_size, true));
            m_block_names.push_back("18.png");
        }
    }

    // Big platform above water (middle)
    m_blocks.push_back(Box(10 * m_block_size, 5 * m_block_size, 1 * m_block_size, 1 * m_block_size, true));
    m_block_names.push_back("14.png");
    m_blocks.push_back(Box(11 * m_block_size, 5 * m_block_size, 1 * m_block_size, 1 * m_block_size, true));
    m_block_names.push_back("15.png");
    m_blocks.push_back(Box(12 * m_block_size, 5 * m_block_size, 1 * m_block_size, 1 * m_block_size, true));
    m_block_names.push_back("16.png");
    m_blocks.push_back(Box(11 * m_block_size, 4 * m_block_size, 1 * m_block_size, 1 * m_block_size, false));
    m_block_names.push_back("Sign_2.png");

    // Small platform above water (left)
    m_blocks.push_back(Box(8 * m_block_size, 8 * m_block_size, 1 * m_block_size, 1 * m_block_size, true));
    m_block_names.push_back("14.png");
    m_blocks.push_back(Box(9 * m_block_size, 8 * m_block_size, 1 * m_block_size, 1 * m_block_size, true));
    m_block_names.push_back("16.png");
    m_blocks.push_back(Box(9.2 * m_block_size, 7 * m_block_size, 0.5 * m_block_size, 1.0 * m_block_size, false));
    m_block_names.push_back("Crystal.png");

    // Platform above water (right)
    m_blocks.push_back(Box(14 * m_block_size, 8 * m_block_size, 1 * m_block_size, 1 * m_block_size, true));
    m_block_names.push_back("14.png");
    m_blocks.push_back(Box(15 * m_block_size, 8 * m_block_size, 1 * m_block_size, 1 * m_block_size, true));
    m_block_names.push_back("15.png");
    m_blocks.push_back(Box(16 * m_block_size, 8 * m_block_size, 1 * m_block_size, 1 * m_block_size, true));
    m_block_names.push_back("15.png");
    m_blocks.push_back(Box(17 * m_block_size, 8 * m_block_size, 1 * m_block_size, 1 * m_block_size, true));
    m_block_names.push_back("16.png");
    //decorations
    m_blocks.push_back(Box(15.5 * m_block_size, 7 * m_block_size, 1.5 * m_block_size, 1 * m_block_size, false));
    m_block_names.push_back("Stone.png");
    m_blocks.push_back(Box(16.3 * m_block_size, 7.3 * m_block_size, 0.5 * m_block_size, 0.5 * m_block_size, false));
    m_block_names.push_back("Crystal.png");
    m_blocks.push_back(Box(14.7 * m_block_size, 7.3 * m_block_size, 0.5 * m_block_size, 0.5 * m_block_size, false));
    m_block_names.push_back("Crystal.png");


    // 2nd block of land

    for (int i = 20; i < 26; i++) {
        m_blocks.push_back(Box(i * m_block_size, 11 * m_block_size, 1 * m_block_size, 1 * m_block_size, true));
        m_block_names.push_back((i == 20) ? "11.png" : "2.png");
        m_blocks.push_back(Box(i * m_block_size, 11 * m_block_size, 1 * m_block_size, 1 * m_block_size, true));
        m_block_names.push_back((i == 25) ? "7.png" : "2.png");
        m_blocks.push_back(Box(i * m_block_size, 12 * m_block_size, 1 * m_block_size, 1 * m_block_size, true));
        m_block_names.push_back("5.png");
        m_blocks.push_back(Box(i * m_block_size, 13 * m_block_size, 1 * m_block_size, 1 * m_block_size, true));
        m_block_names.push_back("5.png");
        m_blocks.push_back(Box(i * m_block_size, 14 * m_block_size, 1 * m_block_size, 1 * m_block_size, true));
        m_block_names.push_back("9.png");
    }

    // Crates
    m_blocks.push_back(Box(22 * m_block_size, 10 * m_block_size, 1 * m_block_size, 1 * m_block_size, true));
    m_block_names.push_back("Crate.png");
    m_blocks.push_back(Box(23 * m_block_size, 10 * m_block_size, 1 * m_block_size, 1 * m_block_size, true));
    m_block_names.push_back("Crate.png");
    m_blocks.push_back(Box(24 * m_block_size, 10 * m_block_size, 1 * m_block_size, 1 * m_block_size, true));
    m_block_names.push_back("Crate.png");
    m_blocks.push_back(Box(22.5 * m_block_size, 9 * m_block_size, 1 * m_block_size, 1 * m_block_size, true));
    m_block_names.push_back("Crate.png");
    m_blocks.push_back(Box(23.5 * m_block_size, 9 * m_block_size, 1 * m_block_size, 1 * m_block_size, true));
    m_block_names.push_back("Crate.png");
    m_blocks.push_back(Box(23 * m_block_size, 8 * m_block_size, 1 * m_block_size, 1 * m_block_size, true));
    m_block_names.push_back("Crate.png");



    // 2nd block of water

    for (int i = 26; i < 43; i++) {
        m_blocks.push_back(Box(i * m_block_size, 11 * m_block_size, 1 * m_block_size, 1 * m_block_size, true));
        m_block_names.push_back("17.png");
        for (int j = 12; j < 15; j++) {
            m_blocks.push_back(Box(i * m_block_size, j * m_block_size, 1 * m_block_size, 1 * m_block_size, true));
            m_block_names.push_back("18.png");
        }
    }




    // Small platforms with cherries

    for (float i = 27.0f; i < 42.0f; i += 3.0f) {
        m_blocks.push_back(Box(i * m_block_size, 8 * m_block_size, 0.5 * m_block_size, 0.5 * m_block_size, true));
        m_block_names.push_back("14.png");
    }

    for (float i = 27.5f; i < 42.5f; i += 3.0f) {
        m_blocks.push_back(Box(i * m_block_size, 8 * m_block_size, 0.5 * m_block_size, 0.5 * m_block_size, true));
        m_block_names.push_back("16.png");
    }



    //3rd block of land
    for (int i = 43; i < 47; i++) {
        m_blocks.push_back(Box(i * m_block_size, 11 * m_block_size, 1 * m_block_size, 1 * m_block_size, true));
        m_block_names.push_back((i == 43) ? "11.png" : "2.png");
        m_blocks.push_back(Box(i * m_block_size, 11 * m_block_size, 1 * m_block_size, 1 * m_block_size, true));
        m_block_names.push_back((i == 46) ? "7.png" : "2.png");
        m_blocks.push_back(Box(i * m_block_size, 12 * m_block_size, 1 * m_block_size, 1 * m_block_size, true));
        m_block_names.push_back("5.png");
        m_blocks.push_back(Box(i * m_block_size, 13 * m_block_size, 1 * m_block_size, 1 * m_block_size, true));
        m_block_names.push_back("5.png");
        m_blocks.push_back(Box(i * m_block_size, 14 * m_block_size, 1 * m_block_size, 1 * m_block_size, true));
        m_block_names.push_back("9.png");
    }

    m_blocks.push_back(Box(44 * m_block_size, 9 * m_block_size, 2 * m_block_size, 3 * m_block_size, false));
    m_block_names.push_back("Tree_1.png");
    m_blocks.push_back(Box(44.5 * m_block_size, 10 * m_block_size, 2 * m_block_size, 1 * m_block_size, false));
    m_block_names.push_back("iglooleft.png");
    m_blocks.push_back(Box(45 * m_block_size, 9.5 * m_block_size, 1 * m_block_size, 2 * m_block_size, false));
    m_block_names.push_back("Tree_2.png");

    // 3rd block of water

    for (int i = 47; i < 68; i++) {
        m_blocks.push_back(Box(i * m_block_size, 11 * m_block_size, 1 * m_block_size, 1 * m_block_size, true));
        m_block_names.push_back("17.png");
        for (int j = 12; j < 15; j++) {
            m_blocks.push_back(Box(i * m_block_size, j * m_block_size, 1 * m_block_size, 1 * m_block_size, true));
            m_block_names.push_back("18.png");
        }
    }


    //step for platform
    m_blocks.push_back(Box(49 * m_block_size, 8 * m_block_size, 0.5 * m_block_size, 0.5 * m_block_size, true));
    m_block_names.push_back("14.png");
    m_blocks.push_back(Box(49.5 * m_block_size, 8 * m_block_size, 0.5 * m_block_size, 0.5 * m_block_size, true));
    m_block_names.push_back("16.png");

    //long platform 
    m_blocks.push_back(Box(52 * m_block_size, 5.5 * m_block_size, 1.0 * m_block_size, 1.0 * m_block_size, true));
    m_block_names.push_back("14.png");
    for (int i = 53; i < 62; i++) {
        m_blocks.push_back(Box(i * m_block_size, 5.5 * m_block_size, 1.0 * m_block_size, 1.0 * m_block_size, true));
        m_block_names.push_back("15.png");
    }
    m_blocks.push_back(Box(62 * m_block_size, 5.5 * m_block_size, 1.0 * m_block_size, 1.0 * m_block_size, true));
    m_block_names.push_back("16.png");
    //decorations
    m_blocks.push_back(Box(57.5 * m_block_size, 4.4 * m_block_size, 3.0 * m_block_size, 3.0 * m_block_size, false));
    m_block_names.push_back("Snowman.png");
    m_blocks.push_back(Box(52.75 * m_block_size, 4.8 * m_block_size, 0.5 * m_block_size, 0.5 * m_block_size, false));
    m_block_names.push_back("Icebox.png");
    m_blocks.push_back(Box(53.25 * m_block_size, 4.8 * m_block_size, 0.5 * m_block_size, 0.5 * m_block_size, false));
    m_block_names.push_back("Icebox.png");
    m_blocks.push_back(Box(53 * m_block_size, 4.3 * m_block_size, 0.5 * m_block_size, 0.5 * m_block_size, false));
    m_block_names.push_back("Icebox.png");
    m_blocks.push_back(Box(53 * m_block_size, 4.8 * m_block_size, 0.5 * m_block_size, 0.5 * m_block_size, false));
    m_block_names.push_back("Stone.png");
    m_blocks.push_back(Box(52.8 * m_block_size, 4.85 * m_block_size, 0.4 * m_block_size, 0.35 * m_block_size, false));
    m_block_names.push_back("Stone.png");
    m_blocks.push_back(Box(53.3 * m_block_size, 4.9 * m_block_size, 0.3 * m_block_size, 0.3 * m_block_size, false));
    m_block_names.push_back("Stone.png");
    m_blocks.push_back(Box(60.75 * m_block_size, 4.8 * m_block_size, 0.5 * m_block_size, 0.5 * m_block_size, false));
    m_block_names.push_back("Crate.png");
    m_blocks.push_back(Box(61 * m_block_size, 4.3 * m_block_size, 0.5 * m_block_size, 0.5 * m_block_size, false));
    m_block_names.push_back("Crate.png");
    m_blocks.push_back(Box(61.25 * m_block_size, 4.8 * m_block_size, 0.5 * m_block_size, 0.5 * m_block_size, false));
    m_block_names.push_back("Crate.png");



    //step for platform(right)
    m_blocks.push_back(Box(64.5 * m_block_size, 8 * m_block_size, 0.5 * m_block_size, 0.5 * m_block_size, true));
    m_block_names.push_back("14.png");
    m_blocks.push_back(Box(65 * m_block_size, 8 * m_block_size, 0.5 * m_block_size, 0.5 * m_block_size, true));
    m_block_names.push_back("16.png");

    //4th block of land

    for (int i = 68; i < 75; i++) {
        m_blocks.push_back(Box(i * m_block_size, 11 * m_block_size, 1 * m_block_size, 1 * m_block_size, true));
        m_block_names.push_back((i == 68) ? "11.png" : "2.png");
        m_blocks.push_back(Box(i * m_block_size, 11 * m_block_size, 1 * m_block_size, 1 * m_block_size, true));
        m_block_names.push_back((i == 74) ? "7.png" : "2.png");
        m_blocks.push_back(Box(i * m_block_size, 12 * m_block_size, 1 * m_block_size, 1 * m_block_size, true));
        m_block_names.push_back("5.png");
        m_blocks.push_back(Box(i * m_block_size, 13 * m_block_size, 1 * m_block_size, 1 * m_block_size, true));
        m_block_names.push_back("5.png");
        m_blocks.push_back(Box(i * m_block_size, 14 * m_block_size, 1 * m_block_size, 1 * m_block_size, true));
        m_block_names.push_back("9.png");
    }
    //crystals
    m_blocks.push_back(Box(69 * m_block_size, 10 * m_block_size, 1.0 * m_block_size, 1 * m_block_size, true));
    m_block_names.push_back("Crystal.png");
    m_blocks.push_back(Box(71 * m_block_size, 10 * m_block_size, 1.0 * m_block_size, 1 * m_block_size, true));
    m_block_names.push_back("Crystal.png");
    m_blocks.push_back(Box(73 * m_block_size, 10 * m_block_size, 1 * m_block_size, 1 * m_block_size, true));
    m_block_names.push_back("Crystal.png");

    //4th block of water
    for (int i = 75; i < 78; i++) {
        m_blocks.push_back(Box(i * m_block_size, 11 * m_block_size, 1 * m_block_size, 1 * m_block_size, true));
        m_block_names.push_back("17.png");
        for (int j = 12; j < 15; j++) {
            m_blocks.push_back(Box(i * m_block_size, j * m_block_size, 1 * m_block_size, 1 * m_block_size, true));
            m_block_names.push_back("18.png");
        }
    }

    //higher block of land
    for (int i = 78; i < 83; i++) {
        m_blocks.push_back(Box(i * m_block_size, 7 * m_block_size, 1 * m_block_size, 1 * m_block_size, true));
        m_block_names.push_back((i == 78) ? "11.png" : "2.png");
        m_blocks.push_back(Box(i * m_block_size, 7 * m_block_size, 1 * m_block_size, 1 * m_block_size, true));
        m_block_names.push_back((i == 82) ? "7.png" : "2.png");
        for (int j = 8; j < 14; j++) {
            m_blocks.push_back(Box(i * m_block_size, j * m_block_size, 1 * m_block_size, 1 * m_block_size, true));
            m_block_names.push_back("5.png");
        }
        m_blocks.push_back(Box(i * m_block_size, 14 * m_block_size, 1 * m_block_size, 1 * m_block_size, true));
        m_block_names.push_back("9.png");
    }
    //decorations
    m_blocks.push_back(Box(79 * m_block_size, 5 * m_block_size, 2 * m_block_size, 3 * m_block_size, false));
    m_block_names.push_back("Tree_1.png");
    m_blocks.push_back(Box(82 * m_block_size, 5.5 * m_block_size, 1 * m_block_size, 2 * m_block_size, false));
    m_block_names.push_back("Tree_2.png");

    //5th block of water

    for (int i = 83; i < 89; i++) {
        m_blocks.push_back(Box(i * m_block_size, 11 * m_block_size, 1 * m_block_size, 1 * m_block_size, true));
        m_block_names.push_back("17.png");
        for (int j = 12; j < 15; j++) {
            m_blocks.push_back(Box(i * m_block_size, j * m_block_size, 1 * m_block_size, 1 * m_block_size, true));
            m_block_names.push_back("18.png");
        }
    }

    //small platform
    m_blocks.push_back(Box(85.5 * m_block_size, 8 * m_block_size, 0.5 * m_block_size, 0.5 * m_block_size, true));
    m_block_names.push_back("14.png");
    m_blocks.push_back(Box(86 * m_block_size, 8 * m_block_size, 0.5 * m_block_size, 0.5 * m_block_size, true));
    m_block_names.push_back("16.png");
    //crystal
    m_blocks.push_back(Box(85.5 * m_block_size, 7.3 * m_block_size, 0.5 * m_block_size, 1.0 * m_block_size, false));
    m_block_names.push_back("Crystal.png");

    //last block of land
    for (int i = 89; i < 103; i++) {
        m_blocks.push_back(Box(i * m_block_size, 11 * m_block_size, 1 * m_block_size, 1 * m_block_size, true));
        m_block_names.push_back((i == 89) ? "11.png" : "2.png");
        m_blocks.push_back(Box(i * m_block_size, 11 * m_block_size, 1 * m_block_size, 1 * m_block_size, true));
        m_block_names.push_back((i == 102) ? "7.png" : "2.png");
        m_blocks.push_back(Box(i * m_block_size, 12 * m_block_size, 1 * m_block_size, 1 * m_block_size, true));
        m_block_names.push_back("5.png");
        m_blocks.push_back(Box(i * m_block_size, 13 * m_block_size, 1 * m_block_size, 1 * m_block_size, true));
        m_block_names.push_back("5.png");
        m_blocks.push_back(Box(i * m_block_size, 14 * m_block_size, 1 * m_block_size, 1 * m_block_size, true));
        m_block_names.push_back("9.png");
    }

    //decorations
    m_blocks.push_back(Box(92 * m_block_size, 10 * m_block_size, 1 * m_block_size, 1 * m_block_size, false));
    m_block_names.push_back("Sign_2.png");

    m_blocks.push_back(Box(94.5 * m_block_size, 10.3 * m_block_size, 0.5 * m_block_size, 0.5 * m_block_size, false));
    m_block_names.push_back("Icebox.png");
    m_blocks.push_back(Box(95 * m_block_size, 10.3 * m_block_size, 0.5 * m_block_size, 0.5 * m_block_size, false));
    m_block_names.push_back("Icebox.png");
    m_blocks.push_back(Box(95.5 * m_block_size, 10.3 * m_block_size, 0.5 * m_block_size, 0.5 * m_block_size, false));
    m_block_names.push_back("Icebox.png");
    m_blocks.push_back(Box(96 * m_block_size, 10.3 * m_block_size, 0.5 * m_block_size, 0.5 * m_block_size, false));
    m_block_names.push_back("Icebox.png");
    m_blocks.push_back(Box(94.75 * m_block_size, 9.8 * m_block_size, 0.5 * m_block_size, 0.5 * m_block_size, false));
    m_block_names.push_back("Icebox.png");
    m_blocks.push_back(Box(95.25 * m_block_size, 9.8 * m_block_size, 0.5 * m_block_size, 0.5 * m_block_size, false));
    m_block_names.push_back("Icebox.png");
    m_blocks.push_back(Box(95.75 * m_block_size, 9.8 * m_block_size, 0.5 * m_block_size, 0.5 * m_block_size, false));
    m_block_names.push_back("Icebox.png");
    m_blocks.push_back(Box(95 * m_block_size, 9.3 * m_block_size, 0.5 * m_block_size, 0.5 * m_block_size, false));
    m_block_names.push_back("Icebox.png");
    m_blocks.push_back(Box(95.5 * m_block_size, 9.3 * m_block_size, 0.5 * m_block_size, 0.5 * m_block_size, false));
    m_block_names.push_back("Icebox.png");
    m_blocks.push_back(Box(95.25 * m_block_size, 8.8 * m_block_size, 0.5 * m_block_size, 0.5 * m_block_size, false));
    m_block_names.push_back("Icebox.png");

    m_blocks.push_back(Box(101 * m_block_size, 8.0 * m_block_size, 4 * m_block_size, 5 * m_block_size, false));
    m_block_names.push_back("Tree_2.png");
    m_blocks.push_back(Box(99.5 * m_block_size, 9 * m_block_size, 3 * m_block_size, 3 * m_block_size, false));
    m_block_names.push_back("igloo.png");

}




void Level1::checkCollisions() {
    bool groundCollision = false;
    int index = 0;

    for (auto& box : m_blocks) {
        float offset = 0.0f;
        index++;

        if (!groundCollision && box.canCollide && (offset = m_state->getPlayer()->intersectDown(box)) != 0.0f) {
            m_state->getPlayer()->m_pos_y += offset;
            m_state->getPlayer()->m_vy = 0.0f;
            groundCollision = true;
            if (m_block_names[index] == "18.png" && !m_state->getPlayer()->isDead) {

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

    auto player = m_state->getPlayer();

    for (auto it = m_cherries.begin(); it != m_cherries.end(); ) {
        if (player->intersect(*static_cast<Box*>(*it))) {
            graphics::playSound("assets/cherry sound.wav", 0.8f);
            m_cherryCount++;

            it = m_cherries.erase(it);
        }
        else {
            ++it;
        }
    }
}

void Level1::checkEndLevel() {
    if (m_state->getPlayer()->m_pos_x >= 100.0f && m_cherryCount == 41) {
        m_state->setLevel(2);
        GameState::getInstance()->init();
    }
}

void Level1::checkOutOfBounds() {
    if (m_state->getPlayer()->m_pos_x >= 110.0f || m_state->getPlayer()->m_pos_y >= 12.0f) {
        m_state->getPlayer()->health = 0;
    }
}

std::string Level1::getBlockTexture(int i) const {
    return m_state->getFullAssetPath(m_block_names[i]);
}

std::string Level1::getBkgndTexture() const {
    return m_state->getFullAssetPath("background.png");
}