#include <iostream>

using namespace std;

void print_field(size_t width, size_t length) {

    for (size_t i = 0; i < width; i++)
    {
        if (i == 0 || i == width - 1)
        {
            for (size_t j = 0; j < length; j++)
            {
                cout << '*';
            }
        }
        else
        {
            for (size_t j = 0; j < length; j++)
            {
                if (j == 0 || j == length - 1)
                    cout << '*';
                else
                    cout << " ";
            }
            cout << '\n';
        }
    }
}

void print_ball(size_t width, size_t length, size_t ball_y, size_t ball_x) {
    for (size_t y = 0; y < width; y++) {
        for (size_t x = 0; x < length; x++) {
            if (y == ball_y && x == ball_x) {
                cout << 'o';
            }
        }
    }
}