/*
*AUTHOR Jamie Mason
Last edit Sunday, March 17th 2024 *
*/

#include "MenuOutput.h"
MenuOutput::MenuOutput() {
	preTextAst = 0; // Initialize preTextAst to 0
	postTextAst = 0; // Initialize postTextAst to 0
	
	setOptions();   //calls and runs the setOptions function
}

void MenuOutput::setOptions() {
	options = new std::string[size]; // Dynamically allocate memory for options array with size 'size'
	options[0] = "(1) Start"; // Set the first option to "(1) Start"
	options[1] = "(2) High Scores"; // Set the second option to "(2) High Scores"
	options[2] = "(3) Quit "; // Set the third option to "(3) Quit "
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
	return options;
}
const std::string MenuOutput::getTitle() const {
	return title;
}
const unsigned int MenuOutput::getSize() const {
	return size;
}

void MenuOutput::printBoxAlignAtLeft(std::string* textList) {
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
void MenuOutput::printBoxAlignAtRight(std::string* textList) {

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
void MenuOutput::printBoxAlignAtCentre(std::string* textList) {

	size_t maxLength = findLongestString(textList), totalSpaces ,leftPadding, rightPadding;
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

// Method to print an option line within the menu box
void MenuOutput::printOptionLine(std::string temp, int numSpacesBeforeOptions) {
	// Print asterisk at the beginning of the line
	printAsterisk();

	// Calculate the number of spaces until the end asterisk
	int numOfSpacesUntilEndAsterisk = titleLength() - temp.length() - 2 - numSpacesBeforeOptions;

	if (numOfSpacesUntilEndAsterisk < 0) {
		// Adjust numSpacesBeforeOptions if needed
		numSpacesBeforeOptions = numSpacesBeforeOptions - abs(numOfSpacesUntilEndAsterisk);
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


size_t MenuOutput::findLongestString(std::string* textList) {
	size_t maxLength = 0;
	for (unsigned int i = 0; i < size; i++) {
		if (textList[i].length() > maxLength) {
			maxLength = textList[i].length();
		}
	}
	return maxLength;
}

unsigned int MenuOutput::setZeroIfNegative(int num) {
	if (num < 0) {
		num = 0;
	}
	return num;
}

void MenuOutput::printTitle() {
	printSpaces(numSpaces);
	preTextAst = setZeroIfNegative(preTextAst);
	postTextAst = setZeroIfNegative(postTextAst);
	std::string PreAst(preTextAst, '*');
	std::string PostAst(postTextAst, '*');


	std::cout << PreAst << title << PostAst << std::endl;

}
int MenuOutput::titleLength() {

	return title.length() + preTextAst + postTextAst;

}
void MenuOutput::printAsterisksAtBottom(int preTextAst, int postTextAst) {
	unsigned int ast = title.length() + unsigned int (setZeroIfNegative(preTextAst)) + unsigned int (setZeroIfNegative(postTextAst));
	printSpaces(numSpaces);

	for (unsigned int i = 0; i < ast; i++) {
		std::cout << "*";
	}
	std::cout << std::endl;
}
void MenuOutput::printAsterisk() {
	printSpaces(numSpaces);
	std::cout << "*";
}
void MenuOutput::printEmptyAsteriskLine() {
	printAsterisk();
	int numOfSpacesUntilEndAsterisk = titleLength() - 2;
	printSpaces(numOfSpacesUntilEndAsterisk);
	std::cout << "*" << std::endl;
}

void MenuOutput::printSpaces(int spaces) {
	for (int i = 0; i < spaces; i++) {
		std::cout << " ";
	}
}
int MenuOutput::printSpacesBeforeOptions(int spaces) {
	spaces = setZeroIfNegative(spaces);
	for (int i = 0; i < spaces; i++) {
		std::cout << " ";
	}
	return spaces;
}

// Functionality to get user input within a range.
template <typename T>
T MenuOutput::getUserInputNumInRange(T min, T max) {
	T input; // Variable to store the user input integer
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


void MenuOutput::displayMenu() {

	unsigned int maxAsterisk = 28;
	postTextAst = 15;        //must be smaller or equal to max Asterisk and be positive number because it is a scalar value.
	preTextAst = maxAsterisk - postTextAst;
	numSpaces = 6;
	numSpacesBeforeOptions = 5;
	printTitle();
	printBoxAlignAtCentre(options);
	printAsterisksAtBottom(preTextAst, postTextAst);
	handleOptionSelection();
}
void MenuOutput::handleOptionSelection() {
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

MenuOutput::~MenuOutput() {
	delete[] options; // Deallocate memory for options array
}