#pragma once

#include "FieldSide.h"
#include "utility.h"

bool check_hit(int field_width, int ball_x) {
    if (ball_x == 1 || ball_x == field_width)
        return true;
    return false;
}
