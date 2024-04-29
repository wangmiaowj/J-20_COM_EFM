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
		aircraftHost->addSource(SND_PLAYMODE_ONCE, protos.APU_Start, 24.628);
		aircraftHost->addSource(SND_PLAYMODE_LOOPED, protos.APU_Running, 10.066);
		aircraftHost->addSource(SND_PLAYMODE_LOOPED, protos.APU_End, 20.498);
		cptHost->addSource(SND_PLAYMODE_ONCE, protos.APU_Start, 24.628);
		cptHost->addSource(SND_PLAYMODE_LOOPED, protos.APU_Running, 10.066);
		cptHost->addSource(SND_PLAYMODE_LOOPED, protos.APU_End, 20.498);
		headPhonesHost->addSource(SND_PLAYMODE_ONCE, protos.Test, 90.666);
		headPhonesHost->addSource(SND_PLAYMODE_ONCE, protos.bitSucc, 1.550);
		headPhonesHost->addSource(SND_PLAYMODE_ONCE, protos.leftEngFire, 1.934);
		headPhonesHost->addSource(SND_PLAYMODE_ONCE, protos.rightEngFire, 1.867);
		aircraftHost->getSource(protos.APU_Start).link(cptHost->getSource(protos.APU_Start));
		aircraftHost->getSource(protos.APU_Running).link(cptHost->getSource(protos.APU_Running));
		aircraftHost->getSource(protos.APU_End).link(cptHost->getSource(protos.APU_End));
		//headPhonesHost->getSource(protos.Test).playOnce();
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
	void updateBitSnd(double dt)
	{
		if (airframe.isBitSucc() && !headPhonesHost->getSource(protos.bitSucc).isPlaying())
		{
			headPhonesHost->getSource(protos.bitSucc).playOnce();
		}
	}
	void updateWarning(double dt)
	{
		if (eng.getFire() && elec.isDC() && warningPlayIdxMap.find(protos.leftEngFire) == warningPlayIdxMap.end())
		{
			warningPlayList.push_back(headPhonesHost->getSourceIndex(protos.leftEngFire));
			warningPlayIdxMap[protos.leftEngFire] = warningPlayList.size() - 1;
		}
		else if (warningPlayIdxMap.find(protos.leftEngFire) != warningPlayIdxMap.end() && !eng.getFire())
		{
			warningPlayList.erase(warningPlayList.begin() + warningPlayIdxMap[protos.leftEngFire]);
			for (auto it = warningPlayIdxMap.begin(); it != warningPlayIdxMap.end(); ++it)
			{
				if (it->second > warningPlayIdxMap[protos.leftEngFire])
				{
					it->second--;
				}
			}
			warningPlayIdxMap.erase(protos.leftEngFire);
		}
		if (eng.getFire2() && elec.isDC() && warningPlayIdxMap.find(protos.rightEngFire) == warningPlayIdxMap.end())
		{
			warningPlayList.push_back(headPhonesHost->getSourceIndex(protos.rightEngFire));
			warningPlayIdxMap[protos.rightEngFire] = warningPlayList.size() - 1;
		}
		else if (warningPlayIdxMap.find(protos.rightEngFire) != warningPlayIdxMap.end() && !eng.getFire2())
		{
			warningPlayList.erase(warningPlayList.begin() + warningPlayIdxMap[protos.rightEngFire]);
			for (auto it = warningPlayIdxMap.begin(); it != warningPlayIdxMap.end(); ++it)
			{
				if (it->second > warningPlayIdxMap[protos.rightEngFire])
				{
					it->second--;
				}
			}
			warningPlayIdxMap.erase(protos.rightEngFire);
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
	}
	void update(double dt)
	{
		//updateApuSnd(dt);
		updateBitSnd(dt);
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
	}
	void setCurrentOrientation(const Quaternion& _quaternion)
	{
		quaternion = _quaternion;
	}
private:
	struct Protos {
		std::wstring Test = L"Mp3Player/HOYO-MiX - 时暮的思眷 Le Souvenir avec le crepuscule";
		std::wstring APU_Start = L"Aircrafts/J-20A/APU";
		std::wstring APU_Running = L"Aircrafts/J-20A/APU_loop";
		std::wstring APU_End = L"Aircrafts/FA-18/APU_End";
		std::wstring bitSucc = L"Aircrafts/J-20A/Cockpit/bitComplate";
		std::wstring leftEngFire = L"Aircrafts/J-20A/Cockpit/Warning/LeftEngineFire";
		std::wstring rightEngFire = L"Aircrafts/J-20A/Cockpit/Warning/RightEngineFire";
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
	int playIdx = -1;
	Protos protos;
	int apuSndPlayStep = 0;
	Quaternion quaternion;
};