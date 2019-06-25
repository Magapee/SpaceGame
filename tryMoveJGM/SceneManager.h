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
	Scene* currentScene = nullptr; //��������� �� ������� �����
	std::shared_ptr<Logger> logger = nullptr;
	std::shared_ptr<ErrorsHandler> handler = nullptr;
	//std::queue<Actor> transSceneData; //������ ��� �������� ����� ������� (��������������)
	SDL_Renderer* renderer = nullptr;
public:
	SceneManager(Scene*,
		SDL_Renderer*,
		std::shared_ptr<Logger>,
		std::shared_ptr<ErrorsHandler>);
	~SceneManager(); //reserved
	void changeScene(Scene*); //�������� ���, �������� ����� �����, � �������� ��������� ��������� �� ������ ���-�� ���������, � ����������� ������� ��������� ����� �������������
	void step(); //just ������������ ������� �����
	void render(); //������ � �� (��������, ��?!?!?!?!?)
};
