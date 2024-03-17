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
    MenuOutput m("PONG");
    m.displayMenu();


    return 0;
}

