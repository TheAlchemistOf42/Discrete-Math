/* nim.cpp
Author:		Andrew Crutcher
Email:		alcrutcher1s@semo.edu
College:	Southeast Missouri State University
Course:		MA138-01 Discrete Mathematics I
Prof:		Dr. Daly
Date:		11/10/2015
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
    while(stack < 1 || stack > sticks.size() || sticks[stack - 1] == 0){
        std::cout << "Please select a valid stack (1 - " << sticks.size() << ") : ";
        std::cin >> stack;
    }
    std::cout << "Please select a number of sticks to remove (1 - " << sticks[stack - 1]
              << ") : ";
    std::cin >> num;
    while(num < 1 || num > sticks[stack - 1]){
        std::cout << "Please select a valid number of sticks to remove (1 - " << sticks[stack - 1] << ") : ";
        std::cin >> num;
    }
    std::cout << "Removed " << num << " from stack " << stack << '\n';
    sticks[stack - 1] -= num;
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

bool endGame(const std::vector<unsigned> & sticks){
    return (std::accumulate(begin(sticks), end(sticks), 0) == 0);
}
