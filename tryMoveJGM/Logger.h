//Logger.h
#pragma once
#include <ctime>
#include <string>
#include <iostream>
#include <fstream>
#include <sstream>
#include <chrono>
#include <string.h>
#include <array>
using std::array;
using std::chrono::time_point;
using std::chrono::system_clock;
using std::stringstream;
using std::ofstream;
using std::ctime;
using std::cout;
using std::clog;
using std::cerr;
using std::string;
using std::localtime;


class Logger
{
private:
	//const char* stdLogsPath = ".\\Logs";
	//путь к папке с логами, нереализованно
	//updated 28.04.2019 реализованно внутри Logger::Logger(string)
	//надо ли переходить к переменной? spoiler: YES
	ofstream* logFile = nullptr; //сам файл
	string logName; //имя файла, к нему добавляется время
	void log(string&, string); //универсальная функция логгирования, принимает помимо сообщения его тип

public:
	static string getCurrentTimeString(bool = false); //возвращает дату и время в строковом виде
	//флаг true для использования символов доступных для имени файла
	Logger(string = "Log");//конструктор, принимает имя файла
	~Logger(); //деструктор, закрывает файл, чистит память *КТО КРИЧИТ???*
	void logMessage(string); //логгирование сообщения, не отображается в release
	void logError(string); //логгирование ошибки, отображается во всех конфигурациях
};
