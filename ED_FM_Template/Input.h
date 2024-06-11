#pragma once
#include "BaseComponent.h"
#include "ED/Actions.h"
#include "maths.h"
//=========================================================================//
//
//		FILE NAME	: Input.h
//		AUTHOR		: Joshua Nelson & Paul Stich
//		Copyright	: Joshua Nelson & Paul Stich
//		DATE		: August 2021
//
//		DESCRIPTION	: Class for Input-handling.  
//					  
//					  
//================================ Includes ===============================//
//=========================================================================//

enum Command
{
	COMMAND_PITCH = 2001,
	COMMAND_ROLL = 2002,

	COMMAND_THROTTLE = 2005,
	COMMAND_THROTTLE2 = 2006,
	COMMAND_THROTTLE_ALL = 2004,

	COMMAND_ENGINES_START = 309,
	COMMAND_ENGINES_STOP = 310,
	COMMAND_ENGINE_START1 = 311,
	COMMAND_ENGINE_START2 = 312,
	COMMAND_ENGINE_STOP1 = 313,
	COMMAND_ENGINE_STOP2 = 314,

	COMMAND_YAW = 2003, //eingefügt 16.02. PJ
	COMMAND_TRIMM_UP = 95,
	COMMAND_TRIMM_DOWN = 96,
	COMMAND_TRIMM_AIL_L = 93,
	COMMAND_TRIMM_AIL_R = 94,
	COMMAND_FLAPS_TOGGLE = 72,
	COMMAND_GEAR_TOGGLE = 68, //68
	COMMAND_GEAR_UP = 430, //
	COMMAND_GEAR_DOWN = 431, //
	COMMAND_BRAKE = 74,//war 2111// Konsole gab 74 und 75 aus bei "W"
	COMMAND_RELEASE_BRAKE = 75, //NEU eingefügt und ein versuch wegen oben
	COMMAND_LEFT_BRAKE = 5162,
	COMMAND_RIGHT_BRAKE = 5163,
	//COMMAND_FLAPS_INCREASE = 10001,
	//COMMAND_FLAPS_DECREASE = 10002,
	COMMAND_FLAPS_DOWN = 145,
	COMMAND_FLAPS_UP = 146,
	COMMAND_AIRBRAKE = 73, // Aus Konsole abgelesen
	COMMAND_AIRBRAKE_EXTEND = 147,
	COMMAND_AIRBRAKE_RETRACT = 148,
	COMMAND_HOOK_TOGGLE = 69,
	COMMAND_NOSEWHEEL_STEERING = 606, //Neu aus Konsole abgelesen
	//COMMAND_NOSEWHEEL_STEERING_ENGAGE = 3133,
	//COMMMAND_NOSEWHEEL_STEERING_DISENGAGE = 3134,
	//COMMAND_NOSEWHEEL_RANGE = 562, //aus Konsole abgelesen
	//COMMAND_STARTER_BUTTON = 3013,
	//COMMAND_THROTTLE_DETEND = 3087,
	COMMAND_BRAKE_CHUTE = 76, //aus der Konsole abgelesen

	//COMMAND_AUTOPILOT_ENG = 389,
	COMMAND_LIGHT_TOGGLE = 328,
	COMMAND_ELECTRIC_SYSTEM = 315,

	COMMAND_ELEV_UP_GO = 195,
	COMMAND_ELEV_UP_STOP = 196,
	COMMAND_ELEV_DOWN_GO = 193,
	COMMAND_ELEV_DOWN_STOP = 194,
	COMMAND_RUD_RIGHT_GO = 203,
	COMMAND_RUD_RIGHT_STOP = 204,
	COMMAND_RUD_LEFT_GO = 201,
	COMMAND_RUD_LEFT_STOP = 202,
	COMMAND_AIL_RIGHT_GO = 199,
	COMMAND_AIL_RIGHT_STOP = 200,
	COMMAND_AIL_LEFT_GO = 197,
	COMMAND_AIL_LEFT_STOP = 198,

	COMMAND_CROSSHAIR_UP = 302,
	COMMAND_CROSSHAIR_DOWN = 303,
	COMMAND_CROSSHAIR_LEFT = 562,
	COMMAND_CROSSHAIR_RIGHT = 301,

	COMMAND_HUD_DARK = 747,

	COMMAND_SIGHT_HORIZONTAL = 2142,//eigentlich 2142
	COMMAND_SIGHT_VERTICAL = 2143,//eigentlich 2143

	COMMAND_WHEELBRAKE_LEFT = 2112,
	COMMAND_WHEELBRAKE_RIGHT = 2113,

	COMMAND_MASTER_AA_1 = 110,
	COMMAND_MASTER_AA_2 = 108,
	COMMAND_MASTER_AA_3 = 107,
	COMMAND_MASTER_AA_4 = 106,
	COMMAND_MASTER_AG = 111,
	COMMAND_MASTER_GUN = 113,
	COMMAND_MASTER_NAVI = 105,

	COMMAND_THROTTLE_UP_GO = 1032,
	COMMAND_THROTTLE_STOP = 1034,
	COMMAND_THROTTLE_DOWN_GO = 1033,

	COMMAND_QNH_UP = 316,
	COMMAND_QNH_DOWN = 317,
	COMMAND_QNH_STOP = 318,

	COMMAND_INST_LIGHT_TGL = 1011,

	COMMAND_WING_FOLD_TOGGLE = 70, // das ist mein CustomCommand als CommandNr.: 689

	COMMAND_REFUELING_DOOR_TGL = 155, //das ist der Standard-Command für 'Refueling Boom'

	COMMAND_LAUNCH_BAR_TGL = 1012,

	COMMAND_TILT_ENGINE_NOZZLE_TGL_PLS = 660, //iCommandPlaneLeftMFD_OSB19	660
	COMMAND_TILT_ENGINE_NOZZLE_TGL_MNS = 661, //iCommandPlaneLeftMFD_OSB20	661

	COMMAND_BAYDOORS_TOGGLE = 655,//iCommandPlaneLeftMFD_OSB14

	COMMAND_AUTOPILOT_ATT_HOLD = 386,//62,
	COMMAND_AUTOPILOT_ALT_HOLD = 389,


	//--------------------------------------

};
enum custom_cmd {
	k_Battery = 10000,
	k_LeftAcGenerator,
	k_RightAcGenerator,
	k_GndPower,

