#ifndef SAFE_MATRIX_HPP
#define SAFE_MATRIX_HPP

#include "SafeArray.hpp"
#include <iostream>

using std::ostream;

template <class T>

class SafeMatrix {
public:
	SafeMatrix (int rows, int cols);
	SafeMatrix (const SafeMatrix& rhs);
	~SafeMatrix ( );
	void driver ( );
	int length ( ) const;
	SafeArray<T>& operator[](int index);
	SafeMatrix& operator=(const SafeMatrix& rhs);
	friend ostream& operator<<(ostream& output, const SafeMatrix& aSafeMatrix) {
		for (int i = 0; i < aSafeMatrix.rowSize; ++i) {
			output << aSafeMatrix.myRows[i] << "\n";
		}
		return output;
	}
private:
	int rowSize;
	//UNsafe array of SafeArrays.
	SafeArray<T>* myRows;
};

template <class T>
SafeMatrix<T>::SafeMatrix(int rows, int cols) : rowSize(rows), myRows(nullptr) {
	if(rows <= 0) {
		cout << "Invalid number of rows entered. The program will terminate.\n";
		exit (1);
	}
	myRows = new SafeArray<T>[rowSize];
	for (int i = 0; i < rowSize; ++i) {
		myRows[i] = SafeArray<T>(cols);
	}
}

template <class T>
SafeMatrix<T>::SafeMatrix(const SafeMatrix& rhs) : rowSize(rhs.rowSize), myRows(new SafeArray<T>[rhs.rowSize]) {
	for (int i = 0; i < rowSize; ++i) {
		myRows[i] = rhs.myRows[i];
	}
}

template <class T>
SafeMatrix<T>::~SafeMatrix( ) {
	delete[] myRows;
}

template <class T>
void SafeMatrix<T>::driver( ) {
	for (int i = 0; i < rowSize; ++i) {
		for (int j = 0; j < myRows[0].length(); ++j) {
			cin >> (*this)[i][j];
		}
	}
	cout << *this;
}

template <class T>
int SafeMatrix<T>::length( ) const {
	return rowSize;
}

template <class T>
SafeArray<T>& SafeMatrix<T>::operator[](int index)
{
	if(index < 0 || index >= rowSize) {
		cout << "Array index out of bounds: " << index << "\n";
		exit (1);
	}
	return myRows[index];
}

template <class T>
SafeMatrix<T>& SafeMatrix<T>::operator=(const SafeMatrix& rhs) {
	if (this != &rhs) {
		delete[] myRows;
		myRows = new SafeArray<T>[rhs.rowSize];
		rowSize = rhs.rowSize;
		for (int i = 0; i < rowSize; ++i) {
			myRows[i] = rhs.myRows[i];
		}
	}
	return *this;
}
#endif //SAFE_MATRIX_HPP

