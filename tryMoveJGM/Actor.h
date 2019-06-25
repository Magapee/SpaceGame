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
    Coord coordinates; //���������� ����� �� ����� (� �����)
protected:
    Scene* ownerScene = nullptr; //�����, ���������� �� �����
    std::shared_ptr<Logger> logger = nullptr; //���������� ������������
    Controller* controller = nullptr; //����������, �������� �� ���� � ����������/����
    Sprite* sprite = nullptr; //������ �����, ������������
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