	k_ThrottleAxisTest,//油门位置
	k_EngStartSelector,
	k_EngStartor,//自定义引擎启动输入
	k_LeftThrottorIdle,
	k_RightThrottorIdle,

	//PlaneFlapsStop,//目前屏蔽手动缝翼
	//PlaneFlapsUpHotas,//
	//PlaneFlapsDownHotas,//

	//武器测试用按键
	k_WeaponSelectNext,
	k_WeaponLaunch,

	//mp3播放器相关按键
	k_mp3Player_pauseOrPlay,
	k_mp3Player_next,
	k_mp3Player_last,
	k_mp3Player_fastForward,
	k_mp3Player_fastBack,

	k_Eject,
	k_hudBrt,
	k_UFCPBrt,
	k_UHF_PIT,
	k_VHF_PIT,
	k_DropFlare,
	k_DropChaff,
	k_DropChaffAndFlare,
	k_PlaneHeadingLightOnOff,
	k_PlaneNavLightOnOff,
	k_PlaneAntiCollisionLightOnOff,
	k_P2_to_radarPage,
	k_P2_to_fcsPage,
	k_setRadarStable,
	k_ShowParamList,
	k_NextTargetPnt,
	k_LastTargetPnt,
	//使用自定义舵输入命令，方便限制用户直接输入舵和转向
	k_LeftRudderStart,
	k_LeftRudderStop,
	k_RightRudderStart,
	k_RightRudderStop,
	k_mp3LrcViewTrigger,
	k_mp3PlayMode,
	k_A2A,
	k_A2G,
	k_specialAb,

	k_masterArm,
	k_hmdPwr,
	k_displayBrtMode,

	k_key0,
	k_key1,
	k_key2,
	k_key3,
	k_key4,
	k_key5,
	k_key6,
	k_key7,
	k_key8,
	k_key9,
	k_Enter,
	k_Clear,
	k_L1,
	k_L2,
	k_L3,
	k_L4,
	k_R1,
	k_R2,
	k_R3,
	k_R4,
	k_comm,
	k_Nav,
	k_combat,
	k_AP,
	k_boat,
	k_key_A,
	k_key_B,
	k_key_C,
	k_key_D,
	k_key_E,
	k_key_F,
	k_key_G,
	k_key_H,
	k_key_I,
	k_key_J,
	k_key_K,
	k_key_L,
	k_key_M,
	k_key_N,
	k_key_O,
	k_key_P,
	k_key_Q,
	k_key_R,
	k_key_S,
	k_key_T,
	k_key_U,
	k_key_V,
	k_key_W,
	k_key_X,
	k_key_Y,
	k_key_Z,
	k_key_SP,
	k_key_NEG,
	k_back_a_car,
	P2_to_flirPage,
	STICK_SENSOR_CONTROL_FWD,
	STICK_SENSOR_CONTROL_AFT,
	STICK_SENSOR_CONTROL_LEFT,
	STICK_SENSOR_CONTROL_RIGHT,
	GunMode,
	EmergJettion,
};

enum snd_cmd {
	LaserFire = EmergJettion + 1
};

enum click_cmd {
	WFOV = 3001,
	NFOV,
	Menu,
	Hook,
	Lock,
	Freeze,
	TrackBrk,
	Power,
	FocusOut,
	FocusIn,
	Cage,
	IPHH,
	Polarity,
	SlewLeft,
	SlewRight,
	SlewUp,
	SlewDown,
	GainUp,
	GainDown,
	LevelDown,
	LevelUp,
	AutoGain,
	LaserOn,
	GearLevel,
	Battery,
	LeftAcGenerator,
	RightAcGenerator,
	GndPower,
	StartorSwitch,
	EngineStart_DN,
	EngineStart_UP,
	hudBrt,
	UFCPBrt,
	hmdPower,
	hudColor,
	hmdBrt,
	hmdHudMFCD_change_dayNight,
	UHF_Volume,
	VHF_Volume,
	VOIP,
	antenna,
	TCN_Volume,
	RWR_Volume,
	strobe_light,
	formation_light,
	refuel_light,
	wingtip_light,
	antiCollision_light,
	background_light,
	flood_light,
	flash_light,
	taxi_light,
	ext_tank_pump,
	air_refuel,
	drain_oil_L,
	drain_oil_R,
	masterArm,
	LeftThrottorIdle,
	RightThrottorIdle,
	LaunchBarSw,
	LeftExtinguishing,
	RightExtinguishing,

	EADI_AUTO,
	EADI_SETUP,
	EADI_IND_ON,
	EADI_IND_OFF,
	EADI_YAW_ON,
	EADI_YAW_OFF,
	EADI_ILS,
	FCS_HOLD_ON,
	FCS_HOLD_OFF,
	FCS_AUTO,
	FCS_BIT,
	FCS_RESET,
	FCS_AUTO2,
	FCS_OVER,
	FCS_CAU,
	HSI_FY,
	HSI_MENU,
	HSI_NAV,
	HSI_HDG_MODE,
	HSI_MAP,
	HSI_SCALE_UP,
	HSI_SCALE_DN,
	HSI_WPT,
	BP5_L1,
	BP5_L2,
	BP5_R1,
	BP5_R2,
	BP5_LAST,
	BP5_NEXT,
	WPN_AAMODE,
	WPN_AGMODE,
	WPN_DOOR_ON,
	WPN_DOOR_AUTO,
	ENG_SW,
	MASTER_CAU,
	FIRE_CAU,

	BTN1,
	BTN2,
	BTN3,
	BTN4,
	BTN5,
	BTN6,
	BTN7,
	BTN8,
	BTN9,
	BTN10,
	BTN11,
	BTN12,
	BTN13,
	BTN14,
	BTN15,
	BTN16,
	BTN17,
	BTN18,
	BTN19,
	BTN20,
	BTN21,
	BTN22,
	BTN23,
	BTN24,
	BTN25,
	BTN26,

