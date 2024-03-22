/*
*AUTHOR Jamie Mason
Last edit Sunday, March 17th 2024 1:23Am*
*/

#pragma once

#ifndef HIGH_SCORE_MANAGER_H
#define HIGH_SCORE_MANAGER_H

#include <string>
#include <vector>
#include <utility>
#include <iostream>
#include <fstream>
#include <algorithm>
#include "MainLoop.h"
#include "MenuOutput.h"


class MainLoop;
class MenuOutput;

class HighScoreManager {
private:
    std::string filename;
    std::vector<std::pair<std::string, int>> highScores;
    const int maxHighScores = 5;

    
    void saveHighScores();

public:
    HighScoreManager(std::string filename);
    void addHighScore(const std::string& playerName, int score);
    const std::vector<std::pair<std::string, int>>& getHighScores() const;
    void loadHighScores();
    void resizeList();
    void printHighScores();
    void deleteHighScore(int index);
    void resetHighScores();
    ~HighScoreManager();

};

#endif
