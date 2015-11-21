#ifndef SAFE_MATRIX_HPP
#define SAFE_MATRIX_HPP

#include "SafeArray.hpp"
#include <iostream>

using std::ostream;

template <class T>

class SafeMatrix {
public:
	SafeMatrix (int rows, int cols);
	void driver ( );
	int length ( ) const;
	SafeArray<T>& operator[](int index);
	friend ostream& operator<<(ostream& output, const SafeMatrix& aSafeMatrix) {
		for (int i = 0; i < aSafeMatrix.rowSize; ++i) {
			output << aSafeMatrix.myRows[i] << "\n";
		}
		return output;
	}
private:
	int rowSize;
	//SafeArray of SafeArrays.
	SafeArray<SafeArray<T>> myRows;
};

template <class T>
SafeMatrix<T>::SafeMatrix(int rows, int cols) : rowSize(rows), myRows(SafeArray<SafeArray<T>>(rowSize)) {
	for (int i = 0; i < rowSize; ++i) {
		myRows[i] = SafeArray<T>(cols);
	}
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

#endif //SAFE_MATRIX_HPP

