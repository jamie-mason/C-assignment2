/*
*AUTHOR Jamie Mason
Last edit Sunday, March 17th 2024 7:57pm*
*/

#include "MenuOutput.h"
MenuOutput::MenuOutput() {
	try {
		preTextAst = 0; // Initialize preTextAst to 0
		postTextAst = 0; // Initialize postTextAst to 0
		numBeforeSpacesEachLine = 6;
		numSpacesBeforeOptions = new int(5);

		hs = new HighScoreManager("HighScores.txt");

		setOptions();   //calls and runs the setOptions function
	}
	catch (...) {
		std::cout << "Error in MenuOutput::MenuOutput() constructor function" << std::endl;
		exit(1);
	}
}

void MenuOutput::setOptions() {
	try {
		options = new std::string[(*size)]; // Dynamically allocate memory for options array with size 'size'
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
		return *title;
	}
	catch (...) {
		std::cout << "Error in MenuOutput class title getter function." << std::endl;
		exit(1);
	}
}
const unsigned int MenuOutput::getSize() const {
	try {
		return *size;
	}
	catch (...) {
		std::cout << "Error in MenuOutput class size getter function." << std::endl;
		exit(1);
	}
}
unsigned int MenuOutput::getNumSpacesBeforeEachLine() const {
	try {
		return numBeforeSpacesEachLine;
	}
	catch (...) {
		std::cout << "ERROR IN getNumSpacesBeforeEachLine()." << std::endl;
		exit(1);
	}
}

void MenuOutput::printBoxAlignAtLeft(std::string* textList) {
	try {
		std::string* temp = new std::string("");
		std::string* horizontalLine = new std::string("");
		unsigned int* i = new unsigned int(0);

		for (; *i < *size; (*i)++) {
			horizontalLine = new std::string(textList[*i].length(), '-');

			temp = new std::string("+" + *horizontalLine + "+");
			printOptionLine(*temp, *numSpacesBeforeOptions);

			temp = new std::string("|" + textList[*i] + "|");
			printOptionLine(*temp, *numSpacesBeforeOptions);

			temp = new std::string("+" + *horizontalLine + "+");
			printOptionLine(*temp, *numSpacesBeforeOptions);

			delete temp;    //deallocate memory for memory pointed to by the pointer temp.
			delete horizontalLine;  //deallocate memory for memory pointed to by the pointer horizontalLine.
		}
		delete i;  //deallocate memory for memory pointed to by the pointer i.
	}
	catch (...) {
		std::cout << "Error in MenuOutput::printBoxAlignAtLeft(std::string*) function" << std::endl;
		exit(1);
	}
}
void MenuOutput::printBoxAlignAtRight(std::string* textList) {
	try {
		size_t* maxLength = new size_t(findLongestString(textList));
		size_t* j = new size_t(0);

		std::string* leftSpaces = new std::string("");
		std::string* temp = new std::string("");
		std::string* horizontalLine = new std::string("");
		unsigned int* i = new unsigned int(0);

		for (; *i < *size; (*i)++) {
			horizontalLine = new std::string(textList[*i].length(), '-');
			if (textList[*i].length() < *maxLength) {
				for (; *j < *maxLength - textList[*i].length(); (*j)++) {
					leftSpaces = new std::string(*leftSpaces + " ");
				}
				delete j;  //deallocate memory for memory pointed to by the pointer j.

			}

			temp = new std::string(*leftSpaces + "+" + *horizontalLine + "+");
			printOptionLine(*temp, *numSpacesBeforeOptions);

			temp = new std::string(*leftSpaces + "|" + textList[*i] + "|");
			printOptionLine(*temp, *numSpacesBeforeOptions);

			temp = new std::string(*leftSpaces + "+" + *horizontalLine + "+");
			printOptionLine(*temp, *numSpacesBeforeOptions);


			delete temp;   //deallocate memory for memory pointed to by the pointer temp.
			delete horizontalLine;   //deallocate memory for memory pointed to by the pointer horizontalLine.
			leftSpaces = new std::string("");
		}
		delete maxLength;   //deallocate memory for memory pointed to by the pointer maxLength.
		delete leftSpaces;  //deallocate memory for memory pointed to by the pointer leftSpaces.
		delete i;  //deallocate memory for memory pointed to by the pointer i.
	}
	catch (...) {
		std::cout << "Error in MenuOutput::printBoxAlignAtRight(std::string*) function" << std::endl;
		exit(1);
	}

}
void MenuOutput::printBoxAlignAtCentre(std::string* textList) {
	try {
		size_t* maxLength = new size_t(findLongestString(textList));
		size_t* totalSpaces = new size_t(0);
		size_t* leftPadding = new size_t(0);
		size_t* rightPadding = new size_t(0);
		size_t* j = new size_t(0);

		unsigned int* i = new unsigned int(0);

		std::string* spacesLeft = new std::string("");
		std::string* spacesRight = new std::string("");
		std::string* temp = new std::string("");
		std::string* horizontalLine = new std::string("");

		for (; *i < *size; (*i)++) {
			horizontalLine = new std::string(textList[*i].length(), '-');
			totalSpaces = new size_t(*maxLength - textList[*i].length());

			// Calculate left and right padding
			leftPadding = new size_t(*totalSpaces / 2);
			rightPadding = new size_t(*totalSpaces - *leftPadding);

			for (j = new size_t(0); *j < *leftPadding; (*j)++) {
				spacesLeft = new std::string(*spacesLeft + " ");
			}
			delete j;    //deallocate memory for memory pointed to by the pointer j.

			for (j = new size_t(0); *j < *leftPadding; (*j)++) {
				spacesRight = new std::string(*spacesRight + " ");
			}
			delete j;   //deallocate memory for memory pointed to by the pointer j.

			temp = new std::string(*spacesLeft + "+" + *horizontalLine + "+" + *spacesRight);
			printOptionLine(*temp, *numSpacesBeforeOptions);


			temp = new std::string(*spacesLeft + "|" + textList[*i] + "|" + *spacesRight);
			printOptionLine(*temp, *numSpacesBeforeOptions);


			temp = new std::string(*spacesLeft + "+" + *horizontalLine + "+" + *spacesRight);
			printOptionLine(*temp, *numSpacesBeforeOptions);


			spacesLeft = new std::string("");
			spacesRight = new std::string("");

			delete temp;           //deallocate memory for memory pointed to by the pointer temp.
			delete horizontalLine;   //deallocate memory for memory pointed to by the pointer horizontalLine.
		}
		delete maxLength;      //deallocate memory for memory pointed to by the pointer maxLength.
		delete totalSpaces;    //deallocate memory for memory pointed to by the pointer totalSpaces.
		delete leftPadding;    //deallocate memory for memory pointed to by the pointer leftPadding.
		delete rightPadding;   //deallocate memory for memory pointed to by the pointer rightPadding.
		delete spacesLeft;    //deallocate memory for memory pointed to by the pointer spacesLeft.
		delete spacesRight;  //deallocate memory for memory pointed to by the pointer spacesRight.
		delete i;   //deallocate memory for memory pointed to by the pointer i.
	}
	catch (...) {
		std::cout << "Error in MenuOutput::printBoxAlignAtCentre(std::string*) function" << std::endl;
		exit(1);
	}
}

