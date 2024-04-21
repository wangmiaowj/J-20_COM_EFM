// §£.§¢. 15.02.02 ////////////////////////////////////////////////////////////////////////
// §£ §ã§Ó§ñ§Ù§Ú §ã §ä§Ö§Þ, §é§ä§à §Ü§à§Õ§í §Ü§à§Þ§Ñ§ß§Õ §Ù§Ñ§á§Ú§ã§í§Ó§Ñ§ð§ä§ã§ñ §Ó §ä§â§Ö§Ü§Ú, §ï§ä§Ú §Ü§à§Õ§í §ß§Ö §Õ§à§Ý§Ø§ß§í §Ú§Ù§Þ§Ö§ß§ñ§ä§î§ã§ñ.
// §±§à§ï§ä§à§Þ§å §ß§Ö§Ý§î§Ù§ñ §Ú§Ù§Þ§Ö§ß§ñ§ä§î §á§à§â§ñ§Õ§à§Ü §ã§å§ë§Ö§ã§ä§Ó§å§ð§ë§Ú§ç §Ü§à§Þ§Ñ§ß§Õ, §å§Õ§Ñ§Ý§ñ§ä§î §ß§Ö§ß§å§Ø§ß§í§Ö §Ü§à§Þ§Ñ§ß§Õ§í §Ú§Ý§Ú
// §Õ§à§Ò§Ñ§Ó§Ý§ñ§ä§î §ß§à§Ó§í§Ö §Þ§Ö§Ø§Õ§å §ã§å§ë§Ö§ã§ä§Ó§å§ð§ë§Ú§Þ§Ú. §¯§à§Ó§í§Ö §Ü§à§Þ§Ñ§ß§Õ§í §â§Ñ§Ù§â§Ö§ê§Ñ§Ö§ä§ã§ñ §Ó§ã§ä§Ñ§Ó§Ý§ñ§ä§î §ä§à§Ý§î§Ü§à §Ó 
// §Ü§à§ß§Ö§è §Õ§Ñ§ß§ß§à§Ô§à §ã§á§Ú§ã§Ü§Ñ. §£§ã§Ý§Ö§Õ§ã§ä§Ó§Ú§Ö §ï§ä§à§Ô§à, §ß§Ö§Ý§î§Ù§ñ §ä§Ñ§Ü§Ø§Ö §Ü§à§Þ§Þ§Ö§ß§ä§Ú§â§à§Ó§Ñ§ä§î/§â§Ñ§ã§Ü§à§Þ§Þ§Ö§ß§ä§Ú§â§à§Ó§Ñ§ä§î
// §Ü§à§Þ§Ñ§ß§Õ§í §Ó §Õ§Ñ§ß§ß§à§Þ §ã§á§Ú§ã§Ü§Ö - §ß§å§Ø§ß§à §ß§Ñ§ç§à§Õ§Ú§ä§î §Õ§â§å§Ô§Ú§Ö §ã§á§à§ã§à§Ò§í §Ó§ß§Ö§ã§Ö§ß§Ú§ñ §Ú§Ù§Þ§Ö§ß§Ö§ß§Ú§Û, §ß§Ö
// §á§â§Ú§Ó§à§Õ§ñ§ë§Ú§Ö §Ü §ß§Ö§â§Ñ§Ò§à§ä§à§ã§á§à§ã§à§Ò§ß§à§ã§ä§Ú §ã§ä§Ñ§â§í§ç §ä§â§Ö§Ü§à§Ó. §¯§Ö§ß§å§Ø§ß§í§Ö §Ü§à§Þ§Ñ§ß§Õ§í §á§â§à§ã§ä§à §à§ä§Þ§Ö§é§Ñ§Û§ä§Ö
// §Ü§à§Þ§Þ§Ö§ß§ä§Ñ§â§Ú§Ö§Þ /* OBSOLETE */, §ã§Þ. §ß§Ú§Ø§Ö. §¯§à§Ó§í§Ö §Ü§à§Þ§Ñ§ß§Õ§í §Ó§ã§ä§Ñ§Ó§Ý§ñ§Û§ä§Ö §ß§Ö§á§à§ã§â§Ö§Õ§ã§ä§Ó§Ö§ß§ß§à
// §á§Ö§â§Ö§Õ iCommandMaximum.
// GSF. §´§Ñ§Ü§Ø§Ö §Ò§à§Ý§î§ê§Ñ§ñ §á§â§à§ã§î§Ò§Ñ §ã§Ú§ß§ç§â§à§ß§Ú§Ù§Ú§â§à§Ó§Ñ§ä§î §Ü§à§Þ§Ñ§ß§Õ§í §ã §æ§Ú§Ý§î§ä§â§Ñ§Þ§Ú §Ó ActionProcessor.
// isVideoAction() - §ã§á§Ú§ã§à§Ü §Ó§Ú§Õ§Ö§à-§Ü§à§Þ§Ñ§ß§Õ. isImportantAction() - §Ó§ã§á§à§Þ§à§Ô§Ñ§ä§Ö§Ý§î§ß§í§Ö.
/////////////////////////////////////////////////////////////////////////////////////////

#ifdef INPUT_LUA_BINDING
#undef _ICOMMAND_H_
#endif

#ifndef _ICOMMAND_H_
#define _ICOMMAND_H_

#ifndef INPUT_LUA_BINDING
#define REGISTER_COMMAND(cmd) cmd,
#define REGISTER_COMMAND_EX(cmd, value) cmd = value,
#endif

#ifndef INPUT_LUA_BINDING
enum iCommand
{
#endif

	REGISTER_COMMAND_EX(iCommandNull, 0)						// §¯§å§Ø§ß§à §Õ§Ý§ñ §á§Ö§â§Ö§Ò§à§â§Ñ §Ó§ã§Ö§ç §Ü§à§Þ§Ñ§ß§Õ

	/*OBSOLETE*/REGISTER_COMMAND(iCommandRotatePlus)						// §£§â§Ö§Þ§Ö§ß§ß§Ñ§ñ §Ü§à§Þ§Ñ§ß§Õ§Ñ
	/*OBSOLETE*/REGISTER_COMMAND(iCommandRotateMinus)					// §£§â§Ö§Þ§Ö§ß§ß§Ñ§ñ §Ü§à§Þ§Ñ§ß§Õ§Ñ
	/*OBSOLETE*/REGISTER_COMMAND(iCommandUpPilon)						// §£§â§Ö§Þ§Ö§ß§ß§Ñ§ñ §Ü§à§Þ§Ñ§ß§Õ§Ñ
	/*OBSOLETE*/REGISTER_COMMAND(iCommandDownPilon)						// §£§â§Ö§Þ§Ö§ß§ß§Ñ§ñ §Ü§à§Þ§Ñ§ß§Õ§Ñ
	/*OBSOLETE*/REGISTER_COMMAND(iCommandMissileFire)					// §£§â§Ö§Þ§Ö§ß§ß§Ñ§ñ §Ü§à§Þ§Ñ§ß§Õ§Ñ
	/*OBSOLETE*/REGISTER_COMMAND(iCommandGunFire)						// §£§â§Ö§Þ§Ö§ß§ß§Ñ§ñ §Ü§à§Þ§Ñ§ß§Õ§Ñ
	REGISTER_COMMAND(iCommandViewCockpit)					// §¬§Ñ§Þ§Ö§â§Ñ - §Ü§Ñ§Ò§Ú§ß§Ñ (Non-simulation Action)
	REGISTER_COMMAND(iCommandViewAir)						// §¬§Ñ§Þ§Ö§â§Ñ - §Ó§à§Ù§Õ§å§ê§ß§í§Ö §à§Ò§ì§Ö§Ü§ä§í (Non-simulation Action)
	REGISTER_COMMAND(iCommandViewTower)						// §¬§Ñ§Þ§Ö§â§Ñ - §Ò§Ñ§ê§ß§ñ (Non-simulation Action)
	REGISTER_COMMAND_EX(iCommandViewGround, 10)				// §¬§Ñ§Þ§Ö§â§Ñ - §ß§Ñ§Ù§Ö§Þ§ß§í§Ö §à§Ò§ì§Ö§Ü§ä§í (Non-simulation Action)
	REGISTER_COMMAND(iCommandViewMirage)						// §¬§Ñ§Þ§Ö§â§Ñ - §Þ§Ú§â§Ñ§Ø§Ú (Non-simulation Action)
	REGISTER_COMMAND(iCommandViewChase)						// §³§Ý§Ö§Õ§ñ§ë§Ñ§ñ §Ü§Ñ§Þ§Ö§â§Ñ (Non-simulation Action)
	REGISTER_COMMAND(iCommandViewNavy)						// §¬§Ñ§Þ§Ö§â§Ñ - §Þ§à§â§ã§Ü§Ú§Ö §à§Ò§ì§Ö§Ü§ä§í (Non-simulation Action)
	REGISTER_COMMAND(iCommandViewFight)						// §¬§Ñ§Þ§Ö§â§Ñ - §Ó§à§Ù§Õ§å§ê§ß§í§Û §Ò§à§Û (Non-simulation Action)
	REGISTER_COMMAND(iCommandViewAWACS)						// §¬§Ñ§Þ§Ö§â§Ñ - §Ü§à§Þ§Ñ§ß§Õ§ß§í§Û §á§å§ß§Ü§ä (§Ó§Ú§Õ §¡§£§¡§¬§³) (Non-simulation Action)
	REGISTER_COMMAND(iCommandViewFree)						// §³§Ó§à§Ò§à§Õ§ß§Ñ§ñ §Ü§Ñ§Þ§Ö§â§Ñ (Non-simulation Action)
	REGISTER_COMMAND(iCommandViewTempCockpitOn)				// §£§Ü§Ý§ð§é§Ö§ß§Ú§Ö §Ü§Ñ§Þ§Ö§â§í §Ó§â§Ö§Þ§Ö§ß§ß§à§Û §Ü§Ñ§Ò§Ú§ß§í (Non-simulation Action)
	REGISTER_COMMAND(iCommandViewTempCockpitOff)				// §£§í§Ü§Ý§ð§é§Ö§ß§Ú§Ö §Ü§Ñ§Þ§Ö§â§í §Ó§â§Ö§Þ§Ö§ß§ß§à§Û §Ü§Ñ§Ò§Ú§ß§í (Non-simulation Action)
	REGISTER_COMMAND(iCommandViewLock)						// §³§Ý§Ö§Ø§Ö§ß§Ú§Ö §Ù§Ñ §Ò§Ý§Ú§Ø§Ñ§Û§ê§Ú§Þ §à§Ò§ì§Ö§Ü§ä§à§Þ (Non-simulation Action)
	REGISTER_COMMAND_EX(iCommandViewUnlock, 20)				// §³§Ò§â§à§ã §ã§Ý§Ö§Ø§Ö§ß§Ú§ñ (Non-simulation Action)
	REGISTER_COMMAND(iCommandViewMe)							// §±§à§Ü§Ñ§Ù§Ñ§ä§î §ã§Ó§à§Û §ã§Ñ§Þ§à§Ý§Ö§ä (Non-simulation Action)
	REGISTER_COMMAND(iCommandViewPlus)						// §±§Ö§â§Ö§Ü§Ý§ð§é§Ñ§ä§Ö§Ý§î §â§Ö§Ø§Ú§Þ§Ñ "+" §Õ§Ý§ñ §ä§Ö§Ü§å§ë§Ö§Û §Ü§Ñ§Þ§Ö§â§í (Non-simulation Action)
	REGISTER_COMMAND(iCommandViewFriends)					// §²§Ö§Ø§Ú§Þ "§´§à§Ý§î§Ü§à §ã§Ó§à§Ú" (Non-simulation Action)
	REGISTER_COMMAND(iCommandViewEnemies)					// §²§Ö§Ø§Ú§Þ "§´§à§Ý§î§Ü§à §Ó§â§Ñ§Ô§Ú" (Non-simulation Action)
	/* OBSOLETE */REGISTER_COMMAND(iCommandViewNeutrals)					// §²§Ö§Ø§Ú§Þ "§¯§Ö§Û§ä§â§Ñ§Ý§î§ß§í§Ö" (Non-simulation Action)
	REGISTER_COMMAND(iCommandViewAll)						// §²§Ö§Ø§Ú§Þ "§£§ã§Ö" (Non-simulation Action)
	REGISTER_COMMAND(iCommandViewExplosion)					// §£§â§Ö§Þ§Ö§ß§ß§Ñ§ñ §Ü§à§Þ§Ñ§ß§Õ§Ñ §Õ§Ý§ñ §Õ§Ö§Þ§à§ß§ã§ä§â§Ñ§è§Ú§Ú §Ó§Ù§â§í§Ó§Ñ (Non-simulation Action)
	REGISTER_COMMAND(iCommandViewLeft)						// §±§à§Ó§à§â§à§ä §Ó§Ù§Ô§Ý§ñ§Õ§Ñ §ß§Ñ§Ý§Ö§Ó§à (Non-simulation Action)
	REGISTER_COMMAND(iCommandViewRight)						// §±§à§Ó§à§â§à§ä §Ó§Ù§Ô§Ý§ñ§Õ§Ñ §ß§Ñ§á§â§Ñ§Ó§à (Non-simulation Action)
	REGISTER_COMMAND_EX(iCommandViewUp, 30)					// §±§à§Ó§à§â§à§ä §Ó§Ù§Ô§Ý§ñ§Õ§Ñ §Ó§Ó§Ö§â§ç (Non-simulation Action)
	REGISTER_COMMAND(iCommandViewDown)						// §±§à§Ó§à§â§à§ä §Ó§Ù§Ô§Ý§ñ§Õ§Ñ §Ó§ß§Ú§Ù (Non-simulation Action)
	REGISTER_COMMAND(iCommandViewLeftSlow)					// §±§à§Ó§à§â§à§ä §Ó§Ù§Ô§Ý§ñ§Õ§Ñ §ß§Ñ§Ý§Ö§Ó§à §Þ§Ö§Õ§Ý§Ö§ß§ß§í§Û (Non-simulation Action)
	REGISTER_COMMAND(iCommandViewRightSlow)					// §±§à§Ó§à§â§à§ä §Ó§Ù§Ô§Ý§ñ§Õ§Ñ §ß§Ñ§á§â§Ñ§Ó§à §Þ§Ö§Õ§Ý§Ö§ß§ß§í§Û (Non-simulation Action)
	REGISTER_COMMAND(iCommandViewUpSlow)						// §±§à§Ó§à§â§à§ä §Ó§Ù§Ô§Ý§ñ§Õ§Ñ §Ó§Ó§Ö§â§ç §Þ§Ö§Õ§Ý§Ö§ß§ß§í§Û (Non-simulation Action)
	REGISTER_COMMAND(iCommandViewDownSlow)					// §±§à§Ó§à§â§à§ä §Ó§Ù§Ô§Ý§ñ§Õ§Ñ §Ó§ß§Ú§Ù §Þ§Ö§Õ§Ý§Ö§ß§ß§í§Û (Non-simulation Action)
	REGISTER_COMMAND(iCommandViewCenter)						// §¸§Ö§ß§ä§â§Ú§â§à§Ó§Ñ§ß§Ú§Ö §Ó§Ù§Ô§Ý§ñ§Õ§Ñ (Non-simulation Action)
	REGISTER_COMMAND(iCommandViewForward)					// §±§â§Ú§Ò§Ý§Ú§Ø§Ö§ß§Ú§Ö §Ü§Ñ§Þ§Ö§â§í (Non-simulation Action)
	REGISTER_COMMAND(iCommandViewBack)						// §µ§Õ§Ñ§Ý§Ö§ß§Ú§Ö §Ü§Ñ§Þ§Ö§â§í (Non-simulation Action)
	REGISTER_COMMAND(iCommandViewForwardSlow)				// §±§â§Ú§Ò§Ý§Ú§Ø§Ö§ß§Ú§Ö §Ü§Ñ§Þ§Ö§â§í §Þ§Ö§Õ§Ý§Ö§ß§ß§à§Ö (Non-simulation Action)
	REGISTER_COMMAND_EX(iCommandViewBackSlow, 40)				// §µ§Õ§Ñ§Ý§Ö§ß§Ú§Ö §Ü§Ñ§Þ§Ö§â§í §Þ§Ö§Õ§Ý§Ö§ß§ß§à§Ö (Non-simulation Action)
	REGISTER_COMMAND(iCommandViewCameraLeft)					// §±§à§Ó§à§â§à§ä §Ü§Ñ§Þ§Ö§â§í §ß§Ñ§Ý§Ö§Ó§à (Non-simulation Action)
	REGISTER_COMMAND(iCommandViewCameraRight)				// §±§à§Ó§à§â§à§ä §Ü§Ñ§Þ§Ö§â§í §ß§Ñ§á§â§Ñ§Ó§à (Non-simulation Action)
	REGISTER_COMMAND(iCommandViewCameraUp)					// §±§à§Ó§à§â§à§ä §Ü§Ñ§Þ§Ö§â§í §Ó§Ó§Ö§â§ç (Non-simulation Action)
	REGISTER_COMMAND(iCommandViewCameraDown)					// §±§à§Ó§à§â§à§ä §Ü§Ñ§Þ§Ö§â§í §Ó§ß§Ú§Ù (Non-simulation Action)
	REGISTER_COMMAND(iCommandViewCameraLeftSlow)				// §±§à§Ó§à§â§à§ä §Ü§Ñ§Þ§Ö§â§í §ß§Ñ§Ý§Ö§Ó§à §Þ§Ö§Õ§Ý§Ö§ß§ß§í§Û (Non-simulation Action)
	REGISTER_COMMAND(iCommandViewCameraRightSlow)			// §±§à§Ó§à§â§à§ä §Ü§Ñ§Þ§Ö§â§í §ß§Ñ§á§â§Ñ§Ó§à §Þ§Ö§Õ§Ý§Ö§ß§ß§í§Û (Non-simulation Action)
	REGISTER_COMMAND(iCommandViewCameraUpSlow)				// §±§à§Ó§à§â§à§ä §Ü§Ñ§Þ§Ö§â§í §Ó§Ó§Ö§â§ç §Þ§Ö§Õ§Ý§Ö§ß§ß§í§Û (Non-simulation Action)
	REGISTER_COMMAND(iCommandViewCameraDownSlow)				// §±§à§Ó§à§â§à§ä §Ü§Ñ§Þ§Ö§â§í §Ó§ß§Ú§Ù §Þ§Ö§Õ§Ý§Ö§ß§ß§í§Û (Non-simulation Action)
	REGISTER_COMMAND(iCommandViewCameraCenter)				// §¸§Ö§ß§ä§â§Ú§â§à§Ó§Ñ§ß§Ú§Ö §Ü§Ñ§Þ§Ö§â§í (Non-simulation Action)
	REGISTER_COMMAND_EX(iCommandFriendlyChat, 50)				// §³§Ö§ä§Ö§Ó§à§Û §¹§Ñ§ä §ä§à§Ý§î§Ü§à §ã§Ó§à§Ú§Þ (Administrative Action)
	REGISTER_COMMAND(iCommandQuit)							// §£§í§ç§à§Õ (Administrative Action)
	REGISTER_COMMAND(iCommandBrakeGo)						// §±§Ñ§å§Ù§Ñ/§á§å§ã§Ü §Ó§â§Ö§Þ§Ö§ß§Ú (§Ü§Ý§Ñ§Ó§Ú§ê§Ñ S) (Administrative Action)
	REGISTER_COMMAND(iCommandAccelerate)						// §µ§ã§Ü§à§â§Ö§ß§Ú§Ö §Ó§â§Ö§Þ§Ö§ß§Ú (Administrative Action) 
	REGISTER_COMMAND(iCommandOneFrame)						// §±§à§Ü§Ñ§Õ§â§à§Ó§à§Ö §Õ§Ó§Ú§Ø§Ö§ß§Ú§Ö §á§â§Ú §à§ã§ä§Ñ§ß§à§Ó§Ü§Ö §Ó§â§Ö§Þ§Ö§ß§Ú (Administrative Action)
	REGISTER_COMMAND(iCommandTrkEsc)							// §±§â§Ö§â§í§Ó§Ñ§ß§Ú§Ö §á§â§à§Ú§Ô§â§í§Ó§Ñ§ß§Ú§ñ §ä§â§Ö§Ü§Ñ (Administrative Action)
	/*OBSOLETE*/REGISTER_COMMAND(iCommandPlayerCntrl)		// §£§í§Ó§à§Õ §á§Ñ§ß§Ö§Ý§Ú §á§â§à§æ§Ú§Ý§Ú§â§à§Ó§Ñ§ß§Ú§ñ - temporary
	REGISTER_COMMAND(iCommandChat)							// §³§Ö§ä§Ö§Ó§à§Û §¹§Ñ§ä §Ó §â§Ö§Ø§Ú§Þ§Ö §Ó§ã§Ö§Þ
	REGISTER_COMMAND(iCommandPlaneSAUAutomatic)				// §³§ä§Ñ§Ò§Ú§Ý§Ú§Ù§Ñ§è§Ú§ñ §å§Ô§Ý§à§Ó
	REGISTER_COMMAND(iCommandPlaneSAUHBarometric)			// §³§ä§Ñ§Ò§Ú§Ý§Ú§Ù§Ñ§è§Ú§ñ §Ñ§Ò§ã§à§Ý§ð§ä§ß§à§Û §Ó§í§ã§à§ä§í
	REGISTER_COMMAND_EX(iCommandPlaneSAUHRadio, 60)			// §±§à§Ý§Ö§ä §ã §à§Ô§Ú§Ò§Ñ§ß§Ú§Ö§Þ §â§Ö§Ý§î§Ö§æ§Ñ
	REGISTER_COMMAND(iCommandPlaneSAUHorizon)				// §±§â§Ú§Ó§Ö§Õ§Ö§ß§Ú§Ö §Ü §Ô§à§â§Ú§Ù§à§ß§ä§å
	REGISTER_COMMAND(iCommandPlaneAutopilot)					// §¡§Ó§ä§à§á§Ú§Ý§à§ä
	REGISTER_COMMAND(iCommandPlaneAUTOnOff)					// §±§Ö§â§Ö§Ü§Ý§ð§é§Ö§ß§Ú§Ö §â§Ö§Ø§Ú§Þ§Ñ §¡§µ§´
	REGISTER_COMMAND(iCommandPlaneAUTIncrease)				// §µ§Ó§Ö§Ý§Ú§é§Ú§ä§î §Ù§Ñ§Õ§Ñ§ß§ß§å§ð §ã§Ü§à§â§à§ã§ä§î
	REGISTER_COMMAND(iCommandPlaneAUTDecrease)				// §µ§Þ§Ö§ß§î§ê§Ú§ä§î §Ù§Ñ§Õ§Ñ§ß§ß§å§ð §ã§Ü§à§â§à§ã§ä§î
	/* OBSOLETE */REGISTER_COMMAND(iCommandPlaneAUTIncreaseRegime)			// §±§Ö§â§Ö§Û§ä§Ú §ß§Ñ §Ò§à§Ý§Ö§Ö §Ó§í§ã§à§Ü§Ú§Û §â§Ö§Ø§Ú§Þ §ä§ñ§Ô§Ú
	/* OBSOLETE */REGISTER_COMMAND(iCommandPlaneAUTDecreaseRegime)			// §±§Ö§â§Ö§Û§ä§Ú §ß§Ñ §Ò§à§Ý§Ö§Ö §ß§Ú§Ù§Ü§Ú§Û §â§Ö§Ø§Ú§Þ §ä§ñ§Ô§Ú
	REGISTER_COMMAND(iCommandPlaneGear)						// §º§Ñ§ã§ã§Ú
	REGISTER_COMMAND(iCommandPlaneHook)						// §¤§Ñ§Ü
	REGISTER_COMMAND_EX(iCommandPlanePackWing, 70)				// §³§Ü§Ý§Ñ§Õ§í§Ó§Ñ§ß§Ú§Ö §Ü§â§í§Ý§î§Ö§Ó
	REGISTER_COMMAND(iCommandPlaneFonar)						// §¶§à§ß§Ñ§â§î
	REGISTER_COMMAND(iCommandPlaneFlaps)						// §©§Ñ§Ü§â§í§Ý§Ü§Ú
	REGISTER_COMMAND(iCommandPlaneAirBrake)					// §£§à§Ù§Õ§å§ê§ß§í§Û §ä§à§â§Þ§à§Ù
	REGISTER_COMMAND(iCommandPlaneWheelBrakeOn)				// §£§Ü§Ý§ð§é§Ö§ß§Ú§Ö §ä§à§â§Þ§à§Ù§Ñ §Ü§à§Ý§Ö§ã
	REGISTER_COMMAND(iCommandPlaneWheelBrakeOff)				// §£§í§Ü§Ý§ð§é§Ö§ß§Ú§Ö §ä§à§â§Þ§à§Ù§Ñ §Ü§à§Ý§Ö§ã
	REGISTER_COMMAND(iCommandPlaneParachute)					// §±§Ñ§â§Ñ§ê§ð§ä
	REGISTER_COMMAND(iCommandPlaneDropSnar)					// §³§Ò§â§à§ã §Ý§à§Ó§å§ê§Ö§Ü
	REGISTER_COMMAND(iCommandPlaneWingtipSmokeOnOff)			// §£§Ü§Ý/§Ó§í§Ü§Ý §Õ§í§Þ§à§Ó§í§ç §ê§Ñ§ê§Ö§Ü §ß§Ñ §Ü§à§ß§è§Ñ§ç §Ü§â§í§Ý§î§Ö§Ó
	REGISTER_COMMAND(iCommandPlaneFuelOn)					// §£§Ü§Ý§ð§é§Ö§ß§Ú§Ö §ã§Ý§Ú§Ó§Ñ §ä§à§á§Ý§Ú§Ó§Ñ §Ú§Ý§Ú §Ù§Ñ§á§â§Ñ§Ó§Ü§Ú
	REGISTER_COMMAND_EX(iCommandPlaneFuelOff, 80)				// §£§í§Ü§Ý§ð§é§Ö§ß§Ú§Ö §ã§Ý§Ú§Ó§Ñ §ä§à§á§Ý§Ú§Ó§Ñ §Ú§Ý§Ú §Ù§Ñ§á§â§Ñ§Ó§Ü§Ú
	REGISTER_COMMAND(iCommandPlaneSalvoOnOff)				// §©§Ñ§Ý§á§à§Ó§í§Û §â§Ö§Ø§Ú§Þ §Ó§Ü§Ý/§Ó§í§Ü§Ý
	REGISTER_COMMAND(iCommandPlaneJettisonWeapons)			// §³§Ò§â§à§ã §à§â§å§Ø§Ú§ñ §á§Ñ§â§Ñ§Þ§Ú
	REGISTER_COMMAND(iCommandPlaneEject)						// §¬§Ñ§ä§Ñ§á§å§Ý§î§ä§Ú§â§à§Ó§Ñ§ß§Ú§Ö
	REGISTER_COMMAND(iCommandPlaneFire)						// §¤§Ñ§ê§Ö§ä§Ü§Ñ
	REGISTER_COMMAND(iCommandPlaneFireOff)					// §¤§Ñ§ê§Ö§ä§Ü§å §à§ä§á§å§ã§ä§Ú§Ý§Ú
	REGISTER_COMMAND(iCommandPlaneRadarOnOff)				// §£§Ü§Ý§ð§é§Ö§ß§Ú§Ö / §Ó§í§Ü§Ý§ð§é§Ö§ß§Ú§Ö §â§Ñ§Õ§Ñ§â§Ñ
	REGISTER_COMMAND(iCommandPlaneEOSOnOff)					// §£§Ü§Ý§ð§é§Ö§ß§Ú§Ö / §Ó§í§Ü§Ý§ð§é§Ö§ß§Ú§Ö §°§­§³
	REGISTER_COMMAND(iCommandPlaneRadarLeft)					// §±§à§Ó§à§â§à§ä §Ñ§ß§ä§Ö§ß§ß§í §²§­§³ §Ó§Ý§Ö§Ó§à
	REGISTER_COMMAND(iCommandPlaneRadarRight)				// §±§à§Ó§à§â§à§ä §Ñ§ß§ä§Ö§ß§ß§í §²§­§³ §Ó§á§â§Ñ§Ó§à
	REGISTER_COMMAND_EX(iCommandPlaneRadarUp, 90)				// §±§à§Ó§à§â§à§ä §Ñ§ß§ä§Ö§ß§ß§í §²§­§³ §Ó§Ó§Ö§â§ç
	REGISTER_COMMAND(iCommandPlaneRadarDown)					// §±§à§Ó§à§â§à§ä §Ñ§ß§ä§Ö§ß§ß§í §²§­§³ §Ó§ß§Ú§Ù
	REGISTER_COMMAND(iCommandPlaneRadarCenter)				// §£§à§Ù§Ó§â§Ñ§ä §Ñ§ß§ä§Ö§ß§ß§í §²§­§³ §Ó §è§Ö§ß§ä§â
	REGISTER_COMMAND(iCommandPlaneTrimLeft)					// §´§â§Ú§Þ§Þ§Ö§â §Ó§Ý§Ö§Ó§à
	REGISTER_COMMAND(iCommandPlaneTrimRight)					// §´§â§Ú§Þ§Þ§Ö§â §Ó§á§â§Ñ§Ó§à
	REGISTER_COMMAND(iCommandPlaneTrimUp)					// §´§â§Ú§Þ§Þ§Ö§â §Ó§Ó§Ö§â§ç
	REGISTER_COMMAND(iCommandPlaneTrimDown)					// §´§â§Ú§Þ§Þ§Ö§â §Ó§ß§Ú§Ù
	REGISTER_COMMAND(iCommandPlaneTrimCancel)				// §³§Ò§â§à§ã §ä§â§Ú§Þ§Þ§Ö§â§Ñ
	REGISTER_COMMAND(iCommandPlaneTrimLeftRudder)			// §´§â§Ú§Þ§Þ§Ö§â §Ý§Ö§Ó§à§Û §á§Ö§Õ§Ñ§Ý§Ú
	REGISTER_COMMAND(iCommandPlaneTrimRightRudder)			// §´§â§Ú§Þ§Þ§Ö§â §á§â§Ñ§Ó§à§Û §á§Ö§Õ§Ñ§Ý§Ú
	REGISTER_COMMAND_EX(iCommandPlaneChangeLock, 100)			// §±§Ö§â§Ö§Ü§Ý§ð§é§Ö§ß§Ú§Ö §á§à§Õ§â§Ö§Ø§Ú§Þ§à§Ó / §Ù§Ñ§ç§Ó§Ñ§ä
	REGISTER_COMMAND(iCommandPlaneChangeWeapon)				// §±§Ö§â§Ö§Ü§Ý§ð§é§Ö§ß§Ú§Ö §á§à§Õ§â§Ö§Ø§Ú§Þ§à§Ó / §á§Ö§â§Ö§Ò§à§â §à§â§å§Ø§Ú§ñ
	REGISTER_COMMAND(iCommandPlaneChangeTarget)				// §±§Ö§â§Ö§Ò§à§â §è§Ö§Ý§Ö§Û
	REGISTER_COMMAND(iCommandPlaneZoomIn)					// §ª§Ù§Þ§Ö§ß§Ö§ß§Ú§Ö §Þ§Ñ§ã§ê§ä§Ñ§Ò§Ñ §®§¶§¥ +
	REGISTER_COMMAND(iCommandPlaneZoomOut)					// §ª§Ù§Þ§Ö§ß§Ö§ß§Ú§Ö §Þ§Ñ§ã§ê§ä§Ñ§Ò§Ñ §®§¶§¥ -
	REGISTER_COMMAND(iCommandPlaneModeNAV)					// §±§Ö§â§Ö§ç§à§Õ §Ó §â§Ö§Ø§Ú§Þ §ß§Ñ§Ó§Ú§Ô§Ñ§è§Ú§Ú
	REGISTER_COMMAND(iCommandPlaneModeBVR)					// §±§Ö§â§Ö§ç§à§Õ §Ó §â§Ö§Ø§Ú§Þ §Õ§Ñ§Ý§î§ß§Ö§Ô§à §Ó§à§Ù§Õ§å§ê§ß§à§Ô§à §Ò§à§ñ
	REGISTER_COMMAND(iCommandPlaneModeVS)					// §±§Ö§â§Ö§ç§à§Õ §Ó §â§Ö§Ø§Ú§Þ §Ò§Ý§Ú§Ø§ß§Ö§Ô§à §Ó§à§Ù§Õ§å§ê§ß§à§Ô§à §Ò§à§ñ (§á§à§Ý§à§ã§Ñ)
	REGISTER_COMMAND(iCommandPlaneModeBore)					// §±§Ö§â§Ö§ç§à§Õ §Ó §â§Ö§Ø§Ú§Þ §Ò§Ý§Ú§Ø§ß§Ö§Ô§à §Ó§à§Ù§Õ§å§ê§ß§à§Ô§à §Ò§à§ñ (§Ü§à§Ý§î§è§à)
	REGISTER_COMMAND(iCommandPlaneModeHelmet)				// §±§Ö§â§Ö§ç§à§Õ §Ó §â§Ö§Ø§Ú§Þ §Ò§Ý§Ú§Ø§ß§Ö§Ô§à §Ó§à§Ù§Õ§å§ê§ß§à§Ô§à §Ò§à§ñ (§ê§Ý§Ö§Þ)
	REGISTER_COMMAND_EX(iCommandPlaneModeFI0, 110)				// §±§Ö§â§Ö§ç§à§Õ §Ó §â§Ö§Ø§Ú§Þ FI0
	REGISTER_COMMAND(iCommandPlaneModeGround)				// §±§Ö§â§Ö§ç§à§Õ §Ó §â§Ö§Ø§Ú§Þ §Ñ§ä§Ñ§Ü§Ú §ß§Ñ§Ù§Ö§Þ§ß§í§ç §è§Ö§Ý§Ö§Û
	REGISTER_COMMAND(iCommandPlaneModeGrid)					// §±§Ö§â§Ö§ç§à§Õ §Ó §â§Ö§Ø§Ú§Þ "§ã§Ö§ä§Ü§Ñ"
	REGISTER_COMMAND(iCommandPlaneModeCannon)				// §£§Ü§Ý§ð§é§Ö§ß§Ú§Ö/§Ó§í§Ü§Ý§ð§é§Ö§ß§Ú§Ö §á§å§ê§Ü§Ú
	REGISTER_COMMAND(iCommandPlaneDoAndHome)					// §£§í§á§à§Ý§ß§Ú §Ù§Ñ§Õ§Ñ§ß§Ú§Ö §Ú §Ó§Ö§â§ß§Ú§ã§î §ß§Ñ §Ò§Ñ§Ù§å
	REGISTER_COMMAND(iCommandPlaneDoAndBack)					// §£§í§á§à§Ý§ß§Ú §Ù§Ñ§Õ§Ñ§ß§Ú§Ö §Ú §Ó§Ö§â§ß§Ú§ã§î §Ü§à §Þ§ß§Ö
	REGISTER_COMMAND(iCommandPlaneFormation)					// §ª§Õ§ä§Ú §â§Ñ§ã§ã§Ö§ñ§ß§ß§í§Þ/§á§Ý§à§ä§ß§í§Þ §ã§ä§â§à§Ö§Þ
	REGISTER_COMMAND(iCommandPlaneJoinUp)					// §³§à§Ò§â§Ñ§ä§î§ã§ñ
	REGISTER_COMMAND(iCommandPlaneAttackMyTarget)			// §¡§ä§Ñ§Ü§å§Û §Þ§à§ð §è§Ö§Ý§î
	REGISTER_COMMAND(iCommandPlaneCoverMySix)				// §±§â§Ú§Ü§â§à§Û §Þ§Ö§ß§ñ §ã§Ù§Ñ§Õ§Ú
	REGISTER_COMMAND_EX(iCommandPlaneShipTakeOff, 120)			// §·§à§é§å §Ó§Ù§Ý§Ö§ä§Ö§ä§î §ã §Ñ§Ó§Ú§Ñ§ß§à§ã§è§Ñ
	REGISTER_COMMAND(iCommandPlaneCobra)						// §®§Ñ§ß§Ö§Ó§â §¬§à§Ò§â§Ñ
	REGISTER_COMMAND(iCommandSoundOnOff)                     // §£§í§Ü§Ý§ð§é§Ú§ä§î/§Ó§Ü§Ý§ð§é§Ú§ä§î §Ù§Ó§å§Ü (Administrative Action)
	REGISTER_COMMAND(iCommandSoundMicOn)						// §£§Ü§Ý§ð§é§Ú§ä§î §á§â§Ú§Ö§Þ §Ù§Ó§å§Ü§Ñ §ã §Þ§Ú§Ü§â§à§æ§à§ß§Ñ (Administrative Action)
	REGISTER_COMMAND(iCommandSoundMicOff)					// §°§ä§Ü§Ý§ð§é§Ú§ä§î §á§â§Ú§Ö§Þ §Ù§Ó§å§Ü§Ñ §ã §Þ§Ú§Ü§â§à§æ§à§ß§Ñ (Administrative Action)
	REGISTER_COMMAND(iCommandViewRightMirrorOn)				// §£§Ù§Ô§Ý§ñ§Õ §ß§Ñ §Ù§Ö§â§Ü§Ñ§Ý§Ñ (Non-simulation Action)
	REGISTER_COMMAND(iCommandViewRightMirrorOff)				// (Non-simulation Action)	
	REGISTER_COMMAND(iCommandViewLeftMirrorOn)				// (Non-simulation Action)			
	REGISTER_COMMAND(iCommandViewLeftMirrorOff)	// (Non-simulation Action)

