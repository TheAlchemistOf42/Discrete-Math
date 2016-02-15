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
#include "nim.hpp"

int main(int argc, char** argv){
    std::default_random_engine eng;
    eng.seed(time(nullptr));
    std::uniform_int_distribution<int> d(0);
    std::vector<unsigned> sticks;
    std::pair<std::string, std::function<void(std::vector<unsigned> &)>> hum;
    std::pair<std::string, std::function<void(std::vector<unsigned> &)>> com("Comp", cPlayer);
    unsigned score[2] {0,0};
    std::string choice;
    bool hfirst;
    std::cout << "Please enter your name : ";
    input(choice);
    hum.first = choice;
    hum.second = hPlayer;
    while(true){
        sticks = initGame();
        hfirst = (d(eng) % 2 == 0);
        while(true){
            // PLayer 1
            std::cout << "Player 1 ( " << (hfirst ? hum.first : com.first ) << " ) turn: \n";
            displayStacks(sticks);
            (hfirst ? hum.second : com.second)(sticks);
            if(endGame(sticks)){
                displayStacks(sticks);
                std::cout << "Player 1 ( " << (hfirst ? hum.first : com.first ) << " ) loses: \n";
                hfirst ? score[1]++ : score[0]++;
                break;
            }
            // PLayer 2
            std::cout << "Player 2 ( " << (hfirst ? com.first : hum.first) << " ) turn: \n";
            displayStacks(sticks);
            (hfirst ? com.second : hum.second)(sticks);
            if(endGame(sticks)){
                displayStacks(sticks);
                std::cout << "Player 2 ( " << (hfirst ? com.first : hum.first) << " ) loses: \n";
                hfirst ? score[0]++ : score[1]++;
                break;
            }
        }
        std::cout << hum.first << " : " << score[0] << '\t' << com.first << " : " << score[1] << '\n';
        std::cout << "Do you want to play again? (y/n) : ";
        input(choice);
        if(choice != "y")
            break;
    }
    return 0;
}
