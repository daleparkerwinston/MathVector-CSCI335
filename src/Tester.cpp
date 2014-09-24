/*
 * Tester.cpp
 *
 *  Created on: Sep 10, 2014
 *      Author: Dale
 */




#include <iostream>
#include "MathVector.h"

using namespace std;

int main() {
	cout << "Math Vector Program" << endl;

	MathVector <int> a, b, c;

	cin >> a;
	cin >> b;

	cout << a << endl;

	c = a + b;

	cout << "a + b: " << c << endl;
}
