#pragma once

void bot_move(
    const int ball_x, const int ball_y, 
    int& bot_y,
    const int field_height
) {
    if (ball_x < 30) {
        return;
    }

    if (ball_y > bot_y){
        bot_y--;
        return;
    }

    if (ball_y < bot_y) {
        bot_y++;
    }
}
