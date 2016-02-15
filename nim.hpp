/* nim.hpp
Author:		Andrew Crutcher
Email:		alcrutcher1s@semo.edu
College:	Southeast Missouri State University
Course:		MA138-01 Discrete Mathematics I
Prof:		Dr. Daly
Date:		02/15/2016
Description: A header containing the game of Nim functions.
*/

#ifndef __NIM_HPP_
#define __NIM_HPP_

#include <iostream>
#include <vector>
#include <algorithm>
#include <random>
#include <ctime>
#include <limits>

unsigned int nimSum(const std::vector<unsigned> & sticks);
void hPlayer(std::vector<unsigned> & sticks);
void cPlayer(std::vector<unsigned> & sticks);
void displayStacks(const std::vector<unsigned> & sticks);
std::vector<unsigned> initGame();
bool endGame(const std::vector<unsigned> & sticks);

template<class T>
void input(T & var){
    std::cin >> var;
    std::cin.clear();
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n');
}
#endif
