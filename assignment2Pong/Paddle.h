#pragma once
#ifndef PADDLE_H
#define PADDLE_H

#include<iostream>
#include <chrono>   // For timing functions
/*
*AUTHOR Jamie Mason
Last edit Sunday, March 17th 2024 1:23Am
*/
#include <thread>   // For thread-related functions

class Paddle {
private:
    int x; // X-coordinate of the paddle
    int y; // Y-coordinate of the top position of the paddle
    int height; // Height of the paddle
    char upKey; // Key for moving the paddle up
    char downKey; // Key for moving the paddle down

public:
    Paddle(int startX, int startY, int paddleHeight, char up, char down);

    // Constructor for CPU-controlled paddle
    Paddle(int startX, int paddleHeight, int boardHeight, int ballInitialY);
    // Getters for paddle coordinates
    int getX() const;
    int getY() const;
    int getHeight() const;

    // Function to move the paddle up
    void moveUp();

    // Function to move the paddle down
    void moveDown(int boardHeight);

    // Function to control paddle movement based on user input
    void controlPaddle(int boardHeight);
    void moveAuto(int xdir, int ballx, int ballY, int boardHeight, int boardWidth);

};

#endif // PADDLE_H
