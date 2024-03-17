/*
*AUTHOR Jamie Mason
Last edit Sunday, March 17th 2024 7:57pm*
Added try-catch in all functions.
*/

#include "MenuOutput.h"
MenuOutput::MenuOutput() {
	try {
		preTextAst = 0; // Initialize preTextAst to 0
		postTextAst = 0; // Initialize postTextAst to 0
		numSpacesBeforeOptions = 0;
		numBeforeSpacesEachLine = 0;
		setOptions();   //calls and runs the setOptions function
	}
	catch (...) {
		std::cout << "Error in MenuOutput::MenuOutput() constructor function" << std::endl;
		exit(1);
	}
}

void MenuOutput::setOptions() {
	try {
		options = new std::string[size]; // Dynamically allocate memory for options array with size 'size'
		options[0] = "(1) Start"; // Set the first option to "(1) Start"
		options[1] = "(2) High Scores"; // Set the second option to "(2) High Scores"
		options[2] = "(3) Quit "; // Set the third option to "(3) Quit "
	}
	catch (...) {
		std::cout << "Error in MenuOutput::setOptions() function" << std::endl;
		exit(1);
	}
}
void MenuOutput::clearScreen() {
#ifdef _WIN32
	std::system("cls"); // Clear the console screen on Windows
#else
	// Assume Unix-like system
	std::system("clear"); // Clear the console screen on Unix-like systems
#endif
}

std::string* MenuOutput::getOptions() const {
	try {
		return options;
	}
	catch (...) {
		std::cout << "Error in MenuOutput class options getter function." << std::endl;
		exit(1);
	}
}
const std::string MenuOutput::getTitle() const {
	try {
		return title;
	}
	catch (...) {
		std::cout << "Error in MenuOutput class title getter function." << std::endl;
		exit(1);
	}
}
const unsigned int MenuOutput::getSize() const {
	try {
		return size;
	}
	catch (...) {
		std::cout << "Error in MenuOutput class size getter function." << std::endl;
		exit(1);
	}
}

void MenuOutput::printBoxAlignAtLeft(std::string* textList) {
	try {
		std::string temp;

		for (unsigned int i = 0; i < size; i++) {
			std::string horizontalLine(textList[i].length(), '-');

			temp = "+" + horizontalLine + "+";
			printOptionLine(temp, numSpacesBeforeOptions);

			temp = "|" + textList[i] + "|";
			printOptionLine(temp, numSpacesBeforeOptions);

			temp = "+" + horizontalLine + "+";
			printOptionLine(temp, numSpacesBeforeOptions);
		}
	}
	catch (...) {
		std::cout << "Error in MenuOutput::printBoxAlignAtLeft(std::string*) function" << std::endl;
		exit(1);
	}
}
void MenuOutput::printBoxAlignAtRight(std::string* textList) {
	try {
		size_t maxLength = findLongestString(textList);
		std::string leftSpaces, temp;

		for (unsigned int i = 0; i < size; i++) {
			std::string horizontalLine(textList[i].length(), '-');
			if (textList[i].length() < maxLength) {
				for (size_t j = 0; j < maxLength - textList[i].length(); j++) {
					leftSpaces = leftSpaces + " ";
				}
			}

			temp = leftSpaces + "+" + horizontalLine + "+";
			printOptionLine(temp, numSpacesBeforeOptions);

			temp = leftSpaces + "|" + textList[i] + "|";
			printOptionLine(temp, numSpacesBeforeOptions);

			temp = leftSpaces + "+" + horizontalLine + "+";
			printOptionLine(temp, numSpacesBeforeOptions);

			leftSpaces = "";
		}
	}
	catch (...) {
		std::cout << "Error in MenuOutput::printBoxAlignAtRight(std::string*) function" << std::endl;
		exit(1);
	}

}
void MenuOutput::printBoxAlignAtCentre(std::string* textList) {
	try {
		size_t maxLength = findLongestString(textList), totalSpaces, leftPadding, rightPadding;
		std::string spacesLeft, spacesRight, temp;

		for (unsigned int i = 0; i < size; i++) {
			std::string horizontalLine(textList[i].length(), '-');
			totalSpaces = maxLength - textList[i].length();

			// Calculate left and right padding
			leftPadding = totalSpaces / 2;
			rightPadding = totalSpaces - leftPadding;

			for (size_t j = 0; j < leftPadding; j++) {
				spacesLeft = spacesLeft + " ";
			}
			for (size_t j = 0; j < rightPadding; j++) {
				spacesRight = spacesRight + " ";
			}


			temp = spacesLeft + "+" + horizontalLine + "+" + spacesRight;
			printOptionLine(temp, numSpacesBeforeOptions);


			temp = spacesLeft + "|" + textList[i] + "|" + spacesRight;
			printOptionLine(temp, numSpacesBeforeOptions);


			temp = spacesLeft + "+" + horizontalLine + "+" + spacesRight;
			printOptionLine(temp, numSpacesBeforeOptions);


			spacesLeft = "";
			spacesRight = "";
		}
	}
	catch (...) {
		std::cout << "Error in MenuOutput::printBoxAlignAtCentre(std::string*) function" << std::endl;
		exit(1);
	}
}

