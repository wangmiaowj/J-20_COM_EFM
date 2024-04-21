#include "Airframe.h"
#include <algorithm>
#include <random>
#include <cstdlib>
#include <ctime>
#include <chrono>

//=========================================================================//
//
//		FILE NAME	: Airframe.cpp
//		AUTHOR		: Joshua Nelson & A4-Comunity-Team & Paul Stich
//		Copyright	: Joshua Nelson & A4-Comunity-Team & Paul Stich
//		DATE		: August 2021
//
//		DESCRIPTION	: All moving parts, gauges, indicators, stick and throttle 
//					  and external animations that are driven from within the EFM.
//					  AND internal damage modell.
//================================ Includes ===============================//
//=========================================================================//

//-----------Neu eingef黦t wegen Chrono und Millisekunden---------
using std::chrono::duration_cast;
using std::chrono::milliseconds;
using std::chrono::seconds;
using std::chrono::system_clock;
//-----------------------------------------------------------------

Airframe::Airframe
(
	State& state,
	Input& input,
	Engine& engine,
	avSimpleElectricSystem& elec,
	EDPARAM& edParam

) :
	m_state(state),
	m_input(input),
	m_engine(engine),
	m_elec(elec),
	m_cockpitAPI(edParam),
	m_actuatorFlap(0.9),
	m_actuatorLeFlap(1.7),
	m_actuatorAirbrk(1.2),
	m_actuatorAirbrkCanard(1.2),
	m_actuatorGearL(0.2),
	m_actuatorGearN(0.2),
	m_actuatorGearR(0.2),
	m_actuatorHook(0.6),
	m_actuatorLaunchBar(0.6),
	m_actuatorNozzle(1.1),
	m_actuatorNosewheel(2.0),
	m_actuatorChuteY(3.0),
	m_actuatorChuteZ(3.0),
	m_actuatorWingFold(0.15),
	m_actuatorRefuelingDoor(0.9),
	m_actuatorTiltNozzle(0.4),
	m_actuatorRotorTopClap(0.05),
	m_actuatorRotorBottomClap(0.3),
	m_actuatorWingNozzles(0.2),
	m_actuatorBayDoors(0.7),
	m_wheelChockHandle(edParam.getParamHandle("WHEEL_CHOCK_STATUS")),

	APascend(DAT_APascendAngle, CON_APascendAngle_min, CON_APascendAngle_max)

{
	m_integrityElement = new float[(int)Damage::COUNT];
	zeroInit();
	params[MAIN_GEAR_POS] = EdParam(m_cockpitAPI.getParamHandle("MAIN_GEAR_POS"), 0.0);
	params[NOSE_GEAR_POS] = EdParam(m_cockpitAPI.getParamHandle("NOSE_GEAR_POS"), 0.0);
	params[HUD_GEAR] = EdParam(m_cockpitAPI.getParamHandle("HUD_GEAR"), "");
	params[HUD_FLAP] = EdParam(m_cockpitAPI.getParamHandle("HUD_FLAP"), "");
	params[HUD_BRAKE] = EdParam(m_cockpitAPI.getParamHandle("HUD_BRAKE"), "");
	params[HUD_CHUTE] = EdParam(m_cockpitAPI.getParamHandle("HUD_CHUTE"), "");
	params[VS_VIS] = EdParam(m_cockpitAPI.getParamHandle("VS_VIS"), 0.0);
	params[leftThrottle] = EdParam(m_cockpitAPI.getParamHandle("LeftThrottor"), 0.0);
	params[rightThrottle] = EdParam(m_cockpitAPI.getParamHandle("RightThrottor"), 0.0);
	params[ROD_LB_POS] = EdParam(m_cockpitAPI.getParamHandle("ROD_LB_POS"), 0.0);
	params[ROD_RB_POS] = EdParam(m_cockpitAPI.getParamHandle("ROD_RB_POS"), 0.0);
	params[ENG_DIRECTION] = EdParam(m_cockpitAPI.getParamHandle("ENG_DIRECTION"), 0.0);
	params[ENG_THRUST_SPORT] = EdParam(m_cockpitAPI.getParamHandle("ENG_THRUST_SPORT"), 0.0);
	m_damageStack.reserve(10);
}

Airframe::~Airframe()
{
	delete[] m_integrityElement;
	m_integrityElement = nullptr;
}

void Airframe::printDamageState()
{
	printf("===========================================\n");

	printf("            ||\n");
	printf("            ||\n");
	printf("%.1lf %.1lf %.1lf || %.1lf %.1lf %.1lf\n",
		DMG_ELEM(Damage::WING_L_OUT),
		DMG_ELEM(Damage::WING_L_CENTER),
		DMG_ELEM(Damage::WING_L_IN),
		DMG_ELEM(Damage::WING_R_IN),
		DMG_ELEM(Damage::WING_R_CENTER),
		DMG_ELEM(Damage::WING_R_OUT));

	printf("        %.1f || %.1f\n", DMG_ELEM(Damage::AILERON_L), DMG_ELEM(Damage::AILERON_R));
	printf("            ||\n");
	printf("        %.1f || %.1f\n", DMG_ELEM(Damage::STABILIZATOR_L), DMG_ELEM(Damage::STABILIZATOR_R));
	printf("        %.1f || %.1f\n", DMG_ELEM(Damage::ELEVATOR_L), DMG_ELEM(Damage::ELEVATOR_R));
	printf("            %.1f\n", getVertStabDamage());
	printf("            %.1f\n", getRudderDamage());
}

void Airframe::resetDamage()
{
	for (int i = 0; i < (int)Damage::COUNT; i++)
	{
		m_integrityElement[i] = 1.0f;
	}
}

void Airframe::zeroInit()
{
	//----------Weight-On-Wheels Sensor-------------
	m_weightOnWheels = 0.0;

	//---Gear position--------
	m_gearLPosition = 0.0;
	m_gearRPosition = 0.0;
	m_gearNPosition = 0.0;

	m_gearFLamp = 0.0;
	m_gearLLamp = 0.0;
	m_gearRLamp = 0.0;

	m_instLightOn = 0.0;

	m_gunSwitch = 0.0;

	m_gearStart = 0.0;

	m_gearOversped = 0.0;
	m_flapOversped = 0.0;

	m_flapOSind = 0.0;
	m_gearOSind = 0.0;

	//------aerodynamic surfaces-------
	m_flapsPosition = 0.0;
	m_leFlapsPosition = 0.0;
	m_autoDriveLeFlaps = 0.0;
	m_speedBrakePosition = 0.0;
	m_speedCanardBrakePosition = 0.0;

	m_brakeLeft = 0.0;
	m_brakeRight = 0.0;
	m_brakeMoment = 0.0;

	m_vMetEAS = 0.0;
	m_vKnotsEAS = 0.0;
	m_vKnotsCAS = 0.0;
	m_vMach = 0.0;
	m_altInM = 0;
	m_altInFt = 0;

	m_qnhVar = 101320;//NEU statt 101325.0 grds. der "Start-Luftdruck" auf Bodenh鰄e
	m_indQnhThousand = 0.0;
	m_indQnhHundred = 0.0;
	m_indQnhTen = 0.0;
	m_indQnhOne = 0.0;
	m_retIndQnhHundred = 0.0;

	m_aileronLeft = 0.0;
	m_aileronRight = 0.0;
	m_stabilizer = 0.0;
	m_rudder = 0.0;

	m_ailDef = 0.0;
	m_rudDef = 0.0;

	m_hookPosition = 0.0;

	m_foldWingMechanic = 0.0;

	m_refuelingDoorToggle = 0.0;
	m_bayDoorToggle = 0.0;

	m_noseWheelAngle = 0.0;

	resetDamage();

	//----------Nozzle Stuff-------
	m_nozzlePosition = 0.0;
	m_nozzle2Position = 0.0;
	m_nozzleTilt = 0.0;
	m_nozzleTiltPosition = 0.0;
	m_tiltNozzleOverSpeed = 0.0;

	m_rotorTopClap = 0.0;
	m_rotorTopClapPosition = 0.0;
	m_rotorBottomClap = 0.0;
	m_rotorBottomClapPosition = 0.0;
	m_wingNozzle = 0.0;
	m_wingNozzlePosition = 0.0;
	//-----------------------------

	m_int_throttlePos = 0.0;

	m_hasACpower = 0.0;
	m_hasDCpower = 0.0;
	m_hasBATpower = 0.0;
	m_batTimer = 0.0;


	//set to "0" after each init
	//m_input.m_brake = 0.0; geht nicht, da jetzt funktion

	//m_chuteSlewingZ = false;
	//m_chuteSlewingY = false;//Neu eingef黦t zum Testen f黵 Chute return 0.0;
	//m_chuteTimeZPassed = 0;
	//m_chuteTimeYPassed = 0;

	m_nwsEngage = 0.0;
	m_chuteState = 0.0;
	m_chuteDeployed = false;
	m_mass = 1.0;

	m_damageStack.clear();

	m_timePassed = 0;

	m_engDmgMulti = 1.0;


	m_desiredAlt = 0.0;
	m_previousAlt = 0.0;
	m_autPilAltEng = 0.0;
	m_altHold = 0.0;
	m_ascHA = 0.0;
	m_decHA = 0.0;
	m_decend = false;
	m_acend = false;
	m_level = false;
	m_acendHoldAngle = false;
	m_decendHoldAngle = false;

	m_flapsLevPos = 0.0;

	/*m_elevUP = 0.0;
	m_elevDOWN = 0.0;
	m_ailRIGHT = 0.0;
	m_ailLEFT = 0.0;
	m_rudRIGHT = 0.0;
	m_rudLEFT = 0.0;

	m_keyPitch = 0.0;
	m_keyRoll = 0.0;
	m_keyYaw = 0.0;

	m_finalPitch = 0.0;
	m_finalRoll = 0.0;
	m_finalYaw = 0.0;*/

	m_scalarVelocity = 0.0;

	m_chuteYAxis = 0.0;
	m_chuteZAxis = 0.0;

	//----------Catapult Variables---------------

	m_catapultState = CatapultState::OFF_CAT;
	m_catStateSent = false;
	m_catMoment = 0.0;
	m_prevAccel = 0.0;
	m_catAngle = 0.0;
	m_catMomentVelocity = 0.0;
	m_launchBar = 0.0;

	//-----------CrossHair Test Stuff------------
	/*m_crossHairHori = 0.0;
	m_crossHairVerti = 0.46;

	m_vertAccPrevY = 0.0;
	m_vertAccdotY = 0.0;
	m_vertAccPrevZ = 0.0;
	m_vertAccdotZ = 0.0;

	m_CHforceVerticalDPure = 0.0;
	m_CHforceVerticalDSmooth = 0.0;
	m_CHforceHori = 0.0;

	m_smoothingValue = 0.0;
	m_smoothingValue2 = 0.0;
	m_smoothingFactor = 0.0;
	m_firstCallV = true;

	m_radiusV = 0.0;
	m_radiusH = 0.0;
	m_defAngleVCOS = 0.0;
	m_defAngleV = 0.0;
	m_defAngleHCOS = 0.0;
	m_defAngleH = 0.0;
	m_angleIndNen = 0.0;
	m_thetaV = 0.0;
	m_thetaH = 0.0;
	m_omegaV = 0.0;
	m_omegaH = 0.0;
	m_targetDist = 600.0;
	m_bulletSpeed = 1050.0;
	m_defAngleVCNen = 0.1;
	m_centriPetalV = 0.0;

	m_moveSightH = 0.0;
	m_moveSightV = 0.0;
	*/

	m_actuatorFlap.revOverSpeedMalFunction();
	m_actuatorGearL.revOverSpeedMalFunction();
	m_actuatorGearN.revOverSpeedMalFunction();
	m_actuatorGearR.revOverSpeedMalFunction();
}

