#include "ufcp.h"
UFCPDevice::UFCPDevice(EDPARAM& edParam, avSimpleElectricSystem& p_elec, avUHF_ARC_164& p_uhf, avVHF_ARC_186& p_vhf, avILS& p_ils, Input& p_input) :
	cockpitApi(edParam),
	elec(p_elec),
	ils(p_ils),
	uhf(p_uhf),
	vhf(p_vhf),
	m_input(p_input),
	ufcpPage(edParam.getParamHandle("UFCP_PAGE")),
	navPage(edParam.getParamHandle("NAV_SUB_PAGE"))
{
	params[UFCP_BRT] = EdParam(cockpitApi.getParamHandle("UFCP_BRT"), 0.0, 0.0, 0.006);
	//params[UFCP_PAGE] = EdParam(cockpitApi.getParamHandle("UFCP_BRT"), 0.0);

	params[COMM1_FREQ] = EdParam(cockpitApi.getParamHandle("COMM1_FREQ"), 0.0);
	params[COMM1_TMP_FREQ] = EdParam(cockpitApi.getParamHandle("COMM1_TMP_FREQ"), 0.0);
	params[COMM1_ERR_FREQ] = EdParam(cockpitApi.getParamHandle("COMM1_ERR_FREQ"), 0.0);
	params[COMM1_EDIT_FREQ] = EdParam(cockpitApi.getParamHandle("COMM1_EDIT_FREQ"), 0.0);
	params[COMM1_AMFM] = EdParam(cockpitApi.getParamHandle("COMM1_AMFM"), "AM");
	params[COMM1_PRE] = EdParam(cockpitApi.getParamHandle("COMM1_PRE"), 1.0);
	params[COMM1_EDIT_PRE] = EdParam(cockpitApi.getParamHandle("COMM1_EDIT_PRE"), 0.0);
	params[COMM1_PRE_MAN] = EdParam(cockpitApi.getParamHandle("COMM1_PRE_MAN"), 0.0);
	params[COMM1_PRE_FREQ] = EdParam(cockpitApi.getParamHandle("COMM1_PRE_FREQ"), 0.0);

	params[COMM2_FREQ] = EdParam(cockpitApi.getParamHandle("COMM2_FREQ"), 0.0);
	params[COMM2_TMP_FREQ] = EdParam(cockpitApi.getParamHandle("COMM2_TMP_FREQ"), 0.0);
	params[COMM2_ERR_FREQ] = EdParam(cockpitApi.getParamHandle("COMM2_ERR_FREQ"), 0.0);
	params[COMM2_EDIT_FREQ] = EdParam(cockpitApi.getParamHandle("COMM2_EDIT_FREQ"), 0.0);
	params[COMM2_AMFM] = EdParam(cockpitApi.getParamHandle("COMM2_AMFM"), "AM");
	params[COMM2_PRE] = EdParam(cockpitApi.getParamHandle("COMM2_PRE"), 1.0);
	params[COMM2_EDIT_PRE] = EdParam(cockpitApi.getParamHandle("COMM2_EDIT_PRE"), 0.0);
	params[COMM2_PRE_MAN] = EdParam(cockpitApi.getParamHandle("COMM2_PRE_MAN"), 0.0);
	params[COMM2_PRE_FREQ] = EdParam(cockpitApi.getParamHandle("COMM2_PRE_FREQ"), 0.0);

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

	params[LASER_CODE] = EdParam(cockpitApi.getParamHandle("LASER_CODE"), 0.0);
	params[LASER_EDIT_CODE] = EdParam(cockpitApi.getParamHandle("LASER_EDIT_CODE"), 0.0);
	params[LASER_ERR_CODE] = EdParam(cockpitApi.getParamHandle("LASER_ERR_CODE"), 0.0);
	params[LASER_TMP_CODE] = EdParam(cockpitApi.getParamHandle("LASER_TMP_CODE"), 0.0);

	params[AP_STATUS] = EdParam(cockpitApi.getParamHandle("AP_STATUS"), 0.0);
	params[STABILITY] = EdParam(cockpitApi.getParamHandle("STABILITY"), 0.0);
	params[AP_ALT] = EdParam(cockpitApi.getParamHandle("AP_ALT"), 0.0);
	params[AP_RALT] = EdParam(cockpitApi.getParamHandle("AP_RALT"), 0.0);
	params[AP_RESET] = EdParam(cockpitApi.getParamHandle("AP_RESET"), 0.0);

	params[VUHF1] = EdParam(cockpitApi.getParamHandle("VUHF1"), 0.0);
	params[VUHF2] = EdParam(cockpitApi.getParamHandle("VUHF2"), 0.0);
	dayNight_h = cockpitApi.getParamHandle("dayNight_h");

	initComm();
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
		if (ufcpPageVal == COMM)
		{
			handleL1_comm();
		}
		else if (ufcpPageVal == NAV)
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
		if (ufcpPageVal == COMM)
		{
			handleR1_comm();
		}
		else if (ufcpPageVal == NAV)
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
		if (ufcpPageVal == COMM)
		{
			handleL2_comm();
		}
		else if (ufcpPageVal == NAV)
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
		if (ufcpPageVal == COMM)
		{
			handleR2_comm();
		}
		else if (ufcpPageVal == NAV)
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
		if (ufcpPageVal == COMM)
		{
			handleL3_comm();
		}
		else if (ufcpPageVal == NAV)
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
		if (ufcpPageVal == COMM)
		{
			handleR3_comm();
		}
		else if (ufcpPageVal == NAV)
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
		if (ufcpPageVal == COMM)
		{
			handleL4_comm();
		}
		else if (ufcpPageVal == NAV)
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
		if (ufcpPageVal == COMM)
		{
			handleR4_comm();
		}
		else if (ufcpPageVal == NAV)
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
		if (ufcpPageVal == COMM)
		{
			setCommand_comm(command, value);
		}
		else if (ufcpPageVal == NAV)
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
		if (ufcpPageVal == COMM)
		{
			changeChannel_comm(value);
		}
		else if (ufcpPageVal == NAV)
		{

		}
	}
	else if (command == boat_up && value == -1)
	{
		if (ufcpPageVal == COMM)
		{
			changeChannel_comm(value);
		}
		else if (ufcpPageVal == NAV)
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
	if (!init)
	{
		try
		{
			cockpitApi.performClickAction(cockpitApi.ELECTRIC_SYSTEM, UFCPBrt, 1.0);
		}
		catch (const MyException& e)
		{
			e.printMsg();
		}
	}
	updateFreq_comm();
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
	for (auto it = params.begin(); it != params.end(); ++it)
	{
		it->second.update(cockpitApi);
	}
}

