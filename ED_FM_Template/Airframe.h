#pragma once
#include <stdio.h>
#include "Table.h"
#include "Vec3.h"
#include "State.h"
#include "Input.h"
#include "AeroData_1.h"
#include "Engine.h"
#include "Maths.h"
#include "Actuators.h"
#include "BaseComponent.h"
#include "Units.h"
#include "Avionics/avSimpleElectricSystem.h"

//=========================================================================//
//
//		FILE NAME	: Airframe.h
//		AUTHOR		: Joshua Nelson & A4-Comunity-Team & Paul Stich
//		Copyright	: Joshua Nelson & A4-Comunity-Team & Paul Stich
//		DATE		: August 2021
//
//		DESCRIPTION	: All moving parts, gauges, indicators, stick and throttle 
//					  and external animations that are driven from within the EFM.
//					  AND internal damage modell.
//================================ Includes ===============================//
//=========================================================================//

#define DMG_ELEM(v) m_integrityElement[(int)v]

class Airframe
{
public:

	//--------------CatapultState Enum als globales Enum-------------
	enum CatapultState
	{
		ON_CAT_READY,
		ON_CAT_NOT_READY,
		ON_CAT_WAITING,
		ON_CAT_LAUNCHING,
		OFF_CAT
	};
	//------------------------------------------

	//------vorher kam nach "public:" gleich Airframe(State& state, Input& input, Engine& engine);
	Airframe(State& state, Input& input, Engine& engine, avSimpleElectricSystem& elec, EDPARAM& edParam);

	~Airframe();

	//Initialization
	virtual void zeroInit();
	virtual void coldInit();
	virtual void hotInit();
	virtual void airborneInit();

	//---------Setting positions-------------------------------------------------
	//Gear
	//inline void setGearLPosition(double position); //for airstart or ground start-OLD
	//inline void setGearRPosition(double position); //for airstart or ground start-OLD
	//inline void setGearNPosition(double position); //for airstart or ground start-OLD
	inline double setGearLPosition(double dt);
	inline double setGearRPosition(double dt);
	inline double setGearNPosition(double dt);

	//Airbrake
	//inline void setAirbrakePosition(double position);//OLD
	inline double setAirbrakePosition(double dt);
	inline double setCanardAirbrakePosition(double dt);

	//Fuel
	//void addFuel(double fuel); //fuel Funktion fehlt aktuell noch

	//Aerodynamic surfaces
	inline double setAileron(double dt);
	inline double setRudder(double dt);
	inline double setStabilizer(double dt);

	//Aerodynamic Surfaces multi due to reduction (Gear-up)
	void aeroSurfaceMulti(double dt);

	//TEFlaps and LEFlaps
	inline double setFlapsPosition(double dt);

	void autoDriveLeFlapPosition();
	inline double setLEFlapsPosition(double dt);
	inline double getLEFlapPosition() const;

	//Hook
	inline double setHookPosition(double dt);

	inline double setLaunchBarPosition(double dt);

	//Wing-Fold-Mechanics
	inline double setWingFoldMechanic(double dt);
	inline double getWingFoldMechanics() const;

	//BrakeChute
	inline double setChutePositionY(double dt);
	inline double setChutePositionZ(double dt);

	//Engine Nozzle
	double setNozzlePosition(double dt); //verschoben nach Airframe CPP wegen der Größe
	double setNozzle2Position(double dt); //verschoben nach Airframe CPP wegen der Größe

	//intern FC3 Cockpit-Stuff
	double getIntThrottlePosition();
	double getIntThrottlePosition2();
	inline double getInstLight();

	//Steering
	inline double setNoseWheelAngle(double dt);

	//---Masses-----
	inline void setMass(double angle);

	//----------WeightOnWheels-Sensor------------------------
	inline void setWeightOnWheels(double x);
	inline double getWeightOnWheels() const;

	//----------Refueling Door Functions--------------------
	inline double setRefuelingDoor(double dt);
	inline double getRefuelingDoor();

	//---------BayDoors Movement----------------------------
	inline double setBayDoorsPosition(double dt);
	inline double getBayDoorsPosition();

	//--------Electric System-------------------------------
	void electricSystem();
	inline double getACpower();
	inline double getDCpower();
	inline double getBATpower();


	//------Getting and returning positions-------------------
	inline double getGearLPosition() const; //returns gear pos
	inline double getGearRPosition() const; //returns gear pos
	inline double getGearNPosition() const; //returns gear pos

	inline double getGearLLamp(); //Gear-Lamp-Left
	inline double getGearRLamp(); //Gear-Lamp-right
	inline double getGearFLamp(); //Gear-Lamp-front

	inline double getGearLeverLamp();

	inline double getSpeedBrakePosition() const;
	inline double getSpeedCanardBrakePosition() const;

	inline double getHookPosition() const;
	inline double getChutePositionY() const;
	inline double getChutePositionZ() const;
	inline double getMass() const;
	inline double getAileron() const;
	inline double getRudder() const;
	inline double getStabilizer() const;
	inline double getFlapsPosition() const;

	inline double getNozzlePosition() const;
	inline double getNozzle2Position() const;

	double NWSstate();//verschoben nach Airframe CPP

	double BLCsystem();


	//--------Setting/Getting Angles-------------------------
	inline double getNoseWheelAngle() const;