	key0_up,
	key0_dn,
	key1_up,
	key1_dn,
	key2_up,
	key2_dn,
	key3_up,
	key3_dn,
	key4_up,
	key4_dn,
	key5_up,
	key5_dn,
	key6_up,
	key6_dn,
	key7_up,
	key7_dn,
	key8_up,
	key8_dn,
	key9_up,
	key9_dn,
	Enter_up,
	Enter_dn,
	Clear_up,
	Clear_dn,
	L1_up,
	L1_dn,
	L2_up,
	L2_dn,
	L3_up,
	L3_dn,
	L4_up,
	L4_dn,
	R1_up,
	R1_dn,
	R2_up,
	R2_dn,
	R3_up,
	R3_dn,
	R4_up,
	R4_dn,
	comm_up,
	comm_dn,
	Nav_up,
	Nav_dn,
	combat_up,
	combat_dn,
	AP_up,
	AP_dn,
	boat_up,
	boat_dn,
	key_A,
	key_B,
	key_C,
	key_D,
	key_E,
	key_F,
	key_G,
	key_H,
	key_I,
	key_J,
	key_K,
	key_L,
	key_M,
	key_N,
	key_O,
	key_P,
	key_Q,
	key_R,
	key_S,
	key_T,
	key_U,
	key_V,
	key_W,
	key_X,
	key_Y,
	key_Z,
	key_SP,
	key_NEG,
};

class Input
{

public:

	Input(); //NEU eingefügt, wenn man Input.cpp baut, sonst raus!

	virtual void zeroInit()
	{
		m_pitch = 0.0;
		m_roll = 0.0;
		m_yaw = 0.0;

		m_throttle = -1.0;
		m_throttle2 = -1.0;
		m_throttleAll = -1.0;

		m_l_idle = 0;
		m_r_idle = 0;

		m_trimm_up = 0.0;
		m_trimm_down = 0.0;
		m_trimm_ail_l = 0.0;
		m_trimm_ail_r = 0.0;
		m_flaps_toggle = 0.0;
		m_gear_toggle = 0.0;
		m_gearup = 0.0;
		m_geardown = 0.0;
		m_brake = 0.0;
		m_release_brake = 0.0;
		m_brakeDuration = 0.0;
		m_leftbrake = 0.0;
		m_rightbrake = 0.0;
		m_flapsinc = 0.0;
		m_flapsdec = 0.0;
		m_flapsdown = 0.0;
		m_flapsup = 0.0;
		m_airbrk = 0.0;
		m_airbrkext = 0.0;
		m_airbrkret = 0.0;
		m_hooktgl = 0.0;
		m_nwsteering = 0.0;

		m_autoPilotEng = 0.0;
		m_attAutoPilotEng = 0.0;

		m_light_toggle = 0.0;
		m_electricSystem = 0.0;

		m_crossHUp = 0.0;
		m_crossHDown = 0.0;
		m_crossHLeft = 0.0;
		m_crossHRight = 0.0;

		m_hudDark = 50.0;

		m_sightVertical = 0.0;
		m_sightHorizontal = 0.0;

		m_elev_up_go = 0.0;
		m_elev_up_stop = 0.0;
		m_elev_down_go = 0.0;
		m_elev_down_stop = 0.0;
		m_rudder_right_go = 0.0;
		m_rudder_right_stop = 0.0;
		m_rudder_left_go = 0.0;
		m_rudder_left_stop = 0.0;
		m_ail_right_go = 0.0;
		m_ail_right_stop = 0.0;
		m_ail_left_go = 0.0;
		m_ail_left_stop = 0.0;

		m_elevUP = 0.0;
		m_elevDOWN = 0.0;
		m_rudRIGHT = 0.0;
		m_rudLEFT = 0.0;
		m_ailRIGHT = 0.0;
		m_ailLEFT = 0.0;

		m_brakeLeftWheel = 0.0;
		m_brakeRightWheel = 0.0;

		m_masterAtoA1 = 0.0;
		m_masterAtoA2 = 0.0;
		m_masterAtoA3 = 0.0;
		m_masterAtoA4 = 0.0;
		m_masterAtoG = 0.0;
		m_masterGUN = 0.0;
		m_masterNavi = 0.0;

		m_throttleUP = 0.0;
		m_throttleDOWN = 0.0;
		m_throttleSTOP = 0.0;

		m_throttlePLUS = -1.0;
		m_throttleMINUS = 0.0;
		m_throttleKeysValue = -1.0;
		m_deltaKeysThrottle = 0.0;

		m_finalThrottle1 = 0.0;
		m_finalThrottle2 = 0.0;

		m_qnhUP = 0.0;
		m_qnhDOWN = 0.0;
		m_qnhPlus = 0.0;
		m_qnhMinus = 0.0;
		m_qnhSTOP = 0.0;
		m_retQNH = 101320.0;//statt 101325.0

		m_instLightTgl = 0.0;
		m_wingFoldToggle = 0.0;

		m_refuelingDoorTgl = 0.0;

		m_launchBarToggle = 0.0;

		m_nozzleTiltTgl = 0.0;

		m_bayDoorToggle = 0.0;
	}


	virtual void coldInit()
	{
		zeroInit();
		m_gear_toggle = 1.0;
		m_wingFoldToggle = 1.0;
	}

	virtual void hotInit()
	{
		zeroInit();
		m_engines_start = 1.0;
		m_engine_start1 = 1.0;
		m_engine_start2 = 1.0;
		m_gear_toggle = 1.0;
		m_wingFoldToggle = 0.0;
		m_left_throttle_idle = 1.0;
		m_right_throttle_idle = 1.0;
		m_battery = 1.0;
		m_l_gen = 1.0;
		m_r_gen = 1.0;
	}

	virtual void airborneInit()
	{
		zeroInit();
		m_engines_start = 1.0;
		m_engine_start1 = 1.0;
		m_engine_start2 = 1.0;
		m_electricSystem = 1.0;
		m_wingFoldToggle = 0.0;
		m_left_throttle_idle = 1.0;
		m_right_throttle_idle = 1.0;
	}

	inline const void pitch(double value) //von "inline const double" zu "inline const void
	{
		m_pitch = value;
		//return m_pitch;
	}

	inline const double getPitch() //ob das geht werden wir mal testen...wenn nicht, checken wo ich überall m_pitch zu getPitch verändert habe
	{
		return m_pitch;
	}

	inline const void roll(double value)
	{
		m_roll = value;
		//return m_roll;
	}

	inline const double getRoll()
	{
		return m_roll;
	}

