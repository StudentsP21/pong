#include <iostream>

using namespace std;

enum Direction {
    left,left_up,left_down,up,right,right_up,right_down,down
};

void field(int x_ball,int x_bot,int x_player,int y_ball,int y_bot,int y_player,size_t width,size_t length) {
    
    
}

void print_field(size_t width,size_t length){
    for (size_t i=0;i<length;i++) {
        cout<<"*";
    }
    for (size_t i=0;i<length;i++) {
        for (size_t j=0;j<width;j++)
            if (i=0 || i=length-1) {
                cout<<'*'
            }
        cout<<" ";
    }
    for (size_t i=0;i<length;i++) {
        cout<<"*";
    }
}