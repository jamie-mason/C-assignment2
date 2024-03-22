/*
*AUTHOR Jamie Mason
Last edit Sunday, March 17th 2024 1:23Am*
*/

#pragma once
#ifndef BALL_H
#define BALL_H

#include"Paddle.h"
#include<iostream>
#include <chrono>   // For timing functions
#include <thread>   // For thread-related functions



class Ball {
private:
    int x; // X-coordinate of the ball
    int y; // Y-coordinate of the ball
    int dirX; // X-direction of the ball (-1 for left, 1 for right)
    int dirY; // Y-direction of the ball (-1 for up, 1 for down)

public:
    Ball(int startX, int startY);

    // Getters for ball coordinates
    int getX() const;
    int getY() const;
    int getDirX() const;
    int getDirY() const;

    // Function to move the ball
    void move();

    // Function to handle ball collisions with walls and paddles
    bool handleCollision(Paddle& leftPaddle, Paddle& rightPaddle, int boardWidth, int boardHeight);

    // Function to reset ball position to center
    void reset(int,int);
};

#endif
