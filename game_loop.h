#pragma once

//счЄтчик повторов цикла игры

//сделать счЄтчик времени проведЄнный в игре (без нажатой паузы)

//сделать паузу игры и счЄтчик времени 

//при попадании м€ча 1 игроку добавл€ть 1 балл 2 игроку и наоборот

//при попадании возвращ€ть м€чь на центр пол€ 

//при набирании 3 очков у 1 или 2 игрока останавливать игру

#include <cstdint>
#include <chrono>
#include <thread>

using namespace std::chrono_literals;

#include "check_ball.hpp"
#include "FieldSide.h"
#include "Direction.h"

constexpr uint64_t FPS = 5;

constexpr int field_height = 30;
constexpr int field_width = 61;

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

void game_loop() {
	int player_y, enemy_y;

	int ball_x, ball_y;
	Direction ball_direction;

	reset_all(player_y, enemy_y, ball_x, ball_y, ball_direction);

	uint64_t frames_count = 0;

	constexpr int win_score = 3;

	constexpr int platform_turns_per_second = 2;
	constexpr int ball_turns_per_second = 5;

	for (;;) {
		if (is_time_for_turn(
			frames_count, 
			FPS,
			platform_turns_per_second
		)) {
			handle_player_control(player_y);
			bot_move(enemy_y, ball_y);
		}

		if (is_time_for_turn(
			frames_count,
			FPS,
			ball_turns_per_second
		)) {
			ball_move(ball_y, ball_x, ball_direction);
			if (check_hit(field_width, ball_x)) {
				FieldSide side = ball_side(field_width, ball_x);

				reset_all(player_y, enemy_y, ball_x, ball_y, ball_direction);

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

		print_field(
			player_y, enemy_y, 
			ball_x, ball_y, ball_direction,
			field_height, field_width
		);

		++frames_count;

		std::this_thread::sleep_for(1000/FPS*1ms);
	}

	if (left_score == win_score) {
		std::cout << "ѕобедил игрок слева";
	}
	else {
		std::cout << "ѕобедил игрок справа"
	}
}
