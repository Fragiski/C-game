#include "level2.h"
#include "level1.h"
#include "gamestate.h"
#include <cstdlib>
#include <ctime>
#include "bomb.h"
#include <random>
#include <iostream>
using namespace std;

Level2::Level2(const std::string& name) : Level(name)
{
}

Level2::~Level2()
{

    for (auto p_gob : m_dynamic_objects)
        if (p_gob) delete p_gob;
}

void Level2::loadPlayerCoords() {
    player_x = m_state->m_canvas_width / 2.0f - 8.0f;
    player_y = m_state->m_canvas_height / 2.0f;
    m_accel_v = 7.0f;
}



void Level2::loadLevelSpecificBlocks() {

    m_blocks.clear();
    m_block_names.clear();

    // beginning step
    m_blocks.push_back(Box((-6) * m_block_size, 9 * m_block_size, 1.5 * m_block_size, 1.5 * m_block_size, true));
    m_block_names.push_back("spring13.png");
    m_blocks.push_back(Box((-4.5) * m_block_size, 9 * m_block_size, 1.5 * m_block_size, 1.5 * m_block_size, true));
    m_block_names.push_back("spring14.png");
    m_blocks.push_back(Box((-3) * m_block_size, 9 * m_block_size, 1.5 * m_block_size, 1.5 * m_block_size, true));
    m_block_names.push_back("spring15.png");
    m_blocks.push_back(Box((-3) * m_block_size, 8 * m_block_size, 0.5 * m_block_size, 0.5 * m_block_size, true));
    m_block_names.push_back("sign2.png");//sign
    m_blocks.push_back(Box((-5.8) * m_block_size, 7.6 * m_block_size, 1.8 * m_block_size, 1.3 * m_block_size, false));
    m_block_names.push_back("Stone.png");//stone
    m_blocks.push_back(Box((-5.3) * m_block_size, 7.9 * m_block_size, 0.8 * m_block_size, 0.7 * m_block_size, false));
    m_block_names.push_back("bush3.png");//bush
    m_blocks.push_back(Box((-5) * m_block_size, 8 * m_block_size, 0.8 * m_block_size, 0.6 * m_block_size, false));
    m_block_names.push_back("bush3.png");//bush



    for (int j = -1; j < 51; j++)
    {
        for (int i = 1; i <= 10; i++) {


            if (i == 3) {
                m_blocks.push_back(Box((j + 151) * m_block_size, 11.5 * m_block_size, 1 * m_block_size, 1 * m_block_size, false));
                m_block_names.push_back("spring17.png");

                m_blocks.push_back(Box((j - 50) * m_block_size, 11.5 * m_block_size, 1 * m_block_size, 1 * m_block_size, false));
                m_block_names.push_back("spring17.png");


            }
            else if (i > 3) {
                m_blocks.push_back(Box((j + 151) * m_block_size, (11.5 + i - 3) * m_block_size, 1 * m_block_size, 1 * m_block_size, true));
                m_block_names.push_back("spring18.png");

                m_blocks.push_back(Box((j - 50) * m_block_size, (11.5 + i - 3) * m_block_size, 1 * m_block_size, 1 * m_block_size, true));
                m_block_names.push_back("spring18.png");
            }

        }
    }

    for (int j = 5; j <= 11; j++)
    { //sea 1
        for (int i = 1; i <= 10; i++) {
            if (i == 3) {
                m_blocks.push_back(Box(j * m_block_size, 11.5 * m_block_size, 1 * m_block_size, 1 * m_block_size, false));
                m_block_names.push_back("spring17.png");




            }
            else if (i > 3) {
                m_blocks.push_back(Box(j * m_block_size, (11.5 + i - 3) * m_block_size, 1 * m_block_size, 1 * m_block_size, true));
                m_block_names.push_back("spring18.png");
            }
        }
    }

    for (int j = 32; j < 39; j++) {
        // sea2
        for (int i = 1; i <= 10; i++) {

            if (i == 3) {
                m_blocks.push_back(Box(j * m_block_size, 11.5 * m_block_size, 1 * m_block_size, 1 * m_block_size, false));
                m_block_names.push_back("spring17.png");




            }
            else if (i > 4) {
                m_blocks.push_back(Box(j * m_block_size, (11.5 + i - 4) * m_block_size, 1 * m_block_size, 1 * m_block_size, true));
                m_block_names.push_back("spring18.png");
            }
        }
    }

    for (int j = 41; j < 100; j++) {
        // sea3
        for (int i = 1; i <= 10; i++) {

            if (i == 3) {
                m_blocks.push_back(Box(j * m_block_size, 11.5 * m_block_size, 1 * m_block_size, 1 * m_block_size, false));
                m_block_names.push_back("spring17.png");




            }
            else if (i > 4) {
                m_blocks.push_back(Box(j * m_block_size, (11.5 + i - 4) * m_block_size, 1 * m_block_size, 1 * m_block_size, true));
                m_block_names.push_back("spring18.png");
            }
        }
    }

    m_blocks.push_back(Box(40 * m_block_size, 14.5 * m_block_size, 1 * m_block_size, 1 * m_block_size, true));
    m_block_names.push_back("spring18.png");

    m_blocks.push_back(Box(40 * m_block_size, 13.5 * m_block_size, 1 * m_block_size, 1 * m_block_size, true));
    m_block_names.push_back("spring18.png");


    // until 40
    for (int j = 0; j <= 39; j++) {
        for (int i = 1; i <= 10; i++) {

            if (j == 0) { // start
                m_blocks.push_back(Box(0 * m_block_size, 11.5f * m_block_size, 1 * m_block_size, 1 * m_block_size, true));
                m_block_names.push_back("spring1.png");

                m_blocks.push_back(Box(0 * m_block_size, (11.5f + i) * m_block_size, 1 * m_block_size, 1 * m_block_size, true));
                m_block_names.push_back("spring4.png");
            }

            else if (j <= 4 || j >= 12 && j <= 31 || j > 38 && j > 0 && j < 40)
            { // anywhere besides near the steps
                m_blocks.push_back(Box(j * m_block_size, 11.5f * m_block_size, 1 * m_block_size, 1 * m_block_size, true));
                m_block_names.push_back("spring2.png");

                m_blocks.push_back(Box(j * m_block_size, (11.5f + i) * m_block_size, 1 * m_block_size, 1 * m_block_size, true));
                m_block_names.push_back("spring5.png");
            }
            else if (j == 32) // left of step3
            {

                m_blocks.push_back(Box(j * m_block_size, 11.5f * m_block_size, 1 * m_block_size, 1 * m_block_size, true));
                m_block_names.push_back("spring3.png");

                m_blocks.push_back(Box(j * m_block_size, (11.5f + i) * m_block_size, 1 * m_block_size, 1 * m_block_size, true));
                m_block_names.push_back("spring6.png");
            }

            else if (j == 38) // right of step3
            {

                m_blocks.push_back(Box(j * m_block_size, 11.5f * m_block_size, 1 * m_block_size, 1 * m_block_size, true));
                m_block_names.push_back("spring1.png");

                m_blocks.push_back(Box(j * m_block_size, (11.5f + i) * m_block_size, 1 * m_block_size, 1 * m_block_size, true));
                m_block_names.push_back("spring4.png");
            }
            else if (j == 5)// left of step1
            {
                m_blocks.push_back(Box(j * m_block_size, 11.5f * m_block_size, 1 * m_block_size, 1 * m_block_size, true));
                m_block_names.push_back("spring3.png");

                m_blocks.push_back(Box(j * m_block_size, (11.5f + i) * m_block_size, 1 * m_block_size, 1 * m_block_size, true));
                m_block_names.push_back("spring6.png");
            }
            else if (j == 11) {// right of step1

                m_blocks.push_back(Box(11 * m_block_size, 11.5f * m_block_size, 1 * m_block_size, 1 * m_block_size, true));
                m_block_names.push_back("spring1.png");

                m_blocks.push_back(Box(11 * m_block_size, (11.5f + i) * m_block_size, 1 * m_block_size, 1 * m_block_size, true));
                m_block_names.push_back("spring4.png");
            }





        }


    }


    //decoration




    m_blocks.push_back(Box(0.5 * m_block_size, 10.5 * m_block_size, 2 * m_block_size, m_block_size, false));
    m_block_names.push_back("bush2.png"); // bush next to mushrooms

    m_blocks.push_back(Box(1 * m_block_size, 9.5 * m_block_size, 3 * m_block_size, 3 * m_block_size, false));
    m_block_names.push_back("Tree3.png");  //tree next to mushroom

    m_blocks.push_back(Box(0.8 * m_block_size, 10.7 * m_block_size, m_block_size, 0.6 * m_block_size, false));
    m_block_names.push_back("bush1.png"); // bush small next to mushrooms

    m_blocks.push_back(Box(0 * m_block_size, 10.7 * m_block_size, 0.6 * m_block_size, 0.6 * m_block_size, false));
    m_block_names.push_back("mushroom2.png");  //mushroom big

    m_blocks.push_back(Box(0.2 * m_block_size, 10.8 * m_block_size, 0.4 * m_block_size, 0.4 * m_block_size, false));
    m_block_names.push_back("mushroom1.png");


    // multiple bushes multiple trees

    m_blocks.push_back(Box(19 * m_block_size, 9.25 * m_block_size, 3.5 * m_block_size, 3.5 * m_block_size, false));
    m_block_names.push_back("Tree2.png");


    m_blocks.push_back(Box(20 * m_block_size, 9 * m_block_size, 4 * m_block_size, 4 * m_block_size, false));
    m_block_names.push_back("Tree2.png");

    m_blocks.push_back(Box(21 * m_block_size, 9.25 * m_block_size, 3.5 * m_block_size, 3.5 * m_block_size, false));
    m_block_names.push_back("Tree2.png");


    m_blocks.push_back(Box(22 * m_block_size, 9 * m_block_size, 4 * m_block_size, 4 * m_block_size, false));
    m_block_names.push_back("Tree2.png");

    m_blocks.push_back(Box(18 * m_block_size, 10.5 * m_block_size, 2 * m_block_size, m_block_size, false));
    m_block_names.push_back("bush2.png");

    m_blocks.push_back(Box(18.7 * m_block_size, 10.7 * m_block_size, 1 * m_block_size, 0.6 * m_block_size, false));
    m_block_names.push_back("bush4.png");

    m_blocks.push_back(Box(17 * m_block_size, 10.5 * m_block_size, 2 * m_block_size, m_block_size, false));
    m_block_names.push_back("bush2.png");

    m_blocks.push_back(Box(18 * m_block_size, 10.7 * m_block_size, 1 * m_block_size, 0.6 * m_block_size, false));
    m_block_names.push_back("bush4.png");

    m_blocks.push_back(Box(22 * m_block_size, 10.5 * m_block_size, 2 * m_block_size, m_block_size, false));
    m_block_names.push_back("bush2.png");

    m_blocks.push_back(Box(21.3 * m_block_size, 10.7 * m_block_size, 1 * m_block_size, 0.6 * m_block_size, false));
    m_block_names.push_back("bush4.png");
    m_blocks.push_back(Box(18 * m_block_size, 10.7 * m_block_size, 1 * m_block_size, 0.6 * m_block_size, false));
    m_block_names.push_back("bush4.png");

    //tree base
    m_blocks.push_back(Box(13 * m_block_size, 10.5 * m_block_size, 3 * m_block_size, m_block_size, false));
    m_block_names.push_back("Tree1.png");
    m_blocks.push_back(Box(12.3 * m_block_size, 10.7 * m_block_size, 0.6 * m_block_size, 0.6 * m_block_size, false));
    m_block_names.push_back("mushroom2.png");  //mushroom big
    m_blocks.push_back(Box(12.9 * m_block_size, 10.75 * m_block_size, 0.55 * m_block_size, 0.55 * m_block_size, false));
    m_block_names.push_back("mushroom2.png");  //mushroom big
    m_blocks.push_back(Box(12.6 * m_block_size, 10.8 * m_block_size, 0.4 * m_block_size, 0.4 * m_block_size, false));
    m_block_names.push_back("mushroom1.png");




    // stone
    m_blocks.push_back(Box(4.9 * m_block_size, 10.55 * m_block_size, 1.3 * m_block_size, 0.9 * m_block_size, false));
    m_block_names.push_back("Stone.png");//stone
    m_blocks.push_back(Box((4.4) * m_block_size, 10.75 * m_block_size, 0.6 * m_block_size, 0.5 * m_block_size, false));
    m_block_names.push_back("bush3.png");//bush
    m_blocks.push_back(Box(4.7 * m_block_size, 10.9 * m_block_size, 0.3 * m_block_size, 0.3 * m_block_size, false));
    m_block_names.push_back("mushroom1.png");








    //STEPS


       //first step
    m_blocks.push_back(Box(8 * m_block_size, 9.5 * m_block_size, 1 * m_block_size, 1 * m_block_size, true));
    m_block_names.push_back("spring13.png");
    m_blocks.push_back(Box(9 * m_block_size, 9.5 * m_block_size, 1 * m_block_size, 1 * m_block_size, true));
    m_block_names.push_back("spring14.png");
    m_blocks.push_back(Box(10 * m_block_size, 9.5 * m_block_size, 1 * m_block_size, 1 * m_block_size, true));
    m_block_names.push_back("spring15.png");


    //second step
    m_blocks.push_back(Box(27 * m_block_size, 9.5 * m_block_size, 1 * m_block_size, 1 * m_block_size, true));
    m_block_names.push_back("spring13.png");
    m_blocks.push_back(Box(28 * m_block_size, 9.5 * m_block_size, 1 * m_block_size, 1 * m_block_size, true));
    m_block_names.push_back("spring14.png");
    m_blocks.push_back(Box(29 * m_block_size, 9.5 * m_block_size, 1 * m_block_size, 1 * m_block_size, true));
    m_block_names.push_back("spring15.png");
    //bush
    m_blocks.push_back(Box(28.7 * m_block_size, 8.75 * m_block_size, 0.8 * m_block_size, 0.5 * m_block_size, false));
    m_block_names.push_back("bush4.png");
    //mushroom
    m_blocks.push_back(Box(29 * m_block_size, 8.8 * m_block_size, 0.4 * m_block_size, 0.4 * m_block_size, false));
    m_block_names.push_back("mushroom2.png");



    //third step
    m_blocks.push_back(Box(33 * m_block_size, 8 * m_block_size, 1 * m_block_size, 1 * m_block_size, true));
    m_block_names.push_back("spring13.png");
    m_blocks.push_back(Box(34 * m_block_size, 8 * m_block_size, 1 * m_block_size, 1 * m_block_size, true));
    m_block_names.push_back("spring14.png");
    m_blocks.push_back(Box(35 * m_block_size, 8 * m_block_size, 1 * m_block_size, 1 * m_block_size, true));
    m_block_names.push_back("spring14.png");
    m_blocks.push_back(Box(36 * m_block_size, 8 * m_block_size, 1 * m_block_size, 1 * m_block_size, true));
    m_block_names.push_back("spring14.png");
    m_blocks.push_back(Box(37 * m_block_size, 8 * m_block_size, 1 * m_block_size, 1 * m_block_size, true));
    m_block_names.push_back("spring14.png");
    m_blocks.push_back(Box(38 * m_block_size, 8 * m_block_size, 1 * m_block_size, 1 * m_block_size, true));
    m_block_names.push_back("spring15.png");
    //sign
    m_blocks.push_back(Box(38 * m_block_size, 7.3 * m_block_size, 0.5 * m_block_size, 0.5 * m_block_size, true));
    m_block_names.push_back("sign2.png");

    m_blocks.push_back(Box(35 * m_block_size, 6.85 * m_block_size, 1.8 * m_block_size, 1.3 * m_block_size, false));
    m_block_names.push_back("Stone.png");//stone
    m_blocks.push_back(Box(34.5 * m_block_size, 7.15 * m_block_size, 0.8 * m_block_size, 0.7 * m_block_size, false));
    m_block_names.push_back("bush3.png");//bush
    m_blocks.push_back(Box(34.2 * m_block_size, 7.2 * m_block_size, 0.8 * m_block_size, 0.6 * m_block_size, false));
    m_block_names.push_back("bush3.png");//bush

    // dirt

    m_blocks.push_back(Box(40 * m_block_size, 11.5 * m_block_size, 1 * m_block_size, 1 * m_block_size, true));
    m_block_names.push_back("spring2.png");

    m_blocks.push_back(Box(40 * m_block_size, 12.5 * m_block_size, 1 * m_block_size, 1 * m_block_size, true));
    m_block_names.push_back("spring5.png");

    m_blocks.push_back(Box(40 * m_block_size, 13.5 * m_block_size, 1 * m_block_size, 1 * m_block_size, true));
    m_block_names.push_back("spring16.png");

    m_blocks.push_back(Box(41 * m_block_size, 11.5 * m_block_size, 1 * m_block_size, 1 * m_block_size, true));
    m_block_names.push_back("spring3.png");

    m_blocks.push_back(Box(41 * m_block_size, 12.5 * m_block_size, 1 * m_block_size, 1 * m_block_size, true));
    m_block_names.push_back("spring16.png");

    // until 100

    //frst step
    m_blocks.push_back(Box(43 * m_block_size, 9.5 * m_block_size, 1 * m_block_size, 1 * m_block_size, true));
    m_block_names.push_back("spring13.png");
    m_blocks.push_back(Box(44 * m_block_size, 9.5 * m_block_size, 1 * m_block_size, 1 * m_block_size, true));
    m_block_names.push_back("spring14.png");
    m_blocks.push_back(Box(45 * m_block_size, 9.5 * m_block_size, 1 * m_block_size, 1 * m_block_size, true));
    m_block_names.push_back("spring15.png");
    m_blocks.push_back(Box(44 * m_block_size, 8.5 * m_block_size, 2 * m_block_size, m_block_size, false));
    m_block_names.push_back("bush2.png");
    m_blocks.push_back(Box(44 * m_block_size, 8.7 * m_block_size, 0.6 * m_block_size, 0.6 * m_block_size, false));
    m_block_names.push_back("mushroom2.png");  //mushroom big
    m_blocks.push_back(Box(44.3 * m_block_size, 8.75 * m_block_size, 0.55 * m_block_size, 0.55 * m_block_size, false));
    m_block_names.push_back("mushroom2.png");  //mushroom big
    m_blocks.push_back(Box(44.6 * m_block_size, 8.8 * m_block_size, 0.4 * m_block_size, 0.4 * m_block_size, false));
    m_block_names.push_back("mushroom1.png");




    //second step
    m_blocks.push_back(Box(48 * m_block_size, 7 * m_block_size, 1 * m_block_size, 1 * m_block_size, true));
    m_block_names.push_back("spring13.png");
    m_blocks.push_back(Box(49 * m_block_size, 7 * m_block_size, 1 * m_block_size, 1 * m_block_size, true));
    m_block_names.push_back("spring14.png");
    m_blocks.push_back(Box(50 * m_block_size, 7 * m_block_size, 1 * m_block_size, 1 * m_block_size, true));
    m_block_names.push_back("spring15.png");
    m_blocks.push_back(Box(48.4 * m_block_size, 6.05 * m_block_size, 1.3 * m_block_size, 0.9 * m_block_size, false));
    m_block_names.push_back("Stone.png");//stone
    m_blocks.push_back(Box(48.8 * m_block_size, 6.25 * m_block_size, 0.6 * m_block_size, 0.5 * m_block_size, false));
    m_block_names.push_back("bush3.png");//bush
    m_blocks.push_back(Box(48.9 * m_block_size, 6.4 * m_block_size, 0.3 * m_block_size, 0.3 * m_block_size, false));
    m_block_names.push_back("mushroom1.png");


    //third step
    m_blocks.push_back(Box(52 * m_block_size, 9.5 * m_block_size, 1 * m_block_size, 1 * m_block_size, true));
    m_block_names.push_back("spring13.png");
    m_blocks.push_back(Box(53 * m_block_size, 9.5 * m_block_size, 1 * m_block_size, 1 * m_block_size, true));
    m_block_names.push_back("spring15.png");

    //forth step
    m_blocks.push_back(Box(56 * m_block_size, 7 * m_block_size, 1 * m_block_size, 1 * m_block_size, true));
    m_block_names.push_back("spring13.png");
    m_blocks.push_back(Box(57 * m_block_size, 7 * m_block_size, 1 * m_block_size, 1 * m_block_size, true));
    m_block_names.push_back("spring15.png");
    m_blocks.push_back(Box(57 * m_block_size, 6.25 * m_block_size, 0.55 * m_block_size, 0.55 * m_block_size, false));
    m_block_names.push_back("mushroom2.png");
    m_blocks.push_back(Box(57.3 * m_block_size, 6.3 * m_block_size, 0.4 * m_block_size, 0.4 * m_block_size, false));
    m_block_names.push_back("mushroom1.png");




    //big platform
    for (int i = 65; i <= 73; i++)
    {


        m_blocks.push_back(Box(i * m_block_size, 10 * m_block_size, m_block_size, m_block_size, true));
        m_block_names.push_back("spring9.png");


    }

    for (int i = 65; i <= 73; i++)
    {
        m_blocks.push_back(Box(i * m_block_size, 8 * m_block_size, m_block_size, m_block_size, true));
        m_block_names.push_back("spring2.png");

    }

    m_blocks.push_back(Box(64 * m_block_size, 8 * m_block_size, m_block_size, m_block_size, true));
    m_block_names.push_back("spring1.png");

    m_blocks.push_back(Box(74 * m_block_size, 8 * m_block_size, m_block_size, m_block_size, true));
    m_block_names.push_back("spring3.png");

    m_blocks.push_back(Box(64 * m_block_size, 9 * m_block_size, m_block_size, m_block_size, true));
    m_block_names.push_back("spring4.png");

    m_blocks.push_back(Box(74 * m_block_size, 9 * m_block_size, m_block_size, m_block_size, true));
    m_block_names.push_back("spring6.png");


    for (int i = 65; i <= 73; i++)
    {
        m_blocks.push_back(Box(i * m_block_size, 9 * m_block_size, m_block_size, m_block_size, true));
        m_block_names.push_back("spring5.png");

    }

    m_blocks.push_back(Box(64 * m_block_size, 10 * m_block_size, m_block_size, m_block_size, true));
    m_block_names.push_back("spring12.png");

    m_blocks.push_back(Box(74 * m_block_size, 10 * m_block_size, m_block_size, m_block_size, true));
    m_block_names.push_back("spring16.png");


    // multiple bushes multiple trees

    m_blocks.push_back(Box(65 * m_block_size, 5.75 * m_block_size, 3.5 * m_block_size, 3.5 * m_block_size, false));
    m_block_names.push_back("Tree2.png");


    m_blocks.push_back(Box(66 * m_block_size, 5.50 * m_block_size, 4 * m_block_size, 4 * m_block_size, false));
    m_block_names.push_back("Tree2.png");

    m_blocks.push_back(Box(67 * m_block_size, 5.75 * m_block_size, 3.5 * m_block_size, 3.5 * m_block_size, false));
    m_block_names.push_back("Tree2.png");


    m_blocks.push_back(Box(68 * m_block_size, 5.50 * m_block_size, 4 * m_block_size, 4 * m_block_size, false));
    m_block_names.push_back("Tree2.png");

    m_blocks.push_back(Box(68 * m_block_size, 7 * m_block_size, 2 * m_block_size, m_block_size, false));
    m_block_names.push_back("bush2.png");

    m_blocks.push_back(Box(67.7 * m_block_size, 7.25 * m_block_size, 1 * m_block_size, 0.6 * m_block_size, false));
    m_block_names.push_back("bush4.png");

    m_blocks.push_back(Box(67 * m_block_size, 7 * m_block_size, 2 * m_block_size, m_block_size, false));
    m_block_names.push_back("bush2.png");

    m_blocks.push_back(Box(67.4 * m_block_size, 7.25 * m_block_size, 1 * m_block_size, 0.6 * m_block_size, false));
    m_block_names.push_back("bush4.png");

    m_blocks.push_back(Box(66 * m_block_size, 7 * m_block_size, 2 * m_block_size, m_block_size, false));
    m_block_names.push_back("bush2.png");

    m_blocks.push_back(Box(65.3 * m_block_size, 7.25 * m_block_size, 1 * m_block_size, 0.6 * m_block_size, false));
    m_block_names.push_back("bush4.png");
    m_blocks.push_back(Box(68 * m_block_size, 7.25 * m_block_size, 1 * m_block_size, 0.6 * m_block_size, false));
    m_block_names.push_back("bush4.png");


    m_blocks.push_back(Box(73.4 * m_block_size, 5.75 * m_block_size, 3.5 * m_block_size, 3.5 * m_block_size, false));
    m_block_names.push_back("Tree2.png");


    m_blocks.push_back(Box(72.6 * m_block_size, 5.50 * m_block_size, 4 * m_block_size, 4 * m_block_size, false));
    m_block_names.push_back("Tree2.png");

    m_blocks.push_back(Box(72.9 * m_block_size, 5.50 * m_block_size, 4 * m_block_size, 4 * m_block_size, false));
    m_block_names.push_back("Tree2.png");

    m_blocks.push_back(Box(73.6 * m_block_size, 5.50 * m_block_size, 4 * m_block_size, 4 * m_block_size, false));
    m_block_names.push_back("Tree2.png");

    m_blocks.push_back(Box(71 * m_block_size, 7.25 * m_block_size, 0.5 * m_block_size, 0.5 * m_block_size, false));
    m_block_names.push_back("sign1.png");



}

