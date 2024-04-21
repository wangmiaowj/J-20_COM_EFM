#include "Actuators.h"
#include "Maths.h"
#include <cmath>

//=========================================================================//
//
//		FILE NAME	: Actuators.cpp
//		AUTHOR		: A4-Comunity-Team & Paul Stich
//		Copyright	: A4-Comunity-Team & Paul Stich
//		DATE		: August 2021
//
//		DESCRIPTION	:	Actuators for visual movements (Ailerons etc.)
//
//================================ Includes ===============================//
//=========================================================================//

Actuator::Actuator() : m_actuatorSpeed{ 10.0 }, m_actuatorPos{ 0.0 }, m_actuatorTargetPos{ 0.0 }, m_actuatorFactor{ 1.0 }
{

}

Actuator::Actuator(double speed) : m_actuatorSpeed{ speed }, m_actuatorPos{ 0.0 }, m_actuatorTargetPos{ 0.0 }, m_actuatorFactor{ 1.0 }
{

}

Actuator::~Actuator()
{

}

void Actuator::zeroInit()
{

}

//NEU eingefügt um die Actuator-Position bei GroundStart setzen zu können
void Actuator::groundInit(double pos, double targetpos)
{

	m_actuatorPos = pos;
	m_actuatorTargetPos = targetpos;
}

void Actuator::hotInit()
{

}
void Actuator::airborneInit()
{

}

void Actuator::setOverSpeedMalFunction()
{
	m_overSpeedMalFunction = true;
}

void Actuator::revOverSpeedMalFunction()
{
	m_overSpeedMalFunction = false;
}

double Actuator::inputUpdate(double targetPosition, double dt)
{
	m_actuatorTargetPos = targetPosition;

	physicsUpdate(dt);

	return m_actuatorPos;
}

void Actuator::physicsUpdate(double dt)
{
	double speedToTarget = (m_actuatorTargetPos - m_actuatorPos) / dt;


	double actuatorSpeed = 0.0;
	if (m_overSpeedMalFunction == true)
	{
		return;
	}

	// dependent on aerodynamic load
	if (m_actuatorPos > 0.0)
	{
		if (m_actuatorTargetPos - m_actuatorPos < 0.0)
		{
			actuatorSpeed = m_actuatorSpeed;
		}
		else
		{
			actuatorSpeed = m_actuatorSpeed * m_actuatorFactor;
		}
	}
	else
	{
		if (m_actuatorTargetPos - m_actuatorPos > 0.0)
		{
			actuatorSpeed = m_actuatorSpeed;
		}
		else
		{
			actuatorSpeed = m_actuatorSpeed * m_actuatorFactor;
		}
	}


	if (abs(speedToTarget) <= actuatorSpeed)
	{
		m_actuatorPos = m_actuatorTargetPos;
	}
	else
	{
		m_actuatorPos += copysign(1.0, speedToTarget) * actuatorSpeed * dt;
	}

	m_actuatorPos = clamp(m_actuatorPos, -1.0, 1.0);
}

double Actuator::getPosition()
{
	return m_actuatorPos;
}

void Actuator::setActuatorSpeed(double factor)
{
	m_actuatorFactor = factor;
}