void Airframe::coldInit()
{
	zeroInit();

	//--Ground Init SET Actuator---------
	m_actuatorGearL.groundInit(1.0, 1.0);
	m_actuatorGearN.groundInit(1.0, 1.0);
	m_actuatorGearR.groundInit(1.0, 1.0);

	m_actuatorWingFold.groundInit(1.0, 1.0);
	//---Gear position--------
	m_gearLPosition = 0.0;
	m_gearRPosition = 0.0;
	m_gearNPosition = 0.0;

	//-----gear position for ground start
	m_gearStart = 0.0;
	//m_actuatorGearL = 0.0;
	//m_actuatorGearN = 0.0;
	//m_actuatorGearR = 0.0;
	//m_input.m_gear_toggle = 1.0; auskommentiert weil nicht zeroable da jetzt funktion
	//------aerodynamic surfaces-------
	m_flapsPosition = 0.0;
	m_speedBrakePosition = 0.0;
	m_speedCanardBrakePosition = 1.0;

	m_aileronLeft = 0.0;
	m_aileronRight = 0.0;
	m_stabilizer = 0.0;
	m_rudder = 0.0;

	m_hookPosition = 0.0;
	m_foldWingMechanic = 1.0;

	m_noseWheelAngle = 0.0;

	m_nozzlePosition = 0.0;
	m_nozzle2Position = 0.0;
	m_int_throttlePos = 0.0;

	//m_input.m_brake = 0.0; geht nicht, da jetzt funktion

	m_nwsEngage = 0.0;
	m_chuteState = 0.0;
	m_mass = 1.0;
	m_timePassed = 0;
}

void Airframe::hotInit()
{
	zeroInit();

	//--Ground Init SET Actuator---------
	m_actuatorGearL.groundInit(1.0, 1.0);
	m_actuatorGearN.groundInit(1.0, 1.0);
	m_actuatorGearR.groundInit(1.0, 1.0);
	//---Gear position--------
	m_gearLPosition = 0.0;
	m_gearRPosition = 0.0;
	m_gearNPosition = 0.0;

	//---Gear position for ground start----------
	m_gearStart = 0.0;
	//m_actuatorGearL = 0.0;
	//m_actuatorGearN = 0.0;
	//m_actuatorGearR = 0.0;
	//m_input.m_gear_toggle = 1.0; nicht mehr setzbar, da jetzt funktion

	//------aerodynamic surfaces-------
	m_flapsPosition = 0.0;
	m_speedBrakePosition = 0.0;
	m_speedCanardBrakePosition = 0.0;

	m_aileronLeft = 0.0;
	m_aileronRight = 0.0;
	m_stabilizer = 0.0;
	m_rudder = 0.0;

	m_hookPosition = 0.0;
	m_foldWingMechanic = 0.0;

	m_noseWheelAngle = 0.0;

	m_nozzlePosition = 0.0;
	m_nozzle2Position = 0.0;
	m_int_throttlePos = 0.0;
	m_int_throttlePos2 = 0.0;

	m_hasACpower = 1.0;
	m_hasDCpower = 1.0;
	m_hasBATpower = 0.0;

	//m_input.m_brake = 0.0; geht nicht, da jetzt funktion

	m_nwsEngage = 0.0;
	m_chuteState = 0.0;
	m_mass = 1.0;
	m_timePassed = 0;
}

void Airframe::airborneInit()
{
	zeroInit();
	m_hasACpower = 1.0;
	m_hasDCpower = 1.0;
	m_hasBATpower = 0.0;

}

