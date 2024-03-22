/*
*AUTHOR Jamie Mason
Last edit Sunday, March 17th 2024 1:23Am*
*/
#include "Paddle.h"
#include <conio.h> // For _kbhit() and _getch() functions on Windows

// Constructor
Paddle::Paddle(int startX, int startY, int paddleHeight, char up, char down){
    x = startX;
    y = startY;
    height = paddleHeight;
    upKey = up;
    downKey = down;
}

// Constructor for CPU-controlled paddle
Paddle::Paddle(int startX, int paddleHeight, int boardHeight, int ballInitialY){
    height = paddleHeight;
    x = startX;
    // Calculate initial y-coordinate of the CPU-controlled paddle based on the ball's initial position
    y = ballInitialY - height / 2;
    // Ensure paddle stays within the boundaries of the game board
    if (y < 1) {
        y = 1;
    }
    else if (y + height > boardHeight - 1) {
        y = boardHeight - height - 1;
    }
}

// Getters for paddle coordinates
int Paddle::getX() const { return x; }
int Paddle::getY() const { return y; }
int Paddle::getHeight() const { return height; }

// Function to move the paddle up
void Paddle::moveUp() {
    if (y > 0) // Check if paddle is already at the top edge
        y--;
}

// Function to move the paddle down
void Paddle::moveDown(int boardHeight) {
    if (y + height < boardHeight) // Check if paddle is already at the bottom edge
        y++;
}

// Function to control paddle movement based on user input
void Paddle::controlPaddle(int boardHeight) {
    if (_kbhit()) { // Check if a key is pressed
        char key = _getch(); // Get the pressed key
        if (key == upKey)
            moveUp();
        else if (key == downKey)
            moveDown(boardHeight);
    }
}
void Paddle::moveAuto(int xdir, int ballx,int ballY, int boardHeight ,int boardWidth) {
    // Move CPU-controlled paddle towards the ball's y-coordinate
    if ((xdir * (x - ballx)) >= 0 && abs(x - ballx) <= boardWidth / 5) {
        if (y + height / 2 < ballY)
            moveDown(boardHeight);
        else if (y + height / 2 > ballY)
            moveUp();
    }
}
