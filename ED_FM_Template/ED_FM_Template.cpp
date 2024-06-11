// ED_FM_Template.cpp : Defines the exported functions for the DLL application.
#include "Vec3.h"
#include "stdafx.h"
#include "ED_FM_Template.h"
#include "ED_FM_Utility.h"
#include "FlightModel.h"
#include "State.h"
#include "devices/hmdDevice.h"
#include "Engine.h"
#include "Fuel_System.h"
#include <Math.h>
#include <stdio.h>
#include <string>
#include "Input.h"
#include "Airframe.h"
#include "BaseComponent.h"
#include "Maths.h"
#include "PID.h"
#include "AutoPilot.h"
#include "APU.h"
#include "CockpitAPI_Declare.h"
#include "LuaVM.h"
#include "LERX.h"
#include "Avionics/avUHF_ARC_164.h"
#include "Avionics/avVHF_ARC_186.h"
#include "Avionics/avILS.h"
#include "devices/ufcp.h"
#include "Avionics/avA11Clock.h"
#include "ED/sound.h"
#include "utils.h"
#include "sounder.h"
//#include "Avionics/avTACAN.h"

//Vec3	common_moment;
//Vec3	common_force;
//Vec3    center_of_gravity;
//Vec3	wind;
//Vec3	velocity_world_cs;
//double  throttle		  = 0;
//double  stick_roll		  = 0;
//double  stick_pitch		  = 0;

//double  internal_fuel     = 0;
//double  fuel_consumption_since_last_time  = 0;
//double  atmosphere_density = 0;
//double  aoa = 0;
//double  speed_of_sound = 320;

//============================= OLD Statics ===================================//
//static Input s_input;
//static State s_state;
//static Engine s_engine(s_state, s_input); //NEU (s_input, s_state)// !!WICHTIG!! 黚erall muss die Reihenfolge Input/State/Engine/Flightmodel sein, NICHT andersrum
//static Fuelsystem s_fuelsystem(s_state, s_input, s_engine);
//static Airframe s_airframe(s_state, s_input, s_engine);
//static FlightModel s_flightModel(s_state, s_input, s_engine, s_airframe); 


//=========================================================================//

//--------------------------NEW Statics-------------------------------------//
static Input* s_input = NULL;
static State* s_state = NULL;
static Engine* s_engine = NULL; //NEU (s_input, s_state)// !!WICHTIG!! 黚erall muss die Reihenfolge Input/State/Engine/Flightmodel sein, NICHT andersrum
static Fuelsystem* s_fuelsystem = NULL;
static Airframe* s_airframe = NULL;
static FlightModel* s_flightModel = NULL;
static PID* s_PID = NULL;
static AutoPilot* s_autoPilot = NULL;
static APU* s_apu = NULL;
static avSimpleElectricSystem* s_elec = NULL;
static EDPARAM* s_edParam = NULL;
static void* CANARD_POS_h = NULL;
static LuaVM* s_luaVM = NULL;
static std::vector<LERX> s_splines;
static double debugLERX;
static HMDDevice* s_hmdDevice;
static avUHF_ARC_164* s_uhfArc164;
static avVHF_ARC_186* s_vhfArc186;
static avILS* s_ils;
static UFCPDevice* s_ufcp;
static avA11Clock* s_clock;
static Sound* s_snd;
static Sounder* sounder;
//static avTACAN* s_tcn;
//------------------------NEW static functions-------------------------------//
static void init(const char* config);
static void cleanup();
//---------------------------------------------------------------------------//

void init(const char* config)
{
	s_luaVM = new LuaVM;

	char configFile[200];
	sprintf_s(configFile, 200, "%s/Effects/J-20_LERXVortex.lua", config);
	s_luaVM->dofile(configFile);
	s_luaVM->getSplines("splines", s_splines);

	s_luaVM->getGlobalNumber("debugLERX", debugLERX);
	//s_luaVM->getTerrainTbl();

	s_edParam = new EDPARAM;
	s_snd = new Sound;
	s_input = new Input;
	s_state = new State;
	s_PID = new PID;
	s_elec = new avSimpleElectricSystem(*s_edParam);
	s_apu = new APU(*s_input, *s_elec, *s_edParam);
	s_engine = new Engine(*s_state, *s_input, *s_elec, *s_apu, *s_edParam);
	s_fuelsystem = new Fuelsystem(*s_state, *s_input, *s_engine, *s_apu, *s_elec, *s_edParam);
	s_airframe = new Airframe(*s_state, *s_input, *s_engine, *s_elec, *s_edParam);
	s_autoPilot = new AutoPilot(*s_state, *s_input, *s_PID, *s_airframe, *s_elec, *s_edParam);
	s_flightModel = new FlightModel(*s_state, *s_input, *s_engine, *s_airframe, *s_fuelsystem, *s_autoPilot, *s_elec, *s_edParam);
	s_hmdDevice = new HMDDevice(*s_edParam, *s_input, *s_elec);
	s_uhfArc164 = new avUHF_ARC_164(*s_edParam, *s_elec);
	s_vhfArc186 = new avVHF_ARC_186(*s_edParam, *s_elec);
	s_ils = new avILS(*s_edParam, *s_elec);
	//s_tcn = new avTACAN(*s_edParam, *s_elec);
	s_ufcp = new UFCPDevice(*s_edParam, *s_elec, *s_ils, *s_input);
	s_clock = new avA11Clock(*s_elec, *s_edParam);
	CANARD_POS_h = s_edParam->getParamHandle("CANARD_POS");
	sounder = new Sounder(*s_snd, *s_engine, *s_state, *s_apu, *s_flightModel, *s_airframe, *s_autoPilot, *s_fuelsystem, *s_input, *s_clock, *s_elec);
}

void cleanup()
{
	delete sounder;
	delete s_snd;
	delete s_input;
	delete s_state;
	delete s_engine;
	delete s_fuelsystem;
	delete s_airframe;
	delete s_flightModel;
	delete s_PID;
	delete s_autoPilot;
	delete s_apu;
	delete s_hmdDevice;
	delete s_ufcp;
	//delete s_tcn;
	delete s_uhfArc164;
	delete s_vhfArc186;
	delete s_ils;
	delete s_clock;
	delete s_elec;
	delete s_edParam;
	delete s_luaVM;
	sounder = nullptr;
	s_snd = NULL;
	//s_tcn = nullptr;
	s_input = NULL;
	s_state = NULL;
	s_engine = NULL;
	s_fuelsystem = NULL;
	s_airframe = NULL;
	s_flightModel = NULL;
	s_PID = NULL;
	s_autoPilot = NULL;
	s_apu = NULL;
	s_hmdDevice = NULL;
	CANARD_POS_h = NULL;
	s_uhfArc164 = NULL;
	s_vhfArc186 = NULL;
	s_ils = NULL;
	s_clock = NULL;
	s_ufcp = NULL;
	s_elec = NULL;
	s_edParam = NULL;
	s_luaVM = NULL;
}

