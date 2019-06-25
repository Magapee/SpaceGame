#include "Logger.h"
#include <assert.h>

Logger::Logger(string lName)
{
	logName = lName;
	logFile = new ofstream;
    stringstream name;
	std::system("mkdir logs"); //создание папки (возможна ли ошибка с наличием прав?)
    #ifdef _WINDOWS //прописывание пути к папке в зависимости от UNIXALIKE
    name << "logs\\";
    #else
    name << "logs/";
    #endif
	name << logName << '_' << Logger::getCurrentTimeString(true) << ".log";
	//cout << name.str() << '\n';
	logFile->open(name.str());
	assert(logFile->is_open()); //TODO: There is errors handler implementation
	*logFile << "Logging " << logName << " has been started successfully at " << Logger::getCurrentTimeString() << '\n';
}

Logger::~Logger()
{
	logFile->close();
	delete logFile;
}

void Logger::log(string& message, string type)
{
    stringstream outputMessage;
    outputMessage << '[' << getCurrentTimeString() << ']' << type << ": ";
    outputMessage << message << std::endl;
	cout << outputMessage.str();
	(*logFile) << outputMessage.str();
}

void Logger::logMessage(string message)
{
    //#ifdef _DEBUG
    log(message, "Message");
    //#endif // _DEBUG
}

void Logger::logError(string message)
{
    log(message, "Error");
}


string Logger::getCurrentTimeString(bool isForFileName)
{
    time_point<system_clock> timeP;
    timeP = system_clock::now();
    time_t tempTime = system_clock::to_time_t(timeP);
    tm* TempTimeStruct;
    TempTimeStruct = localtime(&tempTime);
	stringstream tempSSteam;
	char space, dots;
	if (isForFileName)
	{
		space = '_';
		dots = '-';
	}
	else
	{
		space = ' ';
		dots = ':';
	}
	if (isForFileName)
    {
        tempSSteam << TempTimeStruct->tm_mday << '.'
		<< TempTimeStruct->tm_mon + 1 << space;
    }
	tempSSteam << TempTimeStruct->tm_hour
		<< dots << TempTimeStruct->tm_min << dots << TempTimeStruct->tm_sec;
	return tempSSteam.str();
}
