#include "avSimpleElectricSystem.h"

avSimpleElectricSystem::avSimpleElectricSystem
(
	EDPARAM& edParam
) :
	cockpitAPI(edParam)
{
	params[BAT_VOLTAGE] = EdParam(cockpitAPI.getParamHandle("BAT_VOLTAGE"), 0.0, 0.0, 0.0, 0.0, 28.0);
	params[DC_VOLTAGE] = EdParam(cockpitAPI.getParamHandle("DC_VOLTAGE"), 0.0, 0.0, 0.0, 0.0, 115.0);
	params[AC_VOLTAGE_1] = EdParam(cockpitAPI.getParamHandle("AC_VOLTAGE_1"), 0.0, 0.0, 0.0, 0.0, 115.0);
	params[AC_VOLTAGE_2] = EdParam(cockpitAPI.getParamHandle("AC_VOLTAGE_2"), 0.0, 0.0, 0.0, 0.0, 115.0);
}

void avSimpleElectricSystem::zeroInit() {
	m_battery = false;
	m_genL = false;
	m_genR = false;
	m_gndPwr = false;
}
void avSimpleElectricSystem::coldInit() {
	zeroInit();
}
void avSimpleElectricSystem::hotInit() {
	zeroInit();
	m_battery = true;
	m_genL = true;
	m_genR = true;
	params[AC_VOLTAGE_1].tg = 115.0;
	params[AC_VOLTAGE_1].cur = 115.0;
	params[AC_VOLTAGE_2].tg = 115.0;
	params[AC_VOLTAGE_2].cur = 115.0;
	params[DC_VOLTAGE].tg = 115.0;
	params[DC_VOLTAGE].cur = 115.0;
	params[BAT_VOLTAGE].tg = 28.0;
	params[BAT_VOLTAGE].cur = 28.0;
}
void avSimpleElectricSystem::airborneInit() {
	hotInit();
}

void avSimpleElectricSystem::setCommand(int command, float value)
{
	switch (command)
	{
	case Battery:
		m_battery = (value != 0.0f);
		break;
	case k_Battery:
		m_battery = !m_battery;
		try
		{
			cockpitAPI.performClickAction(cockpitAPI.ELECTRIC_SYSTEM, Battery, m_battery ? 1.0f : 0.0f);
		}
		catch (const MyException& e)
		{
			e.printMsg();
		}
		break;
	case LeftAcGenerator:
		m_genL = (value != 0.0f);
		break;
	case k_LeftAcGenerator:
		m_genL = !m_genL;
		try
		{
			cockpitAPI.performClickAction(cockpitAPI.ELECTRIC_SYSTEM, LeftAcGenerator, m_genL ? 1.0f : 0.0f);
		}
		catch (const MyException& e)
		{
			e.printMsg();
		}
		break;
	case RightAcGenerator:
		m_genR = (value != 0.0f);
		break;
	case k_RightAcGenerator:
		m_genR = !m_genR;
		try
		{
			cockpitAPI.performClickAction(cockpitAPI.ELECTRIC_SYSTEM, RightAcGenerator, m_genR ? 1.0f : 0.0f);
		}
		catch (const MyException& e)
		{
			e.printMsg();
		}
		break;
	case GndPower:
		m_gndPwr = (value != 0.0f);
		break;
	case k_GndPower:
		m_gndPwr = !m_gndPwr;
		try
		{
			cockpitAPI.performClickAction(cockpitAPI.ELECTRIC_SYSTEM, GndPower, m_gndPwr ? 1.0f : 0.0f);
		}
		catch (const MyException& e)
		{
			e.printMsg();
		}
		break;
	case iCommandGroundPowerAC:
		s_gndPwr = 1 - s_gndPwr;
		break;
	default:
		break;
	}
}