void UFCPDevice::updateFreq_comm()
{
	int freq = uhf.getFreq();
	params[COMM1_FREQ].tg = freq / 1e6;
	freq = vhf.getFreq();
	params[COMM2_FREQ].tg = freq / 1e6;

	params[COMM1_PRE_FREQ].tg = uhfPresets[(int)params[COMM1_PRE].tg] / 1E6;
	if (vhf.isFM())
	{
		params[COMM2_PRE_FREQ].tg = vhfFmPresets[(int)params[COMM2_PRE].tg] / 1E6;
	}
	else
	{
		params[COMM2_PRE_FREQ].tg = vhfAmPresets[(int)params[COMM2_PRE].tg] / 1E6;
	}
	double ilsFreq = ils.getLocalizerFreq();
	params[ILS_FREQ].tg = ilsFreq / 1e6;
	params[VUHF1].tg = uhf.getFreq();
	params[VUHF2].tg = vhf.getFreq();
}
void UFCPDevice::initComm()
{
	uhfPresets[1] = 305000000;
	uhfPresets[2] = 264000000;
	uhfPresets[3] = 265000000;
	uhfPresets[4] = 256000000;
	uhfPresets[5] = 254000000;
	uhfPresets[6] = 250000000;
	uhfPresets[7] = 270000000;
	uhfPresets[8] = 257000000;
	uhfPresets[9] = 255000000;
	uhfPresets[10] = 262000000;
	uhfPresets[11] = 259000000;
	uhfPresets[12] = 268000000;
	uhfPresets[13] = 269000000;
	uhfPresets[14] = 260000000;
	uhfPresets[15] = 263000000;
	uhfPresets[16] = 261000000;
	uhfPresets[17] = 267000000;
	uhfPresets[18] = 251000000;
	uhfPresets[19] = 253000000;
	uhfPresets[20] = 266000000;

	vhfAmPresets[1] = 121000000;
	vhfAmPresets[2] = 131000000;
	vhfAmPresets[3] = 141000000;
	vhfAmPresets[4] = 126000000;
	vhfAmPresets[5] = 130000000;
	vhfAmPresets[6] = 133000000;
	vhfAmPresets[7] = 122000000;
	vhfAmPresets[8] = 128000000;
	vhfAmPresets[9] = 124000000;
	vhfAmPresets[10] = 134000000;
	vhfAmPresets[11] = 138000000;
	vhfAmPresets[12] = 125000000;
	vhfAmPresets[13] = 135000000;
	vhfAmPresets[14] = 137000000;
	vhfAmPresets[15] = 136000000;
	vhfAmPresets[16] = 123000000;
	vhfAmPresets[17] = 132000000;
	vhfAmPresets[18] = 127000000;
	vhfAmPresets[19] = 129000000;
	vhfAmPresets[20] = 139000000;

	vhfFmPresets[1] = 38400000;
	vhfFmPresets[2] = 40400000;
	vhfFmPresets[3] = 42400000;
	vhfFmPresets[4] = 39400000;
	vhfFmPresets[5] = 40200000;
	vhfFmPresets[6] = 40800000;
	vhfFmPresets[7] = 38600000;
	vhfFmPresets[8] = 39800000;
	vhfFmPresets[9] = 39000000;
	vhfFmPresets[10] = 41000000;
	vhfFmPresets[11] = 41800000;
	vhfFmPresets[12] = 39200000;
	vhfFmPresets[13] = 41200000;
	vhfFmPresets[14] = 41600000;
	vhfFmPresets[15] = 41400000;
	vhfFmPresets[16] = 38800000;
	vhfFmPresets[17] = 40600000;
	vhfFmPresets[18] = 39600000;
	vhfFmPresets[19] = 40000000;
	vhfFmPresets[20] = 42000000;
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

void UFCPDevice::inputFreq_comm(int num)
{
	if (freqSize > 5)
	{
		return;//防止寄存器输入数据溢出
	}
	if (params[COMM1_EDIT_FREQ].tg == 1.0)
	{
		params[COMM1_TMP_FREQ].tg = iptFreq(params[COMM1_TMP_FREQ].tg * 1e6, num) / 1e6;
	}
	else if (params[COMM2_EDIT_FREQ].tg == 1.0)
	{
		params[COMM2_TMP_FREQ].tg = iptFreq(params[COMM2_TMP_FREQ].tg * 1e6, num) / 1e6;
	}
	else
	{
		params[COMM1_TMP_FREQ].tg = 0.0;
		params[COMM2_TMP_FREQ].tg = 0.0;
	}
}
void UFCPDevice::checkInputFreq_comm()
{
	if (params[COMM1_EDIT_FREQ].tg == 1.0)
	{
		if (uhf.is_frequency_in_range(params[COMM1_TMP_FREQ].tg * 1e6))
		{
			uhf.setFreq(params[COMM1_TMP_FREQ].tg * 1e6);
			params[COMM1_EDIT_FREQ].tg = 0.0;
			params[COMM1_TMP_FREQ].tg = 0.0;
			freqSize = 0;
		}
		else
		{
			params[COMM1_TMP_FREQ].tg = 0.0;
			params[COMM1_ERR_FREQ].tg = 1.0;
			freqSize = 0;
		}
	}
	else if (params[COMM2_EDIT_FREQ].tg == 1.0)
	{
		if (vhf.is_frequency_in_range(params[COMM2_TMP_FREQ].tg * 1e6))
		{
			vhf.setFreq(params[COMM2_TMP_FREQ].tg * 1e6);
			params[COMM2_EDIT_FREQ].tg = 0.0;
			params[COMM2_TMP_FREQ].tg = 0.0;
			freqSize = 0;
		}
		else
		{
			params[COMM2_TMP_FREQ].tg = 0.0;
			params[COMM2_ERR_FREQ].tg = 1.0;
			freqSize = 0;
		}
	}
	else
	{
		params[COMM1_TMP_FREQ].tg = 0.0;
		params[COMM1_ERR_FREQ].tg = 0.0;
		params[COMM2_TMP_FREQ].tg = 0.0;
		params[COMM2_ERR_FREQ].tg = 0.0;
		freqSize = 0;
	}
}
void UFCPDevice::setCommand_comm(int command, float value)
{
	if (params[COMM1_EDIT_FREQ].tg == 1.0)
	{
		if (command > key0_up - 1 && command < key9_dn + 1)
		{
			int num = floor((command - key0_up) * 0.5);
			inputFreq_comm(num);
		}
		else if (command == Enter_dn)
		{
			checkInputFreq_comm();
		}
		else if (command == Clear_dn)
		{
			params[COMM1_TMP_FREQ].tg = 0.0;
			params[COMM1_ERR_FREQ].tg = 0.0;
			freqSize = 0;
		}
	}
	else if (params[COMM2_EDIT_FREQ].tg == 1.0)
	{
		if (command > key0_up - 1 && command < key9_dn + 1)
		{
			int num = floor((command - key0_up) * 0.5);
			inputFreq_comm(num);
		}
		else if (command == Enter_dn)
		{
			checkInputFreq_comm();
		}
		else if (command == Clear_dn)
		{
			params[COMM2_TMP_FREQ].tg = 0.0;
			params[COMM2_ERR_FREQ].tg = 0.0;
			freqSize = 0;
		}
	}
}
void UFCPDevice::handleL1_comm()
{
	if (params[COMM1_EDIT_FREQ].tg == 1.0)
	{
		params[COMM1_EDIT_FREQ].tg = 0.0;//结束电台1频率编辑模式
		params[COMM1_TMP_FREQ].tg = 0.0;//清空寄存器频率1
		params[COMM1_ERR_FREQ].tg = 0.0;//隐藏错误频率1提示
		freqSize = 0;
	}
	else if (params[COMM1_PRE_MAN].tg == 0.0)
	{
		params[COMM1_EDIT_FREQ].tg = 1.0;//开启频率1编辑模式
		params[COMM2_EDIT_FREQ].tg = 0.0;//只能同时编辑一个电台的频率
	}
}
void UFCPDevice::handleR1_comm()
{
	if (params[COMM2_EDIT_FREQ].tg == 1.0)
	{
		params[COMM2_EDIT_FREQ].tg = 0.0;//结束电台1频率编辑模式
		params[COMM2_TMP_FREQ].tg = 0.0;//清空寄存器频率1
		params[COMM2_ERR_FREQ].tg = 0.0;//隐藏错误频率1提示
		freqSize = 0;
	}
	else if (params[COMM2_PRE_MAN].tg == 0.0)
	{
		params[COMM1_EDIT_FREQ].tg = 0.0;//开启频率1编辑模式
		params[COMM2_EDIT_FREQ].tg = 1.0;//只能同时编辑一个电台的频率
	}
}
void UFCPDevice::handleL2_comm()
{
	if (strcmp(params[COMM1_AMFM].tgText, "AM") == 0)
	{
		params[COMM1_AMFM].tgText = "FM";
	}
	else
	{
		params[COMM1_AMFM].tgText = "AM";
	}
	try
	{
		printf("==================%d====================\n", cockpitApi.UHF_get_modulation());
	}
	catch (const MyException& e)
	{
		printf("============ERR======%s==========ERR==========\n", e.what());
	}
}
void UFCPDevice::handleR2_comm()
{
	if (strcmp(params[COMM2_AMFM].tgText, "AM") == 0)
	{
		params[COMM2_AMFM].tgText = "FM";
		vhf.setFM();
		if (params[COMM2_PRE_MAN].tg == 1.0)
		{
			if (params[COMM2_PRE].tg > vhfFmPresets.size())
			{
				params[COMM2_PRE].tg = 1.0;
			}
			vhf.setFreq(vhfFmPresets[(int)params[COMM2_PRE].tg]);
		}
	}
	else
	{
		params[COMM2_AMFM].tgText = "AM";
		vhf.setAM();
	}
}
void UFCPDevice::handleL3_comm()
{
	if (params[COMM1_PRE_MAN].tg == 1.0)
	{
		params[COMM1_EDIT_PRE].tg = 1.0 - params[COMM1_EDIT_PRE].tg;
		params[COMM2_EDIT_PRE].tg = 0.0; //只能同时切换1个电台的预设频道编号
	}
	else
	{
		uhfMan = params[COMM1_FREQ].tg * 1e6; //切换到预设频道时先把当前手动频率存到预设频道的M号
		params[COMM1_PRE_MAN].tg = 1.0;
		params[COMM1_EDIT_FREQ].tg = 0.0;
		params[COMM1_TMP_FREQ].tg = 0.0;
		uhf.setFreq(uhfPresets[(int)params[COMM1_PRE].tg]);
	}
}
void UFCPDevice::handleR3_comm()
{
	if (params[COMM2_PRE_MAN].tg == 1.0)
	{
		params[COMM1_EDIT_PRE].tg = 0.0; //只能同时切换1个电台的预设频道编号
		params[COMM2_EDIT_PRE].tg = 1.0 - params[COMM2_EDIT_PRE].tg;
	}
	else
	{
		if (vhf.isFM())
		{
			vhfFmMan = params[COMM2_FREQ].tg * 1e6; //切换到预设频道时先把当前手动频率存到预设频道的M号
			vhf.setFreq(vhfFmPresets[(int)params[COMM2_PRE].tg]);
		}
		else
		{
			vhfAmMan = params[COMM2_FREQ].tg * 1e6; //切换到预设频道时先把当前手动频率存到预设频道的M号
			vhf.setFreq(vhfAmPresets[(int)params[COMM2_PRE].tg]);
		}
		params[COMM2_PRE_MAN].tg = 1.0;
		params[COMM2_EDIT_FREQ].tg = 0.0;
		params[COMM2_TMP_FREQ].tg = 0.0;
	}
}
void UFCPDevice::handleL4_comm()
{
	if (params[COMM1_PRE_MAN].tg == 1.0)
	{
		uhf.setFreq(uhfMan); //切换回手动频率时将之前存储的手动频率还原到这里
		params[COMM1_PRE_MAN].tg = 0.0;
	}
}
void UFCPDevice::handleR4_comm()
{
	if (params[COMM2_PRE_MAN].tg == 1.0)
	{
		if (vhf.isFM())
		{
			vhf.setFreq(vhfFmMan); //切换回手动频率时将之前存储的手动频率还原到这里
		}
		else
		{
			vhf.setFreq(vhfAmMan); //切换回手动频率时将之前存储的手动频率还原到这里
		}
		params[COMM2_PRE_MAN].tg = 0.0;
	}
}

void UFCPDevice::changeChannel_comm(int num)
{
	if (params[COMM1_EDIT_PRE].tg == 1.0)
	{
		params[COMM1_PRE].tg = clamp(params[COMM1_PRE].tg + num, 1, uhfPresets.size());
		uhf.setFreq(uhfPresets[(int)params[COMM1_PRE].tg]);
	}
	else if (params[COMM2_EDIT_PRE].tg == 1.0)
	{
		if (vhf.isFM())
		{
			params[COMM2_PRE].tg = clamp(params[COMM2_PRE].tg + num, 1, vhfFmPresets.size());
			vhf.setFreq(vhfFmPresets[(int)params[COMM2_PRE].tg]);
		}
		else
		{
			params[COMM2_PRE].tg = clamp(params[COMM2_PRE].tg + num, 1, vhfAmPresets.size());
			vhf.setFreq(vhfAmPresets[(int)params[COMM2_PRE].tg]);
		}
	}
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
		return;//防止寄存器输入数据溢出
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
		params[LASER_EDIT_CODE].tg = 0.0;//结束激光编码编辑模式
		params[LASER_TMP_CODE].tg = 0.0;//清空寄存器激光编码
		params[LASER_ERR_CODE].tg = 0.0;//隐藏错误激光编码提示
		laserCodeSize = 0;
	}
	else
	{
		params[LASER_EDIT_CODE].tg = 1.0;
	}
}
void UFCPDevice::handleR3_combat() {}
void UFCPDevice::handleL4_combat() {}
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
	//自动寻路待开发
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
		return;//防止寄存器输入数据溢出
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
			//错误频道
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
			params[TCN_EDIT_CHANNEL].tg = 0.0;//结束塔康频道编辑模式
			params[TCN_TMP_CHANNEL].tg = 0.0;//清空寄存器塔康频道
			params[TCN_ERR_CHANNEL].tg = 0.0;//隐藏错误塔康提示
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
			params[ILS_EDIT_FREQ].tg = 0.0;//结束塔康频道编辑模式
			params[ILS_TMP_FREQ].tg = 0.0;//清空寄存器塔康频道
			params[ILS_ERR_FREQ].tg = 0.0;//隐藏错误塔康提示
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