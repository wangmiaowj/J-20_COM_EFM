#include "ufcp.h"
UFCPDevice::UFCPDevice(EDPARAM& edParam, avSimpleElectricSystem& p_elec, avILS& p_ils, Input& p_input) :
	cockpitApi(edParam),
	elec(p_elec),
	ils(p_ils),
	m_input(p_input),
	ufcpPage(edParam.getParamHandle("UFCP_PAGE")),
	navPage(edParam.getParamHandle("NAV_SUB_PAGE")),
	atkWptMax(edParam.getParamHandle("ATK_WPT_MAX"))
{
	params[UFCP_BRT] = EdParam(cockpitApi.getParamHandle("UFCP_BRT"), 0.0, 0.0, 0.006);
	//params[UFCP_PAGE] = EdParam(cockpitApi.getParamHandle("UFCP_BRT"), 0.0);
	//params[NAV_SUB_PAGE] = EdParam(cockpitApi.getParamHandle("NAV_SUB_PAGE"), 0.0);

	params[TCN_CHANNEL] = EdParam(cockpitApi.getParamHandle("TCN_CHANNEL"), 0.0);
	params[TCN_EDIT_CHANNEL] = EdParam(cockpitApi.getParamHandle("TCN_EDIT_CHANNEL"), 0.0);
	params[TCN_TMP_CHANNEL] = EdParam(cockpitApi.getParamHandle("TCN_TMP_CHANNEL"), 0.0);
	params[TCN_ERR_CHANNEL] = EdParam(cockpitApi.getParamHandle("TCN_ERR_CHANNEL"), 0.0);
	params[TCN_WORK_MODE] = EdParam(cockpitApi.getParamHandle("TCN_WORK_MODE"), 0.0);
	params[TCN_AA_MODE] = EdParam(cockpitApi.getParamHandle("TCN_AA_MODE"), 0.0);
	params[TCN_XY] = EdParam(cockpitApi.getParamHandle("TCN_XY"), 0.0);
	params[TCN_STATUS] = EdParam(cockpitApi.getParamHandle("TCN_STATUS"), 0.0);

	params[ILS_FREQ] = EdParam(cockpitApi.getParamHandle("ILS_FREQ"), 0.0);
	params[ILS_EDIT_FREQ] = EdParam(cockpitApi.getParamHandle("ILS_EDIT_FREQ"), 0.0);
	params[ILS_TMP_FREQ] = EdParam(cockpitApi.getParamHandle("ILS_TMP_FREQ"), 0.0);
	params[ILS_ERR_FREQ] = EdParam(cockpitApi.getParamHandle("ILS_ERR_FREQ"), 0.0);
	params[ILS_STATUS] = EdParam(cockpitApi.getParamHandle("ILS_STATUS"), 0.0);

	params[IFF_STATUS] = EdParam(cockpitApi.getParamHandle("IFF_STATUS"), 0.0);
	params[IFF_STATUS_RDR] = EdParam(cockpitApi.getParamHandle("IFF_INTERROGATOR_STATUS"), 0.0);
	params[NCTR_STATUS] = EdParam(cockpitApi.getParamHandle("NCTR_STATUS"), 0.0);

	params[LASER_CODE] = EdParam(cockpitApi.getParamHandle("LASER_CODE"), 1688.0);
	params[LASER_EDIT_CODE] = EdParam(cockpitApi.getParamHandle("LASER_EDIT_CODE"), 0.0);
	params[LASER_ERR_CODE] = EdParam(cockpitApi.getParamHandle("LASER_ERR_CODE"), 0.0);
	params[LASER_TMP_CODE] = EdParam(cockpitApi.getParamHandle("LASER_TMP_CODE"), 0.0);

	params[ATK_WPT] = EdParam(cockpitApi.getParamHandle("ATK_WPT"), 0.0);

	params[AP_STATUS] = EdParam(cockpitApi.getParamHandle("AP_STATUS"), 0.0);
	params[STABILITY] = EdParam(cockpitApi.getParamHandle("STABILITY"), 0.0);
	params[AP_ALT] = EdParam(cockpitApi.getParamHandle("AP_ALT"), 0.0);
	params[AP_RALT] = EdParam(cockpitApi.getParamHandle("AP_RALT"), 0.0);
	params[AP_RESET] = EdParam(cockpitApi.getParamHandle("AP_RESET"), 0.0);

	params[VUHF1] = EdParam(cockpitApi.getParamHandle("VUHF1"), 0.0);
	params[VUHF2] = EdParam(cockpitApi.getParamHandle("VUHF2"), 0.0);
	dayNight_h = cockpitApi.getParamHandle("dayNight_h");
}
void UFCPDevice::zeroInit()
{
	params[UFCP_BRT].tg = 0.0;
	params[UFCP_BRT].cur = 0.0;
}
void UFCPDevice::coldInit()
{
	zeroInit();
}
void UFCPDevice::hotInit()
{
	zeroInit();
	params[UFCP_BRT].tg = 1;
	params[UFCP_BRT].cur = 0.98;
}
void UFCPDevice::airborneInit()
{
	hotInit();
}
void UFCPDevice::handleLRFunction(int command, float value)
{
	double ufcpPageVal = cockpitApi.getParamNumber(ufcpPage);
	if (command == L1_dn)
	{
		if (ufcpPageVal == NAV)
		{
			//todo
			handleL1Nav();
		}
		else if (ufcpPageVal == COMBAT)
		{
			handleL1_combat();
		}
		else if (ufcpPageVal == AP)
		{
			handleL1_ap();
		}
	}
	else if (command == R1_dn)
	{
		if (ufcpPageVal == NAV)
		{
			//todo
			handleR1Nav();
		}
		else if (ufcpPageVal == COMBAT)
		{
			handleR1_combat();
		}
		else if (ufcpPageVal == AP)
		{
			handleR1_ap();
		}
	}
	else if (command == L2_dn)
	{
		if (ufcpPageVal == NAV)
		{
			//todo
			handleL2Nav();
		}
		else if (ufcpPageVal == COMBAT)
		{
			handleL2_combat();
		}
		else if (ufcpPageVal == AP)
		{
			handleL2_ap();
		}
	}
	else if (command == R2_dn)
	{
		if (ufcpPageVal == NAV)
		{
			//todo
			handleR2Nav();
		}
		else if (ufcpPageVal == COMBAT)
		{
			handleR2_combat();
		}
		else if (ufcpPageVal == AP)
		{
			handleR2_ap();
		}
	}
	else if (command == L3_dn)
	{
		if (ufcpPageVal == NAV)
		{
			//todo
			handleL3Nav();
		}
		else if (ufcpPageVal == COMBAT)
		{
			handleL3_combat();
		}
		else if (ufcpPageVal == AP)
		{
			handleL3_ap();
		}
	}
	else if (command == R3_dn)
	{
		if (ufcpPageVal == NAV)
		{
			//todo
			handleR3Nav();
		}
		else if (ufcpPageVal == COMBAT)
		{
			handleR3_combat();
		}
		else if (ufcpPageVal == AP)
		{
			handleR3_ap();
		}
	}
	else if (command == L4_dn)
	{
		if (ufcpPageVal == NAV)
		{
			//todo
			handleL4Nav();
		}
		else if (ufcpPageVal == COMBAT)
		{
			handleL4_combat();
		}
		else if (ufcpPageVal == AP)
		{
			handleL4_ap();
		}
	}
	else if (command == R4_dn)
	{
		if (ufcpPageVal == NAV)
		{
			//todo
			handleR4Nav();
		}
		else if (ufcpPageVal == COMBAT)
		{
			handleR4_combat();
		}
		else if (ufcpPageVal == AP)
		{
			handleR4_ap();
		}
	}
}
void UFCPDevice::setCommand(int command, float value)
{
	double ufcpPageVal = cockpitApi.getParamNumber(ufcpPage);
	if ((command > key0_up - 1 && command < Clear_dn + 1 && value == 1) || (command >= key_A && command <= key_NEG && value == 1))
	{
		if (ufcpPageVal == NAV)
		{
			//todo
			setCommandNav(command, value);
		}
		else if (ufcpPageVal == COMBAT)
		{
			setCommand_combat(command, value);
		}
		else if (ufcpPageVal == AP)
		{
			setCommand_ap(command, value);
		}
	}
	else if (command > L1_up && command < R4_dn + 1 && value == 1)
	{
		handleLRFunction(command, value);
	}
	else if (command == comm_dn && value == 1)
	{

	}
	else if (command == Nav_dn && value == 1)
	{

	}
	else if (command == combat_dn && value == 1)
	{

	}
	else if (command == AP_dn && value == 1)
	{

	}
	else if (command == boat_dn && value == 1)
	{
		if (ufcpPageVal == NAV)
		{

		}
	}
	else if (command == boat_up && value == -1)
	{
		if (ufcpPageVal == NAV)
		{

		}
	}
	else if (command == UFCPBrt)
	{
		params[UFCP_BRT].tg = value;
	}
	/*else if (command == hmdHudMFCD_change_dayNight)
	{
		if (value == 1)
		{
			dayNight = 0;
		}
		else if (value == -1)
		{
			dayNight = 1;
		}
	}*/
}
void UFCPDevice::update(double dt)
{

	updateFreq();
	dayNight = cockpitApi.getParamNumber(dayNight_h);
	/*if (params[NAV_SUB_PAGE].tg==navPages::WPTS)
	{
		updateWpt();
	}
	updateSearchResultList();
	*/
	if (elec.isDC())
	{
		params[UFCP_BRT].dt = dt * 0.5;
	}
	else
	{
		params[UFCP_BRT].dt = 0.0;
		params[UFCP_BRT].cur = 0.0;
		params[UFCP_BRT].tg = 0.0;
	}
	if (params[ATK_WPT].tg > cockpitApi.getParamNumber(atkWptMax))
	{
		params[ATK_WPT].tg = cockpitApi.getParamNumber(atkWptMax);
	}
	for (auto it = params.begin(); it != params.end(); ++it)
	{
		it->second.update(cockpitApi);
	}
	cockpitApi.setParamNumber(params[UFCP_BRT].param, params[UFCP_BRT].cur * (1 - 0.8 * dayNight));
}
int UFCPDevice::iptFreq(int freq, int num)
{
	if (freqSize > 5)
	{
		return freq;
	}
	freq += (num * pow(10, 8 - freqSize));
	freqSize++;
	return freq;
}
void UFCPDevice::updateFreq()
{
	double ilsFreq = ils.getLocalizerFreq();
	params[ILS_FREQ].tg = ilsFreq / 1e6;
}

