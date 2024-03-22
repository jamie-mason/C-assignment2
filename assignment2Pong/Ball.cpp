/*
*AUTHOR Jamie Mason
Last edit Sunday, March 17th 2024 1:23Am*
*/
#include "Ball.h"

Ball::Ball(int startX, int startY)
    : x(startX), y(startY)  {
    dirX = 1;

    srand(time(NULL));
    int upOrDown = rand() % 1;
    if (upOrDown == 0) {
        dirY = -1;
    }
    else {
        dirY = 1;
    }
}

int Ball::getX() const {
    return x;
}

int Ball::getY() const {
    return y;
}

int Ball::getDirX() const {
    return dirX;
}

int Ball::getDirY() const {
    return dirY;
}
void Ball::move() {

    x += dirX;
    y += dirY;
}

bool Ball::handleCollision(Paddle& leftPaddle, Paddle& rightPaddle, int boardWidth, int boardHeight) {
    // Check for collision with top or bottom wall
    if (y == 0 || y == boardHeight - 1)
        dirY = -dirY;

    // Check for collision with left or right wall
    if (x == 1 || x == boardWidth - 2) {
        
        // Check for collision with left paddle
        if (x == 1 && y >= leftPaddle.getY() && y < leftPaddle.getY() + leftPaddle.getHeight())
            dirX = -dirX;
        // Check for collision with right paddle
        else if (x == boardWidth - 2 && y >= rightPaddle.getY() && y < rightPaddle.getY() + rightPaddle.getHeight())
            dirX = -dirX;

    }


    if (x == boardWidth-1) {
        reset(boardWidth / 2, boardHeight / 2);
        return true;
    }

    return false;

}

void Ball::reset(int x, int y) {
    srand(time(NULL));
    int upOrDown = rand() % 1;
    this->x = x; // Set X-coordinate to center of board
    this->y = y; // Set Y-coordinate to center of board
    dirX = 1;
    if (upOrDown == 0) {
        dirY = -1;
    }
    else {
        dirY = 1;
    }

}
