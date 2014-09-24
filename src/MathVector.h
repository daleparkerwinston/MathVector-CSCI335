/*
 * MathVector.h
 *
 *  Created on: Sep 10, 2014
 *      Author: Dale
 */

#ifndef MATHVECTOR_H_
#define MATHVECTOR_H_

#include <iostream>
#include <assert.h>

using namespace std;

template <typename dataType>
class MathVector {

private:
	int size;
	dataType *pointer;
public:
	MathVector() {
		size = 0;
		pointer = new dataType[size];
	}

	MathVector(int size) {
		pointer = new dataType[size];
		this->size = size;

	}

	~MathVector() {
		delete[] pointer;
	}

	void Erase() {
		delete[] pointer;
		pointer = 0;
		size = 0;
	}

	int getSize() {
		return size;
	}

	void setSize(int newSize) {
		if(newSize <= 0) {
			Erase();
			return;
		}


		dataType *newPointer = new dataType[newSize];
		if(size > 0) {
			int numToCopy;
			if(newSize < size) {
				numToCopy = newSize;
			} else {
				numToCopy = size;
			}

			for(int i = 0; i < numToCopy; i++) {
				newPointer[i] = pointer[i];
			}
		}

		delete[] pointer;

		pointer = newPointer;

		size = newSize;
	}

	dataType& operator[](int element) {
		assert(element >= 0 && element < size);
		return pointer[element];
	}

	void add(dataType data) {
		size++;
		setSize(size);
		pointer[size - 1] = data;
	}

	dataType deleteElement(int element) {
		dataType data = pointer[element];
		dataType *newPointer = new dataType[size-1];

		for(int i = 0; i < element; i++) {
			newPointer[i] = pointer[i];
		}

		for(int i = element+1; i < size; i++) {
			newPointer[i - 1] = pointer[i];
		}

		delete[] pointer;
		pointer = newPointer;
		size--;
		return data;
	}

	void insertBefore(int element, dataType data) {
		dataType *newPointer = new dataType[size+1];

		for(int i = 0; i < element; i++) {
			newPointer[i] = pointer[i];
		}

		newPointer[element] = data;

		for(int i = element; i < size; i++) {
			newPointer[i+1] = pointer[i];
		}

		delete[] pointer;
		pointer = newPointer;
		size++;
	}

	template <typename type>
	friend ostream &operator<<(ostream &output, MathVector<type> &V);

	template <typename type>
	friend istream &operator>>(istream &input, MathVector<type> &V);

	template <typename type>
	friend MathVector<type> operator+(const MathVector<dataType> &v1, const MathVector<dataType> &v2);



	//overload + operator

	//overload += operator
};

template <typename dataType>
MathVector<dataType> operator+(const MathVector<dataType> v1, const MathVector<dataType> v2) {
	MathVector<dataType> vector;
	//check to see that vectors are the same size
	vector.setSize(v1.getSize()); // problems here!!!!!
	/**
	 *
	 *
	 *
	 *
	 *
	 *
	 */return vector;
}

template <typename dataType>
ostream &operator<<(ostream &output, MathVector<dataType> &V) {
	for(int i = 0; i < V.size - 1; i++) {
		output << V[i] << " ";  //prints element and a space
	}
	output << V[V.size - 1]; //prints the last element without a space after
	return output;
}

template <typename dataType>
istream &operator>>(istream &input, MathVector<dataType> &V) {
	string line;
	int dimensions;
	cout << "Enter number of dimensions for vector: ";
	input >> dimensions;
	V.setSize(dimensions);
	cout << "Enter vector values: ";
	for(int i = 0; i < dimensions; i ++) {
		input >> V[i];
	}

	return input;
}


#endif /* MATHVECTOR_H_ */