int UFCPDevice::iptLaserCode(int lsrCode, int num)
{
	if (laserCodeSize > 3)
	{
		return lsrCode;
	}
	lsrCode = lsrCode * 10 + num;
	laserCodeSize++;
	return lsrCode;
}
void UFCPDevice::inputLaserCode(int num)
{
	if (laserCodeSize > 3)
	{
		return;//·ÀÖ¹¼Ä´æÆ÷ÊäÈëÊý¾ÝÒç³ö
	}
	if (params[LASER_EDIT_CODE].tg == 1.0)
	{
		params[LASER_TMP_CODE].tg = iptLaserCode((int)params[LASER_TMP_CODE].tg, num);
	}
	else
	{
		params[LASER_TMP_CODE].tg = 0.0;
	}
}
void UFCPDevice::checkInputLaserCode()
{
	if (params[LASER_EDIT_CODE].tg == 1.0)
	{
		if (params[LASER_TMP_CODE].tg > 0 && params[LASER_TMP_CODE].tg < 100)
		{
			params[LASER_CODE].tg = params[LASER_TMP_CODE].tg;
			params[LASER_EDIT_CODE].tg = 0.0;
			params[LASER_TMP_CODE].tg = 0.0;
			laserCodeSize = 0;
		}
		else
		{
			params[LASER_TMP_CODE].tg = 0.0;
			params[LASER_ERR_CODE].tg = 1.0;
		}
	}
	else
	{
		params[LASER_TMP_CODE].tg = 0.0;
	}
}
void UFCPDevice::setCommand_combat(int command, float value)
{
	if (command > key0_up - 1 && command < key9_dn + 1)
	{
		int num = floor((command - key0_up) * 0.5);
		if (params[LASER_EDIT_CODE].tg == 1.0)
		{
			inputLaserCode(num);
		}
	}
	else if (command == Enter_dn)
	{
		if (params[LASER_EDIT_CODE].tg == 1.0)
		{
			checkInputLaserCode();
		}
	}
	else if (command == Clear_dn)
	{
		params[LASER_ERR_CODE].tg = 0.0;
		params[LASER_TMP_CODE].tg = 0.0;
		laserCodeSize = 0;
	}
}