void Level2::loadLevelSpecificCherries() {
    m_cherries.clear(); // Clear existing cherries

    // Add cherries
    m_cherries.push_back(new Cherry(Box(-3.0f, 7.0f, 0.5f, 0.5f, false)));
    m_cherries.push_back(new Cherry(Box(-1.0f, 6.0f, 0.5f, 0.5f, false)));
    m_cherries.push_back(new Cherry(Box(3.0f, 10.5f, 0.5f, 0.5f, false)));
    m_cherries.push_back(new Cherry(Box(5.0f, 10.5f, 0.5f, 0.5f, false)));
    m_cherries.push_back(new Cherry(Box(6.0f, 10.5f, 0.5f, 0.5f, false)));

    // on platform
    m_cherries.push_back(new Cherry(Box(8.0f, 8.5f, 0.5f, 0.5f, false)));
    m_cherries.push_back(new Cherry(Box(9.0f, 8.5f, 0.5f, 0.5f, false)));

    m_cherries.push_back(new Cherry(Box(13.0f, 10.5f, 0.5f, 0.5f, false)));
    m_cherries.push_back(new Cherry(Box(14.0f, 10.5f, 0.5f, 0.5f, false)));
    m_cherries.push_back(new Cherry(Box(17.0f, 10.5f, 0.5f, 0.5f, false)));
    m_cherries.push_back(new Cherry(Box(18.0f, 10.5f, 0.5f, 0.5f, false)));
    m_cherries.push_back(new Cherry(Box(19.0f, 10.5f, 0.5f, 0.5f, false)));
    m_cherries.push_back(new Cherry(Box(20.0f, 10.5f, 0.5f, 0.5f, false)));
    m_cherries.push_back(new Cherry(Box(21.0f, 10.5f, 0.5f, 0.5f, false)));

    m_cherries.push_back(new Cherry(Box(31.0f, 10.5f, 0.5f, 0.5f, false)));
    m_cherries.push_back(new Cherry(Box(30.0f, 5.5f, 0.5f, 0.5f, false)));

    m_cherries.push_back(new Cherry(Box(37.0f, 6.5f, 0.5f, 0.5f, false)));
    m_cherries.push_back(new Cherry(Box(38.0f, 6.5f, 0.5f, 0.5f, false)));

    m_cherries.push_back(new Cherry(Box(41.0f, 5.0f, 0.5f, 0.5f, false)));


    m_cherries.push_back(new Cherry(Box(44.0f, 7.5f, 0.5f, 0.5f, false)));
    m_cherries.push_back(new Cherry(Box(45.0f, 7.5f, 0.5f, 0.5f, false)));

    m_cherries.push_back(new Cherry(Box(46.0f, 6.5f, 0.5f, 0.5f, false)));

    m_cherries.push_back(new Cherry(Box(48.0f, 6.0f, 0.5f, 0.5f, false)));

    m_cherries.push_back(new Cherry(Box(50.0f, 5.5f, 0.5f, 0.5f, false)));

    m_cherries.push_back(new Cherry(Box(52.5f, 7.0f, 0.5f, 0.5f, false)));


    m_cherries.push_back(new Cherry(Box(68.0f, 7.0f, 0.5f, 0.5f, false)));
    m_cherries.push_back(new Cherry(Box(69.0f, 7.0f, 0.5f, 0.5f, false)));
    m_cherries.push_back(new Cherry(Box(70.0f, 7.0f, 0.5f, 0.5f, false)));
    m_cherries.push_back(new Cherry(Box(71.0f, 7.0f, 0.5f, 0.5f, false)));
    m_cherries.push_back(new Cherry(Box(72.0f, 7.0f, 0.5f, 0.5f, false)));





    for (auto& cherry : m_cherries) {
        cherry->init();
    }

}