void ed_fm_add_local_force(double& x, double& y, double& z, double& pos_x, double& pos_y, double& pos_z)
{
	x = s_flightModel->getForce().x;
	y = s_flightModel->getForce().y;
	z = s_flightModel->getForce().z;

	pos_x = s_state->m_com.x;
	pos_y = s_state->m_com.y;
	pos_z = s_state->m_com.z;
}

void ed_fm_add_global_force(double& x, double& y, double& z, double& pos_x, double& pos_y, double& pos_z)
{

}

void ed_fm_add_global_moment(double& x, double& y, double& z)
{

}

void ed_fm_add_local_moment(double& x, double& y, double& z)
{
	x = s_flightModel->getMoment().x;
	y = s_flightModel->getMoment().y;
	z = s_flightModel->getMoment().z;
}

void ed_fm_simulate(double dt)
{
	s_edParam->tryInit();
	sounder->update(dt);
	s_state->updateAoaRate(dt);
	s_input->inputUpdate(dt);
	s_flightModel->update(dt);
	s_engine->update(dt);
	s_airframe->airframeUpdate(dt);
	s_fuelsystem->update(dt);
	s_autoPilot->AutoPilotUpdate(dt);
	s_apu->update(dt);
	s_elec->update(dt);
	s_edParam->setParamNumber(CANARD_POS_h, s_state->getAoaRate() * 30 + s_airframe->getSpeedCanardBrakePosition() * -90);
	s_hmdDevice->update(dt);
	s_uhfArc164->update(dt);
	s_vhfArc186->update(dt);
	s_ils->update(dt);
	//s_tcn->update(dt);
	s_clock->update(dt);
	s_ufcp->update(dt);
}

void ed_fm_set_atmosphere(double h,//altitude above sea level
	double t,//current atmosphere temperature , Kelwins
	double a,//speed of sound
	double ro,// atmosphere density
	double p,// atmosphere pressure
	double wind_vx,//components of velocity vector, including turbulence in world coordinate system
	double wind_vy,//components of velocity vector, including turbulence in world coordinate system
	double wind_vz //components of velocity vector, including turbulence in world coordinate system
)
{
	//void State::setCurrentAtmosphere( double temperature, double speedOfSound, double density, double pressure, const Vec3& wind )

	s_state->setCurrentAtmosphere(t, a, ro, p, Vec3(wind_vx, wind_vy, wind_vz));
}
/*
called before simulation to set up your environment for the next step
*/
void ed_fm_set_current_mass_state(double mass,
	double center_of_mass_x,
	double center_of_mass_y,
	double center_of_mass_z,
	double moment_of_inertia_x,
	double moment_of_inertia_y,
	double moment_of_inertia_z
)
{
	s_state->setCOM(Vec3(center_of_mass_x, center_of_mass_y, center_of_mass_z));
	s_state->setWeight(mass);
}
/*
called before simulation to set up your environment for the next step
*/
void ed_fm_set_current_state(double ax,//linear acceleration component in world coordinate system
	double ay,//linear acceleration component in world coordinate system
	double az,//linear acceleration component in world coordinate system
	double vx,//linear velocity component in world coordinate system
	double vy,//linear velocity component in world coordinate system
	double vz,//linear velocity component in world coordinate system
	double px,//center of the body position in world coordinate system
	double py,//center of the body position in world coordinate system
	double pz,//center of the body position in world coordinate system
	double omegadotx,//angular accelearation components in world coordinate system
	double omegadoty,//angular accelearation components in world coordinate system
	double omegadotz,//angular accelearation components in world coordinate system
	double omegax,//angular velocity components in world coordinate system
	double omegay,//angular velocity components in world coordinate system
	double omegaz,//angular velocity components in world coordinate system
	double quaternion_x,//orientation quaternion components in world coordinate system
	double quaternion_y,//orientation quaternion components in world coordinate system
	double quaternion_z,//orientation quaternion components in world coordinate system
	double quaternion_w //orientation quaternion components in world coordinate system
)
{
	s_state->setCurrentStateWorldAxis(
		Vec3(px, py, pz),
		Vec3(vx, vy, vz));
	sounder->setCurrentOrientation(Quaternion(quaternion_x, quaternion_y, quaternion_z, quaternion_w));
	/*double lat = 0.0, lon = 0.0;
	s_luaVM->convertMetersToLatLon(px, pz, lat, lon);
	printf("lat=%.3f\tlon=%.3f\n%s\n%s", lat, lon, DD_to_DMS(lat, 1).c_str(), DD_to_DMS(lon, 0).c_str());*/
}


void ed_fm_set_current_state_body_axis(
	double ax,//linear acceleration component in body coordinate system
	double ay,//linear acceleration component in body coordinate system
	double az,//linear acceleration component in body coordinate system
	double vx,//linear velocity component in body coordinate system
	double vy,//linear velocity component in body coordinate system
	double vz,//linear velocity component in body coordinate system
	double wind_vx,//wind linear velocity component in body coordinate system
	double wind_vy,//wind linear velocity component in body coordinate system
	double wind_vz,//wind linear velocity component in body coordinate system

	double omegadotx,//angular accelearation components in body coordinate system
	double omegadoty,//angular accelearation components in body coordinate system
	double omegadotz,//angular accelearation components in body coordinate system
	double omegax,//angular velocity components in body coordinate system
	double omegay,//angular velocity components in body coordinate system
	double omegaz,//angular velocity components in body coordinate system
	double yaw,  //radians
	double pitch,//radians
	double roll, //radians
	double common_angle_of_attack, //AoA radians
	double common_angle_of_slide   //AoS radians
)
{
	//void State::setCurrentStateBodyAxis(double aoa, double beta, const Vec3& angle, const Vec3& omega, const Vec3& omegaDot, const Vec3& speed, const Vec3& airspeed, const Vec3& acceleration)

	Vec3 velocity(vx, vy, vz);
	Vec3 windVelocity(wind_vx, wind_vy, wind_vz);

	s_state->setCurrentStateBodyAxis(
		common_angle_of_attack,
		common_angle_of_slide,
		Vec3(roll, yaw, pitch),
		Vec3(omegax, omegay, omegaz),
		Vec3(omegadotx, omegadoty, omegadotz),
		velocity,
		velocity - windVelocity,
		Vec3(ax, ay, az)
	);
	if (toDegrees(omegay) > 400 && (s_airframe->getDamageElement(Airframe::Damage::RUDDER_L) == 1 || s_airframe->getDamageElement(Airframe::Damage::RUDDER_R) == 1))
	{
		s_airframe->setDamageDelta(Airframe::Damage::RUDDER_L, 1.0);
		s_airframe->setDamageDelta(Airframe::Damage::RUDDER_R, 1.0);
	}
}

void ed_fm_on_damage(int element, double element_integrity_factor)
{
	//受伤的时候调用
	s_airframe->setIntegrityElement((Airframe::Damage)element, (float)element_integrity_factor);
}