void UFCPDevice::handleL1_combat()
{
	params[IFF_STATUS].tg = 1 - params[IFF_STATUS].tg;
	params[IFF_STATUS_RDR].tg = params[IFF_STATUS].tg;
}
void UFCPDevice::handleR1_combat() {}
void UFCPDevice::handleL2_combat()
{
	params[NCTR_STATUS].tg = 1 - params[NCTR_STATUS].tg;
}
void UFCPDevice::handleR2_combat() {}
void UFCPDevice::handleL3_combat()
{
	if (params[LASER_EDIT_CODE].tg == 1.0)
	{
		params[LASER_EDIT_CODE].tg = 0.0;//½áÊø¼¤¹â±àÂë±à¼­Ä£Ê½
		params[LASER_TMP_CODE].tg = 0.0;//Çå¿Õ¼Ä´æÆ÷¼¤¹â±àÂë
		params[LASER_ERR_CODE].tg = 0.0;//Òþ²Ø´íÎó¼¤¹â±àÂëÌáÊ¾
		laserCodeSize = 0;
	}
	else
	{
		params[LASER_EDIT_CODE].tg = 1.0;
	}
}
void UFCPDevice::handleR3_combat() {}
void UFCPDevice::handleL4_combat()
{
	if (params[ATK_WPT].tg >= cockpitApi.getParamNumber(atkWptMax) && cockpitApi.getParamNumber(atkWptMax) > 0)
	{
		params[ATK_WPT].tg = 0.0;
	}
	else if (params[ATK_WPT].tg < cockpitApi.getParamNumber(atkWptMax) && cockpitApi.getParamNumber(atkWptMax) > 0)
	{
		params[ATK_WPT].tg++;
	}
}
void UFCPDevice::handleR4_combat() {}

