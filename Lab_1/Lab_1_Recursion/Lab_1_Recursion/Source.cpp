#include <iostream>

using	namespace std;

#include "Lab1_recursion.h"


int main()
{
	int n;
	cout << "Enter the value of n  : ";
	cin >> n;
	cout << "sum of squares = " << SumOfSquares(n) << endl;

	// GCD 

	int a, b;
	cout << "Enter value of a: ";
	cin >> a;
	cout << "Enter value of b: ";
	cin >> b;

	cout << " the greatest common divisor of " << a << " and " << b << " is : " << GCD(a, b) << endl;

	cout << " Fibonacci with " << n << " is : " << FIB(n) <<endl;

	system("pause");

	return 0;
}