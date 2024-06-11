#include "hmdDevice.h"

HMDDevice::HMDDevice(EDPARAM& edParam, Input& input, avSimpleElectricSystem& elec)
	:
	m_cockpit_api(edParam),
	m_input(input),
	m_elec(elec)
{
	params["HELMET_BRT"] = EdParam(m_cockpit_api.getParamHandle("HELMET_BRT"), 0.0, 0.0, 0.006);
	params["HEAD_AZ"] = EdParam(m_cockpit_api.getParamHandle("HEAD_AZ"), 0.0);
	params["HEAD_EL"] = EdParam(m_cockpit_api.getParamHandle("HEAD_EL"), 0.0);
	params["HEAD_HDG"] = EdParam(m_cockpit_api.getParamHandle("HEAD_HDG"), 0.0);
	dayNight = 0.0;
}
void HMDDevice::zeroInit()
{
	params["HELMET_BRT"].tg = 0.0;
	params["HELMET_BRT"].cur = 0.0;
}
void HMDDevice::coldInit()
{
	zeroInit();
}
void HMDDevice::hotInit()
{
	zeroInit();
	params["HELMET_BRT"].tg = 1.0;
	params["HELMET_BRT"].cur = 0.98;
}
void HMDDevice::airborneInit()
{
	params["HELMET_BRT"].tg = 1.0;
	params["HELMET_BRT"].cur = 0.98;
}
void HMDDevice::update(double dt)
{
	dayNight = m_cockpit_api.getParamNumber(dayNight_h);
	if (m_elec.isAC() && !m_elec.isGndPwr())
	{
		params["HEAD_HDG"].tg = LoopPlayAnimal(m_cockpit_api.getParamNumber(hdg_h), -params["HEAD_AZ"].tg, 0, 360);
		updateHMD_brt(dt);
		for (auto it = params.begin(); it != params.end(); ++it)
		{
			it->second.update(m_cockpit_api);
		}
	}
}
void HMDDevice::updateHMD_brt(double dt)
{
	if (m_elec.isAC() && !m_elec.isGndPwr())
	{
		if (abs(params["HEAD_AZ"].tg) < 7 && abs(params["HEAD_EL"].tg) < 7)
		{
			params["HELMET_BRT"].cur = 0.0;
			params["HELMET_BRT"].dt = 0.0;
		}
		else
		{
			params["HELMET_BRT"].cur = params["HELMET_BRT"].tg - 0.02;
			params["HELMET_BRT"].dt = dt;
		}
	}
	else
	{
		params["HELMET_BRT"].cur = 0.0;
		params["HELMET_BRT"].dt = 0.0;
	}
}
void HMDDevice::setCommand(int command, float value)
{
	switch (command)
	{
	case iServiceInformAboutUserHAngle:
		params["HEAD_AZ"].tg = value;
		break;
	case iServiceInformAboutUserVAngle:
		params["HEAD_EL"].tg = value;
		break;
	case hmdBrt:
		params["HELMET_BRT"].tg = value;
		break;
	default:
		break;
	}
}