void Airframe::airframeUpdate(double dt)
{
	//printf( "I %lf, L %lf, C %lf, R %lf\n", m_fuel[0], m_fuel[1], m_fuel[2], m_fuel[3] );

	//printf("LEFT: %lf, CENTRE: %lf, RIGHT: %lf, INTERNAL: %lf\n", m_fuel[Tank::LEFT_EXT], m_fuel[Tank::CENTRE_EXT], m_fuel[Tank::RIGHT_EXT], m_fuel[Tank::INTERNAL]);
	//m_engine_L.setHasFuel(m_fuel[Tank::INTERNAL] > 20.0);

	//printf( "Compressor Damage %lf, Turbine Damage: %lf\n", getCompressorDamage(), getTurbineDamage() );

	//m_engine_L.setIntegrity(DMG_ELEM(Damage::ENGINE)); NOCH einf黦en in der engine-class

	aeroSurfaceMulti(dt);//NEU

	m_stabilizer = setStabilizer(dt);
	m_aileronLeft = setAileron(dt);
	m_aileronRight = -m_aileronLeft;
	m_rudder = setRudder(dt);

	m_flapsPosition = setFlapsPosition(dt);
	m_leFlapsPosition = setLEFlapsPosition(dt);

	m_speedBrakePosition = setAirbrakePosition(dt);
	m_speedCanardBrakePosition = setCanardAirbrakePosition(dt);

	m_gearLPosition = setGearLPosition(dt);
	m_gearRPosition = setGearRPosition(dt);
	m_gearNPosition = setGearNPosition(dt);


	m_hookPosition = setHookPosition(dt);
	m_launchBar_pos = setLaunchBarPosition(dt);

	m_chuteYAxis = setChutePositionY(dt);
	m_chuteZAxis = setChutePositionZ(dt);

	m_nozzlePosition = setNozzlePosition(dt);
	m_nozzle2Position = setNozzle2Position(dt);

	m_noseWheelAngle = setNoseWheelAngle(dt);

	m_foldWingMechanic = setWingFoldMechanic(dt);

	m_refuelingDoorToggle = setRefuelingDoor(dt);

	m_nozzleTilt = setTiltEngineNozzlePosition(dt);
	m_rotorTopClap = setTopRotorClap(dt);
	m_rotorBottomClap = setBottomRotorClap(dt);
	m_wingNozzle = setWingNozzles(dt);

	m_bayDoorToggle = setBayDoorsPosition(dt);




	//printf("BayDoor Value %f\n", m_bayDoorToggle);
	//printf("GunSwitchValue %f \n", m_gunSwitch);

	//---------Engine flame-out function Engine 1------------------

	if (((getCompressorDamage() < 0.15) || (getTurbineDamage() < 0.15)) && (m_input.getEngineStart1() == 1))
	{
		m_engine.m_needRepair = true;
		m_engine.m_needRestart = true;
	}
	/*else if (((getCompressorDamage() < 0.15) || (getTurbineDamage() < 0.15)) && (m_input.m_engine_start == 0) && (m_input.m_engine_stop == 0))
	{
		m_input.m_engine_stop = 2.0;
		m_input.m_engine_start = 2.0;
	}*/
	else if ((getCompressorDamage() >= 0.65) && (getTurbineDamage() >= 0.65) && (m_engine.m_needRestart == false))
	{
		m_engine.m_needRepair = false;
	}
	if (((getCompressorDamageR() < 0.15) || (getTurbineDamageR() < 0.15)) && (m_input.getEngineStart2() == 1))
	{
		m_engine.m_needRepair2 = true;
		m_engine.m_needRestart2 = true;
	}
	/*else if (((getCompressorDamage() < 0.15) || (getTurbineDamage() < 0.15)) && (m_input.m_engine_start == 0) && (m_input.m_engine_stop == 0))
	{
		m_input.m_engine_stop = 2.0;
		m_input.m_engine_start = 2.0;
	}*/
	else if ((getCompressorDamageR() >= 0.65) && (getTurbineDamageR() >= 0.65) && (m_engine.m_needRestart2 == false))
	{
		m_engine.m_needRepair2 = false;
	}



	//------------------AutoPilot-Update------------------
	autoPilotAltH(dt);

	//printf("FuelIndicator %f \n", m_fuelThousand);

//----------Brake update---------------(NEU ggf. 黚erfl黶sig)
	//updateBrake();



//----Alle folgenden NEU eingefpgt und von () zu (doubel dt) ge鋘dert!!!
	//brkChutePosition();
	//brkChuteSlewY();
	//brkChuteSlewZ();

	//BLCsystem();
	getEngineDamageMult();

	//----SpeedIndicator-Functions------------
	osGearDamage();
	osFlapDamage();

	catapultCalculations(dt);
	launchBarCalc();
	autoDriveLeFlapPosition();
	tiltNozzleFunction();

	electricSystem();
	bitProgram(dt);



	//printf("True_Mach %f \n", m_state.m_mach);
	//printf("Altitude_in_Ft_Indicator %f \n", altitudeInd());
	//printf("Current_Air_Pressure %f \n", m_state.m_pressure);

	//printf("Flap-Overspeed %f \n", m_flapOSind);
	//printf("GearPosition %f \n", m_gearNPosition);

	//printf("QNH_Value %f \n", m_input.getQnhValue());
	//printf("QNH_Variable %f \n", m_qnhVar);
	params[MAIN_GEAR_POS].tg = (1 - getGearLPosition()) * 90;
	params[NOSE_GEAR_POS].tg = (1 - getGearNPosition()) * 90;
	params[VS_VIS].tg = getFlapsPosition() > 0 && getGearLPosition() > 0.3 && getGearRPosition() > 0.3 && m_state.m_mach < 0.4;
	int gearCount = 0;
	std::string gear;
	int flapCount = getFlapsPosition() * 2;;
	std::string flap;
	if (getGearLPosition() == 1)
	{
		gearCount++;
	}
	if (getGearRPosition() == 1)
	{
		gearCount++;
	}
	if (getGearNPosition() == 1)
	{
		gearCount++;
	}
	if (gearCount == 0)
	{
		gear = "  ";
	}
	else
	{
		gear = "G";
		gear += std::to_string(gearCount);
	}
	if (flapCount == 0)
	{
		flap = "  ";
	}
	else
	{
		flap = "F";
		flap += std::to_string(flapCount);
	}
	if (getSpeedBrakePosition() > 0)
	{
		params[HUD_BRAKE].tgText = "B";
	}
	else
	{
		params[HUD_BRAKE].tgText = " ";
	}
	if (m_chuteState > 0)
	{
		params[HUD_CHUTE].tgText = "C";
	}
	else
	{
		params[HUD_CHUTE].tgText = " ";
	}
	params[HUD_GEAR].tgText = gear.c_str();
	params[HUD_FLAP].tgText = flap.c_str();
	params[leftThrottle].tg = getIntThrottlePosition();
	params[rightThrottle].tg = getIntThrottlePosition2();
	params[ENG_DIRECTION].tg = getTiltEngineNozzlePosition();
	if (m_engine.getRPMNorm() < 0.675 && m_engine.getRPMNorm2() < 0.675)
	{
		params[ENG_THRUST_SPORT].tg = 0.0;
	}
	else if (m_engine.getRPMNorm() >= m_engine.getRPMNorm2())
	{
		params[ENG_THRUST_SPORT].tg = params[ENG_THRUST_SPORT].tg + dt * (m_engine.getRPMNorm() / 0.675) * 2;
		if (params[ENG_THRUST_SPORT].tg > 4)
		{
			params[ENG_THRUST_SPORT].tg = 0.0;
		}
	}
	else if (m_engine.getRPMNorm2() > m_engine.getRPMNorm())
	{
		params[ENG_THRUST_SPORT].tg = params[ENG_THRUST_SPORT].tg + dt * (m_engine.getRPMNorm2() / 0.675) * 2;
		if (params[ENG_THRUST_SPORT].tg > 4)
		{
			params[ENG_THRUST_SPORT].tg = 0.0;
		}
	}
	for (auto it = params.begin(); it != params.end(); ++it)
	{
		it->second.update(m_cockpitAPI);
	}
}

//--------------Catapult non-inline-functions----------------------------
void Airframe::catapultCalculations(double dt)
{
	double c_catConstantMoment = 175000.0;//von 100000.0 auf 1500000.0 wegen dem schweren Vogel...noch ein bissel mehr...auf 175000.0
	double c_catAngle = 0.0;
	double c_catConstrainingForce = 4500.0;

	if (m_catapultState == ON_CAT_NOT_READY && (m_engine.getRPMNorm() > 0.95 || m_engine.getRPMNorm2() > 0.95)) //von 0.9 auf 0.95 erh鰄t damit das CAT erst bei full-AB feuert
	{
		m_catapultState = ON_CAT_READY;
	}

	if (m_catapultState != OFF_CAT)
	{
		if (m_catapultState != ON_CAT_LAUNCHING)
		{
			m_catAngle = m_state.m_angle.z;
			//m_catMoment = -c_catConstantMoment;
		}
		else
		{
			m_catMoment = -c_catConstantMoment + std::max(pow((m_catAngle - m_state.m_angle.z - 0.07) * 60.0, 3.0) * c_catConstrainingForce, -500000.0);
		}
		//printf( "Cat Moment: %lf\n", m_catMoment );
	}
	else
	{
		m_catMoment = 0.0;
		m_catMomentVelocity = 0.0;
		m_prevAccel = 0.0;
		m_catForce = 0.0;
	}
	//printf("Cat Moment: %lf\n", m_catMoment);

	m_catStateSent = false;
}

void Airframe::launchBarCalc()
{
	if ((m_input.getLaunchBarToggle() == 1.0) && (m_state.m_mach <= 0.267))
	{
		m_launchBar = 1.0;
	}
	else if ((m_input.getLaunchBarToggle() == 1.0) && (m_state.m_mach > 0.267))
	{
		m_launchBar = 0.0;
	}
	else
	{
		m_launchBar = 0.0;
	}
}

//-------------Neu eingef黦t f黵 multiplikator AERO-Surfaces--------------
void Airframe::aeroSurfaceMulti(double dt)
{
	if (getGearNPosition() > 0.1)
	{
		m_ailDef = 1.0;
	}
	if (getGearNPosition() == 0.0)
	{
		m_ailDef = 0.75;
	}

	if (getGearNPosition() > 0.1)
	{
		m_rudDef = 1.0;
	}
	if (getGearNPosition() == 0.0)
	{
		m_rudDef = 0.75;
	}
}
//---------------------------------------------------------------------------

//------------Leading Edge Flap Auto-Drive-Function--------------------------

void Airframe::autoDriveLeFlapPosition()
{
	// die Slats/LE-Flaps fahren bei 10?aus und bei 9?AoA wieder automatisch ein
	// in Rad = 0.175 und 0.157

	if (m_flapsPosition == 0.0)
	{
		if (m_state.m_aoa >= 0.21)// && ((m_autoDriveLeFlaps == 0.0) || (m_autoDriveLeFlaps == 1.0)))
		{
			m_autoDriveLeFlaps = 1.0;
		}
		else if (((m_state.m_aoa >= 0.157) && (m_state.m_aoa < 0.21)) && (m_autoDriveLeFlaps == 1.0))
		{
			m_autoDriveLeFlaps = 1.0;
		}
		else
		{
			m_autoDriveLeFlaps = 0.0;
		}
	}
	else if ((m_flapsPosition > 0.0) && (m_autoDriveLeFlaps > m_flapsPosition))
	{
		//-----einfach mal nix 鋘dern hier, sondern alles so lassen wie zuvor :-) -----//m_autoDriveLeFlaps = m_autoDriveLeFlaps;
	}
	else if ((m_flapsPosition > 0.0) && (m_autoDriveLeFlaps <= m_flapsPosition))
	{
		m_autoDriveLeFlaps = m_flapsPosition;
	}
}

