#include "Fuel_System.h"

//=========================================================================//
//
//		FILE NAME	: FuelSystem.cpp
//		AUTHOR		: Joshua Nelson & Paul Stich
//		Copyright	: Joshua Nelson & Paul Stich
//		DATE		: August 2021
//
//		DESCRIPTION	: Simulation of the Fuelsystem. 
//					  
//					  
//================================ Includes ===============================//
//=========================================================================//


Fuelsystem::Fuelsystem
(
	State& state,
	Input& input,
	Engine& engine,
	APU& apu,
	avSimpleElectricSystem& elec,
	EDPARAM& edParam
) :
	m_state(state),
	m_input(input),
	m_engine(engine),
	m_elec(elec),
	m_cockpitAPI(edParam),
	m_apu(apu)


	//jetzt Tables wenn nötig
	//und: DER LETZTE EINTRAG DARF KEIN KOMMA HABEN!!!

{
	//Sülz und Bla....
}

void Fuelsystem::zeroInit()
{
	m_adjExtFuelQty = 0.0;
	m_adjIntFuelQty = 0.0;
	m_lowFuel = 0.0;
	m_bingoFuel = 0.0;
	params["FUEL_RATIO"] = EdParam(m_cockpitAPI.getParamHandle("FUEL_RATIO"), 0.0);
}

void Fuelsystem::coldInit()
{
	zeroInit();
}

void Fuelsystem::hotInit()
{
	zeroInit();
}

void Fuelsystem::airborneInit()
{
	zeroInit();
}

void Fuelsystem::drawFuel(double dm)
{

}

void Fuelsystem::addFuel(double dm)
{

	//If adding fuel add it to the internal tank.
	if (dm > 0.0)
		dm = addFuelToTank(INTERNAL, dm);

	//If removing fuel remove it from the internal tank.
	if (dm < 0.0)
		dm = addFuelToTank(INTERNAL, dm);

}

void Fuelsystem::update(double dt)
{
	//The factor from the engine for transfer since all transfer relies on bleed,
	//either directly to pressurise the tank or to spin a turbopump.
	double rateFactor = CON_fexch;

	double dm = ((m_engine.FuelFlowUpdate() + m_engine.FuelFlowUpdate2() + m_apu.FuelFlowUpdate()) * 0.454 * 0.00028) * dt; //FuelFlowUpdate ist in lbs/h, hier aber kg/s gebraucht

	//double enginePower = m_engine_L.getRPMNorm() > 0.40;

	//Draw from the Fuselage Tank to the engine, minimum usable fuel.
	if (m_fuel[INTERNAL] > 15.0)
	{
		if (dm > 0.0)
			m_fuel[INTERNAL] -= dm;

		m_hasFuel = true;
	}
	else
	{
		m_hasFuel = false;
	}

	m_engine.setHasFuel(m_hasFuel);
	m_apu.setHasFuel(m_hasFuel);

	double wingTransferRate = 4 * CON_fexch;
	wingTransferRate *= dt;

	//transferFuel(INTERNAL_BACK, INTERNAL_FRONT, wingTransferRate);

	double externOutsideRRate = rateFactor * dt;
	double externMidRRate = rateFactor * dt;
	double externInRRate = rateFactor * dt;
	double externCenterRate = rateFactor * dt;
	double externInLRate = rateFactor * dt;
	double externMidLRate = rateFactor * dt;
	double externOutsideLRate = rateFactor * dt;

	double transferAmount = 0.0;

	transferAmount += m_fuelCapacity[LEFT_OUTSIDE] > 15.0 ? externOutsideLRate : 0.0;
	transferAmount += m_fuelCapacity[LEFT_MID] > 15.0 ? externOutsideLRate : 0.0;
	transferAmount += m_fuelCapacity[LEFT_INSIDE] > 15.0 ? externOutsideLRate : 0.0;
	transferAmount += m_fuelCapacity[CENTER_LINE] > 15.0 ? externCenterRate : 0.0;
	transferAmount += m_fuelCapacity[RIGHT_INSIDE] > 15.0 ? externOutsideRRate : 0.0;
	transferAmount += m_fuelCapacity[RIGHT_MID] > 15.0 ? externOutsideRRate : 0.0;
	transferAmount += m_fuelCapacity[RIGHT_OUTSIDE] > 15.0 ? externOutsideRRate : 0.0;

	if (transferAmount <= m_fuelCapacity[INTERNAL] - m_fuel[INTERNAL])
	{
		transferFuel(LEFT_OUTSIDE, INTERNAL, externOutsideLRate);
		transferFuel(LEFT_MID, INTERNAL, externMidLRate);
		transferFuel(LEFT_INSIDE, INTERNAL, externInLRate);
		transferFuel(CENTER_LINE, INTERNAL, externCenterRate);
		transferFuel(RIGHT_INSIDE, INTERNAL, externInRRate);
		transferFuel(RIGHT_MID, INTERNAL, externMidRRate);
		transferFuel(RIGHT_OUTSIDE, INTERNAL, externOutsideRRate);
	}
	else
	{
		//No Transfer here...just wait for the next frame...
	}

	//printf("Fuel in INT_BACK %f\n", m_fuel[INTERNAL_BACK]);
	//printf("Fuel in INT_Front %f\n", m_fuel[INTERNAL_FRONT]);
	params["FUEL_RATIO"].tg = getFuelQtyInternal() / m_fuelCapacity[0];
	for (auto it = params.begin(); it != params.end(); ++it)
	{
		it->second.update(m_cockpitAPI);
	}
}



