#include "FlightModel.h"

//=========================================================================//
//
//		FILE NAME	: FlightModel.cpp
//		AUTHOR		: Joshua Nelson & Paul Stich
//		Copyright	: Joshua Nelson & Paul Stich
//		DATE		: December 2021
//
//		DESCRIPTION	: Every force that is needed for the flight-simulation. 
//					  As well as the Camera-Shaker and rotation of Forces and
//					  moments regarding Alpha an beta.
//					  
//================================ Includes ===============================//
//=========================================================================//


FlightModel::FlightModel
(
	State& state,
	Input& input,
	Engine& engine, //NEU 21Feb21
	Airframe& airframe,
	Fuelsystem& fuelsystem,
	AutoPilot& autoPilot,
	avSimpleElectricSystem& elec,
	EDPARAM& edParam
	//der letzte Eintrag hier darf kein Komma haben!
) :
	m_state(state),
	m_input(input),
	m_engine(engine), //NEU 21Feb21
	m_airframe(airframe),
	m_fuelSystem(fuelsystem),
	m_autoPilot(autoPilot),
	m_elec(elec),
	m_cockpitAPI(edParam),

	m_scalarVelocity(0.0),
	m_scalarVelocitySquared(0.0),
	m_aoaDot(0.0),
	m_aoaPrevious(0.0),

	m_k(0.0),
	m_q(0.0),
	m_p(0.0),

	m_cockpitShake(0.0),
	m_shakeDuration(0.1),

	//-----"init" Tables AeroData_1.h + FlightModel.h-----------
	//-----------------Pitch------------------------------------
	Cmalpha(DAT_Cma_SL, CON_Cma_SL_min, CON_Cma_SL_max),
	CmalphaNEW(DAT_Cma_full, CON_Cma_full_min, CON_Cma_full_max),
	Cmde(DAT_Cmde_SL, CON_Cmde_SL_min, CON_Cmde_SL_max),
	CmdeNEW(DAT_Cmde_full, CON_Cmde_full_min, CON_Cmde_full_max),
	Cmq(DAT_Cmq, CON_Cmq_min, CON_Cmq_max),
	CmadotNEW(DAT_CmaDOT_Full, CON_CmaDOT_Full_Min, CON_CmaDOT_Full_Max),
	CmM(DAT_CmM, CON_Cmq_min, CON_Cmq_max),
	CmTuck(DAT_CmTuck, CON_CmTuck_min, CON_CmTuck_max),
	CmFlap(DAT_CmFlap, CON_CmFlap_min, CON_CmFlap_max),
	CmFuel(DAT_CmFuel, CON_CmFuel_min, CON_CmFuel_max),
	CmFuelMultiS(DAT_CmFuelMultiS, CON_CmFuelMultiS_min, CON_CmFuelMultiS_max),
	CmqStAg(DAT_CmqStAg, CON_CmqStAg_Min, CON_CmqStAg_Max),
	CmaDOTStAg(DAT_CmaDOTStAg, CON_CmaDOTStAg_Min, CON_CmaDOTStAg_Max),
	//----------------DRAG---------------------------------------
	CDmin(DAT_CDmin, CON_CDminmin, CON_CDminmax),
	CDmach(DAT_CDmach_SL, CON_CDmach_SLmin, CON_CDmach_SLmax),
	CDa(DAT_CDa, CON_CDa_min, CON_CDa_max),
	CDeng(DAT_CDeng, CON_CDengmin, CON_CDengmax),
	CDOM(DAT_CD_OM, CON_CD_OM_Min, CON_CD_OM_Max),
	CDminAD(DAT_CDminAD, CON_CDminAD_Min, CON_CDminAD_Max),
	CDOK(DAT_CD_OK, CON_CD_OK_Min, CON_CD_OK_Max),
	//---------------LIFT----------------------------------------
	CLmax(DAT_CLmax, CON_CLmaxmin, CON_CLmaxmax),
	CLmach(DAT_CLmach_SL, CON_CLmach_SLmin, CON_CLmach_SLmax),
	CLa(DAT_CLa, CON_CLamin, CON_CLamax),
	CLds(DAT_CLds, CON_CLdsmin, CON_CLdsmax),
	//CLa_FL1(DAT_CLa_FL1, CON_CLa_FL1_Min, CON_CLa_FL1_Max),
	CLa_FL2(DAT_CLa_FL2, CON_CLa_FL2_Min, CON_CLa_FL2_Max),
	CL_FlStat(DAT_CL_FlStat, CON_CL_FlStat_Min, CON_CL_FlStat_Max), //Static Flap Lift "base-lift"
	//--------------ROLL----------------------------------------
	Clb(DAT_Clb_SL, CON_Clb_SLmin, CON_Clb_SLmax),
	Clp(DAT_Clp_SL, CON_Clp_SLmin, CON_Clp_SLmax),
	Clda(DAT_Clda, CON_Cldamin, CON_Cldamax),
	Clr(DAT_Clr_SL, CON_Clr_SLmin, CON_Clr_SLmax),
	Cldr(DAT_Cldr_full, CON_Cldr_min, CON_Cldr_max),
	ClrStab(DAT_ClrStab, CON_ClrStab_Min, CON_ClrStab_Max),
	ClpStab(DAT_ClpStab, CON_ClpStab_Min, CON_ClpStab_Max),
	//---------------YAW---------------------------------------
	CnbNEW(DAT_Cnb_Full, CON_Cnb_Full_Min, CON_Cnb_Full_Max),
	Cndr(DAT_Cndr, CON_Cndrmin, CON_Cndrmax),
	Cnr(DAT_Cnr, CON_Cnrmin, CON_Cnrmax),
	Cnp(DAT_Cnp, CON_Cnpmin, CON_Cnpmax),
	Cnda(DAT_Cnda, CON_Cndamin, CON_Cndamax),
	CnStab(DAT_CnStab, CON_CnStab_min, CON_CnStab_max),
	//------------SideForce------------------------------------
	Cyb(DAT_Cyb, CON_Cybmin, CON_Cybmax),
	Cydr(DAT_Cydr, CON_Cydrmin, CON_Cydrmax),

	//---------------Thrust------------------------------------
	//PMax(DAT_PMax, CON_PMaxmin, CON_PMaxmax)
	//PFor(DAT_PFor, CON_PFormin, CON_PFormax)
	ThinAM(DAT_ThinAM, CON_ThinAM_Min, CON_ThinAM_Max),
	AdThrLAlt(DAT_AdThrLAlt, CON_AdThrLAlt_Min, CON_AdThrLAlt_Max),
	AdThrLAltMulti(DAT_AdThrLaltMulti, CON_AdThrLAltMulti_Min, CON_AdThrLAltMulti_Max),
	//---------------Misc-------------------------------------
	// --------------FCS-------------------------------------
	FCSPitch(DAT_FCS_Pitch, CON_FCS_Pitch_Min, CON_FCS_Pitch_Max),
	CmaMulti(DAT_CmaMulti, CON_CmaMultiMin, CON_CmaMultiMax),
	CmqMulti(DAT_CmqMulti, CON_CmaMultiMin, CON_CmaMultiMax),
	//--------------PitchUP and Stall------------------------
	PitAoA(DAT_PitchAoA, CON_PitAoAMin, CON_PitAoAMax),
	PitMult(DAT_PitchMult, CON_PitMulMin, CON_PitMulMax),
	StAoA(DAT_StallAoA, CON_StAoAMin, CON_StAoAMax),
	StAoAMulti(DAT_StAoAMulti, CON_StAoAMulti_Min, CON_StAoAMulti_Max),
	CLzero(DAT_CLzero, CON_CLzeroMin, CON_CLzeroMax),
	CLaCorr(DAT_CLaCorr, CON_CLaCorr_min, CON_CLaCorr_max),
	FinalStallValue(DAT_StallFinalValue, CON_StallFinalValue_min, CON_StallFinalValue_max)

	//der letzte Eintrag darf KEIN Komma haben...



	//genau so für jede DATA Table (DATA, min , max)
{
	//printf("Hello\n");
}

void FlightModel::zeroInit()
{
	m_q = 0.0;
	m_p = 0.0;
	m_k = 0.0;
	CLblc = 0.0;

	//----------NEU TESTWEISE-----------------
	//----------TESTWEISE um Spin Probleme zu testen bei Rotation der Forces-------
	//----------HIER Rotation der Momente von der Stability- ind die Body-Axis----
	//----------Siehe auch CR-2144 Appendix B am Anfang--------------------------
	//----------Verwednung in der Formel von Allerton in der rottierten Form zum Testen--
	Clb_b = 0.0;
	Clp_b = 0.0;
	Clr_b = 0.0;
	Clda_b = 0.0;
	Cldr_b = 0.0;

	Cnb_b = 0.0;
	Cnp_b = 0.0;
	Cnr_b = 0.0;
	Cnda_b = 0.0;
	Cndr_b = 0.0;

	CosAoA = 0.0;
	SinusAoA = 0.0;
	CosAoA2 = 0.0;
	SinusAoA2 = 0.0;

	m_corrAoA = 0.0;
	m_corrBeta = 0.0;

	Cnr_S = 0.0;
	Clr_S = 0.0;

	m_CnrStab = 0.0;
	m_ClrStab = 0.0;
	m_ClpStab = 0.0;

	m_CmqStAg = 0.0;
	m_CmaDOTStAg = 0.0;
	m_CnpStab = 0.0;

	m_CybStab = 0.0;

	m_yawStabSystem = 0.0;
	m_pitchStabSystem = 0.0;
	m_rollStabSystem = 0.0;
	m_StabAugSys = 0.0;


	//-------------Nach dem Test ggf. auskommentieren oder entfernen---------------
	//------------ENDE NEU--------------------------------------------------------

	m_thinAirMulti = 0.0;

	m_scalarVelocitySquared = 0.0;
	m_scalarVelocity = 0.0;
	m_aoaPrevious = 0.0;
	//m_aoaPrevious = 0.0;
	m_aoaDot = 0.0;

	m_ailDeflection = 0.0;
	m_rudDeflection = 0.0;
	m_elevDeflection = 0.0;

	//m_state.m_mach = 0.0;
	//m_state.m_beta = 0.0;
	//m_state.m_omega = 0.0;

	m_pitchup = 0.0;
	m_stallMult = 0.0;


	m_zeroLift = 0.0;
	m_setLiftZero = 0.0;
	m_stallIndRoll = 0.0;
	m_stallIndRock = 0.0;
	m_stallIndDrag = 0.0;
	m_wingStalling = false;
	m_CLaCorrMulti = 0.0;
	m_noVertTailEff = 0.0;
	m_inducedRollingRight = false;
	m_inducedRollingLeft = false;
	m_inducedPitZ = 0.0;
	m_setZeroCnBeta = 0.0;
	m_deactivateWingRock = false;
	m_CnBetaMult = 0.0;

	M_mcrit = 0.0;
	M_mcrit_b = 0.0;

	CDwave = 0.0;

	CDi = 0.0;

	CD_OverMach = 0.0;

	m_cdminADD = 0.0;

	m_l_addThrust = 0.0;
	m_r_addThrust = 0.0;
	m_l_thrustForce = 0.0;
	m_r_thrustForce = 0.0;

	CD_brFlap = 0.0;
	m_flapBroken = false;

	CDGear = 0.0;
	CDFlaps = 0.0;
	CLFlaps = 0.0;
	CDBrk = 0.0;
	CDBrkCanard = 0.0;
	CDBrkCht = 0.0;
	CLblc = 0.0;

	m_rWingDamageCL = 0.0;
	m_rWingDamageCD = 0.0;
	m_lWingDamageCL = 0.0;
	m_lWingDamageCD = 0.0;
	m_ailDamage = 0.0;
	m_flapDamage = 0.0;
	m_rSpdBrkDamage = 0.0;
	m_rSpdBrkDamage = 0.0;
	m_hStabDamage = 0.0;
	m_vStabDamage = 0.0;


	m_moment = Vec3();
	m_force = Vec3();

	gearShake = false;
	prevGearShake = false;

	m_thrustTilt = 0.0;
	m_minusThrust = 0.0;
	m_plusThrust = 0.0;
	m_pitchAdjustFBW = 0.0;

	m_pitchHoverThrust = 0.0;
	m_rollHoverThrust = 0.0;
	m_yawHoverThrust = 0.0;

	m_pitchReduceAoA = 0.0;
	m_yawStabBoost = 0.0;
	m_rollBoost = 0.0;
	m_stickKicker = 0.0;
	m_cmaMultiFBW = 0.0;
	m_cmqMultiFBW = 0.0;

}