float decodeClick(float& value)
{
	double device_id;
	double normalized = modf(value, &device_id);
	value = normalized * 8.f - 2.f;
	return device_id;
}
/*
input handling
*/
void ed_fm_set_command(int command,
	float value)
{
	if (command > 3000 && command < 4000)
	{
		decodeClick(value);
	}
	switch (command)
	{
	case COMMAND_PITCH:
		s_input->pitch(value);
		break;

	case COMMAND_ROLL:
		s_input->roll(value);
		break;

	case COMMAND_THROTTLE:
		s_input->throttle(-value);
		break;

	case COMMAND_THROTTLE2:
		s_input->throttle2(-value);
		break;

	case COMMAND_THROTTLE_ALL:
		s_input->throttleAll(-value);
		break;
	case iCommandPlaneAUTIncreaseRegime://PageUp
		s_input->throttleAllUpStep();
		break;
	case iCommandPlaneAUTDecreaseRegime://PageDown
		s_input->throttleAllDownStep();
		break;
	case iCommandPlaneAUTIncreaseRegimeLeft://RAlt+PageUp
		s_input->throttleUpStep();
		break;
	case iCommandPlaneAUTDecreaseRegimeLeft://RAlt+PageDown
		s_input->throttleDownStep();
		break;
	case iCommandPlaneAUTIncreaseRegimeRight://RShift+PageUp
		s_input->throttle2UpStep();
		break;
	case iCommandPlaneAUTDecreaseRegimeRight://RShift+PageDown
		s_input->throttle2DownStep();
		break;
	case iCommandThrottleIncrease://Num+
		s_input->throttleAllIncrease();
		break;
	case iCommandThrottleDecrease://Num-
		s_input->throttleAllDecrease();
		break;
	case iCommandThrottle1Increase://RAlt+Num+
		s_input->throttle1Increase();
		break;
	case iCommandThrottle1Decrease://RAlt+Num-
		s_input->throttle1Decrease();
		break;
	case iCommandThrottle2Increase://RShift+Num+
		s_input->throttle2Increase();
		break;
	case iCommandThrottle2Decrease://RShift+Num-
		s_input->throttle2Decrease();
		break;
	case COMMAND_YAW:
		s_input->yaw(value);
		break;

	case COMMAND_TRIMM_UP:
		s_input->trimmUP();
		break;

	case COMMAND_TRIMM_DOWN:
		s_input->trimmDOWN();
		break;

	case COMMAND_TRIMM_AIL_L:
		s_input->trimmAilL();
		break;

	case COMMAND_TRIMM_AIL_R:
		s_input->trimmAilR();
		break;

	case COMMAND_GEAR_TOGGLE:
		s_input->gearToggle();
		break;

	case COMMAND_GEAR_UP:
		s_input->gearUP();
		break;

	case COMMAND_GEAR_DOWN:
		s_input->gearDOWN();
		break;

	case COMMAND_BRAKE:
		s_input->brake();
		break;
	case iCommandWheelBrake:
		s_input->brake(value);
		break;
	case COMMAND_RELEASE_BRAKE:
		s_input->releaseBrake();
		break;

	case COMMAND_LEFT_BRAKE:
		s_input->m_leftbrake = value;
		break;

	case COMMAND_RIGHT_BRAKE:
		s_input->m_rightbrake = value;
		break;

	case COMMAND_FLAPS_DOWN:
		s_input->flapsDown();
		break;

	case COMMAND_FLAPS_UP:
		s_input->flapsUp();
		break;

	case COMMAND_FLAPS_TOGGLE:
		s_input->flapsToggle();
		break;

	case COMMAND_AIRBRAKE:
		s_input->airbrake();
		break;

	case COMMAND_AIRBRAKE_EXTEND:
		s_input->airbrakeExt();
		break;

	case COMMAND_AIRBRAKE_RETRACT:
		s_input->airbrakeRet();
		break;

	case COMMAND_HOOK_TOGGLE:
		s_input->hookToggle();
		break;

	case COMMAND_WING_FOLD_TOGGLE:
		s_input->wingFoldToggle();
		break;

	case COMMAND_NOSEWHEEL_STEERING:
		s_input->nwSteering();
		break;
	case iCommandPlane_HOTAS_NoseWheelSteeringButton:
		s_input->nwsLimit(value);
		break;
	case COMMAND_BRAKE_CHUTE:
		s_input->brakeChute();
		break;

	case COMMAND_ENGINES_START:
		s_input->enginesStart();
		break;

	case COMMAND_ENGINES_STOP:
		s_input->enginesStop();
		break;

	case COMMAND_ENGINE_START1:
		s_input->engineStart1();
		break;

	case COMMAND_ENGINE_START2:
		s_input->engineStart2();
		break;

	case COMMAND_ENGINE_STOP1:
		s_input->engineStop1();
		break;

	case COMMAND_ENGINE_STOP2:
		s_input->engineStop2();
		break;
	case COMMAND_AUTOPILOT_ALT_HOLD:
		//s_input->autoPilotEng();
		break;

	case COMMAND_LIGHT_TOGGLE:
		s_input->lightToggle();
		break;

		/*case COMMAND_THROTTLE_UP_GO:
			s_input->throttleUpGO();
			break;
		case COMMAND_THROTTLE_STOP:
			s_input->throttleSTOP();
			break;
		case COMMAND_THROTTLE_DOWN_GO:
			s_input->throttleDownGO();
			break;*/

	case COMMAND_ELEV_UP_GO:
		s_input->elevUpGO();
		break;

	case COMMAND_ELEV_UP_STOP:
		s_input->elevUpStop();
		break;

	case COMMAND_ELEV_DOWN_GO:
		s_input->elevDownGO();
		break;

	case COMMAND_ELEV_DOWN_STOP:
		s_input->elevDownStop();
		break;

	case COMMAND_RUD_LEFT_GO:
		s_input->rudLeftGO();// m_rudder_left_go;
		break;

	case COMMAND_RUD_LEFT_STOP:
		s_input->rudLeftStop();//m_rudder_left_stop;
		break;

	case COMMAND_RUD_RIGHT_GO:
		s_input->rudRightGO();// m_rudder_right_go;
		break;

	case COMMAND_RUD_RIGHT_STOP:
		s_input->rudRightStop();// m_rudder_right_stop;
		break;

	case COMMAND_AIL_RIGHT_GO:
		s_input->ailRightGO();// m_ail_right_go;
		break;

	case COMMAND_AIL_RIGHT_STOP:
		s_input->ailRightStop();// m_ail_right_stop;
		break;

	case COMMAND_AIL_LEFT_GO:
		s_input->ailLeftGO();// m_ail_left_go;
		break;

	case COMMAND_AIL_LEFT_STOP:
		s_input->ailLeftStop();// m_ail_left_stop;
		break;

	case COMMAND_HUD_DARK:
		s_input->hudDark();
		break;
	case COMMAND_WHEELBRAKE_LEFT:
		s_input->brakeLeft(value);
		break;

	case COMMAND_WHEELBRAKE_RIGHT:
		s_input->brakeRight(value);
		break;

		/*case COMMAND_NOSEWHEEL_STEERING_ENGAGE:
			s_input->m_nwsteeringeng = value;
			break;
		case COMMMAND_NOSEWHEEL_STEERING_DISENGAGE:
			s_input->m_nwsteeringdiseng = value;
			break;
		case COMMAND_STARTER_BUTTON:
			s_input->m_starterbutton = value;
			break;
		case COMMAND_THROTTLE_DETEND:
			s_input->m_starterbutton = value;
			break;*/
	case COMMAND_MASTER_AA_1:
		s_input->masterAtoA1();
		break;

	case COMMAND_MASTER_AA_2:
		s_input->masterAtoA2();
		break;

	case COMMAND_MASTER_AA_3:
		s_input->masterAtoA3();
		break;

	case COMMAND_MASTER_AA_4:
		s_input->masterAtoA4();
		break;

	case COMMAND_MASTER_AG:
		s_input->masterAtoG();
		break;

	case COMMAND_MASTER_NAVI:
		s_input->masterNAVI();
		break;

	case COMMAND_MASTER_GUN:
		s_input->masterGUN();
		break;

	case COMMAND_QNH_UP:
		s_input->qnhUP();
		break;

	case COMMAND_QNH_DOWN:
		s_input->qnhDOWN();
		break;

	case COMMAND_QNH_STOP:
		s_input->qnhSTOP();
		break;

	case COMMAND_INST_LIGHT_TGL:
		s_input->instLightTgl();
		break;
	case iCommandPlaneAutopilotOverrideOn:
		s_input->ap(1);
		break;
	case iCommandPlaneAutopilotOverrideOff:
		s_input->ap(0);
		break;
	case COMMAND_AUTOPILOT_ATT_HOLD:
		//s_input->autoPilotAttHold();
		break;

	case COMMAND_REFUELING_DOOR_TGL:
		s_input->refuelingDoorTgl();
		break;
	case Battery:
	case k_Battery:
	case LeftAcGenerator:
	case k_LeftAcGenerator:
	case RightAcGenerator:
	case k_RightAcGenerator:
	case GndPower:
	case k_GndPower:
		s_elec->setCommand(command, value);
		break;
	case StartorSwitch:
		s_input->setStartorPos(value);
		break;
	case k_EngStartSelector:
		s_input->setStartorPosTgl();
	case EngineStart_DN:
	case EngineStart_UP:
	case k_EngStartor:
		s_input->setStartor(value);
		break;
	case LeftThrottorIdle:
		s_input->setLeftThrottleIdle(value);
		break;
	case k_LeftThrottorIdle:
		s_input->setLeftThrottleIdleTgl();
		break;
	case RightThrottorIdle:
		s_input->setRightThrottleIdle(value);
		break;
	case k_RightThrottorIdle:
		s_input->setRightThrottleIdleTgl();
		break;
	case iCommandPlane_P_51_WarEmergencyPower:
		s_input->setSpecAb(value);
		break;
	case LaunchBarSw:
		s_input->setLaunchBar(value);
		break;
	case k_back_a_car:
		s_input->backACarTgl();
		break;
	case hmdBrt:
	case iServiceInformAboutUserHAngle:
	case iServiceInformAboutUserVAngle:
		s_hmdDevice->setCommand(command, value);
		break;
	case k_UHF_PIT:
	case UHF_Volume:
		s_uhfArc164->setCommand(command, value);
		break;
	case k_VHF_PIT:
	case VHF_Volume:
		s_vhfArc186->setCommand(command, value);
		break;
	case TCN_Volume:
		//s_tcn->setCommand(command, value);
		break;
	case key0_up:
	case key0_dn:
	case key1_up:
	case key1_dn:
	case key2_up:
	case key2_dn:
	case key3_up:
	case key3_dn:
	case key4_up:
	case key4_dn:
	case key5_up:
	case key5_dn:
	case key6_up:
	case key6_dn:
	case key7_up:
	case key7_dn:
	case key8_up:
	case key8_dn:
	case key9_up:
	case key9_dn:
	case Enter_up:
	case Enter_dn:
	case Clear_up:
	case Clear_dn:
	case L1_up:
	case L1_dn:
	case R1_up:
	case R1_dn:
	case L2_up:
	case L2_dn:
	case R2_up:
	case R2_dn:
	case L3_up:
	case L3_dn:
	case R3_up:
	case R3_dn:
	case L4_up:
	case L4_dn:
	case R4_up:
	case R4_dn:
	case comm_up:
	case comm_dn:
	case Nav_up:
	case Nav_dn:
	case combat_up:
	case combat_dn:
	case AP_up:
	case AP_dn:
	case boat_up:
	case boat_dn:
	case UFCPBrt:
	case key_A:
	case key_B:
	case key_C:
	case key_D:
	case key_E:
	case key_F:
	case key_G:
	case key_H:
	case key_I:
	case key_J:
	case key_K:
	case key_L:
	case key_M:
	case key_N:
	case key_O:
	case key_P:
	case key_Q:
	case key_R:
	case key_S:
	case key_T:
	case key_U:
	case key_V:
	case key_W:
	case key_X:
	case key_Y:
	case key_Z:
	case key_SP:
	case key_NEG:
		s_ufcp->setCommand(command, value);
		break;
	case FCS_BIT:
		s_input->setFcsBit(value);
		break;
	case LeftExtinguishing:
		s_engine->useLeftExtinguishing();
		break;
	case RightExtinguishing:
		s_engine->useRightExtinguishing();
		break;
	case iCommandGroundPowerAC:
		s_elec->setCommand(command, value);
		break;
	default:
		break;
		//printf("number %d: %f\n", command, value); //neu eingef黦t um "unbekannte" Kommandos zur Konsole auszugeben
	}
}
/*
	Mass handling

	will be called  after ed_fm_simulate :
	you should collect mass changes in ed_fm_simulate

	double delta_mass = 0;
	double x = 0;
	double y = 0;
	double z = 0;
	double piece_of_mass_MOI_x = 0;
	double piece_of_mass_MOI_y = 0;
	double piece_of_mass_MOI_z = 0;

	//
	while (ed_fm_change_mass(delta_mass,x,y,z,piece_of_mass_MOI_x,piece_of_mass_MOI_y,piece_of_mass_MOI_z))
	{
	//internal DCS calculations for changing mass, center of gravity,  and moments of inertia
	}
*/
bool ed_fm_change_mass(double& delta_mass,
	double& delta_mass_pos_x,
	double& delta_mass_pos_y,
	double& delta_mass_pos_z,
	double& delta_mass_moment_of_inertia_x,
	double& delta_mass_moment_of_inertia_y,
	double& delta_mass_moment_of_inertia_z
)
{
	Fuelsystem::Tank tank = s_fuelsystem->getSelectedTank();//DAb hier Change Mass geht los
	if (tank == Fuelsystem::NUMBER_OF_TANKS)
	{
		s_fuelsystem->setSelectedTank(Fuelsystem::INTERNAL);
		return false;
	}

	Vec3 pos = s_fuelsystem->getFuelPos(tank);
	//-------Vec3 r = pos - s_state->getCOM();---------------------------

	delta_mass = s_fuelsystem->getFuelQtyDelta(tank);
	s_fuelsystem->setFuelPrevious(tank);

	//-----------printf( "Tank %d, Pos: %lf, %lf, %lf, dm: %lf\n", tank, pos.x, pos.y, pos.z, delta_mass );---------------

	delta_mass_pos_x = pos.x;
	delta_mass_pos_y = pos.y;
	delta_mass_pos_z = pos.z;

	s_fuelsystem->setSelectedTank((Fuelsystem::Tank)((int)tank + 1));
	return true;

	//return false;


	//if (fuel_consumption_since_last_time > 0)
	//{
	//	delta_mass		 = fuel_consumption_since_last_time;
	//	delta_mass_pos_x = -1->0;
	//	delta_mass_pos_y =  1.0;
	//	delta_mass_pos_z =  0;

	//	delta_mass_moment_of_inertia_x	= 0;
	//	delta_mass_moment_of_inertia_y	= 0;
	//	delta_mass_moment_of_inertia_z	= 0;

	//	fuel_consumption_since_last_time = 0; // set it 0 to avoid infinite loop, because it called in cycle 
	//	// better to use stack like structure for mass changing 
	//	return true;
	//}
	//else 
	//{
	//	return false;
	//}
}
/*
	set internal fuel volume , init function, called on object creation and for refueling ,
	you should distribute it inside at different fuel tanks
*/
void   ed_fm_set_internal_fuel(double fuel)
{
	s_fuelsystem->setInternal(fuel);
	//internal_fuel = fuel;
}
/*
	get internal fuel volume
*/

