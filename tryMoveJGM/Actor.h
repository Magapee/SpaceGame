#pragma once
#include <memory>


#include "Coord.h"
#include "Logger.h"
#include "ErrorsHandler.h"
#include "Controller.h"


#include "Sprite.h"
class Scene;
//#include "Scene.h"

class Actor
{
private:
    Coord coordinates; //координаты актёра на сцене (с углом)
protected:
    Scene* ownerScene = nullptr; //сцена, отвечающая за актёра
    std::shared_ptr<Logger> logger = nullptr; //инструмент логгирования
    Controller* controller = nullptr; //контроллер, отвечает за ввод с клавиатуры/мыши
    Sprite* sprite = nullptr; //спрайт актёра, необязателен
public:
    Actor();
    virtual void initialize() = 0;
    virtual void step() = 0;
    void setSprite(Sprite*);
    void render(Camera*);
    Coord getCoord();
    void setCoord(Coord*);
    void changeCoord(long, long, float);
    friend Scene;
};