void FlightModel::coldInit()
{
	zeroInit();
}

void FlightModel::hotInit()
{
	zeroInit();
}

void FlightModel::airborneInit()
{
	zeroInit();
}

void FlightModel::calculateAeroRotateMoments()
{
	//---------------AoA Begrenzungsfunktion für WeightOnWheels-----------------
	if ((m_airframe.getWeightOnWheels() != 0.0) && (m_state.m_mach < 0.07))
	{
		if (m_state.m_aoa > 0.35)
		{
			m_corrAoA = 0.35;
		}
		if (m_state.m_aoa < -0.09)
		{
			m_corrAoA = -0.09;
		}
	}
	else
	{
		m_corrAoA = m_state.m_aoa;
	}

	if ((m_airframe.getWeightOnWheels() != 0.0) && (m_state.m_mach < 0.07))
	{
		if (m_state.m_beta > 0.10)
		{
			m_corrBeta = 0.10;
		}
		if (m_state.m_beta < -0.10)
		{
			m_corrBeta = -0.10;
		}
	}
	else
	{
		m_corrBeta = m_state.m_beta;
	}

	//----------TESTWEISE um Spin Probleme zu testen bei Rotation der Forces-------
	//----------HIER Rotation der Momente von der Stability- ind die Body-Axis----
	//----------Verwednung in der Formel von Allerton in der rottierten Form zum Testen--

	//----------Yaw und Roll inklusive Stabilitäts-System-------------------------
	Clp_S = Clp(m_state.m_mach) + m_ClpStab;// Hier keine Addition, da in der rollStab-funktion anderweitige Veränderung durch einfachen Multiplikator  
	// Clp ist der Wiederstand beim Rollen NICHT die Dämpfung!! daher mal so zum testen 
	// ggf. ändern in so :-) -> m_ClpStab;// so wird das unten berechnet (Clp(m_state.m_mach) + ClpStab(m_state.m_mach));
	Clr_S = Clr(m_state.m_mach) + m_ClrStab;// so wird das unten berechnet (Clr(m_state.m_mach) + ClrStab(m_state.m_mach));

	Cnr_S = Cnr(m_state.m_mach) + m_CnrStab;

	CosAoA = cos(m_corrAoA);
	SinusAoA = sin(m_corrAoA);

	CosAoA2 = CosAoA * CosAoA;
	SinusAoA2 = SinusAoA * SinusAoA;

	//----------Konvertiertung der Momente von der Stabilitäts zu der KörperAchse----------
	//----------Siehe auch CR-2144 Appendix B am Anfang--------------------------
	Cnb_b = CnbNEW(m_state.m_mach) * CosAoA + Clb(m_state.m_mach) * SinusAoA;
	Cnp_b = Cnp(m_state.m_mach) * CosAoA2 - (Cnr_S - (Clp_S)) * SinusAoA * CosAoA - (-Clr_S) * SinusAoA2;
	Cnr_b = Cnr_S * CosAoA2 + ((-Clr_S) + Cnp(m_state.m_mach)) * SinusAoA * CosAoA + (Clp_S)*SinusAoA2;
	Cnda_b = Cnda(m_state.m_mach) * CosAoA * Clda(m_state.m_mach) * SinusAoA;
	Cndr_b = Cndr(m_state.m_mach) * CosAoA - Cldr(m_state.m_mach) * SinusAoA;

	Clb_b = Clb(m_state.m_mach) * CosAoA - CnbNEW(m_state.m_mach) * SinusAoA;
	Clp_b = (Clp_S)*CosAoA2 - ((-Clr_S) - Cnp(m_state.m_mach)) * SinusAoA * CosAoA + Cnr_S * SinusAoA2;
	Clr_b = (-Clr_S) * CosAoA2 - (Cnr_S - Clp_S) * SinusAoA * CosAoA - Cnp(m_state.m_mach) * SinusAoA2;
	Clda_b = Clda(m_state.m_mach) * CosAoA - Cnda(m_state.m_mach) * SinusAoA;
	Cldr_b = Cldr(m_state.m_mach) * CosAoA - Cndr(m_state.m_mach) * SinusAoA;

}

void FlightModel::L_stab()
{
	//set roll moment -- 
	//Neu eingefügt am 14.02.2021 PJ-- "-" vor Clr eingefügt, da Clr Daten positiv waren und negativ sein müssten da Dämpfung
	//m_moment.x-- "2 *" vor Clda eingefügt für stärkere Ailerons = schon besser-- "2*" vor Clp eingefügt -- "0,5 *" vor Clb eingefügt
	//m_ailDamage als multiplikator eingefügt; (m_lWingDamageCD + m_rWingDamageCD) bzgl. WingDamageRoll-Effekt eingefügt;

	//-------------------------ALTE Version ohne Beschränkung des Querruder-Ausschlags-------------------------------------------------
	/*m_moment.x += m_q * (Clb(m_state.m_mach) * m_state.m_beta + Clda(m_state.m_mach) * ((m_input.getRoll() + m_input.getTrimmAilR() - m_input.getTrimmAilL()) * m_ailDamage ) + (m_lWingDamageCD + m_rWingDamageCD) + (0.55 * Cldr(m_state.m_mach)) * m_input.getYaw() )
		+ 0.25 * m_state.m_airDensity * m_scalarVelocity * CON_A * CON_b * CON_b * (2.0 * Clp(m_state.m_mach) * m_state.m_omega.x + (1.5 * -Clr(m_state.m_mach)) * m_state.m_omega.y);
	*/

	//-------------------------NEUE Versíon MIT Beschränkung des Max-Ausschalgs-------------------zum testen der Rotation auskommentiert-------------------------------------
	/*m_moment.x += m_q * (Clb(m_state.m_mach) * m_state.m_beta + Clda(m_state.m_mach) * (((m_input.getRoll() * m_ailDeflection) + m_input.getTrimmAilR() - m_input.getTrimmAilL()) * m_ailDamage) + (m_lWingDamageCD + m_rWingDamageCD) + (0.55 * Cldr(m_state.m_mach)) * (m_input.getYaw() * m_rudDeflection) + m_stallIndRoll)
		+ 0.25 * m_state.m_airDensity * m_scalarVelocity * CON_A * CON_b * CON_b * (2.0 * Clp(m_state.m_mach) * m_state.m_omega.x + (1.5 * -Clr(m_state.m_mach)) * m_state.m_omega.y);
		*/

		//-----------Input Clr aud -Clr in der Rotationsformel geändert und "-" vor Clr hier entfernt (sehr gut)------
		//-----------Multiplikator Clp in der Rotationsformel eingefügt und entfernt wegen Blödheit-----------------------------------
		//-----------Multiplikator in der Moment Formel für Clp_b von 2.0 auf 1.2 und auf 1.25 auf 1.35 und Clr_b von 1.5 auf 1.1 und auf 1.15------------------------------------------------------
		//-----------Multiplikator vor Clda eingefügt auf 1.25 auf 1.5 für schnelleres Ansprechen auf der Rollachse-------------------------------
		//----------m_stallIndRoll verringert auf (s.u.)-----------------------------------------------------------------------------------
		//----------Multiplikator vor m_stallMult von 0.5 auf 0.33
	m_moment.x += m_q * ((Clb_b * m_corrBeta) + ((1.7 * Clda_b) * ((((m_elec.isAC() ? m_input.getRoll() : 0) * m_ailDeflection) + m_input.getTrimmAilR() - m_input.getTrimmAilL()) * m_ailDamage) + (m_lWingDamageCD + m_rWingDamageCD)) + ((0.55 * Cldr_b) * ((m_elec.isAC() ? m_input.getYaw() : 0) * m_rudDeflection)))
		+ 0.25 * m_state.m_airDensity * m_scalarVelocity * CON_A * CON_b * CON_b * (((1.35 * Clp_b) * m_state.m_omega.x) + ((1.15 * Clr_b) * m_state.m_omega.y)) + m_rollHoverThrust;
}

void FlightModel::M_stab()
{
	//set pitch moment-- 
	//"-" vor Cmde eingefügt, da positiver Wert erwartet--//---Cmde von 0.9 auf 0.8 und Cmalpha von 1.15 auf 1.25 auf 1.35 
	//m_pitchup ist Pitch-Up-Moment durch AoA > 15°; m_airframe.autoPilotAltH() ist Pitch due to auto-Pilot Altitude-hold; m_hStabDamage ist horizontal stabilizer integrity in %  

	//---------------Alte Version OHNE Beschränkung des Pitch-Inputs auf maximalen Hoehenruder-ausschlag----------------------------------------------------------------------------------
	/*m_moment.z += m_k * CON_mac * (1.35 * (CmalphaNEW(m_state.m_mach) * m_state.m_aoa) + (0.80 * -CmdeNEW(m_state.m_mach)) * (((m_input.getPitch() + m_pitchup) + m_input.getTrimmUp() - m_input.getTrimmDown() + m_airframe.getAutoPilotAltH()) * m_hStabDamage ))
			+ 0.25 * m_state.m_airDensity * m_scalarVelocity * CON_A * CON_mac * CON_mac * ((1.75 * Cmq(m_state.m_mach))*m_state.m_omega.z + (1.45 * Cmadot(m_state.m_mach)) * m_aoaDot);
	*/
	//1.35 * Cmalpha entfernt, weil CmAlpha negativen PitchMoment gibt; 1.75 * cmq; 1.45 * cmadot //Werte werden verändert für geringere Resistenz gegenüber Pitch
	// "+ m_CmqStAG" eingefügt
	//CmTuck und Multi 3.55 davor eingefügt
	//CmFuel und CmFuelMultiS eingefügt wegen Nose-Heavy bei wenig Fuel
	//m_stallMult bei Cmq und CmadotNEW entfernt. Alte Version:(((1.75 - m_stallMult) * Cmq(m_state.m_mach) + m_CmqStAg) * m_state.m_omega.z + (((1.95 - m_stallMult) * CmadotNEW(m_state.m_mach)) + m_CmaDOTStAg ) * m_aoaDot )
	//Für crisper-feel on Elevator * 1.21 vor -Cmde eingefügt
	//CmFlap als Negativer-Pitch-Wert für Flap-Pitch eingeführt
	//----------------NEUE Version mit Ausschlagsbeschränkung auf max Ausschlag Backstick--------------Cm bleibt unberhürt von der Rotation-----------------------------------------------------------------------------------
	double d1 = 1.0;
	m_moment.z += m_k * CON_mac * ((((d1 * CmalphaNEW(m_state.m_mach) * m_cmaMultiFBW) * m_inducedPitZ) * m_corrAoA) + (d1 * -CmdeNEW(m_state.m_mach) * ((((((m_elec.isAC() ? m_input.getPitch() : 0) * m_elevDeflection)) + m_input.getTrimmUp() - m_input.getTrimmDown() + m_airframe.getAutoPilotAltH() + m_autoPilot.getAutoPitch() + m_autoPilot.getFBWPitch()) * m_pitchReduceAoA) + m_stickKicker) * m_hStabDamage) + (0.70 * CmFlap(m_state.m_mach) * m_airframe.getFlapsPosition()))
		+ 1 * m_state.m_airDensity * m_scalarVelocity * CON_A * CON_mac * CON_mac * (((1.00 * (Cmq(m_state.m_mach) * m_cmqMultiFBW) + (m_cmqMultiFBW * m_CmqStAg)) * m_state.m_omega.z) + (((1.00 * (m_cmqMultiFBW * CmadotNEW(m_state.m_mach))) + (m_cmqMultiFBW * m_CmaDOTStAg)) * m_aoaDot)) + m_pitchHoverThrust;

}