	REGISTER_COMMAND(iCommandNaturalViewCockpitIn)			// §¬§Ñ§Þ§Ö§â§Ñ - §Ü§Ñ§Ò§Ú§ß§Ñ (§Ö§ã§ä§Ö§ã§ä§Ó§Ö§ß§ß§í§Û §Ó§Ù§Ô§Ý§ñ§Õ) (Non-simulation Action)
	/* OBSOLETE */	REGISTER_COMMAND_EX(iCommandNaturalViewCockpitOut, 130)	// §¬§Ñ§Þ§Ö§â§Ñ §Ù§Ñ §Ü§Ñ§Ò§Ú§ß§à§Û (§Ö§ã§ä§Ö§ã§ä§Ó§Ö§ß§ß§í§Û §Ó§Ù§Ô§Ý§ñ§Õ)
	REGISTER_COMMAND(iCommandViewLndgOfficer)				// §â§å§Ü§à§Ó§à§Õ§Ú§ä§Ö§Ý§î §á§à§Ý§Ö§ä§Ñ§Þ§Ú §ß§Ñ §Ñ§Ó§Ú§Ñ§ß§à§ã§è§Ö
	/* OBSOLETE */	REGISTER_COMMAND(iCommandViewCaptainBridge)				// §Ü§Ñ§á§Ú§ä§Ñ§ß§ã§Ü§Ú§Û §Þ§à§ã§ä§Ú§Ü §ß§Ñ §Ñ§Ó§Ú§Ñ§ß§à§ã§è§Ö
	/* OBSOLETE */	REGISTER_COMMAND(iCommandViewGroundAndPlane)				// §ß§Ñ§Ù§Ö§Þ§ß§í§Û §à§Ò§ì§Ö§Ü§ä + §Ó§Ñ§ê §ã§Ñ§Þ§à§Ý§Ö§ä
	/* OBSOLETE */	REGISTER_COMMAND(iCommandViewPlaneAndGround) 			// §Ó§Ñ§ê §ã§Ñ§Þ§à§Ý§Ö§ä + §ß§Ñ§Ù§Ö§Þ§ß§í§Û §à§Ò§ì§Ö§Ü§ä
	REGISTER_COMMAND(iCommandViewWeaponAndTarget)			// §â§Ñ§Ü§Ö§äa §Ú §è§Ö§Ý§î (Non-simulation Action)
	REGISTER_COMMAND(iCommandActiveJamming)
	REGISTER_COMMAND(iCommandLandDetailsIncrease)			// §°§ä§Ý§Ñ§Õ§à§é§ß§à§Ö §å§Ó§Ö§Ý§Ú§é§Ö§ß§Ú§Ö §Õ§Ö§ä§Ñ§Ý§Ú§Ù§Ñ§è§Ú§Ú (Non-simulation Action)
	REGISTER_COMMAND(iCommandLandDetailsDecrease)			// §°§ä§Ý§Ñ§Õ§à§é§ß§à§Ö §å§Þ§Ö§ß§î§ê§Ö§ß§Ú§Ö §Õ§Ö§ä§Ñ§Ý§Ú§Ù§Ñ§è§Ú§Ú (Non-simulation Action)
	REGISTER_COMMAND(iCommandSelecterLeft)				    // §Õ§Ó§Ú§Ø§Ö§ß§Ú§Ö §Þ§Ñ§â§Ü§Ö§â§Ñ §Ù§Ñ§ç§Ó§Ñ§ä§Ñ §è§Ö§Ý§Ö§Û §ß§Ñ HUD §Ó§Ý§Ö§Ó§à
	REGISTER_COMMAND_EX(iCommandSelecterRight, 140)			// §Ó§á§â§Ñ§Ó§à
	REGISTER_COMMAND(iCommandSelecterUp)					    // §Ó§Ó§Ö§â§ç
	REGISTER_COMMAND(iCommandSelecterDown)					// §Ó§ß§Ú§Ù
	REGISTER_COMMAND(iCommandRefusalTWS)						// §à§ä§Ü§Ñ§Ù §à§ä §³§¯§±
	REGISTER_COMMAND(iCommandPlaneResetMasterWarning)
	REGISTER_COMMAND(iCommandPlaneFlapsOn)
	REGISTER_COMMAND(iCommandPlaneFlapsOff)
	REGISTER_COMMAND(iCommandPlaneAirBrakeOn)
	REGISTER_COMMAND(iCommandPlaneAirBrakeOff)
	REGISTER_COMMAND(iCommandViewWeapons)				// §¬§Ñ§Þ§Ö§â§Ñ §Ó§à§à§â§å§Ø§Ö§ß§Ú§Û (Non-simulation Action)
	REGISTER_COMMAND_EX(iCommandViewStatic, 150)			// §¬§Ñ§Þ§Ö§â§Ñ §ã§ä§Ñ§ä§Ú§é§Ö§ã§Ü§Ú§ç §à§Ò§ì§Ö§Ü§ä§à§Ó (Non-simulation Action)
	REGISTER_COMMAND(iCommandViewTargets)				// §¬§Ñ§Þ§Ö§â§Ñ §è§Ö§Ý§Ö§Û
	REGISTER_COMMAND(iCommandInfoOnOff)					// §±§Ö§â§Ö§Ü§Ý§ð§é§Ñ§ä§Ö§Ý§î §Ú§ß§æ§à§â§Þ§Ñ§è§Ú§à§ß§ß§í§ç §ã§ä§â§à§Ü§Ú (Non-simulation Action)
	/* OBSOLETE */REGISTER_COMMAND(iCommandInfoTextOnOff)				// §£§Ü§Ý§ð§é§Ú§ä§î/§Ó§í§Ü§Ý§ð§é§Ú§ä§î §Ó§Ö§â§ç§ß§ð§ð §Ú§ß§æ§à§â§Þ§Ñ§è§Ú§à§ß§ß§å§ð §ã§ä§â§à§Ü§å (Non-simulation Action)
	/* OBSOLETE */REGISTER_COMMAND(iCommandInfoDataOnOff)				// §£§Ü§Ý§ð§é§Ú§ä§î/§Ó§í§Ü§Ý§ð§é§Ú§ä§î §ß§Ú§Ø§ß§ð§ð §Ú§ß§æ§à§â§Þ§Ñ§è§Ú§à§ß§ß§å§ð §ã§ä§â§à§Ü§Ú (Non-simulation Action)
	REGISTER_COMMAND(iCommandPlaneAirRefuel)				// §±§Ö§â§Ö§Ü§Ý§ð§é§Ñ§ä§Ö§Ý§î §á§à§Ý§à§Ø§Ö§ß§Ú§ñ §ê§ä§Ñ§ß§Ô§Ú §Ù§Ñ§á§â§Ñ§Ó§Ü§Ú
	REGISTER_COMMAND(iCommandBrightnessILS)				// §Á§â§Ü§à§ã§ä§î ILS
	/* OBSOLETE */REGISTER_COMMAND(iCommandGraphicsFrameRate)			// §±§Ö§â§Ö§Ü§Ý§ð§é§Ñ§ä§Ö§Ý§î §Ó§í§Ó§à§Õ§Ñ §é§Ñ§ã§ä§à§ä§í §Ü§Ñ§Õ§â§à§Ó (Administrative Action)
	REGISTER_COMMAND(iCommandViewFreeJump)				// §±§Ö§â§Ö§Ü§Ý§ð§é§Ö§ß§Ú§Ö §ß§Ñ §ã§Ó§à§Ò§à§Õ§ß§å§ð §Ü§Ñ§Þ§Ö§â§å §Ó §ä§Ö§Ü§å§ë§Ö§Û §á§à§Ù§Ú§è§Ú§Ú (Non-simulation Action)
	REGISTER_COMMAND(iCommandViewSpeedUp)				// §²§Ñ§Ù§à§Ô§ß§Ñ§ä§î §ã§Ó§à§Ò§à§Õ§ß§å§ð §Ü§Ñ§Þ§Ö§â§å (§á§à§Ý§à§Ø§Ú§ä§Ö§Ý§î§ß§à§Ö §å§ã§Ü§à§â§Ö§ß§Ú§Ö) (Non-simulation Action)
	REGISTER_COMMAND_EX(iCommandViewSlowDown, 160)			// §©§Ñ§Þ§Ö§Õ§Ý§Ú§ä§î §ã§Ó§à§Ò§à§Õ§ß§å§ð §Ü§Ñ§Þ§Ö§â§å (§à§ä§â§Ú§è§Ñ§ä§Ö§Ý§î§ß§à§Ö §å§ã§Ü§à§â§Ö§ß§Ú§Ö) (Non-simulation Action)
	REGISTER_COMMAND(iCommandPlaneAUTIncreaseLeft)
	REGISTER_COMMAND(iCommandPlaneAUTDecreaseLeft)
	REGISTER_COMMAND(iCommandPlaneAUTIncreaseRight)
	REGISTER_COMMAND(iCommandPlaneAUTDecreaseRight)
	/* OBSOLETE */REGISTER_COMMAND(iCommandPlaneAUTIncreaseRegimeLeft)
	/* OBSOLETE */REGISTER_COMMAND(iCommandPlaneAUTDecreaseRegimeLeft)
	/* OBSOLETE */REGISTER_COMMAND(iCommandPlaneAUTIncreaseRegimeRight)
	/* OBSOLETE */REGISTER_COMMAND(iCommandPlaneAUTDecreaseRegimeRight)
	REGISTER_COMMAND(iCommandPlaneImmortal)				// §±§Ö§â§Ö§Ü§Ý§ð§é§Ñ§ä§Ö§Ý§î §Ò§Ö§ã§ã§Þ§Ö§â§ä§Ú§ñ §ã§Ó§à§Ö§Ô§à §ã§Ñ§Þ§à§Ý§Ö§ä§Ñ
	REGISTER_COMMAND_EX(iCommandPlaneJettisonFuelTanksUp, 170)
	REGISTER_COMMAND(iCommandPlaneJettisonWeaponsUp)
	/* OBSOLETE */REGISTER_COMMAND(iCommandPlaneAUTUnlockLeft)
	/* OBSOLETE */REGISTER_COMMAND(iCommandPlaneAUTUnlockRight)
	/* OBSOLETE */REGISTER_COMMAND(iCommandPlaneTrimViewOnOff)			// §£§Ü§Ý/§Ó§í§Ü§Ý §Ú§ß§Õ§Ú§Ü§Ñ§è§Ú§Ú §ä§â§Ú§Þ§Þ§Ö§â§Ñ §ß§Ñ §ª§­§³§Ö				
	REGISTER_COMMAND(iCommandPlaneLightsOnOff)			// §£§Ü§Ý/§Ó§í§Ü§Ý §à§Ô§ß§Ú §ß§Ñ §ã§Ó§à§Ö§Þ §ã§Ñ§Þ§à§Ý§Ö§ä§Ö
	REGISTER_COMMAND(iCommandPlaneDropSnarOnce)			// §°§Õ§ß§à§Ü§â§Ñ§ä§ß§í§Û §ã§Ò§â§à§ã §Ý§à§Ó§å§ê§Ö§Ü
	REGISTER_COMMAND(iCommandViewAngleDefault)			// §µ§ã§ä§Ñ§ß§à§Ó§Ú§ä§î §å§Þ§Ñ§Ý§é§Ú§Ó§Ñ§Ö§Þ§í§Û §å§Ô§à§Ý §à§Ò§Ù§à§â§Ñ §Ü§Ñ§Þ§Ö§â§í (Non-simulation Action)
	REGISTER_COMMAND(iCommandPlaneJettisonFuelTanks)		// §³§Ò§â§à§ã §ä§à§á§Ý§Ú§Ó§ß§í§ç §Ò§Ñ§Ü§à§Ó
	REGISTER_COMMAND(iCommandToggleCommandMenu)		// §£§í§Ù§à§Ó §á§Ñ§ß§Ö§Ý§Ú §Ü§à§Þ§Ñ§ß§Õ §Ó§Ö§Õ§à§Þ§í§Þ
	REGISTER_COMMAND_EX(iCommandViewSwitchReverse, 180)	// §°§Ò§â§Ñ§ä§ß§à§Ö §ß§Ñ§á§â§Ñ§Ó§Ý§Ö§ß§Ú§Ö §á§Ö§â§Ö§Ü§Ý§ð§é§Ö§ß§Ú§ñ §à§Ò§ì§Ö§Ü§ä§à§Ó (Non-simulation Action)
	REGISTER_COMMAND(iCommandViewSwitchForward)			// §±§â§ñ§Þ§à§Ö §ß§Ñ§á§â§Ñ§Ó§Ý§Ö§ß§Ú§Ö §á§Ö§â§Ö§Ü§Ý§ð§é§Ö§ß§Ú§ñ §à§Ò§ì§Ö§Ü§ä§à§Ó (Non-simulation Action)
	REGISTER_COMMAND(iCommandViewObjectIgnore)			// §ª§Ô§ß§à§â§Ú§â§à§Ó§Ñ§ä§î §à§Ò§ì§Ö§Ü§ä §á§â§Ú §á§Ö§â§Ö§Ü§Ý§ð§é§Ö§ß§Ú§ñ§ç §ß§Ñ §ß§Ö§Ô§à (Non-simulation Action)
	REGISTER_COMMAND(iCommandViewObjectsAll)				// §°§é§Ú§ã§ä§Ú§ä§î §ã§á§Ú§ã§à§Ü §Ú§Ô§ß§à§â§Ú§â§å§Ö§Þ§í§ç §à§Ò§ì§Ö§Ü§ä§à§Ó (Non-simulation Action)
	REGISTER_COMMAND(iCommandViewTerrainLock)			// §©§Ñ§ç§Ó§Ñ§ä §ä§à§é§Ü§Ú §ß§Ñ §á§à§Ó§Ö§â§ç§ß§à§ã§ä§Ú §Ù§Ö§Þ§Ý§Ú (Non-simulation Action)
	REGISTER_COMMAND(iCommandViewFromTo)					// §±§Ö§â§Ö§Ü§Ý§ð§é§Ñ§ä§Ö§Ý§î §ß§Ñ§á§â§Ñ§Ó§Ý§Ö§ß§Ú§ñ §Ü§Ñ§Þ§Ö§â§í (§à§ä §à§Ò§ì§Ö§Ü§ä§Ñ/§ß§Ñ §à§Ò§ì§Ö§Ü§ä) (Non-simulation Action)
	REGISTER_COMMAND(iCommandPlaneDown)					// §´§à§ß§Ü§à§Ö §å§á§â§Ñ§Ó§Ý§Ö§ß§Ú§Ö §Ñ§Ó§ä§à§á§Ú§Ý§à§ä§à§Þ §á§à §Ó§í§ã§à§ä§Ö
	REGISTER_COMMAND(iCommandPlaneUp)
	REGISTER_COMMAND(iCommandPlaneLeft)
	REGISTER_COMMAND(iCommandPlaneRight)
	REGISTER_COMMAND_EX(iCommandViewLocal, 190)			// §­§à§Ü§Ñ§Ý§î§ß§í§Ö §á§à§Ó§à§â§à§ä§í §Ü§Ñ§Þ§Ö§â§í
	REGISTER_COMMAND(iCommandDecelerate)					// §©§Ñ§Þ§Ö§Õ§Ý§Ö§ß§Ú§Ö §Þ§à§Õ§Ö§Ý§î§ß§à§Ô§à §Ó§â§Ö§Þ§Ö§ß§Ú (Administrative Action)
	REGISTER_COMMAND(iCommandPlaneJump)      			// §±§Ö§â§Ö§ã§Ü§Ñ§Ü§Ú§Ó§Ñ§ß§Ú§Ö §Ó §ä§Ö§Ü§å§ë§Ú§Û §ã§Ñ§Þ§à§Ý§Ö§ä
	REGISTER_COMMAND(iCommandPlaneUpStart)
	REGISTER_COMMAND(iCommandPlaneUpStop)
	REGISTER_COMMAND(iCommandPlaneDownStart)
	REGISTER_COMMAND(iCommandPlaneDownStop)
	REGISTER_COMMAND(iCommandPlaneLeftStart)
	REGISTER_COMMAND(iCommandPlaneLeftStop)
	REGISTER_COMMAND(iCommandPlaneRightStart)
	REGISTER_COMMAND_EX(iCommandPlaneRightStop, 200)
	REGISTER_COMMAND(iCommandPlaneLeftRudderStart)
	REGISTER_COMMAND(iCommandPlaneLeftRudderStop)
	REGISTER_COMMAND(iCommandPlaneRightRudderStart)
	REGISTER_COMMAND(iCommandPlaneRightRudderStop)
	REGISTER_COMMAND(iCommandViewUpRight)						// (Non-simulation Action)
	REGISTER_COMMAND(iCommandViewDownRight)						// (Non-simulation Action)
	REGISTER_COMMAND(iCommandViewDownLeft)						// (Non-simulation Action)
	REGISTER_COMMAND(iCommandViewUpLeft)							// (Non-simulation Action)
	REGISTER_COMMAND(iCommandViewStop)							// §±§â§Ö§Ü§â§Ñ§ä§Ú§ä§î §Õ§Ó§Ú§Ø§Ö§ß§Ú§Ö §Ü§Ñ§Þ§Ö§â§í (Non-simulation Action) 
	REGISTER_COMMAND_EX(iCommandViewUpRightSlow, 210)				// (Non-simulation Action)
	REGISTER_COMMAND(iCommandViewDownRightSlow)					// (Non-simulation Action)
	REGISTER_COMMAND(iCommandViewDownLeftSlow)					// (Non-simulation Action)
	REGISTER_COMMAND(iCommandViewUpLeftSlow)						// (Non-simulation Action)
	REGISTER_COMMAND(iCommandViewStopSlow)						// (Non-simulation Action) 
	REGISTER_COMMAND(iCommandPlaneTrimStop)
	/* OBSOLETE */   REGISTER_COMMAND(iCommandPointOfViewUp)
	/* OBSOLETE */   REGISTER_COMMAND(iCommandPointOfViewUpRight)
	/* OBSOLETE */   REGISTER_COMMAND(iCommandPointOfViewRight)
	/* OBSOLETE */   REGISTER_COMMAND(iCommandPointOfViewDownRight)
	/* OBSOLETE */    REGISTER_COMMAND_EX(iCommandPointOfViewDown, 220)
	/* OBSOLETE */   REGISTER_COMMAND(iCommandPointOfViewDownLeft)
	/* OBSOLETE */   REGISTER_COMMAND(iCommandPointOfViewLeft)
	/* OBSOLETE */   REGISTER_COMMAND(iCommandPointOfViewUpLeft)
	/* OBSOLETE */   REGISTER_COMMAND(iCommandPointOfViewCenter)
	/* OBSOLETE */   REGISTER_COMMAND(iCommandPointOfViewStop)
	REGISTER_COMMAND(iCommandSelecterUpRight)
	REGISTER_COMMAND(iCommandSelecterDownRight)
	REGISTER_COMMAND(iCommandSelecterDownLeft)
	REGISTER_COMMAND(iCommandSelecterUpLeft)
	REGISTER_COMMAND_EX(iCommandSelecterStop, 230)
	REGISTER_COMMAND(iCommandPlaneRadarUpRight)
	REGISTER_COMMAND(iCommandPlaneRadarDownRight)
	REGISTER_COMMAND(iCommandPlaneRadarDownLeft)
	REGISTER_COMMAND(iCommandPlaneRadarUpLeft)
	REGISTER_COMMAND(iCommandPlaneRadarStop)
	REGISTER_COMMAND(iCommandViewSaveAngles)				// ??? (Non-simulation Action)
	REGISTER_COMMAND(iCommandViewTempCockpitToggle)		// (Non-simulation Action)
	/* OBSOLETE */REGISTER_COMMAND(iCommandViewSaveAngles3)
	/* OBSOLETE */REGISTER_COMMAND(iCommandViewSaveAngles4)
	/* OBSOLETE */	REGISTER_COMMAND_EX(iCommandViewSaveAngles5, 240)
	/* OBSOLETE */REGISTER_COMMAND(iCommandViewSaveAngles6)
	/* OBSOLETE */REGISTER_COMMAND(iCommandViewSaveAngles7)
	/* OBSOLETE */REGISTER_COMMAND(iCommandViewSaveAngles8)
	/* OBSOLETE */REGISTER_COMMAND(iCommandViewSaveAngles9)
	REGISTER_COMMAND(iCommandViewCoordinatesInLinearUnits)	// (Non-simulation Action)	
	REGISTER_COMMAND(iCommandNoAcceleration)					// §µ§ã§Ü§à§â§Ö§ß§Ú§Ö §Þ§à§Õ§Ö§Ý§î§ß§à§Ô§à §Ó§â§Ö§Þ§Ö§ß§Ú = 1 (Administrative Action)
	REGISTER_COMMAND(iCommandPlaneHUDFilterOnOff)			// §±§à§Õ§ß§ñ§ä§î/§à§á§å§ã§ä§Ú§ä§î §ã§Ó§Ö§ä§à§æ§Ú§Ý§î§ä§â §ª§­§³ (Ka-50)
	REGISTER_COMMAND(iCommandCockpitTakeControl)				// §±§Ö§â§Ö§Ü§Ý§ð§é§Ñ§ä§Ö§Ý§î §å§á§â§Ñ§Ó§Ý§Ö§ß§Ú§ñ §Õ§Ý§ñ §ã§Ö§ä§Ö§Ó§à§Ô§à §Ú§ß§ã§á§Ö§Ü§ä§à§â§Ñ
	/* NOT IMPL */REGISTER_COMMAND(iCommandRollbackSave)		// §³§à§Ù§Õ§Ñ§ß§Ú§Ö §ä§à§é§Ü§Ú §à§ä§Ü§Ñ§ä§Ñ §Ó §ä§â§Ö§Ü§Ö (Administrative Action) 
	/* NOT IMPL */	REGISTER_COMMAND_EX(iCommandRollBack, 250)		// §°§ä§Ü§Ñ§ä §ß§Ñ §á§â§Ö§Õ§í§Õ§å§ë§å§ð §ä§à§é§Ü§å (Administrative Action)
	/* NOT IMPL */REGISTER_COMMAND(iCommandRollForward)        // §±§Ö§â§Ö§ç§à§Õ §ß§Ñ §á§à§ã§Ý§Ö§Õ§å§ð§ë§å§ð §ä§à§é§Ü§å (Administrative Action)
	REGISTER_COMMAND(iCommandPlaneMasterCaution)				// §¡§ß§Ñ§Ý§à§Ô "§¿§Ü§â§Ñ§ß §Ó§í§Ù§à§Ó" (§®§Ú§¤-29) §Ü§ß§à§á§Ü§Ñ-§Ý§Ñ§Þ§á§Ñ §¸§³§° (§¬§Ñ-50)
	REGISTER_COMMAND(iCommandPlaneScalesReject)				// Scales reject / §à§Ô§â§Ñ§ß§Ú§é. §Ú§ß§Õ§Ú§Ü§Ñ§è. §ß§Ñ §ª§­§³ (§¬§Ñ-50)
	REGISTER_COMMAND(iCommandPlaneBettyRepeat)				// Repeat Betty messages (Rf-50)
	/* NOT IMPL */	   REGISTER_COMMAND(iCommandSaveGame)		// (Administrative Action)
	/*OBSOLETE*/   REGISTER_COMMAND(iCommandLoadGame)
	/*OBSOLETE*/   REGISTER_COMMAND(iCommandScreenShot)						// (Administrative Action)
	REGISTER_COMMAND(iCommandThreatMissilePadlock)
	REGISTER_COMMAND(iCommandAllMissilePadlock)
	/*OBSOLETE*/	REGISTER_COMMAND_EX(iCommandFinishTrack, 260)
	REGISTER_COMMAND(iCommandMarkerState)					// (Non-simulation Action)
	REGISTER_COMMAND(iCommandDecreaseRadarScanArea)
	REGISTER_COMMAND(iCommandIncreaseRadarScanArea)
	REGISTER_COMMAND(iCommandMarkerStatePlane)				// (Non-simulation Action)
	REGISTER_COMMAND(iCommandMarkerStateRocket)				// (Non-simulation Action)
	REGISTER_COMMAND(iCommandMarkerStateShip)				// (Non-simulation Action)
	REGISTER_COMMAND(iCommandAWACSHomeBearing)
	REGISTER_COMMAND(iCommandAWACSTankerBearing)
	REGISTER_COMMAND(iCommandAWACSBanditBearing)
	REGISTER_COMMAND_EX(iCommandAWACSDeclare, 270)
	REGISTER_COMMAND(iCommandEasyRadarOnOff)
	REGISTER_COMMAND(iCommandAutoLockOnNearestAircraft)
	REGISTER_COMMAND(iCommandAutoLockOnCenterAircraft)
	REGISTER_COMMAND(iCommandAutoLockOnNextAircraft)
	REGISTER_COMMAND(iCommandAutoLockOnPreviousAircraft)
	REGISTER_COMMAND(iCommandAutoLockOnNearestSurfaceTarget)
	REGISTER_COMMAND(iCommandAutoLockOnCenterSurfaceTarget)
	REGISTER_COMMAND(iCommandAutoLockOnNextSurfaceTarget)
	REGISTER_COMMAND(iCommandAutoLockOnPreviousSurfaceTarget)
	REGISTER_COMMAND_EX(iCommandChangeGunRateOfFire, 280)
	REGISTER_COMMAND(iCommandChangeRippleQuantity)
	REGISTER_COMMAND(iCommandChangeRippleInterval)
	REGISTER_COMMAND(iCommandSwitchMasterArm)
	REGISTER_COMMAND(iCommandChangeReleaseMode)
	REGISTER_COMMAND(iCommandPlaneRadarChangeMode)
	REGISTER_COMMAND(iCommandChangeRWRMode)
	REGISTER_COMMAND(iCommandPromotePlane)					// §¡§Ü§ä§Ú§Ó§Ú§Ù§Ú§â§à§Ó§Ñ§ä§î §ã§Ü§â§í§ä§à§Ô§à §Ü§Ý§Ú§Ö§ß§ä§Ñ (Inside Action)
	REGISTER_COMMAND(iCommandFlightClockReset)
	REGISTER_COMMAND(iCommandViewForwardSlowStop)			// (Non-simulation Action)
	REGISTER_COMMAND_EX(iCommandViewBackSlowStop, 290)			// (Non-simulation Action)
	REGISTER_COMMAND(iCommandViewForwardStop)				// (Non-simulation Action)
	REGISTER_COMMAND(iCommandViewBackStop)					// (Non-simulation Action)
	REGISTER_COMMAND(iCommandFreezeActionSystem)				// (Inside Action)
	REGISTER_COMMAND(iCommandUnfreezeActionSystem)			// (Inside Action)
	REGISTER_COMMAND_EX(iCommandViewHorStop, 295)					// (Non-simulation Action)
	REGISTER_COMMAND(iCommandViewVertStop)					// (Non-simulation Action)
	REGISTER_COMMAND(iCommandAutopilotEmergOFF_up)
	REGISTER_COMMAND(iCommandViewTowerJump)					// (Non-simulation Action)
	REGISTER_COMMAND(iCommandViewCameraJiggle)				// (Non-simulation Action)
	REGISTER_COMMAND_EX(iCommandPlaneCockpitIllumination, 300)

