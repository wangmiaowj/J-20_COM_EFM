#pragma once

#include "State.h"
#include "Input.h"
#include "PID.h"
#include "Table.h"
#include "Vec3.h"
#include "AeroData_1.h"
#include "Maths.h"
#include "BaseComponent.h"
#include "Airframe.h"
#include "Units.h"
#include "Avionics/avSimpleElectricSystem.h"

class AutoPilot
{
public:

	AutoPilot(State& state, Input& input, PID& pid, Airframe& airframe, avSimpleElectricSystem& elec, EDPARAM& edParam);

	//~AutoPilot();

	//Initialization
	virtual void zeroInit();
	virtual void coldInit();
	virtual void hotInit();
	virtual void airborneInit();

	//begin of funny functions
	//---------Update Function--------
	void AutoPilotUpdate(double dt);

	//---Sorts of AutoControllers
	void VerticalAngleControl(double dt);
	void AltitudeControl(double dt);
	void RollControl();
	void PitchControl();
	void flyByWire(double dt);

	//-----Return functions----------
	inline double getAutoPitch();
	inline double getAutoRoll();
	inline double getFBWPitch();
	void ap();

private:

	State& m_state;
	Input& m_input;
	PID& m_pid;
	Airframe& m_airframe;
	avSimpleElectricSystem& m_elec;
	EDPARAM& m_cockpitAPI;

	double m_desiredAngle = 0.0;
	double m_desiredAlt = 0.0;
	double m_desiredAngleMax = 0.0;
	double m_desiredAngleMin = 0.0;
	double m_FBW_desiredAngle = 0.0;
	double m_FBW_desiredAngleMax = 0.0;
	double m_FBW_desiredAngleMin = 0.0;

	double m_pitchUpMax = 0.0;
	double m_pitchDownMax = 0.0;

	double m_FBW_pitchUpMax = 0.0;
	double m_FBW_pitchDownMax = 0.0;

	bool m_attAPengaged = false;
	bool m_altAPengaged = false;
	bool m_fbwEngaged = false;

	double m_autoPilotPitch = 0.0;

	double m_autoPilotAngle = 0.0;

	double m_verticalControlEngaged = 0.0;

	double m_autoFBWPitch = 0.0;

	void* fbwStatus_h = m_cockpitAPI.getParamHandle("FBW_STATUS");
	void* apAttStatus_h = m_cockpitAPI.getParamHandle("AP_ATT_STATUS");
	void* apAltStatus_h = m_cockpitAPI.getParamHandle("AP_ALT_STATUS");

};

double AutoPilot::getAutoPitch()
{
	return m_autoPilotPitch;
}

double AutoPilot::getAutoRoll()
{

}

double AutoPilot::getFBWPitch()
{
	return m_autoFBWPitch;
}