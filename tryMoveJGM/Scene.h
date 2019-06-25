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
    SceneManager* sceneManager; //менеджэээр, отвечающий за эту сцену
    SDL_Renderer* renderer = nullptr;
    std::vector<std::shared_ptr<Actor>> sceneActors; //актёры сцены
    SceneInitializer* sceneInitializer = nullptr; //инициализатор сцены
    void initialiseScene(); //применение инициализатора, вызывается менеджером
public:
    Scene(SceneInitializer*);
    ~Scene();
    Camera* getActiveCamera(void);
    void step(); //вызов step для каждого актёра
    void render(); //отрисовка каждого актёра
    void addActor(Actor*); //добавляет актера на сцену и собирает его
	void addActor(std::shared_ptr<Actor>);
    auto getLogger();
    friend SceneManager; //для сборки сцены
};
