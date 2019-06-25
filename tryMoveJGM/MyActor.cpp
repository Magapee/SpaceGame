#include "MyActor.h"

void MyActor::step()
{
    int8_t cx = 0;
    int8_t cy = 0;
    if(this->controller->checkKey(keyCodes::A))
    {
        std::stringstream message;
        message << "Pressed A";
        this->logger->logMessage(message.str());
        cx--;
    }
    if(this->controller->checkKey(keyCodes::D))
    {
        std::stringstream message;
        message << "Pressed D";
        this->logger->logMessage(message.str());
        cx++;
    }
    if(this->controller->checkKey(keyCodes::S))
    {
        std::stringstream message;
        message << "Pressed S";
        this->logger->logMessage(message.str());
        cy++;
    }
    if(this->controller->checkKey(keyCodes::W))
    {
        std::stringstream message;
        message << "Pressed W";
        this->logger->logMessage(message.str());
        cy--;
    }
    changeCoord(cx*speed, cy*speed, 0);
}


void MyActor::initialize()
{
    Coord* newCoordinates = new Coord;
    newCoordinates->angle = 0;
    newCoordinates->x = 100;
    newCoordinates->y = 100;
    this->setCoord(newCoordinates);
    delete newCoordinates;
    std::string a = "stickman.bmp";
    Sprite* sprite = new Sprite(a);
    this->setSprite(sprite);
	sprite->setCenter();

}