	inline const void throttleAll(double value)
	{
		m_throttleAll = value;
		//return m_throttle;
	}
	inline const void throttleAllUpStep()
	{
		m_throttleAll = clamp(m_throttleAll + 0.4, -1, 1);
	}
	inline const void throttleAllDownStep()
	{
		m_throttleAll = clamp(m_throttleAll - 0.4, -1, 1);
	}
	inline const void throttleUpStep()
	{
		m_throttle = clamp(m_throttle + 0.4, -1, 1);
	}
	inline const void throttleDownStep()
	{
		m_throttle = clamp(m_throttle - 0.4, -1, 1);
	}
	inline const void throttle2UpStep()
	{
		m_throttle2 = clamp(m_throttle2 + 0.4, -1, 1);
	}
	inline const void throttle2DownStep()
	{
		m_throttle2 = clamp(m_throttle2 - 0.4, -1, 1);
	}
	inline const void throttleAllIncrease()
	{
		m_throttleAll = clamp(m_throttleAll + 0.1, -1, 1);
	}
	inline const void throttleAllDecrease()
	{
		m_throttleAll = clamp(m_throttleAll - 0.1, -1, 1);
	}
	inline const void throttle1Increase()
	{
		m_throttle = clamp(m_throttle + 0.1, -1, 1);
	}
	inline const void throttle1Decrease()
	{
		m_throttle = clamp(m_throttle - 0.1, -1, 1);
	}
	inline const void throttle2Increase()
	{
		m_throttle2 = clamp(m_throttle2 + 0.1, -1, 1);
	}
	inline const void throttle2Decrease()
	{
		m_throttle2 = clamp(m_throttle2 - 0.1, -1, 1);
	}
	const void throttleDecision();

	inline const void throttle(double value)
	{
		m_throttle = value;
	}

	inline const double getThrottle()
	{
		return m_finalThrottle1;
	}

	inline const void throttle2(double value)
	{
		m_throttle2 = value;
	}

	inline const double getThrottle2()
	{
		return m_finalThrottle2;
	}

	inline const void yaw(double value)
	{
		m_yaw = value;
		//return m_yaw;
	}

	inline const double getYaw()
	{
		return m_yaw;
	}

	inline const void brakeRight(double value)
	{
		m_brakeRightWheel = value;
	}

	inline const double getBrakeRight()
	{
		return m_brakeRightWheel;
	}

	inline const void brakeLeft(double value)
	{
		m_brakeLeftWheel = value;
	}

	inline const double getBrakeLeft()
	{
		return m_brakeLeftWheel;
	}

	void const throttleUpGO();

	void const throttleDownGO();

	void const throttleSTOP();

	void const ThrottleKeysValue();

	inline const void trimmUP()
	{
		if (m_trimm_up == 0.0)
		{
			m_trimm_up = 0.0004;//war 0.0008
		}
		else if (m_trimm_up != 0.0)
		{
			m_trimm_up += 0.0004;
		}

		//return m_trimm_up;
	}

	inline const double getTrimmUp()
	{
		return m_trimm_up;
	}

	inline const void trimmDOWN()
	{
		if (m_trimm_down == 0.0)
		{
			m_trimm_down = 0.0004;
		}
		else if (m_trimm_down != 0.0)
		{
			m_trimm_down += 0.0004;
		}
		//return m_trimm_down;
	}

	inline const double getTrimmDown()
	{
		return m_trimm_down;
	}

	inline const void trimmAilL()
	{
		if (m_trimm_ail_l == 0.0)
		{
			m_trimm_ail_l = 0.0008;
		}
		else if (m_trimm_ail_l != 0.0)
		{
			m_trimm_ail_l += 0.0008;
		}

		//return m_trimm_ail_l;
	}

	inline const double getTrimmAilL()
	{
		return m_trimm_ail_l;
	}


	inline const void trimmAilR()
	{
		if (m_trimm_ail_r == 0.0)
		{
			m_trimm_ail_r = 0.0008;
		}
		else if (m_trimm_ail_r != 0.0)
		{
			m_trimm_ail_r += 0.0008;
		}
		//return m_trimm_ail_r;
	}

	inline const double getTrimmAilR()
	{
		return m_trimm_ail_r;
	}

	inline const void gearToggle()
	{
		if (m_gear_toggle == 0.0)
		{
			m_gear_toggle = 1.0;
		}
		else
		{
			m_gear_toggle = 0.0;
		}
		//return m_gear_toggle;
	}

	inline const double getGearToggle()
	{
		return m_gear_toggle;
	}

	inline const void gearUP()
	{

		if (m_gearup == 0.0)
		{
			m_gear_toggle = 0.0;
		}
		else
		{
			m_gearup = 0.0;
		}
		//return m_gearup;
	}

	inline const void gearDOWN()
	{
		if (m_geardown == 0.0)
		{
			m_gear_toggle = 1.0;
		}
		else
		{
			m_geardown = 0.0;
		}

		//return m_geardown;
	}

	inline const void brake(double brk = 1)
	{
		m_brake = brk;
		//return m_brake;
	}

	inline const double getBrake()
	{
		return m_brake;
	}

	inline const void releaseBrake()
	{
		if (m_release_brake == 0.0)
		{
			m_release_brake = 1.0;
		}
		else
		{
			m_release_brake = 0.0;
		}
		//return m_release_brake;
	}

	inline const double getReleaseBrake()
	{
		return m_release_brake;
	}

	inline const void flapsDown()
	{
		if (m_flapsdown == 0.0)
		{
			m_flaps_toggle = 1.0;
		}
		else
		{
			m_flapsdown = 0.0;
		}
		//return m_flapsdown;
	}

	inline const void flapsToggle()
	{
		if (m_flaps_toggle == 0.0)
		{
			m_flaps_toggle = 0.5;
		}
		else if (m_flaps_toggle == 0.5)
		{
			m_flaps_toggle = 1.0;
		}
		else
		{
			m_flaps_toggle = 0.0;
		}

		//return m_flaps_toggle;
	}

	inline const double getFlapsToggle()
	{
		return m_flaps_toggle;
	}

	inline const void flapsUp()
	{
		if (m_flapsup == 0.0)
		{
			m_flaps_toggle = 0.0;
		}
		else
		{
			m_flapsup = 0.0;
		}
		//return m_flapsup;
	}

	inline const void airbrake()
	{
		if (m_airbrk == 0.0)
		{
			m_airbrk = 1.0;
		}
		else
		{
			m_airbrk = 0.0;
		}
		//return m_airbrk;
	}

