// main.cpp
// Created by Evan Almonte
//  
#include "SafeMatrix.hpp"
#include <string>

void getRowAndColSize (int& rowSize, int& colSize);

int main() {
	int rowSize, colSize;
	
	cout << "Test #1 using <int>:\n";
	getRowAndColSize (rowSize, colSize);
	SafeMatrix<int> mySafeMatrix (rowSize, colSize);
	mySafeMatrix.driver ( );
	
	cout << "Test #2 using <string>:\n";
	getRowAndColSize (rowSize, colSize);
	SafeMatrix<string> mySafeMatrix2 (rowSize, colSize);
	mySafeMatrix2.driver ( );

	return 0;
}

void getRowAndColSize(int& rowSize, int& colSize) {
	cout << "Please enter the row size: ";
	while(!(cin >> rowSize)) {
		cout << "Invalid value entered, try again: ";
		cin.clear ( );
		cin.ignore (100,'\n');
	}
	cout << "Please enter the col size: ";
	while (!(cin >> colSize)) {
		cout << "Invalid value entered, try again: ";
		cin.clear ( );
		cin.ignore (100, '\n');
	}
}