double Airframe::updateBrake()
{
	//m_brakeMoment = 0.0;//黚erfl黶sig weil in ZeroInit auf 0.0 gesetzt

	/*if (m_input.m_release_brake == 1.0)
	{
		if (m_input.m_brake == 1.0)
		{
			m_input.m_brake = 0.0;
			m_input.m_release_brake = 0.0;
		}
	}*/ //wurde in Input.cpp verschoben "setBrake()"

	if (m_input.getBrake() == 1.0 || m_cockpitAPI.getParamNumber(m_wheelChockHandle) > 0.5)
	{
		m_brakeMoment = 1.00;//0.66
	}
	else
	{
		m_brakeMoment = 0.0;
	}

	return m_brakeMoment;
}

double Airframe::updateBrakeLeft()
{
	if (updateBrake() != 0.0)
	{
		m_brakeLeft = updateBrake();
	}
	else
	{
		m_brakeLeft = m_input.getBrakeLeft();
	}
	params[ROD_LB_POS].tg = m_brakeLeft;
	return m_brakeLeft;
}

double Airframe::updateBrakeRight()
{
	if (updateBrake() != 0.0)
	{
		m_brakeRight = updateBrake();
	}
	else
	{
		m_brakeRight = m_input.getBrakeRight();
	}
	params[ROD_RB_POS].tg = m_brakeRight;
	return m_brakeRight;
}

double Airframe::setNozzlePosition(double dt) //Nozzle-Position 0-10% Thrust open, 11-84% Thrust closed, 85-100% Thrust open
{
	double NozzlePos = 0.0;
	double corrThrottle = 0.0;

	if (m_input.getThrottle() >= 0.0)
	{
		corrThrottle = (1 - CON_ThrotIDL) * m_input.getThrottle() + CON_ThrotIDL;
	}
	else
	{
		corrThrottle = (m_input.getThrottle() + 1.0) / 2.0;
	}

	if (corrThrottle <= 0.10)
	{
		NozzlePos = 0.4;
	}
	else if (corrThrottle >= 0.85)
	{
		NozzlePos = 0.80;
	}
	else
	{
		NozzlePos = 0.2;
	}

	double input = NozzlePos;
	return m_actuatorNozzle.inputUpdate(input, dt);
}

double Airframe::setNozzle2Position(double dt) //Nozzle-Position 0-10% Thrust open, 11-84% Thrust closed, 85-100% Thrust open
{
	double NozzlePos = 0.0;
	double corrThrottle = 0.0;

	if (m_input.getThrottle2() >= 0.0)
	{
		corrThrottle = (1 - CON_ThrotIDL) * m_input.getThrottle2() + CON_ThrotIDL;
	}
	else
	{
		corrThrottle = (m_input.getThrottle2() + 1.0) / 2.0;
	}

	if (corrThrottle <= 0.10)
	{
		NozzlePos = 0.4;
	}
	else if (corrThrottle >= 0.85)
	{
		NozzlePos = 0.80;
	}
	else
	{
		NozzlePos = 0.2;
	}

	double input = NozzlePos;
	return m_actuatorNozzle.inputUpdate(input, dt);
}

//----------TiltNozzle Function for Speed----------------------------------------

void Airframe::tiltNozzleFunction()
{
	bool VTOLinAction = false;
	double NozzleFinalTilt = 0.0;

	if (m_input.getTiltEngineNozzle() > 0.0)
	{
		VTOLinAction = true;
	}
	else
	{
		VTOLinAction = false;
	}

	if (m_input.getTiltEngineNozzle() == 0.2)
	{
		NozzleFinalTilt = 0.2;
	}
	else if (m_input.getTiltEngineNozzle() == 0.3)
	{
		NozzleFinalTilt = 0.4;
	}
	else if (m_input.getTiltEngineNozzle() == 0.4)
	{
		NozzleFinalTilt = 0.6;
	}
	else if (m_input.getTiltEngineNozzle() == 0.5)
	{
		NozzleFinalTilt = 0.8;
	}
	else if (m_input.getTiltEngineNozzle() == 0.6)
	{
		NozzleFinalTilt = 1.0;
	}
	else
	{
		NozzleFinalTilt = 0.0;
	}

	if (m_state.m_mach > 0.45)
	{
		m_tiltNozzleOverSpeed = 1.0;
	}
	else
	{
		m_tiltNozzleOverSpeed = 0.0;
	}


	if ((m_tiltNozzleOverSpeed == 0.0) && (VTOLinAction == true))
	{
		m_rotorTopClapPosition = 0.1;
	}
	else
	{
		m_rotorTopClapPosition = 0.0;

	}

	if ((m_tiltNozzleOverSpeed == 0.0) && (getTopRotorClap() >= 0.07) && (VTOLinAction == true))
	{
		m_wingNozzlePosition = 0.1;
	}
	else
	{
		m_wingNozzlePosition = 0.0;
	}

	if ((getWingNozzles() == 0.1) && (getTopRotorClap() == 0.1) && (VTOLinAction == true))
	{
		m_nozzleTiltPosition = NozzleFinalTilt;//m_input.getTiltEngineNozzle();
	}
	else
	{
		m_nozzleTiltPosition = 0.0;
	}

	//printf("m_tiltNozzleOverSpeed %f\n", m_tiltNozzleOverSpeed);
	//printf("TiltNozzle_Input %f\n", m_input.getTiltEngineNozzle());
}


//------------Internal Throttle Position lassen wir erstmal so-------------------
double Airframe::getIntThrottlePosition()
{
	m_int_throttlePos = 0.0;
	double corrThrottle = 0.0;

	if (m_input.getThrottle() >= 0.0)
	{
		corrThrottle = (1.0 - CON_ThrotIDL) * m_input.getThrottle() + CON_ThrotIDL;
	}
	else
	{
		corrThrottle = (m_input.getThrottle() + 1.0) / 2.0;
	}

	m_int_throttlePos = corrThrottle;

	return m_int_throttlePos;
}

double Airframe::getIntThrottlePosition2()
{
	m_int_throttlePos2 = 0.0;
	double corrThrottle = 0.0;

	if (m_input.getThrottle2() >= 0.0)
	{
		corrThrottle = (1.0 - CON_ThrotIDL) * m_input.getThrottle2() + CON_ThrotIDL;
	}
	else
	{
		corrThrottle = (m_input.getThrottle2() + 1.0) / 2.0;
	}

	m_int_throttlePos2 = corrThrottle;

	return m_int_throttlePos2;
}


double Airframe::NWSstate()
{
	if (m_input.getNWS() == 1.0)
	{
		m_nwsEngage = 1.0;
	}
	else if (m_input.getNWS() == 0.0)
	{
		m_nwsEngage = 0.0;
	}
	else
	{
		m_nwsEngage = 0.0;
	}
	return m_nwsEngage;
}

double Airframe::brkChutePosition()
{
	int timeToGo1 = 20; //war 50, jetzt aber meherere Stationen
	int timeToGo2 = 40;
	int timeToGo3 = 60;
	int timeToGo4 = 80;

	if ((m_input.getBrkChute() == 1) && (m_timePassed < timeToGo1) && (m_chuteDeployed == false))
	{
		m_chuteState = 0.2;
	}
	if (m_chuteState == 0.2)
	{
		m_timePassed++;
	}
	if ((m_chuteState == 0.2) && (m_timePassed >= timeToGo1) && (m_timePassed < timeToGo2))
	{
		m_chuteState = 0.5;
	}
	if (m_chuteState == 0.5)
	{
		m_timePassed++;
	}
	if ((m_chuteState == 0.5) && (m_timePassed >= timeToGo2) && (m_timePassed <= timeToGo3))
	{
		m_chuteState = 0.7;
	}
	if (m_chuteState == 0.7)
	{
		m_timePassed++;
	}
	if ((m_chuteState == 0.7) && (m_timePassed >= timeToGo3))
	{
		m_chuteState = 1.0;
		m_timePassed = 85;
	}
	else if (m_input.getBrkChute() == 0.0)
	{
		m_chuteState = 0.0;
		m_timePassed = 0.0;
	}
	else if (m_input.getBrkChute() == 2.0)
	{
		m_chuteState = 0.0;
		m_timePassed = 0.0;
		m_chuteDeployed = true; //jetzt gibt es keine unendlichen Bremsfallschirme mehr...
	}
	if ((m_engine.getRPMNorm() == 0.0 || m_engine.getRPMNorm2() == 0.0) && (m_state.m_mach <= 0.1))
	{
		m_chuteDeployed = false;
	}

	return m_chuteState;
}