	inline double aileronAngle();
	inline double stabilizerAngle();
	inline double rudderAngle();

	inline double flapsAngle();

	inline double gearLAngle();
	inline double gearRAngle();
	inline double gearNAngle();

	inline double airbrakeAngle();
	inline double noseWheelAngle();

	//-----------Catapult Functions---------------------------
	inline double getCatMoment() const;
	inline double getCatForce() const;

	inline const CatapultState& catapultState() const;
	inline CatapultState& catapultState();
	inline const bool& catapultStateSent() const;
	inline bool& catapultStateSent();
	inline void setCatStateFromKey();
	inline void setCatAngle(double angle);
	void catapultCalculations(double dt);
	void launchBarCalc();
	inline double getLaunchBarPos();

	//---------------UPDATE function--------------------------
	void airframeUpdate(double dt);


	//NEU UpdateBrake-Funktion
	double updateBrake();
	double updateBrakeLeft();
	double updateBrakeRight();

	//Brake-Chute-Funktionen
	double brkChutePosition(); //verschoben nach CPP, daher inline gespart
	double brkChuteSlewZ();
	double brkChuteSlewY();

	//Auto-Pilot-Funktionen
	void autoPilotAltH(double dt);
	inline double getAutoPilotAltH();


	inline double getAltInFeet();

	inline double getEASinKnots();

	//----------QNH Einstellung im Altimeter----------

	double getQNHinThousand();
	double getQNHinHundred();
	double getQNHinTen();
	double getQNHinOne();

	//-----------Crosshair Test Functions-------------
	/*void crossHairHori();
	void crossHairVerti();
	inline double getCrossHairHori();
	inline double getCrossHairVerti();
	void CHforceMovementV(double dt);
	void CHforceMovementH(double dt);
	void moveSightHorizontal();
	void moveSightVertical();
	//inline double getSightHorizontal();//vielleicht überflüssig
	//inline double getSIghtVertical();//vielleicht überflüssig
	*/

	inline double overSpeedGearDamageInd();
	inline double overSpeedFlapDamageInd();
	//---------Overspeed to Damage-Modell---------------
	double osGearDamage();
	double osFlapDamage();

	void resetOSdamage();