void FlightModel::N_stab()
{
	//set yaw moment-- 
	//"Cnda * da" ausgelassen, da wegen gegenläufiger ailerons geringfügig (Buch Seite 114) "Cnp * Pstab" ausgelassen, da ggf. unnötig 
	// "-" vor Cndr eingefügt, da "Rudereffektivität" positiv sein müsste-- "-" vor Cnb eingefügt, da Dämpfung-- "2.5 *" vor Cnr eingefügt für mehr Dämpfung
	// "- (0.75 * m_stallMult)" und "- m_stallMult" eingefügt wegen Stall-Verhalten// statt 0.75 0.95 als m_stallMult eingefügt 
	//moment.y

	//----------------------------NEUE Version mit Beschränkung des max-Ruderausschlags-----------------------------------------------------
	// ((1.5 - (0.95 * m_stallMult)) // ((2.5 - m_stallMult) * Cnr(m_state.m_mach) * m_state.m_omega.y) ALT
	//neu eingefügt ist: "+ (Cnda(m_state.m_mach) * (m_input.getRoll() * m_ailDeflection))" und "(Cnp(m_state.m_mach) * m_state.m_omega.x) +"
	//-----------------------auskommentiert zum Testen der rotierten Yaw-Werte----------------------------------------------------------------

	/*m_moment.y += m_q * (((1.2 - (0.95 * m_stallMult)) * -CnbNEW(m_state.m_mach) * m_state.m_beta) + (Cnda(m_state.m_mach) * (m_input.getRoll() * m_ailDeflection)) + -Cndr(m_state.m_mach) * (-m_input.getYaw() * m_rudDeflection))
		+ 0.25 * m_state.m_airDensity * m_scalarVelocity * CON_A * CON_b * CON_b * ((Cnp(m_state.m_mach) * m_state.m_omega.x) + ((2.1 - m_stallMult) * Cnr(m_state.m_mach) * m_state.m_omega.y));
	*/
	//-----------------statt 2.1 * Cnr 3.1 und statt 1.2 * Cnb 2.1 // 1.5 * vor Cnp eingefügt// 0.95 * vor m_stallMult entfernt // 1.25* einmgefügt vor m_stallMult
	//------- von ((3.1 - (0.95 * m_stallMult)) * Cnr_b) zu 1.35 * m_stallMult //  von (((2.1 - (0.95 *m_stallMult)) * -Cnb_b) zu (((3.1 - (2.55 * m_stallMult) * -Cnb_b)
	//--- von ((1.5 * (Cnp_b * m_state.m_omega.x)) zu (((1.5 - m_stallMult) * (Cnp_b * m_state.m_omega.x)) 
	//----ACHTUNG: Cnb_Full war falsch TESTEN ggf. zurück!!!!!
	//------Cnb hatte den "-" Zusatz, dabei soll Cnb doch Yaw erzeugen...ohne - getestet mit neuem Cnb-Werten von "((3.1 - (2.55 * m_stallMult)) * -Cnb_b * m_corrBeta)" zu "((3.1 - (2.55 * m_stallMult)) * Cnb_b * m_corrBeta)"

	//--------von: (((1.5 - ( 1.15 * m_stallMult)) * (Cnp_b * m_state.m_omega.x)) zu (((1.8 - ( 1.15 * m_stallMult)) * (Cnp_b * m_state.m_omega.x))
	//--------von: ((3.1 - (1.25 * m_stallMult)) * Cnr_b * m_state.m_omega.y)) zu ((3.5 - (1.25 * m_stallMult)) * Cnr_b * m_state.m_omega.y))
	//----von ((1.6 * -Cndr_b) * (-m_input.getYaw() * m_rudDeflection)) -> ((1.2 * -Cndr_b) * (-m_input.getYaw() * m_rudDeflection))// 
	m_moment.y += m_q * (((3.1 * -Cnb_b) * m_corrBeta) + ((-Cnda_b * ((m_elec.isAC() ? m_input.getRoll() : 0) * m_ailDeflection)) * m_CnpStab) + ((1.2 * -Cndr_b) * (m_elec.isAC() ? -m_input.getYaw() : 0 * m_rudDeflection)))
		+ 0.25 * m_state.m_airDensity * m_scalarVelocity * CON_A * CON_b * CON_b * (((1.8 - (1.15 * m_stallMult)) * (Cnp_b * m_state.m_omega.x)) + ((3.5 - (1.25 * m_stallMult)) * Cnr_b * m_state.m_omega.y)) + m_yawHoverThrust;
}


void FlightModel::lift()
{
	//set lift 
	//-- eingefügt am 16.02. als "Lift = 0.5 * p * V² * s * CL
	//approx m_force.y
	// erster Versuch : m_force.y = m_k * (CLmach(m_state.m_mach) + CLa(m_state.m_aoa)); //Lift ist so schon gut ;-)
	//-------------------ursprüngliche Lift-Formel mit statischem Flap-Lift------------------------------------------
	//m_force.y += m_k * (((CLa(m_state.m_mach) * m_state.m_aoa) + ((CLFlaps + CLblc) * m_flapDamage)) * ((m_lWingDamageCL + m_rWingDamageCL) / 2.0 ) ); //+ CLds(m_state.m_mach)); //aktuell nur Lift due to AoA ohne Stab-Lift 
	//---------------- * m_CLaCorrMulti eingefügt um Lift aus CLa bei hohen AoA abzusenken--------------------------
	//------------------neue Lift-Formel mit dynamischem Flap-Lift---------------------------------------------------
	//von: ((((1.25 * (CLa(m_state.m_mach)) * m_corrAoA) * m_CLaCorrMulti) + ((0.75 * CLds(m_state.m_mach)) zu -> ((((1.25 * (CLa(m_state.m_mach)) * m_corrAoA) * m_CLaCorrMulti) + ((0.85 * CLds(m_state.m_mach))
	m_force.y += m_k * (((((1.25 * (CLa(m_state.m_mach)) * m_corrAoA) * m_CLaCorrMulti) + ((0.85 * CLds(m_state.m_mach)) * m_elevDeflection) + (CLFlaps * m_flapDamage)) * ((m_lWingDamageCL + m_rWingDamageCL) / 2.0)) * m_zeroLift);
}

void FlightModel::drag()
{
	//set drag
	//--eingefügt 16.02. es fehlt noch supersonic drag, gear-drag, flap-drag, brake-drag
	//approx m_force.x negative
	//erster Versuch: m_force.x = -(m_k * (CDmach(m_state.m_mach) + CDa(m_state.m_aoa)
		//+ ((CLmach(m_state.m_mach) + CLa(m_state.m_mach)) * (CLmach(m_state.m_mach) + CLa(m_state.m_mach))) / CON_pi * CON_AR * CON_e));
	// statt 0.85 jetzt 0.80 * CDa(etc) um Alpha-Drag anzupassen.
	//jetzt wieder 1.0 vor CDa, da aufgrund der Rotation der Drag anders "angreift"
	//abs vor m_corrAoA eingefügt, weil sonst der Wert bei negativem AoA mit CDa auf einmal negativ ist und dann Schub bedeutet.
	//von (1.15 * (CDmin(m_state.m_mach)) + (0.95 * (CDa(m_state.m_mach) -> (0.95 * (CDmin(m_state.m_mach)) + (1.25 * (CDa(m_state.m_mach)
	m_force.x += -m_k * ((CDmin(m_state.m_mach)) + ((CDa(m_state.m_mach) * abs(m_corrAoA))) + (CDeng(m_state.m_mach)) + CDGear + CDFlaps + CDBrk + CDBrkCht + CDBrkCanard + CD_OverMach + m_cdminADD + CD_brFlap + m_stallIndDrag); // +CDwave + CDi); CDwave und CDi wieder dazu, wenn DRAG geklärt.
}

void FlightModel::sideForce()
{
	//set side force
	//m_force.z
	//vor m_input.getYaw() ein "-" eingefügt, da eigentlich "-"Yaw richtig-herum ist.
	//von (Cyb(m_state.m_mach) * m_corrBeta) -> ((0.25 *Cyb(m_state.m_mach)) * m_corrBeta)
	m_force.z += m_k * ((Cydr(m_state.m_mach) * (m_input.getYaw() * m_rudDeflection)) + ((m_CybStab * Cyb(m_state.m_mach)) * m_corrBeta)); //neu eingefügt 28Mar21
}

void FlightModel::l_thrustForce()
{
	//set thrust force
	//m_force.x positive
	//m_force = Vec3();
	//m_engine.update(123); //neu eingefügt// und wieder zum testen auskommentiert 

	//-----------------Alte Formel bei der die Force VOR der Rotation hinzugefügt wird-------------------------
	//m_force.x += ((m_engine.updateThrust() + m_engine.updateThrust2()) + m_addThrust) * m_airframe.getEngineDamageMult() * m_thinAirMulti; //NEU m_thinAirMulti angefügt für Thrustreduktion ab 94.000 ft. und geschummelter Thrustmultiplikator wegen kein Bock auf neue Thrust-Kurwe
	//----------------------------------------------------------------------------------------------------------

	//------------------neue Formel bei der die Thrust-Force NACH der Rotation hinzugefügt wird-----------------
	m_l_thrustForce = ((m_engine.updateThrust() + m_l_addThrust) * m_airframe.getEngineDamageMult() * m_thinAirMulti) * m_minusThrust * (1 + m_spec * 3);

}