double Airframe::brkChuteSlewY()
{
	m_chuteSlewY = 0.0;
	double m_chuteDiceRoll = 0.0;
	int dice_roll = 0;
	int dice_roll1 = 0;
	int dice_roll2 = 0;
	double m_mach_speed = 0.0;
	m_mach_speed = m_state.m_mach;

	if (m_chuteState != 0)
	{

		if (m_mach_speed >= 0.12)
		{
			/*std::default_random_engine generator;
			std::uniform_int_distribution<int> distribution(1, 19);
			dice_roll = distribution(generator);  // generates number in the range 1-19 */

			int mill_seconds = (duration_cast<milliseconds>(system_clock::now().time_since_epoch()).count()) / 100; //weil es eine INT ist macht / 100 Sinn, da dann nur jede 10tel-Sekunde eine neue Zahl kommt, da gerundet wird.

			srand(mill_seconds); //vorher srand(timt(0)); das gab die sekunden-ticks zur點k, wir brauchen aber millisekunden

			dice_roll = (rand() % 19) + 1;

			if ((dice_roll == 2) || (dice_roll == 1))
			{
				m_chuteDiceRoll = -0.05; //was -0.65	
				//m_chuteSlewingY = true; //Neu 黚erall eingef黦t, ggf. wieder hier und im If entfernen
			}
			if ((dice_roll == 3) || (dice_roll == 4))
			{
				m_chuteDiceRoll = 0.00; //was -0.55
				//m_chuteSlewingY = true;
			}
			if ((dice_roll == 5) || (dice_roll == 6))
			{
				m_chuteDiceRoll = 0.10;//was -0.40
				//m_chuteSlewingY = true;
			}
			if ((dice_roll == 7) || (dice_roll == 8))
			{
				m_chuteDiceRoll = 0.25;//was -0.19
				//m_chuteSlewingY = true;
			}
			if ((dice_roll == 9) || (dice_roll == 10))
			{
				m_chuteDiceRoll = 0.35;//was 0.0
				//m_chuteSlewingY = true;
			}
			if ((dice_roll == 11) || (dice_roll == 12))
			{
				m_chuteDiceRoll = 0.55; //was 0.19	
				//m_chuteSlewingY = true;
			}
			if ((dice_roll == 13) || (dice_roll == 14))
			{
				m_chuteDiceRoll = 0.65; //was 0.40	
				//m_chuteSlewingY = true;
			}
			if ((dice_roll == 15) || (dice_roll == 16))
			{
				m_chuteDiceRoll = 0.80;//was 0.55	
				//m_chuteSlewingY = true;
			}
			if (dice_roll >= 17)
			{
				m_chuteDiceRoll = 0.95;//was 0.65	
				//m_chuteSlewingY = true;
			}

			m_chuteSlewY = m_chuteDiceRoll;
			return m_chuteSlewY;
		}
		if ((m_mach_speed >= 0.05) && (m_mach_speed < 0.11))// && (m_chuteSlewing == false))
		{
			/*std::default_random_engine generator;
			std::uniform_int_distribution<int> distribution(1, 11);
			dice_roll1 = distribution(generator);  // generates number in the range -0.20....0.20*/

			int mill_seconds = (duration_cast<milliseconds>(system_clock::now().time_since_epoch()).count()) / 100;

			srand(mill_seconds); //vorher srand(timt(0)); das gab die sekunden-ticks zur點k, wir brauchen aber millisekunden

			dice_roll1 = (rand() % 11) + 1;

			if (dice_roll1 <= 2)
			{
				m_chuteDiceRoll = -0.05;//was -0.35
				//m_chuteSlewingY = true;
			}
			if ((dice_roll1 == 3) || (dice_roll1 == 4))
			{
				m_chuteDiceRoll = 0.05;//was -0.15
				//m_chuteSlewingY = true;
			}
			if ((dice_roll1 == 5) || (dice_roll1 == 6))
			{
				m_chuteDiceRoll = 0.10;//was -0.05
				//m_chuteSlewingY = true;
			}
			if ((dice_roll1 == 7) || (dice_roll1 == 8))
			{
				m_chuteDiceRoll = 0.35;//was 0.10
				//m_chuteSlewingY = true;
			}
			if (dice_roll1 >= 9)
			{
				m_chuteDiceRoll = 0.60;//was 0.25
				//m_chuteSlewingY = true;
			}
			m_chuteSlewY = m_chuteDiceRoll;
			return m_chuteSlewY;
		}
		if ((m_mach_speed < 0.05) && (m_mach_speed > 0.00))// && (m_chuteSlewing == false))
		{
			/*std::default_random_engine generator;
			std::uniform_int_distribution<int> distribution(1, 11);
			dice_roll2 = distribution(generator);  // generates number in the range -0.20....0.20*/

			int mill_seconds = (duration_cast<milliseconds>(system_clock::now().time_since_epoch()).count()) / 100;

			srand(mill_seconds); //vorher srand(timt(0)); das gab die sekunden-ticks zur點k, wir brauchen aber millisekunden


			dice_roll2 = (rand() % 11) + 1;

			if (dice_roll2 <= 2)
			{
				m_chuteDiceRoll = -0.15;//was -0.99
				//m_chuteSlewingY = true;
			}
			if ((dice_roll2 == 3) || (dice_roll2 == 4))
			{
				m_chuteDiceRoll = -0.05;//was -0.95
				//m_chuteSlewingY = true;
			}
			if ((dice_roll2 == 5) || (dice_roll2 == 6))
			{
				m_chuteDiceRoll = 0.05;//was -0.90
				//m_chuteSlewingY = true;
			}
			if ((dice_roll2 == 7) || (dice_roll2 == 8))
			{
				m_chuteDiceRoll = 0.15;//was -0.89
				//m_chuteSlewingY = true;
			}
			if (dice_roll2 >= 9)
			{
				m_chuteDiceRoll = 0.25;//was -0.87
				//m_chuteSlewingY = true;
			}
			m_chuteSlewY = m_chuteDiceRoll;
			return m_chuteSlewY;
		}
		if (m_mach_speed == 0.00)
		{
			m_chuteSlewY = 0.00;//was -1.0
			//m_chuteSlewingY = false;

			return m_chuteSlewY;
		}

	}

	/*if (m_chuteSlewingY == true)
	{
	int chuteTimeToPass = 10;

		if (m_chuteTimeYPassed < chuteTimeToPass)
		{
			m_chuteTimeYPassed++;
		}
		if (m_chuteTimeYPassed >= chuteTimeToPass)
		{
			m_chuteSlewingY = false;
			m_chuteTimeYPassed = 0;
			m_chuteSlewY = 0.0;
			return m_chuteSlewY;
		}
	//return m_chuteSlewY;
	}

	printf("ChuteYTimePassed %f \n", m_chuteTimeYPassed);
	*/
}