void UFCPDevice::setCommand_ap(int command, float value) {}
void UFCPDevice::handleL1_ap()
{
	params[STABILITY].tg = 1 - params[STABILITY].tg;
	m_input.setAutoPilotAttHold(params[STABILITY].tg);
}

void UFCPDevice::handleR1_ap()
{

}
void UFCPDevice::handleL2_ap()
{
	params[AP_STATUS].tg = 1 - params[AP_STATUS].tg;
	//×Ô¶¯Ñ°Â·´ý¿ª·¢
}
void UFCPDevice::handleR2_ap() {}
void UFCPDevice::handleL3_ap()
{
	params[AP_ALT].tg = 1 - params[AP_ALT].tg;
	m_input.setAutoPilot_ALT(params[AP_ALT].tg);
}
void UFCPDevice::handleR3_ap() {}
void UFCPDevice::handleL4_ap()
{
	params[AP_RALT].tg = 1 - params[AP_RALT].tg;
}
void UFCPDevice::handleR4_ap() {}

void UFCPDevice::inputTcnChannel(int num)
{
	if (params[TCN_TMP_CHANNEL].tg > 10)
	{
		return;//·ÀÖ¹¼Ä´æÆ÷ÊäÈëÊý¾ÝÒç³ö
	}
	if (params[TCN_EDIT_CHANNEL].tg == 1.0)
	{
		params[TCN_TMP_CHANNEL].tg = iptLaserCode(params[TCN_TMP_CHANNEL].tg, num);
	}
	else
	{
		params[TCN_TMP_CHANNEL].tg = 0.0;
	}
}
void UFCPDevice::inputIlsFreq(int num)
{
	if (freqSize > 5)
	{
		return;
	}
	if (params[ILS_EDIT_FREQ].tg == 1.0)
	{
		params[ILS_TMP_FREQ].tg = iptFreq(params[ILS_TMP_FREQ].tg * 1e6, num) / 1e6;
	}
	else
	{
		params[ILS_TMP_FREQ].tg = 0.0;
	}
}
void UFCPDevice::checkInputTcnChannel()
{
	if (params[TCN_EDIT_CHANNEL].tg == 1.0)
	{
		if (params[TCN_TMP_CHANNEL].tg > 0 && params[TCN_TMP_CHANNEL].tg < 100)
		{
			params[TCN_CHANNEL].tg = params[TCN_TMP_CHANNEL].tg;
			params[TCN_TMP_CHANNEL].tg = 0.0;
			params[TCN_EDIT_CHANNEL].tg = 0.0;

		}
		else
		{
			//´íÎóÆµµÀ
			params[TCN_TMP_CHANNEL].tg = 0.0;
			params[TCN_ERR_CHANNEL].tg = 1.0;
		}
	}
	else
	{
		params[TCN_TMP_CHANNEL].tg = 0.0;
	}
}
void UFCPDevice::checkInputIlsFreq()
{
	if (params[ILS_EDIT_FREQ].tg == 1.0)
	{
		if (params[ILS_TMP_FREQ].tg >= 108 && params[ILS_TMP_FREQ].tg < 112)
		{
			//params[ILS_FREQ].tg = params[ILS_TMP_FREQ].tg;
			ils.setFreq(params[ILS_TMP_FREQ].tg);
			params[ILS_TMP_FREQ].tg = 0.0;
			params[ILS_EDIT_FREQ].tg = 0.0;
			freqSize = 0;
		}
		else
		{
			params[ILS_ERR_FREQ].tg = 1.0;
			params[ILS_TMP_FREQ].tg = 0.0;
		}
	}
	else
	{
		params[ILS_TMP_FREQ].tg = 0.0;
	}
}
void UFCPDevice::setCommandNav(int command, float value)
{
	if (command > key0_up - 1 && command < key9_dn + 1)
	{
		int num = floor((command - key0_up) * 0.5);
		if (params[TCN_EDIT_CHANNEL].tg == 1.0)
		{
			inputTcnChannel(num);
		}
		else if (params[ILS_EDIT_FREQ].tg == 1.0)
		{
			inputIlsFreq(num);
		}
	}
	else if (command == Enter_dn)
	{
		if (params[TCN_EDIT_CHANNEL].tg == 1.0)
		{
			checkInputTcnChannel();
		}
		else if (params[ILS_EDIT_FREQ].tg == 1.0)
		{
			checkInputIlsFreq();
		}
	}
	else if (command == Clear_dn)
	{
		params[TCN_TMP_CHANNEL].tg = 0.0;
		params[TCN_ERR_CHANNEL].tg = 0.0;
		params[ILS_TMP_FREQ].tg = 0.0;
		params[ILS_ERR_FREQ].tg = 0.0;
		laserCodeSize = 0;
		freqSize = 0;
	}
}
void UFCPDevice::handleL1Nav()
{
	double navSubPage = cockpitApi.getParamNumber(navPage);
	if (navSubPage == TCN)
	{
		if (params[TCN_EDIT_CHANNEL].tg == 1.0)
		{
			params[TCN_EDIT_CHANNEL].tg = 0.0;//½áÊøËþ¿µÆµµÀ±à¼­Ä£Ê½
			params[TCN_TMP_CHANNEL].tg = 0.0;//Çå¿Õ¼Ä´æÆ÷Ëþ¿µÆµµÀ
			params[TCN_ERR_CHANNEL].tg = 0.0;//Òþ²Ø´íÎóËþ¿µÌáÊ¾
			laserCodeSize = 0;
		}
		else
		{
			params[TCN_EDIT_CHANNEL].tg = 1.0;
		}
	}
	else if (navSubPage == ILS)
	{
		if (params[ILS_EDIT_FREQ].tg == 1.0)
		{
			params[ILS_EDIT_FREQ].tg = 0.0;//½áÊøËþ¿µÆµµÀ±à¼­Ä£Ê½
			params[ILS_TMP_FREQ].tg = 0.0;//Çå¿Õ¼Ä´æÆ÷Ëþ¿µÆµµÀ
			params[ILS_ERR_FREQ].tg = 0.0;//Òþ²Ø´íÎóËþ¿µÌáÊ¾
			freqSize = 0;
		}
		else
		{
			params[ILS_EDIT_FREQ].tg = 1.0;
		}
	}
	else if (navSubPage == VOR)
	{

	}
	else if (navSubPage == WPTS)
	{

	}
	else if (navSubPage == WPT)
	{

	}
	else if (navSubPage == COORD)
	{

	}
	else if (navSubPage == SEARCH)
	{

	}
	else if (navSubPage == ALT)
	{

	}
	else if (navSubPage == SEARCH_RESULT)
	{

	}
}
void UFCPDevice::handleR1Nav()
{
	double navSubPage = cockpitApi.getParamNumber(navPage);
	if (navSubPage == TCN)
	{
		params[TCN_STATUS].tg = 1 - params[TCN_STATUS].tg;
	}
}
void UFCPDevice::handleL2Nav()
{
	double navSubPage = cockpitApi.getParamNumber(navPage);
	if (navSubPage == TCN)
	{
		params[TCN_WORK_MODE].tg = 1 - params[TCN_WORK_MODE].tg;
	}
	else if (navSubPage == ILS)
	{
		params[ILS_STATUS].tg = 1 - params[ILS_STATUS].tg;
		if (params[ILS_STATUS].tg == 1)
		{
			ils.enable();
		}
		else
		{
			ils.disable();
		}
	}
}
void UFCPDevice::handleR2Nav()
{
	double navSubPage = cockpitApi.getParamNumber(navPage);
}
void UFCPDevice::handleL3Nav()
{
	double navSubPage = cockpitApi.getParamNumber(navPage);
	if (navSubPage == TCN)
	{
		params[TCN_AA_MODE].tg = 1 - params[TCN_AA_MODE].tg;
	}
}
void UFCPDevice::handleR3Nav()
{
	double navSubPage = cockpitApi.getParamNumber(navPage);
}
void UFCPDevice::handleL4Nav()
{
	double navSubPage = cockpitApi.getParamNumber(navPage);
	if (navSubPage == TCN)
	{
		params[TCN_XY].tg = 1 - params[TCN_XY].tg;
	}
}
void UFCPDevice::handleR4Nav()
{
	double navSubPage = cockpitApi.getParamNumber(navPage);
}