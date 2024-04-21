#pragma once
#include <stdio.h>
#include "../Table.h"
#include "../Input.h"
#include "../Maths.h"
#include "../BaseComponent.h"
#include "../CockpitAPI_Declare.h"
#include "../Avionics/avSimpleElectricSystem.h"
class avILS
{
public:
	avILS(EDPARAM& edParam, avSimpleElectricSystem& elec);
	virtual void zeroInit();
	virtual void coldInit();
	virtual void hotInit();
	virtual void airborneInit();
	void setCommand(int command, float value);
	void update(double dt);
	void setFreq(double freq);
	double getLocalizerFreq();
	double getGlideslopeFrequency(double localizerFreq);
	inline void enable()
	{
		working = true;
	}
	inline void disable()
	{
		working = false;
	}
private:
	enum ILS_handles {
		ILS_IsLocalizerValid,
		ILS_IsGlideslopeValid,
		ILS_LocalizerDeviation,
		ILS_GlideslopeDeviation,
		ILS_IsMarkerBeacon,
		ILS_IsOuterMarkerSignal,
		ILS_IsMiddleMarkerSignal,
		ILS_IsInnerMarkerSignal
	};
	EDPARAM& m_cockpitApi;
	avSimpleElectricSystem& m_elec;
	std::map<int, EdParam>params;
	bool isConnect = false, isElecPower = false, working = false;

	void updateILS();
};