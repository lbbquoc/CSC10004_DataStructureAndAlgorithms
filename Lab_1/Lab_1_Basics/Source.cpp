#include <iostream>
#include <time.h>
#include <cstdlib>
using namespace std;
#include "Lab1.h"



int main()
{
	int n;
	cout << "Nhap so luong phan tu :  " << endl;
	cin >> n;
	int* a;
	
	InputArray(a, n);
	PrintArray(a, n);
	cout << "Min is : " << FindMin(a, n) << endl;
	cout << " Max Mudulus is : " << FindMaxMudulus(a, n) << endl;
	cout << "is Array  ascending ?  : " << IsAscending(a, n) << endl;
	cout << "Sum of array is  : " << SumOfArray(a, n) << endl;
	cout << "the number of  prime numbers in the array : " << CountPrime(a, n) << endl;
	

	int* b = new int[n];
	//cout << ReverseArray(a, b, n) << " ";
	
	int* p;
	p = ReverseArray(a, b, n);

	cout << " the new array which is reversed from array a : " << endl;
	for (int i = 0; i < n; i++)
	{
		cout << " the price of element_1_of_b + " << i << " is : " << *(p+i) << endl;
	}

	/*int value_key;
	cout << " enter the value of key :  ";
	cin >> value_key;
	cout << "the index of key is : " << LinearSearch(a, n, value_key) << endl;
	if (IsAscending(a, n))
	{
		cout << "the index of key use flag is : " << SentinelLinearSearch(a, n, value_key) << endl;
		cout << "the index of key use binary search is : " << BinarySearch(a, n, value_key) << endl;
		cout << "the index of key use recursive binary search is : " << RecursiveBinarySearch(a,0,n-1,value_key) << endl;
	}
	else
	{
		cout << "search by binary search is  fails!!!!" << endl;
	}*/
	
	// ------------- recursion ---------------

	
	
	
	
	DellocateArray(a);
	//DellocateArray(b);
	return 0;
	

		
}

