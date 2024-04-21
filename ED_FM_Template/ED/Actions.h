#ifdef INPUT_LUA_BINDING
#undef _ACTIONS_H_
#endif

#ifndef _ACTIONS_H_
#define _ACTIONS_H_

#include "iCommand.h"

#ifndef INPUT_LUA_BINDING
#undef REGISTER_COMMAND
#define REGISTER_COMMAND(cmd) cmd,
#undef REGISTER_COMMAND_EX
#define REGISTER_COMMAND_EX(cmd, value) cmd = value,
#endif

#ifndef INPUT_LUA_BINDING
enum iCommandKey
{
#endif

	REGISTER_COMMAND_EX(iCommandKeyNull, 2000)
	REGISTER_COMMAND(iCommandPlanePitch)
	REGISTER_COMMAND(iCommandPlaneRoll)
	REGISTER_COMMAND(iCommandPlaneRudder)
	REGISTER_COMMAND(iCommandPlaneThrustCommon)
	REGISTER_COMMAND(iCommandPlaneThrustLeft)
	REGISTER_COMMAND(iCommandPlaneThrustRight)
	REGISTER_COMMAND(iCommandPlaneViewHorizontal)
	REGISTER_COMMAND(iCommandPlaneViewVertical)
	REGISTER_COMMAND(iCommandPlaneZoomView)
	REGISTER_COMMAND(iCommandViewHorizontalAbs) // =  2010
	REGISTER_COMMAND(iCommandViewVerticalAbs)
	REGISTER_COMMAND(iCommandViewZoomAbs)
	REGISTER_COMMAND(iCommandPlanePitchDelta)
	REGISTER_COMMAND(iCommandPlaneRollDelta)
	REGISTER_COMMAND(iCommandPlaneRudderDelta)
	REGISTER_COMMAND(iCommandPlaneThrustCommonDelta)
	REGISTER_COMMAND(iCommandPlaneThrustLeftDelta)
	REGISTER_COMMAND(iCommandPlaneThrustRightDelta)
	REGISTER_COMMAND(iCommandPlaneTrimPitch)
	REGISTER_COMMAND(iCommandPlaneTrimRoll) // == 2020
	REGISTER_COMMAND(iCommandPlaneTrimRudder)
	REGISTER_COMMAND(iCommandPlaneTrimPitchAbs)
	REGISTER_COMMAND(iCommandPlaneTrimRollAbs)
	REGISTER_COMMAND(iCommandPlaneTrimRudderAbs)
	REGISTER_COMMAND(iCommandPlaneRadarHorizontal)
	REGISTER_COMMAND(iCommandPlaneRadarVertical)
	REGISTER_COMMAND(iCommandPlaneRadarHorizontalAbs)
	REGISTER_COMMAND(iCommandPlaneRadarVerticalAbs)
	REGISTER_COMMAND(iCommandPlaneMFDZoom)
	REGISTER_COMMAND(iCommandPlaneMFDZoomAbs) // = 2030
	REGISTER_COMMAND(iCommandPlaneSelecterHorizontal)
	REGISTER_COMMAND(iCommandPlaneSelecterVertical)
	REGISTER_COMMAND(iCommandPlaneSelecterHorizontalAbs)
	REGISTER_COMMAND(iCommandPlaneSelecterVerticalAbs)
	REGISTER_COMMAND(iCommandPlaneFeedbackTrimmer)	// §³§à§ç§â§Ñ§ß§Ö§ß§Ú§Ö §ã§à§ã§ä§à§ñ§ß§Ú§ñ Feedback §Õ§Ý§ñ §ä§â§Ö§Ü§à§Ó (Inside Action)
	REGISTER_COMMAND(iCommandCockpitCursorHorizontal)	// §¬§å§â§ã§à§â §Õ§Ó§Ú§Ø§Ö§ä§ã§ñ §à§ä§ß§à§ã§Ú§ä§Ö§Ý§î§ß§à §Ü§Ñ§Ò§Ú§ß§í §Õ§Ý§ñ §å§á§â§Ñ§Ó§Ý§Ö§ß§Ú§ñ §å§ã§ä§â§à§Û§ã§ä§Ó§Ñ§Þ§Ú
	REGISTER_COMMAND(iCommandCockpitCursorVertical)
	REGISTER_COMMAND(iCommandCockpitCursorHorizontalAbs)
	REGISTER_COMMAND(iCommandCockpitCursorVerticalAbs)
	REGISTER_COMMAND(iCommandPlaneBase_Distance) //2040    // §¤§Ñ§Ý§Ö§ä§ß§Ú§Ü §Ò§Ñ§Ù§Ñ - §Õ§Ñ§Ý§î§ß§à§ã§ä§î (§Ò§Ñ§Ù§Ñ §è§Ö§Ý§Ú )
	REGISTER_COMMAND(iCommandPlaneBase_DistanceAbs)
	/* OBSOLETE */	REGISTER_COMMAND(iCommandViewAWACSMapMouseMove)
	REGISTER_COMMAND(iCommandViewCameraAltitude)		// §¬§à§â§â§Ö§Ü§ä§Ú§â§à§Ó§Ü§Ñ §Ó§í§ã§à§ä§í §Ü§Ñ§Þ§Ö§â§í (§Õ§Ý§ñ §ã§ç§à§Õ§Ú§Þ§à§ã§ä§Ú §ä§â§Ö§Ü§à§Ó)
	REGISTER_COMMAND(iCommandViewAWACSObjectIdLow)
	REGISTER_COMMAND(iCommandViewAWACSObjectIdHigh)
	REGISTER_COMMAND(iCommandViewRoll)
	REGISTER_COMMAND(iCommandViewRollAbs)
	REGISTER_COMMAND(iCommandViewHorTrans)
	REGISTER_COMMAND(iCommandViewHorTransAbs)
	REGISTER_COMMAND(iCommandViewVertTrans) //2050
	REGISTER_COMMAND(iCommandViewVertTransAbs)
	REGISTER_COMMAND(iCommandViewLongitudeTrans)
	REGISTER_COMMAND(iCommandViewLongitudeTransAbs)
	REGISTER_COMMAND(iCommandViewAWACSDistanceToolDistance)
	REGISTER_COMMAND(iCommandViewAWACSDistanceToolAngle)
	REGISTER_COMMAND(iCommandViewAWACSMouseMoveX)
	REGISTER_COMMAND(iCommandViewAWACSMouseMoveY)
	REGISTER_COMMAND(iCommandViewAWACSLastZoomX1)
	REGISTER_COMMAND(iCommandViewAWACSLastZoomX2)
	REGISTER_COMMAND(iCommandViewAWACSLastZoomY1) //2060
	REGISTER_COMMAND(iCommandViewAWACSLastZoomY2)
	REGISTER_COMMAND(iCommandViewAWACSZoom100)
	REGISTER_COMMAND(iCommandViewAWACSZoomIn)
	REGISTER_COMMAND(iCommandViewAWACSZoomOut)
	REGISTER_COMMAND(iCommandViewAWACSDistance)
	REGISTER_COMMAND(iCommandViewAWACSLabels)
	REGISTER_COMMAND(iCommandViewAWACSDetectionAreas)
	REGISTER_COMMAND(iCommandViewAWACSDangerousAreas)
	REGISTER_COMMAND(iCommandViewAWACSCenterOnPlane)
	REGISTER_COMMAND(iCommandViewAWACSDistanceX1) //2070
	REGISTER_COMMAND(iCommandViewAWACSDistanceY1)
	REGISTER_COMMAND(iCommandViewAWACSDistanceX2)
	REGISTER_COMMAND(iCommandViewAWACSDistanceY2)
	REGISTER_COMMAND(iCommandCockpitVirtualAxis)   // §Ó§Ú§â§ä§å§Ñ§Ý§î§ß§Ñ§ñ §à§ã§î §Õ§Ý§ñ §å§á§â§Ñ§Ó§Ý§Ö§ß§Ú§ñ §ï§Ý§Ö§Þ§Ö§ß§ä§Ñ§Þ§Ú §Ó §Ü§Ñ§Ò§Ú§ß§Ö §ä§Ú§á§Ñ §à§ã§î 
	REGISTER_COMMAND(iCommandCockpitVirtualAxisAbs) // §Ó§Ú§â§ä§å§Ñ§Ý§î§ß§Ñ§ñ §à§ã§î §Õ§Ý§ñ §å§á§â§Ñ§Ó§Ý§Ö§ß§Ú§ñ §ï§Ý§Ö§Þ§Ö§ß§ä§Ñ§Þ§Ú §Ó §Ü§Ñ§Ò§Ú§ß§Ö §ä§Ú§á§Ñ §à§ã§î
	REGISTER_COMMAND(iCommandViewAWACSTargetPointerX)
	REGISTER_COMMAND(iCommandViewAWACSTargetPointerY)
	REGISTER_COMMAND(iCommandViewAWACSApplyTargetPointer)
	REGISTER_COMMAND(iCommandViewAWACSInfoTargetButton) //2080
	REGISTER_COMMAND(iCommandViewAWACSInfoCloseButton)
	REGISTER_COMMAND(iCommandViewAWACSTargetFireButton)
	REGISTER_COMMAND(iCommandViewAWACSTargetRemoveButton)
	REGISTER_COMMAND(iCommandViewAWACSTargetCloseButton)
	REGISTER_COMMAND(iCommandViewAWACSTargetStartTime)
	REGISTER_COMMAND(iCommandViewAWACSTargetUnits)
	REGISTER_COMMAND(iCommandViewAWACSTargetRounds)

