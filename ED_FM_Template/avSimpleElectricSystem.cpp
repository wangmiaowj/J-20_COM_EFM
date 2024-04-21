#include "avSimpleElectricSystem.h"

AvSimpleElectricSystem::AvSimpleElectricSystem
(
	EDPARAM& edParam
) :
	cockpitAPI(edParam)
{

}

void AvSimpleElectricSystem::zeroInit() {
	m_battery = false;
	m_genL = false;
	m_genR = false;
	m_gndPwr = false;
}
void AvSimpleElectricSystem::coldInit() {
	zeroInit();
}
void AvSimpleElectricSystem::hotInit() {
	zeroInit();
	m_battery = true;
	m_genL = true;
	m_genR = true;
}
void AvSimpleElectricSystem::airborneInit() {
	hotInit();
}

void AvSimpleElectricSystem::setCommand(int command, float value)
{
	switch (command)
	{
	case Battery:
		m_battery = (value != 0.0f);
		break;
	case k_Battery:
		m_battery = !m_battery;
		cockpitAPI.performClickAction(cockpitAPI.ELECTRIC_SYSTEM, Battery, m_battery ? 1.0f : 0.0f);
		break;
	case LeftAcGenerator:
		m_genL = (value != 0.0f);
		break;
	case k_LeftAcGenerator:
		m_genL = !m_genL;
		cockpitAPI.performClickAction(cockpitAPI.ELECTRIC_SYSTEM, LeftAcGenerator, m_genL ? 1.0f : 0.0f);
		break;
	case RightAcGenerator:
		m_genR = (value != 0.0f);
		break;
	case k_RightAcGenerator:
		m_genR = !m_genR;
		cockpitAPI.performClickAction(cockpitAPI.ELECTRIC_SYSTEM, RightAcGenerator, m_genR ? 1.0f : 0.0f);
		break;
	case GndPower:
		m_gndPwr = (value != 0.0f);
		break;
	case k_GndPower:
		m_gndPwr = !m_gndPwr;
		cockpitAPI.performClickAction(cockpitAPI.ELECTRIC_SYSTEM, GndPower, m_gndPwr ? 1.0f : 0.0f);
		break;
	default:
		break;
	}
}

void AvSimpleElectricSystem::update(double dt)
{
	if (m_battery != s_battery)
	{
		cockpitAPI.switchBattery(m_battery);
		s_battery = m_battery;
	}
	if (m_genL != s_genL)
	{
		cockpitAPI.switchGenerator(m_genL);
		s_genL = m_genL;
	}
	if (m_genR != s_genR)
	{
		cockpitAPI.switchGenerator(m_genR, 2);
		s_genR = m_genR;
	}
}
const bool AvSimpleElectricSystem::isAC1()
{
	return cockpitAPI.getParamNumber(ac1_h) == 1;
}
const bool AvSimpleElectricSystem::isAC2()
{
	return cockpitAPI.getParamNumber(ac2_h) == 1;
}
const bool AvSimpleElectricSystem::isDC()
{
	return cockpitAPI.getParamNumber(dc_h) == 1;
}
const bool AvSimpleElectricSystem::isAC()
{
	return cockpitAPI.getParamNumber(ac_h) == 1;
}

const bool AvSimpleElectricSystem::isGndPwr()
{
	return false;
}