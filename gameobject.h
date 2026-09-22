#pragma once
#include <string>


class GameObject {

    static int m_next_id; // Static counter for unique IDs

protected:
    
    int m_id = 0;
    std::string m_name;
    class GameState* m_state;
    bool m_active = true;

public:

    GameObject(const std::string& name = "");
    virtual ~GameObject() {}
    virtual void init() = 0;
    virtual void update(float dt) {};
    virtual void draw() = 0;
    int getId() const { return m_id; }
    const std::string& getName() const { return m_name; }
    bool isActive() { return m_active; }
    void setActive(bool a) { m_active = a; }
};
