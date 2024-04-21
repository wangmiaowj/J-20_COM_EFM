#pragma once
#include <stdio.h>
#include "../BaseComponent.h"
#include "../Maths.h"
#include "../Input.h"
#include "../CockpitAPI_Declare.h"
#include "avSimpleElectricSystem.h"

class avVHF_ARC_186 {
public:
	avVHF_ARC_186(EDPARAM& cockpitApi, avSimpleElectricSystem& elec);
	//Initialization
	virtual void zeroInit();
	virtual void coldInit();
	virtual void hotInit();
	virtual void airborneInit();

	void setCommand(int command, float value);
	void update(double dt);
	int getFreq();
	void setFreq(int freq);
	bool isFM();
	void setFM();
	void setAM();
	inline const bool is_frequency_in_range(int freq)
	{
		if (fm)
		{
			return (freq >= 30E6 && freq < 108E6);
		}
		return (freq >= 116E6 && freq < 151.95E6);
	}
private:
	EDPARAM& m_cockpitApi;
	avSimpleElectricSystem& m_elec;
	bool isConnect = false, isElecPower = false, fm = false;
	float volume = 0.0;
};