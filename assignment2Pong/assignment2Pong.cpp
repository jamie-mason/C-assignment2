/*
*AUTHOR Jamie Mason
Last edit Sunday, March 17th 2024 *
*/

#include <iostream>
#include <string>
#include "MenuOutput.h"
#include <chrono>
#include <thread>

#ifdef _WIN32
#include <windows.h>
#else
// Assume Unix-like system
#include <unistd.h>
#endif

int main()
{   
    MenuOutput m;
    m.displayMenu();


    return 0;  //return the function at 0;
}

