#include "Scene.h"
#include "SceneInitializer.h"

Scene::Scene(SceneInitializer* newSceneInitializer)
{
    this->sceneInitializer = newSceneInitializer;
    this->controller.reset(new Controller);
    this->activeCamera.reset(new Camera);
}


Scene::~Scene() //теперь актеры удал€ютс€ автоматически вместе с сценой
{}


void Scene::step()
{
    this->controller->updateInput();
    for (unsigned int i = 0; i < sceneActors.size(); ++i)
        if (sceneActors[i] != nullptr)
            sceneActors[i]->step();
}


void Scene::render()
{
    SDL_RenderClear(renderer);
    for (unsigned int i = 0; i < sceneActors.size(); ++i)
        if (sceneActors[i] != nullptr)
            sceneActors[i]->render(this->activeCamera.get());
    SDL_RenderPresent(renderer);

}

void Scene::initialiseScene()
{
    if(sceneInitializer != nullptr)
    {
        this->sceneInitializer->initialize(this);
        delete this->sceneInitializer;
    }
}

auto Scene::getLogger()
{
    return this->logger;
}


void Scene::addActor(Actor* newActorRaw) //актер €вл€тс€ дружественным дл€ сцены
{
    std::shared_ptr<Actor> newActor;
    newActor.reset(newActorRaw);
    newActor->ownerScene = this;
    newActor->logger = this->logger;
    newActor->controller = this->controller.get();
    this->sceneActors.push_back(newActor);
    newActor->initialize();
}

void Scene::addActor(std::shared_ptr<Actor> newActor)
{
	newActor->ownerScene = this;
	newActor->logger = this->logger;
	newActor->controller = this->controller.get();
	this->sceneActors.push_back(newActor);
	newActor->initialize();
}


Camera* Scene::getActiveCamera()
{
	return this->activeCamera.get();
}