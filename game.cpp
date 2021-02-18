#include "game.h"


int game_state = BEFORE_START; 

int direction;

int score;

void start_game(){
    init_snake();
    init_food();
    direction = UP; 
    game_state = STARTED;
    score = 0;
}

void end_game(){
    game_state = ENDED;
}

void paint_status(){
    move(0 , 5);
    printw("Score %d" , score);
}

bool game_logic(){
    paint_border();
    paint_status();

    int key = getch(); 

    if(game_state == BEFORE_START){
        move(10 , 10);
        addstr("Press space to start");
        if(key == 32){
            // start the game
            start_game();
        }
    } else if(game_state == STARTED) {
        // either keep moving snake
        // or react to key inputs
        if(key == UP && direction != DOWN){
            direction = UP;
        } else if (key == DOWN && direction != UP){
            direction = DOWN;
        } if(key == LEFT && direction != RIGHT){
            direction = LEFT;
        } else if (key == RIGHT && direction != LEFT){
            direction = RIGHT;
        }
        pair < int , int > head = move_snake(direction);
        // foood position == head of snake
        // if its true , then eat the food and grow the snake
        if(try_eating_food(head)){
            score ++;
            grow_snake();
        }
        if(has_collision()){
            // end the game
            end_game();
        }
        paint_snake();
        paint_food();
    } else {
        // state is ended
        move(10, 10);
        addstr("GAME OVER! Press space to restart , q to quit");
        if(key == 32){
            start_game();
        } else if(key == 'q'){
            return true; // game_over
        }
    }
    return false;

    // if(key == UP){
    //     x--;
    // } else if (key == DOWN){
    //     x++;
    // } if(key == LEFT){
    //     y--;
    // } else if (key == RIGHT){
    //     y++;
    // }
    // move(x , y);
    // addch('#');
    
}