// ConsoleApplication1.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
#pragma once
#pragma comment (lib, "Lua.lib")
extern "C"
{
	#include "lua.h"
	#include "lualib.h"
	#include "lauxlib.h"
}
#include "pch.h"
#include <iostream>
#include <windows.h>

#define MAX_FILEPATH_LENGTH 255

int main(int argc, char**argv)
{
	char filepath[MAX_FILEPATH_LENGTH];
	strcpy_s(filepath,"main.lua");
	if (argc == 2)
	{
		printf("\nFile name passed, running: %s", argv[1]);
		strcpy_s(filepath, argv[1]);
	}
	else
	{
		printf("\nNo file name, running main.lua");
	}

	lua_State* L;

	//init lua interpreter
	L = luaL_newstate();

	//load lua base libs
	luaL_openlibs(L);
	printf("\nStart Lua\n");
	try
	{
		luaL_dofile(L, filepath);
	}
	catch (const std::exception e)
	{
		printf("\nLua file failed with exception: %s", e.what());
	}

	printf("\nEnd Lua");
	//Dealloc all associated space
	lua_close(L);

	printf("\nPress enter to exit...");
	getchar();

	return 0;
}