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
#include <iterator>
#include <algorithm>
#include <functional>
#include "nim.h"

void cPlayer(std::vector<unsigned> & sticks){
    unsigned stack, remove = nimSum(sticks);
    if(remove == 0){

    } else {
        for(unsigned i = 0; i < sticks.size(); ++i){
            if((sticks[i] & remove) == remove){
                sticks[i] -= remove;
                break;
            }
        }
    }
    return;
}

std::vector<unsigned> startGame(){
    std::vector<unsigned> game;
    unsigned choice, num;
    std::cout << "Do you want to play a standard or custom game?\n1 - Standard (Default)\n"
              << "2 - Custom\n? ";
    std::cin >> choice;
    if(choice == 2){
        std::cout << "How many stacks? (Max 10) : ";
        std::cin >> choice;
        while(choice > 10 || choice < 1){
            std::cout << "Please select a valid number of stacks (1 - 10) : ";
            std::cin >> choice;
        }
        for(unsigned i = 0; i < choice; ++i){
            std::cout << "Please enter a number (1 - 32) for stack " << i + 1 << ": ";
            std::cin >> num;
            while(num < 1 || num > 32 ){
                std::cout << "Please enter a valid number (1 - 32) for stack " << i + 1 << ": ";
                std::cin >> num;
            }
            game.push_back(num);
        }
    } else {
        game.push_back(1);
        game.push_back(3);
        game.push_back(5);
        game.push_back(7);
    }
    return std::move(game);
}

int main(){
    std::vector<unsigned> sticks;
    std::string choice;
    // bool loop = true;
    sticks = startGame();
    displayStacks(sticks);
    hPlayer(sticks);
    displayStacks(sticks);
    hPlayer(sticks);
    displayStacks(sticks);
    hPlayer(sticks);
    displayStacks(sticks);
    hPlayer(sticks);
    displayStacks(sticks);
    hPlayer(sticks);
    displayStacks(sticks);
    std::cout << endGame(sticks);




    return 0;
}