	REGISTER_COMMAND(iCommandHelicopter_PPR_button_K_up)
	REGISTER_COMMAND(iCommandHelicopter_PPR_button_H_up)
	REGISTER_COMMAND(iCommandHelicopter_PPR_button_T_up)
	REGISTER_COMMAND(iCommandHelicopter_PPR_button_B_up)
	REGISTER_COMMAND_EX(iCommandHelicopter_PPR_button_DIR_up, 305)

	REGISTER_COMMAND(iCommandTransferCursor)					// §±§Ö§â§Ö§Þ§Ö§ë§Ö§ß§Ú§Ö §Ü§å§â§ã§à§â§Ñ §Þ§í§ê§Ú (§Õ§Ý§ñ §ä§â§Ö§Ü§à§Ó) (Administrative Action)
	REGISTER_COMMAND(iCommandRecordCursorOnOff)				// §£§Ü§Ý§ð§é§Ö§ß§Ú§Ö/§Ó§í§Ü§Ý§ð§é§Ö§ß§Ú§Ö §Ù§Ñ§á§Ú§ã§Ú §Ü§å§â§ã§à§â§Ñ §Þ§í§ê§Ú (§Õ§Ý§ñ §ä§â§Ö§Ü§à§Ó) (Inside Action)
	REGISTER_COMMAND(iCommandChangeRippleIntervalDown)		// §ª§Ù§Þ§Ö§ß§Ö§ß§Ú§Ö §Ú§ß§ä§Ö§â§Ó§Ñ§Ý§Ñ §ã§Ò§â§à§ã§Ñ §Ò§à§Þ§Ò §Ó §Ù§Ñ§Ý§á§Ö §Õ§Ý§ñ §¡10 §Ó §à§Ò§â§Ñ§ä§ß§à§Þ §ß§Ñ§á§â§Ñ§Ó§Ý§Ö§ß§Ú§Ú

	REGISTER_COMMAND(iCommandEnginesStart)				// §©§Ñ§á§å§ã§Ü §Õ§Ó§Ú§Ô§Ñ§ä§Ö§Ý§Ö§Û
	REGISTER_COMMAND_EX(iCommandEnginesStop, 310)			// §£§í§Ü§Ý§ð§é§Ö§ß§Ú§Ö §Õ§Ó§Ú§Ô§Ñ§ä§Ö§Ý§Ö§Û

	REGISTER_COMMAND(iCommandLeftEngineStart)			// §©§Ñ§á§å§ã§Ü §Ý§Ö§Ó§à§Ô§à §Õ§Ó§Ú§Ô§Ñ§ä§Ö§Ý§ñ
	REGISTER_COMMAND(iCommandRightEngineStart)			// §©§Ñ§á§å§ã§Ü §á§â§Ñ§Ó§à§Ô§à §Õ§Ó§Ú§Ô§Ñ§ä§Ö§Ý§ñ

	REGISTER_COMMAND(iCommandLeftEngineStop)				// §£§í§Ü§Ý§ð§é§Ö§ß§Ú§Ö §Ý§Ö§Ó§à§Ô§à §Õ§Ó§Ú§Ô§Ñ§ä§Ö§Ý§ñ
	REGISTER_COMMAND(iCommandRightEngineStop)			// §£§í§Ü§Ý§ð§é§Ö§ß§Ú§Ö §á§â§Ñ§Ó§à§Ô§à §Õ§Ó§Ú§Ô§Ñ§ä§Ö§Ý§ñ

	REGISTER_COMMAND(iCommandPowerOnOff)					// Activer / d¨¦sactiver le pouvoir (Puissance ¨¦lectrique) - 315

	REGISTER_COMMAND(iCommandAltimeterPressureIncrease)	// §µ§Ó§Ö§Ý§Ú§é§Ö§ß§Ú§Ö §Õ§Ñ§Ó§Ý§Ö§ß§Ú§ñ §ß§Ñ §£§¥
	REGISTER_COMMAND(iCommandAltimeterPressureDecrease)	// §µ§Þ§Ö§ß§î§ê§Ö§ß§Ú§Ö §Õ§Ñ§Ó§Ý§Ö§ß§Ú§ñ §ß§Ñ §£§¥
	REGISTER_COMMAND(iCommandAltimeterPressureStop)

	REGISTER_COMMAND(iCommandTrackEditReplace)			// §²§Ö§Ø§Ú§Þ §â§Ö§Õ§Ñ§Ü§ä§Ú§â§à§Ó§Ñ§ß§Ú§ñ §ä§â§Ö§Ü§Ñ §ã §à§ä§Þ§Ö§ß§à§Û §ã§ä§Ñ§â§à§Ô§à (§á§à §å§Þ§à§Ý§é§Ñ§ß§Ú§ð) (Administrative Action)
	REGISTER_COMMAND_EX(iCommandTrackEditInsert, 320)		// §²§Ö§Ø§Ú§Þ §â§Ö§Õ§Ñ§Ü§ä§Ú§â§à§Ó§Ñ§ß§Ú§ñ §ä§â§Ö§Ü§Ñ §ã §Õ§à§Ò§Ñ§Ó§Ý§Ö§ß§Ú§Ö§Þ §Ü §ã§ä§Ñ§â§à§Þ§å (Administrative Action)

	REGISTER_COMMAND(iCommandViewFastMouse)				// §²§Ö§Ø§Ú§Þ §å§ã§Ü§à§â§Ö§ß§ß§í§ç §Ñ§ß§Ñ§Ý§à§Ô§à§Ó§í§ç §á§Ö§â§Ö§Þ§Ö§ë§Ö§ß§Ú§Û §Ü§Ñ§Þ§Ö§â§í
	REGISTER_COMMAND(iCommandViewSlowMouse)				// §²§Ö§Ø§Ú§Þ §Ù§Ñ§Þ§Ö§Õ§Ý§Ö§ß§ß§í§ç §Ñ§ß§Ñ§Ý§à§Ô§à§Ó§í§ç §á§Ö§â§Ö§Þ§Ö§ë§Ö§ß§Ú§Û §Ü§Ñ§Þ§Ö§â§í
	REGISTER_COMMAND(iCommandViewNormalMouse)			// §²§Ö§Ø§Ú§Þ §ß§à§â§Þ§Ñ§Ý§î§ß§í§ç §Ñ§ß§Ñ§Ý§à§Ô§à§Ó§í§ç §á§Ö§â§Ö§Þ§Ö§ë§Ö§ß§Ú§Û §Ü§Ñ§Þ§Ö§â§í

	REGISTER_COMMAND(iCommandRecordSubtitleOn)			// §£§Ü§Ý§ð§é§Ö§ß§Ú§Ö §á§à§Ü§Ñ§Ù§Ñ §ã§å§Ò§ä§Ú§ä§â§à§Ó (§Õ§Ý§ñ §ä§â§Ö§Ü§à§Ó) (Inside Action)
	REGISTER_COMMAND(iCommandRecordSubtitleOff)			// §£§í§Ü§Ý§ð§é§Ö§ß§Ú§Ö §á§à§Ü§Ñ§Ù§Ñ §ã§å§Ò§ä§Ú§ä§â§à§Ó (§Õ§Ý§ñ §ä§â§Ö§Ü§à§Ó) (Inside Action)

	REGISTER_COMMAND(iCommandViewHUDOnlyOnOff)			// §±§Ö§â§Ö§Ü§Ý§ð§é§Ñ§ä§Ö§Ý§î §â§Ö§Ø§Ú§Þ§Ñ §Ü§Ñ§Ò§Ú§ß§í "§´§à§Ý§î§Ü§à §ª§­§³"

	REGISTER_COMMAND(iCommandRecoverHuman)				// §£§à§ã§ã§ä§Ñ§ß§à§Ó§Ú§ä§î §ç§î§ð§Þ§Ñ§ß§Ñ
	REGISTER_COMMAND(iCommandPlaneHeadLightOnOff)		// §£§Ü§Ý/§Ó§í§Ü§Ý §æ§Ñ§â§í §ß§Ñ §á§Ö§â§Ö§Õ§ß§Ö§Û §ã§ä§à§Û§Ü§Ö §ê§Ñ§ã§ã§Ú

	REGISTER_COMMAND(iCommandPlaneLockPadlock)				// §³§Ý§Ö§Õ§Ú§ä§î §Ù§Ñ §Ò§Ý§Ú§Ø§Ñ§Û§ê§Ú§Þ §à§Ò§ì§Ö§Ü§ä§à§Þ
	REGISTER_COMMAND_EX(iCommandPlaneUnlockPadlock, 330)		// §¢§â§à§ã§Ú§ä§î §ã§Ý§Ö§Õ§Ú§ä§î §Ù§Ñ §à§Ò§ì§Ö§Ü§ä§à§Þ

	REGISTER_COMMAND(iCommandViewFastKeyboard)			// §²§Ö§Ø§Ú§Þ §å§ã§Ü§à§â§Ö§ß§ß§í§ç §Ü§Ý§Ñ§Ó§Ú§ê§ß§í§ç §á§Ö§â§Ö§Þ§Ö§ë§Ö§ß§Ú§Û §Ü§Ñ§Þ§Ö§â§í
	REGISTER_COMMAND(iCommandViewSlowKeyboard)			// §²§Ö§Ø§Ú§Þ §Ù§Ñ§Þ§Ö§Õ§Ý§Ö§ß§ß§í§ç §Ü§Ý§Ñ§Ó§Ú§ê§ß§í§ç §á§Ö§â§Ö§Þ§Ö§ë§Ö§ß§Ú§Û §Ü§Ñ§Þ§Ö§â§í
	REGISTER_COMMAND(iCommandViewNormalKeyboard)			// §²§Ö§Ø§Ú§Þ §ß§à§â§Þ§Ñ§Ý§î§ß§í§ç §Ü§Ý§Ñ§Ó§Ú§ê§ß§í§ç §á§Ö§â§Ö§Þ§Ö§ë§Ö§ß§Ú§Û §Ü§Ñ§Þ§Ö§â§í

	REGISTER_COMMAND(iCommandViewExternalZoomIn)			// Zoom §Õ§Ý§ñ §Ó§ß§Ö§ê§ß§Ú§ç §Ó§Ú§Õ§à§Ó	
	REGISTER_COMMAND(iCommandViewExternalZoomInStop)
	REGISTER_COMMAND(iCommandViewExternalZoomOut)
	REGISTER_COMMAND(iCommandViewExternalZoomOutStop)
	REGISTER_COMMAND(iCommandViewExternalZoomDefault)
	REGISTER_COMMAND(iCommandMouseViewOnOff)			// §©§ß§Ñ§é§Ö§ß§Ú§ñ §Ó§ß§Ö§ê§ß§Ö§Û §Ú §Ü§à§Ü§á§Ú§ä§ß§à§Û §å§ã§ä§Ñ§ß§à§Ó§à§Ü §Þ§í§ê§Ú §Õ§Ý§ñ §ä§â§Ö§Ü§à§Ó (Inside Action)

	REGISTER_COMMAND_EX(iCommandViewCameraMoveMode, 340)	// §±§Ö§â§Ö§Ü§Ý§ð§é§Ñ§ä§Ö§Ý§î §â§Ö§Ø§Ú§Þ§Ñ §á§Ö§â§Ö§Þ§Ö§ë§Ö§ß§Ú§ñ §Ü§Ñ§Þ§Ö§â§í (§ã§Ý§å§Ø§Ö§Ò§ß§Ñ§ñ - §Ó§Þ§Ö§ã§ä§à §Ü§Ý§Ñ§Ó§Ú§ê§Ú S §Ó §ä§â§Ö§Ü§Ñ§ç)
	REGISTER_COMMAND(iCommandViewFightGround)			// §¬§Ñ§Þ§Ö§â§Ñ §ã§Ñ§Þ§à§Ý§Ö§ä-§ß§Ñ§Ù§Ö§Þ§ß§í§Û §ð§ß§Ú§ä/§Ü§à§â§Ñ§Ò§Ý§î (Non-simulation Action)
	REGISTER_COMMAND(iCommandViewCameraUpLeft)			// §±§à§Ó§à§â§à§ä §Ü§Ñ§Þ§Ö§â§í §Ó§Ó§Ö§â§ç-§ß§Ñ§Ý§Ö§Ó§à (Non-simulation Action)
	REGISTER_COMMAND(iCommandViewCameraUpRight)			// §±§à§Ó§à§â§à§ä §Ü§Ñ§Þ§Ö§â§í §Ó§Ó§Ö§â§ç-§ß§Ñ§á§â§Ñ§Ó§à (Non-simulation Action)
	REGISTER_COMMAND(iCommandViewCameraDownLeft)			// §±§à§Ó§à§â§à§ä §Ü§Ñ§Þ§Ö§â§í §Ó§ß§Ú§Ù-§ß§Ñ§Ý§Ö§Ó§à (Non-simulation Action)
	REGISTER_COMMAND(iCommandViewCameraDownRight)		// §±§à§Ó§à§â§à§ä §Ü§Ñ§Þ§Ö§â§í §Ó§ß§Ú§Ù-§ß§Ñ§á§â§Ñ§Ó§à (Non-simulation Action)
	REGISTER_COMMAND(iCommandViewPanToggle)				// §±§Ö§â§Ö§Ü§Ý§ð§é§Ñ§ä§Ö§Ý§î pan-§â§Ö§Ø§Ú§Þ§Ñ (Non-simulation Action)
	REGISTER_COMMAND(iCommandViewCameraReturn)			// §£§à§Ù§Ó§â§Ñ§ä §Ü§Ñ§Þ§Ö§â§í (Non-simulation Action)
	REGISTER_COMMAND(iCommandViewLocomotivesToggle)		// §¶§Ú§Ý§î§ä§â §ä§à§Ý§î§Ü§à_§Ý§à§Ü§à§Þ§à§ä§Ú§Ó§í/§Ó§ã§Ö §Õ§Ý§ñ Ctrl-F12 (Non-simulation Action)
	REGISTER_COMMAND(iCommandPlaneLaunchPermissionOverride)	// §³§ß§ñ§ä§Ú§Ö §Ò§Ý§à§Ü§Ú§â§à§Ó§Ü§Ú §ã §à§â§å§Ø§Ú§ñ
	REGISTER_COMMAND_EX(iCommandPlanePickleOn, 350)		// §±§å§ã§Ü §â§Ñ§Ü§Ö§ä/§ã§Ò§â§à§ã §Ò§à§Þ§Ò §Õ§Ý§ñ §Ù§Ñ§á§Ñ§Õ§ß§í§ç §ã§Ñ§Þ§à§Ý§Ö§ä§à§Ó
	REGISTER_COMMAND(iCommandPlanePickleOff)
	REGISTER_COMMAND(iCommandViewCameraBaseReturn)		// §£§à§Ù§Ó§â§Ñ§ä §Ò§Ñ§Ù§Ú§ã§Ñ §Ü§Ñ§Þ§Ö§â§í (Non-simulation Action)
	REGISTER_COMMAND(iCommandViewCameraUpLeftSlow)		// §±§à§Ó§à§â§à§ä §Ü§Ñ§Þ§Ö§â§í §Ó§Ó§Ö§â§ç-§ß§Ñ§Ý§Ö§Ó§à §Þ§Ö§Õ§Ý§Ö§ß§ß§í§Û (Non-simulation Action)
	REGISTER_COMMAND(iCommandViewCameraUpRightSlow)		// §±§à§Ó§à§â§à§ä §Ü§Ñ§Þ§Ö§â§í §Ó§Ó§Ö§â§ç-§ß§Ñ§á§â§Ñ§Ó§à §Þ§Ö§Õ§Ý§Ö§ß§ß§í§Û (Non-simulation Action)
	REGISTER_COMMAND(iCommandViewCameraDownLeftSlow)		// §±§à§Ó§à§â§à§ä §Ü§Ñ§Þ§Ö§â§í §Ó§ß§Ú§Ù-§ß§Ñ§Ý§Ö§Ó§à §Þ§Ö§Õ§Ý§Ö§ß§ß§í§Û (Non-simulation Action)
	REGISTER_COMMAND(iCommandViewCameraDownRightSlow)	// §±§à§Ó§à§â§à§ä §Ü§Ñ§Þ§Ö§â§í §Ó§ß§Ú§Ù-§ß§Ñ§á§â§Ñ§Ó§à §Þ§Ö§Õ§Ý§Ö§ß§ß§í§Û (Non-simulation Action)
	REGISTER_COMMAND(iCommandPlaneDropFlareOnce)			// §°§Õ§ß§à§Ü§â§Ñ§ä§ß§í§Û §ã§Ò§â§à§ã §ª§¬-§Ý§à§Ó§å§ê§Ö§Ü
	REGISTER_COMMAND(iCommandPlaneDropChaffOnce)			// §°§Õ§ß§à§Ü§â§Ñ§ä§ß§í§Û §ã§Ò§â§à§ã §Õ§Ú§á§à§Ý§î§ß§í§ç §à§ä§â§Ñ§Ø§Ñ§ä§Ö§Ý§Ö§Û
	REGISTER_COMMAND(iCommandViewRear)					// §£§Ú§Õ §ß§Ñ§Ù§Ñ§Õ (Non-simulation Action)
	REGISTER_COMMAND_EX(iCommandScoresWindowToggle, 360)			// §á§à§Ü§Ñ§Ù§Ñ§ä§î\§ã§Ü§â§í§ä§î §à§Ü§ß§à §ã§Ö§ä§Ö§Ó§à§Û §ã§ä§Ñ§ä§Ú§ã§ä§Ú§Ü§Ú §Ó §â§Ö§Ø§Ú§Þ§Ö §ã§Ú§Þ§å§Ý§ñ§è§Ú§Ú
	REGISTER_COMMAND(iCommandCockpitClickOn)		// §¯§Ñ§é§Ñ§ä§î §å§á§â§Ñ§Ó§Ý§Ö§ß§Ú§Ö §å§Ü§Ñ§Ù§Ñ§ß§ß§í§Þ §Ü§à§ß§ä§â§à§Ý§à§Þ §Ó §Ü§Ñ§Ò§Ú§ß§Ö
	REGISTER_COMMAND(iCommandCockpitClickOff)	// §©§Ñ§Ó§Ö§â§ê§Ú§ä§î §å§á§â§Ñ§Ó§Ý§Ö§ß§Ú§Ö §ä§Ö§Ü§å§ë§Ú§Þ §å§á§â§Ñ§Ó§Ý§ñ§Ö§Þ§í§Þ §Ü§à§ß§ä§â§à§Ý§à§Þ §Ó §Ü§Ñ§Ò§Ú§ß§Ö
	REGISTER_COMMAND(iCommandCockpitClickModeOnOff)	// §²§Ö§Ø§Ú§Þ Clickable cockpit §Ó§Ü§Ý§ð§é§Ú§ä§î/§Ó§í§Ü§Ý§ð§é§Ú§ä§î