// Method to print an option line within the menu box
void MenuOutput::printOptionLine(std::string& temp, int& numSpacesBeforeOptions) {
	try {
		// Print asterisk at the beginning of the line
		printAsterisk();

		// Calculate the number of spaces until the end asterisk
		int* numOfSpacesUntilEndAsterisk = new int(titleLength() - temp.length() - 2 - numSpacesBeforeOptions);

		if (*numOfSpacesUntilEndAsterisk < 0) {
			// Adjust numSpacesBeforeOptions if needed
			numSpacesBeforeOptions = numSpacesBeforeOptions - abs(*numOfSpacesUntilEndAsterisk);
			numSpacesBeforeOptions = abs(numSpacesBeforeOptions);
			numOfSpacesUntilEndAsterisk = new int(0);
		}

		// Print spaces before options
		printSpacesBeforeOptions(numSpacesBeforeOptions);

		// Print the option line
		std::cout << temp;

		// Print spaces until the end asterisk
		printSpaces(*numOfSpacesUntilEndAsterisk);

		// Print the end asterisk and move to the next line
		std::cout << "*" << std::endl;
		delete numOfSpacesUntilEndAsterisk;  //deallocate memory for memory pointed to by the pointer numOfSpacesUntilEndAsterisk.
	}
	catch (...) {
		std::cout << "Error in MenuOutput::printOptionLine(std::string, int) function" << std::endl;
		exit(1);
	}
}


size_t MenuOutput::findLongestString(std::string* textList) {
	try {
		size_t maxLength = 0;
		for (unsigned int i = 0; i < *size; i++) {
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
		std::string preAst(preTextAst, '*');
		std::string postAst(postTextAst, '*');


		std::cout << preAst << *title << postAst << std::endl;

	}
	catch (...) {
		std::cout << "ERROR in MenuOutput::printTitle() function" << std::endl;
		exit(1);
	}
}
unsigned int MenuOutput::titleLength() {
	try {
		return (*title).length() + preTextAst + postTextAst;
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
		unsigned int* numOfSpacesUntilEndAsterisk = new unsigned int(0);
		if (!(*numOfSpacesUntilEndAsterisk = titleLength() - 2)) {
			numOfSpacesUntilEndAsterisk = new unsigned int(0);
		}
		printSpaces(*numOfSpacesUntilEndAsterisk);
		delete numOfSpacesUntilEndAsterisk;  //deallocate memory for memory pointed to by the pointer numOfSpacesUntilEndAsterisk.
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


void MenuOutput::printSpaces(int spaces) {
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
				std::cout << "Select an option [" << min << " to " << max << "]: ";
				if (!(std::cin >> input)) {
					std::cout << "Invalid input! Must be an integer.\n" << std::endl;
					std::cin.clear();
					std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
				}
				else if (input < min || input > max) {
					std::cout << "Invalid input! Integer must be in the range [" << min << ", " << max << "].]n" << std::endl;
				}
			} while (input < min || input > max);

			return input;
		}
		else {
			std::cout << "ERROR min value is greater than max value."<<std::endl;
			exit(1);
		}
	}
	catch (...) {
		std::cout << "ERROR in function MenuOutput::getUserInputNumInRange()" << std::endl;
		exit(1);
	}
}

