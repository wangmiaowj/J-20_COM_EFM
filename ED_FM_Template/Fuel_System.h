#pragma once
#include "Maths.h"
#include "AeroData_1.h"
#include "State.h"
#include "Input.h"
#include "Vec3.h"
#include "Engine.h"

//=========================================================================//
//
//		FILE NAME	: FuelSystem.h
//		AUTHOR		: Joshua Nelson & Paul Stich
//		Copyright	: Joshua Nelson & Paul Stich
//		DATE		: February 2022
//
//		DESCRIPTION	: Simulation of the Fuelsystem + Indicators and Warnings. 
//					  
//					  
//================================ Includes ===============================//
//=========================================================================//


class Fuelsystem
{
public:
	Fuelsystem(State& state, Input& input, Engine& engine, APU& apu, avSimpleElectricSystem& elec, EDPARAM& edParam);

	virtual void zeroInit();
	virtual void coldInit();
	virtual void hotInit();
	virtual void airborneInit();

	//---------funktionierte gut mit den 5----------
	/*enum Tank
	{
		INTERNAL,
		LEFT_TIP,
		LEFT_WING,
		RIGHT_WING,
		RIGHT_TIP,
		NUMBER_OF_TANKS,
		UNUSED,
	};*/
	//-------neuer schei?mit 11ven-----------------
	//-------geändert auf 5 Tanks + NumberOfTanks + Unused aufgrund StationToTank-----------------
	enum Tank
	{
		INTERNAL,
		LEFT_OUTSIDE,
		LEFT_MID,
		LEFT_INSIDE,
		CENTER_LINE,
		RIGHT_INSIDE,
		RIGHT_MID,
		RIGHT_OUTSIDE,
		NUMBER_OF_TANKS,
		UNUSED
	};


	void addFuel(double dm);
	void drawFuel(double dm);
	void update(double dt);

	inline bool hasFuel() const;

	inline double transferFuel(Tank from, Tank to, double dm);
	inline double addFuelToTank(Tank tank, double dm, double min = 0.0);
	//inline double transferRateFactor();//brauchen wir nicht, da der fest ist
	inline bool externalFull() const;

	inline double getFuelQty(Tank tank) const;
	inline double getFuelQtyExternal() const;
	inline double getFuelQtyExternalLeft() const;
	inline double getFuelQtyExternalRight() const;
	inline double getFuelQtyExternalTip() const;
	inline double getFuelQtyExternalWing() const;
	inline double getFuelQtyInternal() const;
	inline double getFuelQtyTotal() const;
	inline double getAdjFuelQtyExternal();
	inline double getAdjFuelQtyInternal();
	inline double lowFuelWarning();
	inline double bingoFuelWarning();
	inline double getFuelQtyDelta(Tank tank) const;
	inline const Vec3& getFuelPos(Tank tank) const;
	inline Tank getSelectedTank() const;

	inline Tank stationToTank(int station) //StationToTank funktion im Public-Bereich gelassen								      
	{
		return m_stationToTank[station];
	}

	inline double getTotalCapacity() const;


	inline void setFuelQty(Tank tank, const Vec3& position, double value);
	inline void setInternal(double value);
	inline void setFuelCapacity(double lo, double lm, double li, double cl, double ri, double rm, double ro);
	inline void setFuelPrevious(Tank tank);
	inline void setSelectedTank(Tank tank);

private:

	Vec3 m_force;
	State& m_state;
	Input& m_input;
	Engine& m_engine;
	APU& m_apu;
	avSimpleElectricSystem& m_elec;
	EDPARAM& m_cockpitAPI;

	//11 Stations mit einer Nummerzuordnung zu den tatsächlichen Tanks
	Tank m_stationToTank[12] =
	{
		UNUSED,
		UNUSED,
		UNUSED,
		UNUSED,
		UNUSED,
		UNUSED,
		UNUSED,
		UNUSED,
		LEFT_INSIDE,
		RIGHT_INSIDE,
		LEFT_OUTSIDE,
		RIGHT_OUTSIDE,
	};

	double m_fuel[NUMBER_OF_TANKS] = { 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0 }; //vorher waren es 5 jetzt nur 4 (3x external 1x intrenal)

	double m_fuelPrevious[NUMBER_OF_TANKS] = { 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0 };

	bool m_fuelEmpty[NUMBER_OF_TANKS] = { false, false, false, false, false, false, false, false };

