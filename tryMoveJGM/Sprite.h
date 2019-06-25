#pragma once
#include "SDL.h"
#include "Coord.h"
#include <iostream>
#include <assert.h>
#include <string>
#include "Camera.h"
#include "Globals.h"



class Sprite
{
private:
    SDL_Texture* texture = nullptr; //текстура спрайта
    SDL_Point* center = nullptr; //центр на спрайте
    int height, width; //ширина и высота текстуры без растяжения
    int x_scale = 1; //растяжение по x
    int y_scale = 1; //аналогично y
    int scale = 1; //общее растяжение, умножается на частные
    SDL_Renderer* renderer = nullptr; //рендерер, куда рисовать (будет заменено на камеру)
public:
    void render(Coord*, Camera*); //отрисовка в нужных координатах с учетом камеры
    static SDL_Renderer* defaultRenderer; //рендерер по умолчанию
	void setCenter(SDL_Point* = nullptr); //установить центр спрайта
    void setScale(int); //установить общее растяжение
    void setScaleX(int); //частные растяжения
    void setScaleY(int);
    Sprite(std::string, SDL_Renderer* = nullptr); //конструктор, принимаем имя файла для загрузки в формате bmp,
    ~Sprite(); //очистка памяти
};