	// CMD
	REGISTER_COMMAND(iCommandPlaneCMDDispence)				// §±§Ñ§ã§ã§Ú§Ó§ß§í§Ö §ã§â§Ö§Õ§ã§ä§Ó§Ñ §²§¿§¢ §Ó§í§Ò§â§à§ã §Ý§à§Ó§å§ê§Ö§Ü
	REGISTER_COMMAND(iCommandPlaneCMDDispenceOff)
	REGISTER_COMMAND(iCommandPlaneCMDDispenceStop)			// §±§Ñ§ã§ã§Ú§Ó§ß§í§Ö §ã§â§Ö§Õ§ã§ä§Ó§Ñ §²§¿§¢ §à§ã§ä§Ñ§ß§à§Ó§Ü§Ñ §Ó§í§Ò§â§à§ã§Ñ §Ý§à§Ó§å§ê§Ö§Ü
	REGISTER_COMMAND(iCommandPlaneCMDDispenceStopOff)
	REGISTER_COMMAND(iCommandPlaneCMDChangeRippleQuantity)	// §±§Ñ§ã§ã§Ú§Ó§ß§í§Ö §ã§â§Ö§Õ§ã§ä§Ó§Ñ §²§¿§¢ §Ú§Ù§Þ§Ö§ß§Ú§ä§î §Ü§à§Ý§Ú§é§Ö§ã§ä§Ó§à §Ó §ã§Ö§â§Ú§Ú
	REGISTER_COMMAND(iCommandPlaneCMDChangeRippleQuantityOff)
	REGISTER_COMMAND_EX(iCommandPlaneCMDChangeRippleInterval, 370)	// §±§Ñ§ã§ã§Ú§Ó§ß§í§Ö §ã§â§Ö§Õ§ã§ä§Ó§Ñ §²§¿§¢ §Ú§Ù§Þ§Ö§ß§Ú§ä§î §Ú§ß§ä§Ö§â§Ó§Ñ§Ý §Ó §ã§Ö§â§Ú§Ú
	REGISTER_COMMAND(iCommandPlaneCMDChangeRippleIntervalOff)
	REGISTER_COMMAND(iCommandPlaneCMDChangeBurstAmount)		// §±§Ñ§ã§ã§Ú§Ó§ß§í§Ö §ã§â§Ö§Õ§ã§ä§Ó§Ñ §²§¿§¢ §Ú§Ù§Þ§Ö§ß§Ú§ä§î §Ü§à§Ý§Ú§é§Ö§ã§ä§Ó§à §ã§Ö§â§Ú§Û
	REGISTER_COMMAND(iCommandPlaneCMDChangeBurstAmountOff)
	REGISTER_COMMAND(iCommandPlaneCMDCancelCurrentProgram)	// §±§Ñ§ã§ã§Ú§Ó§ß§í§Ö §ã§â§Ö§Õ§ã§ä§Ó§Ñ §²§¿§¢ §ã§Ò§â§à§ã §á§â§à§Ô§â§Ñ§Þ§Þ§í
	REGISTER_COMMAND(iCommandPlaneCMDCancelCurrentProgramOff)
	REGISTER_COMMAND(iCommandPlaneCMDChangeBoard)			// §±§Ñ§ã§ã§Ú§Ó§ß§í§Ö §ã§â§Ö§Õ§ã§ä§Ó§Ñ §²§¿§¢ §Ó§í§Ò§à§â §Ò§à§â§ä§Ñ
	REGISTER_COMMAND(iCommandPlaneCMDShowAmountOrProgram)	// §±§Ñ§ã§ã§Ú§Ó§ß§í§Ö §ã§â§Ö§Õ§ã§ä§Ó§Ñ §²§¿§¢ §ã§Þ§Ö§ß§Ñ §Ú§ß§Õ§Ú§Ü§Ñ§è§Ú§Ú - §ß§Ñ§Ý§Ú§é§Ú§Ö §Ý§à§Ó§å§ê§Ö§Ü §Ú§Ý§Ú §ä§Ö§Ü§å§ë§Ñ§ñ §á§â§à§Ô§â§Ñ§Þ§Þ§Ñ

	REGISTER_COMMAND(iCommandPlaneCancelWeaponsDelivery)		// §ã§Ò§â§à§ã §â§Ö§Ø§Ú§Þ§Ñ §â§Ñ§Ò§à§ä§í §Ñ§Ó§Ú§à§ß§Ú§Ü§Ú (§¬§Ñ - 50)
	REGISTER_COMMAND(iCommandPlaneMasterCautionOff)
	// §Ö§ã§Ý§Ú §®§¶§¥ §ß§Ö§ã§Ü§à§Ý§î§Ü§à §â§Ñ§ã§á§â§Ö§Õ§Ö§Ý§Ö§ß§Ú§Ö §á§â§à§Ú§ã§ç§à§Õ§Ú§ä §á§à §Ú§Õ§Ö§ß§ä§Ú§æ§Ú§Ü§Ñ§ä§à§â§å §å§ã§ä§â§à§Û§ã§ä§Ó§Ñ  §Ú §ã§à§Ò§í§ä§Ú§ð iCommandCockpitClickOn §Ó§ß§å§ä§â§Ú Cockpit §ã§Þ. cockpit::Clickable
	// §à§á§â§Ö§Õ§Ö§Ý§Ö§ß§Ú§Ö §á§Ö§â§Ö§ß§Ö§ã§Ö§ß§à §Ó Actions.h 	§Ó §ã§Ý§Ö§Õ§ã§ä§Ó§Ú§Ö §á§Ñ§â§Ñ§Þ§Ö§ä§â§Ú§Ù§Ñ§è§Ú§Ú §Ó§í§Ù§à§Ó§Ñ §á§à §Ú§Õ§Ö§ß§ä§Ú§æ§Ú§Ü§Ñ§ä§à§â§å §å§ã§ä§â§à§Û§ã§ä§Ó§Ñ
	REGISTER_COMMAND_EX(iCommandPlane_SpotLight_hor_stop, 380)
	REGISTER_COMMAND(iCommandHelicopter_SelectWeapon_hor_up)
	REGISTER_COMMAND(iCommandHelicopter_SelectWeapon_vert_up)
	REGISTER_COMMAND(iCommandViewChaseArcade) // chase §Ü§Ñ§Þ§Ö§â§Ñ §Õ§Ý§ñ §Ñ§â§Ü§Ñ§Õ§ß§à§Ô§à §Ó§Ú§Õ§Ñ ) §á§Ý§Ñ§Ó§Ñ§ð§ë§Ñ§ñ									
	REGISTER_COMMAND(iCommandAutoLockOnClear)		// §ã§ß§ñ§ä§î §è§Ö§Ý§î §ã EasyRadar
	REGISTER_COMMAND_EX(iCommandHelicopterHover_up, 385)
	REGISTER_COMMAND(iCommandPlaneStabTangBank)			// §³§ä§Ñ§Ò§Ú§Ý§Ú§Ù§Ñ§è§Ú§ñ §ä§Ñ§ß§Ô§Ñ§Ø§Ñ §Ú §Ü§â§Ö§ß§Ñ
	REGISTER_COMMAND(iCommandPlaneStabHbarBank)			// §³§ä§Ñ§Ò§Ú§Ý§Ú§Ù§Ñ§è§Ú§ñ Hbar §Ú §Ü§â§Ö§ß§Ñ
	REGISTER_COMMAND(iCommandPlaneStabHorizon)			// §³§ä§Ñ§Ò§Ú§Ý§Ú§Ù§Ñ§è§Ú§ñ §ä§Ñ§ß§Ô§Ñ§Ø§Ñ §Ú §Ü§â§Ö§ß§Ñ
	REGISTER_COMMAND(iCommandPlaneStabHbar)				// §³§ä§Ñ§Ò§Ú§Ý§Ú§Ù§Ñ§è§Ú§ñ Hbar
	REGISTER_COMMAND_EX(iCommandPlaneStabHrad, 390)				// §³§ä§Ñ§Ò§Ú§Ý§Ú§Ù§Ñ§è§Ú§ñ Hrad
	REGISTER_COMMAND(iCommandActiveIRJamming)			// IR OnOff
	REGISTER_COMMAND(iCommandPlaneLaserRangerOnOff)		// §£§Ü§Ý/§£§í§Ü§Ý §Ý§Ñ§Ù§Ö§â§ß§í§Û §Õ§Ñ§Ý§î§ß§à§Þ§Ö§â
	REGISTER_COMMAND(iCommandPlaneNightTVOnOff)         // §£§Ü§Ý/§£§í§Ü§Ý §ß§à§é§ß§à§Û §Ü§Ñ§ß§Ñ§Ý §ä§Ö§Ý§Ö§Ó§Ú§Ù§Ú§à§ß§ß§à§Û §ã§Ú§ã§ä§Ö§Þ§í (IR or LLTV) 
	REGISTER_COMMAND(iCommandPlaneChangeRadarPRF)       // §ª§Ù§Þ§Ö§ß§Ú§ä§î §é§Ñ§ã§ä§à§ä§å §á§à§Ó§ä§à§â§Ö§ß§Ú§ñ §Ú§Þ§á§å§Ý§î§ã§à§Ó §â§Ñ§Õ§Ñ§â§Ñ
	REGISTER_COMMAND(iCommandViewKeepTerrain)			// §µ§Õ§Ö§â§Ø§Ú§Ó§Ñ§ä§î §ã§Ó§à§Ò§à§Õ§ß§å§ð §Ü§Ñ§Þ§Ö§â§å §à§Ü§à§Ý§à §Ù§Ö§Þ§Ý§Ú
	REGISTER_COMMAND(iCommandViewSnapView0)
	REGISTER_COMMAND(iCommandViewSnapView1)
	REGISTER_COMMAND(iCommandViewSnapView2)
	REGISTER_COMMAND(iCommandViewSnapView3)
	REGISTER_COMMAND_EX(iCommandViewSnapView4, 400)
	REGISTER_COMMAND(iCommandViewSnapView5)
	REGISTER_COMMAND(iCommandViewSnapView6)
	REGISTER_COMMAND(iCommandViewSnapView7)
	REGISTER_COMMAND(iCommandViewSnapView8)
	REGISTER_COMMAND(iCommandViewSnapView9)
	REGISTER_COMMAND(iCommandViewSnapViewStop)
	REGISTER_COMMAND(iCommandViewBinocular)
	REGISTER_COMMAND(iCommandPlaneStabCancel)			// §³§Ò§â§à§ã §Ó§ã§Ö§ç §â§Ö§Ø§Ú§Þ§à§Ó §ã§ä§Ñ§Ò§Ú§Ý§Ú§Ù§Ñ§è§Ú§Ú §Ú §Ñ§Ó§ä§à§á§Ú§Ý§à§ä§Ñ
	REGISTER_COMMAND(iCommandPlaneThreatWarnSoundVolumeDown)	// §µ§Þ§Ö§ß§î§ê§Ö§ß§Ú§Ö §Ô§â§à§Þ§Ü§à§ã§ä§Ú §Ù§Ó§å§Ü§à§Ó§í§ç §ã§Ú§Ô§ß§Ñ§Ý§à§Ó §³§±§°
	REGISTER_COMMAND_EX(iCommandPlaneThreatWarnSoundVolumeUp, 410)	// §µ§Ó§Ö§Ý§Ú§é§Ö§ß§Ú§Ö §Ô§â§à§Þ§Ü§à§ã§ä§Ú §Ù§Ó§å§Ü§à§Ó§í§ç §ã§Ú§Ô§ß§Ñ§Ý§à§Ó §³§±§°
	REGISTER_COMMAND(iCommandViewLaserOnOff)
	REGISTER_COMMAND(iCommandPlaneIncreaseBase_Distance)     // §µ§Ó§Ö§Ý§Ú§é§Ö§ß§Ú§Ö §Ò§Ñ§Ù§í §è§Ö§Ý§Ú
	REGISTER_COMMAND(iCommandPlaneDecreaseBase_Distance)     // §µ§Þ§Ö§ß§î§ê§Ö§ß§Ú§Ö §Ò§Ñ§Ù§í §è§Ö§Ý§Ú
	REGISTER_COMMAND(iCommandPlaneStopBase_Distance)
	REGISTER_COMMAND(iCommandViewIRPointerOnOff)
	REGISTER_COMMAND(iCommandViewNVGOnOff)//!!!!!!Not an avionics action, only view!!!!!!
	/* OBSOLETE */	Obsolete_iCommandViewAWACSZoomOutOn,
	/* OBSOLETE */	Obsolete_iCommandViewAWACSZoomOutOff,
	/* OBSOLETE */	Obsolete_iCommandViewAWACSZoomInOn,
	/* OBSOLETE */	Obsolete_iCommandViewAWACSDetectionAreas,
	/* OBSOLETE */	Obsolete_iCommandViewAWACSDangerousAreas,
	/* OBSOLETE */	Obsolete_iCommandViewAWACSShowLabels,
	REGISTER_COMMAND(iCommandViewAWACSUnitInfoOn)
	REGISTER_COMMAND(iCommandViewAWACSUnitInfoOff)
	REGISTER_COMMAND(iCommandViewIR)
	REGISTER_COMMAND(iCommandViewTargetType)
	REGISTER_COMMAND(iCommandPlaneAutopilotOverrideOn)
	REGISTER_COMMAND(iCommandPlaneAutopilotOverrideOff)
	REGISTER_COMMAND(iCommandPlaneRouteAutopilot)
	REGISTER_COMMAND_EX(iCommandPlaneGearUp, 430)
	REGISTER_COMMAND(iCommandPlaneGearDown)
	REGISTER_COMMAND(iCommandViewAWACSJump)
	REGISTER_COMMAND(iCommandCockpitSecondClickOn)	// §Ö§ã§ä§î §ß§Ö§Ü§à§ä§à§â§í§Ö §Ü§à§ß§ä§â§à§Ý§í §Ü§à§ä§à§â§í§Ö §à§Õ§ß§à§Ó§â§Ö§Þ§Ö§ß§ß§à §à§ã§î §Ú §Ü§ß§à§á§Ü§Ñ 
	REGISTER_COMMAND(iCommandCockpitSecondClickOff)	// §©§Ñ§Ó§Ö§â§ê§Ú§ä§î §å§á§â§Ñ§Ó§Ý§Ö§ß§Ú§Ö §ä§Ö§Ü§å§ë§Ú§Þ §å§á§â§Ñ§Ó§Ý§ñ§Ö§Þ§í§Þ §Ü§à§ß§ä§â§à§Ý§à§Þ §Ó §Ü§Ñ§Ò§Ú§ß§Ö
	REGISTER_COMMAND(iCommandCompassRose)
	REGISTER_COMMAND(iCommandViewAWACSClearDistance)
	REGISTER_COMMAND(iCommandViewAWACSOutOfFocus)
	REGISTER_COMMAND(iCommandViewNightVisionGogglesOn)
	REGISTER_COMMAND(iCommandPlaneDesignate_CageOn)
	REGISTER_COMMAND_EX(iCommandPlaneDesignate_CageOff, 440)
	REGISTER_COMMAND(iCommandPlaneDesignate_CageOn_vertical)
	REGISTER_COMMAND(iCommandPlaneDesignate_CageOn_horizontal)

	//Data Link Panel PRTs (§±§å§Ý§î§ä §²§Ö§Ø§Ú§Þ§à§Ó §¸§Ö§Ý§Ö§å§Ü§Ñ§Ù§Ñ§ß§Ú§ñ §±§²§¸)
	REGISTER_COMMAND(iCommandPlaneDLK_Target1)
	REGISTER_COMMAND(iCommandPlaneDLK_Target2)
	REGISTER_COMMAND(iCommandPlaneDLK_Target3)
	REGISTER_COMMAND(iCommandPlaneDLK_RefPoint)
	REGISTER_COMMAND(iCommandPlaneDLK_Wingman1)
	REGISTER_COMMAND(iCommandPlaneDLK_Wingman2)
	REGISTER_COMMAND(iCommandPlaneDLK_Wingman3)
	REGISTER_COMMAND_EX(iCommandPlaneDLK_Wingman4, 450)
	REGISTER_COMMAND(iCommandPlaneDLK_All)
	REGISTER_COMMAND(iCommandPlaneDLK_Erase)
	REGISTER_COMMAND(iCommandPlaneDLK_Ingress)
	REGISTER_COMMAND(iCommandPlaneDLK_SendMemory)

	// NAV panel controls (§¬§Ñ-50 - §ë§Ú§ä§à§Ü §±§£§ª)
	REGISTER_COMMAND(iCommandPlaneNavChangePanelModeRight)
	REGISTER_COMMAND(iCommandPlaneNavChangePanelModeLeft)
	REGISTER_COMMAND(iCommandPlaneNavSetFixtakingMode)
	REGISTER_COMMAND(iCommandPlaneNav_DLK_OnOff)
	REGISTER_COMMAND(iCommandPlaneNav_PB0)
	REGISTER_COMMAND_EX(iCommandPlaneNav_PB1, 460)
	REGISTER_COMMAND(iCommandPlaneNav_PB2)
	REGISTER_COMMAND(iCommandPlaneNav_PB3)
	REGISTER_COMMAND(iCommandPlaneNav_PB4)
	REGISTER_COMMAND(iCommandPlaneNav_PB5)
	REGISTER_COMMAND(iCommandPlaneNav_PB6)
	REGISTER_COMMAND(iCommandPlaneNav_PB7)
	REGISTER_COMMAND(iCommandPlaneNav_PB8)
	REGISTER_COMMAND(iCommandPlaneNav_PB9)
	REGISTER_COMMAND(iCommandPlaneNav_Steerpoints)
	REGISTER_COMMAND_EX(iCommandPlaneNav_INU_realign, 470)
	REGISTER_COMMAND(iCommandPlaneNav_POS_corrMode)
	REGISTER_COMMAND(iCommandPlaneNav_INU_precise_align)
	REGISTER_COMMAND(iCommandPlaneNav_Airfields)
	REGISTER_COMMAND(iCommandPlaneNav_INU_normal_align)
	REGISTER_COMMAND(iCommandPlaneNav_Targets)
	REGISTER_COMMAND(iCommandPlaneNav_Enter)
	REGISTER_COMMAND(iCommandPlaneNav_Cancel)
	REGISTER_COMMAND(iCommandPlaneNav_POS_init)
	REGISTER_COMMAND(iCommandPlaneNav_SelfCoord)
	REGISTER_COMMAND_EX(iCommandPlaneNav_CourseTimeRange, 480)
	REGISTER_COMMAND(iCommandPlaneNav_Wind)
	REGISTER_COMMAND(iCommandPlaneNav_THeadingTimeRangeF)
	REGISTER_COMMAND(iCommandPlaneNav_BearingRangeT)

	REGISTER_COMMAND(iCommandViewPitCameraMoveUp)
	REGISTER_COMMAND_EX(iCommandViewPitCameraMoveDown, 485)
	REGISTER_COMMAND(iCommandViewPitCameraMoveLeft)
	REGISTER_COMMAND(iCommandViewPitCameraMoveRight)
	REGISTER_COMMAND(iCommandViewPitCameraMoveForward)
	REGISTER_COMMAND(iCommandViewPitCameraMoveBack)
	REGISTER_COMMAND_EX(iCommandViewPitCameraMoveStop, 490)
	REGISTER_COMMAND(iCommandViewPitCameraMoveCenter)
	REGISTER_COMMAND(iCommandViewPitHeadOnOff)
	REGISTER_COMMAND(iCommandPlaneCockpitIlluminationPanels) //obsolete
	REGISTER_COMMAND(iCommandPlaneCockpitIlluminationGauges) //obsolete

	//ABRIS
	REGISTER_COMMAND_EX(iCommandPlane_ABRIS_Power, 495)
	REGISTER_COMMAND(iCommandPlane_ABRIS_BT_1)
	REGISTER_COMMAND(iCommandPlane_ABRIS_BT_2)
	REGISTER_COMMAND(iCommandPlane_ABRIS_BT_3)
	REGISTER_COMMAND(iCommandPlane_ABRIS_BT_4)
	REGISTER_COMMAND_EX(iCommandPlane_ABRIS_BT_5, 500)
	REGISTER_COMMAND(iCommandPlane_ABRIS_Axis_Increase)
	REGISTER_COMMAND(iCommandPlane_ABRIS_Axis_Decrease)
	REGISTER_COMMAND(iCommandPlane_ABRIS_Axis_Push)
	REGISTER_COMMAND(iCommandPlane_ABRIS_Brightness_Increase)
	REGISTER_COMMAND(iCommandPlane_ABRIS_Brightness_Decrease)

	REGISTER_COMMAND(iCommandPlane_RouteMode)
	REGISTER_COMMAND(iCommandPlane_DescentMode)
	REGISTER_COMMAND_EX(iCommandPlane_DescentModeOff, 508)

	REGISTER_COMMAND(iCommandPlane_LockOn_start)          //§¬§Ñ-50 §¡§© §ß§Ñ§Ø§Ñ§ä§î 
	REGISTER_COMMAND_EX(iCommandPlane_LockOn_finish, 510) //§¬§Ñ-50 §¡§© §à§ä§Ø§Ñ§ä§î

	REGISTER_COMMAND(iCommandPlane_SpotLight_left)
	REGISTER_COMMAND(iCommandPlane_SpotLight_right)
	REGISTER_COMMAND(iCommandPlane_SpotLight_up)
	REGISTER_COMMAND(iCommandPlane_SpotLight_down)
	REGISTER_COMMAND_EX(iCommandPlane_SpotLight_vert_stop, 515)

	REGISTER_COMMAND(iCommandPlaneRotorTipLights)
	REGISTER_COMMAND(iCommandPlane_SpotSelect_switch)
	REGISTER_COMMAND(iCommandPlaneAntiCollisionLights)
	REGISTER_COMMAND(iCommandPlaneNavLights_CodeModeOn)
	REGISTER_COMMAND_EX(iCommandPlaneNavLights_CodeModeOff, 520)
	REGISTER_COMMAND(iCommandPlaneFormationLights)

	REGISTER_COMMAND(iCommandPlane_EngageAirDefenses)
	REGISTER_COMMAND(iCommandPlane_EngageGroundTargets)

	REGISTER_COMMAND(iCommandPlane_AutomaticTracking_Gunsight_switch)
	REGISTER_COMMAND_EX(iCommandPlane_K041_Power, 525)
	REGISTER_COMMAND(iCommandPlane_AutomaticTurn)
	REGISTER_COMMAND(iCommandPlane_GroundMovingTarget)
	REGISTER_COMMAND(iCommandPlane_AirborneTarget)
	REGISTER_COMMAND(iCommandPlane_HeadOnAspect)
	REGISTER_COMMAND_EX(iCommandPlane_ChangeDeliveryMode_right, 530)
	REGISTER_COMMAND(iCommandPlane_ChangeDeliveryMode_left)

	REGISTER_COMMAND(iCommandPlane_WeaponMode_Manual_Auto)
	REGISTER_COMMAND(iCommandPlane_WeaponMode_switch)
	REGISTER_COMMAND(iCommandPlane_AmmoTypeSelect)
	REGISTER_COMMAND(iCommandPlane_FireRate)

	REGISTER_COMMAND_EX(iCommandPlaneDropSnarOnceOff, 536)

	REGISTER_COMMAND(iCommandHelicopterHover)
	REGISTER_COMMAND(iCommandAutopilotEmergOFF)

	// HOTAS
	// §£ §Ü§Ñ§é§Ö§ã§ä§Ó§Ö Slew Control Hat Switch (TDC)
	// §Ú Weapon Release Switch §Ò§å§Õ§å§ä §Ú§ã§á§à§Ý§î§Ù§à§Ó§Ñ§ä§î§ã§ñ
	// §å§Ø§Ö §ã§å§ë§Ö§ã§ä§Ó§å§ð§ë§Ú§Ö §Ü§à§Þ§Ñ§ß§Õ§í (iCommandSelecter... §Ú
	// iCommandPlanePickleOn).
	// §³§à§à§ä§Ó§Ö§ä§ã§ä§Ó§Ö§ß§ß§à §à§ß§Ú §Õ§à§Ý§Ø§ß§í §ß§Ñ§ç§à§Õ§Ú§ä§î§ã§ñ §Ó §Ü§Ñ§ä§Ö§Ô§à§â§Ú§Ú HOTAS

	REGISTER_COMMAND(iCommandPlane_HOTAS_CoolieUp)
	REGISTER_COMMAND_EX(iCommandPlane_HOTAS_CoolieDown, 540)
	REGISTER_COMMAND(iCommandPlane_HOTAS_CoolieLeft)
	REGISTER_COMMAND(iCommandPlane_HOTAS_CoolieRight)
	REGISTER_COMMAND(iCommandPlane_HOTAS_CoolieOff)

	REGISTER_COMMAND(iCommandPlane_HOTAS_TargetManagementSwitchUp)
	REGISTER_COMMAND_EX(iCommandPlane_HOTAS_TargetManagementSwitchDown, 545)
	REGISTER_COMMAND(iCommandPlane_HOTAS_TargetManagementSwitchLeft)
	REGISTER_COMMAND(iCommandPlane_HOTAS_TargetManagementSwitchRight)
	REGISTER_COMMAND(iCommandPlane_HOTAS_TargetManagementSwitchOff)

