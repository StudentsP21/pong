#pragma once

enum field_side {
    RIGHT,
    LEFT
};

bool check_hit(int field_width, int ball_x) {

    if (ball_x == 1 || ball_x == field_width)
        return true;
    return false;
}

field_side ball_side(int field_width, int ball_x) {
    if (ball_x > field_width / 2) {
        return RIGHT;
    }
    return LEFT;
}