void FlightModel::r_thrustForce()
{
	//set thrust force
	//m_force.x positive
	//m_force = Vec3();
	//m_engine.update(123); //neu eingefügt// und wieder zum testen auskommentiert 

	//-----------------Alte Formel bei der die Force VOR der Rotation hinzugefügt wird-------------------------
	//m_force.x += ((m_engine.updateThrust() + m_engine.updateThrust2()) + m_addThrust) * m_airframe.getEngineDamageMult() * m_thinAirMulti; //NEU m_thinAirMulti angefügt für Thrustreduktion ab 94.000 ft. und geschummelter Thrustmultiplikator wegen kein Bock auf neue Thrust-Kurwe
	//----------------------------------------------------------------------------------------------------------

	//------------------neue Formel bei der die Thrust-Force NACH der Rotation hinzugefügt wird-----------------
	m_r_thrustForce = ((m_engine.updateThrust2() + m_r_addThrust) * m_airframe.getEngineDamageMultR() * m_thinAirMulti) * m_minusThrust * (1 + m_spec * 3);

}

void FlightModel::update_vector()
{
	if (m_spec > 0)
	{
		m_eng_vector_pitch_l = 0;
		m_eng_vector_pitch_r = 0;
		m_eng_vector_yaw = 0;
	}
	else
	{
		if (m_input.getPitch() > 0.5)
		{
			m_eng_vector_pitch_l = (m_input.getPitch() - 0.5) / 0.5;
		}
		else if (m_input.getPitch() < -0.5)
		{
			m_eng_vector_pitch_l = (m_input.getPitch() + 0.5) / 0.5;
		}
		else
		{
			m_eng_vector_pitch_l = 0;
		}
		if (m_input.getYaw() > 0.5 && m_airframe.getWeightOnWheels() == 0)
		{
			m_eng_vector_yaw = -(m_input.getYaw() - 0.5) / 0.5;
		}
		else if (m_input.getYaw() < -0.5 && m_airframe.getWeightOnWheels() == 0)
		{
			m_eng_vector_yaw = -(m_input.getYaw() + 0.5) / 0.5;
		}
		else
		{
			m_eng_vector_yaw = 0;
		}
		m_eng_vector_pitch_r = m_eng_vector_pitch_l;
		double vectorRoll = 0.0;
		if (m_input.getRoll() > 0.5)
		{
			vectorRoll = -(m_input.getRoll() - 0.5) / 0.5;
		}
		else if (m_input.getRoll() < -0.5)
		{
			vectorRoll = -(m_input.getRoll() + 0.5) / 0.5;
		}
		else
		{
			vectorRoll = 0;
		}
		m_eng_vector_pitch_l = clamp(m_eng_vector_pitch_l + vectorRoll, -1, 1);
		m_eng_vector_pitch_r = clamp(m_eng_vector_pitch_r - vectorRoll, -1, 1);
	}
	m_l_thrustForce_x = cos(toRad(15 * m_eng_vector_pitch_l)) * m_l_thrustForce;
	m_l_thrustForce_y = -tan(toRad(15 * m_eng_vector_pitch_l)) * m_l_thrustForce_x;
	m_l_thrustForce_z = tan(toRad(15 * m_eng_vector_yaw)) * m_l_thrustForce_x;
	m_r_thrustForce_x = cos(toRad(15 * m_eng_vector_pitch_r)) * m_r_thrustForce;
	m_r_thrustForce_y = -tan(toRad(15 * m_eng_vector_pitch_r)) * m_r_thrustForce_x;
	m_r_thrustForce_z = tan(toRad(15 * m_eng_vector_yaw)) * m_r_thrustForce_x;
}

double FlightModel::getVectorPitchL()
{
	return m_eng_vector_pitch_l;
}
double FlightModel::getVectorPitchR()
{
	return m_eng_vector_pitch_r;
}
double FlightModel::getVectorYaw()
{
	return m_eng_vector_yaw;
}

void FlightModel::calcAeroDeflection()
{
	if (m_airframe.getGearNPosition() > 0.0)
	{
		m_ailDeflection = 0.5 * (1.5 * CON_aitgu); // Testweise, da doppelter 30° Ausschlag einfach viel zu viel Roll-due-to-Aileron ist//von 2.0 * CON_aitgu auf 1.5 *
	}
	if (m_airframe.getGearNPosition() == 0.0)
	{
		m_ailDeflection = 0.5 * (1.5 * CON_aitnu);// Testweise, da doppelter 30° Ausschlag einfach viel zu viel Roll-due-to-Aileron ist//von 2.0 * CON_aitgu auf 1.5 *
	}

	if (m_airframe.getGearNPosition() > 0.0)
	{
		m_rudDeflection = 1.5 * CON_RdDefGDR;
	}
	if (m_airframe.getGearNPosition() == 0.0)
	{
		m_rudDeflection = 1.5 * CON_RdDefGUR;
	}

	if (m_input.getPitch() >= 0.0)
	{
		m_elevDeflection = m_input.getPitch() * CON_hstdUP;
	}
	if (m_input.getPitch() < 0.0)
	{
		m_elevDeflection = m_input.getPitch() * CON_hstdDN;
	}

	//printf("M-State.M-Angle.Z in deg: %f\n", toDegrees(m_state.m_angle.z));
	//printf("M-State.M-Angle.X in deg: %f\n", toDegrees(m_state.m_angle.x));

}

void FlightModel::calcLiftFlaps()
{
	if (m_airframe.getFlapsPosition() > 0.0)
	{
		CLFlaps = ((CLa_FL2(m_state.m_mach) * m_corrAoA) + CL_FlStat(m_state.m_mach)) * m_airframe.getFlapsPosition();
	}
	else
	{
		CLFlaps = (((CLa_FL2(m_state.m_mach) * m_corrAoA) + CL_FlStat(m_state.m_mach)) * m_airframe.getLEFlapPosition()) * 0.33;
	}

	//CLblc = (m_airframe.BLCsystem() * CLFlaps) * 0.8;//Doch BLC bei der F-4..hätt ich das gewusst :-) F-35 ohne BLC-System ;-)

}

void FlightModel::pitchStabSystem()
{
	bool hasElectricEnergy = false;
	bool pitchStabEngaged = true;
	double AugStabEffectInStall = 0.0;

	//Check if there is enough electricity
	if (m_elec.isDC())
	{
		hasElectricEnergy = true;
	}
	else
	{
		hasElectricEnergy = false;
	}

	//check if we are in level flight or hovering
	if (m_state.m_mach < 0.15)
	{
		AugStabEffectInStall = 0.0;
	}
	else
	{
		AugStabEffectInStall = m_state.m_mach * 1.5; // ma. testen mit 1.25 zu 1.5
	}

	//now we are getting serious
	if (m_wingStalling == false)
	{
		if (((m_airframe.getCompressorDamage() >= 0.35) && (hasElectricEnergy == true)) && (m_airframe.getTiltEngineNozzlePosition() <= 0.4))
		{
			m_CmqStAg = 1.8 * (CmqStAg(m_state.m_mach));//1.2 - 1.8
			m_CmaDOTStAg = 1.8 * (CmaDOTStAg(m_state.m_mach));//1.2 -> 1.8
			m_pitchStabSystem = 1.0;
		}
		else if (((m_airframe.getCompressorDamage() >= 0.35) && (hasElectricEnergy == true)) && (m_airframe.getTiltEngineNozzlePosition() > 0.4))
		{
			m_CmqStAg = CmqStAg(m_state.m_mach);
			m_CmaDOTStAg = CmaDOTStAg(m_state.m_mach);
			m_pitchStabSystem = 1.0;
		}
		else if ((m_airframe.getCompressorDamage() < 0.35) && (m_elec.isDC()))
		{
			m_CmqStAg = 0.0;
			m_CmaDOTStAg = 0.0;
			m_pitchStabSystem = 0.5;
		}
		else if (!m_elec.isDC())
		{
			m_CmqStAg = 0.0;
			m_CmaDOTStAg = 0.0;
			m_pitchStabSystem = 0.0;
		}
	}
	else if (m_wingStalling == true)
	{
		if ((m_airframe.getCompressorDamage() >= 0.35) && (hasElectricEnergy == true))
		{
			m_CmqStAg = CmqStAg(m_state.m_mach) * AugStabEffectInStall;
			m_CmaDOTStAg = CmaDOTStAg(m_state.m_mach) * AugStabEffectInStall;
			m_pitchStabSystem = 1.0;
		}
		else if (((m_airframe.getCompressorDamage() < 0.35) && (hasElectricEnergy == true)) || (hasElectricEnergy == false))
		{
			m_CmqStAg = 0.0;
			m_CmaDOTStAg = 0.0;
			m_pitchStabSystem = 0.0;
		}

	}
	else
	{
		m_CmqStAg = 0.0;
		m_CmaDOTStAg = 0.0;
		m_pitchStabSystem = 0.0;
	}


}

void FlightModel::yawStabSystem()
{
	bool hasElectricEnergy = false;
	bool yawStabEngaged = true;
	double AugStabEffectInStall = 0.0;

	//Check if there is enough electricity
	if (m_elec.isDC())
	{
		hasElectricEnergy = true;
	}
	else
	{
		hasElectricEnergy = false;
	}

	//check if we are in level flight or hovering
	if (m_state.m_mach < 0.15)
	{
		AugStabEffectInStall = 0.1;
	}
	else if ((m_state.m_mach >= 0.15) && (m_state.m_mach < 0.5))
	{
		AugStabEffectInStall = m_state.m_mach * 1.5; // ma. testen mit 1.25 zu 1.5
	}
	else
	{
		AugStabEffectInStall = m_state.m_mach * 0.6;
	}

	//now we are getting serious
	if (m_wingStalling == false)
	{
		if (((m_airframe.getCompressorDamage() >= 0.35) && (hasElectricEnergy == true)) && (m_airframe.getTiltEngineNozzlePosition() <= 0.4))
		{
			m_CnrStab = 2.8 * CnStab(2.1);//CnStab(2.1); 1.0 -> 1.5 -> 1.9 -> 2.4 -> 2.8
			m_CnpStab = 0.05; //einfach als Multiplikator für Yaw-due-to-roll und yaw-due-to-aileron// war 0.25 -> 0.15 -> 0.11 -> 0.09 -> 0.05
			//m_StabAugSys = 0.5;
			m_yawStabSystem = 1.0;
			m_CybStab = 0.25; //multiplier for Cyb sideforce due to beta
		}
		else if (((m_airframe.getCompressorDamage() >= 0.35) && (hasElectricEnergy == true)) && (m_airframe.getTiltEngineNozzlePosition() > 0.4))
		{

			m_CnrStab = (2.2 * CnStab(2.1));//-0.145 ist einer der größten StabiWerte in der CnStab-Skala bei Mach 2.1
			m_CnpStab = 0.08; //einfach als Multiplikator für Yaw-due-to-roll und yaw-due-to-aileron// war 0.25 -> 0.15 -> 0.11 -> 0.08
			//m_StabAugSys = 0.5;
			m_yawStabSystem = 1.0;
			m_CybStab = 0.25; //multiplier for Cyb sideforce due to beta
		}
		else if ((m_airframe.getCompressorDamage() < 0.35) && (hasElectricEnergy == true))
		{
			m_CnrStab = 0.0;
			m_CnpStab = 1.0;
			//m_StabAugSys = 1.0;
			m_yawStabSystem = 0.5;
			m_CybStab = 1.00; //multiplier for Cyb sideforce due to beta
		}
		else if (hasElectricEnergy == false)
		{
			m_CnrStab = 0.0;
			m_CnpStab = 1.0;
			//m_CnStab = 0.0;
			//m_CnpStab = 1.0;
			//m_StabAugSys = 0.0;
			m_yawStabSystem = 0.0;
			m_CybStab = 1.00; //multiplier for Cyb sideforce due to beta

		}
	}
	else if (m_wingStalling == true)
	{
		if ((m_airframe.getCompressorDamage() >= 0.35) && (hasElectricEnergy == true))
		{
			m_CnrStab = (CnStab(m_state.m_mach)) * AugStabEffectInStall;
			m_CnpStab = 0.15 + (1.0 * AugStabEffectInStall); //einfach als Multiplikator für Yaw-due-to-roll und yaw-due-to-aileron// war 0.25
			//m_StabAugSys = 0.5;
			m_yawStabSystem = 1.0;
			m_CybStab = 0.25; //multiplier for Cyb sideforce due to beta
		}
		else if (((m_airframe.getCompressorDamage() < 0.35) && (hasElectricEnergy == true)) || (hasElectricEnergy == false))
		{
			m_CnrStab = 0.0;
			m_CnpStab = 1.0;
			//m_StabAugSys = 1.0;
			m_yawStabSystem = 0.0;
			m_CybStab = 1.00; //multiplier for Cyb sideforce due to beta
		}

	}
	else
	{

		m_CnrStab = 0.0;
		m_CnpStab = 1.0;
		//m_StabAugSys = 0.0;
		m_yawStabSystem = 0.0;
		m_CybStab = 1.00; //multiplier for Cyb sideforce due to beta
	}



}

