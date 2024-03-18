/*
*AUTHOR Jamie Mason
Last edit Sunday, March 17th 2024 7:57pm*
*/

#pragma once    // Include guard to prevent multiple inclusion of this header file

// Standard library includes
#include <iostream> // For input/output operations
#include <string>   // For string manipulation
#include <math.h>   // For mathematical functions
#include <cstdlib>  // For standard library functions
#include <chrono>   // For timing functions
#include <thread>   // For thread-related functions

// Class definition for MenuOutput
class MenuOutput {
private:
	const std::string* title = new const std::string("PONG");       // Title of the menu
	std::string* options;                   // Array of menu options
	const unsigned int* size = new unsigned int(3);            // Number of options in the menu (const to prevent modification)
	unsigned int* preTextAst,* postTextAst,* numBeforeSpacesEachLine;
	int* numSpacesBeforeOptions;               // unsigned int holding the number of asterisks that will be printed before and after the title.
	void setOptions();
public:
		
	// Constructors
	MenuOutput();                     // Default constructor
	
	std::string* getOptions() const;  // Get the options array
	const std::string getTitle() const; 
	const unsigned int getSize() const;         // Get the size of the menu

	// Utility functions
	void clearScreen();          // Clear the console screen
	size_t findLongestString(std::string*);    // Find the length of the longest string in an array
	unsigned int setZeroIfNegative(int);        // Set a value to zero if it's negative

	//printing functions
	void printBoxAlignAtLeft(std::string*);   // Print text within a bordered box
	void printBoxAlignAtRight(std::string*);  // Print text aligned right within a bordered box
	void printBoxAlignAtCentre(std::string*);  // Print text aligned center within a bordered box
	void printTitle();                              // Print the menu title
	unsigned int titleLength();                             // Calculate the length of the menu title  
	void printAsterisk();                          // Print an asterisk
	void printAsterisksAtBottom(unsigned int, unsigned int);            // Print a line of asterisks  
	void printEmptyAsteriskLine();                 // Print a line with an asterisk at each end
	

	void printSpaces(int);                         // Print a number of spaces 
	void printSpaces(unsigned int);

	unsigned int printSpacesBeforeOptions(int);             // Print spaces before options and return the total number
	void printOptionLine(std::string&, int&);          // Method to print an option line within the menu box.


	// User interaction functions
	template <typename T>
	T getUserInputNumInRange(T, T);            // Get integer input from user within a range

	void handleOptionSelection();                          // Handle user selection
	void displayMenu();                           // Display the menu

	// Destructor
	~MenuOutput();                                  // Destructor to clean up memory

}; //End of class definition