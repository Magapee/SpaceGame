//Game.cpp
#include "Game.h"
#include "MyInitializer.h"

SDL_Renderer* Sprite::defaultRenderer; //TODO: SOLVE!!! (I don't remember, how)
Game::Game()
{

	//TODO: enum as stages
	int stage = 0; //стадии инициализации, так же используется для кода ошибки
	switch (stage)
	{
	case 0: //создание логгера и хэндлера
		logger.reset(new Logger("Main log"));
		handler.reset(new ErrorsHandler(logger.get()));
		logger->logMessage("Logger and handler initialisation succeed...");
		logger->logMessage("Maybe, we don't know exactly, there are no check (TODO: write check)");
		stage++;
	case 1: //инициализация систем SDL
		handler->checkError(SDL_Init(SDL_INIT_EVERYTHING), stage);
		logger->logMessage("SDL initialisation succeed!");
		stage++;
	case 2://Загрузка настроек
		//logger->logMessage("settings initialisation succeed!");
		stage++;
	case 3: //создание окна
		window = SDL_CreateWindow(windowName,
			SDL_WINDOWPOS_CENTERED,
			SDL_WINDOWPOS_CENTERED,
			SCREEN_WIDTH,
			SCREEN_HEIGH,
			SDL_WINDOW_SHOWN);
		handler->checkError(window, stage, "window creation error");
		logger->logMessage("window initialisation succeed!");
		stage++;
	case 4: //создание рендерера
		renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
		handler->checkError(renderer, stage, "renderer creation error");
		logger->logMessage("renderer initialisation succeed!");
		::Sprite::defaultRenderer = renderer; //установка указателя на рендерер для спрайтов
		stage++;
	case 5: //вешание флага
		isRunVar = true;
		logger->logMessage("game initialisation succeed!");
	case 6: //инициализация менеджера сцен
		sceneManager.reset(new SceneManager(new Scene(new MyInitializer), this->renderer, this->logger, this->handler));
	}
}

bool Game::isRunning()//получние состояния игры, работает или не очень
{
	return isRunVar;
}

void Game::step() //обработка внутриигровых состояний
{
	SDL_PumpEvents();
	while (SDL_PollEvent(mainEvent) != 0) //обработка всех событий SDL (всё ещё не понимаю, зачем, кроме окна)
	{
		if (mainEvent->type == SDL_QUIT)
			isRunVar = false;
	}
	//logger->logMessage("Step");
	this->sceneManager->step();
}

void Game::render() //рисование изображения
{
	//logger->logMessage("Render");
	this->sceneManager->render();
}


Game::~Game() //*autistic screams*
{
	logger->logMessage("shutdown game");
	delete mainEvent;
	SDL_Quit();
}


auto Game::getLogger()
{
	return this->logger;
}
