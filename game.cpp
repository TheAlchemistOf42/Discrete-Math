/* game.cpp
Author:		Andrew Crutcher
Email:		alcrutcher1s@semo.edu
College:	Southeast Missouri State University
Course:		MA138-01 Discrete Mathematics I
Prof:		Dr. Daly
Date:		11/10/2015
Description: The game program.
*/

#include <iostream>
#include <vector>
#include <functional>
#include "nim.h"

void cPlayer(std::vector<unsigned> & sticks){
    unsigned stack = 0, remove = nimSum(sticks);
    if(remove == 0){
        // random remove
        // stack must contain at least one
        // must remove between 1 and stack[i] inclusive
        // sticks
    } else {
        for(unsigned i = 0; i < sticks.size(); ++i){
            if((sticks[i] & remove) == remove){
                sticks[i] -= remove;
                stack = i + 1;
                break;
            }
        }
        if(stack == 0){
            // It didn't remove anything
        }
    }
    std::cout << "Removed " << remove << " from stack " << stack << '\n';
    return;
}

int main(){
    std::vector<unsigned> sticks;
    std::string choice;
    // bool loop = true;
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
/*

    while(loop){
        sticks = initGame();
        // Select Player 1 randomly
        // PLayer 1
        std::cout << "Player 1 turn: \n";
        move
        if(endGame){
            std::cout << "Player 1 loses: \n"
            break;
        }
        // PLayer 1
        std::cout << "Player 2 turn: \n";
        move
        if(endGame){
            std::cout << "Player 2 loses: \n"
            break;
        }
    }

*/
    return 0;
}
