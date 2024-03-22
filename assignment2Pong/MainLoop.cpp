/*
*AUTHOR Jamie Mason
Last edit Sunday, March 22th 2024 1:22 AM*
*/
#include "MainLoop.h"
#include <iomanip>

#include <windows.h>

MainLoop::MainLoop() {
    height = 15;
    width = 20;
}
void MainLoop::printCentered(const std::string& text) {
    CONSOLE_SCREEN_BUFFER_INFO csbi;
    GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &csbi);
    int consoleWidth = csbi.srWindow.Right - csbi.srWindow.Left + 1;

    int padding = (consoleWidth - text.length()) / 2;
    std::cout << std::setw(padding + text.length()) << text << std::endl;
}
void MainLoop::clearScreen() {
#ifdef _WIN32
    std::system("cls"); // Clear the console screen on Windows
#else
    // Assume Unix-like system
    std::system("clear"); // Clear the console screen on Unix-like systems
#endif
}

void MainLoop::startCountdown() {
    for (unsigned int i = 3; i > 0; --i) {
        printCentered(std::to_string(i));
        std::this_thread::sleep_for(std::chrono::seconds(1));

    }

    printCentered("Go!");
}

// Function to create the grid
void MainLoop::createGrid(const Paddle& leftPaddle, const Paddle& rightPaddle, const Ball& ball, int boardWidth, int boardHeight) {
    clearScreen();

    // Get console width
    CONSOLE_SCREEN_BUFFER_INFO csbi;
    GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &csbi);
    int consoleWidth = csbi.srWindow.Right - csbi.srWindow.Left + 1;

    // Calculate number of spaces to center the game board horizontally
    int padding = (consoleWidth - boardWidth) / 2;

    // Draw top border
    std::cout << std::setw(padding) << "+" << std::setfill('-') << std::setw(boardWidth) << "+" << std::setfill(' ') << std::endl;

    // Draw middle section with paddings
    for (int y = 0; y < boardHeight; y++) {
        std::cout << std::setw(padding) << "|"; // Left border
        for (int x = 0; x < boardWidth-1; x++) {
            // Draw left paddle
            if (x == leftPaddle.getX() && y >= leftPaddle.getY() && y < leftPaddle.getY() + leftPaddle.getHeight())
                std::cout << "|";
            // Draw right paddle
            else if (x == rightPaddle.getX() && y >= rightPaddle.getY() && y < rightPaddle.getY() + rightPaddle.getHeight())
                std::cout << "|";
            // Draw ball
            else if (x == ball.getX() && y == ball.getY())
                std::cout << "*"; // Ball represented by '*'
            else
                std::cout << " "; // Empty space
        }
        std::cout << "|" << std::endl;  //Right border end line.
    }

    // Draw bottom border
    std::cout << std::setw(padding) << "+" << std::setfill('-') << std::setw(boardWidth) << "+" << std::setfill(' ') << std::endl;
}


void MainLoop::play() {
    MenuOutput m;
    Paddle leftPaddle(0, height / 2, 3, 'w', 's');//0, 3, height, height / 2); // Player-controlled paddle
    Paddle rightPaddle(width - 2, 3, height, height / 2);
    HighScoreManager hs = m.getHighScoreManager();
    std::string name;
    std::string input;
    Ball ball(width / 2, height / 2); // Initial ball position and direction
    bool gameRunning = true;
    int playerScore = 0;

    startCountdown();
    std::this_thread::sleep_for(std::chrono::milliseconds(200));
    clearScreen();

    while (gameRunning) {
        // Draw the game board
        std::this_thread::sleep_for(std::chrono::milliseconds(200));

        createGrid(leftPaddle, rightPaddle, ball, width, height);

        // Move paddles based on user input
        leftPaddle.controlPaddle(height);

        //cpu controls right paddle
        rightPaddle.moveAuto(ball.getDirX(), ball.getX(), ball.getY(), height, width);




        // Move the ball
        ball.move();


        // Handle ball collisions
        bool scored = ball.handleCollision(leftPaddle, rightPaddle, width - 1, height);

        // Update score if the player scored
        if (scored) {
            playerScore++;
            ball.reset(width / 2, height / 2); // Reset the ball position
        }

        // Display the score
        std::cout << "Score: " << playerScore << std::endl;

        // Check if the ball hits the left edge
        if (ball.getX() == -1) {
            gameRunning = false; // Game over
        }

        // Sleep to control game speed
        Sleep(100);
    }

    // Print game over and final score
    std::cout << "Game Over!" << std::endl;
    std::cout << "Final Score: " << playerScore << std::endl;
    std::cout << "Enter a name: ";
    std::cin >> name;
    hs.loadHighScores();
    hs.addHighScore(name, playerScore);
    hs.printHighScores();

    std::cout << "Enter anything to return to menu: ";
    std::cin >> input;
    std::cout << "Returning to menu." << std::endl;
    std::this_thread::sleep_for(std::chrono::milliseconds(500));
    clearScreen();
    m.displayMenu();


}

MainLoop::~MainLoop() {
}