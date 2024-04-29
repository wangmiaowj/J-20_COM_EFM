#include "Engine.h"

//=========================================================================//
//
//		FILE NAME	: Engine.cpp
//		AUTHOR		: Paul Stich
//		Copyright	: Paul Stich
//		DATE		: August 2021
//
//		DESCRIPTION	: Everything concerning the engine e.g. Thrust, Heat, spooling-times, 
//					  fuel-flow and overheat-damage, warnings and indicators.
//					  
//================================ Includes ===============================//
//=========================================================================//

Engine::Engine
(
	State& state,
	Input& input,
	avSimpleElectricSystem& elec,
	APU& apu,
	EDPARAM& edParam
) :
	m_state(state),
	m_input(input),
	m_elec(elec),
	m_apu(apu),
	m_cockpitAPI(edParam),

	//---------------Thrust------------------------------------
	PMax(DAT_PMax, CON_PMaxmin, CON_PMaxmax),
	PFor(DAT_PFor, CON_PFormin, CON_PFormax),
	CADen(DAT_CADen, CON_CADenMin, CON_CADenMax),
	EngDel(DAT_EngDel, CON_EngDelMin, CON_EngDelMax)
	//der letzte Eintrag darf KEIN Komma haben...
{
	//huhu!!
}

void Engine::zeroInit()
{
	m_scalarVelocity = 0.0;
	m_scalarVelocitySquared = 0.0;
	//-------------Engine Values/Commands----------------------------
	m_thrust = 0.0;
	m_thrust2 = 0.0;

	m_burner = 0.0;
	m_burner2 = 0.0;
	m_fuelFlow = 0.0;
	m_fuelFlow2 = 0.0;
	m_correctedFuelFlow = 0;
	m_correctedFuelFlow2 = 0;
	m_corrAirDensity = 0.0;
	m_corrAirDensity2 = 0.0;

	m_spoolFactor = 0.0;
	m_spoolFactor2 = 0.0;
	m_spoolFactorPrevious = 0.0;
	m_spoolFactorPrevious2 = 0.0;
	m_deltaSpool = 0.0;
	m_deltaSpool2 = 0.0;
	m_throttleNEW = 0.0;
	m_throttleNEW2 = 0.0;
	m_newThrottle = 0.0;
	m_newThrottle2 = 0.0;
	m_oldThrottle = 0.0;
	m_oldThrottle2 = 0.0;
	m_deltaSpoolABS = 0.0;
	m_deltaSpoolABS2 = 0.0;
	m_newSpoolStep = 0.0;
	m_newSpoolStep2 = 0.0;
	m_desiredThrottle = 0.0;
	m_desiredThrottle2 = 0.0;

	m_spoolFactorFuel = 0.0;
	m_deltaSpoolFuel = 0.0;
	m_newThrottleFuel = 0.0;
	m_oldThrottleFuel = 0.0;
	m_deltaSpoolABSFuel = 0.0;
	m_newSpoolStepFuel = 0.0;
	m_spoolFactorFuel1 = 0.0;
	m_spoolFactorFuel2 = 0.0;
	m_deltaSpoolFuel2 = 0.0;
	m_newThrottleFuel2 = 0.0;
	m_oldThrottleFuel2 = 0.0;
	m_deltaSpoolABSFuel2 = 0.0;
	m_newSpoolStepFuel2 = 0.0;
	m_spoolFactorFuel2 = 0.0;

	m_needRestart = false;
	m_needRepair = false;
	m_needRestart2 = false;
	m_needRepair2 = false;

	m_spoolCDelta = 0.0;
	m_spoolCDeltaABS = 0.0;
	m_spoolCDown = 0.0;
	m_spoolCNewSpool = 0.0;
	m_spoolCOldSpool = 0.0;
	m_spoolCSpoolStep = 0.0;
	m_spoolCStart = 0.0;
	m_spoolCFactor = 0.0;
	m_spoolCDelta2 = 0.0;
	m_spoolCDeltaABS2 = 0.0;
	m_spoolCDown2 = 0.0;
	m_spoolCNewSpool2 = 0.0;
	m_spoolCOldSpool2 = 0.0;
	m_spoolCSpoolStep2 = 0.0;
	m_spoolCStart2 = 0.0;
	m_spoolCFactor2 = 0.0;

	m_spoolHDelta = 0.0;
	m_spoolHDeltaABS = 0.0;
	m_spoolHFactor = 0.0;
	m_spoolHNewSpool = 0.0;
	m_spoolHOldSpool = 0.70;
	m_spoolHSpoolStep = 0.0;
	m_spoolHDelta2 = 0.0;
	m_spoolHDeltaABS2 = 0.0;
	m_spoolHFactor2 = 0.0;
	m_spoolHNewSpool2 = 0.0;
	m_spoolHOldSpool2 = 0.70;
	m_spoolHSpoolStep2 = 0.0;

	m_rpmNormal = 0.0;
	m_rpmPrevious = 0.0;
	m_rpmNormal2 = 0.0;
	m_rpmPrevious2 = 0.0;

	m_tempInC = 0.0;
	m_tempInC2 = 0.0;

	m_overHeat = 0.0;
	m_heatOne = 0.0;
	m_heatTwo = 0.0;
	m_heatTimerUP = 0;
	m_heatTimerDOWN = 0;
	m_overSpeedInd = 0.0;
	m_heatFailure = false;
	m_overHeatInd = 0.0;
	m_overHeat2 = 0.0;
	m_heatOne2 = 0.0;
	m_heatTwo2 = 0.0;
	m_heatTimerUP2 = 0;
	m_heatTimerDOWN2 = 0;
	m_overSpeedInd2 = 0.0;
	m_heatFailure2 = false;
	m_overHeatInd2 = 0.0;


	m_hasFuel = true;
	m_ignitors1 = false;
	m_ignitors2 = false;
	m_fan_l = -1.0;
	m_fan_r = -1.0;
	//m_input.m_engine_start = 0.0; auskomentiert da in Funktionen
	//m_input.m_engine_stop = 0.0;


}

void Engine::coldInit()
{
	zeroInit();

}

