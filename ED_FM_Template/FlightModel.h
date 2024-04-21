#pragma once
#include <stdio.h>
#include "Table.h"
#include "Vec3.h"
#include "State.h"
#include "Input.h"
#include "AeroData_1.h"
#include "Engine.h"
#include "Airframe.h"
#include "Fuel_System.h"
#include "AutoPilot.h"
#include "BaseComponent.h"
#include "Timer.h"
//=========================================================================//
//
//		FILE NAME	: FlightModel.cpp
//		AUTHOR		: Joshua Nelson & Paul Stich
//		Copyright	: Joshua Nelson & Paul Stich
//		DATE		: Dezember 2021
//
//		DESCRIPTION	: Every force that is needed for the flight-simulation. 
//					  As well as the Camera-Shaker.
//					  
//================================ Includes ===============================//
//=========================================================================//

class FlightModel
{
public:
	FlightModel(State& state, Input& input, Engine& engine, Airframe& airframe, Fuelsystem& fuelsystem, AutoPilot& autoPilot, avSimpleElectricSystem& elec, EDPARAM& edParam); //Fuelsystem& fuelsystem zugefügt 30Jan22

	virtual void zeroInit();
	virtual void coldInit();
	virtual void hotInit();
	virtual void airborneInit();

	void update(double dt);

	void calculateAeroRotateMoments();

	void L_stab();
	void M_stab();
	void N_stab();

	void lift();
	void drag();
	void sideForce();
	void l_thrustForce();
	void r_thrustForce();
	void update_vector();
	double getVectorPitchL();
	double getVectorPitchR();
	double getVectorYaw();

	void addedThrustCalc();

	void calcZeroLift();

	void calcAeroDeflection();
	void calcLiftFlaps();

	void addedDrag();
	void brokenFlapDrag();

	//-------Stability augmentation systems
	void StabAugSystem();
	inline double getStabAugSystem();

	void pitchStabSystem();
	inline double getPitchStabSysten();
	void yawStabSystem();
	inline double getYawStabSystem();
	void rollStabSystem();
	inline double getRollStabSystem();

	void flightControlSystem();


	void thrustTiltFunction();

	void hoverThrustFunction();

	//----------Cockpit-Shaker--------------------------
	void calculateShake(double& dt);
	inline double getCockpitShake();
	inline const double getWheelChockStatus()
	{
		return m_cockpitAPI.getParamNumber(m_wheelChockHandle);
	}
	//inline void setCockpitShakeModifier(double mod);
	//-------------------------------------------------

	//---------------VEränderung des Schwerpunktes denn com = CenterOfMass---------------
	//const void setForcePressurePoint() const;

	//---------------Addierung von Kräften und Momenten----------------------------
	void addMoment(const Vec3& force, const Vec3& pos);
	void addForce(const Vec3& force, const Vec3& pos);

	//------------------------------------------------------------------------------

	inline const Vec3& getForce() const; //inline u.U. unnötig, da die Funktion nicht direkt hier implementiert wurde; inline könnte weg
	inline const Vec3& getMoment() const; //inline u.U. unnötig, da die Funktion nicht direkt hier implementiert wurde; inline könnte weg
	//inline const Vec3& calculateRotation();

private:
	Vec3 m_moment;
	Vec3 m_force;
	//neu eingefügt für Rotation stabilitäts-Achse zu model-Achse
	Vec3 m_force_boddy;
	State& m_state;
	Input& m_input;
	Engine& m_engine; //neu 21Feb21 // wieder rausgenommen
	Airframe& m_airframe;
	Fuelsystem& m_fuelSystem;
	AutoPilot& m_autoPilot;
	avSimpleElectricSystem& m_elec;
	EDPARAM& m_cockpitAPI;


	//--------------Aerodynamic Values--------------------------------
	double m_scalarVelocity = 0.0;
	double m_scalarVelocitySquared = 0.0;
	double m_aoaDot = 0.0;
	double m_aoaPrevious = 0.0;
	//--------------Thrust related Values-----------------------------
	//double m_thrust = 0.0; //neu 21FEb21 rauskommentiert 28.02.2021
	double m_thinAirMulti = 0.0;
	double m_l_thrustForce = 0.0;
	double m_r_thrustForce = 0.0;
	double m_l_thrustForce_x = 0.0;
	double m_r_thrustForce_x = 0.0;
	double m_l_thrustForce_y = 0.0;
	double m_r_thrustForce_y = 0.0;
	double m_l_thrustForce_z = 0.0;
	double m_r_thrustForce_z = 0.0;
	double m_thrustTilt = 0.0;
	double m_minusThrust = 0.0;
	double m_plusThrust = 0.0;
	double m_eng_vector_pitch_l = 0.0;
	double m_eng_vector_pitch_r = 0.0;
	double m_eng_vector_yaw = 0.0;