	REGISTER_COMMAND(iCommandPlane_HOTAS_DataManagementSwitchUp)
	REGISTER_COMMAND_EX(iCommandPlane_HOTAS_DataManagementSwitchDown, 550)
	REGISTER_COMMAND(iCommandPlane_HOTAS_DataManagementSwitchLeft)
	REGISTER_COMMAND(iCommandPlane_HOTAS_DataManagementSwitchRight)
	REGISTER_COMMAND(iCommandPlane_HOTAS_DataManagementSwitchOff)

	REGISTER_COMMAND(iCommandPlane_HOTAS_TriggerSecondStage)
	REGISTER_COMMAND(iCommandPlane_HOTAS_TriggerFirstStage)

	REGISTER_COMMAND(iCommandPlane_HOTAS_CMS_Up)
	REGISTER_COMMAND(iCommandPlane_HOTAS_CMS_Down)
	REGISTER_COMMAND(iCommandPlane_HOTAS_CMS_Left)
	REGISTER_COMMAND(iCommandPlane_HOTAS_CMS_Right)
	REGISTER_COMMAND_EX(iCommandPlane_HOTAS_CMS_Off, 560)

	REGISTER_COMMAND(iCommandPlane_HOTAS_MasterModeControlButton)
	REGISTER_COMMAND(iCommandPlane_HOTAS_NoseWheelSteeringButton)

	REGISTER_COMMAND(iCommandPlane_HOTAS_BoatSwitchForward)
	REGISTER_COMMAND(iCommandPlane_HOTAS_BoatSwitchAft)
	REGISTER_COMMAND(iCommandPlane_HOTAS_BoatSwitchCenter)

	REGISTER_COMMAND(iCommandPlane_HOTAS_ChinaHatForward)
	REGISTER_COMMAND(iCommandPlane_HOTAS_ChinaHatAft)

	REGISTER_COMMAND(iCommandPlane_HOTAS_PinkySwitchForward)
	REGISTER_COMMAND(iCommandPlane_HOTAS_PinkySwitchAft)
	REGISTER_COMMAND_EX(iCommandPlane_HOTAS_PinkySwitchCenter, 570)

	REGISTER_COMMAND(iCommandPlane_HOTAS_LeftThrottleButton)

	REGISTER_COMMAND(iCommandPlane_HOTAS_MIC_SwitchUp)
	REGISTER_COMMAND(iCommandPlane_HOTAS_MIC_SwitchDown)
	REGISTER_COMMAND(iCommandPlane_HOTAS_MIC_SwitchLeft)
	REGISTER_COMMAND(iCommandPlane_HOTAS_MIC_SwitchRight)
	REGISTER_COMMAND(iCommandPlane_HOTAS_MIC_SwitchOff)

	REGISTER_COMMAND(iCommandPlane_HOTAS_SpeedBrakeSwitchForward)
	REGISTER_COMMAND(iCommandPlane_HOTAS_SpeedBrakeSwitchAft)
	REGISTER_COMMAND(iCommandPlane_HOTAS_SpeedBrakeSwitchCenter)

	REGISTER_COMMAND(iCommandPlane_ADF_Homer_change)
	REGISTER_COMMAND(iCommandPlane_ADF_Channel_next)
	REGISTER_COMMAND(iCommandPlane_ADF_Channel_prevous)
	REGISTER_COMMAND(iCommandPlane_ADF_Mode_change)
	REGISTER_COMMAND_EX(iCommandPlane_ADF_Receiver_Mode_change, 585)
	REGISTER_COMMAND(iCommandPlane_ADF_Volume_up)
	REGISTER_COMMAND(iCommandPlane_ADF_Volume_down)
	REGISTER_COMMAND(iCommandPlane_ADF_Test)

	REGISTER_COMMAND(iCommandPlane_HOTAS_ChinaHatOff)

	REGISTER_COMMAND_EX(iCommandHelicopter_PPR_button_K, 590)
	REGISTER_COMMAND(iCommandHelicopter_PPR_button_H)
	REGISTER_COMMAND(iCommandHelicopter_PPR_button_T)
	REGISTER_COMMAND(iCommandHelicopter_PPR_button_B)
	REGISTER_COMMAND(iCommandHelicopter_PPR_button_DIR)
	REGISTER_COMMAND_EX(iCommandHelicopter_PPR_BAR_RV, 595)

	REGISTER_COMMAND(iCommandHelicopter_Selected_Engine_start)
	REGISTER_COMMAND(iCommandHelicopter_Selected_Engine_interrupt_start)
	REGISTER_COMMAND(iCommandHelicopter_APU_stop)
	REGISTER_COMMAND(iCommandHelicopter_Engine_Select)

	REGISTER_COMMAND(iCommandHelicopter_Left_Engine_Lock)
	REGISTER_COMMAND(iCommandHelicopter_Right_Engine_Lock)
	REGISTER_COMMAND_EX(iCommandHelicopter_Rotor_Lock, 605)

	REGISTER_COMMAND(iCommandPlane_HOTAS_NoseWheelSteeringButtonOff)

	//REGISTER_COMMAND(iCommandViewNightVisionGogglesOff)

	REGISTER_COMMAND(iCommandPlane_R_800_1st_wheel_up)
	REGISTER_COMMAND(iCommandPlane_R_800_1st_wheel_down)
	REGISTER_COMMAND(iCommandPlane_R_800_2nd_wheel_up)
	REGISTER_COMMAND_EX(iCommandPlane_R_800_2nd_wheel_down, 610)
	REGISTER_COMMAND(iCommandPlane_R_800_3rd_wheel_up)
	REGISTER_COMMAND(iCommandPlane_R_800_3rd_wheel_down)
	REGISTER_COMMAND(iCommandPlane_R_800_4th_wheel_up)
	REGISTER_COMMAND(iCommandPlane_R_800_4th_wheel_down)
	REGISTER_COMMAND_EX(iCommandPlane_R_800_Noise_Reductor_on_off, 615)
	REGISTER_COMMAND(iCommandPlane_R_800_Modulation_change)
	REGISTER_COMMAND(iCommandPlane_R_800_50_100_switch)
	REGISTER_COMMAND(iCommandPlane_R_800_ADF_Sound_switch)
	REGISTER_COMMAND(iCommandPlane_R_800_Emergency_Radio)
	REGISTER_COMMAND_EX(iCommandPlane_R_800_Test, 620)
	REGISTER_COMMAND(iCommandPlane_R_800_Power_on_off)//§ä§å§Þ§Ò§Ý§Ö§â §µ§¬§£-2

	REGISTER_COMMAND(iCommandPlane_R_828_Channel_next)
	REGISTER_COMMAND(iCommandPlane_R_828_Channel_prevous)
	REGISTER_COMMAND(iCommandPlane_R_828_Noise_Reductor_on_off)
	REGISTER_COMMAND_EX(iCommandPlane_R_828_ASU, 625)
	REGISTER_COMMAND(iCommandPlane_R_828_volume_up)
	REGISTER_COMMAND(iCommandPlane_R_828_volume_down)
	REGISTER_COMMAND(iCommandPlane_R_828_Power_on_off)//§ä§å§Þ§Ò§Ý§Ö§â §µ§¬§£-1

	REGISTER_COMMAND(iCommandPlane_SPU9_SPU_9_on_off) //§ä§å§Þ§Ò§Ý§Ö§â §¡§£§³§¬
	REGISTER_COMMAND_EX(iCommandPlane_SPU9_radio_change, 630)

	REGISTER_COMMAND(iCommandPlaneCollectiveIncrease)  //§Õ§Ú§ã§Ü§â§Ö§ä§ß§à§Ö §å§á§â§Ñ§Ó§Ý§Ö§ß§Ú§Ö §â§å§é§Ü§à§Û §º§¡§¤-§¤§¡§©
	REGISTER_COMMAND(iCommandPlaneCollectiveDecrease)

	REGISTER_COMMAND(iCommandPlane_HOTAS_MasterModeControlButtonUP)

	REGISTER_COMMAND(iCommandPlane_HOTAS_TDC_depress_on)
	REGISTER_COMMAND_EX(iCommandPlane_HOTAS_TDC_depress_off, 635)

	REGISTER_COMMAND(iCommandPlaneStabHbarHeading)
	REGISTER_COMMAND(iCommandPlaneStabPathHold)

	REGISTER_COMMAND(iCommandPlane_HOTAS_TriggerSecondStage_Off)
	REGISTER_COMMAND(iCommandPlane_HOTAS_TriggerFirstStage_Off)

	REGISTER_COMMAND_EX(iCommandPlaneDLK_Self_ID_change, 640)
	REGISTER_COMMAND(iCommandPlaneDLK_mode_change)

	REGISTER_COMMAND_EX(iCommandPlaneLeftMFD_OSB1, 642)
	REGISTER_COMMAND(iCommandPlaneLeftMFD_OSB2)
	REGISTER_COMMAND(iCommandPlaneLeftMFD_OSB3)
	REGISTER_COMMAND(iCommandPlaneLeftMFD_OSB4)
	REGISTER_COMMAND(iCommandPlaneLeftMFD_OSB5)
	REGISTER_COMMAND(iCommandPlaneLeftMFD_OSB6)
	REGISTER_COMMAND(iCommandPlaneLeftMFD_OSB7)
	REGISTER_COMMAND(iCommandPlaneLeftMFD_OSB8)
	REGISTER_COMMAND(iCommandPlaneLeftMFD_OSB9)//650
	REGISTER_COMMAND(iCommandPlaneLeftMFD_OSB10)
	REGISTER_COMMAND(iCommandPlaneLeftMFD_OSB11)
	REGISTER_COMMAND(iCommandPlaneLeftMFD_OSB12)
	REGISTER_COMMAND(iCommandPlaneLeftMFD_OSB13)
	REGISTER_COMMAND(iCommandPlaneLeftMFD_OSB14)
	REGISTER_COMMAND(iCommandPlaneLeftMFD_OSB15)
	REGISTER_COMMAND(iCommandPlaneLeftMFD_OSB16)
	REGISTER_COMMAND(iCommandPlaneLeftMFD_OSB17)
	REGISTER_COMMAND(iCommandPlaneLeftMFD_OSB18)
	REGISTER_COMMAND(iCommandPlaneLeftMFD_OSB19)//660
	REGISTER_COMMAND(iCommandPlaneLeftMFD_OSB20)
	REGISTER_COMMAND(iCommandPlaneLeftMFD_ADJ_Increase)
	REGISTER_COMMAND(iCommandPlaneLeftMFD_ADJ_Decrease)
	REGISTER_COMMAND(iCommandPlaneLeftMFD_DSP_Increase)
	REGISTER_COMMAND(iCommandPlaneLeftMFD_DSP_Decrease)
	REGISTER_COMMAND(iCommandPlaneLeftMFD_BRT_Increase)
	REGISTER_COMMAND(iCommandPlaneLeftMFD_BRT_Decrease)
	REGISTER_COMMAND(iCommandPlaneLeftMFD_CON_Increase)
	REGISTER_COMMAND(iCommandPlaneLeftMFD_CON_Decrease)
	REGISTER_COMMAND(iCommandPlaneLeftMFD_SYM_Up)//670
	REGISTER_COMMAND(iCommandPlaneLeftMFD_SYM_Dn)

	REGISTER_COMMAND_EX(iCommandPlaneRightMFD_OSB1, 672)
	REGISTER_COMMAND(iCommandPlaneRightMFD_OSB2)
	REGISTER_COMMAND(iCommandPlaneRightMFD_OSB3)
	REGISTER_COMMAND(iCommandPlaneRightMFD_OSB4)
	REGISTER_COMMAND(iCommandPlaneRightMFD_OSB5)
	REGISTER_COMMAND(iCommandPlaneRightMFD_OSB6)
	REGISTER_COMMAND(iCommandPlaneRightMFD_OSB7)
	REGISTER_COMMAND(iCommandPlaneRightMFD_OSB8)
	REGISTER_COMMAND(iCommandPlaneRightMFD_OSB9)//680
	REGISTER_COMMAND(iCommandPlaneRightMFD_OSB10)
	REGISTER_COMMAND(iCommandPlaneRightMFD_OSB11)
	REGISTER_COMMAND(iCommandPlaneRightMFD_OSB12)
	REGISTER_COMMAND(iCommandPlaneRightMFD_OSB13)
	REGISTER_COMMAND(iCommandPlaneRightMFD_OSB14)
	REGISTER_COMMAND(iCommandPlaneRightMFD_OSB15)
	REGISTER_COMMAND(iCommandPlaneRightMFD_OSB16)
	REGISTER_COMMAND(iCommandPlaneRightMFD_OSB17)
	REGISTER_COMMAND(iCommandPlaneRightMFD_OSB18)
	REGISTER_COMMAND(iCommandPlaneRightMFD_OSB19)//690
	REGISTER_COMMAND(iCommandPlaneRightMFD_OSB20)

	REGISTER_COMMAND(iCommandPlaneRightMFD_ADJ_Increase)
	REGISTER_COMMAND(iCommandPlaneRightMFD_ADJ_Decrease)
	REGISTER_COMMAND(iCommandPlaneRightMFD_DSP_Increase)
	REGISTER_COMMAND(iCommandPlaneRightMFD_DSP_Decrease)
	REGISTER_COMMAND(iCommandPlaneRightMFD_BRT_Increase)
	REGISTER_COMMAND(iCommandPlaneRightMFD_BRT_Decrease)
	REGISTER_COMMAND(iCommandPlaneRightMFD_CON_Increase)
	REGISTER_COMMAND(iCommandPlaneRightMFD_CON_Decrease)
	REGISTER_COMMAND(iCommandPlaneRightMFD_SYM_Up)//700
	REGISTER_COMMAND(iCommandPlaneRightMFD_SYM_Dn)

	/*OBSOLETE*/	REGISTER_COMMAND(iCommandPlaneLeftMFD_OSB_OFF)
	/*OBSOLETE*/	REGISTER_COMMAND(iCommandPlaneRightMFD_OSB_OFF)

	//ELECTRIC
	REGISTER_COMMAND(iCommandGroundPowerDC)
	REGISTER_COMMAND_EX(iCommandGroundPowerDC_Cover, 705)
	REGISTER_COMMAND(iCommandPowerBattery1)
	REGISTER_COMMAND(iCommandPowerBattery1_Cover)
	REGISTER_COMMAND(iCommandPowerBattery2)
	REGISTER_COMMAND(iCommandPowerBattery2_Cover)
	REGISTER_COMMAND_EX(iCommandGroundPowerAC, 710)
	REGISTER_COMMAND(iCommandPowerGeneratorLeft)
	REGISTER_COMMAND(iCommandPowerGeneratorRight)
	REGISTER_COMMAND(iCommandElectricalPowerInverter)
	//DATALINK
	REGISTER_COMMAND(iCommandDatalinkTLK)
	REGISTER_COMMAND_EX(iCommandDatalinkUHF_TLK, 715)
	//SCRAMBLER
	REGISTER_COMMAND(iCommandDatalinkUHF_SA)

	//FUEL
	REGISTER_COMMAND(iCommandFuelPumpsTankForward)
	REGISTER_COMMAND(iCommandFuelPumpsTankRear)
	REGISTER_COMMAND(iCommandFuelExternalPumpsTanksInner)
	REGISTER_COMMAND_EX(iCommandFuelExternalPumpsTanksOuter, 720)
	REGISTER_COMMAND(iCommandFuelmeterPower)
	REGISTER_COMMAND(iCommandLeftEngineFuelValveShutOff)
	REGISTER_COMMAND(iCommandLeftEngineFuelValveShutOffCover)
	REGISTER_COMMAND(iCommandRightEngineFuelValveShutOff)
	REGISTER_COMMAND_EX(iCommandRightEngineFuelValveShutOffCover, 725)
	REGISTER_COMMAND(iCommandAPUFuelValveShutOff)
	REGISTER_COMMAND(iCommandAPUFuelValveShutOffCover)
	REGISTER_COMMAND(iCommandFuelBypassValve)
	REGISTER_COMMAND(iCommandFuelBypassValveCover)

	//EJECTING SYSTEM
	REGISTER_COMMAND_EX(iCommandEjectingSystemPower1, 730)
	REGISTER_COMMAND(iCommandEjectingSystemPower1Cover)
	REGISTER_COMMAND(iCommandEjectingSystemPower2)
	REGISTER_COMMAND(iCommandEjectingSystemPower3)

	//OTHERS
	REGISTER_COMMAND(iCommandWeaponsControlSystem)
	REGISTER_COMMAND_EX(iCommandWeaponsControlSystemCover, 735)
	REGISTER_COMMAND(iCommandMainHydraulics)
	REGISTER_COMMAND(iCommandMainHydraulicsCover)
	REGISTER_COMMAND(iCommandIFF_Power)
	REGISTER_COMMAND(iCommandIFF_PowerCover)
	REGISTER_COMMAND_EX(iCommandTargetingNavigationSystemsPower, 740)

	REGISTER_COMMAND(iCommandElectronicControlSystemLeftEngine)
	REGISTER_COMMAND(iCommandElectronicControlSystemLeftEngineCover)
	REGISTER_COMMAND(iCommandElectronicControlSystemRightEngine)
	REGISTER_COMMAND(iCommandElectronicControlSystemRightEngineCover)
	REGISTER_COMMAND_EX(iCommandHeadingMethodSwitch, 745)

	//HUD
	REGISTER_COMMAND(iCommandHUDBrightnessUp)
	REGISTER_COMMAND(iCommandHUDBrightnessDown)
	REGISTER_COMMAND(iCommandHUDTest)
	REGISTER_COMMAND(iCommandHUDTest_up)

	//GEARS
	REGISTER_COMMAND_EX(iCommandEmergencyGear, 750)
	REGISTER_COMMAND(iCommandEmergencyGearCover)

	//CLOCK
	REGISTER_COMMAND(iCommandMechClock_LeftLever_Down)
	REGISTER_COMMAND(iCommandMechClock_LeftLever_Down_up)
	REGISTER_COMMAND(iCommandMechClock_LeftLever_Up)
	REGISTER_COMMAND_EX(iCommandMechClock_LeftLever_TurnLeft, 755)
	REGISTER_COMMAND(iCommandMechClock_LeftLever_TurnRight)
	REGISTER_COMMAND(iCommandMechClock_RightLever_Down)
	REGISTER_COMMAND(iCommandMechClock_RightLever_Down_up)
	REGISTER_COMMAND(iCommandMechClock_RightLever_Rotate_left)
	REGISTER_COMMAND_EX(iCommandMechClock_RightLever_Rotate_right, 760)

	//SYSTEMs
	REGISTER_COMMAND(iCommandBKOMode)
	REGISTER_COMMAND(iCommandLampsControl)
	REGISTER_COMMAND(iCommandRotorRPMHigh)

	//HSI
	REGISTER_COMMAND(iCommandHSI_CourseRotaryLeft)
	REGISTER_COMMAND_EX(iCommandHSI_CourseRotaryRight, 765)
	REGISTER_COMMAND(iCommandHSI_HeadingRotaryLeft)
	REGISTER_COMMAND(iCommandHSI_HeadingRotaryRight)
	REGISTER_COMMAND(iCommandHSI_Test)
	REGISTER_COMMAND(iCommandHSI_Test_up)
	REGISTER_COMMAND_EX(iCommandHSI_SteeringSelection, 770)

	//ADI
	REGISTER_COMMAND(iCommandADI_ZeroPitchTrimLeft)
	REGISTER_COMMAND(iCommandADI_ZeroPitchTrimRight)
	REGISTER_COMMAND(iCommandADI_Test)
	REGISTER_COMMAND(iCommandADI_Test_up)
	REGISTER_COMMAND_EX(iCommandADI_TestCover, 775)

	//RALT
	REGISTER_COMMAND(iCommandRALT_DangerousAltitudeRotaryLeft)
	REGISTER_COMMAND(iCommandRALT_DangerousAltitudeRotaryRight)
	REGISTER_COMMAND(iCommandRALT_Test)
	REGISTER_COMMAND(iCommandRALT_Test_up)

	//UPs
	//DATALINK
	REGISTER_COMMAND_EX(iCommandPlaneDLK_Target1_up, 780)
	REGISTER_COMMAND(iCommandPlaneDLK_Target2_up)
	REGISTER_COMMAND(iCommandPlaneDLK_Target3_up)
	REGISTER_COMMAND(iCommandPlaneDLK_RefPoint_up)
	REGISTER_COMMAND(iCommandPlaneDLK_Wingman1_up)
	REGISTER_COMMAND_EX(iCommandPlaneDLK_Wingman2_up, 785)
	REGISTER_COMMAND(iCommandPlaneDLK_Wingman3_up)
	REGISTER_COMMAND(iCommandPlaneDLK_Wingman4_up)
	REGISTER_COMMAND(iCommandPlaneDLK_All_up)
	REGISTER_COMMAND(iCommandPlaneDLK_Erase_up)
	REGISTER_COMMAND_EX(iCommandPlaneDLK_Ingress_up, 790)
	REGISTER_COMMAND(iCommandPlaneDLK_SendMemory_up)
	//RADIOs
	REGISTER_COMMAND(iCommandPlane_ADF_Test_up)
	REGISTER_COMMAND(iCommandPlane_R_800_Test_up)
	REGISTER_COMMAND(iCommandPlane_R_828_ASU_up)
	//§±§£§²
	REGISTER_COMMAND_EX(iCommandPlane_AutomaticTurn_up, 795)
	REGISTER_COMMAND(iCommandPlane_GroundMovingTarget_up)
	REGISTER_COMMAND(iCommandPlane_AirborneTarget_up)
	REGISTER_COMMAND(iCommandPlane_HeadOnAspect_up)
	REGISTER_COMMAND(iCommandPlaneCancelWeaponsDelivery_up)
	//SYSTEM
	REGISTER_COMMAND_EX(iCommandLampsControl_up, 800)
	REGISTER_COMMAND(iCommandRotorRPMHigh_up)
	//ENGINES
	REGISTER_COMMAND(iCommandHelicopter_Selected_Engine_start_up)
	REGISTER_COMMAND(iCommandHelicopter_Selected_Engine_interrupt_start_up)
	REGISTER_COMMAND(iCommandHelicopter_APU_stop_up)
	//ABRIS
	REGISTER_COMMAND_EX(iCommandPlane_ABRIS_BT_1_up, 805)
	REGISTER_COMMAND(iCommandPlane_ABRIS_BT_2_up)
	REGISTER_COMMAND(iCommandPlane_ABRIS_BT_3_up)
	REGISTER_COMMAND(iCommandPlane_ABRIS_BT_4_up)
	REGISTER_COMMAND(iCommandPlane_ABRIS_BT_5_up)
	REGISTER_COMMAND_EX(iCommandPlane_ABRIS_Axis_Increase_up, 810)
	REGISTER_COMMAND(iCommandPlane_ABRIS_Axis_Decrease_up)
	REGISTER_COMMAND(iCommandPlane_ABRIS_Axis_Push_up)
	REGISTER_COMMAND(iCommandPlaneADIAHRIllumination)
	REGISTER_COMMAND(iCommandControlPanelIllumination)
	REGISTER_COMMAND_EX(iCommandCockpitIllumination, 815) //obsolete
	REGISTER_COMMAND(iCommandActivePauseOnOff) // 'Active Pause' feature

	//ENGINES CONTROL additional
	REGISTER_COMMAND(iCommandHelicopter_Engine_Launch_method)
	REGISTER_COMMAND(iCommandHelicopter_Rotor_Anti_Icing_System)
	REGISTER_COMMAND(iCommandHelicopter_Engines_Anti_Icing_Dust_Protection_System)
	REGISTER_COMMAND_EX(iCommandHelicopter_TC_RPM, 820)
	REGISTER_COMMAND(iCommandHelicopter_TC_RPM_Cover)
	REGISTER_COMMAND(iCommandHelicopter_Engine_Temperature_Control)
	REGISTER_COMMAND(iCommandHelicopter_Engine_Temperature_Control_Cover)

	REGISTER_COMMAND(iCommandHelicopter_SelectWeapon_Internal)
	REGISTER_COMMAND_EX(iCommandHelicopter_SelectWeapon_External, 825)
	REGISTER_COMMAND(iCommandHelicopter_SelectWeapon_ALL)
	REGISTER_COMMAND(iCommandHelicopter_SelectWeapon_AA)

	REGISTER_COMMAND(iCommandHelicopter_SignalFlares_switch_OnOff)
	REGISTER_COMMAND(iCommandHelicopter_SignalFlares_GREEN)
	REGISTER_COMMAND_EX(iCommandHelicopter_SignalFlares_RED, 830)
	REGISTER_COMMAND(iCommandHelicopter_SignalFlares_WHITE)
	REGISTER_COMMAND(iCommandHelicopter_SignalFlares_YELLOW)

	REGISTER_COMMAND(iCommandHelicopter_PanelsIlluminationButtonDown)
	REGISTER_COMMAND(iCommandHelicopter_PanelsIlluminationButtonUp)

	REGISTER_COMMAND_EX(iCommandCockpitShowPilotOnOff, 835)

	REGISTER_COMMAND(iCommandEasyRadarScaleUp)
	REGISTER_COMMAND(iCommandEasyRadarScaleOut)

	REGISTER_COMMAND(iCommandEngineLaunchMethod)

	REGISTER_COMMAND(iCommandPlaneCollectiveStop)

	REGISTER_COMMAND_EX(iCommandPlane_Helmet_Brightess_Up, 840)
	REGISTER_COMMAND(iCommandPlane_Helmet_Brightess_Down)

	REGISTER_COMMAND(iCommandPlane_I251_Brightness_Up)
	REGISTER_COMMAND(iCommandPlane_I251_Brightness_Down)

	REGISTER_COMMAND(iCommandPlane_I251_Contrast_Up)
	REGISTER_COMMAND_EX(iCommandPlane_I251_Contrast_Down, 845)

	REGISTER_COMMAND(iCommandPlane_I251_Background_WhiteBlack)

	REGISTER_COMMAND(iCommandPlane_LaserCode_Next)
	REGISTER_COMMAND(iCommandPlane_LaserCode_Previous)

	REGISTER_COMMAND(iCommandReloadTables)			// §±§Ö§â§Ö§Ù§Ñ§Ô§â§å§Ù§Ú§ä§î §ä§Ñ§Ò§Ý§Ú§è§í. §³§å§Ô§å§Ò§à §à§ä§Ý§Ñ§Õ§à§é§ß§Ñ§ñ §Ü§à§Þ§Ñ§ß§Õ§Ñ.

	REGISTER_COMMAND_EX(iCommandPlane_JettisonMode_explosion, 850)
	REGISTER_COMMAND(iCommandPlane_ShowControls)

	REGISTER_COMMAND(iCommandPlane_CallHelpWindow)

	// §±§Ö§â§Ö§ß§Ñ§ã§ä§â§à§Û§Ü§Ñ §à§Ò§à§â§à§ä§à§Ó §ã§Ó§à§Ò§à§Õ§ß§à§Û §ä§å§â§Ò§Ú§ß§í ("§¯§à§Þ§Ú§ß. - §¯§Ú§Ù§Ü.")
	REGISTER_COMMAND(iCommandPlane_ReadjustFreeTurbineRPM_Up)
	REGISTER_COMMAND(iCommandPlane_ReadjustFreeTurbineRPM_Down)

	REGISTER_COMMAND_EX(iCommandPlaneWheelParkingBrake, 855)	// §ã§ä§à§ñ§ß§à§é§ß§í§Û §ä§à§â§Þ§à§Ù §Ü§à§Ý§Ö§ã