void FlightModel::rollStabSystem()
{
	bool hasElectricEnergy = false;
	bool yawStabEngaged = true;
	double AugStabEffectInStall = 0.0;

	//Check if there is enough electricity
	if (m_elec.isDC())
	{
		hasElectricEnergy = true;
	}
	else
	{
		hasElectricEnergy = false;
	}

	//check if we are in level flight or hovering
	if (m_state.m_mach < 0.15)
	{
		AugStabEffectInStall = 0.1;
	}
	else if ((m_state.m_mach >= 0.15) && (m_state.m_mach < 0.5))
	{
		AugStabEffectInStall = m_state.m_mach * 1.5; // ma. testen mit 1.25 zu 1.5
	}
	else
	{
		AugStabEffectInStall = m_state.m_mach * 0.6;
	}


	//now we are getting serious
	if (m_wingStalling == false)
	{
		if (((m_airframe.getCompressorDamage() >= 0.35) && (hasElectricEnergy == true)) && (m_airframe.getTiltEngineNozzlePosition() <= 0.4))
		{
			m_ClrStab = (ClrStab(m_state.m_mach));
			m_ClpStab = 1.35 * (ClpStab(m_state.m_mach));// 
			m_rollStabSystem = 1.0;
		}
		else if (((m_airframe.getCompressorDamage() >= 0.35) && (hasElectricEnergy == true)) && (m_airframe.getTiltEngineNozzlePosition() > 0.4))
		{

			m_ClrStab = 1.25 * ClrStab(m_state.m_mach); //more roll-stability in hover-mode
			m_ClpStab = 2.25 * (ClpStab(m_state.m_mach));// 2.25 ->
			m_rollStabSystem = 1.0;
		}
		else if ((m_airframe.getCompressorDamage() < 0.35) && (m_elec.isDC()))
		{
			m_ClrStab = 0.0;
			m_ClpStab = 0.0;
			m_rollStabSystem = 0.5;
		}
		else if (!m_elec.isDC())
		{

			m_ClrStab = 0.0;
			m_ClpStab = 0.0;
			m_rollStabSystem = 0.0;

		}
	}
	else if (m_wingStalling == true)
	{
		if ((m_airframe.getCompressorDamage() >= 0.35) && (hasElectricEnergy == true))
		{
			m_ClrStab = ClrStab(m_state.m_mach) * AugStabEffectInStall;
			m_ClpStab = 0.25 * (ClpStab(m_state.m_mach)) * AugStabEffectInStall;
			m_rollStabSystem = 1.0;
		}
		else if (((m_airframe.getCompressorDamage() < 0.35) && (hasElectricEnergy == true)) || (hasElectricEnergy == false))
		{
			m_ClrStab = 0.0;
			m_ClpStab = 0.0;
			m_rollStabSystem = 0.0;
		}

	}
	else
	{

		m_ClrStab = 0.0;
		m_ClpStab = 0.0;
		m_rollStabSystem = 0.0;
	}
}

void FlightModel::StabAugSystem()
{
	//---regelt nur noch die Ausgabe für den Failure-Indicator
	if ((m_rollStabSystem == 1.0) && (m_yawStabSystem == 1.0) && (m_pitchStabSystem == 1.0))
	{
		m_StabAugSys = 1.0;
	}
	else if (((m_rollStabSystem != 1.0) || (m_yawStabSystem != 1.0) || (m_pitchStabSystem != 1.0)) && ((m_rollStabSystem != 0.0) && (m_yawStabSystem != 0.0) && (m_pitchStabSystem != 0.0)))
	{
		m_StabAugSys = 0.5;
	}
	else
	{
		m_StabAugSys = 0.0;
	}
}

void FlightModel::calcZeroLift()
{
	double AoAToStallAoAQuotient = 0.0;
	double AoAToWingRockQuotient = 0.0;


	//calculating CLzero at AoA (vs. speed in mach)
	m_setLiftZero = CLzero(m_state.m_mach);

	//calculating the quotient of actual AoA (in Rad) with CLzero AoA (how far are we in regards to stall AoA??)
	//abs(m_state.m_aoa) damit auch negative AoA als AoA erfasst und in der Tabelle verarbeitet werden können
	AoAToStallAoAQuotient = (abs(m_state.m_aoa) / CLzero(m_state.m_mach));

	//AoAToWingRockQuotient = m_state.m_aoa / CLzero(m_state.m_mach);

	//Using the percentage of Stall-AoA to use on the correction-curve for CLa since CLa is not linear but starts to decrease when nearing stall-AoA.
	m_CLaCorrMulti = CLaCorr(AoAToStallAoAQuotient);

	//----------m_wingStalling neu eingefügt um Strömungsabriss aufrecht zu erhalten------

	if (m_airframe.getWeightOnWheels() == 0.0)
	{
		//-------------Alte Formel, leicht vermischt---------------
		/*
		if (m_state.m_aoa >= m_setLiftZero)
		{
			m_zeroLift = 0.1;//war 0.01 jetzt 0.1
			m_inducedPitZ = 0.01;
			m_wingStalling = true;
		}
		else if (m_wingStalling == true)
		{
			//m_zeroLift = 0.01;
			m_zeroLift = m_CLaCorrMulti * 1.1;
			m_inducedPitZ = 0.01;
		}
		else
		{
			m_zeroLift = 1.0;
			m_inducedPitZ = 1.0;
		}

		//----------Check if wing is unstalled---------------------
		//Jetzt NEU um m_wingStalling wieder "auszuschalten"
		if ((m_wingStalling == true) && ((AoAToStallAoAQuotient <= 0.30) && (AoAToStallAoAQuotient >= -0.30)))
		{
			m_wingStalling = false;
			m_inducedPitZ = 1.0;
		}
		*/

		//--------------Neue Formulierung eher stringenter--------

		//----------Check if wing is stalled---------------------
		//----abs (Betrag von) NEU (05Jun22) eingefügt, damit auch negativer AoA von mehr als m_setLiftZero zum Wingstalling führt
		if ((abs(m_state.m_aoa) >= m_setLiftZero) && (m_airframe.getTiltEngineNozzlePosition() <= 0.4))
		{
			m_wingStalling = true;
		}
		else if ((m_state.m_aoa >= (1.35 * m_setLiftZero)) && (m_airframe.getTiltEngineNozzlePosition() > 0.4))
		{
			m_wingStalling = true;
		}


		if (m_wingStalling == true)
		{
			m_zeroLift = m_CLaCorrMulti * 0.8;// von 1.1 zu 0.8
			m_inducedPitZ = 0.001;
		}
		else
		{
			m_zeroLift = 1.0;
			m_inducedPitZ = 1.0;
		}

		//----------Check if wing is unstalled---------------------
		//Jetzt NEU um m_wingStalling wieder "auszuschalten"
		//war ((AoAToStallAoAQuotient <= 0.30) && (AoAToStallAoAQuotient >= -0.30)) dann 0.25 und -0.25
		//ABER: Das hier ist der Quotient akuelles AoA to CLzero-AoA
		if ((m_wingStalling == true) && (AoAToStallAoAQuotient <= 0.82))
		{
			m_wingStalling = false;
			m_inducedPitZ = 1.0;
		}

		//--------Stall-Induced-Wing-Rock due to yawing-motion----
		/*if ((AoAToWingRockQuotient >= 0.60) && (AoAToWingRockQuotient <= 1.5) && (m_wingStalling == false) && (m_deactivateWingRock == false)) //das war zunächst 0.80
		{
			m_stallIndRock = 8.5 * (Clb_b * m_corrBeta); //war 3.5 -> 5.5 mit höherem Multi vor Cnb_b; jetzt 8.5
		}
		else
		{
			m_stallIndRock = 0.0;
		}
		*/
		//deactivation for wingrock during PostStalled flight
		/*if (m_wingStalling == true)
		{
			m_deactivateWingRock == true;
		}
		else
		{
			m_deactivateWingRock == false;
		}*/

		//--------stall-induced extra-drag
		if (m_wingStalling == true)//(m_state.m_aoa > m_setLiftZero)
		{
			// Alte Variante : m_stallIndDrag = abs((CDa(m_state.m_mach) * abs(m_state.m_aoa)) * 0.5);//war 1.5 jetzt 2.2 jetzt 2.8 jetzt 3.0 jetzt 3.5 und 4.5 zu 3.5 zu 3.9
			m_stallIndDrag = abs((CDa(m_state.m_mach) * abs(m_state.m_aoa)) * 0.5);//von 0.4 -> 0.35 -> 0.31-> 0.26 -> 0.5
			m_noVertTailEff = 0.0; //1.9; //Dieser Wert schaltet den Yaw-Stabilizer aus und sorgt für weniger YAW-Stabilisierung// war 2.5
		}
		else
		{
			m_stallIndDrag = 0.0;
			m_noVertTailEff = 0.0;
		}


		//-----------Neuer Ansatz mit Aufhebung der Richtungsstabilisierenden Derivate in Yaw-Moment------
		//-----------Kombinierter Ansatz der m_stallMult und m_stalMulti in einer Funktion---------------

		//----------Neue Stall-Yaw-Destabilisierungs-Funktion angelehnt an Strömungsabriss-Funktion und prozentuale Erreichung abhängig von Aktuellem-AoA/Stall-AoA
		//----------Alter Ansatz mit einem Sprung in der m_stallMult--fühlt sich künstlich an--------------------------------------------------------------------
		/*

		if (m_airframe.getWeightOnWheels() == 0.0)
		{
			if ((m_airframe.getFlapsPosition() == 0.0) && (m_wingStalling == false) && ((AoAToStallAoAQuotient >= 0.60) || (AoAToStallAoAQuotient <= -0.74)))
			{
				m_stallMult = FinalStallValue(AoAToStallAoAQuotient);// neue multi Start 1.1 zu 1.0
				m_setZeroCnBeta = 1.0;

			}
			else if ((m_airframe.getFlapsPosition() > 0.0) && (m_wingStalling == false) && (AoAToStallAoAQuotient >= 0.60) || (AoAToStallAoAQuotient <= -0.74))//
			{
				m_stallMult = 0.89 * FinalStallValue(AoAToStallAoAQuotient); //
				m_setZeroCnBeta = 0.4;

			}
			else if (m_wingStalling == true)
			{
				m_stallMult = 2.5 * FinalStallValue(AoAToStallAoAQuotient);// war 1.8 jetzt 2.5
				m_setZeroCnBeta = 0.0;
			}
			else
			{
				m_stallMult = 0.0;
				m_setZeroCnBeta = 1.0;
			}

		}
		else
		{
			m_stallMult = 0.0;
		}
		*/
		//----------------------Neuer Ansatz ohne sprunghaften Anstieg m_stallMult--------------------------------
		if (m_airframe.getWeightOnWheels() == 0.0)
		{
			if ((m_airframe.getFlapsPosition() == 0.0) && ((AoAToStallAoAQuotient >= 0.60) || (AoAToStallAoAQuotient <= -0.74)))
			{
				m_stallMult = FinalStallValue(AoAToStallAoAQuotient);// neue multi Start 1.1 zu 1.0
				m_CnBetaMult = 0.65 * FinalStallValue(AoAToStallAoAQuotient);//neuer Versuch von 0.75 - 0.65
				m_setZeroCnBeta = 1.0;

				//---------NEUER VERSUCH---------
				//-------sobald die Wing gestalled ist, Reduzierung des CnBeta Einflusses 
				if (m_wingStalling == true)
				{
					m_CnBetaMult = 0.35 * FinalStallValue(AoAToStallAoAQuotient);//von 0.25 -> 0.35
				}

			}
			else if ((m_airframe.getFlapsPosition() > 0.0) && (AoAToStallAoAQuotient >= 0.60) || (AoAToStallAoAQuotient <= -0.74))//
			{
				m_stallMult = 0.85 * FinalStallValue(AoAToStallAoAQuotient); //
				m_CnBetaMult = 0.55 * FinalStallValue(AoAToStallAoAQuotient);//neuer Versuch
				m_setZeroCnBeta = 0.4;

				//---------NEUER VERSUCH---------
				//-------sobald die Wing gestalled ist, Reduzierung des CnBeta Einflusses 
				if (m_wingStalling == true)
				{
					m_CnBetaMult = 0.25 * FinalStallValue(AoAToStallAoAQuotient);//von 0.15 -> 0.25
				}

			}
			else
			{
				m_stallMult = 0.0;
				m_CnBetaMult = 0.0;
				m_setZeroCnBeta = 1.0;
			}

		}
		else
		{
			m_stallMult = 0.0;
		}

	}
	else
	{
		m_zeroLift = 1.0;
		m_stallIndDrag = 0.0;
		m_stallIndRoll = 0.0;
		m_CnBetaMult = 0.0;
		m_wingStalling = false;
	}

	/*double Behelfsvariable = 0.0;

	if (m_wingStalling == true)
	{
		Behelfsvariable = 1.0;
	}
	else
	{
		Behelfsvariable = 0.0;
	}
	*/
	//printf("Wing is stalled %f\n", Behelfsvariable);
	//printf("Nozzle Tilt in Percent %f\n", m_airframe.getTiltEngineNozzlePosition());
	//--------------Berechnung der Verschlechterung des CLa bei hohen Anstellwinkeln nahe des Stall-Bereichs--------------
	//Berechnung des Quotienten aus aktuellem AoA und CLzero-AoA (also dem AoA bei dem NULL-Lift = Stall angesagt ist)
	//dann Bestimmung des aktuellen CLa-quotienten anhand der CLaCorr-Table


	//printf("Rolling in Rads %f\n", m_state.m_omega.x);
	//printf("RollState in Rads %f\n", m_state.m_angle.x);

	/*
	printf("##########################################");

	printf("Mach %f\n", m_state.m_mach);
	printf("AoA in Deg %f\n", toDegrees(m_state.m_aoa));

	printf("Cn Beta Value %F\n", ((3.1 - (2.55 * m_stallMult)) * -Cnb_b * m_corrBeta));

	printf("Cnp_Stall_Value %f\n", ((1.5 - (1.15 * m_stallMult))* (Cnp_b* m_state.m_omega.x)));
	printf("Cnr_Stall_Value %F\n", ((3.1 - (1.25 * m_stallMult))* Cnr_b* m_state.m_omega.y));
	printf("CnStab Value %f\n", ((1.95 - m_noVertTailEff)* m_CnStab));
	printf("Full Yaw Dampening Value %f\n", (((1.5 - (1.15 * m_stallMult))* (Cnp_b* m_state.m_omega.x)) + ((3.1 - (1.25 * m_stallMult)) * Cnr_b * m_state.m_omega.y) + ((1.95 - m_noVertTailEff) * m_CnStab)));
	printf("SatllValue %f\n", m_stallMult);

	printf("##########################################");
	*/
}

