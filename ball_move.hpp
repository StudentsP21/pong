#pragma once

#include "Direction.h"
#include "check_ball.hpp" 

void ball_move(
	int field_height,
	int field_width,
	int& ball_y, int& ball_x,
	Direction& direction,
	int left_platform_y,
	int right_platform_y,
	int platform_size
) {
	if (direction & LEFT)
		--ball_x;
	else
		++ball_x;

	if (ball_y >= field_height)
		direction = replace(direction, DOWN, UP);
	else if (ball_y <= 0)
		direction = replace(direction, UP, DOWN);

	if (direction & UP)
		--ball_y;
	else if (direction & DOWN)
		++ball_y;

	const FieldSide side = ball_side(field_width, ball_x);

	const bool is_left_platform = is_platform_position(
		platform_size,
		left_platform_y, ball_y
	);

	const bool is_right_platform = is_platform_position(
		platform_size,
		right_platform_y, ball_y
	);

	if (!check_hit(field_width, ball_x) ||
		!(side == FieldSide::LEFT && is_left_platform) && 
		!(side == FieldSide::RIGHT && is_right_platform))
		return;

	int platform_position = left_platform_y;
	if (side == FieldSide::LEFT) {
		direction = replace(direction, LEFT, RIGHT);
	} else {
		direction = replace(direction, RIGHT, LEFT);
		platform_position = right_platform_y;
	}

	if (ball_y > platform_position)
		direction = replace(direction, UP, DOWN);
	else if (ball_y <  platform_position)
		direction = replace(direction, DOWN, UP);
	else 
		direction = (Direction)(direction & ~UP & ~DOWN);
	
	ball_move(
		field_height, field_width,
		ball_y, ball_x, direction,
		left_platform_y, right_platform_y, platform_size
	);
}