	REGISTER_COMMAND(iCommandHelicopter_CollectiveStopper_Up)
	REGISTER_COMMAND(iCommandHelicopter_CollectiveStopper_Down)

	REGISTER_COMMAND(iCommandPlaneNav_PB0_off)
	REGISTER_COMMAND(iCommandPlaneNav_PB1_off)
	REGISTER_COMMAND_EX(iCommandPlaneNav_PB2_off, 860)
	REGISTER_COMMAND(iCommandPlaneNav_PB3_off)
	REGISTER_COMMAND(iCommandPlaneNav_PB4_off)
	REGISTER_COMMAND(iCommandPlaneNav_PB5_off)
	REGISTER_COMMAND(iCommandPlaneNav_PB6_off)
	REGISTER_COMMAND(iCommandPlaneNav_PB7_off)
	REGISTER_COMMAND(iCommandPlaneNav_PB8_off)
	REGISTER_COMMAND(iCommandPlaneNav_PB9_off)


	REGISTER_COMMAND(iCommandPlaneNav_Steerpoints_off)
	REGISTER_COMMAND(iCommandPlaneNav_INU_realign_off)
	REGISTER_COMMAND_EX(iCommandPlaneNav_POS_corrMode_off, 870)
	REGISTER_COMMAND(iCommandPlaneNav_INU_precise_align_off)
	REGISTER_COMMAND(iCommandPlaneNav_Airfields_off)
	REGISTER_COMMAND(iCommandPlaneNav_INU_normal_align_off)
	REGISTER_COMMAND(iCommandPlaneNav_Targets_off)
	REGISTER_COMMAND(iCommandPlaneNav_Enter_off)
	REGISTER_COMMAND(iCommandPlaneNav_Cancel_off)
	REGISTER_COMMAND(iCommandPlaneNav_POS_init_off)
	REGISTER_COMMAND(iCommandPlaneNav_SelfCoord_off)
	REGISTER_COMMAND(iCommandPlaneNav_CourseTimeRange_off)
	REGISTER_COMMAND_EX(iCommandPlaneNav_Wind_off, 880)
	REGISTER_COMMAND(iCommandPlaneNav_THeadingTimeRangeF_off)
	REGISTER_COMMAND(iCommandPlaneNav_BearingRangeT_off)

	//§Ó§Ö§â§ç§ß§ñ§ñ §Ý§Ö§Ó§Ñ§ñ §á§Ñ§ß§Ö§Ý§î
	REGISTER_COMMAND(iCommand_CPT_MECH_WindscreenWiper_Speed)
	REGISTER_COMMAND(iCommandAccelReset)
	// LWS
	REGISTER_COMMAND(iCommand_LWS_Reset)
	// LaseRanger
	REGISTER_COMMAND(iCommandLaserRangeModeSwitchCover)
	REGISTER_COMMAND(iCommandLaserRangeModeSwitch)
	REGISTER_COMMAND(iCommandLaserRangeReset)
	// AGR
	REGISTER_COMMAND(iCommand_AGR_Power)
	REGISTER_COMMAND_EX(iCommand_WEAP_INTERF_MasterSimulate, 890)
	REGISTER_COMMAND(iCommand_CPT_MECH_VMG_HYDRO_EKRAN_Cover)
	REGISTER_COMMAND(iCommand_CPT_MECH_VMG_HYDRO_EKRAN)
	REGISTER_COMMAND(iCommand_LWS_BIT_On)
	REGISTER_COMMAND(iCommand_IlluminationInterf_Control_Panel_Illumination)
	REGISTER_COMMAND(iCommand_LWS_Power)
	REGISTER_COMMAND(iCommand_UV26_PowerCover)
	REGISTER_COMMAND(iCommand_UV26_Power)
	REGISTER_COMMAND(iCommand_UV26_BITCover)
	REGISTER_COMMAND(iCommand_UV26_BIT)
	REGISTER_COMMAND_EX(iCommand_C061K_power, 900)
	REGISTER_COMMAND(iCommand_C061K_heat)
	REGISTER_COMMAND(iCommand_VMS_ALMAZ_UP_Check)
	REGISTER_COMMAND(iCommand_EjectInterface_Circuit_Test)
	REGISTER_COMMAND(iCommand_ENG_INTERF_Right_Engine_RT_12_6)
	REGISTER_COMMAND(iCommand_ENG_INTERF_Left_Engine_RT_12_6)
	REGISTER_COMMAND(iCommand_ENG_INTERF_EngVibrDetectorBIT)

	REGISTER_COMMAND(iCommand_ENG_INTERF_TempIndTestwRunningEng)
	REGISTER_COMMAND(iCommand_ENG_INTERF_TempIndTestwStoppedEng)

	REGISTER_COMMAND(iCommand_FuelSysInterf_FuelQuantityIndTestOn)

	REGISTER_COMMAND_EX(iCommandPitotAoAHeat, 910)
	REGISTER_COMMAND(iCommandPitotRam)
	REGISTER_COMMAND(iCommandHelicopter_Rotor_Anti_Icing_Dust_Protection_System)

	REGISTER_COMMAND(iCommand_VMS_ALMAZ_UP_EmergencyOn)
	REGISTER_COMMAND(iCommand_VMS_ALMAZ_UP_SpeechInfoOff)
	REGISTER_COMMAND(iCommand_VMS_ALMAZ_UP_Repeat)

	REGISTER_COMMAND(iCommand_SHKVAL_scan_vel_up)
	REGISTER_COMMAND(iCommand_SHKVAL_scan_vel_down)
	REGISTER_COMMAND(iCommand_SHKVAL_windscreen_wiper)
	REGISTER_COMMAND(iCommand_PVI_BRIGHTNESS_LEVER_up)
	REGISTER_COMMAND_EX(iCommand_PVI_BRIGHTNESS_LEVER_down, 920)
	REGISTER_COMMAND(iCommand_FireExting_LeftEngineExting)
	REGISTER_COMMAND(iCommand_FireExting_APUExting)
	REGISTER_COMMAND(iCommand_FireExting_RightEngineExting)
	REGISTER_COMMAND(iCommand_FireExting_VentilatorExting)
	REGISTER_COMMAND(iCommand_FireExting_ExtinguishersToDown)
	REGISTER_COMMAND(iCommand_FireExting_ExtinguishersCover)
	REGISTER_COMMAND(iCommand_FireExting_Signals)
	REGISTER_COMMAND(iCommand_FireExting_Reservoirs)
	REGISTER_COMMAND(iCommand_FireExting_ReservoirsCover)
	REGISTER_COMMAND_EX(iCommand_IlluminationInterf_Cockpit_Illumination, 930)
	REGISTER_COMMAND(iCommand_FireExting_TestGroups)

	REGISTER_COMMAND(iCommand_AGR_Test)
	REGISTER_COMMAND(iCommand_AGR_Oriet)
	REGISTER_COMMAND(iCommand_AGR_axis_left)
	REGISTER_COMMAND(iCommand_AGR_axis_right)
	REGISTER_COMMAND(iCommand_IlluminationInterf_Cockpit_Night_Illumination_brightness_up)
	REGISTER_COMMAND(iCommand_IlluminationInterf_Cockpit_Night_Illumination_brightness_down)
	REGISTER_COMMAND(iCommand_IlluminationInterf_Panels_Illumination_brightness_up)
	REGISTER_COMMAND(iCommand_IlluminationInterf_Panels_Illumination_brightness_down)
	REGISTER_COMMAND_EX(iCommand_IlluminationInterf_ADI_AHR_Illumination_brightness_up, 940)
	REGISTER_COMMAND(iCommand_IlluminationInterf_ADI_AHR_Illumination_brightness_down)
	REGISTER_COMMAND(iCommand_IlluminationInterf_Control_Panel_Illumination_brightness_up)
	REGISTER_COMMAND(iCommand_IlluminationInterf_Control_Panel_Illumination_brightness_down)
	REGISTER_COMMAND(iCommand_NAVINTERF_HeadingCourse)

	REGISTER_COMMAND(iCommandPlaneDLK_None)
	REGISTER_COMMAND(iCommandPlaneDLK_None_up)

	REGISTER_COMMAND(iCommandWeaponsBallisticSelectorRight)
	REGISTER_COMMAND(iCommandWeaponsBallisticSelectorLeft)

	REGISTER_COMMAND(iCommand_ZMS_3_MagVarRotaryRight)
	REGISTER_COMMAND_EX(iCommand_ZMS_3_MagVarRotaryLeft, 950)

	REGISTER_COMMAND(iCommand_EjectInterface_Circuit_SelectRight)
	REGISTER_COMMAND(iCommand_EjectInterface_Circuit_SelectLeft)

	REGISTER_COMMAND(iCommand_CPT_MECH_PitotSystemHeatTest)


	REGISTER_COMMAND(iCommand_FireDetectorsTest1stGroup)
	REGISTER_COMMAND(iCommand_FireDetectorsTest2ndGroup)
	REGISTER_COMMAND(iCommand_FireDetectorsTest3rdGroup)


	REGISTER_COMMAND(iCommandPlaneTrimOn)					// §¯§Ñ§Ø§Ñ§ä§î §Ü§ß§à§á§Ü§å §ä§â§Ú§Þ§Þ§Ö§â§Ñ (§Ó§Ö§â§ä§à§Ý§Ö§ä §Ú§Ý§Ú §á§Ö§â§Ö§Ó§à§Õ §²§µ§³ §Ó §â§Ö§Ø§Ú§Þ §Ü§ß§ð§á§Ö§Ý§ñ §ä§â§Ú§Þ§Þ§Ö§â§Ñ)
	REGISTER_COMMAND(iCommandPlaneTrimOff)					// §°§ä§Ø§Ñ§ä§î §Ü§ß§à§á§Ü§å §ä§â§Ú§Þ§Þ§Ö§â§Ñ

	REGISTER_COMMAND(iCommandPlaneLevitation)

	REGISTER_COMMAND_EX(iCommandPlaneEmergencyBrake, 960)
	REGISTER_COMMAND(iCommandPlaneWheelBrakeLeftOn)			// §£§Ü§Ý§ð§é§Ö§ß§Ú§Ö §ä§à§â§Þ§à§Ù§Ñ §Ý§Ö§Ó§à§Ô§à §Ü§à§Ý§Ö§ã§Ñ
	REGISTER_COMMAND(iCommandPlaneWheelBrakeLeftOff)		// §£§í§Ü§Ý§ð§é§Ö§ß§Ú§Ö §ä§à§â§Þ§à§Ù§Ñ §Ý§Ö§Ó§à§Ô§à §Ü§à§Ý§Ö§ã§Ñ
	REGISTER_COMMAND(iCommandPlaneWheelBrakeRightOn)		// §£§Ü§Ý§ð§é§Ö§ß§Ú§Ö §ä§à§â§Þ§à§Ù§Ñ §á§â§Ñ§Ó§à§Ô§à §Ü§à§Ý§Ö§ã§Ñ
	REGISTER_COMMAND(iCommandPlaneWheelBrakeRightOff)		// §£§í§Ü§Ý§ð§é§Ö§ß§Ú§Ö §ä§à§â§Þ§à§Ù§Ñ §á§â§Ñ§Ó§à§Ô§à §Ü§à§Ý§Ö§ã§Ñ
	REGISTER_COMMAND(iCommandPlaneEmergencyDisconnectLever)

	//Command menu items
	REGISTER_COMMAND(ICommandMenuItem1)
	REGISTER_COMMAND(ICommandMenuItem2)
	REGISTER_COMMAND(ICommandMenuItem3)
	REGISTER_COMMAND(ICommandMenuItem4)
	REGISTER_COMMAND(ICommandMenuItem5)//970
	REGISTER_COMMAND(ICommandMenuItem6)
	REGISTER_COMMAND(ICommandMenuItem7)
	REGISTER_COMMAND(ICommandMenuItem8)
	REGISTER_COMMAND(ICommandMenuItem9)
	REGISTER_COMMAND(ICommandMenuItem10)
	REGISTER_COMMAND(ICommandMenuItem11)
	REGISTER_COMMAND(ICommandMenuItem12)
	REGISTER_COMMAND(ICommandMenuExit)

	//Command dialogs panel commands
	REGISTER_COMMAND(ICommandSwitchDialog)
	REGISTER_COMMAND_EX(ICommandSwitchToCommonDialog, 980)

	REGISTER_COMMAND(ICommandToggleConsole)


	REGISTER_COMMAND_EX(iCommandPlaneLeftMFD_OSB1_Off, 982)
	REGISTER_COMMAND(iCommandPlaneLeftMFD_OSB2_Off)
	REGISTER_COMMAND(iCommandPlaneLeftMFD_OSB3_Off)
	REGISTER_COMMAND(iCommandPlaneLeftMFD_OSB4_Off)
	REGISTER_COMMAND(iCommandPlaneLeftMFD_OSB5_Off)
	REGISTER_COMMAND(iCommandPlaneLeftMFD_OSB6_Off)
	REGISTER_COMMAND(iCommandPlaneLeftMFD_OSB7_Off)
	REGISTER_COMMAND(iCommandPlaneLeftMFD_OSB8_Off)
	REGISTER_COMMAND(iCommandPlaneLeftMFD_OSB9_Off)//990
	REGISTER_COMMAND(iCommandPlaneLeftMFD_OSB10_Off)
	REGISTER_COMMAND(iCommandPlaneLeftMFD_OSB11_Off)
	REGISTER_COMMAND(iCommandPlaneLeftMFD_OSB12_Off)
	REGISTER_COMMAND(iCommandPlaneLeftMFD_OSB13_Off)
	REGISTER_COMMAND(iCommandPlaneLeftMFD_OSB14_Off)
	REGISTER_COMMAND(iCommandPlaneLeftMFD_OSB15_Off)
	REGISTER_COMMAND(iCommandPlaneLeftMFD_OSB16_Off)
	REGISTER_COMMAND(iCommandPlaneLeftMFD_OSB17_Off)
	REGISTER_COMMAND(iCommandPlaneLeftMFD_OSB18_Off)
	REGISTER_COMMAND_EX(iCommandPlaneLeftMFD_OSB19_Off, 1000)//1000 Get!!!!!!
	REGISTER_COMMAND(iCommandPlaneLeftMFD_OSB20_Off)

	REGISTER_COMMAND(iCommandPlaneLeftMFD_ADJ_Stop)
	REGISTER_COMMAND(iCommandPlaneLeftMFD_DSP_Stop)
	REGISTER_COMMAND(iCommandPlaneLeftMFD_BRT_Stop)
	REGISTER_COMMAND(iCommandPlaneLeftMFD_CON_Stop)
	REGISTER_COMMAND(iCommandPlaneLeftMFD_SYM_Stop)

	REGISTER_COMMAND_EX(iCommandPlaneRightMFD_OSB1_Off, 1007)
	REGISTER_COMMAND(iCommandPlaneRightMFD_OSB2_Off)
	REGISTER_COMMAND(iCommandPlaneRightMFD_OSB3_Off)
	REGISTER_COMMAND(iCommandPlaneRightMFD_OSB4_Off)//1010
	REGISTER_COMMAND(iCommandPlaneRightMFD_OSB5_Off)
	REGISTER_COMMAND(iCommandPlaneRightMFD_OSB6_Off)
	REGISTER_COMMAND(iCommandPlaneRightMFD_OSB7_Off)
	REGISTER_COMMAND(iCommandPlaneRightMFD_OSB8_Off)
	REGISTER_COMMAND(iCommandPlaneRightMFD_OSB9_Off)
	REGISTER_COMMAND(iCommandPlaneRightMFD_OSB10_Off)
	REGISTER_COMMAND(iCommandPlaneRightMFD_OSB11_Off)
	REGISTER_COMMAND(iCommandPlaneRightMFD_OSB12_Off)
	REGISTER_COMMAND(iCommandPlaneRightMFD_OSB13_Off)
	REGISTER_COMMAND(iCommandPlaneRightMFD_OSB14_Off)//1020
	REGISTER_COMMAND(iCommandPlaneRightMFD_OSB15_Off)
	REGISTER_COMMAND(iCommandPlaneRightMFD_OSB16_Off)
	REGISTER_COMMAND(iCommandPlaneRightMFD_OSB17_Off)
	REGISTER_COMMAND(iCommandPlaneRightMFD_OSB18_Off)
	REGISTER_COMMAND(iCommandPlaneRightMFD_OSB19_Off)
	REGISTER_COMMAND(iCommandPlaneRightMFD_OSB20_Off)

	REGISTER_COMMAND(iCommandPlaneRightMFD_ADJ_Stop)
	REGISTER_COMMAND(iCommandPlaneRightMFD_DSP_Stop)
	REGISTER_COMMAND(iCommandPlaneRightMFD_BRT_Stop)
	REGISTER_COMMAND(iCommandPlaneRightMFD_CON_Stop)//1030
	REGISTER_COMMAND(iCommandPlaneRightMFD_SYM_Stop)

	REGISTER_COMMAND(iCommandThrottleIncrease) //§Ü§Ý§Ñ§Ó§Ú§Ñ§ä§å§â§ß§à§Ö "§á§Ý§Ñ§Ó§ß§à§Ö" §å§á§â§Ñ§Ó§Ý§Ö§ß§Ú§Ö §²§µ§¥
	REGISTER_COMMAND(iCommandThrottleDecrease)
	REGISTER_COMMAND(iCommandThrottleStop)
	REGISTER_COMMAND(iCommandThrottle1Increase)
	REGISTER_COMMAND(iCommandThrottle1Decrease)
	REGISTER_COMMAND(iCommandThrottle1Stop)
	REGISTER_COMMAND(iCommandThrottle2Increase)
	REGISTER_COMMAND(iCommandThrottle2Decrease)
	REGISTER_COMMAND_EX(iCommandThrottle2Stop, 1040)

	REGISTER_COMMAND(iCommandPlane_HOTAS_CMS_Zaxis)
	REGISTER_COMMAND(iCommandPlane_HOTAS_CMS_Zaxis_Off)

	REGISTER_COMMAND(iCommandViewJFO) //§Ü§Ñ§Þ§Ö§â§Ñ §á§â§Ú§Ó§ñ§Ù§Ñ§ß§ß§Ñ§ñ §Ü §ð§ß§Ú§ä§å
	REGISTER_COMMAND(iCommandViewSmoke1) //§¥§í§Þ§í §ß§Ñ§Ó§à§Õ§é§Ú§Ü§Ñ
	REGISTER_COMMAND(iCommandViewSmoke2)
	REGISTER_COMMAND(iCommandViewSmoke3)

	REGISTER_COMMAND(iCommandPlane_FLAPS_UP)
	REGISTER_COMMAND(iCommandPlane_FLAPS_MNR)
	REGISTER_COMMAND(iCommandPlane_FLAPS_DN)

	//LASTE control panel
	REGISTER_COMMAND_EX(iCommandPlane_EAC_ARM, 1050)
	REGISTER_COMMAND(iCommandPlane_EAC_OFF)

	REGISTER_COMMAND(iCommandPlane_RDR_ALTM_NRM)
	REGISTER_COMMAND(iCommandPlane_RDR_ALTM_DIS)

	//ENGINE Control Panel
	REGISTER_COMMAND(iCommandPlane_LG_WRN_Silence)
	REGISTER_COMMAND(iCommandPlane_APU_Start)
	REGISTER_COMMAND(iCommandPlane_APU_Off)

	REGISTER_COMMAND(iCommandPlane_L_ENG_OPER_Ign)
	REGISTER_COMMAND(iCommandPlane_L_ENG_OPER_Norm)
	REGISTER_COMMAND(iCommandPlane_L_ENG_OPER_Motor)

	REGISTER_COMMAND_EX(iCommandPlane_R_ENG_OPER_Ign, 1060)
	REGISTER_COMMAND(iCommandPlane_R_ENG_OPER_Norm)
	REGISTER_COMMAND(iCommandPlane_R_ENG_OPER_Motor)

	REGISTER_COMMAND(iCommandPlane_L_ENG_FUEL_FLOW_Norm)
	REGISTER_COMMAND(iCommandPlane_L_ENG_FUEL_FLOW_Override)

	REGISTER_COMMAND_EX(iCommandPlane_R_ENG_FUEL_FLOW_Norm, 1065)
	REGISTER_COMMAND(iCommandPlane_R_ENG_FUEL_FLOW_Override)

	REGISTER_COMMAND(iCommandPlaneQuickPadlockOn)
	REGISTER_COMMAND(iCommandPlaneQuickPadlockOff)
	REGISTER_COMMAND(iCommandPlaneThrottleFrictionDec)
	REGISTER_COMMAND(iCommandPlaneThrottleFrictionInc)

