#include "CameraController.h"
#include "Scene.h"
#include "Macros.h"

void CameraController::initialize(){}

void CameraController::step()
{
    static float cx;
    static float cy;
	static float ca;
	unsigned int speed = 4;
    cx = 0;
    cy = 0;
	ca = 0;
	auto angle = degreesToRadians(this->ownerScene->getActiveCamera()->getPosition()->angle);
	if (this->controller->checkKey(keyCodes::UP))
	{
		cy--;
		//cy = speed * cos(this->getCoord().angle);
		//cx = speed * sin(this->getCoord().angle);
	}
    else if(this->controller->checkKey(keyCodes::DOWN))
        cy++;
    if(this->controller->checkKey(keyCodes::LEFT))
        cx--;
    else if(this->controller->checkKey(keyCodes::RIGHT))
        cx++;
	if (this->controller->checkKey(keyCodes::N))
		ca--;
	else if (this->controller->checkKey(keyCodes::M))
		ca++;
	std::stringstream message;
	if ((cx) || (cy) || (ca))
	{
		message << "Camera: "
			<< this->ownerScene->getActiveCamera()->getPosition()->x
			<< ' '
			<< this->ownerScene->getActiveCamera()->getPosition()->y
			<< ' '
			<< this->ownerScene->getActiveCamera()->getPosition()->angle;
		this->logger->logMessage(message.str());
	}
    this->ownerScene->getActiveCamera()->changeCoord(cx, cy, ca);
}
