/* game.cpp
Author:		Andrew Crutcher
Email:		alcrutcher1s@semo.edu
College:	Southeast Missouri State University
Course:		MA138-01 Discrete Mathematics I
Prof:		Dr. Daly
Date:		9/15/2015
Description: The game program.
*/

#include <iostream>
#include <vector>
#include <iterator>
#include <algorithm>
#include <functional>

unsigned int nimSum(const std::vector<unsigned> & sticks){
    unsigned n = 0;
    for(unsigned x : sticks)
        n ^= x;
    return n;
}

void hPlayer(std::vector<unsigned> & sticks){
    unsigned stack;
    std::cout << "Please select a stack to remove sticks from (1 - " << sticks.size()
              << ") : ";
    std::cin >> stack;
    while(stack < 1 || stack > sticks.size()){
        std::cout << "Please select a valid stack (1 - " << sticks.size() << ") : ";
        std::cin >> stack;
    }
    unsigned num;
    std::cout << "Please select a number of sticks to remove (1 - " << sticks[stack]
              << ") : ";
    std::cin >> num;
    while(num < 1 || num > sticks[stack]){
        std::cout << "Please select a valid number of sticks to remove (1 - " << sticks[stack] << ") : ";
        std::cin >> num;
    }
    std::cout << "Removed " << num << " from stack " << stack << '\n';
    sticks[stack] -= num;
    return;
}

void cPlayer(std::vector<unsigned> & sticks){
    unsigned remove = nimSum(sticks);
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
    unsigned choice;
    std::cout << "Do you want to play a standard or custom game?\n1 - Standard (Default)\n"
              << "2 - Custom\n? ";
    std::cin >> choice;
    if(choice == 2){
        std::cout << "How many stacks? (Max 10) : ";
        std::cin >> choice;
        unsigned num;
        if(choice <= 10){
            for(unsigned i = 0; i < choice; ++i){
                std::cout << "Please enter a number for stack greater than 0 " << i + 1 << ": ";
                std::cin >> num;
                if(num == 0){
                    i--;
                    continue;
                } else {
                    game.push_back(num);
                }
            }
        }
    } else {
        game.push_back(3);
        game.push_back(5);
        game.push_back(7);
    }
    return std::move(game);
}

void displayStacks(const std::vector<unsigned> & sticks){
    for(std::vector<unsigned>::size_type i = 0; i < sticks.size(); ++i){
        std::cout << "Stack " << i + 1 << ": ";
        for(unsigned j = 0; j < sticks[i]; ++j)
            std::cout << '|';
        std::cout << '\n';
    }
    return;
}



bool endGame(const std::vector<unsigned> & sticks){
    return (std::accumulate(begin(sticks), end(sticks), 0) == 0);
}

int main(){
    std::vector<unsigned> sticks;
    std::string choice;
    bool loop = true;





    return 0;
}
