#pragma once
#include <stdio.h>
#include "../Table.h"
#include "../Input.h"
#include "../Maths.h"
#include "../BaseComponent.h"
#include "../CockpitAPI_Declare.h"
#include "../Avionics/avSimpleElectricSystem.h"
#include <map>
#include <string>
class HMDDevice {
public:
	HMDDevice(EDPARAM& edParam, Input& input, avSimpleElectricSystem& elec);
	void update(double rate);
	void setCommand(int command, float value);
	//Initialization
	virtual void zeroInit();
	virtual void coldInit();
	virtual void hotInit();
	virtual void airborneInit();
private:
	enum wavId {
		shiMuDe,
	};
	EDPARAM& m_cockpit_api;
	Input& m_input;
	avSimpleElectricSystem& m_elec;
	std::map<std::string, EdParam>params;
	void* hdg_h = m_cockpit_api.getParamHandle("HDG");
	void* dayNight_h = m_cockpit_api.getParamHandle("DAY_NIGHT");
	void updateHMD_brt(double dt);
	double dayNight = 0.0;
	double time = 0.0;
	bool flag = false;
};