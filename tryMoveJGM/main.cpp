#include "Game.h"
using namespace std;

//#undef main

int main(int arg, char* args[])
{
    Game* game = new Game;
	try
	{
        int previousFrame = SDL_GetTicks();
        int lagTime = 0;
        while(game->isRunning())
        {
            static bool isStepped;
            isStepped = false;
            int currentFrame = SDL_GetTicks();
            lagTime += currentFrame - previousFrame;
            previousFrame = currentFrame;


            while (lagTime >= MS_PER_TICK)
            {
                isStepped = true;
                game->step();
                lagTime -= MS_PER_TICK;
            }
            if (isStepped)
                game->render();

        }
        delete game;
        return 0;
	}
	catch (Error & handler)
	{
        handler.giveError();
        delete game;
        return 1;
    }
}
