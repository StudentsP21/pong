#pragma once

#include <Windows.h>

bool isKeyDown(char key) {
	return GetKeyState(key) & 0x8000;
}

void handle_player_control(int& player_y) {
	if (isKeyDown(VK_UP))
	{
		player_y--;
	}
	if (isKeyDown(VK_DOWN))
	{
		player_y++;
	}
}