	//-------------FlyByWire related variables-----------------------

	double m_pitchAdjustFBW = 0.0;
	double m_pitchReduceAoA = 0.0;
	double m_yawStabBoost = 0.0;
	double m_rollBoost = 0.0;
	double m_stickKicker = 0.0;
	double m_cmaMultiFBW = 0.0;
	double m_cmqMultiFBW = 0.0;


	//---------Stability-augmentation-System--------------------------

	double m_StabAugSys = 0.0;
	double m_pitchStabSystem = 0.0;
	double m_yawStabSystem = 0.0;
	double m_rollStabSystem = 0.0;

	//--------------Hover related sideways/up-down Thrust------------
	double m_pitchHoverThrust = 0.0;
	double m_rollHoverThrust = 0.0;
	double m_yawHoverThrust = 0.0;

	//--------------Misc---------------------------------------------
	//--------------PitchUp and Stall--------------------------------
	double m_pitchup = 0.0;
	double m_stallMult = 0.0;
	double m_zeroLift = 0.0;
	double m_setLiftZero = 0.0;
	double m_stallIndRoll = 0.0;
	double m_stallIndRock = 0.0;
	double m_stallIndDrag = 0.0;
	double m_CLaCorrMulti = 0.0;
	bool m_wingStalling = false;
	double m_noVertTailEff = 0.0;
	bool m_inducedRollingRight = false;
	bool m_inducedRollingLeft = false;
	double m_inducedPitZ = 0.0;
	double m_setZeroCnBeta = 0.0;
	bool m_deactivateWingRock = false;
	double m_CnBetaMult = 0.0;


	//--------------Formula-Parts STAB--------------------------------
	//s : area
	//b : wingspan
	//p : density
	//V : scalar velocity
	double m_k = 0.0; //0.5*p*V^2 * s
	double m_q = 0.0; //0.5*p*V^2 * s * b
	double m_p = 0.0; //0.25*p*V * s * b^2

	//---------------AoA + Beta Correction for WeightOnWheels-----------------------
	double m_corrAoA = 0.0;
	double m_corrBeta = 0.0;

	//----------NEU Thrust to Alt correction variables-----------------------

	double m_l_addThrust = 0.0;
	double m_r_addThrust = 0.0;

	//---------------Coefficients and Derivatives for calculation AERO--------
	//---------------sufix "b" for conversion from stability axis to body axis----
	double Clb_b = 0.0;
	double Clp_b = 0.0;
	double Clr_b = 0.0;
	double Clda_b = 0.0;
	double Cldr_b = 0.0;

	double Cnb_b = 0.0;
	double Cnp_b = 0.0;
	double Cnr_b = 0.0;
	double Cnda_b = 0.0;
	double Cndr_b = 0.0;

	//--------------Stability augmentation System variables for adding to B-Suffix rotated aero-values
	double Cnr_S = 0.0;
	double Clr_S = 0.0;
	double Clp_S = 0.0;

	double m_CnrStab = 0.0;
	double m_CnpStab = 0.0;

	double m_ClrStab = 0.0;
	double m_ClpStab = 0.0;

	double m_CmqStAg = 0.0;
	double m_CmaDOTStAg = 0.0;

	double m_CybStab = 0.0;

	//double m_CnStab = 0.0;

	//------------------rotational formulas to rotate moments around Alpha
	double CosAoA = 0.0;
	double SinusAoA = 0.0;
	double CosAoA2 = 0.0;
	double SinusAoA2 = 0.0;


	//-----------------Formula-Parts DRAG und LIFT----------------------------
	double CDwave = 0.0; // a * (M/Mcrit)^b // neu 18.02.2021
	double M_mcrit = 0.0; // Mach/Mcrit // neu 18.02.2021
	double M_mcrit_b = 0.0; //(Mach/Mcrit)^CON_wdb // neu 18.02.2021
	double CDi = 0.0; //(CL^2/pi * AR * e) neu 18.02.2021
	double CDGear = 0.0; //NEU 05April21 Gear-Down-Drag
	double CDFlaps = 0.0; //NEU 05April21 Flaps-Down-Drag
	double CLFlaps = 0.0;//NEU 05April21 Flaps-Down-Lift
	double CDBrk = 0.0;// NEU 05April21 Brk-Out-Drag
	double CDBrkCanard = 0.0;// NEU 05April21 Brk-Out-Drag
	double CDBrkCht = 0.0;//NEU und Drag Brake-Chute
	double CLblc = 0.0; //NEU BLC Lift-System für die angeströmten Landeklappen
	double CD_OverMach = 0.0;
	double m_cdminADD = 0.0;
	double CD_brFlap = 0.0;
	bool m_flapBroken = false;

