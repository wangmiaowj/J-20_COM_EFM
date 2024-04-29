#pragma once
#include <stdio.h>
#include "../Maths.h"
#include "../CockpitAPI_Declare.h"
#include "../BaseComponent.h"
#include "../Input.h"
#include "../Avionics/avSimpleElectricSystem.h"
#include "../Avionics/avILS.h"
#include "../Table.h"
#include <map>
#include <string.h>
#include <cstring>
class UFCPDevice {
public:
	UFCPDevice(EDPARAM& edParam, avSimpleElectricSystem& p_elec, avILS& p_ils, Input& p_input);
	//Initialization
	virtual void zeroInit();
	virtual void coldInit();
	virtual void hotInit();
	virtual void airborneInit();

	void setCommand(int command, float value);
	void update(double dt);
private:
	enum paramName {
		UFCP_BRT,
		UFCP_PAGE,
		COMM1_FREQ,
		COMM1_TMP_FREQ,
		COMM1_ERR_FREQ,
		COMM1_EDIT_FREQ,
		COMM1_AMFM,
		COMM1_PRE,
		COMM1_EDIT_PRE,
		COMM1_PRE_MAN,
		COMM1_PRE_FREQ,

		COMM2_FREQ,
		COMM2_TMP_FREQ,
		COMM2_ERR_FREQ,
		COMM2_EDIT_FREQ,
		COMM2_AMFM,
		COMM2_PRE,
		COMM2_EDIT_PRE,
		COMM2_PRE_MAN,
		COMM2_PRE_FREQ,

		NAV_SUB_PAGE,

		TCN_CHANNEL,
		TCN_EDIT_CHANNEL,
		TCN_TMP_CHANNEL,
		TCN_ERR_CHANNEL,
		TCN_WORK_MODE,
		TCN_AA_MODE,
		TCN_XY,
		TCN_STATUS,

		ILS_FREQ,
		ILS_GLIDESLOPE_FREQ,
		ILS_EDIT_FREQ,
		ILS_TMP_FREQ,
		ILS_ERR_FREQ,
		ILS_STATUS,

		IFF_STATUS,
		IFF_STATUS_RDR,
		NCTR_STATUS,

		LASER_CODE,
		LASER_EDIT_CODE,
		LASER_ERR_CODE,
		LASER_TMP_CODE,

		ATK_WPT,

		AP_STATUS,
		STABILITY,
		AP_ALT,
		AP_RALT,
		AP_RESET,

		VUHF1,
		VUHF2,

		WPT_LON_WAY,
		WPT_LON_DD,
		WPT_LON_MM,
		WPT_LON_SS,
		WPT_TMP_LON_WAY,
		WPT_TMP_LON_DD,
		WPT_TMP_LON_MM,
		WPT_TMP_LON_SS,
		WPT_EDIT_LON,

		WPT_SEARCH_KEY,
		WPT_TMP_SEARCH_KEY,
		WPT_EDIT_SEARCH_KEY,

		WPT_SEARCH_TYPE,

		WPT_SEARCH_RESULT_LIST_SIZE,

		WPT_ALT,
		WPT_TMP_ALT,
		WPT_EDIT_ALT,

		WPT_ALT_TYPE,

		WPT_SPD,
		WPT_TMP_SPD,
		WPT_EDIT_SPD
	};
	enum ufcpPages {
		BASE = 1,
		COMM,
		NAV,
		COMBAT,
		AP
	};
	enum navPages {
		MENU = 0,
		TCN = 10,
		ILS = 20,
		VOR = 30,
		WPTS = 40,
		WPT = 41,
		COORD = 42,
		SEARCH = 43,
		SEARCH_RESULT = 44,
		ALT = 45
	};
	EDPARAM& cockpitApi;
	avSimpleElectricSystem& elec;
	avILS& ils;
	Input& m_input;
	void* ufcpPage;
	void* navPage;
	void* atkWptMax;
	std::map<int, EdParam>params;
	bool init = false;
	int iptFreq(int freq, int num);
	int freqSize = 0;
	void updateFreq();

	void setCommand_ap(int command, float value);
	void handleL1_ap();
	void handleL2_ap();
	void handleL3_ap();
	void handleL4_ap();
	void handleR1_ap();
	void handleR2_ap();
	void handleR3_ap();
	void handleR4_ap();

	int laserCodeSize = 0;
	int iptLaserCode(int laserCode, int num);
	void inputLaserCode(int num);
	void checkInputLaserCode();
	void setCommand_combat(int command, float value);
	void handleL1_combat();
	void handleL2_combat();
	void handleL3_combat();
	void handleL4_combat();
	void handleR1_combat();
	void handleR2_combat();
	void handleR3_combat();
	void handleR4_combat();

	void inputTcnChannel(int num);
	void inputIlsFreq(int num);
	void checkInputTcnChannel();
	void checkInputIlsFreq();

	void setCommandNav(int cmd, float value);

	void handleL1Nav();
	void handleR1Nav();
	void handleL2Nav();
	void handleR2Nav();
	void handleL3Nav();
	void handleR3Nav();
	void handleL4Nav();
	void handleR4Nav();
	void* dayNight_h;
	double dayNight = 0;
	void handleLRFunction(int command, float value);
};