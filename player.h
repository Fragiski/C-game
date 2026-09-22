#pragma once
#include "gameobject.h"
#include "box.h"
#include <sgg/graphics.h>
#include <map>
#include "timer.h"
#include <chrono>


class Player : public GameObject, public Box {

    const float m_size = 1.0f;
    graphics::Brush m_brush_player;

    const float m_gravity = 10.0f;
    float m_accel_vertical = 9.0f;
    const float m_accel_horizontal = 40.0f;
    const float m_max_velocity = 5.0f;
    bool invulnerable = false;
    std::chrono::time_point<std::chrono::steady_clock> lastDamageTime;

    void movePlayer(float dt);

    //Animations
    Timer animationTimer;                           // Timer to manage animation
    int currentFrame = 0;                           // Current animation frame
    std::map<std::string, std::vector<std::string>> animations; // Animation sets
    std::string currentAnimation;                   // Current animation key

    void loadAnimationsFrames();  // Load all animation frames

public:
    Player(const std::string& name) : GameObject(name) {};  // Constructor

    float m_vy = 0.0f;
    float m_vx = 0.0f;
    bool ceilingCol = false;
    bool isDead = false;
    int health = 3;
    
    void respawn();
    void takeDamage();
    void updateCooldown();
    void init() override;            // Override init
    void draw() override;            // Override draw
    void update(float dt) override;  // Override update

    //Animations
    void setAnimation(const std::string& animationName); // Set the current animation
    void updateAnimation();
};