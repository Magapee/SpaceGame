#include "ErrorsHandler.h"
#include "Logger.h"

void ErrorsHandler::checkError(void* flag, int code)
{
	if (flag == NULL)
        throw Error(code, logger);
}

void ErrorsHandler::checkError(void* flag, int code, string name)
{
	if (flag == NULL)
        throw Error(code, logger, name);
}

void ErrorsHandler::checkError(int flag, int code)
{
    if (flag < 0)
        throw Error(code, logger);
}

ErrorsHandler::ErrorsHandler(Logger* log)
{
    logger = log;
}

Error::Error(int code, Logger* log, string name)
{
    logger = log;
	errorCode = code;
	errorName = name;
}

void Error::giveError()
{
    stringstream name;
    name << "code:" << errorCode << " message: \"" << errorName << '"';
    logger->logError(name.str());
    delete logger;
}

