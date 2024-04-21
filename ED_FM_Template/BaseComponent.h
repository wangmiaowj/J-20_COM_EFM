#pragma once
//=========================================================================//
//
//		FILE NAME	: BaseComponent.h
//		AUTHOR		: Joshua Nelson & A4-Comunity-Team
//		Copyright	: Joshua Nelson & A4-Comunity-Team
//		DATE		: May 2020
//
//		DESCRIPTION	: Init. functions for all classes to set all values to "0"
//					  
//					  
//================================ Includes ===============================//
//=========================================================================//
class BaseComponent
{
public:
	BaseComponent() {}
	virtual void zeroInit() = 0;
	virtual void coldInit() = 0;
	virtual void hotInit() = 0;
	virtual void airborneInit() = 0;

private:
};