void avSimpleElectricSystem::update(double dt)
{
	if (init)
	{
		try
		{
			cockpitAPI.performClickAction(cockpitAPI.ELECTRIC_SYSTEM, Battery, m_battery, false);
			cockpitAPI.performClickAction(cockpitAPI.ELECTRIC_SYSTEM, LeftAcGenerator, m_genL, false);
			cockpitAPI.performClickAction(cockpitAPI.ELECTRIC_SYSTEM, RightAcGenerator, m_genR, false);
			init = true;
		}
		catch (const MyException& e)
		{
			printf("%s\n", e.what());
		}
	}
	if (m_battery != s_battery)
	{
		try
		{
			cockpitAPI.switchBattery(m_battery);
			cockpitAPI.VHF_setElecPower(m_battery);
			cockpitAPI.VHF_setElecPower(m_battery, 2);
			cockpitAPI.UHF_setElecPower(m_battery);
			cockpitAPI.ILS_setElecPower(m_battery);
			s_battery = m_battery;
		}
		catch (const MyException& e)
		{
			printf("%s\n", e.what());
		}
	}
	if (m_genL != s_genL)
	{
		try
		{
			cockpitAPI.switchGenerator(m_genL);
			s_genL = m_genL;
		}
		catch (const MyException& e)
		{
			printf("%s\n", e.what());
		}
	}
	if (m_genR != s_genR)
	{
		try
		{
			cockpitAPI.switchGenerator(m_genR, 2);
			s_genR = m_genR;
		}
		catch (const MyException& e)
		{
			printf("%s\n", e.what());
		}
	}
	if (acWire == nullptr)
	{
		try
		{
			acWire = cockpitAPI.getACbus();
		}
		catch (const MyException& e)
		{
			e.printMsg();
		}
	}
	if (dcWire == nullptr)
	{
		try
		{
			dcWire = cockpitAPI.getDCbus();
		}
		catch (const MyException& e)
		{
			e.printMsg();
		}
	}
	try
	{
		//printf("ac%p\n", acWire);
		//printf("dc%p\n", dcWire);
		params[BAT_VOLTAGE].tg = getDC1Voltage();
		params[DC_VOLTAGE].tg = getDC2Voltage();
		params[AC_VOLTAGE_1].tg = getAC1Voltage();
		params[AC_VOLTAGE_2].tg = getAC2Voltage();
	}
	catch (const MyException& e)
	{
		e.printMsg();
	}
	for (auto it = params.begin(); it != params.end(); ++it)
	{
		it->second.dt = dt * 100;
		it->second.update(cockpitAPI);
	}
}
double avSimpleElectricSystem::getAC1Voltage()
{
	if (acWire == nullptr)
	{
		return 0.0;
	}
	return *((double*)((intptr_t)acWire + 0x138));
	//return 0.0;
}
double avSimpleElectricSystem::getAC2Voltage()
{
	if (acWire == nullptr)
	{
		return 0.0;
	}
	return *((double*)((intptr_t)acWire + 0x2a8));
	//return 0.0;
}
double avSimpleElectricSystem::getDC1Voltage()
{
	if (dcWire == nullptr)
	{
		return 0.0;
	}
	return *((double*)((intptr_t)dcWire + 0x138));
	//return 0.0;
}
double avSimpleElectricSystem::getDC2Voltage()
{
	if (dcWire == nullptr)
	{
		return 0.0;
	}
	double ac = std::max(getAC1Voltage(), getAC2Voltage());
	return (*((double*)((intptr_t)dcWire + 0x2A8))) * (ac / 115.0);
	//return 0.0;
}
const bool avSimpleElectricSystem::isAC1()
{
	return getAC1Voltage() >= 115.0;
	//return cockpitAPI.getParamNumber(ac1_h) == 1;
}
const bool avSimpleElectricSystem::isAC2()
{
	return getAC2Voltage() >= 115.0;
	//return cockpitAPI.getParamNumber(ac2_h) == 1;
}
const bool avSimpleElectricSystem::isDC()
{
	return getDC1Voltage() >= 28.0 || getDC2Voltage() >= 28.0;
	//return cockpitAPI.getParamNumber(dc_h) == 1;
}
const bool avSimpleElectricSystem::isAC()
{
	return isAC1() || isAC2();
	//return cockpitAPI.getParamNumber(ac_h) == 1;
}

const bool avSimpleElectricSystem::isGndPwr()
{
	return m_gndPwr && s_gndPwr;
}