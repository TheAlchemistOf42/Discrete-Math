/* nim.cpp
Author:		Andrew Crutcher
Email:		alcrutcher1s@semo.edu
College:	Southeast Missouri State University
Course:		MA138-01 Discrete Mathematics I
Prof:		Dr. Daly
Date:		11/27/2015
Description: The implementation file
*/

#include "nim.h"

unsigned int nimSum(const std::vector<unsigned> & sticks){
    unsigned n = 0;
    for(unsigned x : sticks)
        n ^= x;
    return n;
}

void hPlayer(std::vector<unsigned> & sticks){
    unsigned stack, num;
    std::cout << "Please select a stack to remove sticks from (1 - " << sticks.size()
              << ") : ";
    std::cin >> stack;
    std::cin.clear();
    std::cin.ignore(10000,'\n');
    while(stack < 1 || stack > sticks.size() || sticks[stack - 1] == 0){
        std::cout << "Please select a valid stack (1 - " << sticks.size() << ") : ";
        std::cin >> stack;
        std::cin.clear();
        std::cin.ignore(10000,'\n');
    }
    std::cout << "Please select a number of sticks to remove (1 - " << sticks[stack - 1]
              << ") from stack " << stack << ": ";
    std::cin >> num;
    std::cin.clear();
    std::cin.ignore(10000,'\n');
    while(num < 1 || num > sticks[stack - 1]){
        std::cout << "Please select a valid number of sticks to remove (1 - " << sticks[stack - 1] << ") : ";
        std::cin >> num;
        std::cin.clear();
        std::cin.ignore(10000,'\n');
    }
    std::cout << "Removed " << num << " from stack " << stack << '\n';
    sticks[stack - 1] -= num;
    return;
}

void cPlayer(std::vector<unsigned> & sticks){
    static std::default_random_engine eng;
    static std::uniform_int_distribution<int> r(0);
    eng.seed(time(nullptr));
    unsigned stack = 0, remove = nimSum(sticks), ones = 0, non = 0;
    for(unsigned a : sticks){
        if(a == 1)
            ones++;
        else if(a > 1)
            non++;
    }
    if(non == 1){
        if(ones % 2 == 0){
            // remove all but one from non one
            for(unsigned i = 0; i < sticks.size(); ++i){
                if(sticks[i] > 1){
                    remove = sticks[i] - 1;
                    sticks[i] -= remove;
                    stack = i + 1;
                    break;
                }
            }
        } else {
            // Remove all
            for(unsigned i = 0; i < sticks.size(); ++i){
                if(sticks[i] > 1){
                    remove = sticks[i];
                    sticks[i] -= remove;
                    stack = i + 1;
                    break;
                }
            }
        }
    } else {
        if(remove == 0){
            // No for sure winning move, remove 1 randomly
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
                unsigned xMax = 0;
                for(unsigned i = 0; i < sticks.size(); ++i){
                    if(sticks[i] != 0){
                        if((sticks[i] & remove) > xMax){
                            xMax = sticks[i] & remove;
                            stack = i + 1;
                        }
                    }
                }
                // remove = sticks[stack - 1] - (xMax ^ remove);
                remove = xMax - (xMax ^ remove);
                sticks[stack - 1] -= remove;
            }
        }
    }
    std::cout << "Removed " << remove << " from stack " << stack << '\n';
    return;
}

void displayStacks(const std::vector<unsigned> & sticks){
    for(unsigned i = 0; i < sticks.size(); ++i){
        std::cout << "Stack " << i + 1 << ": ";
        for(unsigned j = 0; j < sticks[i]; ++j)
            std::cout << '|';
        std::cout << '\n';
    }
    return;
}

std::vector<unsigned> initGame(){
    std::vector<unsigned> game;
    unsigned choice, num;
    std::cout << "Do you want to play a standard or custom game?\n1 - Standard (Default)\n"
              << "2 - Custom\n? ";
    std::cin >> choice;
    std::cin.clear();
    std::cin.ignore(10000,'\n');
    if(choice == 2){
        std::cout << "How many stacks? (3 - 9) : ";
        std::cin >> choice;
        std::cin.clear();
        std::cin.ignore(10000,'\n');
        while(choice > 9 || choice < 3){
            std::cout << "Please select a valid number of stacks (3 - 9) : ";
            std::cin >> choice;
            std::cin.clear();
            std::cin.ignore(10000,'\n');
        }
        for(unsigned i = 0; i < choice; ++i){
            std::cout << "Please enter a number (1 - 32) for stack " << i + 1 << ": ";
            std::cin >> num;
            std::cin.clear();
            std::cin.ignore(10000,'\n');
            while(num < 1 || num > 32 ){
                std::cout << "Please enter a valid number (1 - 32) for stack " << i + 1 << ": ";
                std::cin >> num;
                std::cin.clear();
                std::cin.ignore(10000,'\n');
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

bool endGame(const std::vector<unsigned> & sticks){
    return (std::accumulate(begin(sticks), end(sticks), 0) == 0);
}