void FlightModel::addedDrag()
{
	//-----------auskommentiert, da Versuch mit CDmin_FullNEU und TSFC-Thrust-----------------
	/*if ((m_state.m_mach >= 0.0664) && (m_state.m_mach <= 1.4680))
	{
		m_cdminADD = CDminAD(m_state.m_mach);
	}
	else
	{
		m_cdminADD = 0.0;
	}*/

	m_cdminADD = 0.0;

}

void FlightModel::brokenFlapDrag()
{
	if ((m_airframe.osFlapDamage() > 0.0) && (m_airframe.getFlapsPosition() > 0.5) && ((m_state.m_mach > 0.95) || (m_flapBroken == true)))
	{
		CD_brFlap = 0.15;
		m_flapBroken = true;
	}
	else if ((m_airframe.osFlapDamage() > 0.0) && ((m_airframe.getFlapsPosition() >= 0.15) && (m_airframe.getFlapsPosition() <= 0.5)) && ((m_state.m_mach > 1.25) || (m_flapBroken == true)))
	{
		CD_brFlap = 0.15;
		m_flapBroken = true;
	}
	else if (m_airframe.osFlapDamage() == 0.0)
	{
		CD_brFlap = 0.0;
		m_flapBroken = false;
	}
}

void FlightModel::addedThrustCalc()
{
	//-------------------Alte Version ohne Throttle---------------------------------------
	//m_l_addThrust = AdThrLAlt(m_state.m_mach) * AdThrLAltMulti(m_airframe.getAltInFeet());

	//hier jetzt die Throttle mit eingefügt und als multiplikator für den added-Thrust eingefügt

	double m_addThrustL = 0;
	double m_addThrustR = 0;
	if (m_engine.updateSpool() >= 0.85)
	{
		m_addThrustL = 0.5 * (m_engine.updateSpool() * (AdThrLAlt(m_state.m_mach) * AdThrLAltMulti(m_airframe.getAltInFeet())));
	}
	else
	{
		m_addThrustL = 0.0;
	}
	if (m_engine.updateSpool2() >= 0.85)
	{
		m_addThrustR = 0.5 * (m_engine.updateSpool2() * (AdThrLAlt(m_state.m_mach) * AdThrLAltMulti(m_airframe.getAltInFeet())));
	}
	else
	{
		m_addThrustR = 0.0;
	}
	m_l_addThrust = m_addThrustL;
	m_r_addThrust = m_addThrustR;
}

//-------------Thrust Tilt Function----------------------------------------------
void FlightModel::thrustTiltFunction()
{
	if ((m_airframe.getTiltEngineNozzlePosition() >= 0.2) && (m_airframe.getTiltEngineNozzlePosition() < 0.4))
	{
		m_plusThrust = 0.275 * ((m_engine.updateThrust() + m_engine.updateThrust2()) * (m_airframe.getEngineDamageMult() + m_airframe.getEngineDamageMultR())); //0.376
		m_minusThrust = 0.92;//-> 92% Schub vor
	}
	else if ((m_airframe.getTiltEngineNozzlePosition() >= 0.4) && (m_airframe.getTiltEngineNozzlePosition() < 0.6))
	{
		m_plusThrust = 0.83 * ((m_engine.updateThrust() + m_engine.updateThrust2()) * (m_airframe.getEngineDamageMult() + m_airframe.getEngineDamageMultR())); //0.888
		m_minusThrust = 0.75;// -> 75% Schub vor
	}
	else if ((m_airframe.getTiltEngineNozzlePosition() >= 0.6) && (m_airframe.getTiltEngineNozzlePosition() < 0.8))
	{
		m_plusThrust = 0.885 * ((m_engine.updateThrust() + m_engine.updateThrust2()) * (m_airframe.getEngineDamageMult() + m_airframe.getEngineDamageMultR()));
		m_minusThrust = 0.55;
	}
	else if ((m_airframe.getTiltEngineNozzlePosition() >= 0.8) && (m_airframe.getTiltEngineNozzlePosition() < 1.0))
	{
		m_plusThrust = 1.00 * ((m_engine.updateThrust() + m_engine.updateThrust2()) * (m_airframe.getEngineDamageMult() + m_airframe.getEngineDamageMultR()));// war 1.88
		m_minusThrust = 0.05;//war 0.35
	}
	else if (m_airframe.getTiltEngineNozzlePosition() == 1.0)
	{
		m_plusThrust = 0.995 * ((m_engine.updateThrust() + m_engine.updateThrust2()) * (m_airframe.getEngineDamageMult() + m_airframe.getEngineDamageMultR()));// war 2.05
		m_minusThrust = -0.05;// war 0.0
	}
	else
	{
		m_plusThrust = 0.0;
		m_minusThrust = 1.0;
	}

}

void FlightModel::hoverThrustFunction()
{
	if ((m_airframe.getTiltEngineNozzlePosition() >= 0.4) && (m_state.m_mach <= 0.40) && (m_engine.getRPMNorm() >= 0.70 && m_engine.getRPMNorm2() >= 0.70) && (m_airframe.getWeightOnWheels() == 0.0))
	{
		m_pitchHoverThrust = m_input.getPitch() * 25000.0;
		m_rollHoverThrust = m_input.getRoll() * 15000.0;
		m_yawHoverThrust = -m_input.getYaw() * 25000.0;
	}
	else
	{
		m_pitchHoverThrust = 0.0;
		m_rollHoverThrust = 0.0;
		m_yawHoverThrust = 0.0;
	}

}