double Airframe::brkChuteSlewZ()
{
	//m_chuteSlewZ = 0.0; auskommentiert zum testen
	double m_chuteDiceRoll = 0.0;
	int dice_roll = 0;
	int dice_roll1 = 0;
	int dice_roll2 = 0;
	double m_mach_speed = 0.0;
	m_mach_speed = m_state.m_mach;

	if (m_chuteState != 0)// && (m_chuteSlewingZ == false))
	{

		if (m_mach_speed >= 0.12)
		{
			/*std::default_random_engine generator;
			std::uniform_int_distribution<int> distribution(1, 19);
			dice_roll = distribution(generator);  // generates number in the range -0.75....0.75
			*/
			int mill_seconds = (duration_cast<milliseconds>(system_clock::now().time_since_epoch()).count()) / 100;

			srand(mill_seconds); //vorher srand(timt(0)); das gab die sekunden-ticks zur點k, wir brauchen aber millisekunden

			dice_roll = (rand() % 19) + 1;

			if (dice_roll <= 3)
			{
				m_chuteDiceRoll = -0.95;
				//m_chuteSlewingZ = true;
				//dice_roll = 0;
			}
			if ((dice_roll == 4) || (dice_roll == 5))
			{
				m_chuteDiceRoll = -0.75;
				//m_chuteSlewingZ = true;
			}
			if ((dice_roll == 6) || (dice_roll == 7))
			{
				m_chuteDiceRoll = -0.44;
				//m_chuteSlewingZ = true;
			}
			if ((dice_roll == 8) || (dice_roll == 9))
			{
				m_chuteDiceRoll = -0.19;
				//m_chuteSlewingZ = true;
			}
			if ((dice_roll == 10) || (dice_roll == 11))
			{
				m_chuteDiceRoll = 0;
				//m_chuteSlewingZ = true;
			}
			if ((dice_roll == 12) || (dice_roll == 13))
			{
				m_chuteDiceRoll = 0.19;
				//m_chuteSlewingZ = true;
			}
			if ((dice_roll == 14) || (dice_roll == 15))
			{
				m_chuteDiceRoll = 0.44;
				//m_chuteSlewingZ = true;
			}
			if ((dice_roll == 16) || (dice_roll == 17))
			{
				m_chuteDiceRoll = 0.75;
				//m_chuteSlewingZ = true;
			}
			if (dice_roll >= 18)
			{
				m_chuteDiceRoll = 0.95;
				//m_chuteSlewingZ = true;
			}
			m_chuteSlewZ = m_chuteDiceRoll;
			return m_chuteSlewZ;
		}
		if ((m_mach_speed >= 0.05) && (m_mach_speed < 0.12))
		{
			/*std::default_random_engine generator;
			std::uniform_int_distribution<int> distribution(1, 11);
			dice_roll1 = distribution(generator);  // generates number in the range -0.20....0.20
			*/

			int mill_seconds = (duration_cast<milliseconds>(system_clock::now().time_since_epoch()).count()) / 100;

			srand(mill_seconds); //vorher srand(timt(0)); das gab die sekunden-ticks zur點k, wir brauchen aber millisekunden

			dice_roll1 = (rand() % 11) + 1;

			if (dice_roll1 <= 2)
			{
				m_chuteDiceRoll = -0.45;
				//m_chuteSlewingZ = true;
			}
			if ((dice_roll1 == 3) || (dice_roll1 == 4))
			{
				m_chuteDiceRoll = -0.25;
				//m_chuteSlewingZ = true;
			}
			if ((dice_roll1 == 5) || (dice_roll1 == 6))
			{
				m_chuteDiceRoll = 0.00;
				//m_chuteSlewingZ = true;
			}
			if ((dice_roll1 == 7) || (dice_roll1 == 8))
			{
				m_chuteDiceRoll = 0.25;
				//m_chuteSlewingZ = true;
			}
			if (dice_roll1 >= 9)
			{
				m_chuteDiceRoll = 0.45;
				//m_chuteSlewingZ = true;
			}
			m_chuteSlewZ = m_chuteDiceRoll;
			return m_chuteSlewZ;
		}
		if ((m_mach_speed < 0.05) && (m_mach_speed > 0.00))
		{
			/*std::default_random_engine generator;
			std::uniform_int_distribution<int> distribution(1, 11);
			dice_roll2 = distribution(generator);  // generates number in the range -0.20....0.20
			*/
			int mill_seconds = (duration_cast<milliseconds>(system_clock::now().time_since_epoch()).count()) / 100; //NEU wegen Chrono

			srand(mill_seconds); //vorher srand(timt(0)); das gab die sekunden-ticks zur點k, wir brauchen aber millisekunden

			dice_roll2 = (rand() % 11) + 1;

			if (dice_roll2 <= 2)
			{
				m_chuteDiceRoll = -0.15;
				//m_chuteSlewingZ = true;
			}
			if ((dice_roll2 == 3) || (dice_roll2 == 4))
			{
				m_chuteDiceRoll = -0.07;
				//m_chuteSlewingZ = true;
			}
			if ((dice_roll2 == 5) || (dice_roll2 == 6))
			{
				m_chuteDiceRoll = 0.00;
				//m_chuteSlewingZ = true;
			}
			if ((dice_roll2 == 7) || (dice_roll2 == 8))
			{
				m_chuteDiceRoll = 0.07;
				//m_chuteSlewingZ = true;
			}
			if (dice_roll2 >= 9)
			{
				m_chuteDiceRoll = 0.15;
				//m_chuteSlewingZ = true;
			}
			m_chuteSlewZ = m_chuteDiceRoll;
			return m_chuteSlewZ;
		}
		if (m_mach_speed == 0.00)
		{
			m_chuteSlewZ = 0.0;
			//m_chuteSlewingZ = false;

			//printf("ChuteSlewZ-Value %f \n", m_chuteSlewZ);

			return m_chuteSlewZ;
		}
	}

	return 0.0;

	/*if (m_chuteSlewingZ == true)
	{
	int chuteTimeToPass = 10;

		if (m_chuteTimeZPassed < chuteTimeToPass)
		{
			m_chuteTimeZPassed++;
		}
		if (m_chuteTimeZPassed >= chuteTimeToPass)
		{
			m_chuteSlewingZ = false;
			m_chuteTimeZPassed = 0;
			m_chuteSlewZ = 0.0;
			return m_chuteSlewZ;
		}
	//return m_chuteSlewY;
	}*/
	//printf("TimeZPassed %f \n", m_chuteTimeZPassed);
}

double Airframe::BLCsystem()
{
	m_blcLift = 0.0;
	/*
	if ((getFlapsPosition() == 1.0) && (m_engine_L.getRPMNorm() >= 0.80))
	{
		m_blcLift = 0.22 * ((m_engine_L.getRPMNorm() + m_engine_L.getRPMNorm2()) / 2);// von * 0.31 zu * 0.22
	}
	else
	{
		m_blcLift = 0.0;
	}
	*/

	return m_blcLift;
}

double Airframe::getEngineDamageMult()
{
	if ((getCompressorDamage() <= 0.75) || (getTurbineDamage() <= 0.75))
	{
		m_engDmgMulti = ((getCompressorDamage() + getTurbineDamage())) * 1.15;
	}
	else
	{
		m_engDmgMulti = 1.0;
	}
	return m_engDmgMulti;
}
double Airframe::getEngineDamageMultR()
{
	if ((getCompressorDamageR() <= 0.75) || (getTurbineDamageR() <= 0.75))
	{
		m_engDmgMulti = ((getCompressorDamageR() + getTurbineDamageR())) * 1.15;
	}
	else
	{
		m_engDmgMulti = 1.0;
	}
	return m_engDmgMulti;
}

void Airframe::autoPilotAltH(double dt)
{
	m_ascHA = APascend(m_altInFt / m_altHold);
	m_decHA = -(APascend(m_altHold / m_altInFt));


	//checking of ascend or decend-angle is met
	if (m_state.m_angle.z == (m_ascHA + m_state.m_aoa))
	{
		m_acendHoldAngle = true;
	}
	else
	{
		m_acendHoldAngle = false;
	}

	if (m_state.m_angle.z == (m_decHA - m_state.m_aoa))
	{
		m_decendHoldAngle = true;
	}
	else
	{
		m_decendHoldAngle = false;
	}

	if ((m_state.m_angle.z - m_state.m_aoa) == 0.0)
	{
		m_level = true;
	}
	else
	{
		m_level = false;
	}

	//----checking if plane gains or looses alt---------------------------------
	if ((m_state.m_angle.z > 0.0) && ((m_state.m_angle.z - m_state.m_aoa) > 0.0))
	{
		m_acend = true;
	}
	else
	{
		m_acend = false;
	}

	if ((m_state.m_angle.z < 0.0) || ((m_state.m_angle.z) - (m_state.m_aoa) < 0.0)) //|| ((m_state.m_angle.z) - (m_state.m_aoa) < 0.0)) neu eingef黦t 24.10.
	{
		m_decend = true;
	}
	else
	{
		m_decend = false;
	}

	//-------------Autopilot-AltHold function--------------------------------
	if (m_input.getAutoPEng() == 1.0)
	{
		m_desiredAlt = m_altInFt;

		//-----check and hold decend angle
		if (m_altHold < m_altInFt)
		{
			if ((m_decendHoldAngle == false) && (m_altHold != 0.0))
			{
				if ((m_state.m_angle.z > m_decHA) && (m_pitchAPadj > -0.015))
				{
					m_pitchAPadj -= 0.0001;
				}
				else if ((m_state.m_angle.z < m_decHA) && (m_pitchAPadj < 0.015))
				{
					m_pitchAPadj += 0.0001;
				}
			}

			if ((m_decendHoldAngle == true) && (m_altHold != 0.0))
			{
				m_pitchAPadj = 0.0;
			}
		}

		//----check and hold ascend angle
		if (m_altHold > m_altInFt)
		{
			if ((m_acendHoldAngle == false) && (m_altHold != 0.0))
			{
				if ((m_state.m_angle.z > (m_ascHA + m_state.m_aoa)) && (m_pitchAPadj > -0.015))
				{
					m_pitchAPadj -= 0.0001;
				}
				else if ((m_state.m_angle.z < (m_ascHA + m_state.m_aoa)) && (m_pitchAPadj < 0.015))
				{
					m_pitchAPadj += 0.0001;
				}
			}

			if ((m_acendHoldAngle == true) && (m_altHold != 0.0))
			{
				m_pitchAPadj = 0.0;
			}
		}

		if ((m_altHold == m_altInFt) && (m_level == true))
		{
			m_pitchAPadj += 0.0;
		}

		if ((m_previousAlt != m_desiredAlt) && (m_previousAlt != 0.0) && (m_input.getAutoPEng() == 1) && (m_altHold == 0.0))
		{
			m_altHold = m_altInFt;
		}
		else if ((m_altHold != 0.0) && (m_previousAlt != m_desiredAlt) && (m_input.getAutoPEng() == 1.0))
		{
			//---hier mach ich mal nix---
		}

		m_previousAlt = m_desiredAlt;
	}
	else if (m_input.getAutoPEng() == 0.0)
	{
		m_pitchAPadj = 0.0;
		m_previousAlt = 0.0;
		m_altHold = 0.0;
		m_desiredAlt = 0.0;
	}
}


