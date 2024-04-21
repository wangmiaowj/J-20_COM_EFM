#include "avUHF_ARC_164.h"
avUHF_ARC_164::avUHF_ARC_164(EDPARAM& edParam, avSimpleElectricSystem& elec) :
	m_cockpitApi(edParam),
	m_elec(elec)
{
	/*params[paramName::UHF_isActiveMode] = EdParam(edParam.getParamHandle("UHF_isActiveMode"), 0.0);
	params[paramName::UHF_getKnobsFrequencyMHz] = EdParam(edParam.getParamHandle("UHF_getKnobsFrequencyMHz"), 0.0);
	params[paramName::UHF_getKnobsFrequencyKHz] = EdParam(edParam.getParamHandle("UHF_getKnobsFrequencyKHz"), 0.0);
	params[paramName::UHF_getNetAddress] = EdParam(edParam.getParamHandle("UHF_getNetAddress"), 0.0);
	params[paramName::UHF_indicationOff] = EdParam(edParam.getParamHandle("UHF_indicationOff"), 0.0);
	params[paramName::UHF_getBearing] = EdParam(edParam.getParamHandle("UHF_getBearing"), 0.0);
	params[paramName::UHF_isAlternateFreqStatus] = EdParam(edParam.getParamHandle("UHF_isAlternateFreqStatus"), 0.0);
	params[paramName::UHF_isPresetChannelMode] = EdParam(edParam.getParamHandle("UHF_isPresetChannelMode"), 0.0);
	params[paramName::UHF_getAlternateFrequency] = EdParam(edParam.getParamHandle("UHF_getAlternateFrequency"), 0.0);*/
}

void avUHF_ARC_164::zeroInit() {

}
void avUHF_ARC_164::coldInit() {
	zeroInit();
}
void avUHF_ARC_164::hotInit() {
	zeroInit();
	volume = 1.0;
}

void avUHF_ARC_164::airborneInit() {
	hotInit();
}
void avUHF_ARC_164::setCommand(int command, float value)
{
	switch (command)
	{
	case k_UHF_PIT:
		updateComm();
		try
		{
			m_cockpitApi.intercom_pushToTalk(true);
		}
		catch (const MyException& e)
		{
			printf("%s\n", e.what());
		}
		break;
	case UHF_Volume:
		volume = value;
		try
		{
			m_cockpitApi.UHF_setVolume(volume);
		}
		catch (const MyException& e)
		{
			printf("%s\n", e.what());
		}
		break;
	default:
		break;
	}
}
void avUHF_ARC_164::updateComm()
{
	try
	{
		m_cockpitApi.UHF_intercom_setAsCurrent();
	}
	catch (const MyException& e)
	{
		printf("%s\n", e.what());
	}
}
void avUHF_ARC_164::update(double dt)
{
	if (!isConnect)
	{
		try
		{
			m_cockpitApi.UHF_connect_electric();
			m_cockpitApi.UHF_setVolume(volume);
			m_cockpitApi.performClickAction(m_cockpitApi.UFCP, UHF_Volume, volume);
			isConnect = true;
		}
		catch (const MyException& e)
		{
			printf("%s\n", e.what());
		}
	}
	/*try
	{
		params[paramName::UHF_isActiveMode].tg = m_cockpitApi.UHF_isActiveMode();
		params[paramName::UHF_getKnobsFrequencyMHz].tg = m_cockpitApi.UHF_getKnobsFrequencyMHz();
		params[paramName::UHF_getKnobsFrequencyKHz].tg = m_cockpitApi.UHF_getKnobsFrequencyKHz();
		params[paramName::UHF_getNetAddress].tg = m_cockpitApi.UHF_getNetAddress();
		params[paramName::UHF_indicationOff].tg = m_cockpitApi.UHF_indicationOff();
		params[paramName::UHF_getBearing].tg = m_cockpitApi.UHF_getBearing();
		params[paramName::UHF_isAlternateFreqStatus].tg = m_cockpitApi.UHF_isAlternateFreqStatus();
		params[paramName::UHF_isPresetChannelMode].tg = m_cockpitApi.UHF_isPresetChannelMode();
		params[paramName::UHF_getAlternateFrequency].tg = m_cockpitApi.UHF_getAlternateFrequency();
	}
	catch (const MyException& e)
	{
		e.printMsg();
	}*/
	/*for (auto it = params.begin(); it != params.end(); ++it)
	{
		it->second.update(m_cockpitApi);
	}*/
}
int avUHF_ARC_164::getFreq()
{
	return m_cockpitApi.UHF_getKnobsFrequency();
}
void avUHF_ARC_164::setFreq(int freq)
{
	m_cockpitApi.UHF_set_knobs_frequency(freq);
}
void avUHF_ARC_164::set_preset_channel(unsigned int channel)
{
	try
	{
		m_cockpitApi.UHF_set_preset_channel(channel);
	}
	catch (const MyException& e)
	{
		e.printMsg();
	}
}