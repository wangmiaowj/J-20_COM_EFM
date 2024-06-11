#pragma once
#include <stdio.h>
#include "ED/sound.h"
#include "Engine.h"
#include "State.h"
#include "APU.h"
#include "FlightModel.h"
#include "Airframe.h"
#include "AutoPilot.h"
#include "Fuel_System.h"
#include "input.h"

class Sounder {
public:
	Sounder(Sound& p_sound, Engine& p_eng, State& p_state, APU& p_apu, FlightModel& p_model, Airframe& p_airframe, AutoPilot& p_ap, Fuelsystem& p_fuel, Input& p_input, avA11Clock& p_clock, avSimpleElectricSystem& p_elec)
		:
		snd(p_sound),
		eng(p_eng),
		state(p_state),
		flightModel(p_model),
		airframe(p_airframe),
		ap(p_ap),
		fuel(p_fuel),
		input(p_input),
		apu(p_apu),
		clock(p_clock),
		quaternion(),
		elec(p_elec)
	{

	}
	void init()
	{
		aircraftHost = std::make_unique< SoundHost>(snd.WORLD_CONTEXT, "J-20A_MAIN_HOST", snd);
		cptHost = std::make_unique< SoundHost>(snd.COCKPIT_CONTEXT, "J-20A_MAIN_CPT_HOST", snd);
		headPhonesHost = std::make_unique< SoundHost>(snd.HEADPHONES_CONTEXT, "J-20A_MAIN_HP_HOST", snd);
		aircraftHost->addSource(SND_PLAYMODE_ONCE, protos.APU_Start);
		aircraftHost->addSource(SND_PLAYMODE_LOOPED, protos.APU_Running);
		aircraftHost->addSource(SND_PLAYMODE_LOOPED, protos.APU_End);
		aircraftHost->addSource(SND_PLAYMODE_LOOPED, protos.airbrakeRun);
		aircraftHost->addSource(SND_PLAYMODE_LOOPED, protos.airbrakeEnd);
		aircraftHost->addSource(SND_PLAYMODE_LOOPED, protos.flapRun);
		aircraftHost->addSource(SND_PLAYMODE_LOOPED, protos.flapEnd);
		aircraftHost->addSource(SND_PLAYMODE_ONCE, protos.laserFire);
		cptHost->addSource(SND_PLAYMODE_ONCE, protos.APU_Start);
		cptHost->addSource(SND_PLAYMODE_LOOPED, protos.APU_Running);
		cptHost->addSource(SND_PLAYMODE_LOOPED, protos.APU_End);
		cptHost->addSource(SND_PLAYMODE_ONCE, protos.laserFireIn);
		headPhonesHost->addSource(SND_PLAYMODE_ONCE, protos.Test);
		headPhonesHost->addSource(SND_PLAYMODE_ONCE, protos.bitSucc);
		headPhonesHost->addSource(SND_PLAYMODE_ONCE, protos.leftEngFire);
		headPhonesHost->addSource(SND_PLAYMODE_ONCE, protos.rightEngFire);
		headPhonesHost->addSource(SND_PLAYMODE_ONCE, protos.brokenWingWaring);
		aircraftHost->getSource(protos.APU_Start).link(cptHost->getSource(protos.APU_Start));
		aircraftHost->getSource(protos.APU_Running).link(cptHost->getSource(protos.APU_Running));
		aircraftHost->getSource(protos.APU_End).link(cptHost->getSource(protos.APU_End));
		aircraftHost->getSource(protos.laserFire).link(cptHost->getSource(protos.laserFire));
		//headPhonesHost->getSource(protos.Test).playOnce();

		world3DListenerParam = std::make_unique<SND_ListenerParams>();
		world3DListenerParam->fields = 5;
		world3DListenerParam->position[0] = 0.0;
		world3DListenerParam->position[1] = 0.0;
		world3DListenerParam->position[2] = 0.0;
		world3DListenerParam->velocity[0] = 0.0;
		world3DListenerParam->velocity[1] = 0.0;
		world3DListenerParam->velocity[2] = 0.0;
		world3DListenerParam->orientation[0] = 0.0;
		world3DListenerParam->orientation[1] = 0.0;
		world3DListenerParam->orientation[2] = 0.0;
		world3DListenerParam->orientation[3] = 0.0;
		world3DListenerParam->gain = 1.0;
		world3DListenerParam->pitch = 1.0;
		world3DListenerParam->lowpass = 24000.0;
		world3DListenerParam->timestamp = 0.0;
		snd.snd_set_listener(snd.WORLD_CONTEXT, world3DListenerParam.get());
		printf("sounder init\n");
	}
	void updateApuSnd(double dt)
	{
		if (apu.isRunning())
		{
			if (!snd.snd_is_playing(aircraftHost->getSource(protos.APU_Start).getSrcId()) && apuSndPlayStep == 0)
			{
				aircraftHost->getSource(protos.APU_Start).playOnce();
				apuSndPlayStep++;
			}
			else if (!snd.snd_is_playing(aircraftHost->getSource(protos.APU_Start).getSrcId()) && apuSndPlayStep == 1)
			{
				aircraftHost->getSource(protos.APU_Running).playLoop();
				apuSndPlayStep++;
			}
		}
		else
		{
			if ((snd.snd_is_playing(aircraftHost->getSource(protos.APU_Running).getSrcId()) && apuSndPlayStep == 2) || (snd.snd_is_playing(aircraftHost->getSource(protos.APU_Start).getSrcId()) && apuSndPlayStep == 1))
			{
				aircraftHost->getSource(protos.APU_Start).stop();
				aircraftHost->getSource(protos.APU_Running).stop();
				aircraftHost->getSource(protos.APU_End).playOnce();
				apuSndPlayStep = 0;
			}
		}
	}
	void updateAirBrakeSnd(double dt) {
		SoundSource& airbrakeRunSrc = aircraftHost->getSource(protos.airbrakeRun);
		SoundSource& airbrakeEndSrc = aircraftHost->getSource(protos.airbrakeEnd);
		if (!airframe.airbrakeIsRun() && airbrakeRunSrc.isPlaying() && !airbrakeEndSrc.isPlaying())
		{
			airbrakeRunSrc.stop();
			airbrakeEndSrc.playOnce();
		}
		else if (airframe.airbrakeIsRun() && !airbrakeRunSrc.isPlaying())
		{
			airbrakeEndSrc.stop();
			airbrakeRunSrc.playLoop();
		}
	}
	void updateFlapSnd(double dt) {
		SoundSource& flapRunSrc = aircraftHost->getSource(protos.flapRun);
		SoundSource& flapEndSrc = aircraftHost->getSource(protos.flapEnd);
		if (!airframe.flapsIsRun() && flapRunSrc.isPlaying() && !flapEndSrc.isPlaying())
		{
			flapRunSrc.stop();
			flapEndSrc.playOnce();
		}
		else if (airframe.flapsIsRun() && !flapRunSrc.isPlaying())
		{
			flapEndSrc.stop();
			flapRunSrc.playLoop();
		}
	}
	void updateBitSnd(double dt)
	{
		if (airframe.isBitSucc() && !headPhonesHost->getSource(protos.bitSucc).isPlaying())
		{
			headPhonesHost->getSource(protos.bitSucc).playOnce();
		}
	}
	void updateWarning(double dt)
	{
		if (eng.getFire() && elec.isDC() && warningPlayIdxMap.find(protos.leftEngFire.path) == warningPlayIdxMap.end())
		{
			warningPlayList.push_back(headPhonesHost->getSourceIndex(protos.leftEngFire));
			warningPlayIdxMap[protos.leftEngFire.path] = warningPlayList.size() - 1;
		}
		else if (warningPlayIdxMap.find(protos.leftEngFire.path) != warningPlayIdxMap.end() && !eng.getFire())
		{
			warningPlayList.erase(warningPlayList.begin() + warningPlayIdxMap[protos.leftEngFire.path]);
			for (auto it = warningPlayIdxMap.begin(); it != warningPlayIdxMap.end(); ++it)
			{
				if (it->second > warningPlayIdxMap[protos.leftEngFire.path])
				{
					it->second--;
				}
			}
			warningPlayIdxMap.erase(protos.leftEngFire.path);
		}
		if (eng.getFire2() && elec.isDC() && warningPlayIdxMap.find(protos.rightEngFire.path) == warningPlayIdxMap.end())
		{
			warningPlayList.push_back(headPhonesHost->getSourceIndex(protos.rightEngFire));
			warningPlayIdxMap[protos.rightEngFire.path] = warningPlayList.size() - 1;
		}
		else if (warningPlayIdxMap.find(protos.rightEngFire.path) != warningPlayIdxMap.end() && !eng.getFire2())
		{
			warningPlayList.erase(warningPlayList.begin() + warningPlayIdxMap[protos.rightEngFire.path]);
			for (auto it = warningPlayIdxMap.begin(); it != warningPlayIdxMap.end(); ++it)
			{
				if (it->second > warningPlayIdxMap[protos.rightEngFire.path])
				{
					it->second--;
				}
			}
			warningPlayIdxMap.erase(protos.rightEngFire.path);
		}
		if (warningPlayList.size() > 0)
		{
			if (playIdx == -1)
			{
				playIdx = 0;
			}
			if (playIdx >= warningPlayList.size() - 1)
			{
				playIdx = warningPlayList.size() - 1;
			}
			int lastIdx;
			if (playIdx == 0)
			{
				lastIdx = warningPlayList.size() - 1;
			}
			else
			{
				lastIdx = playIdx - 1;
			}
			SoundSource& src = headPhonesHost->getSource(warningPlayList[lastIdx]);
			if (!src.isPlaying())
			{
				//如果上一个音乐已播放完毕就播放本音乐然后索引+1
				headPhonesHost->getSource(warningPlayList[playIdx]).playOnce();
				playIdx++;
				if (playIdx >= warningPlayList.size())
				{
					playIdx = 0;
				}
			}
		}
		else
		{
			playIdx = -1;
		}
		if (airframe.isBrokenWingWarning())
		{
			if (!headPhonesHost->getSource(protos.brokenWingWaring).isPlaying())
			{
				headPhonesHost->getSource(protos.brokenWingWaring).playOnce();
			}
		}
	}
	void setCommand(int cmd, float value)
	{
		if (cmd == LaserFire)
		{
			SoundSource& laserFireSrc = aircraftHost->getSource(protos.laserFire);
			laserFireSrc.playOnce();
		}
	}
	void update(double dt)
	{
		//updateApuSnd(dt);
		updateBitSnd(dt);
		updateAirBrakeSnd(dt);
		updateFlapSnd(dt);
		try
		{
			updateWarning(dt);
		}
		catch (const std::exception& e)
		{
			printf("%s\n", e.what());
		}
		headPhonesHost->update(dt, state, clock.get_currtime(), quaternion);
		aircraftHost->update(dt, state, clock.get_currtime(), quaternion);
		cptHost->update(dt, state, clock.get_currtime(), quaternion);
		world3DListenerParam->position[0] = state.m_worldPosition.x;
		world3DListenerParam->position[1] = state.m_worldPosition.y;
		world3DListenerParam->position[2] = state.m_worldPosition.z;
		world3DListenerParam->velocity[0] = state.m_localSpeed.x;
		world3DListenerParam->velocity[1] = state.m_localSpeed.y;
		world3DListenerParam->velocity[2] = state.m_localSpeed.z;
		world3DListenerParam->orientation[0] = quaternion.x;
		world3DListenerParam->orientation[1] = quaternion.y;
		world3DListenerParam->orientation[2] = quaternion.z;
		world3DListenerParam->orientation[3] = quaternion.w;
		world3DListenerParam->timestamp = clock.get_currtime();
	}
	void setCurrentOrientation(const Quaternion& _quaternion)
	{
		quaternion = _quaternion;
	}
private:
	struct Protos {
		Proto Test = Proto(L"Mp3Player/HOYO-MiX - 时暮的思眷 Le Souvenir avec le crepuscule", 90.666f);
		Proto APU_Start = Proto(L"Aircrafts/J-20A/APU", 24.628f);
		Proto APU_Running = Proto(L"Aircrafts/J-20A/APU_loop", 10.066f);
		Proto APU_End = Proto(L"Aircrafts/FA-18/APU_End", 20.498f);
		Proto bitSucc = Proto(L"Aircrafts/J-20A/Cockpit/bitComplate", 1.550f);
		Proto leftEngFire = Proto(L"Aircrafts/J-20A/Cockpit/Warning/LeftEngineFire", 1.934f);
		Proto rightEngFire = Proto(L"Aircrafts/J-20A/Cockpit/Warning/RightEngineFire", 1.867f);
		Proto brokenWingWaring = Proto(L"Aircrafts/F-15/Cockpit/OWS2", 0.805f);
		Proto airbrakeRun = Proto(L"Aircrafts/AirBrake", 6.619f);
		Proto airbrakeEnd = Proto(L"Aircrafts/AirBrakeEnd", 0.739f);
		Proto flapRun = Proto(L"Aircrafts/FlapsElectric", 4.609f);
		Proto flapEnd = Proto(L"Aircrafts/FlapsElectricEnd", 0.542f);
		Proto laserFire = Proto(L"Weapons/LaserFire", 1.134f, 5.0f, 5000.0f);
		Proto laserFireIn = Proto(L"Weapons/LaserFire", 1.134f);
	};
	Sound& snd;
	Engine& eng;
	State& state;
	APU& apu;
	FlightModel& flightModel;
	Airframe& airframe;
	AutoPilot& ap;
	Fuelsystem& fuel;
	Input& input;
	avA11Clock& clock;
	avSimpleElectricSystem& elec;
	std::unique_ptr< SoundHost> aircraftHost;
	std::unique_ptr< SoundHost> cptHost;
	std::unique_ptr< SoundHost> headPhonesHost;
	std::map<std::wstring, int>warningPlayIdxMap;
	std::vector<int>warningPlayList;
	std::unique_ptr< SND_ListenerParams> world3DListenerParam;
	int playIdx = -1;
	Protos protos;
	int apuSndPlayStep = 0;
	Quaternion quaternion;
};