	bool m_fuelSet[NUMBER_OF_TANKS] = { false, false, false, false, false, false, false, false }; //Check, if tank is empty or full

	//										   INT      OUS_L  MID_L IN_L   CL    IN_R MID_R OUS_R
	double m_fuelCapacity[NUMBER_OF_TANKS] = { 9500.0, 0.0,  0.0, 0.0, 0.0, 0.0, 0.0, 0.0 }; //values in kg WAS 2416.0, 4000.0, 1190.0, 1930.0, 1190.0

	//---------hier die Position der Tanks. Der CenterLine dürfte genau auf dem Schwerpunkt liegen. Die Tragflächen-Tanks werde ich noch raussuchen....
	//---------CG sollte genau auf (+0.755, -0.25, 0.0) liegen. 
	//Erster Versuch TankF= Vec3(1.15, -0.25, 0.0) TankB = Vec3( -0.755, -0.25, 0.0)
	//Zweiter Versuch { Vec3(1.15, -0.25, 0.0), Vec3(-0.955, -0.25, 0.0), Vec3(), Vec3(), Vec3(),} bei neuem COM auf 0.755
	Vec3 m_fuelPos[NUMBER_OF_TANKS] = { Vec3(), Vec3(), Vec3(), Vec3(), Vec3(), Vec3(), Vec3(), Vec3(), }; //hier kommt die Position der Tanks rein, wobei der GENAUE Wert der Lua hier rein müsste, damit die Tanks auf dem CG liegen.

	bool m_hasFuel = true; //this is false if the fuel cannot be delivered or all fuel is burned.

	Tank m_selectedTank = INTERNAL;

	double m_lowFuel = 0.0;
	double m_bingoFuel = 0.0;

	float m_adjExtFuelQty = 0.0;
	double m_adjIntFuelQty = 0.0;
	std::map<std::string, EdParam>params;
};

void Fuelsystem::setFuelQty(Tank tank, const Vec3& position, double value)
{
	m_fuelSet[tank] = true; //To check if there is an external tank, if yes = true
	m_fuel[tank] = value;
	m_fuelPos[tank] = position;
	//hier habe ich m_fuelPos[tank] = position
}

void Fuelsystem::setFuelPrevious(Tank tank)
{
	m_fuelPrevious[tank] = m_fuel[tank];
}

void Fuelsystem::setInternal(double value)
{

	m_fuel[INTERNAL] = value;

	//m_fuelPos[INTERNAL] = Vec3(); auskomentiert, da keine Position übergeben wird von ed_fm_set_internal_fuel !!
}

void Fuelsystem::setFuelCapacity(double lo, double lm, double li, double cl, double ri, double rm, double ro)
{
	m_fuelEmpty[LEFT_OUTSIDE] = lo < 0.0;
	m_fuelEmpty[LEFT_MID] = lm < 0.0;
	m_fuelEmpty[LEFT_INSIDE] = li < 0.0;
	m_fuelEmpty[CENTER_LINE] = cl < 0.0;
	m_fuelEmpty[RIGHT_INSIDE] = ri < 0.0;
	m_fuelEmpty[RIGHT_MID] = rm < 0.0;
	m_fuelEmpty[RIGHT_OUTSIDE] = ro < 0.0;

	// Check each of the external tanks for negative fuel capacity.
	// This means it is an empty tank.
	// Empty tanks need to have their fuel removed. They don't start empty so DCS
	// knows how much fuel the aircraft should have when fully fueled (taking fuel from tanker).
	// If the fuel has just been set then we need to jump into action to remove the fuel from the
	// tank if it is an empty tank. We then need to make sure this doesn't happen again so set the fuelSet
	// to false for this specific tank.
	if (m_fuelSet[LEFT_OUTSIDE] && lo < 0.0)
	{
		m_fuel[LEFT_OUTSIDE] = 0.0;
		m_fuelSet[LEFT_OUTSIDE] = false;
	}

	if (m_fuelSet[LEFT_MID] && lm < 0.0)
	{
		m_fuel[LEFT_MID] = 0.0;
		m_fuelSet[LEFT_MID] = false;
	}

	if (m_fuelSet[LEFT_INSIDE] && li < 0.0)
	{
		m_fuel[LEFT_INSIDE] = 0.0;
		m_fuelSet[LEFT_INSIDE] = false;
	}

	if (m_fuelSet[CENTER_LINE] && cl < 0.0)
	{
		m_fuel[CENTER_LINE] = 0.0;
		m_fuelSet[CENTER_LINE] = false;
	}

	if (m_fuelSet[RIGHT_INSIDE] && ri < 0.0)
	{
		m_fuel[RIGHT_INSIDE] = 0.0;
		m_fuelSet[RIGHT_INSIDE] = false;
	}

	if (m_fuelSet[RIGHT_MID] && rm < 0.0)
	{
		m_fuel[RIGHT_MID] = 0.0;
		m_fuelSet[RIGHT_MID] = false;
	}

	if (m_fuelSet[RIGHT_OUTSIDE] && ro < 0.0)
	{
		m_fuel[RIGHT_OUTSIDE] = 0.0;
		m_fuelSet[RIGHT_OUTSIDE] = false;
	}

	m_fuelCapacity[LEFT_OUTSIDE] = abs(lo);
	m_fuelCapacity[LEFT_MID] = abs(rm);
	m_fuelCapacity[LEFT_INSIDE] = abs(ri);
	m_fuelCapacity[CENTER_LINE] = abs(cl);
	m_fuelCapacity[RIGHT_INSIDE] = abs(ri);
	m_fuelCapacity[RIGHT_MID] = abs(rm);
	m_fuelCapacity[RIGHT_OUTSIDE] = abs(ro);
}