void Engine::hotInit()
{
	zeroInit();

	m_ignitors1 = true;
	m_ignitors2 = true;

	m_rpmNormal = 0.72;
	m_rpmNormal2 = 0.72;
	m_rpmPrevious = 0.72;
	m_rpmPrevious2 = 0.72;
	//m_input.m_engine_start = 1.0;
	m_spoolHOldSpool = 0.70;
	m_spoolCOldSpool = 0.71;
	m_spoolHOldSpool2 = 0.70;
	m_spoolCOldSpool2 = 0.71;

	m_fan_l = 0;
	m_fan_r = 0;
	//m_input.m_engine_start = 1.0;

}

void Engine::airborneInit()
{
	zeroInit();

	m_ignitors1 = true;
	m_ignitors2 = true;
	m_rpmNormal = 0.85;
	m_rpmPrevious = 0.85;
	m_rpmNormal2 = 0.85;
	m_rpmPrevious2 = 0.85;
	//m_input.m_engine_start = 1.0;
	m_spoolHOldSpool = 0.70;
	m_spoolCOldSpool = 0.71;
	m_spoolHOldSpool2 = 0.70;
	m_spoolCOldSpool2 = 0.71;

	m_fan_l = 0;
	m_fan_r = 0;
	m_rpmNormal2 = 0.85;
	m_rpmPrevious2 = 0.85;
	//m_input.m_engine_start = 1.0;
	m_spoolHOldSpool2 = 0.70;
	m_spoolCOldSpool2 = 0.71;
}

void Engine::update(double dt)
{
	double corrThrottle = 0.0;
	if ((m_input.getEngineStart1() == 1.0) && (m_needRepair == false) && (m_heatFailure == false) && (m_needRestart == false))
	{
		m_ignitors1 = true;
	}
	if ((m_input.getEngineStop1() == 1.0) || (m_input.getEngineStart1() == 0.0) || (m_needRepair == true) || (m_heatFailure == true) || (m_needRestart == true))
	{
		m_ignitors1 = false;
		//m_input.m_engine_start = 0.0;
		//m_input.m_engine_stop = 0.0;
	}
	if ((m_input.getEngineStart2() == 1.0) && (m_needRepair2 == false) && (m_heatFailure2 == false) && (m_needRestart2 == false))
	{
		m_ignitors2 = true;
	}
	if ((m_input.getEngineStop2() == 1.0) || (m_input.getEngineStart2() == 0.0) || (m_needRepair2 == true) || (m_heatFailure2 == true) || (m_needRestart2 == true))
	{
		m_ignitors2 = false;
		//m_input.m_engine_start = 0.0;
		//m_input.m_engine_stop = 0.0;
	}

	//------------NEW corrected Air Density with a lot of steps through lookup----------
	//-------------OLD Version---------------------------------------------------------
	/*if (m_state.m_airDensity <= 0.88)
	{
		m_corrAirDensity = CADen(m_state.m_airDensity);
	}
	else
	{
		m_corrAirDensity = 0.0;
	}*/
	//-----------------NEW Version mit CAD bis SL---------------------------------------
	m_corrAirDensity = CADen(m_state.m_airDensity);
	m_corrAirDensity2 = CADen(m_state.m_airDensity);

	//--------------END of corrected airdensity----------------------------------------------
	//--------------Start of Engine starting up and spooling down//Noch drüber nachdenken----------------------------	

		//RESET updateSpoolCold Engine 1
	if ((m_ignitors1 == false) || (m_hasFuel == false) || (overHeat() == 1.0))
	{
		m_spoolCOldSpool = getRPMNorm();
		m_spoolCDelta = 0.0;
		m_spoolCDeltaABS = 0.0;
		m_spoolCFactor = 0.0;
		m_spoolCNewSpool = 0.0;
		m_spoolCSpoolStep = 0.0;

	}
	if ((m_ignitors2 == false) || (m_hasFuel == false) || (overHeat2() == 1.0))
	{
		m_spoolCOldSpool2 = getRPMNorm2();
		m_spoolCDelta2 = 0.0;
		m_spoolCDeltaABS2 = 0.0;
		m_spoolCFactor2 = 0.0;
		m_spoolCNewSpool2 = 0.0;
		m_spoolCSpoolStep2 = 0.0;

	}

	//RESET updateSpoolHot Engine 1
	if ((m_ignitors1 == true) && (m_hasFuel == true))
	{
		m_spoolHOldSpool = getRPMNorm();
		m_spoolHDelta = 0.0;
		m_spoolHDeltaABS = 0.0;
		m_spoolHFactor = 0.0;
		m_spoolHNewSpool = 0.0;
		m_spoolHSpoolStep = 0.0;

	}
	//RESET updateSpoolHot Engine 2
	if ((m_ignitors2 == true) && (m_hasFuel == true))
	{
		m_spoolHOldSpool2 = getRPMNorm2();
		m_spoolHDelta2 = 0.0;
		m_spoolHDeltaABS2 = 0.0;
		m_spoolHFactor2 = 0.0;
		m_spoolHNewSpool2 = 0.0;
		m_spoolHSpoolStep2 = 0.0;
	}
	if (m_input.getStartor() == 0 && m_engStartor_dn == true)
	{
		m_engStartor_dn = false;
	}
	if (m_elec.isDC())
	{
		if (m_input.getStartor() == 1 && m_engStartor_dn == false)
		{
			m_engStartor_dn = true;
			if (m_input.getStartorPos() == 2)
			{
				if (m_input.getEngineStart1() == 1)
				{
					printf("EngStop1=============================================================================\n");
					m_input.engineStop1();
					m_apu.unoccupy();
				}
				else if (!m_apu.isOccupy() && m_apu.isReady() && !m_extinguishing)
				{
					printf("EngStart1=============================================================================\n");
					m_input.engineStart1();
					m_apu.occupy(1);
				}
			}
			else if (m_input.getStartorPos() == 3)
			{
				if (m_input.getEngineStart2() == 1)
				{
					printf("EngStop2=============================================================================\n");
					m_input.engineStop2();
					m_apu.unoccupy();
				}
				else if (!m_apu.isOccupy() && m_apu.isReady() && !m_extinguishing2)
				{
					printf("EngStart2=============================================================================\n");
					m_input.engineStart2();
					m_apu.occupy(2);
				}
			}
		}
	}
	else if (!m_elec.isDC() || !m_apu.isReady())
	{
		if (getRPMNorm() < 0.425)
		{
			m_input.engineStop1();
		}
		if (getRPMNorm2() < 0.425)
		{
			m_input.engineStop2();
		}
		m_apu.unoccupy();
	}
	if ((getRPMNorm() > 0.425 && m_apu.getOccupier() == 1) || (getRPMNorm2() > 0.425 && m_apu.getOccupier() == 2))
	{
		m_apu.unoccupy();
	}
	if (m_input.getLeftThrottleIdle() == 0 && m_rpmNormal > 0.425 && m_input.getEngineStart1() == 1)
	{
		m_input.engineStop1();
	}
	if (m_input.getRightThrottleIdle() == 0 && m_rpmNormal2 > 0.425 && m_input.getEngineStart2() == 1)
	{
		m_input.engineStop2();
	}
	if ((m_rpmNormal < 0.2 || m_fire_temp>0) && m_input.getEngineStart1() > 0.99 && m_input.getLeftThrottleIdle() > 0.99 && m_apu.isRunning())
	{
		m_isFireIgnorEng = true;
	}
	else if (m_rpmNormal < 0.2 && m_input.getEngineStop1() < 0.99 && m_input.getLeftThrottleIdle() < 0.1 && m_tempInC < 100)
	{
		m_isFireIgnorEng = false;
	}
	if ((m_rpmNormal2 < 0.2 || m_fire_temp2>0) && m_input.getEngineStart2() > 0.99 && m_input.getRightThrottleIdle() > 0.99 && m_apu.isRunning())
	{
		m_isFireIgnorEng2 = true;
	}
	else if (m_rpmNormal2 < 0.2 && m_input.getEngineStop2() < 0.99 && m_input.getRightThrottleIdle() < 0.1 && m_tempInC2 < 100)
	{
		m_isFireIgnorEng2 = false;
	}




	//heatCoolDown();

	//printf("Throttle_Position %f \n", m_input.getThrottle());
	/*printf("FuelIndicator %f \n", m_heatTimerUP);
	printf("OHStage %f \n", m_overHeat);
	printf("OverSpeedInd %f \n", m_overSpeedInd);
	printf("Mach %f \n", m_state.m_mach);
	printf("AirDensity %f \n", m_state.m_airDensity);*/

	//-------------NEU eingefügt wegen Replay-Käse--------------
	updateThrust();
	updateThrust2();
	FuelFlowUpdate();
	FuelFlowUpdate2();
	updateSpool();
	updateSpool2();
	updateBurner();
	updateBurner2();
	updateSpoolCold();
	updateSpoolCold2();
	updateSpoolHot();
	updateSpoolHot2();
	tempInC();
	tempInC2();
	overHeat();
	overHeat2();
	overHeatCount();
	overHeatCount2();
	overSpeedInd();
	overSpeedInd2();
	restartNeeded();
	restartNeeded2();
	overHeatInd();
	overHeatInd2();
	updateAnimation(dt);
	updateEngineFireTemp();
}