	//---------Begin of Damage-Stuff--------------
	enum class Damage
	{
		NOSE_CENTER = 0,
		FRONT = 0,
		Line_NOSE = 0,
		NOSE_LEFT_SIDE = 1,
		NOSE_RIGHT_SIDE = 2,
		COCKPIT = 3,
		CABINA = 3,
		CABIN_LEFT_SIDE = 4,
		CABIN_RIGHT_SIDE = 5,
		CABIN_BOTTOM = 6,
		GUN = 7,
		FRONT_GEAR_BOX = 8,
		GEAR_REAR = 8,
		GEAR_C = 8,
		GEAR_F = 8,
		STOIKA_F = 8,
		FUSELAGE_LEFT_SIDE = 9,
		FUSELAGE_RIGHT_SIDE = 10,
		MAIN = 10,
		LINE_MAIN = 10,
		ENGINE = 11,
		ENGINE_L = 11,
		ENGINE_L_VNUTR = 11,
		ENGINE_L_IN = 11,
		ENGINE_R = 12,
		ENGINE_R_VNUTR = 12,
		ENGINE_R_IN = 12,
		MTG_L_BOTTOM = 13,
		MTG_R_BOTTOM = 14,
		LEFT_GEAR_BOX = 15,
		GEAR_L = 15,
		STOIKA_L = 15,
		RIGHT_GEAR_BOX = 16,
		GEAR_R = 16,
		STOIKA_R = 16,
		MTG_L = 17,
		ENGINE_L_VNESHN = 17,
		ENGINE_L_OUT = 17,
		EWU_L = 17,
		MTG_R = 18,
		ENGINE_R_VNESHN = 18,
		ENGINE_R_OUT = 18,
		EWU_R = 18,
		AIR_BRAKE_L = 19,
		AIR_BRAKE_R = 20,
		WING_L_PART_OUT = 21,
		WING_R_PART_OUT = 22,
		WING_L_OUT = 23,
		WING_R_OUT = 24,
		ELERON_L = 25,
		AILERON_L = 25,
		ELERON_R = 26,
		AILERON_R = 26,
		WING_L_PART_CENTER = 27,
		WING_R_PART_CENTER = 28,
		WING_L_CENTER = 29,
		WING_R_CENTER = 30,
		FLAP_L_OUT = 31,
		FLAP_R_OUT = 32,
		WING_L_PART_IN = 33,
		WING_R_PART_IN = 34,
		WING_L_IN = 35,
		WING_L = 35,
		Line_WING_L = 35,
		WING_R_IN = 36,
		WING_R = 36,
		Line_WING_R = 36,
		FLAP_L_IN = 37,
		FLAP_L = 37,
		FLAP_R_IN = 38,
		FLAP_R = 38,
		FIN_L_TOP = 39,
		KEEL_L_OUT = 39,
		KEEL_OUT = 39,
		FIN_R_TOP = 40,
		KEEL_R_OUT = 40,
		FIN_L_CENTER = 41,
		KEEL_L_CENTER = 41,
		KEEL_CENTER = 41,
		FIN_R_CENTER = 42,
		KEEL_R_CENTER = 42,
		FIN_L_BOTTOM = 43,
		KIL_L = 43,
		Line_KIL_L = 43,
		KEEL = 43,
		KEEL_IN = 43,
		KEEL_L = 43,
		KEEL_L_IN = 43,
		FIN_R_BOTTOM = 44,
		KIL_R = 44,
		Line_KIL_R = 44,
		KEEL_R = 44,
		KEEL_R_IN = 44,
		STABILIZER_L_OUT = 45,
		STABILIZATOR_L_OUT = 45,
		STABILIZER_R_OUT = 46,
		STABILIZATOR_R_OUT = 46,
		STABILIZER_L_IN = 47,
		STABILIZATOR_L = 47,
		STABILIZATOR_L01 = 47,
		Line_STABIL_L = 47,
		STABILIZER_R_IN = 48,
		STABILIZATOR_R = 48,
		STABILIZATOR_R01 = 48,
		Line_STABIL_R = 48,
		ELEVATOR_L_OUT = 49,
		ELEVATOR_R_OUT = 50,
		ELEVATOR_L_IN = 51,
		ELEVATOR_L = 51,
		RV_L = 51,
		ELEVATOR_R_IN = 52,
		ELEVATOR_R = 52,
		RV_R = 52,
		RUDDER_L = 53,
		RN_L = 53,
		RUDDER = 53,
		RUDDER_R = 54,
		RN_R = 54,
		TAIL = 55,
		TAIL_LEFT_SIDE = 56,
		TAIL_RIGHT_SIDE = 57,
		TAIL_BOTTOM = 58,
		NOSE_BOTTOM = 59,
		PWD = 60,
		PITOT = 60,
		FUEL_TANK_F = 61,
		FUEL_TANK_LEFT_SIDE = 61,
		FUEL_TANK_B = 62,
		FUEL_TANK_RIGHT_SIDE = 62,
		ROTOR = 63,
		BLADE_1_IN = 64,
		BLADE_1_CENTER = 65,
		BLADE_1_OUT = 66,
		BLADE_2_IN = 67,
		BLADE_2_CENTER = 68,
		BLADE_2_OUT = 69,
		BLADE_3_IN = 70,
		BLADE_3_CENTER = 71,
		BLADE_3_OUT = 72,
		BLADE_4_IN = 73,
		BLADE_4_CENTER = 74,
		BLADE_4_OUT = 75,
		BLADE_5_IN = 76,
		BLADE_5_CENTER = 77,
		BLADE_5_OUT = 78,
		BLADE_6_IN = 79,
		BLADE_6_CENTER = 80,
		BLADE_6_OUT = 81,
		FUSELAGE_BOTTOM = 82,
		WHEEL_F = 83,
		WHEEL_C = 83,
		WHEEL_REAR = 83,
		WHEEL_L = 84,
		WHEEL_R = 85,
		PYLON1 = 86,
		PYLONL = 86,
		PYLON2 = 87,
		PYLONR = 87,
		PYLON3 = 88,
		PYLON4 = 89,
		CREW_1 = 90,
		CREW_2 = 91,
		CREW_3 = 92,
		CREW_4 = 93,
		ARMOR_NOSE_PLATE_LEFT = 94,
		ARMOR_NOSE_PLATE_RIGHT = 95,
		ARMOR_PLATE_LEFT = 96,
		ARMOR_PLATE_RIGHT = 97,
		HOOK = 98,
		FUSELAGE_TOP = 99,
		TAIL_TOP = 100,
		FLAP_L_CENTER = 101,
		FLAP_R_CENTER = 102,
		ENGINE_1 = 103,
		ENGINE_2 = 104,
		ENGINE_3 = 105,
		ENGINE_4 = 106,
		ENGINE_5 = 107,
		ENGINE_6 = 108,
		ENGINE_7 = 109,
		ENGINE_8 = 110,
		COUNT = 111,
	};

	struct DamageDelta
	{
		Damage m_element;
		float m_delta;
	};

	inline void setIntegrityElement(Damage element, float integrity);
	inline float getIntegrityElement(Damage element);
	inline void setDamageDelta(Damage element, float delta);
	inline bool processDamageStack(Damage& element, float& damage);
	void resetDamage();
	void printDamageState();

	inline float getLWingDamage() const;
	inline float getRWingDamage() const;

	inline float getAileronDamage() const;

	inline float getVertStabDamage() const;
	inline float getRudderDamage() const;

	inline float getHoriStabDamage() const;

	inline float getCompressorDamage() const;
	inline float getCompressorDamageR() const;
	inline float getTurbineDamage() const;
	inline float getTurbineDamageR() const;
	inline float getSpeedbrakeDamage() const;
	inline float getFlapDamage() const;

	double getEngineDamageMult();
	double getEngineDamageMultR();
	//void engineFlameOut();

