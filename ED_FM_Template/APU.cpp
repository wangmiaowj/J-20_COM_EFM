#include "APU.h"
APU::APU
(
	Input& input,
	avSimpleElectricSystem& elec,
	EDPARAM& cockpitAPI
) :
	m_input(input),
	m_cockpitAPI(cockpitAPI),
	m_elec(elec)
{

}

void APU::zeroInit() {
	m_rpmNormal = 0.0;
	m_fuelFlow = 0.0;
	m_correctedFuelFlow = 0.0;
	m_hasFuel = true;
	m_startor_dn = false;
}
void APU::coldInit() {
	zeroInit();
}
void APU::hotInit() {
	zeroInit();
}

void APU::airborneInit() {
	zeroInit();
}

void APU::update(double dt) {
	if ((!m_hasFuel || !m_elec.isDC()) && m_apuRunning)
	{
		m_apuRunning = false;
	}
	if (m_input.getStartor() == 0)
	{
		m_startor_dn = false;
	}
	if (m_input.getStartorPos() == 1 && m_input.getStartor() == 1 && m_hasFuel && m_elec.isDC() == 1 && m_startor_dn == false)
	{
		m_startor_dn = true;
		m_apuRunning = !m_apuRunning;
	}
	if (m_apuRunning && m_rpmNormal < 1 && m_elec.isDC())
	{
		m_rpmNormal = clamp(m_rpmNormal + dt * 0.1, 0, 1);
	}
	else if ((!m_apuRunning || !m_elec.isDC()) && m_rpmNormal > 0)
	{
		m_rpmNormal = clamp(m_rpmNormal - dt * 0.1, 0, 1);
	}
	m_cockpitAPI.setParamNumber(apuRpm_h, m_rpmNormal * 100);
}

double APU::FuelFlowUpdate() {
	m_fuelFlow = 0.005 * m_rpmNormal;
	return m_fuelFlow;
}
bool APU::isOccupy() {
	return m_occupy;
}
void APU::occupy(int pos) {
	m_occupy = true;
	m_occupier = pos;
}
void APU::unoccupy() {
	m_occupy = false;
	m_occupier = 0;
}
int APU::getOccupier() {
	return m_occupier;
}