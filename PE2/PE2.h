#ifndef _PE2_H_
#define _PE2_H_
#include <vector>

typedef double mathFunc(double x);
class PE2
{
private: 
	double _a;
	double _b;
	double _h;
	int _n;

	std::vector<double*> _v;

public:

	inline void Reset() { _v.clear(); }

	PE2(double a, double b, int n) {
		if (a > b) {
			double temp = a;
			a = b;
			b = temp;
		}
		
		_a = a;
		_b = b;
		_n = n;

		_h = (b - a) / (n - 1);
	}

	double* CalculateOnASpan(mathFunc func);
	inline void CalculateOnASpanAndStore(mathFunc func) { _v.push_back(CalculateOnASpan(func)); }

	void Parse(double** arrayToParse);
	void ProperParse();
};

#endif