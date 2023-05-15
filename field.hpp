#pragma once

#include <iostream>
#include <sstream>

#include "utility.h"

using namespace std;

void clear() {
    system("cls");
}

void print_field(
    int height, int width,
    int ball_y, int ball_x,
    uint16_t platform_size,
    int left_player_y, int right_player_y
) {
    stringstream out;

    for (int x = 0; x < width; x++)
    {
        out << '*';
    }
    out << '\n';
    for (int y = 0; y < height; y++)
    {
        if (is_platform_position(platform_size, left_player_y, y))
            out << '#';
        else
            out << ' ';

        for (int x = 1; x < width-1; x++)
        {
            if (y == ball_y && x == ball_x) {
                out << 'o';
                continue;
            }

            if (x == width / 2 + 1) {
                out << '|';
                continue;
            }

            out << ' ';
        }

        if (is_platform_position(platform_size, right_player_y, y))
            out << '#';
        else
            out << ' ';
        out << '\n';
    }

    for (int x = 0; x < width; x++)
    {
        out << '*';
    }

    clear();

    std::cout << out.rdbuf();
}
