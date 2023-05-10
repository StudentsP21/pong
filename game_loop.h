#pragma once

#include <cstdint>
#include "FieldSide.h"

bool is_time_for_turn(
	uint64_t frames_count,
	uint64_t fps,
	uint64_t turns_per_second
) {
	if (frames_count % (fps / turns_per_second) == 0) {
		return true;
	}
	return false;
}

void game_loop() {
	uint64_t frames_count = 0;
	const uint64_t FPS = 5;

	const int platform_delay_frames_count = 2;

	while (true) {
		if (is_time_for_turn(
			frames_count, 
			FPS,
			platform_delay_frames_count
		)) {
			if (check_player_moving())
				move(player_y, handle_moving_direction());
			bot_move();
		}

		if (is_time_for_turn(
			frames_count,
			FPS,
			ball_delay_frames_count
		)) {
			ball_move();
			if (check_hit(field_width, ball_x)) {
				FieldSide side = ball_side(field_width, ball_x);
				switch (side) {
				case LEFT:
					++right_score;
					break;
				case RIGHT:
					++left_score;
					break;
				}
			}
			if (left_score == win_score
				|| right_score == win_score)
				break;
		}

		++frames_count;
	}

	if (left_score == win_score) {
		std::cout << "Победил игрок слева";
	}
	else {
		std::cout << "Победил игрок справа"
	}
}