// Method to print an option line within the menu box
void MenuOutput::printOptionLine(std::string temp, int numSpacesBeforeOptions) {
	try {
		// Print asterisk at the beginning of the line
		printAsterisk();

		// Calculate the number of spaces until the end asterisk
		int numOfSpacesUntilEndAsterisk = titleLength() - temp.length() - 2 - numSpacesBeforeOptions;

		if (numOfSpacesUntilEndAsterisk < 0) {
			// Adjust numSpacesBeforeOptions if needed
			numSpacesBeforeOptions = numSpacesBeforeOptions - abs(numOfSpacesUntilEndAsterisk);
			numSpacesBeforeOptions = abs(numSpacesBeforeOptions);
			numOfSpacesUntilEndAsterisk = 0;
		}

		// Print spaces before options
		printSpacesBeforeOptions(numSpacesBeforeOptions);

		// Print the option line
		std::cout << temp;

		// Print spaces until the end asterisk
		printSpaces(numOfSpacesUntilEndAsterisk);

		// Print the end asterisk and move to the next line
		std::cout << "*" << std::endl;
	}
	catch (...) {
		std::cout << "Error in MenuOutput::printOptionLine(std::string, int) function" << std::endl;
		exit(1);
	}
}


size_t MenuOutput::findLongestString(std::string* textList) {
	try {
		size_t maxLength = 0;
		for (unsigned int i = 0; i < size; i++) {
			if (textList[i].length() > maxLength) {
				maxLength = textList[i].length();
			}
		}
		return maxLength;
	}
	catch (...) {
		std::cout << "ERROR in MenuOutput::findLongestString(std::string*) function" << std::endl;
		exit(1);
	}
}

unsigned int MenuOutput::setZeroIfNegative(int num) {
	try {
		if (num < 0) {
			num = 0;
		}
		return num;
	}
	catch (...) {
		std::cout << "ERROR in MenuOutput::setZeroIfNegative(int) function" << std::endl;
		exit(1);
	}
}

void MenuOutput::printTitle() {
	try {
		printSpaces(numBeforeSpacesEachLine);
		preTextAst = setZeroIfNegative(preTextAst);
		postTextAst = setZeroIfNegative(postTextAst);
		std::string PreAst(preTextAst, '*');
		std::string PostAst(postTextAst, '*');


		std::cout << PreAst << title << PostAst << std::endl;
	}
	catch (...) {
		std::cout << "ERROR in MenuOutput::printTitle() function" << std::endl;
		exit(1);
	}
}
unsigned int MenuOutput::titleLength() {
	try {
		return title.length() + preTextAst + postTextAst;
	}
	catch (...) {
		std::cout << "ERROR in MenuOutput::titleLength() function" << std::endl;
		exit(1);
	}

}
void MenuOutput::printAsterisksAtBottom(unsigned int preTextAst, unsigned int postTextAst) {
	try {
		unsigned int ast = titleLength();
		printSpaces(numBeforeSpacesEachLine);

		for (unsigned int i = 0; i < ast; i++) {
			std::cout << "*";
		}
		std::cout << std::endl;
	}
	catch (...) {
		std::cout << "ERROR in MenuOutput::printAsterisksAtBottom(unsigned int, unsigned int) function" << std::endl;
		exit(1);
	}
}
void MenuOutput::printAsterisk() {
	try {
		printSpaces(numBeforeSpacesEachLine);
		std::cout << "*";
	}
	catch (...) {
		std::cout << "ERROR in MenuOutput::printAsterisk() function" << std::endl;
		exit(1);
	}
}
void MenuOutput::printEmptyAsteriskLine() {
	try {
		printAsterisk();
		unsigned int numOfSpacesUntilEndAsterisk;
		if (!(numOfSpacesUntilEndAsterisk = titleLength() - 2)) {
			numOfSpacesUntilEndAsterisk = 0;
		}
		printSpaces(numOfSpacesUntilEndAsterisk);
		std::cout << "*" << std::endl;
	}
	catch (const std::invalid_argument& e) {
		std::cerr << e.what() << std::endl;
		std::cout << "Negative value was passed as unsigned int in MenuOutput::printEmptyAsteriskLine() function" << std::endl;

		exit(1);
	}
	catch (...) {
		std::cout << "ERROR in MenuOutput::printEmptyAsteriskLine() function" << std::endl;
		exit(1);
	}
}