//---------------NEU EINGEF蹽T---------------------
void ed_fm_refueling_add_fuel(double fuel)
{
	//printf("Add fuel: %lf\n", fuel);
	s_fuelsystem->addFuel(fuel);
}
//-----------------NEU EINGEF蹽T ENDE----------------

double ed_fm_get_internal_fuel()
{
	//return 1.0;
	return s_fuelsystem->getFuelQtyInternal();
}
/*
	set external fuel volume for each payload station , called for weapon init and on reload
*/
//lediglich 膎derung in der {} f黵 StationToTank

void  ed_fm_set_external_fuel(int	 station,
	double fuel,
	double x,
	double y,
	double z)
{
	Fuelsystem::Tank tank = s_fuelsystem->stationToTank(station);
	s_fuelsystem->setFuelQty(tank, Vec3(x, y, z), fuel);
}

//Das folgende ist das Original, davor ist meine schlechte F鋖schung
/*{
	s_fuelsystem->setFuelQty((Fuelsystem::Tank)(station + 1), Vec3(x, y, z), fuel);
}*/

/*
	get external fuel volume
*/
double ed_fm_get_external_fuel()
{
	//return 0;
	return s_fuelsystem->getFuelQtyExternal();
}

/*ACHTUNG-ACHTUNG Ver鋘derungen im Anmarsch: Ab DCS V2.7 muss ed_fm_set_draw_args und
ed_fm_set_fc3_cockpit_draw_args wie folgt ver鋘dert werden


NEU!! void ed_fm_set_fc3_cockpit_draw_args_v2(float* data, size_t size)
NEU!! {
NEU!!	data[YOUR_ARGUMENT] = WHAT_YOU_WANT;
NEU!! }
NEU!!
NEU!! Compared to
ALT!! void ed_fm_set_fc3_cockpit_draw_args(EdDrawArgument* drawargs, size_t size)
ALT!! {
ALT!!	drawargs[YOUR_ARGUMENT].f = WHAT_YOU_WANT;
ALT!! }

in der ed_fm_template.h m黶sen auch 膎derungen vorgenommen werden in:

void ed_fm_set_fc3_cockpit_draw_args_v2(float* data, size_t size)
*/