	inline const double getAirbrake()
	{
		return m_airbrk;
	}

	inline const void airbrakeExt()
	{
		if (m_airbrkext == 0.0)
		{
			m_airbrk = 1.0;
		}
		else
		{
			m_airbrkext = 0.0;
		}
		//return m_airbrkext;
	}

	inline const void airbrakeRet()
	{
		if (m_airbrkret == 0.0)
		{
			m_airbrk = 0.0;
		}
		else
		{
			m_airbrkret = 0.0;
		}
		//return m_airbrkret;
	}

	inline const void hookToggle()
	{
		if (m_hooktgl == 0.0)
		{
			m_hooktgl = 1.0;
		}
		else
		{
			m_hooktgl = 0.0;
		}
		//return m_hooktgl;
	}

	inline const double getHookToggle()
	{
		return m_hooktgl;
	}

	inline const void wingFoldToggle()
	{
		if (m_wingFoldToggle == 0.0)
		{
			m_wingFoldToggle = 1.0;
		}
		else
		{
			m_wingFoldToggle = 0.0;
		}
	}

	inline const double getWingFoldToggle()
	{
		return m_wingFoldToggle;
	}

	inline const void nwSteering()
	{
		if (m_nwsteering == 0.0)
		{
			m_nwsteering = 1.0;
		}
		else
		{
			m_nwsteering = 0.0;
		}
		//return m_nwsteering;
	}

	inline const double getNWS()
	{
		return m_nwsteering;
	}
	inline const void nwsLimit(double value)
	{
		m_nwsLimit = value;
		//return m_nwsteering;
	}
	inline const double getNwsLimit()
	{
		return m_nwsLimit;
	}

	inline const void brakeChute()
	{
		if (m_brkchute == 0.0)
		{
			m_brkchute = 1.0;
		}
		else if (m_brkchute == 1.0)
		{
			m_brkchute = 2.0;
		}
		else
		{
			m_brkchute = 0.0;
		}
		//return m_brkchute;
	}

	inline const double getBrkChute()
	{
		return m_brkchute;
	}

	void const enginesUpdate();

	inline const void enginesStart()
	{
		if (m_engines_start == 0.0)
		{
			m_engines_stop = 0.0;
			m_engine_stop1 = 0.0;
			m_engine_stop2 = 0.0;
			m_engine_start1 = 1.0;
			m_engine_start2 = 1.0;
			m_engines_start = 1.0;
		}
		else
		{
			m_engines_start = 0.0;
			m_engine_start1 = 0.0;
			m_engine_start2 = 0.0;
		}
	}

	inline const void engineStart1()
	{
		if (m_engine_start1 == 0.0)
		{
			m_engine_start1 = 1.0;
			m_engine_stop1 = 0.0;
		}
		else
		{
			m_engine_start1 = 0.0;
		}
	}

	inline const void engineStart2()
	{
		if (m_engine_start2 == 0.0)
		{
			m_engine_start2 = 1.0;
			m_engine_stop2 = 0.0;
		}
		else
		{
			m_engine_start2 = 0.0;
		}
	}

	inline const double getEngineStart1()
	{
		return m_engine_start1;
	}

	inline const double getEngineStart2()
	{
		return m_engine_start2;
	}

	inline const void enginesStop()
	{
		if (m_engines_stop == 0.0)
		{
			m_engine_start1 = 0.0;
			m_engine_start2 = 0.0;
			m_engines_start = 0.0;
			m_engine_stop1 = 1.0;
			m_engine_stop2 = 1.0;
			m_engines_stop = 1.0;
		}

		//return m_engine_stop;
	}

	inline const void engineStop1()
	{
		if (m_engine_stop1 == 0.0)
		{
			m_engine_stop1 = 1.0;
			m_engine_start1 = 0.0;
		}

	}

	inline const void engineStop2()
	{
		if (m_engine_stop2 == 0.0)
		{
			m_engine_stop2 = 1.0;
			m_engine_start2 = 0.0;
		}

	}

	inline const double getEngineStop1()
	{
		return m_engine_stop1;
	}

	inline const double getEngineStop2()
	{
		return m_engine_stop2;
	}

	inline const void autoPilotEng()
	{
		if (m_autoPilotEng == 0.0)
		{
			m_autoPilotEng = 1.0;
		}
		else
		{
			m_autoPilotEng = 0.0;
		}

		//return m_autoPilotEng;
	}
	inline void setAutoPilot_ALT(double status)
	{
		m_autoPilotEng = status;
	}

	inline const double getAutoPEng()
	{
		return m_autoPilotEng;
	}

	inline const void autoPilotAttHold()
	{
		if (m_attAutoPilotEng == 0.0)
		{
			m_attAutoPilotEng = 1.0;
		}
		else
		{
			m_attAutoPilotEng = 0.0;
		}
	}
	inline void setAutoPilotAttHold(double status)
	{
		m_attAutoPilotEng = status;
	}

	inline const double getAttAutoPilot()
	{
		return m_attAutoPilotEng;
	}

	inline const void lightToggle()
	{
		if (m_light_toggle == 0.0)
		{
			m_light_toggle = 0.5;
		}
		else if (m_light_toggle == 0.5)
		{
			m_light_toggle = 1.0;
		}
		else
		{
			m_light_toggle = 0.0;
		}

		//return m_light_toggle;
	}

	inline const double getLightToggle()
	{
		return m_light_toggle;
	}

	inline const void instLightTgl()
	{
		if (m_instLightTgl == 0.0)
		{
			m_instLightTgl = 1.0;
		}
		else
		{
			m_instLightTgl = 0.0;
		}
	}

	inline const void ap(double value)
	{
		m_ap = value;
	}

	inline const double getAp()
	{
		return m_ap;
	}

	inline const double getInstLightTgl()
	{
		return m_instLightTgl;
	}

	inline const double getElectricSystem()
	{
		return m_electricSystem;
	}

	inline const void setElectricSystem(int pwr)
	{
		m_electricSystem = pwr;
	}

	inline const void masterAtoA1()
	{
		if (m_masterAtoA1 == 0.0)
		{
			m_masterAtoA1 = 1.0;
			m_masterAtoG = 0.0;
			m_masterNavi = 0.0;
			m_masterGUN = 0.0;
		}

	}

	inline const double getMasterAtoA1()
	{
		return m_masterAtoA1;
	}

