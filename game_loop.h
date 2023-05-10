#pragma once

#include <cstdint>
#include <chrono>
#include <thread>
#include <iostream>

using namespace std::chrono_literals;

#include "check_ball.hpp"
#include "bot_move.hpp"
#include "ball_move.hpp"
#include "field.hpp"
#include "handle_player_control.hpp"
#include "FieldSide.h"
#include "Direction.h"


constexpr uint64_t FPS = 30;

constexpr int field_height = 30;
constexpr int field_width = 91;

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

void reset_all(int& player_y, int& enemy_y, 
	int& ball_x, int& ball_y, Direction& ball_direction) {
	player_y = field_height / 2;
	enemy_y = field_height / 2;

	ball_x = field_width / 2 + 1;
	ball_y = field_height / 2;
	ball_direction = rand() % 2 == 0 ?
		Direction::LEFT : Direction::RIGHT;
}

void print_winner(int left_score, int win_score) {
	std::cout << "Победил игрок "
		<< (left_score >= win_score ? "слева" : "справа");
}

void game_loop() {
	int player_y, enemy_y;

	int ball_x, ball_y;
	Direction ball_direction;

	reset_all(player_y, enemy_y, ball_x, ball_y, ball_direction);

	uint64_t frames_count = 0;

	uint16_t left_score = 0;
	uint16_t right_score = 0;

	constexpr int win_score = 3;

	constexpr int platform_turns_per_second = 10;
	constexpr int ball_turns_per_second = 30;

	constexpr uint16_t platform_size = 3;

	for (;;) {
		if (is_time_for_turn(
			frames_count, 
			FPS,
			platform_turns_per_second
		)) {
			handle_player_control(player_y);
			bot_move(ball_x, ball_y, enemy_y, field_height);
		}

		if (is_time_for_turn(
			frames_count,
			FPS,
			ball_turns_per_second
		)) {
			ball_move(field_height, ball_y, ball_x, ball_direction);
			if (check_hit(field_width, ball_x)) {
				FieldSide side = ball_side(field_width, ball_x);

				reset_all(player_y, enemy_y, ball_x, ball_y, ball_direction);

				switch (side) {
				case FieldSide::LEFT:
					++right_score;
					break;
				case FieldSide::RIGHT:
					++left_score;
					break;
				}
			}
			if (left_score == win_score
				|| right_score == win_score)
				break;
		}

		print_field(
			field_height, field_width,
			ball_y, ball_x, platform_size,
			player_y, enemy_y
		);

		++frames_count;

		std::this_thread::sleep_for(1000/FPS*1ms);
	}

	clear();
	print_winner(left_score, win_score);
}
