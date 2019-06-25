//Game.h
#pragma once
#include "SDL.h"
#include "ErrorsHandler.h"
#include "Globals.h"
#include "Logger.h"
#include "Scene.h"
#include "SceneManager.h"
#include "Sprite.h"
#include "Actor.h"
//#include "SDL_image.h"
#include <iostream>
#include <string>
#include <vector>
#include <chrono>
#include <memory>
//#include "box2d/Box2D.h"
using std::cout;
using std::string;
using std::vector;
using namespace std;


const int TPS = 60;
const int MS_PER_TICK = 1000 / TPS;


class Game
{
private:
	int mSecondsPerTick;
	std::chrono::time_point<std::chrono::system_clock> beginTime;
	std::shared_ptr<SceneManager> sceneManager = nullptr; //менеджер сцен
	const char* windowName = "BEST GAME EVER!!!!!"; //имя окна temporal!!!
	bool isRunVar = false; //флаг, показывающий работу программы
	SDL_Window* window = nullptr; //указатель на окно программы
	SDL_Renderer* renderer = nullptr; //указатель на рендрер окна
	SDL_Event* mainEvent = new SDL_Event; //основное событие приложения
	std::shared_ptr<Logger> logger = nullptr;//объект для логов
	std::shared_ptr<ErrorsHandler> handler = nullptr; //обработчик ошибок
public:
	bool isRunning(); //получение состояния программы, работает или нет
	//void loadContent(char*); //откуда это?!?!?!
	void step(); //метод обработки внутренних состояний
	void render(); //метод рисования на экран
	auto getLogger();
	Game(); //конструктор, включающий в себя инициализацию всех основных систем
	~Game(); //*внезапно* очистка памяти *крик аутиста*
};