	inline const void masterAtoA2()
	{
		if (m_masterAtoA2 == 0.0)
		{
			m_masterAtoA2 = 1.0;
			m_masterAtoG = 0.0;
			m_masterNavi = 0.0;
			m_masterGUN = 0.0;
		}

	}

	inline const double getMasterAtoA2()
	{
		return m_masterAtoA2;
	}

	inline const void masterAtoA3()
	{
		if (m_masterAtoA3 == 0.0)
		{
			m_masterAtoA3 = 1.0;
			m_masterAtoG = 0.0;
			m_masterNavi = 0.0;
			m_masterGUN = 0.0;
		}

	}

	inline const double getMasterAtoA3()
	{
		return m_masterAtoA3;
	}

	inline const void masterAtoA4()
	{
		if (m_masterAtoA4 == 0.0)
		{
			m_masterAtoA4 = 1.0;
			m_masterAtoG = 0.0;
			m_masterNavi = 0.0;
			m_masterGUN = 0.0;
		}

	}

	inline const double getMasterAtoA4()
	{
		return m_masterAtoA4;
	}

	inline const void masterAtoG()
	{
		if (m_masterAtoG == 0.0)
		{
			m_masterAtoG = 1.0;
			m_masterAtoA1 = 0.0;
			m_masterAtoA2 = 0.0;
			m_masterAtoA3 = 0.0;
			m_masterAtoA4 = 0.0;
			m_masterNavi = 0.0;
			m_masterGUN = 0.0;

		}

	}

	inline const double getMasterAtoG()
	{
		return m_masterAtoG;
	}

	inline const void masterGUN()
	{
		if (m_masterGUN == 0.0)
		{
			m_masterGUN = 1.0;
			m_masterAtoA1 = 0.0;
			m_masterAtoA2 = 0.0;
			m_masterAtoA3 = 0.0;
			m_masterAtoA4 = 0.0;
			m_masterNavi = 0.0;
			m_masterAtoG = 0.0;
		}

	}

	inline const double getMasterGUN()
	{
		return m_masterGUN;
	}

	inline const void masterNAVI()
	{
		if (m_masterNavi == 0.0)
		{
			m_masterNavi = 1.0;
			m_masterAtoA1 = 0.0;
			m_masterAtoA2 = 0.0;
			m_masterAtoA3 = 0.0;
			m_masterAtoA4 = 0.0;
			m_masterAtoG = 0.0;
			m_masterGUN = 0.0;
		}

	}

	inline const double getMasterNAVI()
	{
		return m_masterNavi;
	}

	inline const void refuelingDoorTgl()
	{
		if (m_refuelingDoorTgl == 0.0)
		{
			m_refuelingDoorTgl = 1.0;
		}
		else
		{
			m_refuelingDoorTgl = 0.0;
		}
	}

	inline const double getRefuelingDoorTgl()
	{
		return m_refuelingDoorTgl;
	}

	void resetLaunchBar();

	inline const void launchBarToggle()
	{
		m_launchBarToggle = 1 - m_launchBarToggle;
	}

	inline const double getLaunchBarToggle()
	{
		return m_launchBarToggle;
	}

	inline const void tiltEngineNozzleTGLPLUS()
	{
		if (m_nozzleTiltTgl <= 0.5)//if (m_nozzleTiltTgl <= 0.8)
		{
			m_nozzleTiltTgl += 0.1;//m_nozzleTiltTgl += 0.20;
		}
		else
		{
			m_nozzleTiltTgl = 0.6;
		}
	}

	inline const void tiltEngineNozzleTGLMINUS()
	{
		if (m_nozzleTiltTgl >= 0.20)//if (m_nozzleTiltTgl >= 0.40)
		{
			m_nozzleTiltTgl -= 0.1;//m_nozzleTiltTgl -= 0.20;
		}
		else
		{
			m_nozzleTiltTgl = 0.0;
		}
	}

	inline const double getTiltEngineNozzle()
	{
		return m_nozzleTiltTgl;
	}

	inline const void bayDoorsOpenClose()
	{
		if (m_bayDoorToggle == 0.0)
		{
			m_bayDoorToggle = 1.0;
		}
		else
		{
			m_bayDoorToggle = 0.0;
		}
	}

	inline const void leftThrottleIdle(double value) {
		m_l_idle = value;
	}

	inline const void rightThrottleIdle(double value) {
		m_r_idle = value;
	}

	inline const double getBayDoorsToggle()
	{
		return m_bayDoorToggle;
	}

	//----------QNH Einstellung am Altimeter------------
	void const qnhUP();
	void const qnhDOWN();
	void const qnhSTOP();
	void const qnhValue();

	inline const double getQnhValue()
	{
		return m_retQNH;
	}





	//----------Crosshair-Test-Functions-------------

	inline const void hudDark()
	{
		if (m_hudDark == 0.0)
		{
			m_hudDark = 50.0;
		}
	}

	inline const double getHudDark()
	{
		return m_hudDark;
	}

	inline const void sightHorizontal(double value)//eigentlich (double value)
	{
		m_sightHorizontal = value;
	}

	inline const double getSightHorizontal()
	{
		return -(m_sightHorizontal);
	}

	inline const void sightVertical(double value)
	{
		m_sightVertical = value;
	}

	inline const double getSightVertical()
	{
		return m_sightVertical;
	}


	//---------Key Command Functions-----------------
	inline const double elevUpGO()
	{
		if (m_elev_up_go == 0.0)
		{
			m_elev_up_go = 1.0;
		}
		else
		{
			m_elev_up_go = 0.0;
		}
		return m_elev_up_go;
	}

	inline const double elevUpStop()
	{
		if (m_elev_up_stop == 0.0)
		{
			m_elev_up_stop = 1.0;
		}
		else
		{
			m_elev_up_stop = 0.0;
		}
		return m_elev_up_stop;
	}

	inline const double elevDownGO()
	{
		if (m_elev_down_go == 0.0)
		{
			m_elev_down_go = 1.0;
		}
		else
		{
			m_elev_down_go = 0.0;
		}
		return m_elev_down_go;
	}

	inline const double elevDownStop()
	{
		if (m_elev_down_stop == 0.0)
		{
			m_elev_down_stop = 1.0;
		}
		else
		{
			m_elev_down_stop = 0.0;
		}
		return m_elev_down_stop;
	}

