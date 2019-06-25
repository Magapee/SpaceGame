#pragma once
#include <memory>
#include <vector>

#include "Logger.h"
#include "ErrorsHandler.h"
#include "Controller.h"
#include "Camera.h"


#include "Actor.h"

//class Actor;

class SceneInitializer;
class SceneManager;


class Scene
{
private:
    std::shared_ptr<Logger> logger = nullptr;
    std::shared_ptr<ErrorsHandler> handler = nullptr;
    std::shared_ptr<Controller> controller = nullptr;
    std::shared_ptr<Camera> activeCamera = nullptr;
    SceneManager* sceneManager; //����������, ���������� �� ��� �����
    SDL_Renderer* renderer = nullptr;
    std::vector<std::shared_ptr<Actor>> sceneActors; //����� �����
    SceneInitializer* sceneInitializer = nullptr; //������������� �����
    void initialiseScene(); //���������� ��������������, ���������� ����������
public:
    Scene(SceneInitializer*);
    ~Scene();
    Camera* getActiveCamera(void);
    void step(); //����� step ��� ������� �����
    void render(); //��������� ������� �����
    void addActor(Actor*); //��������� ������ �� ����� � �������� ���
	void addActor(std::shared_ptr<Actor>);
    auto getLogger();
    friend SceneManager; //��� ������ �����
};