	REGISTER_COMMAND(iCommandPlaneCollective) //§²§å§é§Ü§Ñ §º§¡§¤-§¤§¡§©

	//§à§ã§Ú §Õ§Ý§ñ §Õ§Ú§ß§Ñ§Þ§Ú§é§Ö§ã§Ü§Ú§ç §ß§Ñ§ã§ä§â§à§Ö§Ü 
	REGISTER_COMMAND(iCommandDebugAxis1)
	REGISTER_COMMAND(iCommandDebugAxis2)
	REGISTER_COMMAND(iCommandDebugAxis3)
	REGISTER_COMMAND(iCommandDebugAxis4)
	REGISTER_COMMAND(iCommandDebugAxis5)
	REGISTER_COMMAND(iCommandDebugAxis6)
	REGISTER_COMMAND(iCommandDebugAxis7)
	REGISTER_COMMAND(iCommandDebugAxis8)
	REGISTER_COMMAND(iCommandDebugAxis9)
	REGISTER_COMMAND(iCommandDebugAxis10)
	//ENGINE CONTROL ANALOG AXIS
	REGISTER_COMMAND(iCommandHelicopterLeftEngineBrake_ByAxis)
	REGISTER_COMMAND(iCommandHelicopterRightEngineBrake_ByAxis)
	REGISTER_COMMAND(iCommandHelicopterRotorEngineBrake_ByAxis)

