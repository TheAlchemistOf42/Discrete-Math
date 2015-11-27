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

void cPlayer(std::vector<unsigned> & sticks){
    static std::default_random_engine eng;
    static std::uniform_int_distribution<int> r(0);
    eng.seed(time(nullptr));
    unsigned stack = 0, remove = nimSum(sticks);
    if(remove == 0){
        // No for sure winning move, remove 1 randomly
        stack = (r(eng) % sticks.size()) + 1;
        while(sticks[stack - 1] == 0)
            stack = (r(eng) % sticks.size()) + 1;
        remove = 1;
        sticks[stack - 1] -= remove;
    } else if(*std::max_element(sticks.begin(), sticks.end()) == remove){
        // Need to check if it is the only stack, remove all but one
    } else {
        for(unsigned i = 0; i < sticks.size(); ++i){
            if((sticks[i] & remove) == remove){
                sticks[i] -= remove;
                stack = i + 1;
                break;
            }
        }
        if(stack == 0){
            unsigned xMax = 0;
            for(unsigned i = 0; i < sticks.size(); ++i){
                if(sticks[i] != 0){
                    for(unsigned j = 0; j <= 5; ++j){
                        if((sticks[i] & 1<<j) != 0  && (remove & 1<<j) != 0 && xMax < 1<<j){
                            xMax = 1<<j;
                            stack = i + 1;
                        }
                    }
                }
            }
            remove = xMax - (remove ^ xMax);
            sticks[stack - 1] -= remove;
        }
    }
    std::cout << "Removed " << remove << " from stack " << stack << '\n';
    return;
}

int main(){
    std::default_random_engine eng;
    eng.seed(time(nullptr));
    std::uniform_int_distribution<int> d(0);
    std::vector<unsigned> sticks;
    std::pair<std::string, std::function<void(std::vector<unsigned> &)>> hum;
    std::pair<std::string, std::function<void(std::vector<unsigned> &)>> com;
    std::string choice;
    bool play = true, hfirst;
    std::cout << "Please enter your name : ";
    std::cin >> choice;
    std::cin.clear();
    std::cin.ignore(10000,'\n');
    // Initialize Players
    hum.first = choice;
    com.first = "Comp";
    hum.second = hPlayer;
    com.second = cPlayer;
    while(play){
        sticks = initGame();
        hfirst = true;
        // hfirst = (d(eng) % 2 == 0);
        while(true){
            // PLayer 1
            std::cout << "Player 1 ( " << (hfirst ? hum.first : com.first ) << " ) turn: \n";
            displayStacks(sticks);
            hPlayer(sticks);
            // (hfirst ? hum.second : com.second)(sticks);
            if(endGame(sticks)){
                std::cout << "Player 1 ( " << (hfirst ? hum.first : com.first ) << " ) loses: \n";
                break;
            }
            // PLayer 2
            std::cout << "Player 2 ( " << (hfirst ? com.first : hum.first) << " ) turn: \n";
            displayStacks(sticks);
            cPlayer(sticks);
            // (hfirst ? com.second : hum.second)(sticks);
            if(endGame(sticks)){
                std::cout << "Player 2 ( " << (hfirst ? com.first : hum.first) << " ) loses: \n";
                break;
            }
        }
        std::cout << "Do you want to play again? (y/n) : ";
        std::cin >> choice;
        if(choice != "y")
            break;
    }
    return 0;
}