void FlightModel::flightControlSystem()
{
	//-------------AoA-Liniter Functions------------------------------------------------------------------------------
	double allowableAOA = 0.0;
	double allowableAoAPercent = 0.0;

	allowableAOA = (CLzero(m_state.m_mach)) * 0.91;// 91% des AoA bei dem Stall eintritt ist "Vertretbar" für das FCS
	allowableAoAPercent = m_state.m_aoa / allowableAOA;

	if ((m_airframe.getACpower() == 1.0) || (m_airframe.getDCpower() == 1.0) || (m_airframe.getBATpower() == 1.0))
	{
		if ((allowableAoAPercent >= 0.73) && (m_airframe.getTiltEngineNozzlePosition() <= 0.4) && (m_input.getPitch() > 0.0))
		{
			m_pitchReduceAoA = FCSPitch(allowableAoAPercent);// Pitchmultiplier for actual allowable AoA
		}
		else
		{
			m_pitchReduceAoA = 1.0;
		}
	}
	else
	{
		m_pitchReduceAoA = 1.0;
	}
	//------------------------------------------------------------------------------------------------
	//----------------added "Stick-Kicker" Function to apply "front-stick" input when neccessary------

	if ((allowableAoAPercent >= 0.95) && (m_input.getPitch() >= 0.0))
	{
		m_stickKicker = -0.25;//ganz blöder stick-Kicker wird noch mit einer Table besser gemacht :-)
	}
	else
	{
		m_stickKicker = 0.0;
	}
	//-------------------------------------------------------------------------------------------------
	//-----------------------"distubed"-FBW-System by changing physics...why not the other way around?--
	//----------Cma change function to have just very few Cma at 0.0 input, and normal Cma at full input
	//----------Cmq change function to have more dampening at around 0.0 input--------------------------


	if ((m_airframe.getACpower() == 1.0) || (m_airframe.getDCpower() == 1.0) || (m_airframe.getBATpower() == 1.0))
	{
		//m_cmaMultiFBW = CmaMulti(m_input.getPitch());
		//m_cmqMultiFBW = CmqMulti(m_input.getPitch());

		//zum PID-Testen--
		m_cmaMultiFBW = 1.0;
		m_cmqMultiFBW = 1.0;
		//-----------------
	}
	else
	{
		m_cmaMultiFBW = 1.0;
		m_cmqMultiFBW = 1.0;
	}



	//----------------------------------------------------------------------------------------------------------------

}

//------------------Add Force to Moments and Add Force to Force-------------------
void FlightModel::addMoment(const Vec3& force, const Vec3& pos)
{
	//Add the force to the overall force
	//m_force_boddy += force;//auskommentiert, da ich zu m_boddy_force nichts hinzufügen möchte, sondern nur momente aus Kräften

	//Calculate the relative position to the centre of mass
	//Wenn CenterOfMass in Lua gesetzt wird, dann reicht hier als "eingabe" eine feste Zahl aus, um die sich der Druckpunkt der Kraft nach hinten verschiebt 
	Vec3 relativePos = pos - m_state.m_com;

	//Calculate the "moment" (actually torque)
	Vec3 moment = cross(relativePos, force);

	//Add it on to the moments
	m_moment += moment;

}

void FlightModel::addForce(const Vec3& force, const Vec3& pos)
{
	//Add the force to the overall force
	m_force_boddy += force;//hier will ich auch FORCE haben!!!

	//Calculate the relative position to the centre of mass
	Vec3 relativePos = pos - m_state.m_com;

	//Calculate the "moment" (actually torque)
	Vec3 moment = cross(relativePos, force);

	//Add it on to the moments
	m_moment += moment;

}
//--------------------Adding Forces end--------------------------------------------

void FlightModel::update(double dt)
{
	m_moment = Vec3();
	m_force = Vec3();


	m_aoaDot = (m_corrAoA - m_aoaPrevious) / dt;
	m_aoaPrevious = m_corrAoA;

	m_scalarVelocity = magnitude(m_state.m_localAirspeed);
	m_scalarVelocitySquared = m_scalarVelocity * m_scalarVelocity;


	m_k = 0.5 * m_state.m_airDensity * m_scalarVelocitySquared * CON_A;
	m_p = 0.25 * m_state.m_airDensity * m_scalarVelocity * CON_A * CON_b * CON_b;
	m_q = m_k * CON_b;

	m_state.m_mach = m_scalarVelocity / m_state.m_speedOfSound;

	M_mcrit = m_state.m_mach / CON_Mcrit; //Mach/Machcrit //neu eingefügt 18.02.2021
	M_mcrit_b = pow(M_mcrit, CON_wdb); //M_mcrit ^ CON_wdb //neu eingefügt 18.02.2021

	CDwave = CON_wda * M_mcrit_b; //neu eingefügt 18.02.2021

	CDi = ((CLmach(m_state.m_mach) * CLmach(m_state.m_mach)) / CON_pi * CON_A * CON_e);

	CDGear = CON_GrDD * m_airframe.getGearNPosition();
	CDFlaps = CON_FlpD2 * m_airframe.getFlapsPosition();
	//---OLD CLFlaps---//	CLFlaps = CON_FlpL2 * m_airframe.getFlapsPosition();
	//CLFlaps = (CLa_FL2(m_state.m_mach) * m_state.m_aoa) * m_airframe.getFlapsPosition();
	CDBrk = CON_BrkD * m_airframe.getSpeedBrakePosition();
	CDBrkCanard = CON_BrkCanardD * m_airframe.getSpeedCanardBrakePosition();
	CDBrkCht = CON_ChtD * m_airframe.brkChutePosition();
	//CLblc = m_airframe.BLCsystem() * CLFlaps;
	if (m_spec == 0 && m_input.getSpecAb() == 1.0 && m_state.m_mach < 0.28 && m_airframe.getTiltEngineNozzlePosition() == 0.0 && m_airframe.getIntThrottlePosition()>0.95 && m_airframe.getIntThrottlePosition2() > 0.95 && m_engine.getRPMNorm() > 0.95 && m_engine.getRPMNorm2() > 0.95)
	{
		m_spec = 1.0;
		m_specTime = 3.0;
	}
	else if (m_specTime <= 0.0 || m_state.m_mach > 0.45 || m_airframe.getTiltEngineNozzlePosition() > 0.0 || m_airframe.getIntThrottlePosition() < 0.95 || m_airframe.getIntThrottlePosition2() < 0.95 || m_engine.getRPMNorm() < 0.95 || m_engine.getRPMNorm2() < 0.95)
	{
		m_spec = 0.0;
		m_specTime = 0.0;
	}
	if (m_specTime > 0)
	{
		m_specTime -= dt;
	}
	m_engine.m_spec_ab = m_spec > 0.9;
	calculateAeroRotateMoments();
	L_stab();
	M_stab();
	N_stab();
	lift();
	drag();
	sideForce();
	l_thrustForce();
	r_thrustForce();
	calculateShake(dt);
	calcAeroDeflection();
	calcLiftFlaps();
	StabAugSystem();
	addedDrag();
	brokenFlapDrag();
	calcZeroLift();
	addedThrustCalc();
	thrustTiltFunction();
	hoverThrustFunction();
	flightControlSystem();
	rollStabSystem();
	yawStabSystem();
	pitchStabSystem();
	update_vector();

	//printf("Roll_Moment %f \n", m_moment.x);
	//printf("Roll_Dampening Clp %f \n", Clp_b);
	//printf("RollDuYaw_Dampening Clr %f \n", Clr_b);

	//printf("Pitch due to Fuel %f\n", CmFuel(m_fuelSystem.getFuelQtyInternal()));
	//printf("CmFuel SlowSpeed Multi %f\n", CmFuelMultiS(m_state.m_mach));
	//printf("PitchingMoment due to LowFuel FULL %f\n", m_k * CON_mac * (CmFuel(m_fuelSystem.getFuelQtyInternal()) * CmFuelMultiS(m_state.m_mach)));
	//printf("Full PitchingMoment %f\n", m_moment.z);
	//printf("Pitch-Input-Stick %f\n", m_input.getPitch());
	//printf("Pitching Moment due to Stick and Elevator FULL %f\n", m_k * CON_mac * (1.21 * -CmdeNEW(m_state.m_mach) * ((m_input.getPitch() * m_elevDeflection))));
	//printf("Pitching Moment due to Alpa FULL %f\n", m_k * CON_mac * (1.35 * (CmalphaNEW(m_state.m_mach) * m_corrAoA)));
	//printf("Pitching Moment due to Cmq FULL %f\n", 0.25 * m_state.m_airDensity * m_scalarVelocity * CON_A * CON_mac * CON_mac * (1.75 * Cmq(m_state.m_mach) + m_CmqStAg) * m_state.m_omega.z);
	//printf("Pitching Moment due to CmaDOT FULL %f\n", 0.25 * m_state.m_airDensity * m_scalarVelocity * CON_A * CON_mac * CON_mac * ((1.95 * CmadotNEW(m_state.m_mach)) + m_CmaDOTStAg) * m_aoaDot);
	//printf("CenterOfMass %f\n", m_state.m_com.x);
	// printf("CD broken Flap %f \n", CD_brFlap);

	//printf("CL Total %f \n", m_force.y);
	//----------------function for Pitchup-Factor, Pitchup-force and pitchup-speed ausser Funktion, da kein Pitchup bei F-4E--------------------
	/* if ((m_state.m_aoa >= 0.2617) && (m_airframe.getFlapsPosition() == 0.0) && (m_state.m_mach > 0.26))
	{
		m_pitchup = 1.35 * ((PitAoA(m_state.m_aoa) * PitMult(m_state.m_mach))); //war 0.65 * zu 0.95 zu 1.25 zu 1.35
	}
	else if ((m_state.m_aoa >= 0.2617) && ((m_airframe.getFlapsPosition() > 0.0) || (m_state.m_mach <= 0.26)))
	{
		m_pitchup = 0.95 * ((PitAoA(m_state.m_aoa) * PitMult(m_state.m_mach))); // war 0.45 * zu 0.65 zu 0.95
	}
	else
	{
		m_pitchup = 0.0;
	}
	//printf("m_pitchup %f \n", m_pitchup);
	//printf("AoA %f \n", m_state.m_aoa);
	*/
	//-------------function for Stall-AoA and Stall-Speed and resulting stall-force----------------------------------------------
	//---Alte Stall-Funktion mit festen Werten bedingt durch Geschwindigkeit und AoA mit 2 sich multiplizierenden Kurven----
	/*
	if (m_airframe.getWeightOnWheels() == 0.0)
	{
		if ((m_state.m_aoa >= 0.332) && (m_airframe.getFlapsPosition() == 0.0))
		{
			m_stallMult = 1.65 * (StAoA(m_state.m_aoa) * StAoAMulti(m_state.m_mach));//neuer Multiplikator 1.65 zu 1.85
		}
		else if ((m_state.m_aoa >= 0.332) && (m_airframe.getFlapsPosition() > 0.0)) // || (m_state.m_mach <= 0.26)))
		{
			m_stallMult = 1.15 * (StAoA(m_state.m_aoa) * StAoAMulti(m_state.m_mach)); //neuer Multiplikator 0.95 zu 1.15
		}
		else
		{
			m_stallMult = 0.0;
		}
	}
	else
	{
		m_stallMult = 0.0;
	}
	//printf("m_stallMult %f \n", m_stallMult);*/

	//----------Neue Stall-Yaw-Destabilisierungs-Funktion angelehnt an Strömungsabriss-Funktion und prozentuale Erreichung abhängig von Aktuellem-AoA/Stall-AoA
	//----------Verschoben in die andere Formel------------------------ 
	/*
	double AoAToStallAoAQuotient = 0.0;
	AoAToStallAoAQuotient = (m_state.m_aoa / CLzero(m_state.m_mach));

	if (m_airframe.getWeightOnWheels() == 0.0)
	{
		if ((m_airframe.getFlapsPosition() == 0.0) && (m_wingStalling == false) && (AoAToStallAoAQuotient >= 0.74))
		{
			m_stallMult = 1.1 * FinalStallValue(AoAToStallAoAQuotient);// neue multi Start 1.1 zu 1.0

		}
		else if ((m_airframe.getFlapsPosition() > 0.0) && (m_wingStalling == false) && (AoAToStallAoAQuotient >= 0.74))//
		{
			m_stallMult = 0.89 * FinalStallValue(AoAToStallAoAQuotient); //

		}
		else if (m_wingStalling == true)
		{
			m_stallMult = 1.5 * FinalStallValue(AoAToStallAoAQuotient);
		}
		else
		{
			m_stallMult = 0.0;
		}


	}
	else
	{
		m_stallMult = 0.0;
	}
	*/


	//printf("m_stallMult %f\n", m_stallMult);
	//printf("FinalStall-Value %f\n", FinalStallValue(AoAToStallAoAQuotient));
	//printf("AoA-to-Stall_CLa-to-CLZero-Quot %f\n", AoAToStallAoAQuotient);
	//printf("AoA in Deg %f\n", (m_state.m_aoa * 57.296));
	//printf("Rocking_Moment %f\n", m_stallIndRock);

	//printf("CnStabSystem %f\n", m_CnStab);

	//TestVar_1 = (((Cnda_b * (m_input.getRoll() * m_ailDeflection)) * m_CnpStab));

	//printf("CnBeta_Formel %f\n", ((2.1 - (1.25 * m_stallMult)) * -Cnb_b * m_corrBeta));
	//printf("Cnd_Aileron_incl.All %f\n", TestVar_1);
	//printf("CnBeta %f\n", Cnb_b);
	//printf("Cnda_b %f\n", Cnda_b);
	//printf("RollInput %f\n", (m_input.getRoll() * m_ailDeflection));
	//printf("CnP_Stab_Value %f\n", m_CnpStab);


	//------------------ThinAir-Multiplyer-------------------------- // NEU-NEU-NEU
	if (m_airframe.getAltInFeet() < 94000.0)
	{
		m_thinAirMulti = 1.0;
	}
	else
	{
		m_thinAirMulti = ThinAM(m_airframe.getAltInFeet());
	}

	//-------------------OverMach Drag-------------------------------
	if ((m_state.m_mach < 1.75) && (m_airframe.getEASinKnots() < 760.0))
	{
		CD_OverMach = 0.0;
	}
	else
	{
		if ((m_state.m_mach >= 1.75) && (m_airframe.getEASinKnots() < 760.0))
		{
			CD_OverMach = CDOM(m_state.m_mach);
		}
		else if ((m_state.m_mach < 1.75) && (m_airframe.getEASinKnots() >= 760.0))
		{
			CD_OverMach = CDOK(m_airframe.getEASinKnots());
		}
		else if ((m_state.m_mach >= 1.75) && (m_airframe.getEASinKnots() >= 760.0))
		{
			CD_OverMach = CDOK(m_airframe.getEASinKnots());
		}
	}


	//-------------damage-stuff--------------------------------------
	if (m_airframe.getAileronDamage() < 1.0)
	{
		m_ailDamage = m_airframe.getAileronDamage();
	}
	else
	{
		m_ailDamage = 1.0;
	}
	//im Foglenden dann noch Flap-Damage durch Overspeed einbauen!!!
	if (m_airframe.getFlapDamage() < 1.0)
	{
		m_flapDamage = m_airframe.getFlapDamage();
	}
	else
	{
		m_flapDamage = 1.0;
	}

	if (m_airframe.getLWingDamage() < 1.0)
	{
		m_lWingDamageCL = m_airframe.getLWingDamage();
		m_lWingDamageCD = (m_airframe.getLWingDamage()) / 10.0; //Roll-Links ist -, Roll-Rechts ist + 
	}
	else
	{
		m_lWingDamageCL = 1.0;
		m_lWingDamageCD = 0.1;
	}

	if (m_airframe.getRWingDamage() < 1.0)
	{
		m_rWingDamageCL = m_airframe.getRWingDamage();
		m_rWingDamageCD = (-(m_airframe.getRWingDamage())) / 10; //Roll-Links ist +, Roll-Rechts ist - ?? 
	}
	else
	{
		m_rWingDamageCL = 1.0;
		m_rWingDamageCD = -0.1;
	}

	if (m_airframe.getHoriStabDamage() < 1.0)
	{
		m_hStabDamage = m_airframe.getHoriStabDamage();
	}
	else
	{
		m_hStabDamage = 1.0;
	}

	//printf("HStabDamage %f \n", m_hStabDamage);
	/*printf("HStabIntegrity %f \n", m_airframe.getHoriStabDamage());
	printf("WingLIntegrity %f \n", m_airframe.getLWingDamage());
	printf("WingRIntegrity %f \n", m_airframe.getRWingDamage());
	printf("AileronIntegrity %f \n", m_airframe.getAileronDamage());
	printf("TurbineIntegrity %f \n", m_airframe.getTurbineDamage());
	printf("CompressorIntegrity %f \n", m_airframe.getCompressorDamage());*/
	//printf("Roll %f \n", m_input.m_roll);

	//das muss hier hinten hin, damit m_force durch das update der Lift und Drag-Funktionen gefüllt ist. Sonnst ist m_force = 0.0
	m_force_boddy = windAxisToBodyAxis(m_force, m_corrAoA, m_corrBeta);

	//----zu erst die Rotation und DANN die Addition-----------------
	//Alte Formel: addMoment(m_force_boddy, Vec3(-0.18 * CON_mac, 0.0, 0.0)); //hier noch mit einem Prozentsatz von MAC verschoben
	//NEUE Formel: Da die POS eine Bezugnahme zum COM (aus der config.lua) hat, kann ich hier auch einen festen WErt eintragen
	//addMoment(m_force_boddy, Vec3(-0.50, 0.0, 0.0)); //also 50cm zurück vom COM
	//addMoment(Vec3(0.0, m_force_boddy.y, 0.0), Vec3(-0.55, 0.0, 0.0)); //das ist ein Versuch NUR die Drag-Force und die LiftForce
	//--------addMoment addiert Lift zu pitch als Moment----------
	double wheelChock = m_cockpitAPI.getParamNumber(m_wheelChockHandle);
	if (wheelChock < 0.9)
	{
		if (m_input.getBackACar() == 1.0 && m_l_thrustForce_x < 2000.0 && m_r_thrustForce_x < 2000.0 && m_airframe.getWeightOnWheels()>0)
		{
			printf("倒车请注意\n");
			double power = -13000 * (m_state.m_weight / 38000.0);
			addForce(Vec3(power, 0.0, 0.0), Vec3(-8, m_state.m_com.y, -0.8));
			addForce(Vec3(power, 0.0, 0.0), Vec3(-8, m_state.m_com.y, 0.8));
		}
		else
		{
			addForce(Vec3(m_l_thrustForce_x, m_l_thrustForce_y, m_l_thrustForce_z), Vec3(-8, m_state.m_com.y, -0.8));
			addForce(Vec3(m_r_thrustForce_x, m_r_thrustForce_y, m_r_thrustForce_z), Vec3(-8, m_state.m_com.y, 0.8));
		}
		//--------addForce addiert den Schub nach der Rotation des Drag zu der statischen Körper-X-Achse
		addForce(Vec3(0.0, m_plusThrust, 0.0), m_state.m_com);
	}
	//printf("boddy_force_X %f \n", m_force_boddy.x);
	//printf("BoddyForce Lift %f\n", m_force_boddy.y);
	//printf("BoddyForce-Drag %f\n", m_force_boddy.x);
	//printf("boddy_force_Z %f \n", m_force_boddy.z);
}

