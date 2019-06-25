#include "MyInitializer.h"
#include "CameraController.h"
#include "Wall.h"

void MyInitializer::initialize(Scene* currentScene)
{
    //currentScene->addActor(new MyActor);
	currentScene->addActor(new CameraController);
	auto tempSprite = new Sprite("Wall.bmp");
	tempSprite->setCenter();
	for (int i = -10; i < 10; i++)
		for (int j = -10; j < 10; j++)
		{
			std::shared_ptr<Wall> tempWall(new Wall);
			tempWall->setSprite(tempSprite);
			tempWall->set(i * 50, j * 50);
			currentScene->addActor(tempWall);
		}
	//currentScene->addActor(new Wall);
}

MyInitializer::~MyInitializer(){}
