#include "Controller.h"

void Controller::updateInput()
{
    this->LEFT_KEY = false;
    this->RIGHT_KEY = false;
    this->MIDDLE_KEY = false;

    if (SDL_GetMouseState(&(this->x),
                          &(this->y)))
    {
        if (SDL_BUTTON_LMASK)
            this->LEFT_KEY = true;
        if (SDL_BUTTON_RMASK)
            this->RIGHT_KEY = true;
        if (SDL_BUTTON_MMASK)
            this->MIDDLE_KEY = true;
    }
}

Controller::Controller(){}
Controller::~Controller(){}
bool Controller::mouseX() {return this->x;}
bool Controller::mouseY() {return this->y;}
bool Controller::mouseLeftButton() {return this->LEFT_KEY;}
bool Controller::mouseRightButton() {return this->RIGHT_KEY;}
bool Controller::mouseMiddleButton() {return this->MIDDLE_KEY;}
bool Controller::checkKey(keyCodes code){return this->keyboardState[static_cast<int>(code)];}