	inline double getDamageElement(Damage element) const;
	inline const bool fcsIsBiting()
	{
		return fcsBit;
	}
	inline const double getBit_flapL()
	{
		return bit_flapL;
	}
	inline const double getBit_flapR()
	{
		return bit_flapR;
	}
	inline const double getBit_aileronL()
	{
		return bit_aileronL;
	}
	inline const double getBit_aileronR()
	{
		return bit_aileronR;
	}
	inline const double getBit_leflapL()
	{
		return bit_leflapL;
	}
	inline const double getBit_leflapR()
	{
		return bit_leflapR;
	}
	inline const double getBit_canardL()
	{
		return bit_canardL;
	}
	inline const double getBit_canardR()
	{
		return bit_canardR;
	}
	inline const double getBit_rudderL()
	{
		return bit_rudderL;
	}
	inline const double getBit_rudderR()
	{
		return bit_rudderR;
	}
	inline const double getBit_airBrake()
	{
		return bit_airBrake;
	}
	inline const double getBit_canardBrake()
	{
		return bit_canardBrake;
	}
	inline const bool isBitSucc()
	{
		return bitCount == 32;
	}
private:
	enum paramName
	{
		MAIN_GEAR_POS,
		NOSE_GEAR_POS,
		HUD_GEAR,
		HUD_FLAP,
		HUD_BRAKE,
		HUD_CHUTE,
		VS_VIS,
		leftThrottle,
		rightThrottle,
		ROD_LB_POS,
		ROD_RB_POS,
		ENG_DIRECTION,
		ENG_THRUST_SPORT
	};
	Vec3 m_moment;
	Vec3 m_force;
	State& m_state;
	Input& m_input;
	Engine& m_engine;
	avSimpleElectricSystem& m_elec;
	EDPARAM& m_cockpitAPI;
	std::vector<DamageDelta> m_damageStack;

	//Gear
	double m_gearLPosition = 0.0; //0 -> 1
	double m_gearRPosition = 0.0;
	double m_gearNPosition = 0.0;

	double m_gearLLamp = 0.0;
	double m_gearRLamp = 0.0;
	double m_gearFLamp = 0.0;

	double m_gearOversped = 0.0;

	//modification variable for Ground-Start
	double m_gearStart = 0.0;
	double m_gearStartDown = 0.0;

	//aerodynamic surfaces
	double m_flapsPosition = 0.0;

	double m_leFlapsPosition = 0.0;
	double m_autoDriveLeFlaps = 0.0;

	double m_speedBrakePosition = 0.0;
	double m_speedCanardBrakePosition = 0.0;
	double m_hookPosition = 0.0;
	double m_launchBar_pos = 0.0;

	double m_foldWingMechanic = 0.0;

	double m_aileronLeft = 0.0;
	double m_aileronRight = 0.0;
	double m_stabilizer = 0.0;
	double m_rudder = 0.0;

	double m_ailDef = 0.0;
	double m_rudDef = 0.0;

	double m_flapOversped = 0.0;
	double m_flapOSind = 0.0;
	double m_gearOSind = 0.0;

	double m_noseWheelAngle = 0.0;

	double m_nozzlePosition = 0.0;

	double m_nozzle2Position = 0.0;

	double m_int_throttlePos = 0.0;
	double m_int_throttlePos2 = 0.0;

	double m_engDmgMulti = 0.0;

	//--------Brk-Chute Stuff-------------------------
	double m_brakeMoment = 0.0;
	double m_brakeLeft = 0.0;
	double m_brakeRight = 0.0;
	double m_chuteState = 0.0;
	double m_nwsEngage = 0.0;
	double m_chuteSlewY = 0.0;
	double m_chuteSlewZ = 0.0;
	int m_timePassed = 0;
	bool m_chuteDeployed = false;

	//bool m_chuteSlewingZ = false;//neu eingefügt zum Testenfür Rückkehr 0-Position
	//bool m_chuteSlewingY = false;
	//int m_chuteTimeZPassed = 0;
	//int m_chuteTimeYPassed = 0;

	double m_chuteYAxis = 0.0;
	double m_chuteZAxis = 0.0;
	//------------------------------------------------


	double m_bayDoorToggle = 0.0;

	//---------AutoPilot Stuff Alt-Hold--------------
	double m_desiredAlt = 0.0;
	double m_previousAlt = 0.0;
	double m_autPilAltEng = 0.0;
	double m_altHold = 0.0;
	double m_pitchAPadj = 0.0;
	double m_ascHA = 0.0;
	double m_decHA = 0.0;
	bool m_decend = false;
	bool m_acend = false;
	bool m_level = false;
	bool m_acendHoldAngle = false;
	bool m_decendHoldAngle = false;
	//double m_speedPrevious = 0.0;

	//-----------Flaps and Gear Systems and Indicators------------
	double m_blcLift = 0.0;
	double m_flapsLevPos = 0.0;

	double m_gunSwitch = 0.0;

	//-----------Instrument Lights--------------------------------
	double m_instLightOn = 0.0;

	//-----------Speedo-Meter in kn und Mach und Höhe-------------------------
	double m_vMetEAS = 0.0;
	double m_vKnotsEAS = 0.0;
	double m_vKnotsCAS = 0.0;
	double m_vMach = 0.0;
	int m_altInM = 0;
	int m_altInFt = 0;

	//--------------WeightOnWheels-Sensor-------------------------
	double m_weightOnWheels = 0.0;

	//------------Refueling-Door variables-----------------------
	double m_refuelingDoorToggle = 0.0;

	//-----------Electric System Variables-----------------------
	double m_hasACpower = 0.0;
	double m_hasDCpower = 0.0;
	double m_hasBATpower = 0.0;
	double m_batTimer = 0.0;

