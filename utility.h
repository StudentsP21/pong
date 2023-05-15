#pragma once

#include <cmath>
#include "Direction.h"

bool is_platform_position(uint16_t platform_size,
    int platform_y, int y
) {
    return abs(platform_y - y) <= platform_size / 2;
}

FieldSide ball_side(int field_width, int ball_x) {
    if (ball_x > field_width / 2) {
        return FieldSide::RIGHT;
    }
    return FieldSide::LEFT;
}

Direction replace(
    Direction direction,
    Direction from_side,
    Direction to_side
) {
    return (Direction)(direction & ~from_side | to_side);
}
