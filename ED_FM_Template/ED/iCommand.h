// ��.��. 15.02.02 ////////////////////////////////////////////////////////////////////////
// �� ��ӧ�٧� �� ��֧�, ���� �ܧ�է� �ܧ�ާѧߧ� �٧ѧ�ڧ��ӧѧ���� �� ���֧ܧ�, ���� �ܧ�է� �ߧ� �է�ݧاߧ� �ڧ٧ާ֧ߧ�����.
// �������ާ� �ߧ֧ݧ�٧� �ڧ٧ާ֧ߧ��� �����է�� ����֧��ӧ���ڧ� �ܧ�ާѧߧ�, ��էѧݧ��� �ߧ֧ߧ�اߧ�� �ܧ�ާѧߧէ� �ڧݧ�
// �է�ҧѧӧݧ��� �ߧ�ӧ�� �ާ֧اէ� ����֧��ӧ���ڧާ�. ����ӧ�� �ܧ�ާѧߧէ� ��ѧ٧�֧�ѧ֧��� �ӧ��ѧӧݧ��� ���ݧ�ܧ� �� 
// �ܧ�ߧ֧� �էѧߧߧ�ԧ� ���ڧ�ܧ�. ����ݧ֧է��ӧڧ� ����ԧ�, �ߧ֧ݧ�٧� ��ѧܧا� �ܧ�ާާ֧ߧ�ڧ��ӧѧ��/��ѧ�ܧ�ާާ֧ߧ�ڧ��ӧѧ��
// �ܧ�ާѧߧէ� �� �էѧߧߧ�� ���ڧ�ܧ� - �ߧ�اߧ� �ߧѧ��էڧ�� �է��ԧڧ� ������ҧ� �ӧߧ֧�֧ߧڧ� �ڧ٧ާ֧ߧ֧ߧڧ�, �ߧ�
// ���ڧӧ�է��ڧ� �� �ߧ֧�ѧҧ��������ҧߧ���� ���ѧ��� ���֧ܧ��. ���֧ߧ�اߧ�� �ܧ�ާѧߧէ� ������� ���ާ֧�ѧۧ��
// �ܧ�ާާ֧ߧ�ѧ�ڧ֧� /* OBSOLETE */, ���. �ߧڧا�. ����ӧ�� �ܧ�ާѧߧէ� �ӧ��ѧӧݧ�ۧ�� �ߧ֧����֧է��ӧ֧ߧߧ�
// ��֧�֧� iCommandMaximum.
// GSF. ���ѧܧا� �ҧ�ݧ��ѧ� ������ҧ� ��ڧߧ���ߧڧ٧ڧ��ӧѧ�� �ܧ�ާѧߧէ� �� ��ڧݧ���ѧާ� �� ActionProcessor.
// isVideoAction() - ���ڧ��� �ӧڧէ֧�-�ܧ�ާѧߧ�. isImportantAction() - �ӧ���ާ�ԧѧ�֧ݧ�ߧ��.
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

	REGISTER_COMMAND_EX(iCommandNull, 0)						// ����اߧ� �էݧ� ��֧�֧ҧ��� �ӧ�֧� �ܧ�ާѧߧ�

	/*OBSOLETE*/REGISTER_COMMAND(iCommandRotatePlus)						// ����֧ާ֧ߧߧѧ� �ܧ�ާѧߧէ�
	/*OBSOLETE*/REGISTER_COMMAND(iCommandRotateMinus)					// ����֧ާ֧ߧߧѧ� �ܧ�ާѧߧէ�
	/*OBSOLETE*/REGISTER_COMMAND(iCommandUpPilon)						// ����֧ާ֧ߧߧѧ� �ܧ�ާѧߧէ�
	/*OBSOLETE*/REGISTER_COMMAND(iCommandDownPilon)						// ����֧ާ֧ߧߧѧ� �ܧ�ާѧߧէ�
	/*OBSOLETE*/REGISTER_COMMAND(iCommandMissileFire)					// ����֧ާ֧ߧߧѧ� �ܧ�ާѧߧէ�
	/*OBSOLETE*/REGISTER_COMMAND(iCommandGunFire)						// ����֧ާ֧ߧߧѧ� �ܧ�ާѧߧէ�
	REGISTER_COMMAND(iCommandViewCockpit)					// ���ѧާ֧�� - �ܧѧҧڧߧ� (Non-simulation Action)
	REGISTER_COMMAND(iCommandViewAir)						// ���ѧާ֧�� - �ӧ�٧է��ߧ�� ��ҧ�֧ܧ�� (Non-simulation Action)
	REGISTER_COMMAND(iCommandViewTower)						// ���ѧާ֧�� - �ҧѧ�ߧ� (Non-simulation Action)
	REGISTER_COMMAND_EX(iCommandViewGround, 10)				// ���ѧާ֧�� - �ߧѧ٧֧ާߧ�� ��ҧ�֧ܧ�� (Non-simulation Action)
	REGISTER_COMMAND(iCommandViewMirage)						// ���ѧާ֧�� - �ާڧ�ѧا� (Non-simulation Action)
	REGISTER_COMMAND(iCommandViewChase)						// ���ݧ֧է��ѧ� �ܧѧާ֧�� (Non-simulation Action)
	REGISTER_COMMAND(iCommandViewNavy)						// ���ѧާ֧�� - �ާ���ܧڧ� ��ҧ�֧ܧ�� (Non-simulation Action)
	REGISTER_COMMAND(iCommandViewFight)						// ���ѧާ֧�� - �ӧ�٧է��ߧ�� �ҧ�� (Non-simulation Action)
	REGISTER_COMMAND(iCommandViewAWACS)						// ���ѧާ֧�� - �ܧ�ާѧߧէߧ�� ���ߧܧ� (�ӧڧ� ����������) (Non-simulation Action)
	REGISTER_COMMAND(iCommandViewFree)						// ���ӧ�ҧ�էߧѧ� �ܧѧާ֧�� (Non-simulation Action)
	REGISTER_COMMAND(iCommandViewTempCockpitOn)				// ���ܧݧ��֧ߧڧ� �ܧѧާ֧�� �ӧ�֧ާ֧ߧߧ�� �ܧѧҧڧߧ� (Non-simulation Action)
	REGISTER_COMMAND(iCommandViewTempCockpitOff)				// ����ܧݧ��֧ߧڧ� �ܧѧާ֧�� �ӧ�֧ާ֧ߧߧ�� �ܧѧҧڧߧ� (Non-simulation Action)
	REGISTER_COMMAND(iCommandViewLock)						// ���ݧ֧ا֧ߧڧ� �٧� �ҧݧڧاѧۧ�ڧ� ��ҧ�֧ܧ��� (Non-simulation Action)
	REGISTER_COMMAND_EX(iCommandViewUnlock, 20)				// ���ҧ��� ��ݧ֧ا֧ߧڧ� (Non-simulation Action)
	REGISTER_COMMAND(iCommandViewMe)							// ����ܧѧ٧ѧ�� ��ӧ�� ��ѧާ�ݧ֧� (Non-simulation Action)
	REGISTER_COMMAND(iCommandViewPlus)						// ���֧�֧ܧݧ��ѧ�֧ݧ� ��֧اڧާ� "+" �էݧ� ��֧ܧ��֧� �ܧѧާ֧�� (Non-simulation Action)
	REGISTER_COMMAND(iCommandViewFriends)					// ���֧اڧ� "����ݧ�ܧ� ��ӧ��" (Non-simulation Action)
	REGISTER_COMMAND(iCommandViewEnemies)					// ���֧اڧ� "����ݧ�ܧ� �ӧ�ѧԧ�" (Non-simulation Action)
	/* OBSOLETE */REGISTER_COMMAND(iCommandViewNeutrals)					// ���֧اڧ� "���֧ۧ��ѧݧ�ߧ��" (Non-simulation Action)
	REGISTER_COMMAND(iCommandViewAll)						// ���֧اڧ� "�����" (Non-simulation Action)
	REGISTER_COMMAND(iCommandViewExplosion)					// ����֧ާ֧ߧߧѧ� �ܧ�ާѧߧէ� �էݧ� �է֧ާ�ߧ���ѧ�ڧ� �ӧ٧��ӧ� (Non-simulation Action)
	REGISTER_COMMAND(iCommandViewLeft)						// ����ӧ���� �ӧ٧ԧݧ�է� �ߧѧݧ֧ӧ� (Non-simulation Action)
	REGISTER_COMMAND(iCommandViewRight)						// ����ӧ���� �ӧ٧ԧݧ�է� �ߧѧ��ѧӧ� (Non-simulation Action)
	REGISTER_COMMAND_EX(iCommandViewUp, 30)					// ����ӧ���� �ӧ٧ԧݧ�է� �ӧӧ֧�� (Non-simulation Action)
	REGISTER_COMMAND(iCommandViewDown)						// ����ӧ���� �ӧ٧ԧݧ�է� �ӧߧڧ� (Non-simulation Action)
	REGISTER_COMMAND(iCommandViewLeftSlow)					// ����ӧ���� �ӧ٧ԧݧ�է� �ߧѧݧ֧ӧ� �ާ֧էݧ֧ߧߧ�� (Non-simulation Action)
	REGISTER_COMMAND(iCommandViewRightSlow)					// ����ӧ���� �ӧ٧ԧݧ�է� �ߧѧ��ѧӧ� �ާ֧էݧ֧ߧߧ�� (Non-simulation Action)
	REGISTER_COMMAND(iCommandViewUpSlow)						// ����ӧ���� �ӧ٧ԧݧ�է� �ӧӧ֧�� �ާ֧էݧ֧ߧߧ�� (Non-simulation Action)
	REGISTER_COMMAND(iCommandViewDownSlow)					// ����ӧ���� �ӧ٧ԧݧ�է� �ӧߧڧ� �ާ֧էݧ֧ߧߧ�� (Non-simulation Action)
	REGISTER_COMMAND(iCommandViewCenter)						// ���֧ߧ��ڧ��ӧѧߧڧ� �ӧ٧ԧݧ�է� (Non-simulation Action)
	REGISTER_COMMAND(iCommandViewForward)					// ����ڧҧݧڧا֧ߧڧ� �ܧѧާ֧�� (Non-simulation Action)
	REGISTER_COMMAND(iCommandViewBack)						// ���էѧݧ֧ߧڧ� �ܧѧާ֧�� (Non-simulation Action)
	REGISTER_COMMAND(iCommandViewForwardSlow)				// ����ڧҧݧڧا֧ߧڧ� �ܧѧާ֧�� �ާ֧էݧ֧ߧߧ�� (Non-simulation Action)
	REGISTER_COMMAND_EX(iCommandViewBackSlow, 40)				// ���էѧݧ֧ߧڧ� �ܧѧާ֧�� �ާ֧էݧ֧ߧߧ�� (Non-simulation Action)
	REGISTER_COMMAND(iCommandViewCameraLeft)					// ����ӧ���� �ܧѧާ֧�� �ߧѧݧ֧ӧ� (Non-simulation Action)
	REGISTER_COMMAND(iCommandViewCameraRight)				// ����ӧ���� �ܧѧާ֧�� �ߧѧ��ѧӧ� (Non-simulation Action)
	REGISTER_COMMAND(iCommandViewCameraUp)					// ����ӧ���� �ܧѧާ֧�� �ӧӧ֧�� (Non-simulation Action)
	REGISTER_COMMAND(iCommandViewCameraDown)					// ����ӧ���� �ܧѧާ֧�� �ӧߧڧ� (Non-simulation Action)
	REGISTER_COMMAND(iCommandViewCameraLeftSlow)				// ����ӧ���� �ܧѧާ֧�� �ߧѧݧ֧ӧ� �ާ֧էݧ֧ߧߧ�� (Non-simulation Action)
	REGISTER_COMMAND(iCommandViewCameraRightSlow)			// ����ӧ���� �ܧѧާ֧�� �ߧѧ��ѧӧ� �ާ֧էݧ֧ߧߧ�� (Non-simulation Action)
	REGISTER_COMMAND(iCommandViewCameraUpSlow)				// ����ӧ���� �ܧѧާ֧�� �ӧӧ֧�� �ާ֧էݧ֧ߧߧ�� (Non-simulation Action)
	REGISTER_COMMAND(iCommandViewCameraDownSlow)				// ����ӧ���� �ܧѧާ֧�� �ӧߧڧ� �ާ֧էݧ֧ߧߧ�� (Non-simulation Action)
	REGISTER_COMMAND(iCommandViewCameraCenter)				// ���֧ߧ��ڧ��ӧѧߧڧ� �ܧѧާ֧�� (Non-simulation Action)
	REGISTER_COMMAND_EX(iCommandFriendlyChat, 50)				// ���֧�֧ӧ�� ���ѧ� ���ݧ�ܧ� ��ӧ�ڧ� (Administrative Action)
	REGISTER_COMMAND(iCommandQuit)							// ������� (Administrative Action)
	REGISTER_COMMAND(iCommandBrakeGo)						// ���ѧ�٧�/����� �ӧ�֧ާ֧ߧ� (�ܧݧѧӧڧ�� S) (Administrative Action)
	REGISTER_COMMAND(iCommandAccelerate)						// ����ܧ��֧ߧڧ� �ӧ�֧ާ֧ߧ� (Administrative Action) 
	REGISTER_COMMAND(iCommandOneFrame)						// ����ܧѧէ��ӧ�� �էӧڧا֧ߧڧ� ���� ����ѧߧ�ӧܧ� �ӧ�֧ާ֧ߧ� (Administrative Action)
	REGISTER_COMMAND(iCommandTrkEsc)							// ����֧��ӧѧߧڧ� ����ڧԧ��ӧѧߧڧ� ���֧ܧ� (Administrative Action)
	/*OBSOLETE*/REGISTER_COMMAND(iCommandPlayerCntrl)		// ����ӧ�� ��ѧߧ֧ݧ� �����ڧݧڧ��ӧѧߧڧ� - temporary
	REGISTER_COMMAND(iCommandChat)							// ���֧�֧ӧ�� ���ѧ� �� ��֧اڧާ� �ӧ�֧�
	REGISTER_COMMAND(iCommandPlaneSAUAutomatic)				// ����ѧҧڧݧڧ٧ѧ�ڧ� ��ԧݧ��
	REGISTER_COMMAND(iCommandPlaneSAUHBarometric)			// ����ѧҧڧݧڧ٧ѧ�ڧ� �ѧҧ��ݧ��ߧ�� �ӧ�����
	REGISTER_COMMAND_EX(iCommandPlaneSAUHRadio, 60)			// ����ݧ֧� �� ��ԧڧҧѧߧڧ֧� ��֧ݧ�֧��
	REGISTER_COMMAND(iCommandPlaneSAUHorizon)				// ����ڧӧ֧է֧ߧڧ� �� �ԧ��ڧ٧�ߧ��
	REGISTER_COMMAND(iCommandPlaneAutopilot)					// ���ӧ���ڧݧ��
	REGISTER_COMMAND(iCommandPlaneAUTOnOff)					// ���֧�֧ܧݧ��֧ߧڧ� ��֧اڧާ� ������
	REGISTER_COMMAND(iCommandPlaneAUTIncrease)				// ���ӧ֧ݧڧ�ڧ�� �٧ѧէѧߧߧ�� ��ܧ������
	REGISTER_COMMAND(iCommandPlaneAUTDecrease)				// ���ާ֧ߧ��ڧ�� �٧ѧէѧߧߧ�� ��ܧ������
	/* OBSOLETE */REGISTER_COMMAND(iCommandPlaneAUTIncreaseRegime)			// ���֧�֧ۧ�� �ߧ� �ҧ�ݧ֧� �ӧ���ܧڧ� ��֧اڧ� ���ԧ�
	/* OBSOLETE */REGISTER_COMMAND(iCommandPlaneAUTDecreaseRegime)			// ���֧�֧ۧ�� �ߧ� �ҧ�ݧ֧� �ߧڧ٧ܧڧ� ��֧اڧ� ���ԧ�
	REGISTER_COMMAND(iCommandPlaneGear)						// ���ѧ���
	REGISTER_COMMAND(iCommandPlaneHook)						// ���ѧ�
	REGISTER_COMMAND_EX(iCommandPlanePackWing, 70)				// ���ܧݧѧէ�ӧѧߧڧ� �ܧ��ݧ�֧�
	REGISTER_COMMAND(iCommandPlaneFonar)						// ����ߧѧ��
	REGISTER_COMMAND(iCommandPlaneFlaps)						// ���ѧܧ��ݧܧ�
	REGISTER_COMMAND(iCommandPlaneAirBrake)					// ����٧է��ߧ�� ����ާ��
	REGISTER_COMMAND(iCommandPlaneWheelBrakeOn)				// ���ܧݧ��֧ߧڧ� ����ާ�٧� �ܧ�ݧ֧�
	REGISTER_COMMAND(iCommandPlaneWheelBrakeOff)				// ����ܧݧ��֧ߧڧ� ����ާ�٧� �ܧ�ݧ֧�
	REGISTER_COMMAND(iCommandPlaneParachute)					// ���ѧ�ѧ���
	REGISTER_COMMAND(iCommandPlaneDropSnar)					// ���ҧ��� �ݧ�ӧ��֧�
	REGISTER_COMMAND(iCommandPlaneWingtipSmokeOnOff)			// ���ܧ�/�ӧ�ܧ� �է�ާ�ӧ�� ��ѧ�֧� �ߧ� �ܧ�ߧ�ѧ� �ܧ��ݧ�֧�
	REGISTER_COMMAND(iCommandPlaneFuelOn)					// ���ܧݧ��֧ߧڧ� ��ݧڧӧ� ����ݧڧӧ� �ڧݧ� �٧ѧ��ѧӧܧ�
	REGISTER_COMMAND_EX(iCommandPlaneFuelOff, 80)				// ����ܧݧ��֧ߧڧ� ��ݧڧӧ� ����ݧڧӧ� �ڧݧ� �٧ѧ��ѧӧܧ�
	REGISTER_COMMAND(iCommandPlaneSalvoOnOff)				// ���ѧݧ��ӧ�� ��֧اڧ� �ӧܧ�/�ӧ�ܧ�
	REGISTER_COMMAND(iCommandPlaneJettisonWeapons)			// ���ҧ��� ����اڧ� ��ѧ�ѧާ�
	REGISTER_COMMAND(iCommandPlaneEject)						// ���ѧ�ѧ��ݧ��ڧ��ӧѧߧڧ�
	REGISTER_COMMAND(iCommandPlaneFire)						// ���ѧ�֧�ܧ�
	REGISTER_COMMAND(iCommandPlaneFireOff)					// ���ѧ�֧�ܧ� �������ڧݧ�
	REGISTER_COMMAND(iCommandPlaneRadarOnOff)				// ���ܧݧ��֧ߧڧ� / �ӧ�ܧݧ��֧ߧڧ� ��ѧէѧ��
	REGISTER_COMMAND(iCommandPlaneEOSOnOff)					// ���ܧݧ��֧ߧڧ� / �ӧ�ܧݧ��֧ߧڧ� ������
	REGISTER_COMMAND(iCommandPlaneRadarLeft)					// ����ӧ���� �ѧߧ�֧ߧߧ� ������ �ӧݧ֧ӧ�
	REGISTER_COMMAND(iCommandPlaneRadarRight)				// ����ӧ���� �ѧߧ�֧ߧߧ� ������ �ӧ��ѧӧ�
	REGISTER_COMMAND_EX(iCommandPlaneRadarUp, 90)				// ����ӧ���� �ѧߧ�֧ߧߧ� ������ �ӧӧ֧��
	REGISTER_COMMAND(iCommandPlaneRadarDown)					// ����ӧ���� �ѧߧ�֧ߧߧ� ������ �ӧߧڧ�
	REGISTER_COMMAND(iCommandPlaneRadarCenter)				// ����٧ӧ�ѧ� �ѧߧ�֧ߧߧ� ������ �� ��֧ߧ��
	REGISTER_COMMAND(iCommandPlaneTrimLeft)					// ����ڧާާ֧� �ӧݧ֧ӧ�
	REGISTER_COMMAND(iCommandPlaneTrimRight)					// ����ڧާާ֧� �ӧ��ѧӧ�
	REGISTER_COMMAND(iCommandPlaneTrimUp)					// ����ڧާާ֧� �ӧӧ֧��
	REGISTER_COMMAND(iCommandPlaneTrimDown)					// ����ڧާާ֧� �ӧߧڧ�
	REGISTER_COMMAND(iCommandPlaneTrimCancel)				// ���ҧ��� ���ڧާާ֧��
	REGISTER_COMMAND(iCommandPlaneTrimLeftRudder)			// ����ڧާާ֧� �ݧ֧ӧ�� ��֧էѧݧ�
	REGISTER_COMMAND(iCommandPlaneTrimRightRudder)			// ����ڧާާ֧� ���ѧӧ�� ��֧էѧݧ�
	REGISTER_COMMAND_EX(iCommandPlaneChangeLock, 100)			// ���֧�֧ܧݧ��֧ߧڧ� ���է�֧اڧާ�� / �٧ѧ�ӧѧ�
	REGISTER_COMMAND(iCommandPlaneChangeWeapon)				// ���֧�֧ܧݧ��֧ߧڧ� ���է�֧اڧާ�� / ��֧�֧ҧ�� ����اڧ�
	REGISTER_COMMAND(iCommandPlaneChangeTarget)				// ���֧�֧ҧ�� ��֧ݧ֧�
	REGISTER_COMMAND(iCommandPlaneZoomIn)					// ���٧ާ֧ߧ֧ߧڧ� �ާѧ���ѧҧ� ������ +
	REGISTER_COMMAND(iCommandPlaneZoomOut)					// ���٧ާ֧ߧ֧ߧڧ� �ާѧ���ѧҧ� ������ -
	REGISTER_COMMAND(iCommandPlaneModeNAV)					// ���֧�֧��� �� ��֧اڧ� �ߧѧӧڧԧѧ�ڧ�
	REGISTER_COMMAND(iCommandPlaneModeBVR)					// ���֧�֧��� �� ��֧اڧ� �էѧݧ�ߧ֧ԧ� �ӧ�٧է��ߧ�ԧ� �ҧ��
	REGISTER_COMMAND(iCommandPlaneModeVS)					// ���֧�֧��� �� ��֧اڧ� �ҧݧڧاߧ֧ԧ� �ӧ�٧է��ߧ�ԧ� �ҧ�� (���ݧ���)
	REGISTER_COMMAND(iCommandPlaneModeBore)					// ���֧�֧��� �� ��֧اڧ� �ҧݧڧاߧ֧ԧ� �ӧ�٧է��ߧ�ԧ� �ҧ�� (�ܧ�ݧ���)
	REGISTER_COMMAND(iCommandPlaneModeHelmet)				// ���֧�֧��� �� ��֧اڧ� �ҧݧڧاߧ֧ԧ� �ӧ�٧է��ߧ�ԧ� �ҧ�� (��ݧ֧�)
	REGISTER_COMMAND_EX(iCommandPlaneModeFI0, 110)				// ���֧�֧��� �� ��֧اڧ� FI0
	REGISTER_COMMAND(iCommandPlaneModeGround)				// ���֧�֧��� �� ��֧اڧ� �ѧ�ѧܧ� �ߧѧ٧֧ާߧ�� ��֧ݧ֧�
	REGISTER_COMMAND(iCommandPlaneModeGrid)					// ���֧�֧��� �� ��֧اڧ� "��֧�ܧ�"
	REGISTER_COMMAND(iCommandPlaneModeCannon)				// ���ܧݧ��֧ߧڧ�/�ӧ�ܧݧ��֧ߧڧ� ����ܧ�
	REGISTER_COMMAND(iCommandPlaneDoAndHome)					// ������ݧߧ� �٧ѧէѧߧڧ� �� �ӧ֧�ߧڧ�� �ߧ� �ҧѧ٧�
	REGISTER_COMMAND(iCommandPlaneDoAndBack)					// ������ݧߧ� �٧ѧէѧߧڧ� �� �ӧ֧�ߧڧ�� �ܧ� �ާߧ�
	REGISTER_COMMAND(iCommandPlaneFormation)					// ���է�� ��ѧ��֧�ߧߧ��/��ݧ��ߧ�� �����֧�
	REGISTER_COMMAND(iCommandPlaneJoinUp)					// ����ҧ�ѧ����
	REGISTER_COMMAND(iCommandPlaneAttackMyTarget)			// ����ѧܧ�� �ާ�� ��֧ݧ�
	REGISTER_COMMAND(iCommandPlaneCoverMySix)				// ����ڧܧ��� �ާ֧ߧ� ��٧ѧէ�
	REGISTER_COMMAND_EX(iCommandPlaneShipTakeOff, 120)			// ������ �ӧ٧ݧ֧�֧�� �� �ѧӧڧѧߧ����
	REGISTER_COMMAND(iCommandPlaneCobra)						// ���ѧߧ֧ӧ� ����ҧ��
	REGISTER_COMMAND(iCommandSoundOnOff)                     // ����ܧݧ��ڧ��/�ӧܧݧ��ڧ�� �٧ӧ�� (Administrative Action)
	REGISTER_COMMAND(iCommandSoundMicOn)						// ���ܧݧ��ڧ�� ���ڧ֧� �٧ӧ�ܧ� �� �ާڧܧ����ߧ� (Administrative Action)
	REGISTER_COMMAND(iCommandSoundMicOff)					// ����ܧݧ��ڧ�� ���ڧ֧� �٧ӧ�ܧ� �� �ާڧܧ����ߧ� (Administrative Action)
	REGISTER_COMMAND(iCommandViewRightMirrorOn)				// ���٧ԧݧ�� �ߧ� �٧֧�ܧѧݧ� (Non-simulation Action)
	REGISTER_COMMAND(iCommandViewRightMirrorOff)				// (Non-simulation Action)	
	REGISTER_COMMAND(iCommandViewLeftMirrorOn)				// (Non-simulation Action)			
	REGISTER_COMMAND(iCommandViewLeftMirrorOff)	// (Non-simulation Action)

	REGISTER_COMMAND(iCommandNaturalViewCockpitIn)			// ���ѧާ֧�� - �ܧѧҧڧߧ� (�֧��֧��ӧ֧ߧߧ�� �ӧ٧ԧݧ��) (Non-simulation Action)
	/* OBSOLETE */	REGISTER_COMMAND_EX(iCommandNaturalViewCockpitOut, 130)	// ���ѧާ֧�� �٧� �ܧѧҧڧߧ�� (�֧��֧��ӧ֧ߧߧ�� �ӧ٧ԧݧ��)
	REGISTER_COMMAND(iCommandViewLndgOfficer)				// ���ܧ�ӧ�էڧ�֧ݧ� ���ݧ֧�ѧާ� �ߧ� �ѧӧڧѧߧ����
	/* OBSOLETE */	REGISTER_COMMAND(iCommandViewCaptainBridge)				// �ܧѧ�ڧ�ѧߧ�ܧڧ� �ާ���ڧ� �ߧ� �ѧӧڧѧߧ����
	/* OBSOLETE */	REGISTER_COMMAND(iCommandViewGroundAndPlane)				// �ߧѧ٧֧ާߧ�� ��ҧ�֧ܧ� + �ӧѧ� ��ѧާ�ݧ֧�
	/* OBSOLETE */	REGISTER_COMMAND(iCommandViewPlaneAndGround) 			// �ӧѧ� ��ѧާ�ݧ֧� + �ߧѧ٧֧ާߧ�� ��ҧ�֧ܧ�
	REGISTER_COMMAND(iCommandViewWeaponAndTarget)			// ��ѧܧ֧�a �� ��֧ݧ� (Non-simulation Action)
	REGISTER_COMMAND(iCommandActiveJamming)
	REGISTER_COMMAND(iCommandLandDetailsIncrease)			// ����ݧѧէ��ߧ�� ��ӧ֧ݧڧ�֧ߧڧ� �է֧�ѧݧڧ٧ѧ�ڧ� (Non-simulation Action)
	REGISTER_COMMAND(iCommandLandDetailsDecrease)			// ����ݧѧէ��ߧ�� ��ާ֧ߧ��֧ߧڧ� �է֧�ѧݧڧ٧ѧ�ڧ� (Non-simulation Action)
	REGISTER_COMMAND(iCommandSelecterLeft)				    // �էӧڧا֧ߧڧ� �ާѧ�ܧ֧�� �٧ѧ�ӧѧ�� ��֧ݧ֧� �ߧ� HUD �ӧݧ֧ӧ�
	REGISTER_COMMAND_EX(iCommandSelecterRight, 140)			// �ӧ��ѧӧ�
	REGISTER_COMMAND(iCommandSelecterUp)					    // �ӧӧ֧��
	REGISTER_COMMAND(iCommandSelecterDown)					// �ӧߧڧ�
	REGISTER_COMMAND(iCommandRefusalTWS)						// ���ܧѧ� ��� ������
	REGISTER_COMMAND(iCommandPlaneResetMasterWarning)
	REGISTER_COMMAND(iCommandPlaneFlapsOn)
	REGISTER_COMMAND(iCommandPlaneFlapsOff)
	REGISTER_COMMAND(iCommandPlaneAirBrakeOn)
	REGISTER_COMMAND(iCommandPlaneAirBrakeOff)
	REGISTER_COMMAND(iCommandViewWeapons)				// ���ѧާ֧�� �ӧ����ا֧ߧڧ� (Non-simulation Action)
	REGISTER_COMMAND_EX(iCommandViewStatic, 150)			// ���ѧާ֧�� ���ѧ�ڧ�֧�ܧڧ� ��ҧ�֧ܧ��� (Non-simulation Action)
	REGISTER_COMMAND(iCommandViewTargets)				// ���ѧާ֧�� ��֧ݧ֧�
	REGISTER_COMMAND(iCommandInfoOnOff)					// ���֧�֧ܧݧ��ѧ�֧ݧ� �ڧߧ���ާѧ�ڧ�ߧߧ�� �����ܧ� (Non-simulation Action)
	/* OBSOLETE */REGISTER_COMMAND(iCommandInfoTextOnOff)				// ���ܧݧ��ڧ��/�ӧ�ܧݧ��ڧ�� �ӧ֧��ߧ�� �ڧߧ���ާѧ�ڧ�ߧߧ�� �����ܧ� (Non-simulation Action)
	/* OBSOLETE */REGISTER_COMMAND(iCommandInfoDataOnOff)				// ���ܧݧ��ڧ��/�ӧ�ܧݧ��ڧ�� �ߧڧاߧ�� �ڧߧ���ާѧ�ڧ�ߧߧ�� �����ܧ� (Non-simulation Action)
	REGISTER_COMMAND(iCommandPlaneAirRefuel)				// ���֧�֧ܧݧ��ѧ�֧ݧ� ���ݧ�ا֧ߧڧ� ���ѧߧԧ� �٧ѧ��ѧӧܧ�
	REGISTER_COMMAND(iCommandBrightnessILS)				// ����ܧ���� ILS
	/* OBSOLETE */REGISTER_COMMAND(iCommandGraphicsFrameRate)			// ���֧�֧ܧݧ��ѧ�֧ݧ� �ӧ�ӧ�է� ��ѧ����� �ܧѧէ��� (Administrative Action)
	REGISTER_COMMAND(iCommandViewFreeJump)				// ���֧�֧ܧݧ��֧ߧڧ� �ߧ� ��ӧ�ҧ�էߧ�� �ܧѧާ֧�� �� ��֧ܧ��֧� ���٧ڧ�ڧ� (Non-simulation Action)
	REGISTER_COMMAND(iCommandViewSpeedUp)				// ���ѧ٧�ԧߧѧ�� ��ӧ�ҧ�էߧ�� �ܧѧާ֧�� (���ݧ�اڧ�֧ݧ�ߧ�� ���ܧ��֧ߧڧ�) (Non-simulation Action)
	REGISTER_COMMAND_EX(iCommandViewSlowDown, 160)			// ���ѧާ֧էݧڧ�� ��ӧ�ҧ�էߧ�� �ܧѧާ֧�� (����ڧ�ѧ�֧ݧ�ߧ�� ���ܧ��֧ߧڧ�) (Non-simulation Action)
	REGISTER_COMMAND(iCommandPlaneAUTIncreaseLeft)
	REGISTER_COMMAND(iCommandPlaneAUTDecreaseLeft)
	REGISTER_COMMAND(iCommandPlaneAUTIncreaseRight)
	REGISTER_COMMAND(iCommandPlaneAUTDecreaseRight)
	/* OBSOLETE */REGISTER_COMMAND(iCommandPlaneAUTIncreaseRegimeLeft)
	/* OBSOLETE */REGISTER_COMMAND(iCommandPlaneAUTDecreaseRegimeLeft)
	/* OBSOLETE */REGISTER_COMMAND(iCommandPlaneAUTIncreaseRegimeRight)
	/* OBSOLETE */REGISTER_COMMAND(iCommandPlaneAUTDecreaseRegimeRight)
	REGISTER_COMMAND(iCommandPlaneImmortal)				// ���֧�֧ܧݧ��ѧ�֧ݧ� �ҧ֧��ާ֧��ڧ� ��ӧ�֧ԧ� ��ѧާ�ݧ֧��
	REGISTER_COMMAND_EX(iCommandPlaneJettisonFuelTanksUp, 170)
	REGISTER_COMMAND(iCommandPlaneJettisonWeaponsUp)
	/* OBSOLETE */REGISTER_COMMAND(iCommandPlaneAUTUnlockLeft)
	/* OBSOLETE */REGISTER_COMMAND(iCommandPlaneAUTUnlockRight)
	/* OBSOLETE */REGISTER_COMMAND(iCommandPlaneTrimViewOnOff)			// ���ܧ�/�ӧ�ܧ� �ڧߧէڧܧѧ�ڧ� ���ڧާާ֧�� �ߧ� ��������				
	REGISTER_COMMAND(iCommandPlaneLightsOnOff)			// ���ܧ�/�ӧ�ܧ� ��ԧߧ� �ߧ� ��ӧ�֧� ��ѧާ�ݧ֧��
	REGISTER_COMMAND(iCommandPlaneDropSnarOnce)			// ���էߧ�ܧ�ѧ�ߧ�� ��ҧ��� �ݧ�ӧ��֧�
	REGISTER_COMMAND(iCommandViewAngleDefault)			// �����ѧߧ�ӧڧ�� ��ާѧݧ�ڧӧѧ֧ާ�� ��ԧ�� ��ҧ٧��� �ܧѧާ֧�� (Non-simulation Action)
	REGISTER_COMMAND(iCommandPlaneJettisonFuelTanks)		// ���ҧ��� ����ݧڧӧߧ�� �ҧѧܧ��
	REGISTER_COMMAND(iCommandToggleCommandMenu)		// ����٧�� ��ѧߧ֧ݧ� �ܧ�ާѧߧ� �ӧ֧է�ާ��
	REGISTER_COMMAND_EX(iCommandViewSwitchReverse, 180)	// ���ҧ�ѧ�ߧ�� �ߧѧ��ѧӧݧ֧ߧڧ� ��֧�֧ܧݧ��֧ߧڧ� ��ҧ�֧ܧ��� (Non-simulation Action)
	REGISTER_COMMAND(iCommandViewSwitchForward)			// �����ާ�� �ߧѧ��ѧӧݧ֧ߧڧ� ��֧�֧ܧݧ��֧ߧڧ� ��ҧ�֧ܧ��� (Non-simulation Action)
	REGISTER_COMMAND(iCommandViewObjectIgnore)			// ���ԧߧ��ڧ��ӧѧ�� ��ҧ�֧ܧ� ���� ��֧�֧ܧݧ��֧ߧڧ�� �ߧ� �ߧ֧ԧ� (Non-simulation Action)
	REGISTER_COMMAND(iCommandViewObjectsAll)				// ����ڧ��ڧ�� ���ڧ��� �ڧԧߧ��ڧ��֧ާ�� ��ҧ�֧ܧ��� (Non-simulation Action)
	REGISTER_COMMAND(iCommandViewTerrainLock)			// ���ѧ�ӧѧ� ����ܧ� �ߧ� ���ӧ֧��ߧ���� �٧֧ާݧ� (Non-simulation Action)
	REGISTER_COMMAND(iCommandViewFromTo)					// ���֧�֧ܧݧ��ѧ�֧ݧ� �ߧѧ��ѧӧݧ֧ߧڧ� �ܧѧާ֧�� (��� ��ҧ�֧ܧ��/�ߧ� ��ҧ�֧ܧ�) (Non-simulation Action)
	REGISTER_COMMAND(iCommandPlaneDown)					// ����ߧܧ�� ����ѧӧݧ֧ߧڧ� �ѧӧ���ڧݧ���� ��� �ӧ�����
	REGISTER_COMMAND(iCommandPlaneUp)
	REGISTER_COMMAND(iCommandPlaneLeft)
	REGISTER_COMMAND(iCommandPlaneRight)
	REGISTER_COMMAND_EX(iCommandViewLocal, 190)			// ����ܧѧݧ�ߧ�� ���ӧ����� �ܧѧާ֧��
	REGISTER_COMMAND(iCommandDecelerate)					// ���ѧާ֧էݧ֧ߧڧ� �ާ�է֧ݧ�ߧ�ԧ� �ӧ�֧ާ֧ߧ� (Administrative Action)
	REGISTER_COMMAND(iCommandPlaneJump)      			// ���֧�֧�ܧѧܧڧӧѧߧڧ� �� ��֧ܧ��ڧ� ��ѧާ�ݧ֧�
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
	REGISTER_COMMAND(iCommandViewStop)							// ����֧ܧ�ѧ�ڧ�� �էӧڧا֧ߧڧ� �ܧѧާ֧�� (Non-simulation Action) 
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
	REGISTER_COMMAND(iCommandNoAcceleration)					// ����ܧ��֧ߧڧ� �ާ�է֧ݧ�ߧ�ԧ� �ӧ�֧ާ֧ߧ� = 1 (Administrative Action)
	REGISTER_COMMAND(iCommandPlaneHUDFilterOnOff)			// ����էߧ���/������ڧ�� ��ӧ֧���ڧݧ��� ������ (Ka-50)
	REGISTER_COMMAND(iCommandCockpitTakeControl)				// ���֧�֧ܧݧ��ѧ�֧ݧ� ����ѧӧݧ֧ߧڧ� �էݧ� ��֧�֧ӧ�ԧ� �ڧߧ��֧ܧ����
	/* NOT IMPL */REGISTER_COMMAND(iCommandRollbackSave)		// ����٧էѧߧڧ� ����ܧ� ���ܧѧ�� �� ���֧ܧ� (Administrative Action) 
	/* NOT IMPL */	REGISTER_COMMAND_EX(iCommandRollBack, 250)		// ����ܧѧ� �ߧ� ���֧է�է���� ����ܧ� (Administrative Action)
	/* NOT IMPL */REGISTER_COMMAND(iCommandRollForward)        // ���֧�֧��� �ߧ� ����ݧ֧է����� ����ܧ� (Administrative Action)
	REGISTER_COMMAND(iCommandPlaneMasterCaution)				// ���ߧѧݧ�� "���ܧ�ѧ� �ӧ�٧��" (���ڧ�-29) �ܧߧ��ܧ�-�ݧѧާ�� ������ (����-50)
	REGISTER_COMMAND(iCommandPlaneScalesReject)				// Scales reject / ��ԧ�ѧߧڧ�. �ڧߧէڧܧѧ�. �ߧ� ������ (����-50)
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
	REGISTER_COMMAND(iCommandPromotePlane)					// ���ܧ�ڧӧڧ٧ڧ��ӧѧ�� ��ܧ����ԧ� �ܧݧڧ֧ߧ�� (Inside Action)
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

	REGISTER_COMMAND(iCommandTransferCursor)					// ���֧�֧ާ֧�֧ߧڧ� �ܧ������ �ާ��� (�էݧ� ���֧ܧ��) (Administrative Action)
	REGISTER_COMMAND(iCommandRecordCursorOnOff)				// ���ܧݧ��֧ߧڧ�/�ӧ�ܧݧ��֧ߧڧ� �٧ѧ�ڧ�� �ܧ������ �ާ��� (�էݧ� ���֧ܧ��) (Inside Action)
	REGISTER_COMMAND(iCommandChangeRippleIntervalDown)		// ���٧ާ֧ߧ֧ߧڧ� �ڧߧ�֧�ӧѧݧ� ��ҧ���� �ҧ�ާ� �� �٧ѧݧ�� �էݧ� ��10 �� ��ҧ�ѧ�ߧ�� �ߧѧ��ѧӧݧ֧ߧڧ�

	REGISTER_COMMAND(iCommandEnginesStart)				// ���ѧ���� �էӧڧԧѧ�֧ݧ֧�
	REGISTER_COMMAND_EX(iCommandEnginesStop, 310)			// ����ܧݧ��֧ߧڧ� �էӧڧԧѧ�֧ݧ֧�

	REGISTER_COMMAND(iCommandLeftEngineStart)			// ���ѧ���� �ݧ֧ӧ�ԧ� �էӧڧԧѧ�֧ݧ�
	REGISTER_COMMAND(iCommandRightEngineStart)			// ���ѧ���� ���ѧӧ�ԧ� �էӧڧԧѧ�֧ݧ�

	REGISTER_COMMAND(iCommandLeftEngineStop)				// ����ܧݧ��֧ߧڧ� �ݧ֧ӧ�ԧ� �էӧڧԧѧ�֧ݧ�
	REGISTER_COMMAND(iCommandRightEngineStop)			// ����ܧݧ��֧ߧڧ� ���ѧӧ�ԧ� �էӧڧԧѧ�֧ݧ�

	REGISTER_COMMAND(iCommandPowerOnOff)					// Activer / d��sactiver le pouvoir (Puissance ��lectrique) - 315

	REGISTER_COMMAND(iCommandAltimeterPressureIncrease)	// ���ӧ֧ݧڧ�֧ߧڧ� �էѧӧݧ֧ߧڧ� �ߧ� ����
	REGISTER_COMMAND(iCommandAltimeterPressureDecrease)	// ���ާ֧ߧ��֧ߧڧ� �էѧӧݧ֧ߧڧ� �ߧ� ����
	REGISTER_COMMAND(iCommandAltimeterPressureStop)

	REGISTER_COMMAND(iCommandTrackEditReplace)			// ���֧اڧ� ��֧էѧܧ�ڧ��ӧѧߧڧ� ���֧ܧ� �� ���ާ֧ߧ�� ���ѧ��ԧ� (��� ��ާ�ݧ�ѧߧڧ�) (Administrative Action)
	REGISTER_COMMAND_EX(iCommandTrackEditInsert, 320)		// ���֧اڧ� ��֧էѧܧ�ڧ��ӧѧߧڧ� ���֧ܧ� �� �է�ҧѧӧݧ֧ߧڧ֧� �� ���ѧ��ާ� (Administrative Action)

	REGISTER_COMMAND(iCommandViewFastMouse)				// ���֧اڧ� ���ܧ��֧ߧߧ�� �ѧߧѧݧ�ԧ�ӧ�� ��֧�֧ާ֧�֧ߧڧ� �ܧѧާ֧��
	REGISTER_COMMAND(iCommandViewSlowMouse)				// ���֧اڧ� �٧ѧާ֧էݧ֧ߧߧ�� �ѧߧѧݧ�ԧ�ӧ�� ��֧�֧ާ֧�֧ߧڧ� �ܧѧާ֧��
	REGISTER_COMMAND(iCommandViewNormalMouse)			// ���֧اڧ� �ߧ��ާѧݧ�ߧ�� �ѧߧѧݧ�ԧ�ӧ�� ��֧�֧ާ֧�֧ߧڧ� �ܧѧާ֧��

	REGISTER_COMMAND(iCommandRecordSubtitleOn)			// ���ܧݧ��֧ߧڧ� ���ܧѧ٧� ���ҧ�ڧ���� (�էݧ� ���֧ܧ��) (Inside Action)
	REGISTER_COMMAND(iCommandRecordSubtitleOff)			// ����ܧݧ��֧ߧڧ� ���ܧѧ٧� ���ҧ�ڧ���� (�էݧ� ���֧ܧ��) (Inside Action)

	REGISTER_COMMAND(iCommandViewHUDOnlyOnOff)			// ���֧�֧ܧݧ��ѧ�֧ݧ� ��֧اڧާ� �ܧѧҧڧߧ� "����ݧ�ܧ� ������"

	REGISTER_COMMAND(iCommandRecoverHuman)				// �������ѧߧ�ӧڧ�� ����ާѧߧ�
	REGISTER_COMMAND(iCommandPlaneHeadLightOnOff)		// ���ܧ�/�ӧ�ܧ� ��ѧ�� �ߧ� ��֧�֧էߧ֧� ����ۧܧ� ��ѧ���

	REGISTER_COMMAND(iCommandPlaneLockPadlock)				// ���ݧ֧էڧ�� �٧� �ҧݧڧاѧۧ�ڧ� ��ҧ�֧ܧ���
	REGISTER_COMMAND_EX(iCommandPlaneUnlockPadlock, 330)		// ������ڧ�� ��ݧ֧էڧ�� �٧� ��ҧ�֧ܧ���

	REGISTER_COMMAND(iCommandViewFastKeyboard)			// ���֧اڧ� ���ܧ��֧ߧߧ�� �ܧݧѧӧڧ�ߧ�� ��֧�֧ާ֧�֧ߧڧ� �ܧѧާ֧��
	REGISTER_COMMAND(iCommandViewSlowKeyboard)			// ���֧اڧ� �٧ѧާ֧էݧ֧ߧߧ�� �ܧݧѧӧڧ�ߧ�� ��֧�֧ާ֧�֧ߧڧ� �ܧѧާ֧��
	REGISTER_COMMAND(iCommandViewNormalKeyboard)			// ���֧اڧ� �ߧ��ާѧݧ�ߧ�� �ܧݧѧӧڧ�ߧ�� ��֧�֧ާ֧�֧ߧڧ� �ܧѧާ֧��

	REGISTER_COMMAND(iCommandViewExternalZoomIn)			// Zoom �էݧ� �ӧߧ֧�ߧڧ� �ӧڧէ��	
	REGISTER_COMMAND(iCommandViewExternalZoomInStop)
	REGISTER_COMMAND(iCommandViewExternalZoomOut)
	REGISTER_COMMAND(iCommandViewExternalZoomOutStop)
	REGISTER_COMMAND(iCommandViewExternalZoomDefault)
	REGISTER_COMMAND(iCommandMouseViewOnOff)			// ���ߧѧ�֧ߧڧ� �ӧߧ֧�ߧ֧� �� �ܧ�ܧ�ڧ�ߧ�� ����ѧߧ�ӧ�� �ާ��� �էݧ� ���֧ܧ�� (Inside Action)

	REGISTER_COMMAND_EX(iCommandViewCameraMoveMode, 340)	// ���֧�֧ܧݧ��ѧ�֧ݧ� ��֧اڧާ� ��֧�֧ާ֧�֧ߧڧ� �ܧѧާ֧�� (��ݧ�ا֧ҧߧѧ� - �ӧާ֧��� �ܧݧѧӧڧ�� S �� ���֧ܧѧ�)
	REGISTER_COMMAND(iCommandViewFightGround)			// ���ѧާ֧�� ��ѧާ�ݧ֧�-�ߧѧ٧֧ާߧ�� ��ߧڧ�/�ܧ��ѧҧݧ� (Non-simulation Action)
	REGISTER_COMMAND(iCommandViewCameraUpLeft)			// ����ӧ���� �ܧѧާ֧�� �ӧӧ֧��-�ߧѧݧ֧ӧ� (Non-simulation Action)
	REGISTER_COMMAND(iCommandViewCameraUpRight)			// ����ӧ���� �ܧѧާ֧�� �ӧӧ֧��-�ߧѧ��ѧӧ� (Non-simulation Action)
	REGISTER_COMMAND(iCommandViewCameraDownLeft)			// ����ӧ���� �ܧѧާ֧�� �ӧߧڧ�-�ߧѧݧ֧ӧ� (Non-simulation Action)
	REGISTER_COMMAND(iCommandViewCameraDownRight)		// ����ӧ���� �ܧѧާ֧�� �ӧߧڧ�-�ߧѧ��ѧӧ� (Non-simulation Action)
	REGISTER_COMMAND(iCommandViewPanToggle)				// ���֧�֧ܧݧ��ѧ�֧ݧ� pan-��֧اڧާ� (Non-simulation Action)
	REGISTER_COMMAND(iCommandViewCameraReturn)			// ����٧ӧ�ѧ� �ܧѧާ֧�� (Non-simulation Action)
	REGISTER_COMMAND(iCommandViewLocomotivesToggle)		// ���ڧݧ��� ���ݧ�ܧ�_�ݧ�ܧ�ާ��ڧӧ�/�ӧ�� �էݧ� Ctrl-F12 (Non-simulation Action)
	REGISTER_COMMAND(iCommandPlaneLaunchPermissionOverride)	// ���ߧ��ڧ� �ҧݧ�ܧڧ��ӧܧ� �� ����اڧ�
	REGISTER_COMMAND_EX(iCommandPlanePickleOn, 350)		// ������ ��ѧܧ֧�/��ҧ��� �ҧ�ާ� �էݧ� �٧ѧ�ѧէߧ�� ��ѧާ�ݧ֧���
	REGISTER_COMMAND(iCommandPlanePickleOff)
	REGISTER_COMMAND(iCommandViewCameraBaseReturn)		// ����٧ӧ�ѧ� �ҧѧ٧ڧ�� �ܧѧާ֧�� (Non-simulation Action)
	REGISTER_COMMAND(iCommandViewCameraUpLeftSlow)		// ����ӧ���� �ܧѧާ֧�� �ӧӧ֧��-�ߧѧݧ֧ӧ� �ާ֧էݧ֧ߧߧ�� (Non-simulation Action)
	REGISTER_COMMAND(iCommandViewCameraUpRightSlow)		// ����ӧ���� �ܧѧާ֧�� �ӧӧ֧��-�ߧѧ��ѧӧ� �ާ֧էݧ֧ߧߧ�� (Non-simulation Action)
	REGISTER_COMMAND(iCommandViewCameraDownLeftSlow)		// ����ӧ���� �ܧѧާ֧�� �ӧߧڧ�-�ߧѧݧ֧ӧ� �ާ֧էݧ֧ߧߧ�� (Non-simulation Action)
	REGISTER_COMMAND(iCommandViewCameraDownRightSlow)	// ����ӧ���� �ܧѧާ֧�� �ӧߧڧ�-�ߧѧ��ѧӧ� �ާ֧էݧ֧ߧߧ�� (Non-simulation Action)
	REGISTER_COMMAND(iCommandPlaneDropFlareOnce)			// ���էߧ�ܧ�ѧ�ߧ�� ��ҧ��� ����-�ݧ�ӧ��֧�
	REGISTER_COMMAND(iCommandPlaneDropChaffOnce)			// ���էߧ�ܧ�ѧ�ߧ�� ��ҧ��� �էڧ��ݧ�ߧ�� ����ѧاѧ�֧ݧ֧�
	REGISTER_COMMAND(iCommandViewRear)					// ���ڧ� �ߧѧ٧ѧ� (Non-simulation Action)
	REGISTER_COMMAND_EX(iCommandScoresWindowToggle, 360)			// ���ܧѧ٧ѧ��\��ܧ���� ��ܧߧ� ��֧�֧ӧ�� ���ѧ�ڧ��ڧܧ� �� ��֧اڧާ� ��ڧާ�ݧ��ڧ�
	REGISTER_COMMAND(iCommandCockpitClickOn)		// ���ѧ�ѧ�� ����ѧӧݧ֧ߧڧ� ��ܧѧ٧ѧߧߧ�� �ܧ�ߧ���ݧ�� �� �ܧѧҧڧߧ�
	REGISTER_COMMAND(iCommandCockpitClickOff)	// ���ѧӧ֧��ڧ�� ����ѧӧݧ֧ߧڧ� ��֧ܧ��ڧ� ����ѧӧݧ�֧ާ�� �ܧ�ߧ���ݧ�� �� �ܧѧҧڧߧ�
	REGISTER_COMMAND(iCommandCockpitClickModeOnOff)	// ���֧اڧ� Clickable cockpit �ӧܧݧ��ڧ��/�ӧ�ܧݧ��ڧ��

	// CMD
	REGISTER_COMMAND(iCommandPlaneCMDDispence)				// ���ѧ��ڧӧߧ�� ���֧է��ӧ� ������ �ӧ�ҧ��� �ݧ�ӧ��֧�
	REGISTER_COMMAND(iCommandPlaneCMDDispenceOff)
	REGISTER_COMMAND(iCommandPlaneCMDDispenceStop)			// ���ѧ��ڧӧߧ�� ���֧է��ӧ� ������ ����ѧߧ�ӧܧ� �ӧ�ҧ���� �ݧ�ӧ��֧�
	REGISTER_COMMAND(iCommandPlaneCMDDispenceStopOff)
	REGISTER_COMMAND(iCommandPlaneCMDChangeRippleQuantity)	// ���ѧ��ڧӧߧ�� ���֧է��ӧ� ������ �ڧ٧ާ֧ߧڧ�� �ܧ�ݧڧ�֧��ӧ� �� ��֧�ڧ�
	REGISTER_COMMAND(iCommandPlaneCMDChangeRippleQuantityOff)
	REGISTER_COMMAND_EX(iCommandPlaneCMDChangeRippleInterval, 370)	// ���ѧ��ڧӧߧ�� ���֧է��ӧ� ������ �ڧ٧ާ֧ߧڧ�� �ڧߧ�֧�ӧѧ� �� ��֧�ڧ�
	REGISTER_COMMAND(iCommandPlaneCMDChangeRippleIntervalOff)
	REGISTER_COMMAND(iCommandPlaneCMDChangeBurstAmount)		// ���ѧ��ڧӧߧ�� ���֧է��ӧ� ������ �ڧ٧ާ֧ߧڧ�� �ܧ�ݧڧ�֧��ӧ� ��֧�ڧ�
	REGISTER_COMMAND(iCommandPlaneCMDChangeBurstAmountOff)
	REGISTER_COMMAND(iCommandPlaneCMDCancelCurrentProgram)	// ���ѧ��ڧӧߧ�� ���֧է��ӧ� ������ ��ҧ��� ����ԧ�ѧާާ�
	REGISTER_COMMAND(iCommandPlaneCMDCancelCurrentProgramOff)
	REGISTER_COMMAND(iCommandPlaneCMDChangeBoard)			// ���ѧ��ڧӧߧ�� ���֧է��ӧ� ������ �ӧ�ҧ�� �ҧ����
	REGISTER_COMMAND(iCommandPlaneCMDShowAmountOrProgram)	// ���ѧ��ڧӧߧ�� ���֧է��ӧ� ������ ��ާ֧ߧ� �ڧߧէڧܧѧ�ڧ� - �ߧѧݧڧ�ڧ� �ݧ�ӧ��֧� �ڧݧ� ��֧ܧ��ѧ� ����ԧ�ѧާާ�

	REGISTER_COMMAND(iCommandPlaneCancelWeaponsDelivery)		// ��ҧ��� ��֧اڧާ� ��ѧҧ��� �ѧӧڧ�ߧڧܧ� (���� - 50)
	REGISTER_COMMAND(iCommandPlaneMasterCautionOff)
	// �֧�ݧ� ������ �ߧ֧�ܧ�ݧ�ܧ� ��ѧ���֧է֧ݧ֧ߧڧ� ����ڧ���էڧ� ��� �ڧէ֧ߧ�ڧ�ڧܧѧ���� ������ۧ��ӧ�  �� ���ҧ��ڧ� iCommandCockpitClickOn �ӧߧ���� Cockpit ���. cockpit::Clickable
	// ����֧է֧ݧ֧ߧڧ� ��֧�֧ߧ֧�֧ߧ� �� Actions.h 	�� ��ݧ֧է��ӧڧ� ��ѧ�ѧާ֧��ڧ٧ѧ�ڧ� �ӧ�٧�ӧ� ��� �ڧէ֧ߧ�ڧ�ڧܧѧ���� ������ۧ��ӧ�
	REGISTER_COMMAND_EX(iCommandPlane_SpotLight_hor_stop, 380)
	REGISTER_COMMAND(iCommandHelicopter_SelectWeapon_hor_up)
	REGISTER_COMMAND(iCommandHelicopter_SelectWeapon_vert_up)
	REGISTER_COMMAND(iCommandViewChaseArcade) // chase �ܧѧާ֧�� �էݧ� �ѧ�ܧѧէߧ�ԧ� �ӧڧէ� ) ��ݧѧӧѧ��ѧ�									
	REGISTER_COMMAND(iCommandAutoLockOnClear)		// ��ߧ��� ��֧ݧ� �� EasyRadar
	REGISTER_COMMAND_EX(iCommandHelicopterHover_up, 385)
	REGISTER_COMMAND(iCommandPlaneStabTangBank)			// ����ѧҧڧݧڧ٧ѧ�ڧ� ��ѧߧԧѧا� �� �ܧ�֧ߧ�
	REGISTER_COMMAND(iCommandPlaneStabHbarBank)			// ����ѧҧڧݧڧ٧ѧ�ڧ� Hbar �� �ܧ�֧ߧ�
	REGISTER_COMMAND(iCommandPlaneStabHorizon)			// ����ѧҧڧݧڧ٧ѧ�ڧ� ��ѧߧԧѧا� �� �ܧ�֧ߧ�
	REGISTER_COMMAND(iCommandPlaneStabHbar)				// ����ѧҧڧݧڧ٧ѧ�ڧ� Hbar
	REGISTER_COMMAND_EX(iCommandPlaneStabHrad, 390)				// ����ѧҧڧݧڧ٧ѧ�ڧ� Hrad
	REGISTER_COMMAND(iCommandActiveIRJamming)			// IR OnOff
	REGISTER_COMMAND(iCommandPlaneLaserRangerOnOff)		// ���ܧ�/����ܧ� �ݧѧ٧֧�ߧ�� �էѧݧ�ߧ�ާ֧�
	REGISTER_COMMAND(iCommandPlaneNightTVOnOff)         // ���ܧ�/����ܧ� �ߧ��ߧ�� �ܧѧߧѧ� ��֧ݧ֧ӧڧ٧ڧ�ߧߧ�� ��ڧ��֧ާ� (IR or LLTV) 
	REGISTER_COMMAND(iCommandPlaneChangeRadarPRF)       // ���٧ާ֧ߧڧ�� ��ѧ����� ���ӧ���֧ߧڧ� �ڧާ��ݧ���� ��ѧէѧ��
	REGISTER_COMMAND(iCommandViewKeepTerrain)			// ���է֧�اڧӧѧ�� ��ӧ�ҧ�էߧ�� �ܧѧާ֧�� ��ܧ�ݧ� �٧֧ާݧ�
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
	REGISTER_COMMAND(iCommandPlaneStabCancel)			// ���ҧ��� �ӧ�֧� ��֧اڧާ�� ���ѧҧڧݧڧ٧ѧ�ڧ� �� �ѧӧ���ڧݧ���
	REGISTER_COMMAND(iCommandPlaneThreatWarnSoundVolumeDown)	// ���ާ֧ߧ��֧ߧڧ� �ԧ��ާܧ���� �٧ӧ�ܧ�ӧ�� ��ڧԧߧѧݧ�� ������
	REGISTER_COMMAND_EX(iCommandPlaneThreatWarnSoundVolumeUp, 410)	// ���ӧ֧ݧڧ�֧ߧڧ� �ԧ��ާܧ���� �٧ӧ�ܧ�ӧ�� ��ڧԧߧѧݧ�� ������
	REGISTER_COMMAND(iCommandViewLaserOnOff)
	REGISTER_COMMAND(iCommandPlaneIncreaseBase_Distance)     // ���ӧ֧ݧڧ�֧ߧڧ� �ҧѧ٧� ��֧ݧ�
	REGISTER_COMMAND(iCommandPlaneDecreaseBase_Distance)     // ���ާ֧ߧ��֧ߧڧ� �ҧѧ٧� ��֧ݧ�
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
	REGISTER_COMMAND(iCommandCockpitSecondClickOn)	// �֧��� �ߧ֧ܧ������ �ܧ�ߧ���ݧ� �ܧ������ ��էߧ�ӧ�֧ާ֧ߧߧ� ���� �� �ܧߧ��ܧ� 
	REGISTER_COMMAND(iCommandCockpitSecondClickOff)	// ���ѧӧ֧��ڧ�� ����ѧӧݧ֧ߧڧ� ��֧ܧ��ڧ� ����ѧӧݧ�֧ާ�� �ܧ�ߧ���ݧ�� �� �ܧѧҧڧߧ�
	REGISTER_COMMAND(iCommandCompassRose)
	REGISTER_COMMAND(iCommandViewAWACSClearDistance)
	REGISTER_COMMAND(iCommandViewAWACSOutOfFocus)
	REGISTER_COMMAND(iCommandViewNightVisionGogglesOn)
	REGISTER_COMMAND(iCommandPlaneDesignate_CageOn)
	REGISTER_COMMAND_EX(iCommandPlaneDesignate_CageOff, 440)
	REGISTER_COMMAND(iCommandPlaneDesignate_CageOn_vertical)
	REGISTER_COMMAND(iCommandPlaneDesignate_CageOn_horizontal)

	//Data Link Panel PRTs (����ݧ�� ���֧اڧާ�� ���֧ݧ֧�ܧѧ٧ѧߧڧ� ������)
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

	// NAV panel controls (����-50 - ��ڧ��� ������)
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

	REGISTER_COMMAND(iCommandPlane_LockOn_start)          //����-50 ���� �ߧѧاѧ�� 
	REGISTER_COMMAND_EX(iCommandPlane_LockOn_finish, 510) //����-50 ���� ���اѧ��

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
	// �� �ܧѧ�֧��ӧ� Slew Control Hat Switch (TDC)
	// �� Weapon Release Switch �ҧ�է�� �ڧ���ݧ�٧�ӧѧ����
	// ��ا� ����֧��ӧ���ڧ� �ܧ�ާѧߧէ� (iCommandSelecter... ��
	// iCommandPlanePickleOn).
	// ������ӧ֧���ӧ֧ߧߧ� ��ߧ� �է�ݧاߧ� �ߧѧ��էڧ���� �� �ܧѧ�֧ԧ��ڧ� HOTAS

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
	REGISTER_COMMAND(iCommandPlane_R_800_Power_on_off)//���ާҧݧ֧� ������-2

	REGISTER_COMMAND(iCommandPlane_R_828_Channel_next)
	REGISTER_COMMAND(iCommandPlane_R_828_Channel_prevous)
	REGISTER_COMMAND(iCommandPlane_R_828_Noise_Reductor_on_off)
	REGISTER_COMMAND_EX(iCommandPlane_R_828_ASU, 625)
	REGISTER_COMMAND(iCommandPlane_R_828_volume_up)
	REGISTER_COMMAND(iCommandPlane_R_828_volume_down)
	REGISTER_COMMAND(iCommandPlane_R_828_Power_on_off)//���ާҧݧ֧� ������-1

	REGISTER_COMMAND(iCommandPlane_SPU9_SPU_9_on_off) //���ާҧݧ֧� ��������
	REGISTER_COMMAND_EX(iCommandPlane_SPU9_radio_change, 630)

	REGISTER_COMMAND(iCommandPlaneCollectiveIncrease)  //�էڧ�ܧ�֧�ߧ�� ����ѧӧݧ֧ߧڧ� ����ܧ�� ������-������
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
	//������
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

	REGISTER_COMMAND(iCommandReloadTables)			// ���֧�֧٧ѧԧ��٧ڧ�� ��ѧҧݧڧ��. ����ԧ�ҧ� ���ݧѧէ��ߧѧ� �ܧ�ާѧߧէ�.

	REGISTER_COMMAND_EX(iCommandPlane_JettisonMode_explosion, 850)
	REGISTER_COMMAND(iCommandPlane_ShowControls)

	REGISTER_COMMAND(iCommandPlane_CallHelpWindow)

	// ���֧�֧ߧѧ����ۧܧ� ��ҧ������ ��ӧ�ҧ�էߧ�� ����ҧڧߧ� ("����ާڧ�. - ���ڧ٧�.")
	REGISTER_COMMAND(iCommandPlane_ReadjustFreeTurbineRPM_Up)
	REGISTER_COMMAND(iCommandPlane_ReadjustFreeTurbineRPM_Down)

	REGISTER_COMMAND_EX(iCommandPlaneWheelParkingBrake, 855)	// �����ߧ��ߧ�� ����ާ�� �ܧ�ݧ֧�

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

	//�ӧ֧��ߧ�� �ݧ֧ӧѧ� ��ѧߧ֧ݧ�
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


	REGISTER_COMMAND(iCommandPlaneTrimOn)					// ���ѧاѧ�� �ܧߧ��ܧ� ���ڧާާ֧�� (�ӧ֧���ݧ֧� �ڧݧ� ��֧�֧ӧ�� ������ �� ��֧اڧ� �ܧߧ��֧ݧ� ���ڧާާ֧��)
	REGISTER_COMMAND(iCommandPlaneTrimOff)					// ����اѧ�� �ܧߧ��ܧ� ���ڧާާ֧��

	REGISTER_COMMAND(iCommandPlaneLevitation)

	REGISTER_COMMAND_EX(iCommandPlaneEmergencyBrake, 960)
	REGISTER_COMMAND(iCommandPlaneWheelBrakeLeftOn)			// ���ܧݧ��֧ߧڧ� ����ާ�٧� �ݧ֧ӧ�ԧ� �ܧ�ݧ֧��
	REGISTER_COMMAND(iCommandPlaneWheelBrakeLeftOff)		// ����ܧݧ��֧ߧڧ� ����ާ�٧� �ݧ֧ӧ�ԧ� �ܧ�ݧ֧��
	REGISTER_COMMAND(iCommandPlaneWheelBrakeRightOn)		// ���ܧݧ��֧ߧڧ� ����ާ�٧� ���ѧӧ�ԧ� �ܧ�ݧ֧��
	REGISTER_COMMAND(iCommandPlaneWheelBrakeRightOff)		// ����ܧݧ��֧ߧڧ� ����ާ�٧� ���ѧӧ�ԧ� �ܧ�ݧ֧��
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

	REGISTER_COMMAND(iCommandThrottleIncrease) //�ܧݧѧӧڧѧ���ߧ�� "��ݧѧӧߧ��" ����ѧӧݧ֧ߧڧ� ������
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

	REGISTER_COMMAND(iCommandViewJFO) //�ܧѧާ֧�� ���ڧӧ�٧ѧߧߧѧ� �� ��ߧڧ��
	REGISTER_COMMAND(iCommandViewSmoke1) //����ާ� �ߧѧӧ�է�ڧܧ�
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
	REGISTER_COMMAND(iCommandGViewAction)    //Dmut: ��֧�֧ܧݧ��֧ߧڧ� �ߧ� �ܧѧާ֧��-���ڧ�֧� �էݧ� �ߧѧ٧֧ާܧ�
	REGISTER_COMMAND(iCommandGChangeWS)      //Dmut: ��ާ֧ߧ� �ѧܧ�ڧӧߧ�ԧ� ����اڧ� (��� ��ڧܧݧ�)
	REGISTER_COMMAND(iCommandGChangeLN)      //Dmut: ��ާ֧ߧ� �ѧܧ�ڧӧߧ�ԧ� ����اڧ� (��� ��ڧܧݧ�)
	REGISTER_COMMAND(iCommandGReloadWeapon)  //Dmut: ��֧�֧٧ѧ��էܧ� �ѧܧ�ڧӧߧ�ԧ� ����اڧ�
	REGISTER_COMMAND(iCommandGFire)          //Dmut: �ӧ����֧� �ڧݧ� �ߧѧ�ѧݧ� ���֧�֧է� 
	REGISTER_COMMAND(iCommandGFireStop)      //Dmut: �ܧ�ߧ֧� ���֧�֧է� 
	REGISTER_COMMAND(iCommandGZoomIn)        //Dmut: ���ڧҧݧڧ٧ڧ�� FOV
	REGISTER_COMMAND(iCommandGZoomOut)    //Dmut: �ӧ֧�ߧ��� �� �ߧ��ާ� FOV
	REGISTER_COMMAND(iCommandGChangeSpeedH)  //SFINX �ѧݧ��֧�ߧѧ�ڧӧߧ�� ����ѧӧݧ֧ߧڧ� (��� ��ܧ������) ��� �ԧ��ڧ٧�ߧ��
	REGISTER_COMMAND(iCommandGChangeSpeedV)  //SFINX �ѧݧ��֧�ߧѧ�ڧӧߧ�� ����ѧӧݧ֧ߧڧ� (��� ��ܧ������) ��� �ӧ�����
	REGISTER_COMMAND(iCommandGLockon)        //Dmut: �٧ѧ�ӧѧ�ڧ�� ��֧ݧ�
	REGISTER_COMMAND(iCommandGLockoff)       //Dmut: ��ߧ��� �٧ѧ�ӧѧ� ��֧ݧ�
	REGISTER_COMMAND(iCommandGGroupModeOn)  //���ܧݧ��ڧ�� ��֧اڧ� ����ѧӧݧ֧ߧڧ� �ԧ������ (3d �ӧڧ�)
	REGISTER_COMMAND(iCommandGGroupModeOff) //����ܧݧ��ڧ�� ��֧اڧ� ����ѧӧݧ֧ߧڧ� �ԧ������
	REGISTER_COMMAND(iCommandGHoldCursorModeOn)  //���ܧݧ��ڧ�� ���ڧӧ�٧ܧ� �ܧ������ �� ��ܧ�ѧߧߧ�� �ܧ���էڧߧѧ�ѧ� ���� ����֧ݧ�ҧ�
	REGISTER_COMMAND(iCommandGHoldCursorModeOff) //����ܧݧ��ڧ�� ���ڧӧ�٧ܧ� �ܧ������ �� ��ܧ�ѧߧߧ�� �ܧ���էڧߧѧ�ѧ� ���� ����֧ݧ�ҧ�

	REGISTER_COMMAND(iCommandViewParticleEffect) //�էݧ� ���ݧѧէܧ�: ���٧էѧ�� ��֧ܧ��ڧ� ����֧ܧ�, �� �ާ֧��� �ܧ�է� ��ާ���ڧ� �ܧѧާ֧��

	REGISTER_COMMAND(iCommandPlaneShowKneeboard)

	REGISTER_COMMAND(iCommandGIsometricView) //Dmut: �ӧ�ߧ֧�֧ߧߧѧ� ����ܧ� �ܧѧާ֧�� ON\OFF
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
	/* OBSOLETE */REGISTER_COMMAND(iCommandGZoomUpdate)    //Panov: �ӧ���ѧӧڧ�� FOV ���� ��ާ֧ߧ� ����اڧ� (GroundCockpit)
	REGISTER_COMMAND(iCommandTakeControlTrack) // �էݧ� �ާѧ�ڧߧ��

	REGISTER_COMMAND(iCommandGSelectFeedSlot1)      //SFINX: �ӧ�ҧ�� 1-�ԧ� ��ݧ��� ���էѧ�� �ҧ�֧��ڧ�ѧ���
	REGISTER_COMMAND(iCommandGSelectFeedSlot2)      //SFINX: �ӧ�ҧ�� 2-�ԧ� ��ݧ��� ���էѧ�� �ҧ�֧��ڧ�ѧ���
	REGISTER_COMMAND(iCommandGEmissionToggle) // SFINX: �ӧܧݧ��֧ߧڧ� �� ���ܧݧ��֧ߧڧ� �ڧ٧ݧ��֧ߧڧ� (���է� �ا� �ݧѧ٧֧�ߧ�� �էѧݧ�ߧ�ާ֧��)

	REGISTER_COMMAND(iCommandToggleMirrors) // on/off mirrors rendering in cockpit
	REGISTER_COMMAND(iCommandToggleReceiveMode) // on/off mirrors rendering in cockpit

	REGISTER_COMMAND(iCommandPlaneChangeLockUp) // informs avionics that iCommandPlaneChangeLock key was released
	REGISTER_COMMAND(iCommandTrainingUserRespondedBack) // user do not understand at want to repeat 

	REGISTER_COMMAND(iCommandClockElapsedTimeReset) // Reset Clock elapsed time meter

	// �ݧѧ٧֧�ߧ�� �էѧݧ�ߧ�ާ֧� �� �ߧѧ٧֧ާߧ�� �ܧ�ܧ�ڧ��
	REGISTER_COMMAND(iCommandGLaserRangerOn)
	REGISTER_COMMAND(iCommandGLaserRangerOff)
	REGISTER_COMMAND(iCommandGLaserRangerReset)
	//�ܧ�ާѧߧէ� �էݧ� �ԧ��٧�
	REGISTER_COMMAND(iCommandExtCargoHook)
	REGISTER_COMMAND(iCommandExternalCargoAutounhook)
	// Example of usage: F-15 Return To Search, F-15 reset to NDTWS
	REGISTER_COMMAND(iCommandSensorReset)

	REGISTER_COMMAND(iCommandViewInfoControlPanelOnOff)

	// ����ާѧߧէ� ����ѧӧݧ֧ߧڧ� ���ӧ������ �ҧѧ�ߧ� �ާѧ�ڧߧܧ� �էݧ� �ܧݧѧӧڧѧ����

	REGISTER_COMMAND(iCommandRotateTurretLeftPressed) // ����ӧ���� �ҧѧ�ߧ� �ӧݧ֧ӧ�.
	REGISTER_COMMAND(iCommandRotateTurretRightPressed) // ����ӧ���� �ҧѧ�ߧ� �ӧ��ѧӧ�.
	REGISTER_COMMAND(iCommandRotateTurretUpPressed) // ����է�֧� ���ӧ�ݧ� �ҧѧ�ߧ� �ӧӧ֧��.
	REGISTER_COMMAND(iCommandRotateTurretDownPressed) // ������ܧѧߧڧ� ���ӧ�ݧ� �ҧѧ�ߧ� �ӧߧڧ�.

	//Track or mission restart on the way
	REGISTER_COMMAND(iCommandMissionRestart)

	REGISTER_COMMAND(iCommandVehicle_ReloadStart) // For manual reloading
	REGISTER_COMMAND(iCommandVehicle_AmmoMaintainInterrupt) // To abort reloading|rearming
	REGISTER_COMMAND(iCommandReloadShaders) // ��֧�֧ܧ�ާ�ڧݧڧ��ӧѧ�� �ڧ٧ާ֧ߧ֧ߧߧ�� ��֧ۧէ֧��

	REGISTER_COMMAND(iCommandVehicleElevationCorrectionUp)
	REGISTER_COMMAND(iCommandVehicleElevationCorrectionDown)
	REGISTER_COMMAND(iCommandVehicleAzimuthCorrectionLeft)
	REGISTER_COMMAND(iCommandVehicleAzimuthCorrectionRight)

	REGISTER_COMMAND(iCommandVehicleSightReticleAlternate)

	REGISTER_COMMAND(iCommandExternalCargoIndicator)

	REGISTER_COMMAND(iCommandGReticleLightToggle)
	REGISTER_COMMAND(iCommandGZoomInPressed)
	REGISTER_COMMAND(iCommandGZoomOutPressed)

	REGISTER_COMMAND(iCommandRotateTurretLeftReleased) // �����ѧߧ�� ���ӧ����� �ҧѧ�ߧ� �ӧݧ֧ӧ�.
	REGISTER_COMMAND(iCommandRotateTurretRightReleased) // �����ѧߧ�� ���ӧ����� �ҧѧ�ߧ� �ӧ��ѧӧ�.
	REGISTER_COMMAND(iCommandRotateTurretUpReleased) // �����ѧߧ�� ���է�֧ާ� ���ӧ�ݧ� �ҧѧ�ߧ� �ӧӧ֧��.
	REGISTER_COMMAND(iCommandRotateTurretDownReleased) // �����ѧߧ�� �����ܧѧߧڧ� ���ӧ�ݧ� �ҧѧ�ߧ� �ӧߧڧ�.

	// ����֧ݧ�ҧ� �ڧ� ���ѧ�֧ߧߧ�ԧ� ���ݧ֧ާ֧�� �� ���ߧ�ӧߧ�ԧ� ����էڧ� ��� ��ѧ٧ߧ�� �ܧߧ��ܧѧ�
	REGISTER_COMMAND(iCommandVehicle_FireSecondary)
	REGISTER_COMMAND(iCommandVehicle_FireSecondaryOff)

	REGISTER_COMMAND(iCommand_Ground_IFF_Down)
	REGISTER_COMMAND(iCommandDriverView)

	// Ins��rer nouvelles commandes juste avant ce commentaire!
	// ATTENTION! Avec 500 d��parts commande analogique.
	// Oykin: lancer des commandes analogiques report��es �� 2000
	REGISTER_COMMAND(iCommandMaximum)							// ����ݧڧ�֧��ӧ� �ӧ�֧� �ܧ�ާѧߧ�
	// ����է� �ߧڧ�֧ԧ� �ߧ� �ӧ��ѧӧݧ���!

#ifndef INPUT_LUA_BINDING
};
#endif

#endif

#ifdef INPUT_LUA_BINDING
#define _ICOMMAND_H_
#endif