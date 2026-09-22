#pragma once
#include "box.h"
#include "gameobject.h"
#include "sgg/graphics.h"
#include "timer.h"
#include <string>
#include <map>

class Bomb : public GameObject, public Box {
public:
    graphics::Brush m_brush_bomb;


    // Constructor 
    Bomb(float x, float y, float width, float height, bool cc);

    //Animations
    Timer animationTimerBomb;                           // Timer to manage animation
    int currentFrameBomb = 0;                           // Current animation frame
    std::map<std::string, std::vector<std::string>> animationsBomb; // Animation sets
    std::string currentAnimationBomb;                   // Current animation key


    Bomb* bomb;

    void init() override;
    void draw() override;
    void update(float deltaTime) override;




    //Animations
    void loadAnimationsFramesBomb();
    void setAnimationBomb(const std::string& animationNameBomb); // Set the current animation
    void updateAnimationBomb();                              // Updates the current animation frame


};