	//--------------Calculate aero and calculate deflections---------
	double m_ailDeflection = 0.0;
	double m_rudDeflection = 0.0;
	double m_elevDeflection = 0.0;

	//---------------damage varaiables for parts---------------------
	double m_rWingDamageCL = 0.0;
	double m_rWingDamageCD = 0.0;
	double m_lWingDamageCL = 0.0;
	double m_lWingDamageCD = 0.0;
	double m_ailDamage = 0.0;
	double m_flapDamage = 0.0;
	double m_rSpdBrkDamage = 0.0;
	double m_lSpdBrkDamage = 0.0;
	double m_hStabDamage = 0.0;
	double m_vStabDamage = 0.0;

	//-------------Shaker-Stuff-------------------------------
	double m_cockpitShake = 0.0;
	double m_cockpitShakeModifier = 0.0;

	bool prevGearShake = false;
	bool gearShake = false;
	Timer m_shakeDuration;
	double m_specTime = 0.0;
	double m_spec = 0.0;
	void* m_wheelChockHandle = m_cockpitAPI.getParamHandle("WHEEL_CHOCK_STATUS");
	//-------------TestVariablen !!!wieder auskommentieren!!!--------

	//double TestVar_1 = 0.0;
	//bool TestBoolVar1 = false;




	//--------------Tables from AeroData_1.h------------------------
	//--------------PITCH--------------------------
	Table Cmalpha;
	Table CmalphaNEW;
	Table Cmde;
	Table CmdeNEW;
	Table Cmq;
	Table CmadotNEW; //genau so für jede DATA_Table
	Table CmM;
	Table CmTuck;
	Table CmFlap;
	Table CmFuel;
	Table CmFuelMultiS;
	//------------Pitch stability augmentation system--------------
	Table CmqStAg;
	Table CmaDOTStAg;
	//-----------------DRAG------------------------
	Table CDmin;
	Table CDmach;
	Table CDa;
	Table CDeng;
	Table CDOM;
	Table CDminAD;
	Table CDOK;
	//-------------LIFT----------------------------
	Table CLmax;
	Table CLmach;
	Table CLa;
	Table CLds;
	//Table CLa_FL1;
	Table CLa_FL2;
	Table CL_FlStat;
	//-------------Roll---------------------------
	Table Clb;
	Table Clp;
	Table Clda;
	Table Clr;
	Table Cldr;
	Table ClrStab;
	Table ClpStab;
	//--------------YAW---------------------------
	Table CnbNEW;
	Table Cndr;
	Table Cnr;
	Table Cnp;
	Table Cnda;
	Table CnStab;
	Table Cyb;
	Table Cydr;
	//-------------Thrust------------------------
	//Table PMax;
	//Table PFor;
	Table ThinAM;
	Table AdThrLAlt;
	Table AdThrLAltMulti;
	//------------Misc---------------------------
	//------------FCS---------------------------
	Table FCSPitch;
	Table CmaMulti;
	Table CmqMulti;
	//------------PitchUp and Stall-------------
	Table PitAoA;
	Table PitMult;
	Table StAoA;
	Table StAoAMulti;
	Table CLzero;
	Table CLaCorr;
	Table FinalStallValue;
};


const Vec3& FlightModel::getForce() const
{
	return m_force_boddy;
	//return m_force;
}

const Vec3& FlightModel::getMoment() const
{
	return m_moment;
}


double FlightModel::getCockpitShake()
{
	return m_cockpitShake;
}

double FlightModel::getStabAugSystem()
{
	return m_StabAugSys;
}

double FlightModel::getPitchStabSysten()
{
	return m_pitchStabSystem;
}

double FlightModel::getYawStabSystem()
{
	return m_yawStabSystem;
}

double FlightModel::getRollStabSystem()
{
	return m_rollStabSystem;
}

/*void FlightModel::setCockpitShakeModifier(double mod)
{
	m_cockpitShakeModifier = mod;
	m_cockpitShakeModifier = 1.5;
}*/
