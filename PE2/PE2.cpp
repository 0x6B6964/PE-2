#include "PE2.h"
#include <math.h>
#include <iostream>
#include <iomanip>

using namespace std;

int LengthOfInt(int n);

double* PE2::CalculateOnASpan(mathFunc func)
{
	double* resultArray = new double[_n];

	for (int i = 0; i < _n; i++) {
		resultArray[i] = func(_a + _h * i);
	}

	return resultArray;
}

void PE2::Parse(double** arrayToParse)
{
	cout << fixed << setprecision(5);

	int spacing = 12;

	cout << setw(spacing) << "x"
		<< setw(spacing) << "Iterative"
		<< setw(spacing) << "Math func"
		<< setw(spacing) << "Recursive"
		<< endl;

	for (int i = 0; i < _n; i++) {
		cout << setw(spacing) << (_a + _h * i)
			<< setw(spacing) << arrayToParse[0][i]
			<< setw(spacing) << arrayToParse[1][i]
			<< setw(spacing) << arrayToParse[2][i]
			<< endl;
	}
}

void PE2::ProperParse()
{
	cout << fixed << setprecision(5);

	cout << setw(12) << "X"
		<< setw(12) << "F0"
		<< " ";

	for (int i = 1; i < _v.size(); i++) {
		cout << setw(10) << "F" << i
			<< setw(5 - LengthOfInt(i)) << "|F" << i << " - F0|";
	}

	cout << endl;

	for (int i = 0; i < _n; i++) {
		cout << setw(12) << (_a + _h * i) 
			<< setw(12) << _v[0][i];

		for (int j = 1; j < _v.size(); j++)
			cout << setw(12) << _v[j][i] 
				<< setw(10) << fabs(_v[0][i] - _v[j][i]);

		cout << endl;
	}
}

int LengthOfInt(int n) {
	int i = 0;
	
	if (n < 0) {
		n *= -1;
		i++;
	}

	while (n > 0) {
		n /= 10;
		i++;
	}

	return i;
}