double Engine::updateThrust() //Wenn Veränderungen dann hier verändern NICHT oben!!!!! //dt in die Klammer eingefügt//double zu void mit double dt verändert
{
	m_force = Vec3(); //braucht man hier vielleicht nicht, trotzdem wieder eingesetzt zum testen
	m_throttle = 0.0; //neu eingefügt
	m_thrust = 0.0; //wieder eingefügt nach auskommentierung
	//m_thrust = 150000; //nur zum testen, wieder rausnehmen

	m_scalarVelocity = magnitude(m_state.m_localAirspeed);
	m_scalarVelocitySquared = m_scalarVelocity * m_scalarVelocity;
	m_state.m_mach = m_scalarVelocity / m_state.m_speedOfSound;

	//corrThrottle = -0.55 * m_input.m_throttle + 1.0; //TESTSETTINGS
	//m_thrust = corrThrottle * PFor(m_state.m_mach); //TESTSETTINGS

	//printf("Throttle %f \n", corrThrottle);

	//printf("CurrentAirDensity %f \n", m_state.m_airDensity);

	//-----------Thrust-function---------------------------------------------------------------------------
	//bei PMax den airdensity-correction-multiplyer eingefügt. Dieser bedarf einer Überarbeitung zusammen mit dem Drag und Thrust-profil...
	//

	if ((updateSpool() <= 0.85) && (m_ignitors1 == true) && (m_hasFuel == true) && (getRPMNorm() >= 0.70))
	{
		m_thrust = (updateSpool() * PMax(m_state.m_mach)) * ((m_state.m_airDensity + (0.66 * m_corrAirDensity)) / CON_sDay_den);
	}
	else if ((updateSpool() > 0.85) && (m_ignitors1 == true) && (m_hasFuel == true) && (getRPMNorm() >= 0.70))
	{
		m_thrust = (updateSpool() * PFor(m_state.m_mach)) * ((m_state.m_airDensity + m_corrAirDensity) / CON_sDay_den);
	}
	else
	{
		m_thrust = 0.0;
	}
	//printf("Thrust %f \n", m_thrust); //eingefügt zum testen, ob M_thrust ausgegeben wird...
	return m_thrust * 0.7;
}

double Engine::updateThrust2() //Wenn Veränderungen dann hier verändern NICHT oben!!!!! //dt in die Klammer eingefügt//double zu void mit double dt verändert
{
	m_force = Vec3(); //braucht man hier vielleicht nicht, trotzdem wieder eingesetzt zum testen
	m_throttle2 = 0.0; //neu eingefügt
	m_thrust2 = 0.0; //wieder eingefügt nach auskommentierung
	//m_thrust = 150000; //nur zum testen, wieder rausnehmen

	m_scalarVelocity = magnitude(m_state.m_localAirspeed);
	m_scalarVelocitySquared = m_scalarVelocity * m_scalarVelocity;
	m_state.m_mach = m_scalarVelocity / m_state.m_speedOfSound;

	//corrThrottle = -0.55 * m_input.m_throttle + 1.0; //TESTSETTINGS
	//m_thrust = corrThrottle * PFor(m_state.m_mach); //TESTSETTINGS

	//printf("Throttle %f \n", corrThrottle);

	//printf("CurrentAirDensity %f \n", m_state.m_airDensity);

	//-----------Thrust-function---------------------------------------------------------------------------
	//bei PMax den airdensity-correction-multiplyer eingefügt. Dieser bedarf einer Überarbeitung zusammen mit dem Drag und Thrust-profil...
	//

	if ((updateSpool2() <= 0.85) && (m_ignitors2 == true) && (m_hasFuel == true) && (getRPMNorm2() >= 0.70))
	{
		m_thrust2 = (updateSpool2() * PMax(m_state.m_mach)) * ((m_state.m_airDensity + (0.66 * m_corrAirDensity)) / CON_sDay_den);
	}
	else if ((updateSpool2() > 0.85) && (m_ignitors2 == true) && (m_hasFuel == true) && (getRPMNorm2() >= 0.70))
	{
		m_thrust2 = (updateSpool2() * PFor(m_state.m_mach)) * ((m_state.m_airDensity + m_corrAirDensity) / CON_sDay_den);
	}
	else
	{
		m_thrust2 = 0.0;
	}
	//printf("Thrust %f \n", m_thrust2); //eingefügt zum testen, ob M_thrust ausgegeben wird...
	return m_thrust2 * 0.7;
}