void ed_fm_set_draw_args_v2(float* data, size_t size)
{
	//data[28]   = (float)throttle;
	//data[29]   = (float)throttle;

	if (size > 616)
	{
		data[611] = data[0];
		data[614] = data[3];
		data[616] = data[5];
	}
	data[0] = s_airframe->getGearNPosition();//Nosewheel Position前起落架
	data[2] = s_airframe->getNoseWheelAngle();//Nosewheel Angle +/- 60? 鼻轮转向角度
	data[3] = s_airframe->getGearRPosition();//Right Gear Position 右起落架
	data[5] = s_airframe->getGearLPosition();//Left Gear Position 左起落架
	if (s_airframe->fcsIsBiting())
	{
		data[9] = s_airframe->getBit_flapR();//right flap Versuch 右襟翼
		data[10] = s_airframe->getBit_flapL();//left flap Versuch 左襟翼
		data[11] = s_airframe->getBit_aileronR();//right aileron 右副翼
		data[12] = -s_airframe->getBit_aileronL();//left Aileron 左副翼
		data[13] = s_airframe->getBit_leflapR();//右前缘襟翼
		data[14] = s_airframe->getBit_leflapL();//左前缘襟翼
		data[15] = s_airframe->getBit_canardR(); //right elevator ist standard f黵 ein Leitwerk 右鸭翼
		data[16] = s_airframe->getBit_canardL();//left elevator 左鸭翼
		data[17] = -s_airframe->getBit_rudderR(); //rudder 右垂尾
		data[18] = -s_airframe->getBit_rudderL();//rudder nr. 2 左垂尾
		data[21] = s_airframe->getBit_airBrake(); //扰流板
		data[181] = s_airframe->getBit_canardBrake();//鸭翼扰流板
	}
	else
	{
		data[9] = s_airframe->getFlapsPosition();//right flap Versuch 右襟翼
		data[10] = s_airframe->getFlapsPosition();//left flap Versuch 左襟翼
		data[11] = s_airframe->getAileron();//right aileron 右副翼
		data[12] = -s_airframe->getAileron();//left Aileron 左副翼
		data[13] = s_airframe->getLEFlapPosition();//右前缘襟翼
		data[14] = s_airframe->getLEFlapPosition();//左前缘襟翼
		data[15] = s_state->getAoaRate(); //right elevator ist standard f黵 ein Leitwerk 右鸭翼
		data[16] = s_state->getAoaRate();//left elevator 左鸭翼
		data[17] = -s_airframe->getRudder(); //rudder 右垂尾
		data[18] = -s_airframe->getRudder();//rudder nr. 2 左垂尾
		data[21] = s_airframe->getSpeedBrakePosition(); //扰流板
		data[181] = s_airframe->getSpeedCanardBrakePosition();//鸭翼扰流板
	}
	data[22] = s_airframe->getRefuelingDoor();// 加油管
	data[23] = s_flightModel->getWheelChockStatus();
	data[26] = s_airframe->getBayDoorsPosition();//BayDoorPosition 0.0 = zu 1.0 = auf AI弹仓
	data[28] = s_engine->updateBurner2();//Burner Stage 1 and 0 for right engine 右发动机燃烧室动画
	data[29] = s_engine->updateBurner();//Burner Stage 1 and 0 for right engine 左发动机燃烧室动画
	data[35] = s_airframe->brkChutePosition();//减速伞释放
	data[36] = s_airframe->getChutePositionY();//slew chute in Y-Axis (-1 to +1) 减速伞Y轴摆动
	data[37] = s_airframe->getChutePositionZ();//slew chute in Z-Axis (-1 to +1) 减速伞X轴摆动
	data[85] = s_airframe->getLaunchBarPos();//aktuell noch ohne Anbindung an die Actuators, weil wir auch eh nix zum anziegne haben... 弹射杆
	data[89] = s_airframe->getNozzlePosition();//Engine Nozzle Stage 1 - 0 - 1 右喷口动画
	data[90] = s_airframe->getNozzle2Position();//Engine2 Nozzle Position 1 - 0 - 1 左喷口动画
	//data[182] = s_airframe->getSpeedBrakePosition();//airbrake #1
	//data[184] = s_airframe->getSpeedBrakePosition();//airbrake #2
	data[325] = s_engine->getLeftFanAnimationValue();
	data[324] = s_engine->getRightFanAnimationValue();
	data[515] = s_flightModel->getVectorPitchR();
	data[516] = s_flightModel->getVectorPitchL();
	data[517] = s_flightModel->getVectorYaw();
	data[518] = s_flightModel->getVectorYaw();
	//data[403] = s_airframe->getRefuelingDoor();//Refueling-Door toggle Function
	//data[404] = s_airframe->getTiltEngineNozzlePosition();// gibt die TiltNozzlePosition wieder mit 0.0 = gerade 1.0 = 90?runter
	//data[293] = s_airframe->getTopRotorClap();// 293 ist die Rotor-TopKlappe

	//--------this is Refueling-Probe argument---------
	//data[22] = 1.0; //auskommentiert um zu testen ob FC3 das auch so macht...
}

