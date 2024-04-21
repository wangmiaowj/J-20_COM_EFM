#pragma once
#include "BaseComponent.h"

//=========================================================================//
//
//		FILE NAME	: Timer.cpp
//		AUTHOR		: A4-Comunity-Team
//		Copyright	: A4-Comunity-Team
//		DATE		: May 2020
//
//		DESCRIPTION	: A Timer-Class...which times...time...sort off...  
//					  
//					  
//================================ Includes ===============================//
//=========================================================================//

class Timer : public BaseComponent
	{
	public:
		Timer(double time);
		~Timer();

		virtual void Timer::zeroInit();
		virtual void Timer::coldInit();
		virtual void Timer::hotInit();
		virtual void Timer::airborneInit();

		void updateLoop(double& dt);
		void startTimer();

		inline double getTime() { return m_time; };
		inline bool getState() { return m_isActive; };
		
	private:
		double m_time;
		double m_timeElapsed;
		bool m_isActive;
	};