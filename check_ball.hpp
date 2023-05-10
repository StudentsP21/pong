#pragma once

#include "FieldSide.h"

bool check_hit(int field_width, int ball_x) {
    if (ball_x == 1 || ball_x == field_width)
        return true;
    return false;
}

FieldSide ball_side(int field_width, int ball_x) {
    if (ball_x > field_width / 2) {
        return FieldSide::RIGHT;
    }
    return FieldSide::LEFT;
}