void ed_fm_set_fc3_cockpit_draw_args_v2(float* data, size_t size)
{

}

void ed_fm_set_plugin_data_install_path(const char* path)
{
	printf("%s\n", srcvers);
	printf("%s\n", path);
	init(path);
}

void ed_fm_configure(const char* cfg_path) //neu eingef黦t wegen Pointer und steuert die Initialisierung
{
	printf("Initialising...%s\n", cfg_path);//zur 黚erpr黤ung des Initialisierungsprozesses
}

void ed_fm_release() //neu eingef黦t wegen Pointer und steuert den CleanUp nach dem Shut-Down
{
	cleanup();
}

double test_gear_state = 0;

double ed_fm_get_param(unsigned index)
{

	switch (index)
	{
	case ED_FM_SUSPENSION_0_GEAR_POST_STATE:
	case ED_FM_SUSPENSION_0_DOWN_LOCK:
	case ED_FM_SUSPENSION_0_UP_LOCK:
		return s_airframe->getGearNPosition(); //vorher zum testen bei allen 3 "return 1.0;"

	case ED_FM_SUSPENSION_1_GEAR_POST_STATE:
	case ED_FM_SUSPENSION_1_DOWN_LOCK:
	case ED_FM_SUSPENSION_1_UP_LOCK:
		return s_airframe->getGearLPosition();

	case ED_FM_SUSPENSION_2_GEAR_POST_STATE:
	case ED_FM_SUSPENSION_2_DOWN_LOCK:
	case ED_FM_SUSPENSION_2_UP_LOCK:
		return s_airframe->getGearRPosition();

	case ED_FM_SUSPENSION_1_RELATIVE_BRAKE_MOMENT:
		return s_airframe->updateBrakeLeft();//updateBrake();
	case ED_FM_SUSPENSION_2_RELATIVE_BRAKE_MOMENT:
		return s_airframe->updateBrakeRight();//updateBrake();

	case ED_FM_ANTI_SKID_ENABLE:
		return 1.0;

		//NWS-Stuff
	case ED_FM_SUSPENSION_0_WHEEL_SELF_ATTITUDE:
		return s_input->getNWS() == 1.0 ? 0.0 : 1.0; //was return s_airframe->NWSstate() == 1.0 ? 1.0 : 0.0;
	case ED_FM_SUSPENSION_0_WHEEL_YAW:
		return s_airframe->getNoseWheelAngle(); //war 1.0 dan 0.75 //> 0.5 ? -s_input.m_yaw * 0.5 : 0.0; //rotation to 45 degrees, half 90 (range of the wheel)//jetzt statt 0.65 0.75 wegen Carrier.

	//Engine-Stuff
	case ED_FM_ENGINE_0_CORE_RELATED_RPM:
		return s_apu->getRPMNorm();
	case ED_FM_ENGINE_0_FUEL_FLOW:
		return s_apu->FuelFlowUpdate();
	case ED_FM_ENGINE_1_CORE_RPM: //RPM in Rad/s
		//return s_engine->getRPMNorm() * 777;
	case ED_FM_ENGINE_1_RPM:
		return s_engine->getRPMNorm() * 777;//RPM in Rad/s
	case ED_FM_ENGINE_1_TEMPERATURE:
		return s_engine->tempInC();
	case ED_FM_ENGINE_1_OIL_PRESSURE:
		return (s_engine->getRPMNorm()) * 650.0;
	case ED_FM_ENGINE_1_FUEL_FLOW:
		return s_engine->FuelFlowUpdate() / 3600;
	case ED_FM_ENGINE_1_CORE_RELATED_THRUST:
		return s_engine->updateThrust() / 50000.0;
	case ED_FM_ENGINE_1_RELATED_THRUST:
		//return s_engine->updateThrust() / 50000.0; //NEUer Versuch, wegen HeatBlurr-Effekt
	case ED_FM_ENGINE_1_RELATED_RPM:
		return s_engine->getRPMNorm();
	case ED_FM_ENGINE_1_CORE_RELATED_RPM: //related=normalised RPM in %
		return s_engine->getRPMNorm();

	case ED_FM_ENGINE_1_THRUST:
		return s_engine->updateThrust();

	case ED_FM_ENGINE_1_COMBUSTION:
		if (s_engine->isFire())
		{
			return 0.01;
		}
		return s_engine->FuelFlowUpdate();

	case ED_FM_ENGINE_2_CORE_RPM: //RPM in Rad/s
		//return s_engine->getRPMNorm() * 777;
	case ED_FM_ENGINE_2_RPM:
		return s_engine->getRPMNorm2() * 777;//RPM in Rad/s
	case ED_FM_ENGINE_2_TEMPERATURE:
		return s_engine->tempInC2();
	case ED_FM_ENGINE_2_OIL_PRESSURE:
		return (s_engine->getRPMNorm2()) * 650.0;
	case ED_FM_ENGINE_2_FUEL_FLOW:
		return s_engine->FuelFlowUpdate2() / 3600;
	case ED_FM_ENGINE_2_CORE_RELATED_THRUST:
		return s_engine->updateThrust2() / 50000.0;
	case ED_FM_ENGINE_2_RELATED_THRUST:
		//return s_engine->updateThrust() / 50000.0; //NEUer Versuch, wegen HeatBlurr-Effekt
	case ED_FM_ENGINE_2_RELATED_RPM:
		return s_engine->getRPMNorm2();
	case ED_FM_ENGINE_2_CORE_RELATED_RPM: //related=normalised RPM in %
		return s_engine->getRPMNorm2();

	case ED_FM_ENGINE_2_THRUST:
		return s_engine->updateThrust2();

	case ED_FM_ENGINE_2_COMBUSTION:
		if (s_engine->isFire2())
		{
			return 0.01;
		}
		return s_engine->FuelFlowUpdate2();
	case ED_FM_FUEL_INTERNAL_FUEL:
		return s_fuelsystem->getFuelQtyInternal();

	case ED_FM_FUEL_TOTAL_FUEL:
		return s_fuelsystem->getFuelQtyTotal();

	case ED_FM_FUEL_FUEL_TANK_GROUP_0_LEFT:
		return s_fuelsystem->getFuelQtyExternalLeft();

	case ED_FM_FUEL_FUEL_TANK_GROUP_0_RIGHT:
		return s_fuelsystem->getFuelQtyExternalRight();

	case ED_FM_CAN_ACCEPT_FUEL_FROM_TANKER:
		return s_airframe->getRefuelingDoor();//Versuch, damit es nicht mehr flackert...
		//return 1.0;

	case ED_FM_FC3_STICK_PITCH:
		return s_input->getPitch();
	case ED_FM_FC3_STICK_ROLL:
		return s_input->getRoll();
	case ED_FM_FC3_RUDDER_PEDALS:
		return s_input->getYaw();

	case ED_FM_FC3_THROTTLE_LEFT:
		return s_airframe->getIntThrottlePosition();
	case ED_FM_FC3_THROTTLE_RIGHT:
		return s_airframe->getIntThrottlePosition2();

	case ED_FM_FC3_GEAR_HANDLE_POS:
		return s_input->getGearToggle();

		//-------------Neu eingef黦t zum Testen von AtoA refueling----------------
	case ED_FM_FC3_AR_DOOR_PROBE_HANDLE_POS:
		return s_airframe->getRefuelingDoor();
		//-------------------------------------------------------------------------

	case ED_FM_STICK_FORCE_CENTRAL_PITCH:
		return 0.0;
	case ED_FM_STICK_FORCE_FACTOR_PITCH:
		return 0.75;
	case ED_FM_STICK_FORCE_CENTRAL_ROLL:
		return 0.0;
	case ED_FM_STICK_FORCE_FACTOR_ROLL:
		return 0.75;
	case ED_FM_FC3_BREAKE_CHUTE_STATUS:
		return s_airframe->brkChutePosition();
	case ED_FM_FC3_BREAKE_CHUTE_VALUE:
		return s_input->getBrkChute();
	}

	return 0;

}

