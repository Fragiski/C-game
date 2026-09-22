#include "sgg/graphics.h"
#include "gamestate.h"
#include "startscreen.h"
#include "settingscreen.h"
#include "deathscreen.h"
#include "level.h"
#include "level1.h"
#include "level2.h"
#include "level3.h"


int main(int argc, char** argv) {
    graphics::createWindow(800, 800, "Diego's Adventures");

    GameState* state = GameState::getInstance();

    StartScreen start_screen("Start Screen");
    start_screen.init();

    SettingScreen setting_screen("Settings Screen");
    setting_screen.init();

    graphics::playMusic("assets/Ylvis -The Fox Instrumental Version.mp3", 0.5f, true);

    graphics::setDrawFunction([&]() {
        if (state->getLevel() == 0)
            start_screen.draw();
        else if (state->getLevel() == -1)
            setting_screen.draw();
        else
            state->getInstance()->draw();
        });

    graphics::setUpdateFunction([&](float dt) {
        if (state->getLevel() == 0)
            start_screen.update(dt);
        else if (state->getLevel() == -1)
            setting_screen.update(dt);
        else
            state->getInstance()->update(dt);
        });

    graphics::setCanvasSize(state->m_canvas_width, state->m_canvas_height);
    graphics::setCanvasScaleMode(graphics::CANVAS_SCALE_FIT);

    graphics::startMessageLoop();

    return 0;
}
