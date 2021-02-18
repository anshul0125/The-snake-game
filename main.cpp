#include <iostream>
#include <curses.h>
#include "ui.h"
#include "game.h"
#include <chrono>
#include "settings_constants.h"

using namespace std;

 // microseconds , time taken by one frame to execute -  4 sec
void event_loop(){
    // next probem - mainatain the speed
    
    int dt;
    while(true){
        auto last_time = chrono::system_clock::now();   
        erase();
        
        bool game_over;
        game_over = game_logic();
        
        if(game_over)
        break;

        refresh();

        do {
            auto current_time = chrono::system_clock::now();
            dt = chrono::duration_cast<std::chrono::microseconds>(current_time - last_time).count();
        } while(dt < TIME_DELAY_BETWEEN_FRAMES);

        // 10 frames - 1 sec
        // 1 frame - 0.1 sec
        // 100 ms
        // 1sec - 10^6 microseconds
        // 0.1 -> 10 ^ 5 microseconds
        
        

        
        // sleep(100); // sleep of 100 ms (0.1 sec), 1 sec = 1000 ms
        // 1 sec - 10 frames / sec
        // 1 sec -  3 frames / sec
        // bad for a game to have variable fps
    }
}

int main(){
    init_ui();
    event_loop();
    tear_down_ui();
    cout << "THANKS FOR PLAYING SNAKE GAME! BUT DON\'T BE A SNAKE IN REAL WORLD" << endl;
    return 0;
}




 // /*
    // #############
    // #           #
    // #           #
    // #           #
    // #           #
    // #############
    // */
    // int width = 20;
    // int height = 20;
    // for(int i = 0; i < width; i ++){
    //     cout << "#";
    // }
    // cout << endl;
    // for(int i = 1 ; i < height - 1; i++){
    //     cout << "#";
    //     for(int j = 1 ; j < width - 1; j ++){
    //         cout << " ";
    //     }
    //     cout << "#";
    //     cout << endl;
    // }
    // //cout << endl;
    // for(int i = 0; i < width; i ++){
    //     cout << "#";
    // }
    // cout << endl;