void MenuOutput::printSpaces(unsigned int spaces) {
	try {
		for (unsigned int i = 0; i < spaces; i++) {
			std::cout << " ";
		}
	}
	catch (const std::invalid_argument& e) {
		std::cerr << e.what() << std::endl;
		std::cout << "Negative value was passed as unsigned int in MenuOutput::printSpaces(unsigned int) function" << std::endl;

		exit(1);
	}
	catch (...) {
		std::cout << "ERROR in MenuOutput::printSpaces(unsigned int) function" << std::endl;
		exit(1);
	}
}
unsigned int MenuOutput::printSpacesBeforeOptions(int spaces) {

	try {
		spaces = setZeroIfNegative(spaces);
		unsigned int uSpaces = spaces;
		for (unsigned int i = 0; i < uSpaces; i++) {
			std::cout << " ";
		}
		return uSpaces;
	}
	catch (const std::invalid_argument& e) {
		std::cerr << e.what() << std::endl;
		std::cout << "Negative value was passed as unsigned int in function MenuOutput::printSpacesBeforeOptions(int spaces)." << std::endl;
		exit(1);
	}
	catch (...) {
		std::cout << "ERROR in function MenuOutput::printSpacesBeforeOptions(int spaces)." << std::endl;
		exit(1);
	}
}

// Functionality to get user input within a range.
template <typename T>
T MenuOutput::getUserInputNumInRange(T min, T max) {
	T input; // Variable to store the user input integer
	try {
		if (min <= max) {
			do {
				std::cout << "Select and option [" << min << " to " << max << "]: ";
				if (!(std::cin >> input)) {
					std::cout << "Invalid input! Must be an integer." << std::endl;
					std::cin.clear();
					std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
					continue;
				}
				else if (input < min || input > max) {
					std::cout << "Invalid input! Integer must be in the range [" << min << ", " << max << "]." << std::endl;
				}
			} while (input < min || input > max);

			return input;
		}
		else {
			std::cout << "ERROR min value is greater than max value.";
			exit(1);
		}
	}
	catch (...) {
		std::cout << "ERROR in function MenuOutput::getUserInputNumInRange()" << std::endl;
		exit(1);
	}
}


void MenuOutput::displayMenu() {

	try {
		const unsigned int maxAsterisk = 28;
		postTextAst = 15;
		if (maxAsterisk < postTextAst) {
			postTextAst = maxAsterisk;
		}
		preTextAst = maxAsterisk - postTextAst;
		numBeforeSpacesEachLine = 6;
		numSpacesBeforeOptions = 5;
		printTitle();
		printBoxAlignAtCentre(options);
		printAsterisksAtBottom(preTextAst, postTextAst);
		handleOptionSelection();
	}
	catch (const std::invalid_argument& e) {
		std::cerr << e.what() << std::endl;
		std::cout << "Negative value was assigned tp unsigned int in function MenuOutput::displayMenu()." << std::endl;
		exit(1);

	}
	catch (...) {
		std::cout << "ERROR in function MenuOutput::displayMenu()" << std::endl;
		exit(1);

	}
}
void MenuOutput::handleOptionSelection() {
	try {
		unsigned int userOption = getUserInputNumInRange((const unsigned int)1, size);
		switch (userOption) {
		case 1:
			//StartFunction
			std::this_thread::sleep_for(std::chrono::seconds(1));
			clearScreen();
			std::cout << "\nStart" << std::endl;
			break;
		case 2:
			std::this_thread::sleep_for(std::chrono::seconds(1));
			clearScreen();
			std::cout << "\nHigh Scores" << std::endl;

			break;
		case 3:
			//Quit function
			std::cout << "\nQUITTING GAME.....";
			std::this_thread::sleep_for(std::chrono::seconds(3));
			clearScreen();
			std::cout << "Game has Quitted" << std::endl;
			exit(1);
			break;
		default:
			std::cout << "Invalid input." << std::endl;
		}
	}
	catch (const std::invalid_argument& e) {
		std::cerr << e.what() << std::endl;
		std::cout << "Negative value was passed as unsigned int in function MenuOutput::handleOptionSelection()." << std::endl;
		exit(1);


	}
	catch (...) {
		std::cout << "ERROR in function MenuOutput::handleOptionSelection()." << std::endl;
		exit(1);

	}
}

MenuOutput::~MenuOutput() {
	try {
		delete[] options; // Deallocate memory for options array
	}
	catch (...) {
		std::cout << "Error in MenuOutput class destructor function." << std::endl;
		exit(1);
	}
}