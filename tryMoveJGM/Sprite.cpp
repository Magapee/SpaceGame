#include "Sprite.h"
#include "Macros.h"


Sprite::Sprite(std::string fileName, SDL_Renderer* newRenderer)
{
    if (newRenderer == nullptr)
        if (Sprite::defaultRenderer == 0x0)
            assert(0); // TODO: there is an errors handler...
        else
            this->renderer = Sprite::defaultRenderer;
    else
        this->renderer = newRenderer;
    //загрузка текстуры
    SDL_Surface* tempSurface = SDL_LoadBMP(fileName.c_str());
    if (tempSurface == NULL) //проверка на открытие текстуры
    {
        assert(0); //TODO: исправить на исключение, пристыковать к обработчику ошибок
    }
    texture = SDL_CreateTextureFromSurface(renderer, tempSurface);
    //auto e = SDL_GetError();
    height = tempSurface->h;
    width = tempSurface->w;
    SDL_FreeSurface(tempSurface);
    //delete tempSurface;
    center = new SDL_Point;
    center->x = 1;
    center->y = 1;
}



void Sprite::setCenter(SDL_Point* newCenter)
{
	if (!newCenter)
	{
		center->x = this->width / 2;
		center->y = this->height / 2;
	}
	else
	{
		center->x = newCenter->x;
		center->y = newCenter->y;
	}
}

void Sprite::setScale(int s)
{
    scale = s;
}

void Sprite::setScaleX(int s)
{
    x_scale = s;
}

void Sprite::setScaleY(int s)
{
    y_scale = s;
}

void Sprite::render(Coord* coordinates, Camera* activeCamera) //магия ТУТ
{
    auto dstRect = new SDL_Rect;
	auto angle = degreesToRadians(activeCamera->getPosition()->angle);
	angle = -angle;
	float renderingAngle = coordinates->angle - activeCamera->getPosition()->angle;
	int x = coordinates->x - activeCamera->getPosition()->x;
	int y = coordinates->y - activeCamera->getPosition()->y;
	dstRect->x =  x * cos(angle) + y * sin(-angle) + SCREEN_WIDTH/2;
	dstRect->y =  y * cos(-angle) + x * sin(angle) + SCREEN_HEIGH/2;
    dstRect->h = height*scale*y_scale;
    dstRect->w = width*scale*x_scale;
    SDL_RenderCopyEx(renderer, texture, NULL, dstRect, renderingAngle, NULL, SDL_RendererFlip::SDL_FLIP_NONE);
    delete dstRect;
}

Sprite::~Sprite()
{
    SDL_DestroyTexture(texture);
    delete center;
}
