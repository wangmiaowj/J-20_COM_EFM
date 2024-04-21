#pragma once
#ifndef PID_H
#define PID_H

#include "BaseComponent.h" 



struct PID
{
	PID() {}

	//Initialization
	virtual void zeroInit();
	virtual void coldInit();
	virtual void hotInit();
	virtual void airborneInit();

	//Controller Functions
	//--------Attitude Controller---------------------------------
	double attitudePIDControl(double setpoint, double measurement);
	//--------Altitude Controler as in "Höhe" :-) ----------------
	double altitudePIDControl(double setpoint, double measurement);
	//-------fly-by-wire PID Controller---------------------------
	double fbwPIDControl(double setpoint, double measurement);
	//--------HDG PID Controller
	double hdgPIDControl(double setpoint, double measurement);

	//Controller Gains
	//att
	double p_Kp = 0.0; //Present -> Proportional
	double p_Ki = 0.0; //Past -> Integral
	double p_Kd = 0.0; //Future -> Derivative
	//ALT
	double p_ALT_Kp = 0.0; //Present -> Proportional
	double p_ALT_Ki = 0.0; //Past -> Integral
	double p_ALT_Kd = 0.0; //Future -> Derivative
	//FBW
	double p_FBW_Kp = 0.0; //Present -> Proportional
	double p_FBW_Ki = 0.0; //Past -> Integral
	double p_FBW_Kd = 0.0; //Future -> Derivative
	//AP
	double p_HDG_Kp = 0.0; //Present -> Proportional
	double p_HDG_Ki = 0.0; //Past -> Integral
	double p_HDG_Kd = 0.0; //Future -> Derivative


	//Derivative Filter Variable for time constant
	//att
	double p_TAU = 0.0;
	//ALT
	double p_ALT_TAU = 0.0;
	//FBW
	double p_FBW_TAU = 0.0;
	//AP
	double p_HDG_TAU = 0.0;

	//Output Limits
	//att
	double p_limMin = 0.0;
	double p_limMax = 0.0;
	//ALT
	double p_ALT_limMin = 0.0;
	double p_ALT_limMax = 0.0;
	//FBW
	double p_FBW_limMin = 0.0;
	double p_FBW_limMax = 0.0;
	//AP
	double p_HDG_limMin = 0.0;
	double p_HDG_limMax = 0.0;

	//Sample Time
	//att
	double p_time = 0.0;
	//ALT
	double p_ALT_time = 0.0;
	//FBW
	double p_FBW_time = 0.0;
	//AP
	double p_HDG_time = 0.0;

	//Controler Memory of step and last step
	//att
	double p_integrator = 0.0;
	double p_error = 0.0;
	double p_prevError = 0.0;
	double p_prevMeasurement = 0.0;
	double p_differentiator = 0.0;
	double p_proportional = 0.0;
	//ALT
	double p_ALT_integrator = 0.0;
	double p_ALT_error = 0.0;
	double p_ALT_prevError = 0.0;
	double p_ALT_prevMeasurement = 0.0;
	double p_ALT_differentiator = 0.0;
	double p_ALT_proportional = 0.0;
	//FBW
	double p_FBW_integrator = 0.0;
	double p_FBW_error = 0.0;
	double p_FBW_prevError = 0.0;
	double p_FBW_prevMeasurement = 0.0;
	double p_FBW_differentiator = 0.0;
	double p_FBW_proportional = 0.0;
	//ap
	double p_HDG_integrator = 0.0;
	double p_HDG_error = 0.0;
	double p_HDG_prevError = 0.0;
	double p_HDG_prevMeasurement = 0.0;
	double p_HDG_differentiator = 0.0;
	double p_HDG_proportional = 0.0;

	//Controller Output
	//att
	double p_output = 0.0;
	//ALT
	double p_ALT_output = 0.0;
	//FBW
	double p_FBW_output = 0.0;
	//AP
	double p_HDG_output = 0.0;
};



#endif
