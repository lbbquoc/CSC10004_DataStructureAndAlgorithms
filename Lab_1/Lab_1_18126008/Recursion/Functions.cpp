
#include <iostream>
int SumOfSquares(int n)
{
	if (n == 1) return n;
		
	return SumOfSquares(n - 1) + pow(n, 2) ;
}

int GCD(int a, int b)
{
	if (b==0) return a;
	
	return GCD(b, a % b);

}

int FIB(int n)
{
	if (n == 1) return 1;
	if (n == 2) return 1;

	return FIB(n - 1) + FIB(n - 2);
}