void Fuelsystem::setSelectedTank(Tank tank)
{
	m_selectedTank = tank;
}

double Fuelsystem::getFuelQtyDelta(Tank tank) const
{
	return m_fuel[tank] - m_fuelPrevious[tank];
}

double Fuelsystem::getFuelQty(Tank tank) const
{
	return m_fuel[tank];
}

double Fuelsystem::getFuelQtyExternal() const
{
	return m_fuel[LEFT_OUTSIDE] + m_fuel[LEFT_MID] + m_fuel[LEFT_INSIDE] + m_fuel[CENTER_LINE] +
		m_fuel[RIGHT_INSIDE] + m_fuel[RIGHT_MID] + m_fuel[RIGHT_OUTSIDE];
}

double Fuelsystem::getAdjFuelQtyExternal()
{
	//---------hier muss immer der Wert in Pfund in relation zu der Anzeige rein
	//bei einer Anzeige VOLL = 1.0 und VOLL ist 6.416kg dann ist der Modifikator 1/6416 = 0.00015586
	//Hier muss jetzt also die Anzeige bei 1.0 auf 6416kg oder auch 14.115 lbs gesetzt werden

	m_adjExtFuelQty = getFuelQtyExternal() * 0.0003274;//auf 3054 (3*1018) kg für 100% gerechnet


	/*printf("ExternalFuel %f \n", m_adjExtFuelQty);
	printf("EF_Wing-L %f \n", m_fuel[LEFT_WING]);
	printf("EF_Wing-R %f \n", m_fuel[RIGHT_WING]);
	printf("EF_TIP-L %f \n", m_fuel[LEFT_TIP]);
	printf("EF_TIP-R %f \n", m_fuel[RIGHT_TIP]);*/


	return m_adjExtFuelQty;
}


double Fuelsystem::getFuelQtyExternalLeft() const
{
	return m_fuel[LEFT_OUTSIDE] + m_fuel[LEFT_MID] + m_fuel[LEFT_INSIDE];
}

double Fuelsystem::getFuelQtyExternalRight() const
{
	return m_fuel[RIGHT_OUTSIDE] + m_fuel[RIGHT_MID] + m_fuel[RIGHT_INSIDE];
}

//------------die folgenden beiden sind "DOPPEL-MOPPEL", aber wegen Bresigkeit drin gelassen
double Fuelsystem::getFuelQtyExternalTip() const
{
	return m_fuel[RIGHT_OUTSIDE] + m_fuel[LEFT_OUTSIDE];
}

double Fuelsystem::getFuelQtyExternalWing() const
{
	return m_fuel[RIGHT_OUTSIDE] + m_fuel[RIGHT_MID] + m_fuel[RIGHT_INSIDE] + m_fuel[LEFT_INSIDE] + m_fuel[LEFT_MID] + m_fuel[LEFT_OUTSIDE];
}