	inline const double rudLeftGO()
	{
		if (m_rudder_left_go == 0.0)
		{
			m_rudder_left_go = 1.0;
		}
		else
		{
			m_rudder_left_go = 0.0;
		}
		return m_rudder_left_go;
	}

	inline const double rudLeftStop()
	{
		if (m_rudder_left_stop == 0.0)
		{
			m_rudder_left_stop = 1.0;
		}
		else
		{
			m_rudder_left_stop = 0.0;
		}
		return m_rudder_left_stop;
	}

	inline const double rudRightGO()
	{
		if (m_rudder_right_go == 0.0)
		{
			m_rudder_right_go = 1.0;
		}
		else
		{
			m_rudder_right_go = 0.0;
		}
		return m_rudder_right_go;
	}

	inline const double rudRightStop()
	{
		if (m_rudder_right_stop == 0.0)
		{
			m_rudder_right_stop = 1.0;
		}
		else
		{
			m_rudder_right_stop = 0.0;
		}
		return m_rudder_right_stop;
	}

	inline const double ailRightGO()
	{
		if (m_ail_right_go == 0.0)
		{
			m_ail_right_go = 1.0;
		}
		else
		{
			m_ail_right_go = 0.0;
		}
		return m_ail_right_go;
	}

	inline const double ailRightStop()
	{
		if (m_ail_right_stop == 0.0)
		{
			m_ail_right_stop = 1.0;
		}
		else
		{
			m_ail_right_stop = 0.0;
		}
		return m_ail_right_stop;
	}

	inline const double ailLeftGO()
	{
		if (m_ail_left_go == 0.0)
		{
			m_ail_left_go = 1.0;
		}
		else
		{
			m_ail_left_go = 0.0;
		}
		return m_ail_left_go;
	}

	inline const double ailLeftStop()
	{
		if (m_ail_left_stop == 0.0)
		{
			m_ail_left_stop = 1.0;
		}
		else
		{
			m_ail_left_stop = 0.0;
		}
		return m_ail_left_stop;
	}

	inline const double getBatteryPos()
	{
		return m_battery;
	}
	inline const void setBatteryPos(double value)
	{
		m_battery = value;
	}

	inline const void setBatteryPosTgl()
	{
		m_battery = 1 - m_battery;
	}

	inline const double getLeftGenPos()
	{
		return m_l_gen;
	}
	inline const void setLeftGenPos(double value)
	{
		m_l_gen = value;
	}
	inline const void setLeftGenPosTgl()
	{
		m_l_gen = 1 - m_l_gen;
	}

	inline const double getRightGenPos()
	{
		return m_r_gen;
	}
	inline const void setRightGenPosTgl()
	{
		m_r_gen = 1 - m_r_gen;
	}
	inline const void setRightGenPos(double value)
	{
		m_r_gen = value;
	}
	inline const void setSpecAb(double value)
	{
		if (value == 1.0 && m_specAb_dn)
		{
			this->m_specAb = 0.0;
			return;
		}
		else if (value == 1.0 && !m_specAb)
		{
			this->m_specAb = 1.0;
			m_specAb_dn = true;
		}
		else
		{
			m_specAb_dn = false;
			this->m_specAb = 0.0;
		}
		this->m_specAb = value;
	}
	inline const double getSpecAb()
	{
		return m_specAb;
	}

	inline const double getGndPwrPos()
	{
		return m_gndPwr;
	}
	inline const void setGndPwrPos(double value)
	{
		m_gndPwr = value;
	}
	inline const void setGndPwrPosTgl()
	{
		m_gndPwr = 1 - m_gndPwr;
	}

	inline const double getStartorPos()
	{
		double pos;
		if (m_startor_pos == 0.25)
		{
			pos = 1;
		}
		else if (m_startor_pos == 0.5)
		{
			pos = 2;
		}
		else if (m_startor_pos == 0.75)
		{
			pos = 3;
		}
		else
		{
			pos = 0;
		}
		return pos;
	}
	inline const void setStartorPos(double value)
	{
		m_startor_pos = value;
	}
	inline const void setStartorPosTgl()
	{
		m_startor_pos += 0.25;
		if (m_startor_pos >= 1)
		{
			m_startor_pos = 0;
		}
	}
	inline const double getStartor()
	{
		return m_startor;
	}
	inline const void setStartor(double value)
	{
		m_startor = value;
	}
	inline const void setLeftThrottleIdle(double value)
	{
		m_left_throttle_idle = value;
	}
	inline const void setLeftThrottleIdleTgl()
	{
		m_left_throttle_idle = 1 - m_left_throttle_idle;
	}
	inline const double getLeftThrottleIdle()
	{
		return m_left_throttle_idle;
	}
	inline const void setRightThrottleIdle(double value)
	{
		m_right_throttle_idle = value;
	}
	inline const void setRightThrottleIdleTgl()
	{
		m_right_throttle_idle = 1 - m_right_throttle_idle;
	}
	inline const double getRightThrottleIdle()
	{
		return m_right_throttle_idle;
	}
	inline const void setLaunchBar(double value)
	{
		m_launchBarToggle = value;
	}

	inline const void backACarTgl()
	{
		m_back_a_car = 1 - m_back_a_car;
	}
	inline const double getBackACar()
	{
		return m_back_a_car;
	}
	//----------Input Update-------------------------
	void inputUpdate(double dt);

	//--------Setter-Functions for Key-Commands-------
	void setKeyPitch();
	void setKeyRoll();
	void setKeyYaw();

	//---------Setter-Funktion for Brake/Release Brake-------
	void setBrake();

	inline void setFcsBit(double value)
	{
		m_fcsBit = value;
	}
	inline const double getFcsBit()
	{
		return m_fcsBit;
	}
	/*//--------Getter-Functions for Key-Commands-------
	inline double getElevUpGO();
	inline double getElevUpStop();
	inline double getElevDownGO();
	inline double getElevDownStop();

	inline double getRudRightGO();
	inline double getRudRightStop();
	inline double getRudLeftGO();
	inline double getRudLeftStop();

	inline double getAilRightGO();
	inline double getAilRightStop();
	inline double getAilLeftGO();
	inline double getAilLeftStop();*/