double Engine::FuelFlowUpdate()
{
	double lowOmegaInertia = 1.0;

	double spoolUpFactor = 0.0;

	if ((getRPMNorm() < 0.70) && (m_ignitors1 == true) && (m_hasFuel == true))
	{
		spoolUpFactor = clamp((updateSpoolCold() - 0.26) * 2, 0, 1);
	}
	else
	{
		spoolUpFactor = 1.0;
	}


	double corrThrottle = 0.0;


	if (m_input.getThrottle() >= 0.0)
	{
		corrThrottle = (1.0 - CON_ThrotIDL) * m_input.getThrottle() + CON_ThrotIDL;
	}
	else
	{
		corrThrottle = (m_input.getThrottle() + 1.0) / 2.0;
	}



	m_deltaSpoolFuel = corrThrottle - m_oldThrottleFuel;
	m_deltaSpoolABSFuel = abs(m_deltaSpoolFuel);
	//m_spoolFactor = EngDel(m_deltaSpoolABS);//die alte Idee mit der Alten "Table"
	int indexInArray = m_deltaSpoolABSFuel / 0.02; //hier wird der Index für den Array aus einer "double" in eine "int" umgemünzt, damit ganze Zahlen generiert werden// kein Factor, damit nicht außerhalb des Arrays verschoben wird
	m_spoolFactorFuel = (DAT_EngSpoolFuel[indexInArray]);//Variale indexInArray ergibt diejenige Zahl die dem Index in dem Array entspricht// /5 hinzugefügt, für langsameres Ansprechen testweise
	m_spoolFactorFuel1 = m_spoolFactorFuel * 10;
	m_newSpoolStepFuel = m_deltaSpoolFuel * m_spoolFactorFuel1;
	m_newThrottleFuel = m_oldThrottleFuel + m_newSpoolStepFuel;

	m_oldThrottleFuel = m_newThrottleFuel; //m_newThrottleFuel ist der Wert anstatt des corrThrottle

	//printf("Throttle %f \n", corrThrottle);
	//printf("NEW_Throttle %f \n", m_newThrottle);


	//-------------------Begin FuelFlow-NEW angelehnt an Leistung kN-----------------------------------

	if ((corrThrottle < 0.01) && (m_ignitors1 == true) && (m_hasFuel == true))
	{
		m_fuelFlow = spoolUpFactor * (1500.0 * (m_state.m_airDensity / CON_sDay_den) + (m_state.m_mach * (0.60 * m_newThrottleFuel * (CON_FuCoMil * PMax(m_state.m_mach) / 1000.0))));
	}

	else if ((corrThrottle >= 0.01) && (corrThrottle < 0.85) && (m_ignitors1 == true) && (m_hasFuel == true))
	{
		m_fuelFlow = spoolUpFactor * ((m_newThrottleFuel * ((CON_FuCoMil * PMax(m_state.m_mach)) / 1000.0) + 1500.0) * (m_state.m_airDensity / CON_sDay_den)); //+ (m_state.m_mach * (0.60 * updateSpool() * CON_CeMax * 3600 * 2.205));
	}
	else if ((corrThrottle >= 0.85) && (m_ignitors1 == true) && (m_hasFuel == true))//&& (nozzleIsStraight == true)
	{
		m_fuelFlow = spoolUpFactor * ((m_newThrottleFuel * ((CON_FuCoAB * PFor(m_state.m_mach)) / 1000.0) + 1500.0) * (m_state.m_airDensity / CON_sDay_den)); // (m_state.m_mach * (0.60 * updateSpool() * CON_CeFor * 3600 * 2.205));
	}
	else
	{
		m_fuelFlow = 0.0;
	}

	return m_fuelFlow;
}

double Engine::FuelFlowUpdate2()
{

	double lowOmegaInertia = 1.0;

	double spoolUpFactor = 0.0;

	if ((getRPMNorm2() < 0.70) && (m_ignitors2 == true) && (m_hasFuel == true))
	{
		spoolUpFactor = updateSpoolCold2();
	}
	else
	{
		spoolUpFactor = 1.0;
	}


	double corrThrottle = 0.0;


	if (m_input.getThrottle2() >= 0.0)
	{
		corrThrottle = (1.0 - CON_ThrotIDL) * m_input.getThrottle2() + CON_ThrotIDL;
	}
	else
	{
		corrThrottle = (m_input.getThrottle2() + 1.0) / 2.0;
	}



	m_deltaSpoolFuel2 = corrThrottle - m_oldThrottleFuel2;
	m_deltaSpoolABSFuel2 = abs(m_deltaSpoolFuel2);
	//m_spoolFactor = EngDel(m_deltaSpoolABS);//die alte Idee mit der Alten "Table"
	int indexInArray = m_deltaSpoolABSFuel2 / 0.02; //hier wird der Index für den Array aus einer "double" in eine "int" umgemünzt, damit ganze Zahlen generiert werden// kein Factor, damit nicht außerhalb des Arrays verschoben wird
	m_spoolFactorFuel2 = (DAT_EngSpoolFuel[indexInArray]);//Variale indexInArray ergibt diejenige Zahl die dem Index in dem Array entspricht// /5 hinzugefügt, für langsameres Ansprechen testweise
	m_spoolFactorFuel2 = m_spoolFactorFuel2 * 10;
	m_newSpoolStepFuel2 = m_deltaSpoolFuel2 * m_spoolFactorFuel2;
	m_newThrottleFuel2 = m_oldThrottleFuel2 + m_newSpoolStepFuel2;

	m_oldThrottleFuel2 = m_newThrottleFuel2; //m_newThrottleFuel ist der Wert anstatt des corrThrottle

	//printf("Throttle %f \n", corrThrottle);
	//printf("NEW_Throttle %f \n", m_newThrottle);


	//-------------------Begin FuelFlow-NEW angelehnt an Leistung kN-----------------------------------

	if ((corrThrottle < 0.01) && (m_ignitors2 == true) && (m_hasFuel == true))
	{
		m_fuelFlow2 = spoolUpFactor * (1500.0 * (m_state.m_airDensity / CON_sDay_den) + (m_state.m_mach * (0.60 * m_newThrottleFuel2 * (CON_FuCoMil * PMax(m_state.m_mach) / 1000.0))));
	}

	else if ((corrThrottle >= 0.01) && (corrThrottle < 0.85) && (m_ignitors2 == true) && (m_hasFuel == true))
	{
		m_fuelFlow2 = spoolUpFactor * ((m_newThrottleFuel2 * ((CON_FuCoMil * PMax(m_state.m_mach)) / 1000.0) + 1500.0) * (m_state.m_airDensity / CON_sDay_den)); //+ (m_state.m_mach * (0.60 * updateSpool() * CON_CeMax * 3600 * 2.205));
	}
	else if ((corrThrottle >= 0.85) && (m_ignitors2 == true) && (m_hasFuel == true))//&&(nozzleIsStraight == true)
	{
		m_fuelFlow2 = spoolUpFactor * ((m_newThrottleFuel2 * ((CON_FuCoAB * PFor(m_state.m_mach)) / 1000.0) + 1500.0) * (m_state.m_airDensity / CON_sDay_den)); // (m_state.m_mach * (0.60 * updateSpool() * CON_CeFor * 3600 * 2.205));
	}
	else
	{
		m_fuelFlow2 = 0.0;
	}

	return m_fuelFlow2;
}