template <typename U>
U MenuOutput::getUserInputNumInRange(std::string output, U min, U max) {
	U input; // Variable to store the user input integer
	try {
		if (min <= max) {
			do {
				std::cout << output;
				if (!(std::cin >> input)) {
					std::cout << "Invalid input! Must be an integer.\n" << std::endl;
					std::cin.clear();
					std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
				}
				else if (input < min || input > max) {
					return -1;
				}
			} while (input < min || input > max);

			return input;
		}
		else {
			std::cout << "ERROR min value is greater than max value."<<std::endl;
			exit(1);
		}
	}
	catch (...) {
		std::cout << "ERROR in function MenuOutput::getUserInputNumInRange()" << std::endl;
		exit(1);
	}
}

int MenuOutput::getUserInputNum(std::string output) {
	try {
		int input; // Variable to store the user input integer
		while (true) {
			std::cout << output;
			if (!(std::cin >> input)) {
				std::cout << "Invalid input! Must be an integer." << std::endl;
				std::cin.clear();
				std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			}
			else {
				return input;
			}
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
		MainLoop p;
		unsigned int userOption = getUserInputNumInRange((const unsigned int)1, *size);
		if (userOption == 1) {
			// StartFunction
			std::cout << "\nSTARTING GAME.....\n";
			std::this_thread::sleep_for(std::chrono::seconds(1));
			clearScreen();
			p.play();
		}
		else if (userOption == 2) {
			std::cout << "\nACCESSING HIGH SCORES.....\n";
			std::this_thread::sleep_for(std::chrono::seconds(1));
			clearScreen();
			accessResetDeleteHS();
		}
		else if (userOption == 3) {
			// Quit function
			std::cout << "\nQUITTING GAME.....\n";
			std::this_thread::sleep_for(std::chrono::seconds(3));
			clearScreen();
			std::cout << "Game has Quitted" << std::endl;
			exit(1);
		}
		else {
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
HighScoreManager MenuOutput::getHighScoreManager() {
	return *hs;
}
void MenuOutput::accessResetDeleteHS() {
	try {
		hs->printHighScores();
		int selected;
		std::string spaces(numBeforeSpacesEachLine, ' ');
		std::string output;
		std::cout << std::endl;
		unsigned int userOption;
		if (hs->getHighScores().size() > 0) {
			output = spaces + "Options: [Go back (1 or any other number)|Delete scores (2)|Reset all scores (3)]: ";
			userOption = getUserInputNumInRange(output, (const unsigned int)1, (const unsigned int)3);

			if (userOption == 2) {
				//delete
				selected = getUserInputNum("\n" + spaces + "Which index would you like to delete? [enter any other number to go back]: ");
				if (selected > 1 && selected <= hs->getHighScores().size()) {
					hs->deleteHighScore(selected - 1);
				}
				clearScreen();
				accessResetDeleteHS();

			}

			else if (userOption == 3) {
				//reset function
				char ans;
				std::cout << "Are you sure you want to reset your stats? [y/n]: ";
				if (std::cin >> ans) {
					if (ans == 'y' || ans == 'Y') {
						hs->resetHighScores();

					}
					clearScreen();
					accessResetDeleteHS();
				}
			}
			else {
				//Back 
				std::cout << "\nMAIN MENU.....\n";
				std::this_thread::sleep_for(std::chrono::seconds(1));
				clearScreen();
				displayMenu();
			}
		}
		else
		{
			std::string input;
			std::cout << spaces + "Options: [Go back (any key)]: ";
			std::cin >> input;
			std::cout << "\nMAIN MENU.....\n";
			std::this_thread::sleep_for(std::chrono::seconds(1));
			clearScreen();
			displayMenu();
		}
		

	}
	catch (...) {
		std::cout << "ERROR in accessResetDeleteHS() function." << std::endl;
		exit(1);
	}
}
MenuOutput::~MenuOutput() {
	try {
		delete[] options; // Deallocate memory for options array
		delete numSpacesBeforeOptions;  // Deallocate memory pointed to by the pointer numSpacesBeforeOptions
		delete title; // Deallocate memory pointed to by the pointer title
		delete size; // Deallocate memory pointed to by the pointer size
		delete hs;

	}
	catch (...) {
		std::cout << "Error in MenuOutput class destructor function." << std::endl;
		exit(1);
	}
}