	//A10 - Electrical power control panel
	REGISTER_COMMAND(iCommandAPUGeneratorPower)
	REGISTER_COMMAND(iCommandEmergencyFlood)
	REGISTER_COMMAND(iCommandBatteryPower)
	REGISTER_COMMAND(iCommandElectricalPowerInverterSTBY)
	REGISTER_COMMAND(iCommandElectricalPowerInverterOFF)
	REGISTER_COMMAND(iCommandElectricalPowerInverterTEST)
	//A10 - Electrical circuit breakers
	//A10 - Fuel system control panel
	REGISTER_COMMAND(iCommandPlaneFSExtTanksWingValve)
	REGISTER_COMMAND(iCommandPlaneFSExtTanksFuselageValve)
	REGISTER_COMMAND(iCommandPlaneFSSigAmplifier)
	REGISTER_COMMAND(iCommandPlaneFSLineCheck)
	REGISTER_COMMAND(iCommandPlaneFSTankGate)
	REGISTER_COMMAND(iCommandPlaneFSTankCrossFeed)
	REGISTER_COMMAND(iCommandPlaneFSLeftWingBoostPump)
	REGISTER_COMMAND(iCommandPlaneFSRightWingBoostPump)
	REGISTER_COMMAND(iCommandPlaneFSLeftWingFillDisable)
	REGISTER_COMMAND(iCommandPlaneFSRightWingFillDisable)
	REGISTER_COMMAND(iCommandPlaneFSLeftMainBoostPump)
	REGISTER_COMMAND(iCommandPlaneFSRightMainBoostPump)
	REGISTER_COMMAND(iCommandPlaneFSLeftMainFillDisable)
	REGISTER_COMMAND(iCommandPlaneFSRightMainFillDisable)
	REGISTER_COMMAND(iCommandPlaneFSReceiverLever)
	REGISTER_COMMAND(iCommandPlaneFSQuantityIndicatorSelectorINT)
	REGISTER_COMMAND(iCommandPlaneFSQuantityIndicatorSelectorMAIN)
	REGISTER_COMMAND(iCommandPlaneFSQuantityIndicatorSelectorWING)
	REGISTER_COMMAND(iCommandPlaneFSQuantityIndicatorSelectorEXTWING)
	REGISTER_COMMAND(iCommandPlaneFSQuantityIndicatorSelectorEXTCTR)
	REGISTER_COMMAND(iCommandPlaneFSQuantityIndicatorTest)
	REGISTER_COMMAND(iCommandPlaneFSRefuelLigtingDecrease)
	REGISTER_COMMAND(iCommandPlaneFSRefuelLigtingIncrease)
	//A10 - Emergency flight control panel
	REGISTER_COMMAND(iCommandPlaneEmerSpeedBrakeRetract)
	REGISTER_COMMAND(iCommandPlaneEmerPitchRollTrim)
	REGISTER_COMMAND(iCommandPlaneEmerTrimNoseDn)
	REGISTER_COMMAND(iCommandPlaneEmerTrimLWingDn)
	REGISTER_COMMAND(iCommandPlaneEmerTrimRWingDn)
	REGISTER_COMMAND(iCommandPlaneEmerTrimNoseUP)
	REGISTER_COMMAND(iCommandPlaneEmerTrimNeutral)
	REGISTER_COMMAND(iCommandPlaneEmerAileronDisengageL)
	REGISTER_COMMAND(iCommandPlaneEmerAileronDisengageOff)
	REGISTER_COMMAND(iCommandPlaneEmerAileronDisengageR)
	REGISTER_COMMAND(iCommandPlaneEmerElevatorDisengageL)
	REGISTER_COMMAND(iCommandPlaneEmerElevatorDisengageOff)
	REGISTER_COMMAND(iCommandPlaneEmerElevatorDisengageR)
	REGISTER_COMMAND(iCommandPlaneEmerFlapsRetract)
	REGISTER_COMMAND(iCommandPlaneEmerFlightControl)
	//A10 - Circuit breaker panel
	REGISTER_COMMAND(iCommandPlaneCircuitBreaker_1)
	REGISTER_COMMAND(iCommandPlaneCircuitBreaker_2)
	REGISTER_COMMAND(iCommandPlaneCircuitBreaker_3)
	REGISTER_COMMAND(iCommandPlaneCircuitBreaker_4)
	REGISTER_COMMAND(iCommandPlaneCircuitBreaker_5)
	REGISTER_COMMAND(iCommandPlaneCircuitBreaker_6)
	REGISTER_COMMAND(iCommandPlaneCircuitBreaker_7)
	REGISTER_COMMAND(iCommandPlaneCircuitBreaker_8)
	REGISTER_COMMAND(iCommandPlaneCircuitBreaker_9)
	REGISTER_COMMAND(iCommandPlaneCircuitBreaker_10)
	REGISTER_COMMAND(iCommandPlaneCircuitBreaker_11)
	REGISTER_COMMAND(iCommandPlaneCircuitBreaker_12)
	REGISTER_COMMAND(iCommandPlaneCircuitBreaker_13)
	REGISTER_COMMAND(iCommandPlaneCircuitBreaker_14)
	REGISTER_COMMAND(iCommandPlaneCircuitBreaker_15)
	REGISTER_COMMAND(iCommandPlaneCircuitBreaker_16)
	REGISTER_COMMAND(iCommandPlaneCircuitBreaker_17)
	REGISTER_COMMAND(iCommandPlaneCircuitBreaker_18)
	REGISTER_COMMAND(iCommandPlaneCircuitBreaker_19)
	REGISTER_COMMAND(iCommandPlaneCircuitBreaker_20)
	REGISTER_COMMAND(iCommandPlaneCircuitBreaker_21)
	REGISTER_COMMAND(iCommandPlaneCircuitBreaker_22)
	REGISTER_COMMAND(iCommandPlaneCircuitBreaker_23)
	REGISTER_COMMAND(iCommandPlaneCircuitBreaker_24)
	REGISTER_COMMAND(iCommandPlaneCircuitBreaker_25)
	REGISTER_COMMAND(iCommandPlaneCircuitBreaker_26)
	REGISTER_COMMAND(iCommandPlaneCircuitBreaker_27)
	REGISTER_COMMAND(iCommandPlaneCircuitBreaker_28)
	REGISTER_COMMAND(iCommandPlaneCircuitBreaker_29)
	REGISTER_COMMAND(iCommandPlaneCircuitBreaker_30)
	REGISTER_COMMAND(iCommandPlaneCircuitBreaker_31)
	REGISTER_COMMAND(iCommandPlaneCircuitBreaker_32)
	REGISTER_COMMAND(iCommandPlaneCircuitBreaker_33)
	REGISTER_COMMAND(iCommandPlaneCircuitBreaker_34)
	REGISTER_COMMAND(iCommandPlaneCircuitBreaker_35)
	REGISTER_COMMAND(iCommandPlaneCircuitBreaker_36)
	REGISTER_COMMAND(iCommandPlaneCircuitBreaker_37)
	REGISTER_COMMAND(iCommandPlaneCircuitBreaker_38)
	//A-10 Stability Augmentation system panel
	REGISTER_COMMAND(iCommandPlaneYawSASEngageL)
	REGISTER_COMMAND(iCommandPlaneYawSASEngageR)
	REGISTER_COMMAND(iCommandPlanePitchSASEngageL)
	REGISTER_COMMAND(iCommandPlanePitchSASEngageR)
	REGISTER_COMMAND(iCommandPlaneSASMonitorTestLeft)
	REGISTER_COMMAND(iCommandPlaneSASMonitorTestOff)
	REGISTER_COMMAND(iCommandPlaneSASMonitorTestRight)
	REGISTER_COMMAND(iCommandPlaneSASTakeOffTrim)
	//A-10 Inercom control panel
	REGISTER_COMMAND(iCommandPlaneIntercomINTDecrease)
	REGISTER_COMMAND(iCommandPlaneIntercomINTIncrease)
	REGISTER_COMMAND(iCommandPlaneIntercomINTPress)
	REGISTER_COMMAND(iCommandPlaneIntercomFMDecrease)
	REGISTER_COMMAND(iCommandPlaneIntercomFMIncrease)
	REGISTER_COMMAND(iCommandPlaneIntercomFMPress)
	REGISTER_COMMAND(iCommandPlaneIntercomVHFDecrease)
	REGISTER_COMMAND(iCommandPlaneIntercomVHFIncrease)
	REGISTER_COMMAND(iCommandPlaneIntercomVHFPress)
	REGISTER_COMMAND(iCommandPlaneIntercomUHFDecrease)
	REGISTER_COMMAND(iCommandPlaneIntercomUHFIncrease)
	REGISTER_COMMAND(iCommandPlaneIntercomUHFPress)
	REGISTER_COMMAND(iCommandPlaneIntercomAIMDecrease)
	REGISTER_COMMAND(iCommandPlaneIntercomAIMIncrease)
	REGISTER_COMMAND(iCommandPlaneIntercomAIMPress)
	REGISTER_COMMAND(iCommandPlaneIntercomIFFDecrease)
	REGISTER_COMMAND(iCommandPlaneIntercomIFFIncrease)
	REGISTER_COMMAND(iCommandPlaneIntercomIFFPress)
	REGISTER_COMMAND(iCommandPlaneIntercomILSDecrease)
	REGISTER_COMMAND(iCommandPlaneIntercomILSIncrease)
	REGISTER_COMMAND(iCommandPlaneIntercomILSPress)
	REGISTER_COMMAND(iCommandPlaneIntercomTCNDecrease)
	REGISTER_COMMAND(iCommandPlaneIntercomTCNIncrease)
	REGISTER_COMMAND(iCommandPlaneIntercomTCNPress)
	REGISTER_COMMAND(iCommandPlaneIntercomVolumeDecrease)
	REGISTER_COMMAND(iCommandPlaneIntercomVolumeIncrease)
	REGISTER_COMMAND(iCommandPlaneIntercomHM)
	REGISTER_COMMAND(iCommandPlaneIntercomINT)
	REGISTER_COMMAND(iCommandPlaneIntercomVHF)
	REGISTER_COMMAND(iCommandPlaneIntercomFM)
	REGISTER_COMMAND(iCommandPlaneIntercomHF)
	//A-10 Auxiliary lighting control panel
	REGISTER_COMMAND(iCommandPlaneRefuelStatusIndLTSDecrease)
	REGISTER_COMMAND(iCommandPlaneRefuelStatusIndLTSIncrease)
	REGISTER_COMMAND(iCommandPlaneNightVisionLTSTCP)
	REGISTER_COMMAND(iCommandPlaneNightVisionLTSALL)
	REGISTER_COMMAND(iCommandPlaneNightVisionLTSOFF)
	//REGISTER_COMMAND   (iCommandPlaneWeaponStationLTSOff) //NOT IMPL IN SYSTEM
	//REGISTER_COMMAND   (iCommandPlaneWeaponStationLTSBrt) //NOT IMPL IN SYSTEM
	REGISTER_COMMAND(iCommandPlaneHarsSasNormOverride)
	REGISTER_COMMAND(iCommandPlaneFireDetectBleedAirTest)
	//A-10 UHF Radio
	REGISTER_COMMAND(iCommandPlaneUHFPresetChannelSelectorInc)
	REGISTER_COMMAND(iCommandPlaneUHFPresetChannelSelectorDec)
	REGISTER_COMMAND(iCommandPlaneUHF100MhzSelector1)
	REGISTER_COMMAND(iCommandPlaneUHF100MhzSelector2)
	REGISTER_COMMAND(iCommandPlaneUHF100MhzSelector3)
	REGISTER_COMMAND(iCommandPlaneUHF100MhzSelectorA)
	REGISTER_COMMAND(iCommandPlaneUHF10MhzSelectorInc)
	REGISTER_COMMAND(iCommandPlaneUHF10MhzSelectorDec)
	REGISTER_COMMAND(iCommandPlaneUHF1MhzSelectorInc)
	REGISTER_COMMAND(iCommandPlaneUHF1MhzSelectorDec)
	REGISTER_COMMAND(iCommandPlaneUHF01MhzSelectorInc)
	REGISTER_COMMAND(iCommandPlaneUHF01MhzSelectorDec)
	REGISTER_COMMAND(iCommandPlaneUHF0025MhzSelectorInc)
	REGISTER_COMMAND(iCommandPlaneUHF0025MhzSelectorDec)
	REGISTER_COMMAND(iCommandPlaneUHFTestDisplay)
	REGISTER_COMMAND(iCommandPlaneUHFStatus)
	REGISTER_COMMAND(iCommandPlaneUHFLoad)
	REGISTER_COMMAND(iCommandPlaneUHFVolumeDec)
	REGISTER_COMMAND(iCommandPlaneUHFVolumeInc)
	REGISTER_COMMAND(iCommandPlaneUHFFunctionDialOFF)
	REGISTER_COMMAND(iCommandPlaneUHFFunctionDialMAIN)
	REGISTER_COMMAND(iCommandPlaneUHFFunctionDialBOTH)
	REGISTER_COMMAND(iCommandPlaneUHFFunctionDialADF)
	REGISTER_COMMAND(iCommandPlaneUHFFreqModeDialMNL)
	REGISTER_COMMAND(iCommandPlaneUHFFreqModeDialPRESET)
	REGISTER_COMMAND(iCommandPlaneUHFFreqModeDialGRD)
	REGISTER_COMMAND(iCommandPlaneUHFTTone) //NOT IMPLEMENTED IN UHF
	REGISTER_COMMAND(iCommandPlaneUHFSquelch)
	REGISTER_COMMAND(iCommandPlaneUHFPanelCover)

	//A-10 CDU panel
	//!!! Do not change commands count and order. 
	//!!! It must be exactly like order in enum_avCDU_commands.
	REGISTER_COMMAND(iCommandPlaneCDU_LSK_3L)
	REGISTER_COMMAND(iCommandPlaneCDU_LSK_5L)
	REGISTER_COMMAND(iCommandPlaneCDU_LSK_7L)
	REGISTER_COMMAND(iCommandPlaneCDU_LSK_9L)
	REGISTER_COMMAND(iCommandPlaneCDU_LSK_3R)
	REGISTER_COMMAND(iCommandPlaneCDU_LSK_5R)
	REGISTER_COMMAND(iCommandPlaneCDU_LSK_7R)
	REGISTER_COMMAND(iCommandPlaneCDU_LSK_9R)

	REGISTER_COMMAND(iCommandPlaneCDU_SYS)
	REGISTER_COMMAND(iCommandPlaneCDU_NAV)
	REGISTER_COMMAND(iCommandPlaneCDU_WP)
	REGISTER_COMMAND(iCommandPlaneCDU_OSET)
	REGISTER_COMMAND(iCommandPlaneCDU_FPM)
	REGISTER_COMMAND(iCommandPlaneCDU_PREV)

	REGISTER_COMMAND(iCommandPlaneCDU_1)
	REGISTER_COMMAND(iCommandPlaneCDU_2)
	REGISTER_COMMAND(iCommandPlaneCDU_3)
	REGISTER_COMMAND(iCommandPlaneCDU_4)
	REGISTER_COMMAND(iCommandPlaneCDU_5)
	REGISTER_COMMAND(iCommandPlaneCDU_6)
	REGISTER_COMMAND(iCommandPlaneCDU_7)
	REGISTER_COMMAND(iCommandPlaneCDU_8)
	REGISTER_COMMAND(iCommandPlaneCDU_9)
	REGISTER_COMMAND(iCommandPlaneCDU_0)
	REGISTER_COMMAND(iCommandPlaneCDU_PNT)
	REGISTER_COMMAND(iCommandPlaneCDU_SLASH)

	REGISTER_COMMAND(iCommandPlaneCDU_A)
	REGISTER_COMMAND(iCommandPlaneCDU_B)
	REGISTER_COMMAND(iCommandPlaneCDU_C)
	REGISTER_COMMAND(iCommandPlaneCDU_D)
	REGISTER_COMMAND(iCommandPlaneCDU_E)
	REGISTER_COMMAND(iCommandPlaneCDU_F)
	REGISTER_COMMAND(iCommandPlaneCDU_G)
	REGISTER_COMMAND(iCommandPlaneCDU_H)
	REGISTER_COMMAND(iCommandPlaneCDU_I)
	REGISTER_COMMAND(iCommandPlaneCDU_J)
	REGISTER_COMMAND(iCommandPlaneCDU_K)
	REGISTER_COMMAND(iCommandPlaneCDU_L)
	REGISTER_COMMAND(iCommandPlaneCDU_M)
	REGISTER_COMMAND(iCommandPlaneCDU_N)
	REGISTER_COMMAND(iCommandPlaneCDU_O)
	REGISTER_COMMAND(iCommandPlaneCDU_P)
	REGISTER_COMMAND(iCommandPlaneCDU_Q)
	REGISTER_COMMAND(iCommandPlaneCDU_R)
	REGISTER_COMMAND(iCommandPlaneCDU_S)
	REGISTER_COMMAND(iCommandPlaneCDU_T)
	REGISTER_COMMAND(iCommandPlaneCDU_U)
	REGISTER_COMMAND(iCommandPlaneCDU_V)
	REGISTER_COMMAND(iCommandPlaneCDU_W)
	REGISTER_COMMAND(iCommandPlaneCDU_X)
	REGISTER_COMMAND(iCommandPlaneCDU_Y)
	REGISTER_COMMAND(iCommandPlaneCDU_Z)

	REGISTER_COMMAND(iCommandPlaneVOID_1)
	REGISTER_COMMAND(iCommandPlaneVOID_2)
	REGISTER_COMMAND(iCommandPlaneCDU_MK)
	REGISTER_COMMAND(iCommandPlaneCDU_BCK)
	REGISTER_COMMAND(iCommandPlaneCDU_SPC)
	REGISTER_COMMAND(iCommandPlaneCDU_CLR)
	REGISTER_COMMAND(iCommandPlaneCDU_FA)


	REGISTER_COMMAND(iCommandPlaneCDU_DIM)
	REGISTER_COMMAND(iCommandPlaneCDU_BRT)
	REGISTER_COMMAND(iCommandPlaneCDU_PGUP)
	REGISTER_COMMAND(iCommandPlaneCDU_PGDN)
	REGISTER_COMMAND(iCommandPlaneCDU_BLANC_L)
	REGISTER_COMMAND(iCommandPlaneCDU_BLANC_R)
	REGISTER_COMMAND(iCommandPlaneCDU_PLUS)
	REGISTER_COMMAND(iCommandPlaneCDU_MINUS)

	//A-10 UFC panel
	//!!! Do not change commands count and order. 
	//!!! It must be exactly like order in enum_avCDU_commands.
	REGISTER_COMMAND(iCommandPlaneUFC_1)
	REGISTER_COMMAND(iCommandPlaneUFC_2)
	REGISTER_COMMAND(iCommandPlaneUFC_3)
	REGISTER_COMMAND(iCommandPlaneUFC_4)
	REGISTER_COMMAND(iCommandPlaneUFC_5)
	REGISTER_COMMAND(iCommandPlaneUFC_6)
	REGISTER_COMMAND(iCommandPlaneUFC_7)
	REGISTER_COMMAND(iCommandPlaneUFC_8)
	REGISTER_COMMAND(iCommandPlaneUFC_9)
	REGISTER_COMMAND(iCommandPlaneUFC_0)

	REGISTER_COMMAND(iCommandPlaneUFC_SPC)
	REGISTER_COMMAND(iCommandPlaneUFC_HACK)
	REGISTER_COMMAND(iCommandPlaneUFC_FUNC)
	REGISTER_COMMAND(iCommandPlaneUFC_LTR)
	REGISTER_COMMAND(iCommandPlaneUFC_CLR)
	REGISTER_COMMAND(iCommandPlaneUFC_ENT)
	REGISTER_COMMAND(iCommandPlaneUFC_MK)
	REGISTER_COMMAND(iCommandPlaneUFC_ALT)
	REGISTER_COMMAND(iCommandPlaneUFC_MASTER_WARNING)
	REGISTER_COMMAND(iCommandPlaneUFC_STEER_UP)
	REGISTER_COMMAND(iCommandPlaneUFC_STEER_DOWN)
	REGISTER_COMMAND(iCommandPlaneUFC_DATA_UP)
	REGISTER_COMMAND(iCommandPlaneUFC_DATA_DOWN)
	REGISTER_COMMAND(iCommandPlaneUFC_SEL_UP)
	REGISTER_COMMAND(iCommandPlaneUFC_SEL_DOWN)
	REGISTER_COMMAND(iCommandPlaneUFC_DEPR_UP)
	REGISTER_COMMAND(iCommandPlaneUFC_DEPR_DOWN)
	REGISTER_COMMAND(iCommandPlaneUFC_INTEN_INCREASE)
	REGISTER_COMMAND(iCommandPlaneUFC_INTEN_DECREASE)

	//A-10 CMSP panel
	REGISTER_COMMAND(iCommandPlaneCMSP_OSB_1)
	REGISTER_COMMAND(iCommandPlaneCMSP_OSB_2)
	REGISTER_COMMAND(iCommandPlaneCMSP_OSB_3)
	REGISTER_COMMAND(iCommandPlaneCMSP_OSB_4)

	REGISTER_COMMAND(iCommandPlaneCMSP_NEXT_UP)
	REGISTER_COMMAND(iCommandPlaneCMSP_NEXT_DOWN)

	REGISTER_COMMAND(iCommandPlaneCMSP_RTN)
	REGISTER_COMMAND(iCommandPlaneCMSP_JTSN)
	REGISTER_COMMAND(iCommandPlaneCMSP_BRT_DEC)
	REGISTER_COMMAND(iCommandPlaneCMSP_BRT_INC)

	REGISTER_COMMAND(iCommandPlaneCMSP_MWS_MENU)
	REGISTER_COMMAND(iCommandPlaneCMSP_MWS_ON)

	REGISTER_COMMAND(iCommandPlaneCMSP_JMR_MENU)
	REGISTER_COMMAND(iCommandPlaneCMSP_JMR_ON)

	REGISTER_COMMAND(iCommandPlaneCMSP_RWR_MENU)
	REGISTER_COMMAND(iCommandPlaneCMSP_RWR_ON)

	REGISTER_COMMAND(iCommandPlaneCMSP_DISP_MENU)
	REGISTER_COMMAND(iCommandPlaneCMSP_DISP_ON)

	REGISTER_COMMAND(iCommandPlaneCMSP_MODE_OFF)
	REGISTER_COMMAND(iCommandPlaneCMSP_MODE_STBY)
	REGISTER_COMMAND(iCommandPlaneCMSP_MODE_MAN)
	REGISTER_COMMAND(iCommandPlaneCMSP_MODE_SEMI)
	REGISTER_COMMAND(iCommandPlaneCMSP_MODE_AUTO)

	//A-10 CMSC panel
	REGISTER_COMMAND(iCommandPlaneCMSC_JMR)
	REGISTER_COMMAND(iCommandPlaneCMSC_MWS)
	REGISTER_COMMAND(iCommandPlaneCMSC_BRT_DEC)
	REGISTER_COMMAND(iCommandPlaneCMSC_BRT_INC)
	REGISTER_COMMAND(iCommandPlaneCMSC_AUD_DEC)
	REGISTER_COMMAND(iCommandPlaneCMSC_AUD_INC)
	REGISTER_COMMAND(iCommandPlaneCMSC_PRI)
	REGISTER_COMMAND(iCommandPlaneCMSC_SEP)
	REGISTER_COMMAND(iCommandPlaneCMSC_UNK)

	//A-10 Lighting panel
	REGISTER_COMMAND(iCommandPlanePositionLightsFlash)
	REGISTER_COMMAND(iCommandPlanePositionLightsOff)
	REGISTER_COMMAND(iCommandPlanePositionLightsSteady)
	REGISTER_COMMAND(iCommandPlaneFormationLightsDecrease)
	REGISTER_COMMAND(iCommandPlaneFormationLightsIncrease)
	REGISTER_COMMAND(iCommandPlaneEngInstLightsDecrease)
	REGISTER_COMMAND(iCommandPlaneEngInstLightsIncrease)
	REGISTER_COMMAND(iCommandPlaneNoseIllum)
	REGISTER_COMMAND(iCommandPlaneAuxInstLightsDecrease)
	REGISTER_COMMAND(iCommandPlaneAuxInstLightsIncrease)
	REGISTER_COMMAND(iCommandPlaneSignalLTS)
	REGISTER_COMMAND(iCommandPlaneFltInstLightsDecrease)
	REGISTER_COMMAND(iCommandPlaneFltInstLightsIncrease)
	REGISTER_COMMAND(iCommandPlaneAccelCompLights)
	REGISTER_COMMAND(iCommandPlaneFloodLightsDecrease)
	REGISTER_COMMAND(iCommandPlaneFloodLightsIncrease)
	REGISTER_COMMAND(iCommandPlaneConsoleLightsDecrease)
	REGISTER_COMMAND(iCommandPlaneConsoleLightsIncrease)

	//A-10 Armament HUD Control Panel
	REGISTER_COMMAND(iCommandPlaneAHCPMasterArm)
	REGISTER_COMMAND(iCommandPlaneAHCPMasterSafe)
	REGISTER_COMMAND(iCommandPlaneAHCPMasterTrain)
	REGISTER_COMMAND(iCommandPlaneAHCPGUNPACArm)
	REGISTER_COMMAND(iCommandPlaneAHCPGUNSafe)
	REGISTER_COMMAND(iCommandPlaneAHCPGUNArm)
	REGISTER_COMMAND(iCommandPlaneAHCPLaserArm)
	REGISTER_COMMAND(iCommandPlaneAHCPLaserSafe)
	REGISTER_COMMAND(iCommandPlaneAHCPLaserTrain)
	REGISTER_COMMAND(iCommandPlaneAHCPTGPOnOff)
	REGISTER_COMMAND(iCommandPlaneAHCPAltSCEBaro)
	REGISTER_COMMAND(iCommandPlaneAHCPAltSCEDelta)
	REGISTER_COMMAND(iCommandPlaneAHCPAltSCERadar)
	REGISTER_COMMAND(iCommandPlaneAHCPHUDModeDayNight)
	REGISTER_COMMAND(iCommandPlaneAHCPHUDModeNormSTBY)
	REGISTER_COMMAND(iCommandPlaneAHCPCICUOnOff)
	REGISTER_COMMAND(iCommandPlaneAHCPJTRSOnOff)
	REGISTER_COMMAND(iCommandPlaneAHCPIFFCCOn)
	REGISTER_COMMAND(iCommandPlaneAHCPIFFCCTest)
	REGISTER_COMMAND(iCommandPlaneAHCPIFFCCOff)

	//A-10 Landing Gear panel
	REGISTER_COMMAND(iCommandPlaneLGPAntiSkid)
	REGISTER_COMMAND(iCommandPlaneLGPDownlockOverride)
	REGISTER_COMMAND(iCommandPlaneLGPLandLight)
	REGISTER_COMMAND(iCommandPlaneLGPLightsOff)
	REGISTER_COMMAND(iCommandPlaneLGPTaxiLight)

	//A-10 NMSP
	REGISTER_COMMAND(iCommandPlaneNMSP_HARS)
	REGISTER_COMMAND(iCommandPlaneNMSP_EGI)
	REGISTER_COMMAND(iCommandPlaneNMSP_TISL)
	REGISTER_COMMAND(iCommandPlaneNMSP_STRPT)
	REGISTER_COMMAND(iCommandPlaneNMSP_ANCHR)
	REGISTER_COMMAND(iCommandPlaneNMSP_TCN)
	REGISTER_COMMAND(iCommandPlaneNMSP_ILS)
	REGISTER_COMMAND(iCommandPlaneNMSP_PTR_ABLE_STOW)

	//A-10 TISL Control Panel.
	// NOT IMPL IN IFFCC
	/*REGISTER_COMMAND	(iCommandPlaneTISL_MODE_OFF)
	REGISTER_COMMAND	(iCommandPlaneTISL_MODE_CAGE)
	REGISTER_COMMAND	(iCommandPlaneTISL_MODE_DIVE)
	REGISTER_COMMAND	(iCommandPlaneTISL_MODE_LVLBAR)
	REGISTER_COMMAND	(iCommandPlaneTISL_MODE_LVLWIDE)
	REGISTER_COMMAND	(iCommandPlaneTISL_OVER10)
	REGISTER_COMMAND	(iCommandPlaneTISL_5_10)
	REGISTER_COMMAND	(iCommandPlaneTISL_UNDER5)
	REGISTER_COMMAND	(iCommandPlaneTISL_CODE_TISL)
	REGISTER_COMMAND	(iCommandPlaneTISL_CODE_BOTH)
	REGISTER_COMMAND	(iCommandPlaneTISL_CODE_AUX)
	REGISTER_COMMAND	(iCommandPlaneTISL_ENTER)
	REGISTER_COMMAND	(iCommandPlaneTISL_TRACK)
	REGISTER_COMMAND	(iCommandPlaneTISL_OVERTEMP)
	REGISTER_COMMAND	(iCommandPlaneTISL_BITE)
	REGISTER_COMMAND	(iCommandPlaneTISL_ATAT1_UP)
	REGISTER_COMMAND	(iCommandPlaneTISL_ATAT1_DOWN)
	REGISTER_COMMAND	(iCommandPlaneTISL_ATAT2_UP)
	REGISTER_COMMAND	(iCommandPlaneTISL_ATAT2_DOWN)
	REGISTER_COMMAND	(iCommandPlaneTISL_CODE1_UP)
	REGISTER_COMMAND	(iCommandPlaneTISL_CODE1_DOWN)
	REGISTER_COMMAND	(iCommandPlaneTISL_CODE2_UP)
	REGISTER_COMMAND	(iCommandPlaneTISL_CODE2_DOWN)
	REGISTER_COMMAND	(iCommandPlaneTISL_CODE3_UP)
	REGISTER_COMMAND	(iCommandPlaneTISL_CODE3_DOWN)
	REGISTER_COMMAND	(iCommandPlaneTISL_CODE4_UP)
	REGISTER_COMMAND	(iCommandPlaneTISL_CODE4_DOWN)*/

	//A-10 FireSystem
	REGISTER_COMMAND(iCommand_FireExting_Discharge_Left)
	REGISTER_COMMAND(iCommand_FireExting_Discharge_Center)
	REGISTER_COMMAND(iCommand_FireExting_Discharge_Right)

	//A-10 Left Front
	REGISTER_COMMAND(iCommandPlane_HARS_Fast_Erect)
	REGISTER_COMMAND(iCommandPlane_Altimeter_PNEU)
	REGISTER_COMMAND(iCommandPlane_Altimeter_ELECT)
	REGISTER_COMMAND(iCommandPlane_Altimeter_CENTER)

	//A-10 Auxiliary Avionics Panel
	REGISTER_COMMAND(iCommandPlane_AAP_CDU_Power)
	REGISTER_COMMAND(iCommandPlane_AAP_EGI_Power)
	REGISTER_COMMAND(iCommandPlane_AAP_PageSel_OTHER)
	REGISTER_COMMAND(iCommandPlane_AAP_PageSel_POSITION)
	REGISTER_COMMAND(iCommandPlane_AAP_PageSel_STEER)
	REGISTER_COMMAND(iCommandPlane_AAP_PageSel_WAYPT)

	REGISTER_COMMAND(iCommandPlane_AAP_SteerPt_FLTPLAN)
	REGISTER_COMMAND(iCommandPlane_AAP_SteerPt_MARK)
	REGISTER_COMMAND(iCommandPlane_AAP_SteerPt_MISSION)

	REGISTER_COMMAND(iCommandPlane_AAP_SteerSw_Up)
	REGISTER_COMMAND(iCommandPlane_AAP_SteerSw_Down)
	//A-10 Tacan Control Panel
	REGISTER_COMMAND(iCommandPlane_TACAN_Mode_Off)
	REGISTER_COMMAND(iCommandPlane_TACAN_Mode_Rec)
	REGISTER_COMMAND(iCommandPlane_TACAN_Mode_TR)
	REGISTER_COMMAND(iCommandPlane_TACAN_Mode_AAREC)
	REGISTER_COMMAND(iCommandPlane_TACAN_Mode_AATR)
	REGISTER_COMMAND(iCommandPlane_TACAN_Volume_Decrease)
	REGISTER_COMMAND(iCommandPlane_TACAN_Volume_Increase)
	REGISTER_COMMAND(iCommandPlane_TACAN_Chanel_Ones_Decrease)
	REGISTER_COMMAND(iCommandPlane_TACAN_Chanel_Ones_Increase)
	REGISTER_COMMAND(iCommandPlane_TACAN_Chanel_Tens_Decrease)
	REGISTER_COMMAND(iCommandPlane_TACAN_Chanel_Tens_Increase)
	REGISTER_COMMAND(iCommandPlane_TACAN_Chanel_XY_Mode)
	REGISTER_COMMAND(iCommandPlane_TACAN_Test)

	//A-10 ILS Control Panel
	REGISTER_COMMAND(iCommandPlane_ILS_Power)
	REGISTER_COMMAND(iCommandPlane_ILS_MHz_Decrease)
	REGISTER_COMMAND(iCommandPlane_ILS_MHz_Increase)
	REGISTER_COMMAND(iCommandPlane_ILS_KHz_Decrease)
	REGISTER_COMMAND(iCommandPlane_ILS_KHz_Increase)
	REGISTER_COMMAND(iCommandPlane_ILS_Volume_Decrease)
	REGISTER_COMMAND(iCommandPlane_ILS_Volume_Increase)

	//A-10 HARS Control Panel
	REGISTER_COMMAND(iCommandPlane_HARS_Mode)
	REGISTER_COMMAND(iCommandPlane_HARS_LAT_Correction_Decrease)
	REGISTER_COMMAND(iCommandPlane_HARS_LAT_Correction_Increase)
	REGISTER_COMMAND(iCommandPlane_HARS_HemisphereSel)
	REGISTER_COMMAND(iCommandPlane_HARS_MagneticVar_Min15)
	REGISTER_COMMAND(iCommandPlane_HARS_MagneticVar_Null)
	REGISTER_COMMAND(iCommandPlane_HARS_MagneticVar_Plus15)
	REGISTER_COMMAND(iCommandPlane_HARS_SyncButton)
	REGISTER_COMMAND(iCommandPlane_HARS_HDG_Decrease)
	REGISTER_COMMAND(iCommandPlane_HARS_HDG_Increase)