double Engine::updateSpool()
{
	double corrThrottle = 0.0;


	if (m_input.getThrottle() >= 0.0)
	{
		corrThrottle = (1.0 - CON_ThrotIDL) * m_input.getThrottle() + CON_ThrotIDL;
	}
	else
	{
		corrThrottle = (m_input.getThrottle() + 1.0) / 2.0;
	}



	m_deltaSpool = corrThrottle - m_oldThrottle;
	m_deltaSpoolABS = abs(m_deltaSpool);
	//m_spoolFactor = EngDel(m_deltaSpoolABS);//die alte Idee mit der Alten "Table"
	int indexInArray = m_deltaSpoolABS / 0.02; //hier wird der Index für den Array aus einer "double" in eine "int" umgemünzt, damit ganze Zahlen generiert werden// kein Factor, damit nicht außerhalb des Arrays verschoben wird
	m_spoolFactor = (DAT_EngSpool[indexInArray]) / 6.0;//Variale indexInArray ergibt diejenige Zahl die dem Index in dem Array entspricht// /5 hinzugefügt, für langsameres Ansprechen testweise/ jetzt auf 6.0 erhöht
	m_newSpoolStep = m_deltaSpool * m_spoolFactor;
	m_newThrottle = m_oldThrottle + m_newSpoolStep;

	m_oldThrottle = m_newThrottle;

	//printf("Throttle %f \n", corrThrottle);
	//printf("NEW_Throttle %f \n", m_newThrottle);
	return m_newThrottle;

	//double spool[50] = { 1.0000, 0.7817, 0.6753, 0.5834, 0.5040, 0.4354, 0.3762, 0.3250, 0.2808, 0.2425, 0.2095, 0.1810, 0.1564, 0.1351, 0.1167, 0.1008, 0.0871, 0.0753, 0.0650, 0.0562, 0.0485, 0.0419, 0.0362, 0.0313, 0.0270, 0.0234, 0.0202, 0.0174, 0.0151, 0.0130, 0.0112, 0.0097, 0.0084, 0.0072, 0.0063, 0.0054, 0.0047, 0.0040, 0.0035, 0.0030, 0.0026, 0.0022, 0.0019, 0.0017, 0.0014, 0.0013, 0.0011, 0.0009, 0.0008, 0.0007,};// voll aufgefüllt
}

double Engine::updateSpool2()
{
	double corrThrottle = 0.0;


	if (m_input.getThrottle2() >= 0.0)
	{
		corrThrottle = (1.0 - CON_ThrotIDL) * m_input.getThrottle2() + CON_ThrotIDL;
	}
	else
	{
		corrThrottle = (m_input.getThrottle2() + 1.0) / 2.0;
	}



	m_deltaSpool2 = corrThrottle - m_oldThrottle2;
	m_deltaSpoolABS2 = abs(m_deltaSpool2);
	//m_spoolFactor = EngDel(m_deltaSpoolABS);//die alte Idee mit der Alten "Table"
	int indexInArray = m_deltaSpoolABS2 / 0.02; //hier wird der Index für den Array aus einer "double" in eine "int" umgemünzt, damit ganze Zahlen generiert werden// kein Factor, damit nicht außerhalb des Arrays verschoben wird
	m_spoolFactor2 = (DAT_EngSpool[indexInArray]) / 6.0;//Variale indexInArray ergibt diejenige Zahl die dem Index in dem Array entspricht// /5 hinzugefügt, für langsameres Ansprechen testweise/ jetzt auf 6.0 erhöht
	m_newSpoolStep2 = m_deltaSpool2 * m_spoolFactor2;
	m_newThrottle2 = m_oldThrottle2 + m_newSpoolStep2;

	m_oldThrottle2 = m_newThrottle2;

	//printf("Throttle %f \n", corrThrottle);
	//printf("NEW_Throttle %f \n", m_newThrottle);
	return m_newThrottle2;

	//double spool[50] = { 1.0000, 0.7817, 0.6753, 0.5834, 0.5040, 0.4354, 0.3762, 0.3250, 0.2808, 0.2425, 0.2095, 0.1810, 0.1564, 0.1351, 0.1167, 0.1008, 0.0871, 0.0753, 0.0650, 0.0562, 0.0485, 0.0419, 0.0362, 0.0313, 0.0270, 0.0234, 0.0202, 0.0174, 0.0151, 0.0130, 0.0112, 0.0097, 0.0084, 0.0072, 0.0063, 0.0054, 0.0047, 0.0040, 0.0035, 0.0030, 0.0026, 0.0022, 0.0019, 0.0017, 0.0014, 0.0013, 0.0011, 0.0009, 0.0008, 0.0007,};// voll aufgefüllt
}

