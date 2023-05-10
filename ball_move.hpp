#pragma once

#include "Direction.h"

void ball_move(
	int field_height,
	int& ball_y, int& ball_x,
	Direction direction
) {
	if (direction & LEFT)
		--ball_x;
	else
		++ball_x;

	if (ball_y == field_height)
		direction = (Direction)(direction & ~UP | DOWN);
	else if (ball_y == 0)
		direction = (Direction)(direction & ~DOWN | UP);

	if (direction & UP)
		--ball_y;
	if (direction & DOWN)
		++ball_y;
}
