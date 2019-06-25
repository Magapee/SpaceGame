#include "SceneManager.h"
#include "Scene.h"

void SceneManager::step()
{
	this->currentScene->step();
}

void SceneManager::render()
{
	this->currentScene->render();
}

void SceneManager::changeScene(Scene* newScene)
{
	if (!currentScene)
		delete currentScene;
	currentScene = newScene;
	currentScene->logger = this->logger;
	currentScene->renderer = this->renderer;
	currentScene->handler = this->handler;
	currentScene->sceneManager = this;
	currentScene->initialiseScene();


}

SceneManager::SceneManager(Scene* newScene,
	SDL_Renderer* newRenderer,
	std::shared_ptr<Logger> newLogger,
	std::shared_ptr<ErrorsHandler> newHandler)
{
	this->logger = newLogger;
	this->handler = newHandler;
	this->renderer = newRenderer;
	this->changeScene(newScene);
}
SceneManager::~SceneManager() {}