void Airframe::electricSystem()
{

	bool BattCounter = false;

	if ((m_elec.isDC()) && (getCompressorDamage() > 0.25))
	{
		m_hasACpower = 1.0;
	}
	if ((m_elec.isDC()) && (getTurbineDamage() > 0.20))
	{
		m_hasDCpower = 1.0;
	}
	else if ((!m_elec.isDC()) || (getCompressorDamage() <= 0.25))
	{
		m_hasACpower = 0.0;
	}
	else if ((!m_elec.isDC()) || (getTurbineDamage() <= 0.20))
	{
		m_hasDCpower = 0.0;
	}

	//Batterie-Life is 100000 calculate frames...
	if ((m_elec.isDC()) && ((m_hasDCpower == 0.0) || (m_hasACpower == 0.0)))
	{
		BattCounter = true;
	}

	if ((BattCounter == true) && (m_batTimer == 0.0))
	{
		m_hasBATpower = 1.0;
	}
	else if ((BattCounter == true) && ((m_batTimer != 0.0) && (m_batTimer < 100000)))
	{
		m_batTimer++;
	}
	else if ((BattCounter == true) && (m_batTimer == 100000.0))
	{
		m_hasBATpower = 0.0;
	}
}

double Airframe::getQNHinThousand()
{
	return m_indQnhThousand;
}

double Airframe::getQNHinHundred()
{
	if (m_indQnhHundred >= 9.0)
	{
		m_retIndQnhHundred = 0.0;
	}
	else
	{
		m_retIndQnhHundred = 1.0;
	}

	return m_retIndQnhHundred;
}

double Airframe::getQNHinTen()
{
	return m_indQnhTen / 10.0;
}

double Airframe::getQNHinOne()
{
	return m_indQnhOne / 10.0;
}

//-------------------Gear and Flap overspeed Damage functions----------------
double Airframe::osGearDamage()
{
	if ((m_state.m_mach > 0.61) && (getGearNPosition() > 0.2))
	{
		m_actuatorGearN.setOverSpeedMalFunction();
		m_actuatorGearL.setOverSpeedMalFunction();
		m_actuatorGearR.setOverSpeedMalFunction();

		m_gearOversped = 1.0;
	}
	return m_gearOversped;
}

double Airframe::osFlapDamage()
{
	if ((m_state.m_mach > 0.65) && (getFlapsPosition() > 0.75))
	{
		m_actuatorFlap.setOverSpeedMalFunction();
		m_flapOversped = 1.0;
	}
	if ((m_state.m_mach > 0.99) && (getFlapsPosition() > 0.25))
	{
		m_actuatorFlap.setOverSpeedMalFunction();
		m_flapOversped = 1.0;
	}
	return m_flapOversped;
}

//-------------------Repair-Needs and Repair-Function-----------------------


void Airframe::resetOSdamage()
{
	m_flapOversped = 0.0;
	m_gearOversped = 0.0;
	m_batTimer = 0.0;
	m_actuatorFlap.revOverSpeedMalFunction();
	m_actuatorGearL.revOverSpeedMalFunction();
	m_actuatorGearN.revOverSpeedMalFunction();
	m_actuatorGearR.revOverSpeedMalFunction();

}