	//-------neu wegen QNH-----------------------------------------
	int m_qnhVar = 0;
	double m_indQnhThousand = 0.0;
	double m_indQnhHundred = 0.0;
	double m_retIndQnhHundred = 0.0;
	double m_indQnhTen = 0.0;
	double m_indQnhOne = 0.0;

	//------------CrossHair Movement--------------------------------
	/*
	double m_crossHairHori = 0.0;
	double m_crossHairVerti = 0.0;
	double m_vertAccPrevY = 0.0;
	double m_vertAccdotY = 0.0;
	double m_vertAccPrevZ = 0.0;
	double m_vertAccdotZ = 0.0;
	double m_CHforceVerticalDPure = 0.0;
	double m_CHforceVerticalDSmooth = 0.0;
	double m_CHforceHori = 0.0;

	double m_radiusV = 0.0;
	double m_radiusH = 0.0;
	double m_defAngleV = 0.0;
	double m_defAngleVCOS = 0.0;
	double m_defAngleH = 0.0;
	double m_defAngleHCOS = 0.0;
	double m_defAngleVCNen = 0.1;
	double m_angleIndNen = 0.0;
	double m_thetaV = 0.0;
	double m_thetaH = 0.0;
	double m_omegaV = 0.0;
	double m_omegaH = 0.0;
	double m_bulletSpeed = 1050.0;//Geschwindikgeit M61 Kugel m/s
	double m_targetDist = 600.0;//Entfernung zum Ziel fix in m
	double m_centriPetalV = 0.0;

	double m_moveSightV = 0.0;
	double m_moveSightH = 0.0;

	//----Smoothing the movement--------
	double m_smoothingValue = 0.0;
	double m_smoothingValue2 = 0.0;
	double m_smoothingFactor = 0.0;
	bool m_firstCallV = true;
	*/

	//-----------Catapult variables----------------------------------
	CatapultState m_catapultState = OFF_CAT;
	bool m_catStateSent = false;
	double m_catMoment = 0.0;
	double m_catForce = 0.0;
	double m_catMomentVelocity = 0.0;
	double m_catAngle = 0.0;
	double m_prevAccel = 0.0;
	double m_launchBar = 0.0;
	void* m_wheelChockHandle;




	//---------------Actuators--------------------------------------

	Actuator m_actuatorStab; //scheint nur zur optischen "Verschönerung" zu sein, aber egal
	Actuator m_actuatorAil;
	Actuator m_actuatorRud;
	Actuator m_actuatorFlap;
	Actuator m_actuatorLeFlap;
	Actuator m_actuatorGearL;
	Actuator m_actuatorGearR;
	Actuator m_actuatorGearN;
	Actuator m_actuatorAirbrk;
	Actuator m_actuatorAirbrkCanard;
	Actuator m_actuatorHook;
	Actuator m_actuatorLaunchBar;
	Actuator m_actuatorNozzle;
	//Actuator m_actuatorNozzle2;
	Actuator m_actuatorNosewheel;
	Actuator m_actuatorChuteY;
	Actuator m_actuatorChuteZ;
	Actuator m_actuatorWingFold;
	Actuator m_actuatorRefuelingDoor;
	Actuator m_actuatorTiltNozzle;
	Actuator m_actuatorRotorTopClap;
	Actuator m_actuatorRotorBottomClap;
	Actuator m_actuatorWingNozzles;
	Actuator m_actuatorBayDoors;


	//double m_stabilizerZeroForceDeflection = 0.0;

	double m_mass = 1.0;

	float* m_integrityElement;

	double m_scalarVelocity = 0.0;

	//----------Tables--------------
	Table APascend;

	std::map<int, EdParam>params;
	bool fcsBit = false;
	int bitCount = 0;
	double bitTime = 0;
	double bit_flapL = 0.0;
	double bit_flapR = 0.0;
	double bit_leflapL = 0.0;
	double bit_leflapR = 0.0;
	double bit_aileronL = 0.0;
	double bit_aileronR = 0.0;
	double bit_canardL = 0.0;
	double bit_canardR = 0.0;
	double bit_canardBrake = 0.0;
	double bit_rudderL = 0.0;
	double bit_rudderR = 0.0;
	double bit_airBrake = 0.0;


	void bitProgram(double dt);
};

double Airframe::setAileron(double dt)
{
	double input = m_input.getRoll() * m_ailDef; // +m_input.m_rollTrim(); // m_rollTrim kommt noch
	if (!m_elec.isAC())
	{
		input = 0;
	}
	return m_actuatorAil.inputUpdate(input, dt);
}

//Folgend Auskommentierungen zum Testen des Stabilizers, da Aileron und Rudder so funktionieren
double Airframe::setStabilizer(double dt)
{
	double input = m_input.getPitch();//m_input.getPitch(); // +m_stabilizerZeroForceDeflection;
	if (!m_elec.isAC())
	{
		input = 0;
	}
	return m_actuatorStab.inputUpdate(input, dt);

}

double Airframe::setRudder(double dt)
{
	double input = m_input.getYaw() * m_rudDef; // +m_controls.yawTrim(); Yaw-Trim kommt noch
	if (!m_elec.isAC())
	{
		input = 0;
	}
	return m_actuatorRud.inputUpdate(input, dt);
}

