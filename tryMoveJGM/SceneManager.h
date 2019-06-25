#pragma once
#include <vector>
#include <memory>
#include "ErrorsHandler.h"
#include <queue>
#include "SDL.h"
//#include "Scene.h"
//class Actor;
class Scene;
//#include "Actor.h"

class SceneManager
{
private:
	Scene* currentScene = nullptr; //указатель на текущею сцену
	std::shared_ptr<Logger> logger = nullptr;
	std::shared_ptr<ErrorsHandler> handler = nullptr;
	//std::queue<Actor> transSceneData; //данные для передачи между сценами (нереализованно)
	SDL_Renderer* renderer = nullptr;
public:
	SceneManager(Scene*,
		SDL_Renderer*,
		std::shared_ptr<Logger>,
		std::shared_ptr<ErrorsHandler>);
	~SceneManager(); //reserved
	void changeScene(Scene*); //основной мем, собирает новую сцену, в аргумент передаётся указатель на только что-то созданную, в конструктор которой передаётся новый инициализатор
	void step(); //just обрабатывает текущую сцену
	void render(); //рисует её же (внезапно, да?!?!?!?!?)
};
