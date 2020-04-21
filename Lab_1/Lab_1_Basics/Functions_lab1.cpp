#include <iostream>
#include <time.h>
#include <cstdlib>
#include <math.h>
#include <array>
#include <algorithm>
using namespace std;

#include "Lab1.h"

void InputArray(int*& a, int& n)
{	
	//srand(time(NULL));
	a = new int[n];
	for (int i = 0; i < n; i++)
	{
		cout << "a[" << i << "] = ";
		cin >> a[i];
		cout << endl;
		//a[i] = rand() % 100 + 50 ;
	}
}

void DellocateArray(int*& a)
{
	delete[] a;
}

void PrintArray(int* a, int n)
{
	for (int i = 0; i < n; i++)	
	{

		cout <<"a[" << i << "] = " << a[i];
		cout << endl;
	}
	
}

int FindMin(int* a, int n)
{
	int min = a[0];
	for (int i = 1; i < n; i++)
	{
		if (a[i] < min)
			min = a[i];
	}

	return min;
}

int FindMaxMudulus(int* a, int n)
{
	int max = abs(a[0]);
	for (int i = 0; i < n; i++)
	{
		if (abs(a[i]) > max)
			max = abs(a[i]);
	}
	return max;
}

bool IsAscending(int* a, int n)
{
	int dem = 0;
	for (int i = 0; i < n - 1; i++)
	{
		if (a[i + 1] >= a[i]) dem++;
	}
	if (dem == n - 1) return true;
	else return false;
}

int SumOfArray(int* a, int n)
{
	int sum = 0;
	for (int i = 0; i < n; i++)
	{
		sum += a[i];
	}

	return sum;
}

// kiếm tra số đó có phải số nguyên tố không ! 
int check_prime(int x)
{
	if (x < 2)
		return 0;
	for (int i = 2; i < sqrt(x); i++)
	{
		if (x % i == 0)
			return 0;
	}

	return 1;
}

int CountPrime(int* a, int n)
{
	int count = 0;
	for (int i = 0; i < n; i++)
	{
		if (check_prime(a[i]) == 1)
			count++;
	}

	return count;
}

int* ReverseArray(int*& a, int *b, int n)
{
	
	for (int i = 0; i < n; i++)
	{
		b[i] = a[n - i - 1];
	}

	return b;
}

int LinearSearch(int* a, int n, int key)
{
	

	for (int i = 0; i < n; i++)
	{
		if (a[i] == key)
			return i;
	}

	return -1;
}

int SentinelLinearSearch(int* a, int n, int key)
{
	
	int last = arr[n - 1];

	
	arr[n - 1] = key;
	int i = 0;

	while (arr[i] != key)
		i++;

	 
	arr[n - 1] = last;

	if ((i < n - 1) || (key == arr[n - 1]))
		return i;
	else
		return -1;
	
		
}

// sap xep mang : 
void sort_array(int* a, int n)
{
	int temp;
	for (int i = 0; i < n; i++)
	{
		for (int j = 1; j < n - 1; j++)
		{
			if (a[i] > a[j])
			{
				temp = a[i];
				a[i] = a[j];
				a[j] = temp;
			}
		}
	}
}
int BinarySearch(int* a, int n, int key) // only use ascending
{
	int l = 0, r = n - 1;
	int mid;
	
	
		while (l <= r)
		{
			mid = (l + r) / 2;
			if (a[mid] == key)
			{
				return mid;
			}
			else if (a[mid] > key)
			{
				r = mid - 1;
			}
			else if (a[mid] < key)
			{
				l = mid + 1;
			}
		}
	
	
	return 0;
}

int RecursiveBinarySearch(int* a, int left, int right, int key)
{
	int mid = (left + right) / 2;
	
		if (a[mid] == key) return mid;
		else if (a[mid] < key) return RecursiveBinarySearch(a, mid + 1, right, key);
		else if (a[mid] > key) return RecursiveBinarySearch(a, left, mid - 1, key);
	
		return 0;
	
}

// ----------------------------------- recursion --------------------------
