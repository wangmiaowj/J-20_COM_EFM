#pragma once
#include <stdio.h>
#include "../Table.h"
#include "../Maths.h"
#include "../BaseComponent.h"
#include "../CockpitAPI_Declare.h"
#include "../Input.h"

class avSimpleElectricSystem
{
public:
	avSimpleElectricSystem(EDPARAM& edParam);

	//Initialization
	virtual void zeroInit();
	virtual void coldInit();
	virtual void hotInit();
	virtual void airborneInit();

	void update(double dt); //in der () "double dt" eingefügt, war vorher ohne
	void setCommand(int command, float value);

	//----------Functions Engine 1-----------
	const bool isDC();
	const bool isAC();
	const bool isAC1();
	const bool isAC2();
	const bool isGndPwr();
	double getAC1Voltage();
	double getAC2Voltage();
	double getDC1Voltage();
	double getDC2Voltage();

private:
	enum paramName {
		BAT_VOLTAGE,
		DC_VOLTAGE,
		AC_VOLTAGE_1,
		AC_VOLTAGE_2
	};
	EDPARAM& cockpitAPI;
	//-------------Engine Values/Commands Engine1----------------------------
	bool m_battery = false;
	bool m_genL = false;
	bool m_genR = false;
	bool m_gndPwr = false;
	bool s_battery = false;
	bool s_genL = false;
	bool s_genR = false;
	bool s_gndPwr = false;
	bool init = false;
	void* acWire = nullptr;
	void* dcWire = nullptr;
	std::map<int, EdParam>params;
};