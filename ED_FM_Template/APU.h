#pragma once
#include <stdio.h>
#include "State.h"
#include "Input.h"
#include "Maths.h"
#include "BaseComponent.h"
#include "CockpitAPI_Declare.h"
#include "Avionics/avSimpleElectricSystem.h"
//=========================================================================//
//
//		FILE NAME	: Engine.h
//		AUTHOR		: Paul Stich
//		Copyright	: Paul Stich
//		DATE		: August 2021
//
//		DESCRIPTION	: Everything concerning the engine e.g. Thrust, Heat, spooling-times, 
//					  fuel-flow and overheat-damage, warnings and indicators.
//					  
//================================ Includes ===============================//
//=========================================================================//

//#include "FlightModel.h" war doppelt in flightmodel (Ringabhängigkeit)

class APU
{
public:
	APU(Input& input, avSimpleElectricSystem& elec, EDPARAM& cockpitAPI);

	//Initialization
	virtual void zeroInit();
	virtual void coldInit();
	virtual void hotInit();
	virtual void airborneInit();
	virtual void occupy(int pos);
	virtual bool isOccupy();
	virtual int getOccupier();
	virtual void unoccupy();

	void update(double dt); //in der () "double dt" eingefügt, war vorher ohne

	//----------Functions Engine 1-----------
	double FuelFlowUpdate();

	inline double getRPMNorm()
	{
		return m_rpmNormal;
	}
	inline double getRPM()
	{

		return m_rpmNormal * 723.0; // 100% = 7000 u/min = 7000 * 6,283 / 60 = rad/s
		//return CON_ThrToRPM * updateThrust(); //erstmal um was zu haben
	}
	inline bool isRunning()
	{
		return m_apuRunning;
	}

	//inline double getFuelFlow();//zum testen auskommentiert
	inline void setHasFuel(bool hasFuel)
	{
		m_hasFuel = hasFuel;
	}

private:
	Input& m_input;
	EDPARAM& m_cockpitAPI;
	avSimpleElectricSystem& m_elec;
	void* apuRpm_h = m_cockpitAPI.getParamHandle("APU_EFM_RPM");
	void* startorPos_h = m_cockpitAPI.getParamHandle("EFM_INTERCOM");

	//-------------Engine Values/Commands Engine1----------------------------
	double m_correctedFuelFlow = 0.0;
	double m_fuelFlow = 0.0; //von double zu float wegen Datenübertragung
	double m_rpmNormal = 0.0;

	bool m_hasFuel = true;
	bool m_apuRunning = false;
	bool m_startor_dn = false;

	bool m_occupy = false;
	int m_occupier = 0;
};