	//Stall warning control panel
	REGISTER_COMMAND(iCommandPlane_STALL_Vol_Decrease)
	REGISTER_COMMAND(iCommandPlane_STALL_Vol_Increase)
	REGISTER_COMMAND(iCommandPlane_Peak_Vol_Decrease)
	REGISTER_COMMAND(iCommandPlane_Peak_Vol_Increase)

	//A-10 VHF FM Radio
	REGISTER_COMMAND(iCommandPlane_VHF_FM_Volume_Dec)
	REGISTER_COMMAND(iCommandPlane_VHF_FM_Volume_Inc)
	REGISTER_COMMAND(iCommandPlane_VHF_FM_Mode_EMERFM)
	REGISTER_COMMAND(iCommandPlane_VHF_FM_Mode_EMERAM)
	REGISTER_COMMAND(iCommandPlane_VHF_FM_Mode_MAN)
	REGISTER_COMMAND(iCommandPlane_VHF_FM_Mode_PRE)

	REGISTER_COMMAND(iCommandPlane_VHF_FM_FreqMode_OFF)
	REGISTER_COMMAND(iCommandPlane_VHF_FM_FreqMode_TK)
	REGISTER_COMMAND(iCommandPlane_VHF_FM_FreqMode_DN)

	REGISTER_COMMAND(iCommandPlane_VHF_FM_Squelch)
	REGISTER_COMMAND(iCommandPlane_VHF_FM_Tone)

	REGISTER_COMMAND(iCommandPlane_VHF_FM_Load)
	REGISTER_COMMAND(iCommandPlane_VHF_FM_Preset_Dec)
	REGISTER_COMMAND(iCommandPlane_VHF_FM_Preset_Inc)

	REGISTER_COMMAND(iCommandPlane_VHF_FM_10MHz_Dec)
	REGISTER_COMMAND(iCommandPlane_VHF_FM_10MHz_Inc)
	REGISTER_COMMAND(iCommandPlane_VHF_FM_1MHz_Dec)
	REGISTER_COMMAND(iCommandPlane_VHF_FM_1MHz_Inc)
	REGISTER_COMMAND(iCommandPlane_VHF_FM_01MHz_Dec)
	REGISTER_COMMAND(iCommandPlane_VHF_FM_01MHz_Inc)
	REGISTER_COMMAND(iCommandPlane_VHF_FM_025MHz_Dec)
	REGISTER_COMMAND(iCommandPlane_VHF_FM_025MHz_Inc)

	//A-10 VHF AM Radio
	REGISTER_COMMAND(iCommandPlane_VHF_AM_Volume_Dec)
	REGISTER_COMMAND(iCommandPlane_VHF_AM_Volume_Inc)
	REGISTER_COMMAND(iCommandPlane_VHF_AM_Mode_EMERFM)
	REGISTER_COMMAND(iCommandPlane_VHF_AM_Mode_EMERAM)
	REGISTER_COMMAND(iCommandPlane_VHF_AM_Mode_MAN)
	REGISTER_COMMAND(iCommandPlane_VHF_AM_Mode_PRE)

	REGISTER_COMMAND(iCommandPlane_VHF_AM_FreqMode_OFF)
	REGISTER_COMMAND(iCommandPlane_VHF_AM_FreqMode_TK)
	REGISTER_COMMAND(iCommandPlane_VHF_AM_FreqMode_DN)

	REGISTER_COMMAND(iCommandPlane_VHF_AM_Squelch)
	REGISTER_COMMAND(iCommandPlane_VHF_AM_Tone)
	REGISTER_COMMAND(iCommandPlane_VHF_AM_Load)
	REGISTER_COMMAND(iCommandPlane_VHF_AM_Preset_Dec)
	REGISTER_COMMAND(iCommandPlane_VHF_AM_Preset_Inc)

	REGISTER_COMMAND(iCommandPlane_VHF_AM_10MHz_Dec)
	REGISTER_COMMAND(iCommandPlane_VHF_AM_10MHz_Inc)
	REGISTER_COMMAND(iCommandPlane_VHF_AM_1MHz_Dec)
	REGISTER_COMMAND(iCommandPlane_VHF_AM_1MHz_Inc)
	REGISTER_COMMAND(iCommandPlane_VHF_AM_01MHz_Dec)
	REGISTER_COMMAND(iCommandPlane_VHF_AM_01MHz_Inc)
	REGISTER_COMMAND(iCommandPlane_VHF_AM_025MHz_Dec)
	REGISTER_COMMAND(iCommandPlane_VHF_AM_025MHz_Inc)

	//A-10 Environment System Panel
	REGISTER_COMMAND(iCommandPlane_Oxygen_Emergency)
	REGISTER_COMMAND(iCommandPlane_Oxygen_Normal)
	REGISTER_COMMAND(iCommandPlane_Oxygen_TestMark)
	REGISTER_COMMAND(iCommandPlane_Oxygen_Supply)
	REGISTER_COMMAND(iCommandPlane_Oxygen_100Oxygen)
	REGISTER_COMMAND(iCommandPlane_Oxygen_Ind_Test)

	REGISTER_COMMAND(iCommandPlane_Env_WindshieldDefogDeice)
	REGISTER_COMMAND(iCommandPlane_Env_CanopyDefog_Dec)
	REGISTER_COMMAND(iCommandPlane_Env_CanopyDefog_Inc)
	REGISTER_COMMAND(iCommandPlane_Env_WindshieldRainRemove)
	REGISTER_COMMAND(iCommandPlane_Env_WindshieldCenter)
	REGISTER_COMMAND(iCommandPlane_Env_WindshieldWash)
	REGISTER_COMMAND(iCommandPlane_Env_BleddAir)
	REGISTER_COMMAND(iCommandPlane_Env_TempPress_NORM)
	REGISTER_COMMAND(iCommandPlane_Env_TempPress_DUMP)
	REGISTER_COMMAND(iCommandPlane_Env_TempPress_RAM)
	REGISTER_COMMAND(iCommandPlane_Env_MainAirSupply)
	REGISTER_COMMAND(iCommandPlane_Env_FlowLevel_Decrease)
	REGISTER_COMMAND(iCommandPlane_Env_FlowLevel_Increase)
	REGISTER_COMMAND(iCommandPlane_Env_AirConditioner_AUTO)
	REGISTER_COMMAND(iCommandPlane_Env_AirConditioner_HOT)
	REGISTER_COMMAND(iCommandPlane_Env_AirConditioner_COLD)
	REGISTER_COMMAND(iCommandPlane_Env_TempLevel_Decrease)
	REGISTER_COMMAND(iCommandPlane_Env_TempLevel_Increase)

	REGISTER_COMMAND(iCommandPlaneLeftMFD_BRTMODE_OFF)
	REGISTER_COMMAND(iCommandPlaneLeftMFD_BRTMODE_NIGHT)
	REGISTER_COMMAND(iCommandPlaneLeftMFD_BRTMODE_DAY)

	REGISTER_COMMAND(iCommandPlaneRightMFD_BRTMODE_OFF)
	REGISTER_COMMAND(iCommandPlaneRightMFD_BRTMODE_NIGHT)
	REGISTER_COMMAND(iCommandPlaneRightMFD_BRTMODE_DAY)

	REGISTER_COMMAND(iCommandSeatArmHandle)
	REGISTER_COMMAND(iCommandPlaneLockPadlockTerrain)

	REGISTER_COMMAND(iCommandTrainingUserResponded)

	REGISTER_COMMAND(iCommandViewBriefing)
	REGISTER_COMMAND(iCommandDebriefing)

	REGISTER_COMMAND(iCommandExtLadderButtonCover)
	REGISTER_COMMAND(iCommandExtLadderButton)
	REGISTER_COMMAND(iCommandExtLadderRelease)
	REGISTER_COMMAND(iCommandArmGroundSafetyCover)
	REGISTER_COMMAND(iCommandArmGroundSafetySwitch)

	REGISTER_COMMAND(iCommandDVADRFunctionOff)
	REGISTER_COMMAND(iCommandDVADRFunctionSTDBY)
	REGISTER_COMMAND(iCommandDVADRFunctionREC)

	REGISTER_COMMAND(iCommandAntiGSuitTest)
	REGISTER_COMMAND(iCommandCanopyActuatorDisengage)
	REGISTER_COMMAND(iCommandCanopyJettison)
	REGISTER_COMMAND(iCommandCanopyJettisonUnlockButton)

	//A-10 Antenna Select Panel						
	REGISTER_COMMAND(iCommandIFFAntennaUpper)
	REGISTER_COMMAND(iCommandIFFAntennaBoth)
	REGISTER_COMMAND(iCommandIFFAntennaLower)
	REGISTER_COMMAND(iCommandUHFAntennaUpper)
	REGISTER_COMMAND(iCommandUHFAntennaAuto)
	REGISTER_COMMAND(iCommandUHFAntennaLower)
	REGISTER_COMMAND(iCommandEGI_HQ_TOD)

	REGISTER_COMMAND(iCommandPlane_HOTAS_LeftThrottleButton_Off)

	REGISTER_COMMAND(iCommandRWRIntensityDecrease)
	REGISTER_COMMAND(iCommandRWRIntensityIncrease)

	REGISTER_COMMAND(iCommandMissionResourcesManagement)

	REGISTER_COMMAND(iCommandViewLaserChangeCode)

	//separate commands for HOTAS warthog, to fix synchronization issues
	REGISTER_COMMAND(iCommand_LASTE_from_PATH_to_ALTHDG)
	REGISTER_COMMAND(iCommand_LASTE_from_ALT_to_ALTHDG)

	REGISTER_COMMAND(iCommandPlane_L_ENG_OPER_Norm_from_Motor)
	REGISTER_COMMAND(iCommandPlane_R_ENG_OPER_Norm_from_Motor)
	REGISTER_COMMAND(iCommandPlane_L_ENG_OPER_Norm_from_Ign)
	REGISTER_COMMAND(iCommandPlane_R_ENG_OPER_Norm_from_Ign)

	REGISTER_COMMAND(iCommandPlane_FLAPS_MNR_from_UP)
	REGISTER_COMMAND(iCommandPlane_FLAPS_MNR_from_DN)

	//manual vehicle control
	REGISTER_COMMAND(iCommandGViewAction)    //Dmut: §á§Ö§â§Ö§Ü§Ý§ð§é§Ö§ß§Ú§Ö §ß§Ñ §Ü§Ñ§Þ§Ö§â§å-§á§â§Ú§è§Ö§Ý §Õ§Ý§ñ §ß§Ñ§Ù§Ö§Þ§Ü§Ú
	REGISTER_COMMAND(iCommandGChangeWS)      //Dmut: §ã§Þ§Ö§ß§Ñ §Ñ§Ü§ä§Ú§Ó§ß§à§Ô§à §à§â§å§Ø§Ú§ñ (§á§à §è§Ú§Ü§Ý§å)
	REGISTER_COMMAND(iCommandGChangeLN)      //Dmut: §ã§Þ§Ö§ß§Ñ §Ñ§Ü§ä§Ú§Ó§ß§à§Ô§à §à§â§å§Ø§Ú§ñ (§á§à §è§Ú§Ü§Ý§å)
	REGISTER_COMMAND(iCommandGReloadWeapon)  //Dmut: §á§Ö§â§Ö§Ù§Ñ§â§ñ§Õ§Ü§Ñ §Ñ§Ü§ä§Ú§Ó§ß§à§Ô§à §à§â§å§Ø§Ú§ñ
	REGISTER_COMMAND(iCommandGFire)          //Dmut: §Ó§í§ã§ä§â§Ö§Ý §Ú§Ý§Ú §ß§Ñ§é§Ñ§Ý§à §à§é§Ö§â§Ö§Õ§Ú 
	REGISTER_COMMAND(iCommandGFireStop)      //Dmut: §Ü§à§ß§Ö§è §à§é§Ö§â§Ö§Õ§Ú 
	REGISTER_COMMAND(iCommandGZoomIn)        //Dmut: §á§â§Ú§Ò§Ý§Ú§Ù§Ú§ä§î FOV
	REGISTER_COMMAND(iCommandGZoomOut)    //Dmut: §Ó§Ö§â§ß§å§ä§î §Ó §ß§à§â§Þ§å FOV
	REGISTER_COMMAND(iCommandGChangeSpeedH)  //SFINX §Ñ§Ý§î§ä§Ö§â§ß§Ñ§ä§Ú§Ó§ß§à§Ö §å§á§â§Ñ§Ó§Ý§Ö§ß§Ú§Ö (§á§à §ã§Ü§à§â§à§ã§ä§Ú) §á§à §Ô§à§â§Ú§Ù§à§ß§ä§å
	REGISTER_COMMAND(iCommandGChangeSpeedV)  //SFINX §Ñ§Ý§î§ä§Ö§â§ß§Ñ§ä§Ú§Ó§ß§à§Ö §å§á§â§Ñ§Ó§Ý§Ö§ß§Ú§Ö (§á§à §ã§Ü§à§â§à§ã§ä§Ú) §á§à §Ó§í§ã§à§ä§Ö
	REGISTER_COMMAND(iCommandGLockon)        //Dmut: §Ù§Ñ§ç§Ó§Ñ§ä§Ú§ä§î §è§Ö§Ý§î
	REGISTER_COMMAND(iCommandGLockoff)       //Dmut: §ã§ß§ñ§ä§î §Ù§Ñ§ç§Ó§Ñ§ä §è§Ö§Ý§Ú
	REGISTER_COMMAND(iCommandGGroupModeOn)  //§£§Ü§Ý§ð§é§Ú§ä§î §â§Ö§Ø§Ú§Þ §å§á§â§Ñ§Ó§Ý§Ö§ß§Ú§ñ §Ô§â§å§á§á§à§Û (3d §Ó§Ú§Õ)
	REGISTER_COMMAND(iCommandGGroupModeOff) //§£§í§Ü§Ý§ð§é§Ú§ä§î §â§Ö§Ø§Ú§Þ §å§á§â§Ñ§Ó§Ý§Ö§ß§Ú§ñ §Ô§â§å§á§á§à§Û
	REGISTER_COMMAND(iCommandGHoldCursorModeOn)  //§£§Ü§Ý§ð§é§Ú§ä§î §á§â§Ú§Ó§ñ§Ù§Ü§å §Ü§å§â§ã§à§â§Ñ §Ü §ï§Ü§â§Ñ§ß§ß§í§Þ §Ü§à§à§â§Õ§Ú§ß§Ñ§ä§Ñ§Þ §á§â§Ú §ã§ä§â§Ö§Ý§î§Ò§Ö
	REGISTER_COMMAND(iCommandGHoldCursorModeOff) //§£§í§Ü§Ý§ð§é§Ú§ä§î §á§â§Ú§Ó§ñ§Ù§Ü§å §Ü§å§â§ã§à§â§Ñ §Ü §ï§Ü§â§Ñ§ß§ß§í§Þ §Ü§à§à§â§Õ§Ú§ß§Ñ§ä§Ñ§Þ §á§â§Ú §ã§ä§â§Ö§Ý§î§Ò§Ö

	REGISTER_COMMAND(iCommandViewParticleEffect) //§Õ§Ý§ñ §à§ä§Ý§Ñ§Õ§Ü§Ú: §ã§à§Ù§Õ§Ñ§ä§î §ä§Ö§Ü§å§ë§Ú§Û §ï§æ§æ§Ö§Ü§ä, §Ó §Þ§Ö§ã§ä§Ö §Ü§å§Õ§Ñ §ã§Þ§à§ä§â§Ú§ä §Ü§Ñ§Þ§Ö§â§Ñ

	REGISTER_COMMAND(iCommandPlaneShowKneeboard)

	REGISTER_COMMAND(iCommandGIsometricView) //Dmut: §Ó§í§ß§Ö§ã§Ö§ß§ß§Ñ§ñ §ä§à§é§Ü§Ñ §Ü§Ñ§Þ§Ö§â§í ON\OFF
	REGISTER_COMMAND(iCommandPlane_SPU9_PTT_on)
	REGISTER_COMMAND(iCommandPlane_SPU9_PTT_off)

	REGISTER_COMMAND(iCommandPlane_P_51_PTT_on)
	REGISTER_COMMAND(iCommandPlane_P_51_PTT_off)

	REGISTER_COMMAND(iCommandViewTransposeModeOn)
	REGISTER_COMMAND(iCommandViewTransposeModeOff)

	REGISTER_COMMAND(iCommandViewBtn1Down)
	REGISTER_COMMAND(iCommandViewBtn1Up)
	REGISTER_COMMAND(iCommandViewBtn2Down)
	REGISTER_COMMAND(iCommandViewBtn2Up)
	REGISTER_COMMAND(iCommandViewBtn3Down)
	REGISTER_COMMAND(iCommandViewBtn3Up)

	REGISTER_COMMAND(iCommandPlane_P_51_WarEmergencyPower)

	REGISTER_COMMAND(iCommandViewCockpitChangeSeat)
	REGISTER_COMMAND(iCommandViewCockpitSetPilotSeat)
	REGISTER_COMMAND(iCommandViewCockpitSetOperatorSeat)
	REGISTER_COMMAND(iCommandViewCockpitSetGunnerSeat1)
	REGISTER_COMMAND(iCommandViewCockpitSetGunnerSeat2)

	REGISTER_COMMAND(iCommandGViewWSCenter)  //Dmut:Return turret to center position
	REGISTER_COMMAND(iCommandGStabilize)     //Dmut:Turret stabilizer On/Off

	// panov {
	REGISTER_COMMAND(iCommandViewPauseOnOff)
	// panov }

	REGISTER_COMMAND(iCommandSlaveToTanker)

	REGISTER_COMMAND(iCommandViewNVG_GainUp)
	REGISTER_COMMAND(iCommandViewNVG_GainDown)

	REGISTER_COMMAND(iCommandVehicle_LaunchRedFlare)
	REGISTER_COMMAND(iCommandVehicle_LaunchGreenFlare)
	REGISTER_COMMAND(iCommandVehicle_LaunchWhiteFlare)

	REGISTER_COMMAND(iCommand_ExplorationStart)
	REGISTER_COMMAND(iCommand_ExplorationTargetSelection)
	REGISTER_COMMAND(iCommand_ExplorationCansel)

	REGISTER_COMMAND(iCommandViewNVGOff) //!!!!!!Not an avionics action, only view!!!!!!
	/* OBSOLETE */REGISTER_COMMAND(iCommandGZoomUpdate)    //Panov: §Ó§í§ã§ä§Ñ§Ó§Ú§ä§î FOV §á§â§Ú §ã§Þ§Ö§ß§Ö §à§â§å§Ø§Ú§ñ (GroundCockpit)
	REGISTER_COMMAND(iCommandTakeControlTrack) // §Õ§Ý§ñ §Þ§Ñ§ê§Ú§ß§à§Ü

	REGISTER_COMMAND(iCommandGSelectFeedSlot1)      //SFINX: §Ó§í§Ò§à§â 1-§Ô§à §ã§Ý§à§ä§Ñ §á§à§Õ§Ñ§é§Ú §Ò§à§Ö§á§â§Ú§á§Ñ§ã§à§Ó
	REGISTER_COMMAND(iCommandGSelectFeedSlot2)      //SFINX: §Ó§í§Ò§à§â 2-§Ô§à §ã§Ý§à§ä§Ñ §á§à§Õ§Ñ§é§Ú §Ò§à§Ö§á§â§Ú§á§Ñ§ã§à§Ó
	REGISTER_COMMAND(iCommandGEmissionToggle) // SFINX: §Ó§Ü§Ý§ð§é§Ö§ß§Ú§Ö §Ú §à§ä§Ü§Ý§ð§é§Ö§ß§Ú§Ö §Ú§Ù§Ý§å§é§Ö§ß§Ú§ñ (§ã§ð§Õ§Ñ §Ø§Ö §Ý§Ñ§Ù§Ö§â§ß§í§Ö §Õ§Ñ§Ý§î§ß§à§Þ§Ö§â§í)

	REGISTER_COMMAND(iCommandToggleMirrors) // on/off mirrors rendering in cockpit
	REGISTER_COMMAND(iCommandToggleReceiveMode) // on/off mirrors rendering in cockpit

	REGISTER_COMMAND(iCommandPlaneChangeLockUp) // informs avionics that iCommandPlaneChangeLock key was released
	REGISTER_COMMAND(iCommandTrainingUserRespondedBack) // user do not understand at want to repeat 

	REGISTER_COMMAND(iCommandClockElapsedTimeReset) // Reset Clock elapsed time meter

	// §Ý§Ñ§Ù§Ö§â§ß§í§Û §Õ§Ñ§Ý§î§ß§à§Þ§Ö§â §Ó §ß§Ñ§Ù§Ö§Þ§ß§à§Þ §Ü§à§Ü§á§Ú§ä§Ö
	REGISTER_COMMAND(iCommandGLaserRangerOn)
	REGISTER_COMMAND(iCommandGLaserRangerOff)
	REGISTER_COMMAND(iCommandGLaserRangerReset)
	//§Ü§à§Þ§Ñ§ß§Õ§í §Õ§Ý§ñ §Ô§â§å§Ù§Ñ
	REGISTER_COMMAND(iCommandExtCargoHook)
	REGISTER_COMMAND(iCommandExternalCargoAutounhook)
	// Example of usage: F-15 Return To Search, F-15 reset to NDTWS
	REGISTER_COMMAND(iCommandSensorReset)

	REGISTER_COMMAND(iCommandViewInfoControlPanelOnOff)

	// §¬§à§Þ§Ñ§ß§Õ§í §å§á§â§Ñ§Ó§Ý§Ö§ß§Ú§ñ §á§à§Ó§à§â§à§ä§à§Þ §Ò§Ñ§ê§ß§Ú §Þ§Ñ§ê§Ú§ß§Ü§Ú §Õ§Ý§ñ §Ü§Ý§Ñ§Ó§Ú§Ñ§ä§å§â§í

	REGISTER_COMMAND(iCommandRotateTurretLeftPressed) // §±§à§Ó§à§â§à§ä §Ò§Ñ§ê§ß§Ú §Ó§Ý§Ö§Ó§à.
	REGISTER_COMMAND(iCommandRotateTurretRightPressed) // §±§à§Ó§à§â§à§ä §Ò§Ñ§ê§ß§Ú §Ó§á§â§Ñ§Ó§à.
	REGISTER_COMMAND(iCommandRotateTurretUpPressed) // §±§à§Õ§ì§Ö§Þ §ã§ä§Ó§à§Ý§Ñ §Ò§Ñ§ê§ß§Ú §Ó§Ó§Ö§â§ç.
	REGISTER_COMMAND(iCommandRotateTurretDownPressed) // §°§á§å§ã§Ü§Ñ§ß§Ú§Ö §ã§ä§Ó§à§Ý§Ñ §Ò§Ñ§ê§ß§Ú §Ó§ß§Ú§Ù.

	//Track or mission restart on the way
	REGISTER_COMMAND(iCommandMissionRestart)

	REGISTER_COMMAND(iCommandVehicle_ReloadStart) // For manual reloading
	REGISTER_COMMAND(iCommandVehicle_AmmoMaintainInterrupt) // To abort reloading|rearming
	REGISTER_COMMAND(iCommandReloadShaders) // §á§Ö§â§Ö§Ü§à§Þ§á§Ú§Ý§Ú§â§à§Ó§Ñ§ä§î §Ú§Ù§Þ§Ö§ß§Ö§ß§ß§í§Ö §ê§Ö§Û§Õ§Ö§â§Ñ

	REGISTER_COMMAND(iCommandVehicleElevationCorrectionUp)
	REGISTER_COMMAND(iCommandVehicleElevationCorrectionDown)
	REGISTER_COMMAND(iCommandVehicleAzimuthCorrectionLeft)
	REGISTER_COMMAND(iCommandVehicleAzimuthCorrectionRight)

	REGISTER_COMMAND(iCommandVehicleSightReticleAlternate)

	REGISTER_COMMAND(iCommandExternalCargoIndicator)

	REGISTER_COMMAND(iCommandGReticleLightToggle)
	REGISTER_COMMAND(iCommandGZoomInPressed)
	REGISTER_COMMAND(iCommandGZoomOutPressed)

	REGISTER_COMMAND(iCommandRotateTurretLeftReleased) // §°§ã§ä§Ñ§ß§à§Ó §á§à§Ó§à§â§à§ä§Ñ §Ò§Ñ§ê§ß§Ú §Ó§Ý§Ö§Ó§à.
	REGISTER_COMMAND(iCommandRotateTurretRightReleased) // §°§ã§ä§Ñ§ß§à§Ó §á§à§Ó§à§â§à§ä§Ñ §Ò§Ñ§ê§ß§Ú §Ó§á§â§Ñ§Ó§à.
	REGISTER_COMMAND(iCommandRotateTurretUpReleased) // §°§ã§ä§Ñ§ß§à§Ó §á§à§Õ§ì§Ö§Þ§Ñ §ã§ä§Ó§à§Ý§Ñ §Ò§Ñ§ê§ß§Ú §Ó§Ó§Ö§â§ç.
	REGISTER_COMMAND(iCommandRotateTurretDownReleased) // §°§ã§ä§Ñ§ß§à§Ó §à§á§å§ã§Ü§Ñ§ß§Ú§ñ §ã§ä§Ó§à§Ý§Ñ §Ò§Ñ§ê§ß§Ú §Ó§ß§Ú§Ù.

	// §ã§ä§â§Ö§Ý§î§Ò§Ñ §Ú§Ù §ã§á§Ñ§â§Ö§ß§ß§à§Ô§à §á§å§Ý§Ö§Þ§Ö§ä§Ñ §Ú §à§ã§ß§à§Ó§ß§à§Ô§à §à§â§å§Õ§Ú§ñ §á§à §â§Ñ§Ù§ß§í§Þ §Ü§ß§à§á§Ü§Ñ§Þ
	REGISTER_COMMAND(iCommandVehicle_FireSecondary)
	REGISTER_COMMAND(iCommandVehicle_FireSecondaryOff)

	REGISTER_COMMAND(iCommand_Ground_IFF_Down)
	REGISTER_COMMAND(iCommandDriverView)

	// Ins¨¦rer nouvelles commandes juste avant ce commentaire!
	// ATTENTION! Avec 500 d¨¦parts commande analogique.
	// Oykin: lancer des commandes analogiques report¨¦es ¨¤ 2000
	REGISTER_COMMAND(iCommandMaximum)							// §¬§à§Ý§Ú§é§Ö§ã§ä§Ó§à §Ó§ã§Ö§ç §Ü§à§Þ§Ñ§ß§Õ
	// §³§ð§Õ§Ñ §ß§Ú§é§Ö§Ô§à §ß§Ö §Ó§ã§ä§Ñ§Ó§Ý§ñ§ä§î!

#ifndef INPUT_LUA_BINDING
};
#endif

#endif

#ifdef INPUT_LUA_BINDING
#define _ICOMMAND_H_
#endif