//------------Testweise um den Druck-Punkt der Kräfte zu setzen
/*const void FlightModel::setForcePressurePoint() const
{
	//m_state.m_com.x +=  aktuell -(WERT) weil durch den Einsatz der Klappen sich der Schwerpunkt nach hinten verschieben soll
	if (m_airframe.getFlapsPosition() > 0.0)
	{
		m_state.m_com.x += -(m_airframe.getFlapsPosition() * 0.45);// m_com.x ist der Schwerpunkt auf der X-Achse, NICHT der Druck-Punkt
	}
	else
	{
		m_state.m_com.x = 0.755; //setzt den Druckpunkt für die Kräfte auf der X-Achse orientiert nach dem 3d-Modell-Nullpunkt auf 0.75 Meter vor dem 3d-Modell-Nullpunkt
	}

}*/
//---------------Testweise ende-------------------------------

void FlightModel::calculateShake(double& dt)
{


	// cockpit shake calculations
	double shakeAmplitude{ 0.0 };
	double shakeInstGear = 0.0;
	double buffetAmplitude = 0.72; //war 0.6
	double x{ 0.0 };

	// 20 - 28
	double aoa = toDegrees(std::abs(m_state.m_aoa));
	double maxAoA = toDegrees(abs(CLzero(m_state.m_mach)));

	if (m_state.m_mach > 0.15)
	{
		//--Alte Formulierung die den MAX-Shaker bei 27° AOA setzte und shaker-Off bei 10°
		//shakeAmplitude = clamp((aoa - 10.0) / 17.0, 0.0, 1.0);//hier wird der Shaker für AoA gesetzt. Von 15.0 auf 18.0 auf 17.0
		//---Neue Formel, die den Shaker an dem Wert aus aktuellem AoA und max-AoA für die jeweilige Geschwindigkeit setzt.
		shakeAmplitude = clamp(((aoa / maxAoA) - 0.20) / 0.80, 0.0, 1.0);
	}

	shakeAmplitude *= buffetAmplitude;

	// GEAR CONTRIBUTION

	double gearContinousShake = (m_airframe.getGearLPosition() + m_airframe.getGearRPosition() + m_airframe.getGearNPosition()) / 3.0 * 0.8;


	if (m_airframe.getGearLPosition() > 0.99 || m_airframe.getGearLPosition() < 0.01)
	{
		gearShake = true;
	}
	else if (m_airframe.getGearRPosition() > 0.99 || m_airframe.getGearLPosition() < 0.01)
	{
		gearShake = true;
	}
	else if (m_airframe.getGearNPosition() > 0.99 || m_airframe.getGearLPosition() < 0.01)
	{
		gearShake = true;
	}
	else
	{
		gearShake = false;
	}

	if (gearShake && !prevGearShake)
	{
		m_shakeDuration.startTimer();
		prevGearShake = true;
	}
	else if (!gearShake)
	{
		prevGearShake = false;
	}

	// FLAPS CONTRIBUTION
	double flapsContinousShake = m_airframe.getFlapsPosition() * 0.06;


	// SPEED BRAKES CONTRIBUTION
	double speedBrakesContinousShake = m_airframe.getSpeedBrakePosition() * 0.12;


	m_shakeDuration.updateLoop(dt);

	if (m_shakeDuration.getState())
	{
		shakeInstGear += 0.5;
	}
	//printf(gearShake ? "true" : "false");
	//printf(prevGearShake ? "true" : "false");

	double airspeedScale = clamp((1.0 / 50.0) * (m_scalarVelocity - 50.0), 0.0, 1.0);

	double shakeGroupA = airspeedScale * std::min(flapsContinousShake + gearContinousShake, 0.075);
	double shakeGroupB = airspeedScale * speedBrakesContinousShake;
	double shakeGroupInst = std::min(shakeInstGear, 1.5);

	//printf("shake: %lf\n", shakeAmplitude);

	m_cockpitShake = shakeAmplitude + shakeGroupA + shakeGroupB + shakeGroupInst;
	m_cockpitShake *= 1.3; //CockpitShakeMultiplier von 1.5 auf 1.3

}