double Airframe::setFlapsPosition(double dt)
{
	double input = m_input.getFlapsToggle();
	if (!m_elec.isAC())
	{
		input = 1.0;
	}
	return m_actuatorFlap.inputUpdate(input, dt);
}

double Airframe::setLEFlapsPosition(double dt)
{
	double input = m_autoDriveLeFlaps;
	if (!m_elec.isAC())
	{
		input = 1.0;
	}
	return m_actuatorLeFlap.inputUpdate(input, dt);
}


/*void Airframe::setFlapsPosition(double position) //ALT aber insges. funktionstüchtig
{
	m_flapsPosition = position;
}*/

double Airframe::setGearLPosition(double dt)
{
	double input = m_input.getGearToggle();
	if (!m_elec.isAC())
	{
		if (input < 1)
		{
			input = 1;
		}
		dt *= 0.3;
	}
	return m_actuatorGearL.inputUpdate(input, dt);
}

double Airframe::setGearRPosition(double dt)
{
	double input = m_input.getGearToggle();
	if (!m_elec.isAC())
	{
		if (input < 1)
		{
			input = 1;
		}
		dt *= 0.3;
	}
	return m_actuatorGearR.inputUpdate(input, dt);

}

double Airframe::setGearNPosition(double dt)
{

	double input = m_input.getGearToggle();
	if (!m_elec.isAC())
	{
		if (input < 1)
		{
			input = 1;
		}
		dt *= 0.3;
	}
	return m_actuatorGearN.inputUpdate(input, dt);

}

double Airframe::setAirbrakePosition(double dt)
{
	double input = m_input.getAirbrake();
	if (!m_elec.isAC())
	{
		if (input > 0)
		{
			input = 0;
		}
		dt *= 0.3;
	}
	return m_actuatorAirbrk.inputUpdate(input, dt);
}
double Airframe::setCanardAirbrakePosition(double dt)
{
	double input;
	if ((getIntThrottlePosition() < 0.45 || getIntThrottlePosition2() < 0.45) && getWeightOnWheels() > 0)
	{
		if (m_elec.isAC())
		{
			input = clamp(getWeightOnWheels() + 0.2, 0, 1);
		}
		else
		{
			input = 1;
		}
	}
	else
	{
		input = 0;
	}
	return m_actuatorAirbrkCanard.inputUpdate(input, dt);
}

double Airframe::setHookPosition(double dt)
{
	double input = m_input.getHookToggle();
	if (!m_elec.isAC())
	{
		if (input < 1)
		{
			input = 1;
		}
		dt *= 0.3;
	}
	return m_actuatorHook.inputUpdate(input, dt);
}

double Airframe::setLaunchBarPosition(double dt)
{
	double input = m_launchBar;
	return m_actuatorLaunchBar.inputUpdate(input, dt);
}

double Airframe::setWingFoldMechanic(double dt)
{
	double input = m_input.getWingFoldToggle();
	return m_actuatorWingFold.inputUpdate(input, dt);
}

double Airframe::setChutePositionY(double dt)
{
	double input = brkChuteSlewY();
	return m_actuatorChuteY.inputUpdate(input, dt);
}

double Airframe::setChutePositionZ(double dt)
{
	double input = brkChuteSlewZ();
	return m_actuatorChuteZ.inputUpdate(input, dt);
}
//-----------------------------------------------------


void Airframe::setMass(double mass)
{
	m_mass = mass;
}

double Airframe::setNoseWheelAngle(double dt)
{
	double input = m_input.getYaw();
	input = clamp(input, -1, 1);
	input = m_input.getNwsLimit() > 0.9 ? input : input * 0.6;
	return m_actuatorNosewheel.inputUpdate(input, dt);
}

//---------Neu für WeightOnWheels Sensor---------
void Airframe::setWeightOnWheels(double x)
{
	m_weightOnWheels = x;
}

double Airframe::getWeightOnWheels() const
{
	return m_weightOnWheels;
}
//------------------------------------------------

//-------------Refueling Door Functions-----------

double Airframe::setRefuelingDoor(double dt)
{
	double input = m_input.getRefuelingDoorTgl();
	if (!m_elec.isAC())
	{
		if (input > 0)
		{
			input = 0;
		}
		dt *= 0.3;
	}
	return m_actuatorRefuelingDoor.inputUpdate(input, dt);
}

double Airframe::getRefuelingDoor()
{
	return m_refuelingDoorToggle;
}

//-------------BayDoors Functions----------------
double Airframe::setBayDoorsPosition(double dt)
{
	double input = m_input.getBayDoorsToggle();
	return m_actuatorBayDoors.inputUpdate(input, dt);
}

double Airframe::getBayDoorsPosition()
{
	return m_bayDoorToggle;
}

//---------Getting Positions---------------------
double Airframe::getNoseWheelAngle() const
{
	return -m_noseWheelAngle;
}

double Airframe::getGearLPosition() const
{
	return m_gearLPosition;
}

double Airframe::getGearRPosition() const
{
	return m_gearRPosition;
}

double Airframe::getGearNPosition() const
{
	return m_gearNPosition;
}

