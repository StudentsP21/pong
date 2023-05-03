#include <iostream>

using namespace::std;

void field(int x_ball,int x_bot,int x_player,int y_ball,int y_bot,int y_player,size_t width,size_t length) {
    enum Direction(left,left-up,left-down,right,right-up-right-down);
    for (size_t i=0;i<length;i++) {
        if (i=x_ball) {
            cout<<'O';
        }
        for (size_t j=0;j<width;j++) {
            if (i==y_ball) {
                cout<<'O';
            }
            else if (i==y_bot or i==y_player) {
            cout<<'|';
        }
        }
    }
    for (size_t i=0;i<length+1;i++) {
        cout<<
    }
}
