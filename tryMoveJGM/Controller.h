#pragma once
#include "KeyCodes.h"
#include <stdio.h>
#include "SDL.h"

class Controller
{
private:
    const Uint8* keyboardState = SDL_GetKeyboardState(nullptr);
    int x = 0, y = 0;
    bool LEFT_KEY = false;
    bool RIGHT_KEY = false;
    bool MIDDLE_KEY = false;
public:
    Controller();
    ~Controller();
    void updateInput();
    bool mouseX();
    bool mouseY();
    bool mouseLeftButton();
    bool mouseRightButton();
    bool mouseMiddleButton();
    bool checkKey(keyCodes);
};
