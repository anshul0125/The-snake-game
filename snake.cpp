#include "snake.h"

int x, y;

vector < pair<int , int > > body; 

void init_snake(){
    body.clear();
    body.push_back({10,10});        
    body.push_back({10,11});
    body.push_back({10,12});
}

void paint_snake(){
    for(int i =0 ; i < body.size(); i ++){
        pair < int , int > location = body[i];
        move(location.first, location.second);

        addch('#');
    }
}

pair < int , int > snake_tail;
pair < int , int > move_snake(int direction){

    snake_tail = body[body.size() - 1];
    body.pop_back();
    pair < int , int > old_head = body[0]; 
    pair < int , int > new_head = old_head;
    if(direction == UP){
       new_head.first --;
    } else if (direction == DOWN){
       new_head.first ++;
    } if(direction == LEFT){
       new_head.second --;
    } else if (direction == RIGHT){
       new_head.second++;
    }
    body.insert(body.begin(), new_head);
    return body[0];

}


void grow_snake(){
    body.push_back(snake_tail);
}

bool has_collision(){

    pair < int , int > head = body[0];
    int x = head.first;
    int y = head.second;
    if(x == 0 || x == LINES - 1 || y == 0 || y == COLS - 1){
        return true;
    }
    

    for(int i = 1;i < body.size();i++){
        if(head == body[i]){
            return true;
        }
    }

    return false;
}