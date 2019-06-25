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
    SDL_Texture* texture = nullptr; //�������� �������
    SDL_Point* center = nullptr; //����� �� �������
    int height, width; //������ � ������ �������� ��� ����������
    int x_scale = 1; //���������� �� x
    int y_scale = 1; //���������� y
    int scale = 1; //����� ����������, ���������� �� �������
    SDL_Renderer* renderer = nullptr; //��������, ���� �������� (����� �������� �� ������)
public:
    void render(Coord*, Camera*); //��������� � ������ ����������� � ������ ������
    static SDL_Renderer* defaultRenderer; //�������� �� ���������
	void setCenter(SDL_Point* = nullptr); //���������� ����� �������
    void setScale(int); //���������� ����� ����������
    void setScaleX(int); //������� ����������
    void setScaleY(int);
    Sprite(std::string, SDL_Renderer* = nullptr); //�����������, ��������� ��� ����� ��� �������� � ������� bmp,
    ~Sprite(); //������� ������
};
