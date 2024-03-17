#include "MenuOutput.h"

MenuOutput::MenuOutput() {
	title = "";
	size = 3;
	options = new std::string[0];
	preTextAst = 0;
	postTextAst = 0;
}
void MenuOutput::clearScreen() {
#ifdef _WIN32
	std::system("cls");
#else
	// Assume Unix-like system
	std::system("clear");
#endif
}

MenuOutput::MenuOutput(std::string title) {
	this->title = title;
	size = 3;

	preTextAst = 0;
	postTextAst = 0;

	options = new std::string[size];
	options[0] = "(1) Start";
	options[1] = "(2) High Scores";
	options[2] = "(3) Quit ";

}
std::string* MenuOutput::getOptions() {
	return options;
}
std::string MenuOutput::getTitle() {
	return title;
}
int MenuOutput::getSize() {
	return size;
}
void MenuOutput::printBox(std::string& text) {

	std::string horizontalLine(text.length(), '-');

	std::cout << "+" << horizontalLine << "+\n";
	std::cout << "|" << text << "|\n";
	std::cout << "+" << horizontalLine << "+\n";
}

void MenuOutput::printBoxAlignAtLeft(std::string* textList) {
	std::string temp;
	int numOfSpacesUntilEndAsterisk;

	for (int i = 0; i < size; i++) {
		std::string horizontalLine(textList[i].length(), '-');
		auto printOptionLine = [&](std::string temp, int numSpacesBeforeOptions) {
			printAsterisk();
			int numOfSpacesUntilEndAsterisk = titleLength() - temp.length() - 2 - numSpacesBeforeOptions;
			if (numOfSpacesUntilEndAsterisk < 0) {
				numSpacesBeforeOptions = numSpacesBeforeOptions - abs(numOfSpacesUntilEndAsterisk);
				numOfSpacesUntilEndAsterisk = 0;
			}
			printSpacesBeforeOptions(numSpacesBeforeOptions);
			std::cout << temp;
			printSpaces(numOfSpacesUntilEndAsterisk);
			std::cout << "*" << std::endl;

			};
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
	int numOfSpacesUntilEndAsterisk;

	for (int i = 0; i < size; i++) {
		std::string horizontalLine(textList[i].length(), '-');
		if (textList[i].length() < maxLength) {
			for (size_t j = 0; j < maxLength - textList[i].length(); j++) {
				leftSpaces = leftSpaces + " ";
			}
		}
		auto printOptionLine = [&](std::string temp, int numSpacesBeforeOptions) {
			printAsterisk();
			int numOfSpacesUntilEndAsterisk = titleLength() - temp.length() - 2 - numSpacesBeforeOptions;
			if (numOfSpacesUntilEndAsterisk < 0) {
				numSpacesBeforeOptions = numSpacesBeforeOptions - abs(numOfSpacesUntilEndAsterisk);
				numOfSpacesUntilEndAsterisk = 0;
			}
			printSpacesBeforeOptions(numSpacesBeforeOptions);
			std::cout << temp;
			printSpaces(numOfSpacesUntilEndAsterisk);
			std::cout << "*" << std::endl;

		};
		temp =  leftSpaces + "+" + horizontalLine + "+";
		printOptionLine(temp, numSpacesBeforeOptions);

		temp =  leftSpaces + "|" + textList[i] + "|";
		printOptionLine(temp, numSpacesBeforeOptions);

		temp =  leftSpaces + "+" + horizontalLine + "+";
		printOptionLine(temp, numSpacesBeforeOptions);

		leftSpaces = "";
	}
	
}
void MenuOutput::printBoxAlignAtCentre(std::string* textList) {

	size_t maxLength = findLongestString(textList), totalSpaces;
	std::string spacesLeft, spacesRight,temp;
	int numOfSpacesUntilEndAsterisk;


	for (int i = 0; i < size; i++) {
		std::string horizontalLine(textList[i].length(), '-');
		totalSpaces = maxLength - textList[i].length();
		// Calculate left and right padding
		size_t leftPadding = totalSpaces / 2;
		size_t rightPadding = totalSpaces - leftPadding;

		for (size_t j = 0; j < leftPadding; j++) {
			spacesLeft = spacesLeft + " ";
		}
		for (size_t j = 0; j < rightPadding; j++) {
			spacesRight = spacesRight + " ";
		}
		auto printOptionLine = [&](std::string temp, int numSpacesBeforeOptions) {
			printAsterisk();
			int numOfSpacesUntilEndAsterisk = titleLength() - temp.length() - 2 - numSpacesBeforeOptions;
			if (numOfSpacesUntilEndAsterisk < 0) {
				numSpacesBeforeOptions = numSpacesBeforeOptions - abs(numOfSpacesUntilEndAsterisk);
				numOfSpacesUntilEndAsterisk = 0;
			}
			printSpacesBeforeOptions(numSpacesBeforeOptions);
			std::cout << temp;
			printSpaces(numOfSpacesUntilEndAsterisk);
			std::cout << "*" << std::endl;

			};

		temp = spacesLeft + "+" + horizontalLine + "+" + spacesRight;
		printOptionLine(temp, numSpacesBeforeOptions);


		temp =  spacesLeft + "|" + textList[i] + "|" + spacesRight;
		printOptionLine(temp, numSpacesBeforeOptions);


		temp = spacesLeft + "+" + horizontalLine + "+" + spacesRight;
		printOptionLine(temp, numSpacesBeforeOptions);


		spacesLeft = "";
		spacesRight = "";
	}
}
size_t MenuOutput::findLongestString(std::string* textList) {
	size_t maxLength = 0;
	for (int i = 0; i < size; i++) {
		if (textList[i].length() > maxLength) {
			maxLength = textList[i].length();
		}
	}
	return maxLength;
}

template<typename T>
T MenuOutput::setZeroIfNegative(T num) {
	if (num < 0) {
		num = 0;
	}
	return num;
}

void MenuOutput::printTitle() {
	printSpacesBeforeText();
	preTextAst = setZeroIfNegative(preTextAst);
	postTextAst = setZeroIfNegative(postTextAst);
	std::string PreAst(preTextAst, '*');
	std::string PostAst(postTextAst, '*');


	std::cout << PreAst << title << PostAst << std::endl;

}
int MenuOutput::titleLength() {

	return title.length() + preTextAst + postTextAst;

}
void MenuOutput::printAsterisks() {
	int ast = title.length() + preTextAst + postTextAst;
	printSpacesBeforeText();
	for (int i = 0; i < ast; i++) {
		std::cout << "*";
	}
	std::cout << std::endl;
}
void MenuOutput::printAsterisk() {
	printSpacesBeforeText();
	std::cout << "*";
}
void MenuOutput::printEmptyAsteriskLine() {
	printAsterisk();
	int numOfSpacesUntilEndAsterisk = titleLength() - 2;
	printSpaces(numOfSpacesUntilEndAsterisk);
	std::cout << "*" << std::endl;
}

void MenuOutput::printSpacesBeforeText() {
	for (int i = 0; i < numSpaces; i++) {
		std::cout << " ";
	}
}
void MenuOutput::printSpaces(int spaces) {
	for (int i = 0; i < spaces; i++) {
		std::cout << " ";
	}
}
void MenuOutput::printSpacesBeforeOptions() {
	if (numSpacesBeforeOptions < 0) {
		numSpacesBeforeOptions = 0;
	}
	for (int i = 0; i < numSpacesBeforeOptions; i++) {
		std::cout << " ";
	}
}
int MenuOutput::printSpacesBeforeOptions(int numSpaces) {
	if (numSpaces < 0) {
		numSpaces = 0;
	}
	for (int i = 0; i < numSpaces; i++) {
		std::cout << " ";
	}
	return numSpaces;
}
int MenuOutput::getUserInputInteger(int min, int max) {
	int input; // Variable to store the user input integer
	if (min <= max) {
		do {
			std::cout << "Select and option ["<<min << " to " << max <<"]: ";
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
	
	int maxAsterisk = 28;
	postTextAst = 15;
	preTextAst = maxAsterisk - postTextAst;
	numSpaces = 6;
	numSpacesBeforeOptions = 5;
	printTitle();
	printBoxAlignAtCentre(options);
	printAsterisks();
	selectOption();
}
void MenuOutput::selectOption() {
	int userOption = getUserInputInteger(1, size);
	switch (userOption) {
	case 1:
		//StartFunction
		std::this_thread::sleep_for(std::chrono::seconds(1));
		clearScreen();
		std::cout << "\nStart"<<std::endl;
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
	delete[] options;
}