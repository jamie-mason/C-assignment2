/*
*AUTHOR Jamie Mason
Last edit Sunday, March 17th 2024 1:23Am*
*/
#pragma once
#include <string>
#include <iostream> // For input/output operations
#include <string>   // For string manipulation
#include <chrono>   // For timing functions
#include <thread>   // For thread-related functions
#include <time.h>
#include "Paddle.h"

#include "Ball.h"
#include "MenuOutput.h"
#include "HighScoreManager.h"


class MenuOutput;
class HighScoreManager;

class MainLoop {
private:
	int height, width;



public:
	MainLoop();
	void clearScreen();
	void play();
	void startCountdown();
	void createGrid(const Paddle& leftPaddle, const Paddle& rightPaddle, const Ball& ball, int boardWidth, int boardHeight);
	void printCentered(const std::string& text);
	~MainLoop();
};