	REGISTER_COMMAND(iCommandWheelBrake) //§à§ã§î §Ü§à§Ý§Ö§ã§ß§à§Ô§à §ä§à§â§Þ§à§Ù§Ñ

	REGISTER_COMMAND(iCommandViewAWACSSetColumnPath)
	REGISTER_COMMAND(iCommandViewAWACSCancelColumnPath)
	REGISTER_COMMAND(iCommandViewAWACSInfoPathButton)
	REGISTER_COMMAND(iCommandViewAWACSSetPathCloseButton)
	REGISTER_COMMAND(iCommandViewAWACSUpdateWOInfoLow)
	REGISTER_COMMAND(iCommandViewAWACSUpdateWOInfoHigh)

	REGISTER_COMMAND(iCommandViewAWACSVehControlCloseButton)
	REGISTER_COMMAND(iCommandViewAWACSSetColumnSpeed)
	REGISTER_COMMAND(iCommandViewAWACSChangeColumnState)
	REGISTER_COMMAND(iCommandViewAWACSChangeColumnForm)

	REGISTER_COMMAND(iCommandLeftWheelBrake) //§à§ã§î §ä§à§â§Þ§à§Ù§Ñ §Ý§Ö§Ó§à§Ô§à §Ü§à§Ý§Ö§ã§Ñ
	REGISTER_COMMAND(iCommandRightWheelBrake) //§à§ã§î §ä§à§â§Þ§à§Ù§Ñ §á§â§Ñ§Ó§à§Ô§à §Ü§à§Ý§Ö§ã§Ñ

	REGISTER_COMMAND(iCommandViewAWACSTargetSetButton)
	REGISTER_COMMAND(iCommandRoleCoalitionUpdated)

	//§¬§à§Þ§Ñ§ß§Õ§í §á§â§Ú§ç§à§Õ§ñ§ë§Ú§Ö §à§ä §Õ§Ú§Ñ§Ý§à§Ô§Ñ §Ü§Ñ§â§ä§í §Ó §æ10, §ß§å§Ø§ß§í §Õ§Ý§ñ §Ó§à§ã§á§â§à§Ú§Ù§Ó§Ö§Õ§Ö§ß§Ú§ñ §ä§â§ï§Ü§à§Ó
	REGISTER_COMMAND(iCommandViewAWACSMapEventType)
	REGISTER_COMMAND(iCommandViewAWACSMapEventX)
	REGISTER_COMMAND(iCommandViewAWACSMapEventY)
	REGISTER_COMMAND(iCommandViewAWACSMapEventFlags)

	//§¬§à§Þ§Ñ§ß§Õ§í §á§â§Ú§ç§à§Õ§ñ§ë§Ú§Ö §à§ä §Ü§Ý§Ñ§Ó§Ú§Ñ§ä§å§â§í §Ó §æ10, §ß§å§Ø§ß§í §Õ§Ý§ñ §Ó§à§ã§á§â§à§Ú§Ù§Ó§Ö§Õ§Ö§ß§Ú§ñ §ä§â§ï§Ü§à§Ó
	REGISTER_COMMAND(iCommandViewAWACSKeyState)
	REGISTER_COMMAND(iCommandViewAWACSKeyKey)
	REGISTER_COMMAND(iCommandViewAWACSKeyData)