// Neu eingefügt den Lampen-Kram zur directen Steuerung der FC-3 Cockpit-Args
double Airframe::getGearLLamp()
{
	if (m_elec.isDC())
	{
		if (getGearLPosition() == 1.0)
		{
			m_gearLLamp = 1.0;
		}
		else
		{
			m_gearLLamp = 0.0;
		}
	}
	else
	{
		m_gearLLamp = 0.0;
	}

	return m_gearLLamp;
}

double Airframe::getGearRLamp()
{
	if (m_elec.isDC())
	{
		if (getGearRPosition() == 1.0)
		{
			m_gearRLamp = 1.0;
		}
		else
		{
			m_gearRLamp = 0.0;
		}
	}
	else
	{
		m_gearRLamp = 0.0;
	}

	return m_gearRLamp;
}

double Airframe::getGearFLamp()
{
	if (m_elec.isDC())
	{

		if (getGearNPosition() == 1.0)
		{
			m_gearFLamp = 1.0;
		}
		else
		{
			m_gearFLamp = 0.0;
		}
	}
	else
	{
		m_gearFLamp = 0.0;
	}

	return m_gearFLamp;
}

double Airframe::getGearLeverLamp()
{
	return m_gearNPosition;
}

//------------Instrument lighting---------------
double Airframe::getInstLight()
{
	if (m_elec.isDC())
	{
		if (m_input.getInstLightTgl() == 1.0)
		{
			m_instLightOn = 1.0;
		}
		else
		{
			m_instLightOn = 0.0;
		}
	}
	else
	{
		m_instLightOn = 0.0;
	}

	return m_instLightOn;
}

double Airframe::getSpeedBrakePosition() const
{
	return m_speedBrakePosition;
}

double Airframe::getSpeedCanardBrakePosition() const
{
	return m_speedCanardBrakePosition;
}

double Airframe::getHookPosition() const
{
	return m_hookPosition;
}

double Airframe::getWingFoldMechanics() const
{
	return m_foldWingMechanic;
}

double Airframe::getChutePositionY() const
{
	return m_chuteYAxis;
}

double Airframe::getChutePositionZ() const
{
	return m_chuteZAxis;
}
double Airframe::overSpeedFlapDamageInd()
{
	if (m_input.getElectricSystem() == 1.0)
	{
		if (osFlapDamage() > 0.0)
		{
			m_flapOSind = 1.0;
		}
		else if (osFlapDamage() == 0.0)
		{
			m_flapOSind = 0.0;
		}
	}
	else
	{
		m_flapOSind = 0.0;
	}

	return m_flapOSind;
}

double Airframe::overSpeedGearDamageInd()
{
	if (m_input.getElectricSystem() == 1.0)
	{
		if (osGearDamage() > 0.0)
		{
			m_gearOSind = 1.0;
		}
		else if (osGearDamage() == 0.0)
		{
			m_gearOSind = 0.0;
		}
	}
	else
	{
		m_gearOSind = 0.0;
	}

	return m_gearOSind;

}
double Airframe::getAileron() const
{
	return m_aileronLeft;
}

double Airframe::getStabilizer() const
{
	return m_stabilizer;
}

double Airframe::getRudder() const
{
	return m_rudder;
}

double Airframe::getFlapsPosition() const
{
	return m_flapsPosition;
}

double Airframe::getLEFlapPosition() const
{
	return m_leFlapsPosition;
}

double Airframe::getNozzlePosition() const
{
	return m_nozzlePosition;
}
double Airframe::getNozzle2Position() const
{
	return m_nozzle2Position;
}

double Airframe::aileronAngle()
{
	return 	m_aileronLeft > 0.0 ? CON_aitnu * m_aileronLeft : -CON_aitnd * m_aileronLeft;
}

double Airframe::stabilizerAngle()
{
	return m_stabilizer > 0.0 ? (-CON_hstdUP) * m_stabilizer : CON_hstdDN * m_stabilizer;
}

double Airframe::rudderAngle()
{
	return m_rudder > 0.0 ? CON_RdDefGUR * m_rudder : -CON_RdDefGUL * m_rudder;
}

//FlapsAngle scheint egal zu sein, da fester Ausschlag 0-50%-100%
double Airframe::flapsAngle()
{
	return m_flapsPosition > 0.0 ? -CON_teft2 * m_flapsPosition : 0.001 * m_flapsPosition;
}

double Airframe::gearLAngle()
{
	return m_gearLPosition > 0.0 ? 1 * m_gearLPosition : 0.0001 * m_gearLPosition;
}

double Airframe::gearRAngle()
{
	return m_gearRPosition > 0.0 ? 1 * m_gearRPosition : 0.0001 * m_gearRPosition;
}

double Airframe::gearNAngle()
{
	return m_gearNPosition > 0.0 ? 1 * m_gearNPosition : 0.0001 * m_gearNPosition;
}

double Airframe::airbrakeAngle()
{
	return m_speedBrakePosition > 0.0 ? CON_BrkAngl * m_speedBrakePosition : 0.0001 * m_speedBrakePosition;
}

double Airframe::noseWheelAngle()
{
	return m_noseWheelAngle > 0.0 ? CON_NSWL * m_noseWheelAngle : -CON_NSWR * m_noseWheelAngle;
}

double Airframe::getMass() const
{
	return m_mass;
}

//--------------value cast functions----------------------
double Airframe::getAltInFeet()
{
	return m_altInM * 3.28084;
}