double Fuelsystem::getFuelQtyTotal() const
{
	return m_fuel[RIGHT_OUTSIDE] + m_fuel[RIGHT_MID] + m_fuel[RIGHT_INSIDE] + m_fuel[CENTER_LINE] +
		m_fuel[LEFT_INSIDE] + m_fuel[LEFT_MID] + m_fuel[LEFT_OUTSIDE] + m_fuel[CENTER_LINE] + m_fuel[INTERNAL];
}

double Fuelsystem::getFuelQtyInternal() const
{
	return m_fuel[INTERNAL];
}

double Fuelsystem::getAdjFuelQtyInternal()
{
	//---------hier muss immer der Wert in Pfund in relation zu der Anzeige rein
	//bei einer Anzeige VOLL = 1.0 und VOLL ist 6.215kg dann ist der Modifikator 1/6215 = 0.0001609

	m_adjIntFuelQty = getFuelQtyInternal() * 0.0001609;

	return m_adjIntFuelQty;
}

const Vec3& Fuelsystem::getFuelPos(Tank tank) const
{
	return m_fuelPos[tank];
}

Fuelsystem::Tank Fuelsystem::getSelectedTank() const
{
	return m_selectedTank;
}

/*Fuelsystem::Tank Fuelsystem::stationToTank(int station)
{
	return m_stationToTank[station];
}*/

double Fuelsystem::getTotalCapacity() const
{
	double total = 0.0;
	for (int i = 0; i < NUMBER_OF_TANKS; i++)
	{
		total += m_fuelCapacity[i];
	}

	total += 1.0;

	return total;
}

bool Fuelsystem::hasFuel() const
{
	return m_hasFuel;
}

bool Fuelsystem::externalFull() const
{
	return m_fuel[LEFT_OUTSIDE] == m_fuelCapacity[LEFT_OUTSIDE] &&
		m_fuel[LEFT_MID] == m_fuelCapacity[LEFT_MID] &&
		m_fuel[LEFT_INSIDE] == m_fuelCapacity[LEFT_INSIDE] &&
		m_fuel[CENTER_LINE] == m_fuelCapacity[CENTER_LINE] &&
		m_fuel[RIGHT_INSIDE] == m_fuelCapacity[RIGHT_INSIDE] &&
		m_fuel[RIGHT_MID] == m_fuelCapacity[RIGHT_MID] &&
		m_fuel[RIGHT_OUTSIDE] == m_fuelCapacity[RIGHT_OUTSIDE];
}

double Fuelsystem::transferFuel(Tank from, Tank to, double dm)
{
	double desiredTransfer = dm;

	//15 kg minimum usable should be tank specific but it's not that different.
	double remainingFrom = m_fuel[from] - 15.0;
	//Check there is enough fuel to take.
	if (remainingFrom < dm)
		dm = std::max(remainingFrom, 0.0);

	//Check there is enough room in the to tank.
	double spaceInTo = m_fuelCapacity[to] - m_fuel[to];
	if (spaceInTo < dm)
		dm = std::max(spaceInTo, 0.0);

	//Actually transfer the fuel
	m_fuel[from] -= dm;
	m_fuel[to] += dm;

	return desiredTransfer - dm;
}

double Fuelsystem::addFuelToTank(Tank tank, double dm, double min)
{
	double desiredTransfer = dm;

	double remainingFuel = m_fuel[tank] - min;
	double remainingSpace = m_fuelCapacity[tank] - m_fuel[tank];

	if (dm < 0.0 && remainingFuel + dm < 0.0)
		dm = std::min(-remainingFuel, 0.0);

	if (dm > 0.0 && remainingSpace < dm)
		dm = std::max(remainingSpace, 0.0);

	m_fuel[tank] += dm;

	return desiredTransfer - dm;
}

double Fuelsystem::lowFuelWarning()
{
	if (m_elec.isDC())
	{
		if (getFuelQtyTotal() <= 454.0)
		{
			m_lowFuel = 1.0;
		}
		else
		{
			m_lowFuel = 0.0;
		}
	}
	else
	{
		m_lowFuel = 0.0;
	}

	return m_lowFuel;
}

double Fuelsystem::bingoFuelWarning()
{
	if (m_elec.isDC())
	{

		if (getFuelQtyTotal() <= 908.0)
		{
			m_bingoFuel = 1.0;
		}
		else
		{
			m_bingoFuel = 0.0;
		}
	}
	else
	{
		m_bingoFuel = 0.0;
	}

	return m_bingoFuel;
}
