#pragma once
#ifndef STATE_H
#define STATE_H

#include "Vec3.h"
#include"BaseComponent.h" //eingefügt

//=========================================================================//
//
//		FILE NAME	: State.h
//		AUTHOR		: Joshua Nelson
//		Copyright	: Joshua Nelson
//		DATE		: May 2020
//
//		DESCRIPTION	: Class to store the info regarding the surroundings of DCS.  
//					  CPP is just for init.
//					  
//================================ Includes ===============================//
//=========================================================================//

struct State
{
	State() {}

	//--------------NEU eingefügt------------------
	//Initialization
	virtual void zeroInit();
	virtual void coldInit();
	virtual void hotInit();
	virtual void airborneInit();
	//----------------------------------------------

	inline void setCurrentStateBodyAxis(double aoa, double beta, const Vec3& angle, const Vec3& omega, const Vec3& omegaDot, const Vec3& speed, const Vec3& airspeed, const Vec3& acceleration);
	inline void setCurrentStateWorldAxis(const Vec3& worldPosition, const Vec3& worldVelocity);
	inline void setCurrentAtmosphere(double temperature, double speedOfSound, double density, double pressure, const Vec3& wind);

	inline void setMach(double mach);
	inline void setCOM(const Vec3& com);
	inline void setWeight(double weight)
	{
		m_weight = weight;
	}

	inline void updateAoaRate(double dt);
	inline double getAoaRate();

	Vec3 m_worldPosition;
	Vec3 m_worldVelocity;
	Vec3 m_worldWind;
	Vec3 m_angle;
	Vec3 m_omega;
	Vec3 m_omegaDot;
	Vec3 m_localSpeed;
	Vec3 m_localAirspeed;
	Vec3 m_localAcceleration;
	Vec3 m_com; //centre of mass

	double m_aoa = 0.0; // geändert von m_aoa; zu m_aoa = 0.0; und initialisiert
	double m_aoa_old = 0.0; // geändert von m_aoa; zu m_aoa = 0.0; und initialisiert
	double m_aoa_rate = 0.0;
	double m_beta = 0.0;
	double m_mach = 0.0;
	double m_speedOfSound = 0.0;
	double m_airDensity = 0.0;
	double m_temperature = 0.0;
	double m_pressure = 0.0;
	double m_weight = 0.0;
};

void State::setCurrentStateBodyAxis(double aoa, double beta, const Vec3& angle, const Vec3& omega, const Vec3& omegaDot, const Vec3& speed, const Vec3& airspeed, const Vec3& acceleration)
{
	m_aoa_old = m_aoa;
	m_aoa = aoa;
	m_beta = beta;
	m_angle = angle;
	m_omega = omega;
	m_omegaDot = omegaDot;
	m_localSpeed = speed;
	m_localAirspeed = airspeed;
	m_localAcceleration = acceleration;
}

void State::setCurrentStateWorldAxis(const Vec3& worldPosition, const Vec3& worldVelocity)
{
	m_worldPosition = worldPosition;
	m_worldVelocity = worldVelocity;
}

void State::setCurrentAtmosphere(double temperature, double speedOfSound, double density, double pressure, const Vec3& wind)
{
	m_temperature = temperature;
	m_speedOfSound = speedOfSound;
	m_airDensity = density;
	m_pressure = pressure;
	m_worldWind = wind;
}

void State::updateAoaRate(double dt)
{
	m_aoa_rate = (m_aoa - m_aoa_old) * (1 / dt);
}
double State::getAoaRate()
{
	return m_aoa_rate;
}
inline void State::setMach(double mach)
{
	m_mach = mach;
}

void State::setCOM(const Vec3& com)
{
	m_com = com;
}

#endif