double Engine::updateSpoolCold()
{
	double spoolColdEnd;
	if (m_input.getLeftThrottleIdle() == 1 && !m_isFireIgnorEng)
	{
		spoolColdEnd = 0.71;
	}
	else
	{
		spoolColdEnd = 0.20;
	}

	m_spoolCDelta = spoolColdEnd - m_spoolCOldSpool;
	m_spoolCDeltaABS = abs(m_spoolCDelta);
	//m_spoolFactor = EngDel(m_deltaSpoolABS);//die alte Idee mit der Alten "Table"
	int indexInArray = m_spoolCDeltaABS / 0.014; //hier wird der Index für den Array aus einer "double" in eine "int" umgemünzt, damit ganze Zahlen generiert werden// kein Factor, damit nicht außerhalb des Arrays verschoben wird
	m_spoolCFactor = (DAT_EngSpool[indexInArray]) / 22;//von /10 auf / 15 hochgesetzt für langsameren Cold-Start//Variable indexInArray ergibt diejenige Zahl die dem Index in dem Array entspricht
	m_spoolCSpoolStep = m_spoolCDelta * m_spoolCFactor;
	m_spoolCNewSpool = m_spoolCOldSpool + m_spoolCSpoolStep + 0.000001;
	m_spoolCOldSpool = m_spoolCNewSpool;

	//printf("Throttle %f \n", corrThrottle);
	//printf("NEW_Throttle %f \n", m_newThrottle);
	return m_spoolCNewSpool;
}

double Engine::updateSpoolCold2()
{
	double spoolColdEnd;
	if (m_input.getRightThrottleIdle() == 1 && !m_isFireIgnorEng2)
	{
		spoolColdEnd = 0.71;
	}
	else
	{
		spoolColdEnd = 0.20;
	}


	m_spoolCDelta2 = spoolColdEnd - m_spoolCOldSpool2;
	m_spoolCDeltaABS2 = abs(m_spoolCDelta2);
	//m_spoolFactor = EngDel(m_deltaSpoolABS);//die alte Idee mit der Alten "Table"
	int indexInArray = m_spoolCDeltaABS2 / 0.014; //hier wird der Index für den Array aus einer "double" in eine "int" umgemünzt, damit ganze Zahlen generiert werden// kein Factor, damit nicht außerhalb des Arrays verschoben wird
	m_spoolCFactor2 = (DAT_EngSpool[indexInArray]) / 22;//von /10 auf / 15 hochgesetzt für langsameren Cold-Start//Variable indexInArray ergibt diejenige Zahl die dem Index in dem Array entspricht
	m_spoolCSpoolStep2 = m_spoolCDelta2 * m_spoolCFactor2;
	m_spoolCNewSpool2 = m_spoolCOldSpool2 + m_spoolCSpoolStep2 + 0.000001;
	m_spoolCOldSpool2 = m_spoolCNewSpool2;

	//printf("Throttle %f \n", corrThrottle);
	//printf("NEW_Throttle %f \n", m_newThrottle);
	return m_spoolCNewSpool2;
}

double Engine::updateSpoolHot()
{
	double SpoolHotEnd = -0.1;


	m_spoolHDelta = SpoolHotEnd - m_spoolHOldSpool;
	m_spoolHDeltaABS = abs(m_spoolHDelta);
	//m_spoolFactor = EngDel(m_deltaSpoolABS);//die alte Idee mit der Alten "Table"
	int indexInArray = m_spoolHDeltaABS / 0.022; //hier wird der Index für den Array aus einer "double" in eine "int" umgemünzt, damit ganze Zahlen generiert werden// kein Factor, damit nicht außerhalb des Arrays verschoben wird
	m_spoolHFactor = (DAT_HtoCspool[indexInArray]) / 120.0;//Variale indexInArray ergibt diejenige Zahl die dem Index in dem Array entspricht
	m_spoolHSpoolStep = (m_spoolHDelta * m_spoolHFactor) - 0.000004;
	m_spoolHNewSpool = m_spoolHOldSpool + m_spoolHSpoolStep;
	m_spoolHOldSpool = m_spoolHNewSpool;
	//printf("Throttle %f \n", corrThrottle);
	//printf("NEW_Throttle %f \n", m_newThrottle);
	return m_spoolHNewSpool;
}

double Engine::updateSpoolHot2()
{
	double SpoolHotEnd = -0.1;


	m_spoolHDelta2 = SpoolHotEnd - m_spoolHOldSpool2;
	m_spoolHDeltaABS2 = abs(m_spoolHDelta2);
	//m_spoolFactor = EngDel(m_deltaSpoolABS);//die alte Idee mit der Alten "Table"
	int indexInArray = m_spoolHDeltaABS2 / 0.022; //hier wird der Index für den Array aus einer "double" in eine "int" umgemünzt, damit ganze Zahlen generiert werden// kein Factor, damit nicht außerhalb des Arrays verschoben wird
	m_spoolHFactor2 = (DAT_HtoCspool[indexInArray]) / 120.0;//Variale indexInArray ergibt diejenige Zahl die dem Index in dem Array entspricht
	m_spoolHSpoolStep2 = (m_spoolHDelta2 * m_spoolHFactor2) - 0.000004;
	m_spoolHNewSpool2 = m_spoolHOldSpool2 + m_spoolHSpoolStep2;
	m_spoolHOldSpool2 = m_spoolHNewSpool2;

	//printf("Throttle %f \n", corrThrottle);
	//printf("NEW_Throttle %f \n", m_newThrottle);


	return m_spoolHNewSpool2;
}

double Engine::updateBurner()
{
	m_burner = 0.0;

	//------------------Alte Burner-Funktion die funktioniert----------------
	/*double corrThrottle = 0.0;

	if (m_input.m_throttle >= 0.0)
	{
		corrThrottle = ((1 - CON_ThrotIDL) * m_input.m_throttle + CON_ThrotIDL);
	}
	else
	{
		corrThrottle = ((m_input.m_throttle + 1.0) / 2.0);
	}*/

	if ((updateSpool() >= 0.85) && (m_ignitors1 == true) && (m_hasFuel == true))
	{
		m_burner = 1.0;
	}
	else
	{
		m_burner = 0.0;
	}
	return m_burner;
}

