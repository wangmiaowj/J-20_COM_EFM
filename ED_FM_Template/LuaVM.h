#pragma once
//=========================================================================//
//
//		FILE NAME	: LuaVM.h
//		AUTHOR		: Joshua Nelson
//		DATE		: Feb 2021
//
//		This file falls under the licence found in the root ExternalFM directory.
//
//		DESCRIPTION	:	Lua helper, for config files.
//
//================================ Includes ===============================//
#include "ccParametersAPI.h"
#include "include/FM/wHumanCustomPhysicsAPI.h"
#include <vector>
#include "Vec3.h"
#include "LERX.h"

extern "C"
{
#define LUA_BUILD_AS_DLL
#include "include/lua/lua.h"
#include "include/lua/lauxlib.h"
#include "include/lua/lualib.h"
}

#pragma comment(lib, "libs/lua.lib")

class LuaVM
{
public:
	LuaVM();
	~LuaVM();

	lua_State* L();

	bool dofile(const char* path);
	bool getGlobalNumber(const char* name, double& number);
	const char* getGlobalString(const char* name);
	bool getGlobalTableNumber(const char* table, const char* key, float& result);
	void getSplines(const char* name, std::vector<LERX>& vec);
	bool outputCommands(const char* name);
	bool outputDevices(const char* name);
	void getTerrainTbl();
	void convertLatLonToMeters(double lat, double lon, double& x, double& y);
	void convertMetersToLatLon(double x, double y, double& lat, double& lon);
private:

	bool writeTableKeysToFile(FILE* file, const char* name);

	void getSpline(std::vector<LERX_vortex_spline_point>& vec);
	bool getTableVec3(const char* name, float* vec);
	bool processSplinePoint(LERX_vortex_spline_point& point);

	bool luaOkay(const int status);
	bool getTableValue(const char* key);
	bool getTableNumber(const char* key, float& value);

	bool getTableLuaFunction(const char* key);


	lua_State* m_state = NULL;

	cockpit_param_api m_api;
};