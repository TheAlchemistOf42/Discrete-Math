/* nim.h
Author:		Andrew Crutcher
Email:		alcrutcher1s@semo.edu
College:	Southeast Missouri State University
Course:		MA138-01 Discrete Mathematics I
Prof:		Dr. Daly
Date:		11/27/2015
Description: A header containing the game of Nim functions.
*/

#ifndef __NIM_H_
#define __NIM_H_

#include <iostream>
#include <vector>
#include <algorithm>
#include <random>
#include <ctime>

unsigned int nimSum(const std::vector<unsigned> & sticks);
void hPlayer(std::vector<unsigned> & sticks);
void cPlayer(std::vector<unsigned> & sticks);
void displayStacks(const std::vector<unsigned> & sticks);
std::vector<unsigned> initGame();
bool endGame(const std::vector<unsigned> & sticks);

#endif
