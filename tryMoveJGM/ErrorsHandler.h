#pragma once
#include <string>
#include <sstream>
#include "Logger.h"
using std::cout;
using std::string;
using std::stringstream;

class Error : public std::exception//Класс, который мы бросаем с помощью throw
{
private:
    string errorName;
    int errorCode;
    Logger* logger;
public:
    Error(int, Logger*, string = "Undeclared error");//Первым  полем передаем код ошибки, вторым - указатель на логгер, 3 - описание
    void giveError();//Функция, которая выполняется в catch для логирования ошибки
};

class ErrorsHandler//Класс для проверки существования указателей и еще какой-то ебанины, хз че ты там хотел
{
private:
    Logger* logger;
public:
    void checkError(void*, int);//Для проверки указателя на NULL, первым полем - указатель, вторым - код ошибки,
    void checkError(void*, int, string);//третьим - описание ошибки (будет в логах если выпадет ошибка)
    void checkError(int, int);//хз че это делает, но вторым полем - код ошибки
    ErrorsHandler(Logger*);//Передаем указатель на логгер
};
