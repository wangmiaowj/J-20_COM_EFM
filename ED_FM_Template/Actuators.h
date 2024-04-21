#pragma once
#include "BaseComponent.h"

//=========================================================================//
//
//		FILE NAME	: Actuators.h
//		AUTHOR		: A4-Comunity-Team & Paul Stich
//		Copyright	: A4-Comunity-Team & Paul Stich
//		DATE		: August 2021
//
//		DESCRIPTION	:	Actuators for visual movements (Ailerons etc.)
//
//================================ Includes ===============================//
//=========================================================================//

class Actuator
{
public:
	Actuator();
	Actuator(double speed);
	~Actuator();

	virtual void Actuator::zeroInit();
	void Actuator::groundInit(double pos, double targetpos); //neu eingefügt für GroundInits
	virtual void Actuator::hotInit();
	virtual void Actuator::airborneInit();

	double inputUpdate(double targetPosition, double dt);
	void physicsUpdate(double dt);
	double getPosition();
	void setActuatorSpeed(double factor);
	void setOverSpeedMalFunction();
	void revOverSpeedMalFunction();


private: // = 0.0; bei allen actuators eingefügt, vorher fehlte das!!!
	double m_actuatorFactor = 0.0;
	double m_actuatorSpeed = 0.0;
	double m_actuatorPos = 0.0;
	double m_actuatorTargetPos = 0.0;
	bool m_overSpeedMalFunction = false;
};