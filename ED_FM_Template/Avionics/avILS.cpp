#include "avILS.h"
avILS::avILS(EDPARAM& edParam, avSimpleElectricSystem& elec) :
	m_cockpitApi(edParam),
	m_elec(elec)
{
	params[ILS_IsLocalizerValid] = EdParam(m_cockpitApi.getParamHandle("ILS_IS_LOCALIZER_VALID"), 0.0);
	params[ILS_IsGlideslopeValid] = EdParam(m_cockpitApi.getParamHandle("ILS_IS_GLIDESLOPE_VALID"), 0.0);
	params[ILS_LocalizerDeviation] = EdParam(m_cockpitApi.getParamHandle("ILS_LOCALIZER_DEVIATION"), 0.0);
	params[ILS_GlideslopeDeviation] = EdParam(m_cockpitApi.getParamHandle("ILS_GLIDESLOPE_DEVIATION"), 0.0);
	params[ILS_IsMarkerBeacon] = EdParam(m_cockpitApi.getParamHandle("ILS_IS_MARKER_BEACON"), 0.0);
	params[ILS_IsOuterMarkerSignal] = EdParam(m_cockpitApi.getParamHandle("ILS_IS_OUTER_MARKER_SIGNAL"), 0.0);
	params[ILS_IsMiddleMarkerSignal] = EdParam(m_cockpitApi.getParamHandle("ILS_IS_MIDDLE_MARKER_SIGNAL"), 0.0);
	params[ILS_IsInnerMarkerSignal] = EdParam(m_cockpitApi.getParamHandle("ILS_IS_INNER_MARKER_SIGNAL"), 0.0);
}

void avILS::zeroInit() {

}
void avILS::coldInit() {
	zeroInit();
}
void avILS::hotInit() {
	zeroInit();
}

void avILS::airborneInit() {
	zeroInit();
}
void avILS::setCommand(int command, float value)
{

}
void avILS::setFreq(double freq)
{
	int MHz = (int)floor(freq);
	int KHz = (int)((freq - MHz) * 1000);
	printf("==============================%d\n==============================%d\n", MHz, KHz);
	try
	{
		m_cockpitApi.ILS_setFrequencyMHz(MHz);
		m_cockpitApi.ILS_setFrequencyKHz(KHz);
	}
	catch (const MyException& e)
	{
		e.printMsg();
	}
}
double avILS::getLocalizerFreq()
{
	try
	{
		return m_cockpitApi.ILS_getLocalizerFrequency();
	}
	catch (const MyException& e)
	{
		e.printMsg();
	}
}
double avILS::getGlideslopeFrequency(double localizerFreq)
{
	try
	{
		return m_cockpitApi.ILS_getGlideslopeFrequency(localizerFreq);
	}
	catch (const MyException& e)
	{
		e.printMsg();
	}
}
void avILS::update(double dt)
{
	if (!isConnect)
	{
		try
		{
			m_cockpitApi.ILS_connectElecPower();
			isConnect = true;
		}
		catch (const MyException& e)
		{
			printf("%s\n", e.what());
		}
	}
	if (working && m_elec.isDC())
	{
		updateILS();
	}
	else
	{
		params[ILS_IsLocalizerValid].tg = 0.0;
		params[ILS_IsGlideslopeValid].tg = 0.0;
		params[ILS_LocalizerDeviation].tg = 0.0;
		params[ILS_GlideslopeDeviation].tg = 0.0;
		params[ILS_IsMarkerBeacon].tg = 0.0;
		params[ILS_IsOuterMarkerSignal].tg = 0.0;
		params[ILS_IsMiddleMarkerSignal].tg = 0.0;
		params[ILS_IsInnerMarkerSignal].tg = 0.0;
	}
	for (auto it = params.begin(); it != params.end(); ++it)
	{
		it->second.update(m_cockpitApi);
	}
}
void avILS::updateILS()
{
	bool isLocalizerValid = m_cockpitApi.ILS_isLocalizerValid();
	bool isGlideslopeValid = m_cockpitApi.ILS_isGlideslopeValid();
	params[ILS_IsLocalizerValid].tg = isLocalizerValid ? 1.0 : 0.0;
	params[ILS_IsGlideslopeValid].tg = isGlideslopeValid ? 1.0 : 0.0;
	if (isLocalizerValid)
	{
		double localizerDeviation = m_cockpitApi.ILS_getLocalizerDeviation();
		params[ILS_LocalizerDeviation].tg = tan(localizerDeviation) * 0.757;
	}
	else
	{
		params[ILS_LocalizerDeviation].tg = 0.0;
	}
	if (isGlideslopeValid)
	{
		double glideslopeDeviation = m_cockpitApi.ILS_getGlideslopeDeviation();
		params[ILS_GlideslopeDeviation].tg = tan(glideslopeDeviation) * 0.757;
	}
	else
	{
		params[ILS_GlideslopeDeviation].tg = 0.0;
	}
	params[ILS_IsOuterMarkerSignal].tg = m_cockpitApi.ILS_isOuterMarkerSignal() ? 1.0 : 0.0;
	params[ILS_IsMiddleMarkerSignal].tg = m_cockpitApi.ILS_isMiddleMarkerSignal() ? 1.0 : 0.0;
	params[ILS_IsInnerMarkerSignal].tg = m_cockpitApi.ILS_isInnerMarkerSignal() ? 1.0 : 0.0;
	params[ILS_IsMarkerBeacon].tg = m_cockpitApi.ILS_isMarkerBeacon();
}