/* game.cpp
Author:		Andrew Crutcher
Email:		alcrutcher1s@semo.edu
College:	Southeast Missouri State University
Course:		MA138-01 Discrete Mathematics I
Prof:		Dr. Daly
Date:		11/25/2015
Description: The game program.
*/

#include <iostream>
#include <vector>
#include <functional>
#include <random>
#include <ctime>
#include "nim.h"

void cPlayer(std::vector<unsigned> & sticks, std::uniform_int_distribution<unsigned> r, std::default_random_engine eng){

    unsigned stack = 0, remove = nimSum(sticks);
    if(remove == 0){
        stack = (r(eng) % sticks.size()) + 1;
        while(sticks[stack - 1] == 0)
            stack = (r(eng) % sticks.size()) + 1;
        remove = 1;
        sticks[stack - 1] -= remove;
    } else {
        for(unsigned i = 0; i < sticks.size(); ++i){
            if((sticks[i] & remove) == remove){
                sticks[i] -= remove;
                stack = i + 1;
                break;
            }
        }
        if(stack == 0){
            for(unsigned i = 0; i < sticks.size(); ++i){
                if((sticks[i] & remove) == remove){
                    sticks[i] -= remove;
                    stack = i + 1;
                    break;
                }
            }
            // It didn't remove anything
            unsigned max = *std::max_element(begin(sticks), end(sticks));
            if(remove > max){
                remove = max - (remove ^ max);
            }
        }
    }
    std::cout << "Removed " << remove << " from stack " << stack << '\n';
    return;
}

int main(){
    std::default_random_engine eng;
    eng.seed(time(nullptr));
    std::uniform_int_distribution<unsigned> d(1);
    std::vector<unsigned> sticks;
    std::string choice;
    bool play = true;
    /*
    sticks = initGame();
    displayStacks(sticks);
    hPlayer(sticks);
    displayStacks(sticks);
    cPlayer(sticks);
    displayStacks(sticks);
    hPlayer(sticks);
    displayStacks(sticks);
    cPlayer(sticks);
    displayStacks(sticks);
    cPlayer(sticks);
    std::cout << endGame(sticks);
    */
    while(play){
        sticks = initGame();
        // Select Player 1 randomly
        displayStacks(sticks);
        while(true){
            // PLayer 1
            std::cout << "Player 1 turn: \n";
            hPlayer(sticks);
            displayStacks(sticks);
            if(endGame(sticks)){
                std::cout << "Player 1 loses: \n";
                break;
            }
            // PLayer 2
            std::cout << "Player 2 turn: \n";
            cPlayer(sticks, d, eng);
            displayStacks(sticks);
            if(endGame(sticks)){
                std::cout << "Player 2 loses: \n";
                break;
            }
        }
    }
    return 0;
}