double Engine::updateBurner2()
{
	m_burner2 = 0.0;
	//------------------Alte Burner-Funktion die funktioniert----------------
	/*double corrThrottle = 0.0;

	if (m_input.m_throttle >= 0.0)
	{
		corrThrottle = ((1 - CON_ThrotIDL) * m_input.m_throttle + CON_ThrotIDL);
	}
	else
	{
		corrThrottle = ((m_input.m_throttle + 1.0) / 2.0);
	}*/

	if ((updateSpool2() >= 0.85) && (m_ignitors2 == true) && (m_hasFuel == true))
	{
		m_burner2 = 1.0;
	}
	else
	{
		m_burner2 = 0.0;
	}
	return m_burner2;
}

double Engine::tempInC()
{
	m_tempInC = 0.0;

	if (getRPMNorm() > 0.26)
	{
		m_tempInC = (450 * ((getRPMNorm() - 0.26) / 0.74)) * overHeatCount();
	}
	else
	{
		m_tempInC = 0.0;
	}
	if (m_spec_ab && m_thrust > 0)
	{
		m_spec_tmp = clamp(m_spec_tmp + 0.05, 0, 9999);
	}
	else
	{
		m_spec_tmp = clamp(m_spec_tmp - 0.02, 0, 9999);
	}
	return m_tempInC + m_spec_tmp + m_fire_temp;
}

double Engine::tempInC2()
{
	m_tempInC2 = 0.0;

	if (getRPMNorm2() > 0.26)
	{
		m_tempInC2 = (450 * ((getRPMNorm2() - 0.26) / 0.74)) * overHeatCount2();
	}
	else
	{
		m_tempInC2 = 0.0;
	}
	if (m_spec_ab && m_thrust2 > 0)
	{
		m_spec_tmp2 = clamp(m_spec_tmp2 + 0.05, 0, 9999);
	}
	else
	{
		m_spec_tmp2 = clamp(m_spec_tmp2 - 0.02, 0, 9999);
	}
	return m_tempInC2 + m_spec_tmp2 + m_fire_temp2;
}

double Engine::overHeatCount()
{
	//Overheating of the engine due to overspeed
	bool CounterGo = false;
	bool CounterBack = false;

	//Heat-Counter auskommentiert, da Heat-Failure für F-35 aktuell unbekannt ;-)
	/*
	if ((((m_state.m_mach > 1.17) && (m_state.m_mach <= 1.25)) && (m_state.m_airDensity > 1.112)) || (((m_state.m_mach > 1.40) && (m_state.m_mach <= 1.55)) && ((m_state.m_airDensity > 0.9093) && (m_state.m_airDensity <= 1.112))) || (((m_state.m_mach > 1.70) && (m_state.m_mach <= 1.9)) && ((m_state.m_airDensity > 0.6601) && (m_state.m_airDensity < 0.9093))) || (((m_state.m_mach > 2.2) && (m_state.m_mach <= 2.3)) && (m_state.m_airDensity < 0.6601)))
	{
		m_heatOne = 0.00001;
		CounterGo = true;
	}
	else if (((m_state.m_mach > 1.25) && (m_state.m_airDensity > 1.112)) || ((m_state.m_mach > 1.55) && ((m_state.m_airDensity > 0.9093) && (m_state.m_airDensity <= 1.112))) || ((m_state.m_mach > 1.90) && ((m_state.m_airDensity > 0.6601) && (m_state.m_airDensity < 0.9093))) || ((m_state.m_mach > 2.3) && (m_state.m_airDensity < 0.6601)))
	{
		m_heatOne = 0.00005;
		CounterGo = true;
	}
	else if ((m_state.m_mach < 1.0) && (m_heatTimerUP > 1) && (m_heatFailure == false))
	{
		CounterBack = true;
	}

	if (CounterGo == true)
	{
		m_heatTimerUP++;
	}
	else if ((CounterBack == true) && (CounterGo == false) && (m_heatTimerUP > m_heatTimerDOWN))
	{
		m_heatTimerDOWN++;
	}

	m_heatTwo = (m_heatOne * (m_heatTimerUP - m_heatTimerDOWN)) + 1.0;
	*/
	m_heatTwo = 1.0;
	return m_heatTwo;
}

double Engine::overHeatCount2()
{
	//Overheating of the engine due to overspeed
	bool CounterGo = false;
	bool CounterBack = false;

	//Heat-Counter auskommentiert, da Heat-Failure für F-35 aktuell unbekannt ;-)
	/*
	if ((((m_state.m_mach > 1.17) && (m_state.m_mach <= 1.25)) && (m_state.m_airDensity > 1.112)) || (((m_state.m_mach > 1.40) && (m_state.m_mach <= 1.55)) && ((m_state.m_airDensity > 0.9093) && (m_state.m_airDensity <= 1.112))) || (((m_state.m_mach > 1.70) && (m_state.m_mach <= 1.9)) && ((m_state.m_airDensity > 0.6601) && (m_state.m_airDensity < 0.9093))) || (((m_state.m_mach > 2.2) && (m_state.m_mach <= 2.3)) && (m_state.m_airDensity < 0.6601)))
	{
		m_heatOne = 0.00001;
		CounterGo = true;
	}
	else if (((m_state.m_mach > 1.25) && (m_state.m_airDensity > 1.112)) || ((m_state.m_mach > 1.55) && ((m_state.m_airDensity > 0.9093) && (m_state.m_airDensity <= 1.112))) || ((m_state.m_mach > 1.90) && ((m_state.m_airDensity > 0.6601) && (m_state.m_airDensity < 0.9093))) || ((m_state.m_mach > 2.3) && (m_state.m_airDensity < 0.6601)))
	{
		m_heatOne = 0.00005;
		CounterGo = true;
	}
	else if ((m_state.m_mach < 1.0) && (m_heatTimerUP > 1) && (m_heatFailure == false))
	{
		CounterBack = true;
	}

	if (CounterGo == true)
	{
		m_heatTimerUP++;
	}
	else if ((CounterBack == true) && (CounterGo == false) && (m_heatTimerUP > m_heatTimerDOWN))
	{
		m_heatTimerDOWN++;
	}

	m_heatTwo = (m_heatOne * (m_heatTimerUP - m_heatTimerDOWN)) + 1.0;
	*/
	m_heatTwo2 = 1.0;
	return m_heatTwo2;
}