double Airframe::getEASinKnots()
{
	return m_vKnotsEAS;
}

//------------AutoPilot-Stuff-----------------------------
double Airframe::getAutoPilotAltH()
{
	//return m_pitchAPadj;
	return 0.0;
}

//----------------Electric System-----------------------------
double Airframe::getACpower()
{
	return m_hasACpower;
}

double Airframe::getDCpower()
{
	return m_hasDCpower;
}

double Airframe::getBATpower()
{
	return m_hasBATpower;
}

//---------------Catapult inline Functions--------------------

void Airframe::setCatAngle(double angle)
{
	m_catAngle = angle;
}

const Airframe::CatapultState& Airframe::catapultState() const
{
	return m_catapultState;
}

Airframe::CatapultState& Airframe::catapultState()
{
	return m_catapultState;
}

const bool& Airframe::catapultStateSent() const
{
	return m_catStateSent;
}

bool& Airframe::catapultStateSent()
{
	return m_catStateSent;
}

void Airframe::setCatStateFromKey()
{
	switch (m_catapultState)
	{
	case ON_CAT_NOT_READY:
	case ON_CAT_READY:
	case ON_CAT_WAITING:
		printf("OFF_CAT\n");
		m_catapultState = OFF_CAT;
		break;
	case OFF_CAT:
		printf("ON_CAT_NOT_READY\n");
		m_catapultState = ON_CAT_NOT_READY;
		break;
	}
}

double Airframe::getCatMoment() const
{
	return m_catMoment;
}

double Airframe::getCatForce() const
{
	return m_catForce;
}

double Airframe::getLaunchBarPos()
{
	return m_launchBar_pos;
}



//-------------CrossHair Test-Stuff-------------------------
/*
double Airframe::getCrossHairHori()
{
	return m_crossHairHori;
}

double Airframe::getCrossHairVerti()
{
	return m_crossHairVerti;
}
*/

//----------Damage-Stuff-------------------------------------

double Airframe::getDamageElement(Damage element) const
{
	return DMG_ELEM(element);
}

inline void Airframe::setIntegrityElement(Damage element, float integrity)
{
	m_integrityElement[(int)element] = integrity;
}

inline float Airframe::getIntegrityElement(Damage element)
{
	return m_integrityElement[(int)element];
}

void Airframe::setDamageDelta(Damage element, float delta)
{
	DamageDelta d;
	d.m_delta = delta;
	d.m_element = element;
	m_damageStack.push_back(d);
}

bool Airframe::processDamageStack(Damage& element, float& damage)
{
	if (m_damageStack.empty())
		return false;

	DamageDelta delta = m_damageStack.back();
	m_damageStack.pop_back();


	m_integrityElement[(int)delta.m_element] -= delta.m_delta;
	m_integrityElement[(int)delta.m_element] = clamp(m_integrityElement[(int)delta.m_element], 0.0, 1.0);

	element = delta.m_element;
	damage = m_integrityElement[(int)delta.m_element];

	return true;
}

inline float Airframe::getLWingDamage() const
{
	return (DMG_ELEM(Damage::WING_L_IN) + DMG_ELEM(Damage::WING_L_CENTER) + DMG_ELEM(Damage::WING_L_OUT)) / 3.0;
}

inline float Airframe::getRWingDamage() const
{
	return (DMG_ELEM(Damage::WING_R_IN) + DMG_ELEM(Damage::WING_R_CENTER) + DMG_ELEM(Damage::WING_R_OUT)) / 3.0;
}

inline float Airframe::getAileronDamage() const
{
	return (DMG_ELEM(Damage::AILERON_L) + DMG_ELEM(Damage::AILERON_R)) / 2.0;
}

inline float Airframe::getVertStabDamage() const
{
	return (DMG_ELEM(Damage::FIN_L_TOP) + DMG_ELEM(Damage::FIN_L_BOTTOM)) / 2.0;
}

inline float Airframe::getRudderDamage() const
{
	return DMG_ELEM(Damage::RUDDER);
}

inline float Airframe::getHoriStabDamage() const
{
	return (DMG_ELEM(Damage::STABILIZATOR_L) + DMG_ELEM(Damage::STABILIZATOR_R)) / 2.0;
}

inline float Airframe::getCompressorDamage() const
{
	return 1.0 - clamp(1.0 - DMG_ELEM(Damage::MTG_L), 0.0, 1.0);
}
inline float Airframe::getCompressorDamageR() const
{
	return 1.0 - clamp(1.0 - DMG_ELEM(Damage::MTG_R), 0.0, 1.0);
}
inline float Airframe::getTurbineDamage() const
{
	return 1.0 - clamp(1.0 - DMG_ELEM(Damage::ENGINE_L), 0.0, 1.0);
}

inline float Airframe::getTurbineDamageR() const
{
	return 1.0 - clamp(1.0 - DMG_ELEM(Damage::ENGINE_R), 0.0, 1.0);
}

inline float Airframe::getSpeedbrakeDamage() const
{
	return (DMG_ELEM(Damage::AIR_BRAKE_L) + DMG_ELEM(Damage::AIR_BRAKE_R)) / 2.0;
}
inline float Airframe::getFlapDamage() const
{
	return (DMG_ELEM(Damage::FLAP_L) + DMG_ELEM(Damage::FLAP_R)) / 2.0;
}


