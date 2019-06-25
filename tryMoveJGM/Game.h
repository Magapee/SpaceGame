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
	std::shared_ptr<SceneManager> sceneManager = nullptr; //�������� ����
	const char* windowName = "BEST GAME EVER!!!!!"; //��� ���� temporal!!!
	bool isRunVar = false; //����, ������������ ������ ���������
	SDL_Window* window = nullptr; //��������� �� ���� ���������
	SDL_Renderer* renderer = nullptr; //��������� �� ������� ����
	SDL_Event* mainEvent = new SDL_Event; //�������� ������� ����������
	std::shared_ptr<Logger> logger = nullptr;//������ ��� �����
	std::shared_ptr<ErrorsHandler> handler = nullptr; //���������� ������
public:
	bool isRunning(); //��������� ��������� ���������, �������� ��� ���
	//void loadContent(char*); //������ ���?!?!?!
	void step(); //����� ��������� ���������� ���������
	void render(); //����� ��������� �� �����
	auto getLogger();
	Game(); //�����������, ���������� � ���� ������������� ���� �������� ������
	~Game(); //*��������* ������� ������ *���� �������*
};