	//§¬§à§Þ§Ñ§ß§Õ§í §á§â§Ú§ç§à§Õ§ñ§ë§Ú§Ö §à§ä §ä§å§Ý§Ò§Ñ§â§Ñ §Ó §æ10, §ß§å§Ø§ß§í §Õ§Ý§ñ §Ó§à§ã§á§â§à§Ú§Ù§Ó§Ö§Õ§Ö§ß§Ú§ñ §ä§â§ï§Ü§à§Ó
	REGISTER_COMMAND(iCommandViewAWACSShowPathes)
	REGISTER_COMMAND(iCommandViewAWACSShowTargets)

	//§¬§à§Þ§Þ§Ñ§ß§Õ§í §à§ä §Õ§Ú§Ñ§Ý§à§Ô§à§Ó §æ10
	REGISTER_COMMAND(iCommandViewAWACSRoadPriorChanged)
	REGISTER_COMMAND(iCommandViewAWACSBridgesPriorChanged)
	REGISTER_COMMAND(iCommandViewAWACSFireEnabledChanged)
	REGISTER_COMMAND(iCommandViewAWACSTargetXChanged)
	REGISTER_COMMAND(iCommandViewAWACSTargetZChanged)


	REGISTER_COMMAND(iCommand_TDC_AbsolutePositionHorizontal)
	REGISTER_COMMAND(iCommand_TDC_AbsolutePositionVertical)

	REGISTER_COMMAND(iCommandAdjustViewAngleToComfortValue)

	REGISTER_COMMAND(iCommandViewAWACSChangeROE)
	REGISTER_COMMAND(iCommandViewAWACSChangeAlarmState)
	REGISTER_COMMAND(iCommandViewAWACSTargetChangeRadius)
	REGISTER_COMMAND(iCommandViewAWACSTargetRadiusSet)

	REGISTER_COMMAND(iCommandViewLaserCodeChanged)
	REGISTER_COMMAND(iCommandViewAWACSSetColumnAltitude)
	REGISTER_COMMAND(iCommandViewAWACSShowHealths)
	REGISTER_COMMAND(iCommandViewAWACSInfoAddTargetButton)
	REGISTER_COMMAND(iCommandViewAWACSInfoDelTargetButton)

	REGISTER_COMMAND(iServiceInformAboutUserHAngle)
	REGISTER_COMMAND(iServiceInformAboutUserVAngle)

	REGISTER_COMMAND(iOculusRiftYaw)
	REGISTER_COMMAND(iOculusRiftPitch)
	REGISTER_COMMAND(iOculusRiftRoll)
	REGISTER_COMMAND(iOculusRiftHeadPosX)
	REGISTER_COMMAND(iOculusRiftHeadPosY)
	REGISTER_COMMAND(iOculusRiftHeadPosZ)


	//-insert here
	REGISTER_COMMAND(iCommandRoleSet)
	REGISTER_COMMAND(iCommandCoalitionSet)

	REGISTER_COMMAND(iCommandKeyMaximum)
	//----------------------------------------
	REGISTER_COMMAND_EX(iCommandCockpitDeviceCommandsStart, 3000) //§ß§Ñ§é§Ñ§Ý§î§ß§Ñ§ñ §ä§à§é§Ü§Ñ §Ü§à§Þ§Ñ§ß§Õ §Ü§à§Ü§á§Ú§ä§Ñ (§Ù§Ñ§â§Ö§Ù§Ö§â§Ó§Ú§â§à§Ó§Ñ§ß§à §Õ§à iCommandCockpitDeviceCommandsEnd)
	REGISTER_COMMAND_EX(iCommandCockpitDeviceCommandsEnd, 3999) //§Ü§à§ß§Ö§é§ß§Ñ§ñ §ä§à§é§Ü§Ñ  §Ü§à§Þ§Ñ§ß§Õ §Ü§à§Ü§á§Ú§ä§Ñ (§Ó§ã§ä§Ñ§Ó§Ý§ñ§ä§î §á§à§ã§Ý§Ö !!!!)
//----------------------------------------
REGISTER_COMMAND_EX(iCommandRepKeyBegin, 4000)		// §¯§Ñ§é§Ñ§Ý§î§ß§Ñ§ñ §ä§à§é§Ü§Ñ §Õ§Ý§ñ §â§Ñ§Õ§Ú§à §Ü§à§Þ§Ñ§ß§Õ 

#ifndef INPUT_LUA_BINDING
};
#endif

#endif

#ifdef INPUT_LUA_BINDING
#define _ACTIONS_H_
#endif