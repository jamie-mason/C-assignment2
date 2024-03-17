#pragma once
#include <iostream>
#include <string>
#include <math.h>
#include <cstdlib> 
#include <chrono>
#include <thread>


class MenuOutput {
private:
	std::string title;
	std::string* options;
	int size;
public:
	int preTextAst, postTextAst,numSpaces, numSpacesBeforeOptions;
	MenuOutput();
	MenuOutput(std::string title);
	
	std::string* getOptions();
	std::string getTitle();
	void clearScreen();
	int getSize();
	void printBox(std::string& text);
	void printBoxAlignAtLeft(std::string* textList);
	void printBoxAlignAtRight(std::string* textList);
	void printBoxAlignAtCentre(std::string* textList);
	size_t findLongestString(std::string* textList);
	template<typename T>
	T setZeroIfNegative(T num);
	int getUserInputInteger(int, int);
	void selectOption();
	void printTitle();
	int titleLength();
	void printAsterisk();
	void printAsterisks();
	void printEmptyAsteriskLine();
	void printSpacesBeforeText();
	void printSpaces(int spaces);
	void printSpacesBeforeOptions();
	int printSpacesBeforeOptions(int);
	void displayMenu();

	~MenuOutput();

};