	//die auskommentierten Variablen sind jetzt alle Private	
	//double m_pitch = 0.0;
	//double m_roll = 0.0;
	//double m_yaw = 0.0;
	//double m_throttle = 0.0;
	//double m_trimm_up = 0.0;
	//double m_trimm_down = 0.0;
	//double m_trimm_ail_l = 0.0;
	//double m_trimm_ail_r = 0.0;
	//double m_flaps_toggle = 0.0;
	//double m_gear_toggle = 0.0;
	//double m_gearup = 0.0;
	//double m_geardown = 0.0;
	//double m_brake = 0.0;
	//double m_release_brake = 0.0;
	double m_brakeDuration = 0.0;
	double m_leftbrake = 0.0;
	double m_rightbrake = 0.0;
	double m_flapsinc = 0.0;
	double m_flapsdec = 0.0;
	//double m_flapsdown = 0.0;
	//double m_flapsup = 0.0;
	//double m_airbrk = 0.0;
	//double m_airbrkext = 0.0;
	//double m_airbrkret = 0.0;
	//double m_hooktgl = 0.0;
	//double m_nwsteering = 0.0;
	//double m_nwsteeringeng;
	//double m_nwsteeringdiseng;
	//double m_starterbutton;
	//double m_trhottledet;
	//double m_brkchute = 0.0;
	//double m_engine_start = 0.0;
	//double m_engine_stop = 0.0;
	//double m_autoPilotEng = 0.0;
	//double m_light_toggle = 0.0;

	//double m_elev_up_go = 0.0;
	//double m_elev_up_stop = 0.0;
	//double m_elev_down_go = 0.0;
	//double m_elev_down_stop = 0.0;

	//double m_rudder_right_go = 0.0;
	//double m_rudder_right_stop = 0.0;
	//double m_rudder_left_go = 0.0;
	//double m_rudder_left_stop = 0.0;

	//double m_ail_right_go = 0.0;
	//double m_ail_right_stop = 0.0;
	//double m_ail_left_go = 0.0;
	//double m_ail_left_stop = 0.0;

private:

	double m_pitch = 0.0;
	double m_roll = 0.0;
	double m_yaw = 0.0;

	double m_throttle = 0.0;
	double m_throttle2 = 0.0;
	double m_throttleAll = 0.0;

	double m_l_idle = 0.0;
	double m_r_idle = 0.0;

	double m_trimm_up = 0.0;
	double m_trimm_down = 0.0;
	double m_trimm_ail_l = 0.0;
	double m_trimm_ail_r = 0.0;

	double m_flaps_toggle = 0.0;
	double m_flapsdown = 0.0;
	double m_flapsup = 0.0;

	double m_gear_toggle = 0.0;
	double m_gearup = 0.0;
	double m_geardown = 0.0;

	double m_brake = 0.0;
	double m_release_brake = 0.0;

	double m_airbrk = 0.0;
	double m_airbrkext = 0.0;
	double m_airbrkret = 0.0;

	double m_hooktgl = 0.0;

	double m_brkchute = 0.0;

	double m_nwsteering = 0.0;
	double m_nwsLimit = 0.0;

	double m_autoPilotEng = 0.0;

	double m_light_toggle = 0.0;

	double m_engines_start = 0.0;
	double m_engine_start1 = 0.0;
	double m_engine_start2 = 0.0;
	double m_engines_stop = 0.0;
	double m_engine_stop1 = 0.0;
	double m_engine_stop2 = 0.0;

	double m_electricSystem = 0.0;

	double m_crossHUp = 0.0;
	double m_crossHDown = 0.0;
	double m_crossHLeft = 0.0;
	double m_crossHRight = 0.0;
	double m_hudDark = 0.0;

	double m_sightVertical = 0.0;
	double m_sightHorizontal = 0.0;

	double m_elev_up_go = 0.0;
	double m_elev_up_stop = 0.0;
	double m_elev_down_go = 0.0;
	double m_elev_down_stop = 0.0;

	double m_rudder_right_go = 0.0;
	double m_rudder_right_stop = 0.0;
	double m_rudder_left_go = 0.0;
	double m_rudder_left_stop = 0.0;

	double m_ail_right_go = 0.0;
	double m_ail_right_stop = 0.0;
	double m_ail_left_go = 0.0;
	double m_ail_left_stop = 0.0;

	double m_elevUP = 0.0;
	double m_elevDOWN = 0.0;
	double m_rudRIGHT = 0.0;
	double m_rudLEFT = 0.0;
	double m_ailRIGHT = 0.0;
	double m_ailLEFT = 0.0;

	double m_brakeLeftWheel = 0.0;
	double m_brakeRightWheel = 0.0;

	double m_masterAtoA1 = 0.0;
	double m_masterAtoA2 = 0.0;
	double m_masterAtoA3 = 0.0;
	double m_masterAtoA4 = 0.0;
	double m_masterAtoG = 0.0;
	double m_masterGUN = 0.0;
	double m_masterNavi = 0.0;

	double m_throttleUP = 0.0;
	double m_throttleDOWN = 0.0;
	double m_throttleSTOP = 0.0;
	double m_throttlePLUS = 0.0;
	double m_throttleMINUS = 0.0;
	double m_throttleKeysValue = 0.0;
	double m_deltaKeysThrottle = 0.0;

	double m_finalThrottle1 = 0.0;
	double m_finalThrottle2 = 0.0;

	double m_qnhUP = 0.0;
	double m_qnhDOWN = 0.0;
	double m_qnhSTOP = 0.0;
	double m_retQNH = 0.0;
	double m_qnhPlus = 0.0;
	double m_qnhMinus = 0.0;

	double m_instLightTgl = 0.0;

	double m_wingFoldToggle = 0.0;

	double m_refuelingDoorTgl = 0.0;

	double m_launchBarToggle = 0.0;

	double m_nozzleTiltTgl = 0.0;

	double m_bayDoorToggle = 0.0;

	double m_attAutoPilotEng = 0.0;

	double m_battery = 0.0;
	double m_l_gen = 0.0;
	double m_r_gen = 0.0;
	double m_gndPwr = 0.0;

	double m_startor_pos = 0.0;
	double m_startor = 0.0;

	double m_left_throttle_idle = 0.0;
	double m_right_throttle_idle = 0.0;

	double m_specAb = 0.0;
	bool m_specAb_dn = false;

	double m_ap = 0.0;

	double m_back_a_car = 0.0;
	double m_fcsBit = 0.0;

	bool throttleJoy = false;
};