bool ed_fm_pop_simulation_event(ed_fm_simulation_event& out)
{
	//这个函数每一帧都在调用，事件类型为0,需要自己处理事件类型
	if (s_airframe->catapultState() == Airframe::ON_CAT_NOT_READY && !s_airframe->catapultStateSent())
	{
		out.event_type = ED_FM_EVENT_CARRIER_CATAPULT;
		out.event_params[0] = 0;
		s_airframe->catapultStateSent() = true;
		return true;
	}
	else if (s_airframe->catapultState() == Airframe::ON_CAT_READY)
	{
		out.event_type = ED_FM_EVENT_CARRIER_CATAPULT;
		out.event_params[0] = 1;
		out.event_params[1] = 3.0f;
		out.event_params[2] = 90.0f + 20.0 * std::min(s_airframe->getMass() / c_maxTakeoffMass, 1.0);// original Funktion "60.0f + 20.0 * std::min(s_airframe->getMass() / c_maxTakeoffMass, 1.0);"
		out.event_params[3] = s_engine->updateThrust() + s_engine->updateThrust2();
		s_airframe->catapultState() = Airframe::ON_CAT_WAITING;
		printf("弹射器状态:ON_CAT_READY->ON_CAT_WAITING/n");
		return true;
	}
	else
	{
		Airframe::Damage damage;
		float integrity;

		if (s_airframe->processDamageStack(damage, integrity))
		{
			s_airframe->toAircraftDamagePartHp((int)damage, integrity);
			out.event_type = ED_FM_EVENT_STRUCTURE_DAMAGE;
			out.event_params[0] = (float)damage;
			out.event_params[1] = integrity;
			printf("我向DCS推送结构损坏事件%.2f,%.2f\n", out.event_params[0], out.event_params[1]);
			return true;
		}
		else if (s_engine->isFire() || s_engine->isFire2() || s_airframe->getEngineDamageMult() < 0.15 || s_airframe->getEngineDamageMultR() < 0.15)
		{
			if ((s_engine->isFire() || s_airframe->getEngineDamageMult() < 0.15) && !s_engine->getFire() && !s_engine->usedLeftExtinguishing())
			{
				//触发左发动机火灾
				printf("左发火灾\n");
				out.event_type = ED_FM_EVENT_FIRE;
				s_airframe->leftEngineFire(out.event_params);
				s_engine->setFire();
			}
			else if ((s_engine->isFire2() || s_airframe->getEngineDamageMultR() < 0.15) && !s_engine->getFire2() && !s_engine->usedRightExtinguishing())
			{
				//触发右发动机火灾
				printf("右发火灾\n");
				out.event_type = ED_FM_EVENT_FIRE;
				s_airframe->rightEngineFire(out.event_params);
				s_engine->setFire2();
			}
			else if ((s_engine->isFire() || s_airframe->getEngineDamageMult() < 0.15) && s_engine->getFire() && s_engine->usedLeftExtinguishing())
			{
				//使用了左发动机灭火器
				printf("左发灭火\n");
				out.event_type = ED_FM_EVENT_FIRE;
				s_airframe->useLeftExtinguishing(out.event_params);
			}
			else if ((s_engine->isFire2() || s_airframe->getEngineDamageMultR() < 0.15) && s_engine->getFire2() && s_engine->usedRightExtinguishing())
			{
				//使用了右发动机灭火器
				printf("右发灭火\n");
				out.event_type = ED_FM_EVENT_FIRE;
				s_airframe->useRightExtinguishing(out.event_params);
			}
			else
			{
				return false;
			}
			return true;
		}
		else
		{
			return false;
		}
	}
}