double Engine::overHeat()
{
	if ((tempInC() > 1045.0) && (tempInC() <= 1250.0))
	{
		m_overHeat = 0.5;
	}
	else if ((tempInC() > 1250.0) && (tempInC() <= 1350.0))
	{
		m_overHeat = 0.75;
	}
	else if (tempInC() > 1350.0)
	{
		m_overHeat = 1.0;
		m_heatFailure = true;
	}
	else if (((m_heatFailure == true) || (m_needRepair == true)) && (m_input.getEngineStart1() == 1.0))
	{
		//m_input.m_engine_start = 2.0;
		//m_input.m_engine_stop = 2.0;
		m_needRestart = true;
	}
	else
	{
		m_overHeat = 0.0;
	}

	return m_overHeat;
}


double Engine::overHeat2()
{
	if ((tempInC2() > 1045.0) && (tempInC2() <= 1250.0))
	{
		m_overHeat2 = 0.5;
	}
	else if ((tempInC2() > 1250.0) && (tempInC2() <= 1350.0))
	{
		m_overHeat2 = 0.75;
	}
	else if (tempInC2() > 1350.0)
	{
		m_overHeat2 = 1.0;
		//m_input.m_engine_start = 0.0;
		//m_input.m_engine_stop = 0.0;
		m_heatFailure2 = true;
	}
	else if (((m_heatFailure2 == true) || (m_needRepair2 == true)) && (m_input.getEngineStart1() == 1.0))
	{
		//m_input.m_engine_start = 2.0;
		//m_input.m_engine_stop = 2.0;
		m_needRestart2 = true;
	}
	else
	{
		m_overHeat2 = 0.0;
	}

	return m_overHeat2;
}

double Engine::overHeatInd()
{
	if (m_elec.isDC())
	{
		if ((overHeat() >= 0.75) || (m_heatFailure == true))
		{
			m_overHeatInd = 1.0;
		}
		else
		{
			m_overHeatInd = 0.0;
		}
	}
	else
	{
		m_overHeatInd = 0.0;
	}
	return m_overHeatInd;
}

double Engine::overHeatInd2()
{
	if (m_elec.isDC())
	{
		if ((overHeat2() >= 0.75) || (m_heatFailure2 == true))
		{
			m_overHeatInd2 = 1.0;
		}
		else
		{
			m_overHeatInd2 = 0.0;
		}
	}
	else
	{
		m_overHeatInd2 = 0.0;
	}
	return m_overHeatInd2;
}

double Engine::overSpeedInd()
{
	if (m_elec.isDC())
	{
		if (((m_state.m_mach > 1.114) && (m_state.m_airDensity > 1.112)) || ((m_state.m_mach > 1.25) && ((m_state.m_airDensity > 0.9093) && (m_state.m_airDensity <= 1.112))) || ((m_state.m_mach > 1.60) && ((m_state.m_airDensity > 0.6601) && (m_state.m_airDensity < 0.9093))) || ((m_state.m_mach > 2.2) && (m_state.m_airDensity < 0.6601)))
		{
			m_overSpeedInd = 1.0;
		}
		else
		{
			m_overSpeedInd = 0.0;
		}
	}
	else
	{
		m_overSpeedInd = 0.0;
	}

	return m_overSpeedInd;
}
double Engine::overSpeedInd2()
{
	if (m_elec.isDC())
	{
		if (((m_state.m_mach > 1.114) && (m_state.m_airDensity > 1.112)) || ((m_state.m_mach > 1.25) && ((m_state.m_airDensity > 0.9093) && (m_state.m_airDensity <= 1.112))) || ((m_state.m_mach > 1.60) && ((m_state.m_airDensity > 0.6601) && (m_state.m_airDensity < 0.9093))) || ((m_state.m_mach > 2.2) && (m_state.m_airDensity < 0.6601)))
		{
			m_overSpeedInd2 = 1.0;
		}
		else
		{
			m_overSpeedInd2 = 0.0;
		}
	}
	else
	{
		m_overSpeedInd2 = 0.0;
	}

	return m_overSpeedInd2;
}

//-----------------Repair and REset damages due to overheat or overspeed--------------------------------

void Engine::repairHeatDamage()
{
	m_overHeat = 0.0;
	m_overHeatInd = 0.0;
	//m_input.m_engine_start = 0.0;
	//m_input.m_engine_stop = 0.0;
	m_heatFailure = false;
	m_needRepair = false;
	m_heatTimerDOWN = 0;
	m_heatTimerUP = 0;

}

void Engine::repairHeatDamage2()
{
	m_overHeat2 = 0.0;
	m_overHeatInd2 = 0.0;
	//m_input.m_engine_start = 0.0;
	//m_input.m_engine_stop = 0.0;
	m_heatFailure2 = false;
	m_needRepair2 = false;
	m_heatTimerDOWN2 = 0;
	m_heatTimerUP2 = 0;

}

void Engine::restartNeeded()
{
	if ((m_input.getEngineStart1() == 0.0) && (m_heatFailure == false) && (m_needRepair == false) && (m_needRestart == true))
	{
		m_needRestart = false;
	}
}

void Engine::restartNeeded2()
{
	if ((m_input.getEngineStart2() == 0.0) && (m_heatFailure2 == false) && (m_needRepair2 == false) && (m_needRestart2 == true))
	{
		m_needRestart2 = false;
	}
}

void Engine::updateAnimation(double dt)
{

	updateFanAnimation(dt);
}

void Engine::updateFanAnimation(double dt)
{
	m_fan_l = m_fan_l + dt * m_rpmNormal * 100;
	m_fan_r = m_fan_r + dt * m_rpmNormal2 * 100;
	if (m_rpmNormal < 0.3)
	{
		if (m_fan_l > 0)
		{
			m_fan_l = fmod(m_fan_l, 1) - 1;
		}
	}
	else
	{
		if (m_fan_l > 1)
		{
			m_fan_l = fmod(m_fan_l, 1);
		}
	}
	if (m_rpmNormal2 < 0.3)
	{
		if (m_fan_r > 0)
		{
			m_fan_r = fmod(m_fan_r, 1) - 1;
		}
	}
	else
	{
		if (m_fan_r > 1)
		{
			m_fan_r = fmod(m_fan_r, 1);
		}
	}
}
double Engine::getLeftFanAnimationValue()
{
	return m_fan_l;
}
double Engine::getRightFanAnimationValue()
{
	return m_fan_r;
}


