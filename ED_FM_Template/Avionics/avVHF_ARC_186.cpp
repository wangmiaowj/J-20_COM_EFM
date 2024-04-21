#include "avVHF_ARC_186.h"
avVHF_ARC_186::avVHF_ARC_186(EDPARAM& edParam, avSimpleElectricSystem& elec) :
	m_cockpitApi(edParam),
	m_elec(elec)
{

}

void avVHF_ARC_186::zeroInit() {

}
void avVHF_ARC_186::coldInit() {
	zeroInit();
}
void avVHF_ARC_186::hotInit() {
	zeroInit();
	volume = 1.0;
}

void avVHF_ARC_186::airborneInit() {
	hotInit();
}
void avVHF_ARC_186::setCommand(int command, float value)
{
	switch (command)
	{
	case k_VHF_PIT:
		try
		{
			m_cockpitApi.VHF_intercom_setAsCurrent(fm ? 2 : 1);
			m_cockpitApi.intercom_pushToTalk(true);
		}
		catch (const MyException& e)
		{
			printf("%s\n", e.what());
		}
		break;
	case VHF_Volume:
		volume = value;
		try
		{
			m_cockpitApi.VHF_setVolume(volume);
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
void avVHF_ARC_186::update(double dt)
{
	if (!isConnect)
	{
		try
		{
			m_cockpitApi.VHF_connect_electric();
			m_cockpitApi.VHF_setVolume(volume);
			m_cockpitApi.performClickAction(m_cockpitApi.UFCP, VHF_Volume, volume);
			isConnect = true;
		}
		catch (const MyException& e)
		{
			printf("%s\n", e.what());
		}
	}
}
int avVHF_ARC_186::getFreq()
{
	return m_cockpitApi.VHF_getKnobsFrequency(fm ? 2 : 1);
}
void avVHF_ARC_186::setFreq(int freq)
{
	m_cockpitApi.VHF_set_knobs_frequency(freq, fm ? 2 : 1);
}
bool avVHF_ARC_186::isFM()
{
	return fm;
}
void avVHF_ARC_186::setAM()
{
	fm = false;
}
void avVHF_ARC_186::setFM()
{
	fm = true;
}