bool ed_fm_push_simulation_event(const ed_fm_simulation_event& in)
{
	//DCS推送的事件
	if (in.event_type != ED_FM_EVENT_INVALID)
	{
		printf("ed_fm_push_simulation_event\n");
	}
	switch (in.event_type)
	{
	case ED_FM_EVENT_FAILURE:
		printf("失效事件\n");
		break;
	case ED_FM_EVENT_STRUCTURE_DAMAGE:
		printf("结构损坏事件\n");
		break;
	case ED_FM_EVENT_FIRE:
		printf("火灾事件\n");
		break;
	case ED_FM_EVENT_CARRIER_CATAPULT:
		printf("航母弹射器事件\n");
		break;
	case ED_FM_EVENT_CARRIER_HOOKED:
		printf("航母尾勾事件\n");
		break;
	case ED_FM_EVENT_EFFECT:
		printf("效果事件\n");
		break;
	default:
		break;
	}
	if (in.event_type != ED_FM_EVENT_INVALID)
	{
		printf("事件消息:\n");
		for (int i = 0; i < 512; i++)
		{
			if ((int)in.event_message[i] == 0)
			{
				break;
			}
			printf("\\%d", (int)in.event_message[i]);
		}
		printf("\n");
		printf("事件参数:{");
		for (int i = 0; i < 16; i++)
		{
			if (i == 15)
			{
				printf("%.1f", in.event_params[i]);
			}
			else
			{
				printf("%.1f,", in.event_params[i]);
			}
		}
		printf("}\n");
	}
	if (in.event_type == ED_FM_EVENT_CARRIER_CATAPULT)
	{
		if (in.event_params[0] == 1)
		{
			//弹射架挂上弹射器
			printf("弹射器状态:%d->ON_CAT_NOT_READY\n", s_airframe->catapultState());
			s_airframe->catapultState() = Airframe::ON_CAT_NOT_READY;
		}
		else if (in.event_params[0] == 2)
		{
			//已弹射
			printf("弹射器状态:%d->ON_CAT_LAUNCHING\n", s_airframe->catapultState());
			s_airframe->catapultState() = Airframe::ON_CAT_LAUNCHING;
		}
		else if (in.event_params[0] == 3)
		{
			printf("弹射器状态:%d->OFF_CAT\n", s_airframe->catapultState());
			if (s_airframe->catapultState() == Airframe::ON_CAT_LAUNCHING)
			{
				//离舰
				//这里需要回收弹射架
				s_airframe->catapultState() = Airframe::OFF_CAT;
			}
			else
			{
				//终止起飞，弹射架脱钩CAT
				s_airframe->catapultState() = Airframe::OFF_CAT;
			}
		}
	}
	return true;
}

void ed_fm_cold_start()
{
	s_state->coldInit();
	s_input->coldInit();
	s_airframe->coldInit();
	s_engine->coldInit();
	s_fuelsystem->coldInit();
	s_flightModel->coldInit();
	s_PID->coldInit();
	s_autoPilot->coldInit();
	s_elec->coldInit();
	s_hmdDevice->coldInit();
	s_uhfArc164->coldInit();
	s_vhfArc186->coldInit();
	s_ils->coldInit();
	//s_tcn->coldInit();
	s_clock->coldInit();
	s_ufcp->coldInit();
	sounder->init();
}

void ed_fm_hot_start()
{
	s_state->hotInit();
	s_input->hotInit();
	s_airframe->hotInit();
	s_engine->hotInit();
	s_fuelsystem->hotInit();
	s_flightModel->hotInit();
	s_PID->hotInit();
	s_autoPilot->hotInit();
	s_elec->hotInit();
	s_hmdDevice->hotInit();
	s_uhfArc164->hotInit();
	s_vhfArc186->hotInit();
	s_ils->hotInit();
	//s_tcn->hotInit();
	s_clock->hotInit();
	s_ufcp->hotInit();
	sounder->init();
}

void ed_fm_hot_start_in_air()
{
	s_state->airborneInit();
	s_input->airborneInit();
	s_airframe->airborneInit();
	s_engine->airborneInit();
	s_fuelsystem->airborneInit();
	s_flightModel->airborneInit();
	s_PID->airborneInit();
	s_autoPilot->airborneInit();
	s_elec->airborneInit();
	s_hmdDevice->airborneInit();
	s_uhfArc164->airborneInit();
	s_vhfArc186->airborneInit();
	s_ils->airborneInit();
	//s_tcn->airborneInit();
	s_clock->airborneInit();
	s_ufcp->airborneInit();
	sounder->init();
}

//Neu eingef黦t und in der ED_FM_Template.h ebenfalls
void ed_fm_repair()
{
	s_airframe->resetDamage();
	s_airframe->resetOSdamage();
	s_engine->repairHeatDamage();
	s_engine->repairHeatDamage2();
	s_engine->resetFire();
}

bool ed_fm_need_to_be_repaired()
{
	if (s_engine->overHeatInd() == 1.0 || s_engine->overHeatInd2() == 1.0)
		return true;
	if ((s_airframe->overSpeedGearDamageInd() == 1.0) || (s_airframe->overSpeedFlapDamageInd() == 1.0))
	{
		return true;
	}
	else
	{
		return false;
	}
}

double ed_fm_get_shake_amplitude()
{
	return s_flightModel->getCockpitShake();
}

void ed_fm_suspension_feedback(int idx, const ed_fm_suspension_info* info)
{
	if (idx == 0)
	{
		s_airframe->setWeightOnWheels(info->struct_compression);
	}

	//-----possible info about structs---------------------------------------
	//printf("Struct Compression %d: %lf\n", idx, info->struct_compression);
	//printf("Integrity Factor: %lf", info->integrity_factor);
}

bool ed_fm_enable_debug_info()
{
	return false;
}

bool ed_fm_add_local_force_component(double& x, double& y, double& z, double& pos_x, double& pos_y, double& pos_z)
{
	return false;
}

bool ed_fm_add_global_force_component(double& x, double& y, double& z, double& pos_x, double& pos_y, double& pos_z)
{
	return false;
}

bool ed_fm_add_local_moment_component(double& x, double& y, double& z)
{
	return false;
}

bool ed_fm_add_global_moment_component(double& x, double& y, double& z)
{
	return false;
}

bool ed_fm_LERX_vortex_update(unsigned idx, LERX_vortex& out)
{
	if (idx < s_splines.size())
	{
		if (idx == 0 || idx == 3)
		{
			//前缘缝翼
			out.opacity = debugLERX > 0.0 ? 0.8 : clamp((s_airframe->getG() - 1.5) / 12.0 * s_state->m_mach * 1.5, 0.0, 0.8);
			if (idx == 0)
			{
				out.opacity *= s_airframe->getDamageElement(Airframe::Damage::WING_L);
			}
			else
			{
				out.opacity *= s_airframe->getDamageElement(Airframe::Damage::WING_R);
			}
		}
		else if (idx == 2 || idx == 5)
		{
			//鸭翼后面
			out.opacity = debugLERX > 0.0 ? 0.8 : clamp((s_airframe->getG() - 3.0) / 12.0 * s_state->m_mach * 1.5, 0.0, 0.8);
			if (idx == 2)
			{
				out.opacity *= s_airframe->getDamageElement(Airframe::Damage::STABILIZATOR_L);
			}
			else
			{
				out.opacity *= s_airframe->getDamageElement(Airframe::Damage::STABILIZATOR_R);
			}
		}
		else if (idx == 1 || idx == 4)
		{
			//鸭翼前面
			out.opacity = debugLERX > 0.0 ? 0.8 : clamp((s_airframe->getG() - 6.0) / 12.0 * s_state->m_mach * 1.5, 0.0, 0.8);
		}
		else
		{
			out.opacity = debugLERX > 0.0 ? 0.8 : clamp((s_airframe->getG() - 1.0) / 12 * s_state->m_mach * 1.5, 0.0, 0.8);
		}
		s_splines[idx].setOpacity(out.opacity);
		out.explosion_start = 10.0;
		out.spline = s_splines[idx].getArrayPointer();
		out.spline_points_count = s_splines[idx].size();
		out.spline_point_size_in_bytes = LERX_vortex_spline_point_size;
		out.version = 0;
		return true;
	}

	return false;
}