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
	Sounder(Sound& p_sound, Engine& p_eng, State& p_state, APU& p_apu, FlightModel& p_model, Airframe& p_airframe, AutoPilot& p_ap, Fuelsystem& p_fuel, Input& p_input, avA11Clock& p_clock)
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
		quaternion()
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
	void update(double dt)
	{
		//updateApuSnd(dt);
		updateBitSnd(dt);
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
		std::wstring Test = L"Mp3Player/HOYO-MiX - Ê±ÄºµÄË¼¾ì Le Souvenir avec le crepuscule";
		std::wstring APU_Start = L"Aircrafts/J-20A/APU";
		std::wstring APU_Running = L"Aircrafts/J-20A/APU_loop";
		std::wstring APU_End = L"Aircrafts/FA-18/APU_End";
		std::wstring bitSucc = L"Aircrafts/J-20A/Cockpit/bitComplate";
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
	std::unique_ptr< SoundHost> aircraftHost;
	std::unique_ptr< SoundHost> cptHost;
	std::unique_ptr< SoundHost> headPhonesHost;
	Protos protos;
	int apuSndPlayStep = 0;
	Quaternion quaternion;
};