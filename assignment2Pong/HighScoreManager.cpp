/*
*AUTHOR Jamie Mason
Last edit Sunday, March 17th 2024 1:23Am*
*/
#include "HighScoreManager.h"


HighScoreManager::HighScoreManager(std::string filename) {
    this->filename = filename;
}



void HighScoreManager::loadHighScores() {
    std::ifstream file(filename);
    if (!file.is_open()) {
        std::cout<<"File: "<< filename <<" not found!"<<std::endl;
        exit(1);
    }
    std::string name;
    int score;

    highScores.clear();

    while (file >> name >> score) {
        highScores.push_back({ name, score });
    }

    file.close();

    // Sort high scores
    std::sort(highScores.begin(), highScores.end(), [](const auto& a, const auto& b) {
        return a.second > b.second;
        });
}

void HighScoreManager::saveHighScores() {
    std::string rank;
    int i = 1;
    std::ofstream file(filename);
    if (!file.is_open()) {
        std::cout << "File: " << filename << " not found!" << std::endl;
        exit(1);
    }
    for (const auto& entry : highScores) {
        rank = std::to_string(i) + ". ";
        file << entry.first << " " << entry.second << std::endl;
        i++;
    }
    file.close();
}

void HighScoreManager::addHighScore(const std::string& playerName, int score) {
    highScores.push_back({ playerName, score });

    // Sort high scores
    std::sort(highScores.begin(), highScores.end(), [](const auto& a, const auto& b) {
        return a.second > b.second;
        });

    // Keep only top 5 high scores
    highScores.resize(std::min(static_cast<int>(highScores.size()), maxHighScores));

    

    // Save updated high scores to file
    saveHighScores();
}

void HighScoreManager::resizeList() {
    highScores.resize(std::min(static_cast<int>(highScores.size()), maxHighScores));
    saveHighScores();
}

const std::vector<std::pair<std::string, int>>& HighScoreManager::getHighScores() const {
    return highScores;
}
void HighScoreManager::printHighScores(){
    loadHighScores();
    MenuOutput m;

    std::string spaces(m.getNumSpacesBeforeEachLine(), ' ');
    if (highScores.empty()) {
        std::cout << spaces << "No high scores available." << std::endl;
    }
    else {
        std::cout << spaces <<"Top " << highScores.size() << " High Scores:" << std::endl;
        for (size_t i = 0; i < highScores.size(); ++i) {
            std::cout << spaces <<"\t"<< i + 1 << ". " << highScores[i].first << ": " << highScores[i].second << std::endl;
        }
    }
}
void HighScoreManager::deleteHighScore(int index) {
    if (index >= 0 && index < highScores.size()) {
        highScores.erase(highScores.begin() + index);
        saveHighScores(); // Save updated high scores to file
    }
    else {
        std::cout << "Invalid index. Please provide a valid index." << std::endl;
    }
}
void HighScoreManager::resetHighScores() {
    highScores.clear();
    saveHighScores(); // Save updated high scores to file


    // Load default high scores or save empty high scores to file
}

HighScoreManager::~HighScoreManager() {
}