void Airframe::bitProgram(double dt)
{
	if (!fcsBit && m_input.getFcsBit() > 0.5 && m_elec.isAC())
	{
		printf("自检开始\n");
		fcsBit = true;
	}
	else if (fcsBit && m_state.m_localSpeed.x < 1.0 && getWeightOnWheels()>0)
	{
		bool bitStep2Flag = !(bit_flapL != 0 || bit_flapR != 0 || bit_leflapL != 0 || bit_leflapR != 0 || bit_aileronL != 0 || bit_aileronR != 0 || bit_canardL != 0 || bit_canardR != 0 || bit_rudderL != 0 || bit_rudderR != 0 || bit_canardBrake != 0 || bit_airBrake != 0);
		double bitStep32Flag = (bit_flapL - m_flapsPosition)
			+ (bit_flapR - m_flapsPosition)
			+ (bit_leflapL - m_leFlapsPosition)
			+ (bit_leflapR - m_leFlapsPosition)
			+ (bit_aileronL - m_aileronLeft)
			+ (bit_aileronR - m_aileronRight)
			+ (bit_canardL - m_state.getAoaRate())
			+ (bit_canardR - m_state.getAoaRate())
			+ (1 - (int)(bit_rudderL == -m_rudder))
			+ (1 - (int)(bit_rudderR == -m_rudder))
			+ (bit_canardBrake - m_speedCanardBrakePosition)
			+ (bit_airBrake - m_speedBrakePosition);
		bitStep32Flag = clamp(bitStep32Flag, -1, 1);
		bitTime += dt;
		if (bitCount == 0)
		{
			bit_flapL = getFlapsPosition();
			bit_flapR = getFlapsPosition();
			bit_leflapL = getLEFlapPosition();
			bit_leflapR = getLEFlapPosition();
			bit_aileronL = m_aileronLeft;
			bit_aileronR = m_aileronRight;
			bit_canardL = m_state.getAoaRate();
			bit_canardR = m_state.getAoaRate();
			bit_rudderL = -getRudder();
			bit_rudderR = -getRudder();
			bit_canardBrake = m_speedCanardBrakePosition;
			bit_airBrake = m_speedBrakePosition;
			bitCount++;
			printf("对接就绪\n");
		}
		else if (bitCount == 1)
		{
			if (!bitStep2Flag)
			{
				bit_flapL = clamp(bit_flapL - dt, 0, 1);
				bit_flapR = clamp(bit_flapR - dt, 0, 1);
				bit_leflapL = clamp(bit_leflapL - dt, 0, 1);
				bit_leflapR = clamp(bit_leflapR - dt, 0, 1);
				bit_aileronL = clamp(bit_aileronL - dt, 0, 1);
				bit_aileronR = clamp(bit_aileronR - dt, 0, 1);
				bit_canardL = clamp(bit_canardL - dt, 0, 1);
				bit_canardR = clamp(bit_canardR - dt, 0, 1);
				bit_rudderL = clamp(bit_rudderL - dt, 0, 1);
				bit_rudderR = clamp(bit_rudderR - dt, 0, 1);
				bit_canardBrake = clamp(bit_canardBrake - dt, 0, 1);
				bit_airBrake = clamp(bit_airBrake - dt, 0, 1);
				printf("重置中\n");
				printf("arg09==%.2f\n", bit_flapR);
				printf("arg10==%.2f\n", bit_flapL);
				printf("arg11==%.2f\n", bit_aileronR);
				printf("arg12==%.2f\n", bit_aileronL);
				printf("arg13==%.2f\n", bit_leflapR);
				printf("arg14==%.2f\n", bit_leflapL);
				printf("arg15==%.2f\n", bit_canardR);
				printf("arg16==%.2f\n", bit_canardL);
				printf("arg17==%.2f\n", bit_rudderR);
				printf("arg18==%.2f\n", bit_rudderL);
				printf("arg21==%.2f\n", bit_airBrake);
				printf("arg181==%.2f\n", bit_canardBrake);
			}
			else
			{
				bitCount++;
				printf("重置完成\n");
				printf("arg09==%.2f\n", bit_flapR);
				printf("arg10==%.2f\n", bit_flapL);
				printf("arg11==%.2f\n", bit_aileronR);
				printf("arg12==%.2f\n", bit_aileronL);
				printf("arg13==%.2f\n", bit_leflapR);
				printf("arg14==%.2f\n", bit_leflapL);
				printf("arg15==%.2f\n", bit_canardR);
				printf("arg16==%.2f\n", bit_canardL);
				printf("arg17==%.2f\n", bit_rudderR);
				printf("arg18==%.2f\n", bit_rudderL);
				printf("arg21==%.2f\n", bit_airBrake);
				printf("arg181==%.2f\n", bit_canardBrake);
			}
		}
		else if (bitCount == 2)
		{
			bit_flapL = clamp(bit_flapL + dt, 0, 1);
			if (bit_flapL == 1.0)
			{
				bitCount++;
			}
		}
		else if (bitCount == 3)
		{
			bit_flapL = clamp(bit_flapL - dt, 0, 1);
			if (bit_flapL == 0.0)
			{
				printf("左襟翼自检完成\n");
				bitCount++;
			}
		}
		else if (bitCount == 4)
		{
			bit_flapR = clamp(bit_flapR + dt, 0, 1);
			if (bit_flapR == 1.0)
			{
				bitCount++;
			}
		}
		else if (bitCount == 5)
		{
			bit_flapR = clamp(bit_flapR - dt, 0, 1);
			if (bit_flapR == 0.0)
			{
				printf("右襟翼自检完成\n");
				bitCount++;
			}
		}
		else if (bitCount == 6)
		{
			bit_aileronL = clamp(bit_aileronL + dt, 0, 1);
			if (bit_aileronL == 1.0)
			{
				bitCount++;
			}
		}
		else if (bitCount == 7)
		{
			bit_aileronL = clamp(bit_aileronL - dt, -1, 1);
			if (bit_aileronL == -1)
			{
				bitCount++;
			}
		}
		else if (bitCount == 8)
		{
			bit_aileronL = clamp(bit_aileronL + dt, -1, 0);
			if (bit_aileronL == 0)
			{
				printf("左副翼自检完成\n");
				bitCount++;
			}
		}
		else if (bitCount == 9)
		{
			bit_aileronR = clamp(bit_aileronR + dt, 0, 1);
			if (bit_aileronR == 1.0)
			{
				bitCount++;
			}
		}
		else if (bitCount == 10)
		{
			bit_aileronR = clamp(bit_aileronR - dt, -1, 1);
			if (bit_aileronR == -1.0)
			{
				bitCount++;
			}
		}
		else if (bitCount == 11)
		{
			bit_aileronR = clamp(bit_aileronR + dt, -1, 0);
			if (bit_aileronR == 0.0)
			{
				printf("右副翼自检完成\n");
				bitCount++;
			}
		}
		else if (bitCount == 12)
		{
			bit_leflapL = clamp(bit_leflapL + dt, 0, 1);
			if (bit_leflapL == 1.0)
			{
				bitCount++;
			}
		}
		else if (bitCount == 13)
		{
			bit_leflapL = clamp(bit_leflapL - dt, 0, 1);
			if (bit_leflapL == 0.0)
			{
				printf("左前缘襟翼自检完成\n");
				bitCount++;
			}
		}
		else if (bitCount == 14)
		{
			bit_leflapR = clamp(bit_leflapR + dt, 0, 1);
			if (bit_leflapR == 1.0)
			{
				bitCount++;
			}
		}
		else if (bitCount == 15)
		{
			bit_leflapR = clamp(bit_leflapR - dt, 0, 1);
			if (bit_leflapR == 0.0)
			{
				printf("右前缘襟翼自检完成\n");
				bitCount++;
			}
		}
		else if (bitCount == 16)
		{
			bit_canardL = clamp(bit_canardL + dt, 0, 1);
			if (bit_canardL == 1.0)
			{
				bitCount++;
			}
		}
		else if (bitCount == 17)
		{
			bit_canardL = clamp(bit_canardL - dt, -1, 1);
			if (bit_canardL == -1)
			{
				bitCount++;
			}
		}
		else if (bitCount == 18)
		{
			bit_canardL = clamp(bit_canardL + dt, -1, 0);
			if (bit_canardL == 0)
			{
				printf("左鸭翼自检完成\n");
				bitCount++;
			}
		}
		else if (bitCount == 19)
		{
			bit_canardR = clamp(bit_canardR + dt, 0, 1);
			if (bit_canardR == 1.0)
			{
				bitCount++;
			}
		}
		else if (bitCount == 20)
		{
			bit_canardR = clamp(bit_canardR - dt, -1, 1);
			if (bit_canardR == -1.0)
			{
				bitCount++;
			}
		}
		else if (bitCount == 21)
		{
			bit_canardR = clamp(bit_canardR + dt, -1, 0);
			if (bit_canardR == 0.0)
			{
				printf("右鸭翼自检完成\n");
				bitCount++;
			}
		}
		else if (bitCount == 22)
		{
			bit_rudderL = clamp(bit_rudderL + dt, 0, 1);
			if (bit_rudderL == 1.0)
			{
				bitCount++;
			}
		}
		else if (bitCount == 23)
		{
			bit_rudderL = clamp(bit_rudderL - dt, -1, 1);
			if (bit_rudderL == -1)
			{
				bitCount++;
			}
		}
		else if (bitCount == 24)
		{
			bit_rudderL = clamp(bit_rudderL + dt, -1, 0);
			if (bit_rudderL == 0)
			{
				printf("左垂尾自检完成\n");
				bitCount++;
			}
		}
		else if (bitCount == 25)
		{
			bit_rudderR = clamp(bit_rudderR + dt, 0, 1);
			if (bit_rudderR == 1.0)
			{
				bitCount++;
			}
		}
		else if (bitCount == 26)
		{
			bit_rudderR = clamp(bit_rudderR - dt, -1, 1);
			if (bit_rudderR == -1.0)
			{
				bitCount++;
			}
		}
		else if (bitCount == 27)
		{
			bit_rudderR = clamp(bit_rudderR + dt, -1, 0);
			if (bit_rudderR == 0.0)
			{
				printf("右垂尾自检完成\n");
				bitCount++;
			}
		}
		else if (bitCount == 28)
		{
			bit_canardBrake = clamp(bit_canardBrake + dt, 0, 1);
			if (bit_canardBrake == 1.0)
			{
				bitCount++;
			}
		}
		else if (bitCount == 29)
		{
			bit_canardBrake = clamp(bit_canardBrake - dt, 0, 1);
			if (bit_canardBrake == 0.0)
			{
				printf("鸭翼扰流板自检完成\n");
				bitCount++;
			}
		}
		else if (bitCount == 30)
		{
			bit_airBrake = clamp(bit_airBrake + dt, 0, 1);
			if (bit_airBrake == 1.0)
			{
				bitCount++;
			}
		}
		else if (bitCount == 31)
		{
			bit_airBrake = clamp(bit_airBrake - dt, 0, 1);
			if (bit_airBrake == 0.0)
			{
				bitCount++;
				printf("扰流板自检完成\n");
			}
		}
		else if (bitCount == 32)
		{
			double epsilon = 0.0001;
			if (abs(bitStep32Flag) > epsilon)
			{
				printf("复位中\n");
				bit_flapL = clamp(bit_flapL + dt, 0, m_flapsPosition);
				bit_flapR = clamp(bit_flapR + dt, 0, m_flapsPosition);
				bit_leflapL = clamp(bit_leflapL + dt, 0, m_leFlapsPosition);
				bit_leflapR = clamp(bit_leflapR + dt, 0, m_leFlapsPosition);
				if (m_aileronLeft > 0)
				{
					bit_aileronL = clamp(bit_aileronL + dt, 0, m_aileronLeft);
					bit_aileronR = clamp(bit_aileronR - dt, m_aileronRight, 1);
				}
				else if (m_aileronLeft < 0)
				{
					bit_aileronL = clamp(bit_aileronL - dt, m_aileronLeft, 1);
					bit_aileronR = clamp(bit_aileronR + dt, 0, m_aileronRight);
				}
				if (m_state.getAoaRate() > 0)
				{
					bit_canardL = clamp(bit_canardL + dt, 0, m_state.getAoaRate());
					bit_canardR = clamp(bit_canardR + dt, 0, m_state.getAoaRate());
				}
				else if (m_state.getAoaRate() < 0)
				{
					bit_canardL = clamp(bit_canardL - dt, m_state.getAoaRate(), 1);
					bit_canardR = clamp(bit_canardR - dt, m_state.getAoaRate(), 1);
				}
				if (-m_rudder > 0)
				{
					bit_rudderL = clamp(bit_rudderL + dt, 0, -m_rudder);
					bit_rudderR = clamp(bit_rudderR + dt, 0, -m_rudder);
				}
				else if (-m_rudder < 0)
				{
					bit_rudderL = clamp(bit_rudderL - dt, -m_rudder, 1);
					bit_rudderR = clamp(bit_rudderR - dt, -m_rudder, 1);
				}
				if (m_speedCanardBrakePosition > 0)
				{
					bit_canardBrake = clamp(bit_canardBrake + dt, 0, m_speedCanardBrakePosition);
				}
				else if (m_speedCanardBrakePosition < 0)
				{
					bit_canardBrake = clamp(bit_canardBrake - dt, m_speedCanardBrakePosition, 1);
				}
				if (m_speedBrakePosition > 0)
				{
					bit_airBrake = clamp(bit_airBrake + dt, 0, m_speedBrakePosition);
				}
				else if (m_speedBrakePosition < 0)
				{
					bit_airBrake = clamp(bit_airBrake - dt, m_speedBrakePosition, 1);
				}
				printf("arg09==%.2f\t%.2f\n", bit_flapR, m_flapsPosition);
				printf("arg10==%.2f\t%.2f\n", bit_flapL, m_flapsPosition);
				printf("arg11==%.2f\t%.2f\n", bit_aileronR, m_aileronRight);
				printf("arg12==%.2f\t%.2f\n", bit_aileronL, m_aileronLeft);
				printf("arg13==%.2f\t%.2f\n", bit_leflapR, m_leFlapsPosition);
				printf("arg14==%.2f\t%.2f\n", bit_leflapL, m_leFlapsPosition);
				printf("arg15==%.2f\t%.2f\n", bit_canardR, m_state.getAoaRate());
				printf("arg16==%.2f\t%.2f\n", bit_canardL, m_state.getAoaRate());
				printf("arg17==%.2f\t%.2f\n", bit_rudderR, -m_rudder);
				printf("arg18==%.2f\t%.2f\n", bit_rudderL, -m_rudder);
				printf("arg21==%.2f\t%.2f\n", bit_airBrake, m_speedBrakePosition);
				printf("arg181==%.2f\t%.2f\n", bit_canardBrake, m_speedCanardBrakePosition);
			}
			else
			{
				printf("复位结束\n");
				bitCount++;
			}
		}
		else if (bitCount == 33)
		{
			printf("自检结束\n");
			bitCount++;
		}
		else
		{
			bitTime = 0;
			bitCount = 0;
			fcsBit = false;
		}
	}
	else
	{
		bitTime = 0;
		bitCount = 0;
		fcsBit = false;
	}
}