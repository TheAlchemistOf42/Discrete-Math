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

void hPlayer(){

    return;
}

void cPlayer(){

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
        if(choice < 10){
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

int nimSum(const std::vector<unsigned> & sticks){

    return 0;
}

bool endGame(const std::vector<unsigned> & sticks){
    return (std::accumulate(begin(sticks), end(sticks), 0) == 0);
}

int main(){
    std::vector<unsigned> sticks;
    std::string choice;
    bool loop = true;

    while(loop){



        std::cout << "Would you like to play a game? (Y/N)";
    }



    return 0;
}
