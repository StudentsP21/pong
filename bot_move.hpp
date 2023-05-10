void ai_move(int& ball_x, int& ball_y, size_t racket_y, size_t speed_ball, const mas_racket)
{
  if(ball_x <= 30){
    if(ball_y>(field_height/2)){
      racket_movement(x,y,racket);//движение ракетки (under)
    }
    if(ball_y<(field_height/2)){
      racket_movement(x,y,racket);//движение ракетки (up)      }
    }
  }
}