void Level2::checkCollisions() {
    bool groundCollision = false;
    int index = 0;
    for (auto& box : m_blocks) {
        float offset = 0.0f;
        index++;

        if (!groundCollision && box.canCollide && (offset = m_state->getPlayer()->intersectDown(box)) != 0.0f) {
            groundCollision = true;
            m_state->getPlayer()->m_pos_y += offset;
            m_state->getPlayer()->m_vy = 0.0f;
            if (m_block_names[index] == "spring18.png" && !m_state->getPlayer()->isDead) {

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

    for (auto& bomb : bombs) {
        float offset = 0.0f;


        if ((offset = m_state->getPlayer()->intersectBomb(bomb)) != 0.0f && bomb.canCollide && (offset = m_state->getPlayer()->intersectSideways(bomb)) != 0.0f) {

            m_state->getPlayer()->takeDamage();

            groundCollision = true;

            for (auto& box : m_blocks) {
                if (box.canCollide && (offset = m_state->getPlayer()->intersectDown(box)) != 0.0f) {
                    {
                        m_state->getPlayer()->m_pos_x += offset;
                        m_state->getPlayer()->m_vx = 0.0f;

                        m_state->getPlayer()->m_pos_y += offset;
                        m_state->getPlayer()->m_vy = 0.0f;
                    }
                }
            }


            for (auto& box : m_blocks) {
                if (box.canCollide && (offset = m_state->getPlayer()->intersectSideways(box)) != 0.0f) {
                    {

                        m_state->getPlayer()->m_pos_x += offset;
                        m_state->getPlayer()->m_vx = 0.0f;
                    }
                }
            }
        }
    }
}



void Level2::FallingBombs()
{


    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> dist(1, 500);


    int randomNumber;

    do {
        randomNumber = dist(gen);

    } while ((randomNumber > previousRandomNumber + 300) && (randomNumber < previousRandomNumber - 300));  // Regenerate if it's the same as the previous

    previousRandomNumber = randomNumber;

    bombs.emplace_back(randomNumber * m_block_size, (-15) * m_block_size, m_block_size, m_block_size, true);
    bombs.back().init();
}

void Level2::checkEndLevel() {
    if (m_state->getPlayer()->m_pos_x >= 73.0f && m_cherryCount == 30) {
        m_state->setLevel(3);
        GameState::getInstance()->init();
    }
}

void Level2::checkOutOfBounds() {
    if (m_state->getPlayer()->m_pos_x >= 80.0f || m_state->getPlayer()->m_pos_y >= 12.0f) {
        m_state->getPlayer()->health = 0;
    }
}

std::string Level2::getBlockTexture(int i) const {
    return m_state->getFullAssetPath(m_block_names[i]);
}

std::string Level2::getBkgndTexture() const {
    return m_state->getFullAssetPath("bg_spring.png");
}