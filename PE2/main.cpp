#include "PE2.h"
#include <math.h>
#include <iostream>
#include <iomanip>
#define EPSILON 0.00001
#define MAX_DEPTH 5000
#define MAX_RECURSIVE_DEPTH 20
#define PI 3.141592653589793

double Iterative(double x);
double Mathfunc(double x);
double Recursive(double x);
double Recursive(double x, double power, int depth);

int main() {
	double* arrayOfSets[3];

	PE2 testCase(-0.99, 0.99, 21);

	/*arrayOfSets[0] = testCase.CalculateOnASpan(Mathfunc);
	arrayOfSets[1] = testCase.CalculateOnASpan(Iterative);
	arrayOfSets[2] = testCase.CalculateOnASpan(Recursive);

	testCase.Parse(arrayOfSets);*/

	testCase.CalculateOnASpanAndStore(Mathfunc);
	testCase.CalculateOnASpanAndStore(Iterative);
	testCase.CalculateOnASpanAndStore(Recursive);

	testCase.ProperParse();

	return 0;
}

double Iterative(double x) {
	
	int i = 1;

	double result = PI / 2;
	double power = -x;

	double desiredResult = Mathfunc(x);

	while (i < MAX_DEPTH && fabs(result - desiredResult) > EPSILON) {
		result += power / (i * 2 - 1);
		power *= -x * x;

		i++;
	}
	
	return result;
}

double Mathfunc(double x) {
	return PI / 2 - atan(x);
}

double Recursive(double x) {
	return PI / 2 - x + Recursive(x, x, 1);
}

double Recursive(double x, double element, int depth) {
	element *= x * x;
	
	if(depth < MAX_RECURSIVE_DEPTH)
		return element / (depth * 2 - 1) - Recursive(x, element, ++depth);

	return element / (depth * 2 - 1);
}