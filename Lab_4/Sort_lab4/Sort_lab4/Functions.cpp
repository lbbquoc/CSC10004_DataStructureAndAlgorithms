#include <iostream>
#include <string>
#include <algorithm>
#include <array>
#include <fstream>
#include <cmath>
#include <time.h>
using namespace std;


#include "Header.h"



// Hàm phát sinh mảng dữ liệu ngẫu nhiên
void GenerateRandomData(int a[], int n)
{
	srand((unsigned int)time(NULL));

	for (int i = 0; i < n; i++)
	{
		a[i] = rand() % n;
	}
}

// Hàm phát sinh mảng dữ liệu có thứ tự tăng dần
void GenerateSortedData(int a[], int n)
{
	for (int i = 0; i < n; i++)
	{
		a[i] = i;
	}
}

// Hàm phát sinh mảng dữ liệu có thứ tự ngược (giảm dần)
void GenerateReverseData(int a[], int n)
{
	for (int i = 0; i < n; i++)
	{
		a[i] = n - 1 - i;
	}
}

// Hàm phát sinh mảng dữ liệu gần như có thứ tự
void GenerateNearlySortedData(int a[], int n)
{
	for (int i = 0; i < n; i++)
	{
		a[i] = i;
	}
	srand((unsigned int)time(NULL));
	for (int i = 0; i < 10; i++)
	{
		int r1 = rand() % n;
		int r2 = rand() % n;
		swap(a[r1], a[r2]);
	}
}

void GenerateData(int a[], int n, int dataType)
{
	switch (dataType)
	{
	case 0:	// ngẫu nhiên
		GenerateRandomData(a, n);
		break;
	case 1:	// có thứ tự
		GenerateSortedData(a, n);
		break;
	case 2:	// có thứ tự ngược
		GenerateReverseData(a, n);
		break;
	case 3:	// gần như có thứ tự
		GenerateNearlySortedData(a, n);
		break;
	default:
		printf("Error: unknown data type!\n");
	}
}




void print_Array(int* a, int n)
{
	for (int i = 0; i < n; i++)
	{
		cout << a[i] << "  ";
	}
}

void Input_Array(int* a, int n)
{
	for (int i = 0; i < n; i++)
	{
		cout << "a[" << i << "] = "; 
		cin >> a[i];
	}
}

//// selection - sort // Selection_Sort
void swap(int* xp, int* yp)
{
	int temp = *xp;
	*xp = *yp;
	*yp = temp;
}
void Selection_Sort(int* arr, int n)
{
	int i, j, min_idx;

	
	for (i = 0; i < n - 1; i++)
	{
		
		min_idx = i;
		for (j = i + 1; j < n; j++)
			if (arr[j] < arr[min_idx])
				min_idx = j;

	
		swap(&arr[min_idx], &arr[i]);
	}
}
//// heap - sort
void heap_Rebuild(int pos, int* a, int n)
{
	int  k = pos;
	int v = a[k];
	bool  IsHeap = false;

	while (!IsHeap && 2*k+1 < n)
	{
		int j = 2 * k + 1;
		if (j < n - 1)
		{
			if (a[j] < a[j + 1])
				j = j + 1;
		}
		if (v >= a[j])
		{
			IsHeap = true;
		}
		else
		{
			swap(a[k], a[j]);
			k = j;
		}
	}
}

void Heap_Construction(int* a, int n)
{
	int start = (n - 1) / 2;
	while (start >= 0)
	{
		heap_Rebuild(start, a, n);
		start = start - 1;
	}
}

void Heap_Sort(int* a, int n)
{
	Heap_Construction(a, n);
	int r = n - 1;
	while (r > 0)
	{
		swap(a[0], a[r]);
		heap_Rebuild(0, a, r);
		r = r - 1;
	}
	//print_Array(a, n);
}

void merge(int *arr, int l, int m, int r)
{
	 int i, j, k;
	 int n1 = m - l + 1;
	 int n2 = r - m;

	/* create temp arrays */
	int* L = new int[n1];
	int* R = new int[n2];

	/* Copy data to temp arrays L[] and R[] */
	for (i = 0; i < n1; i++)
		L[i] = arr[l + i];
	for (j = 0; j < n2; j++)
		R[j] = arr[m + 1 + j];

	/* Merge the temp arrays back into arr[l..r]*/
	i = 0; // Initial index of first subarray 
	j = 0; // Initial index of second subarray 
	k = l; // Initial index of merged subarray 
	while (i < n1 && j < n2)
	{
		if (L[i] <= R[j])
		{
			arr[k] = L[i];
			i++;
		}
		else
		{
			arr[k] = R[j];
			j++;
		}
		k++;
	}

	/* Copy the remaining elements of L[], if there
	   are any */
	while (i < n1)
	{
		arr[k] = L[i];
		i++;
		k++;
	}

	/* Copy the remaining elements of R[], if there
	   are any */
	while (j < n2)
	{
		arr[k] = R[j];
		j++;
		k++;
	}
}

void mergeSort(int *arr, int l, int r)
{
	if (l < r)
	{
		// Same as (l+r)/2, but avoids overflow for 
		// large l and h 
		int m = l + (r - l) / 2;

		// Sort first and second halves 
		mergeSort(arr, l, m);
		mergeSort(arr, m + 1, r);

		merge(arr, l, m, r);
	}
	
}

void quickSort(int *a, int left_index, int right_index)
{
	int left, right, pivot;
	if (left_index >= right_index) return;

	left = left_index;
	right = right_index;

	// pivot selection
	pivot = a[(left_index + right_index) / 2];

	// partition
	while (left <= right) {
		while (a[left] < pivot) left++;
		while (a[right] > pivot) right--;
		if (left <= right) {
			swap(a[left], a[right]);
			left++; right--;
		}
		
	}

	// recursion
	quickSort(a, left_index, right);
	quickSort(a, left, right_index);
}


void bubbleSort(int *arr, int n)
{
	int i, j;
	for (i = 0; i < n - 1; i++)

	
		for (j = 0; j < n - i - 1; j++)
			if (arr[j] > arr[j + 1])
				swap(arr[j], arr[j + 1]);
}

void insertionSort(int* a, int n)
{
	for (int i = 0; i < n; i++)
	{
		int j = i - 1;
		int temp = a[i];
		while (temp < a[j] && j >= 0)
		{
			a[j + 1] = a[j];
			j--;
		}
		a[j + 1] = temp;
	}
}


int getMax(int *arr, int n)
{
	int mx = arr[0];
	for (int i = 1; i < n; i++)
		if (arr[i] > mx)
			mx = arr[i];
	return mx;
}

// A function to do counting sort of arr[] according to 
// the digit represented by exp. 
void countSort(int *arr, int n, int exp)
{
	int* output = new int[n];// output array 
	int i, count[10] = { 0 };

	// Store count of occurrences in count[] 
	for (i = 0; i < n; i++)
		count[(arr[i] / exp) % 10]++;

	// Change count[i] so that count[i] now contains actual 
	//  position of this digit in output[] 
	for (i = 1; i < 10; i++)
		count[i] += count[i - 1];

	// Build the output array 
	for (i = n - 1; i >= 0; i--)
	{
		output[count[(arr[i] / exp) % 10] - 1] = arr[i];
		count[(arr[i] / exp) % 10]--;
	}

	// Copy the output array to arr[], so that arr[] now 
	// contains sorted numbers according to current digit 
	for (i = 0; i < n; i++)
		arr[i] = output[i];
}

// The main function to that sorts arr[] of size n using  
// Radix Sort 
void radixSort(int *arr, int n)
{
	// Find the maximum number to know number of digits 
	int m = getMax(arr, n);

	// Do counting sort for every digit. Note that instead 
	// of passing digit number, exp is passed. exp is 10^i 
	// where i is current digit number 
	for (int exp = 1; m / exp > 0; exp *= 10)
		countSort(arr, n, exp);
}



// khi muốn kết quả thời gian thì nhập số lượng phần tử, out_put_name ( dùng để lưu kết quả dạng csv ), option(1 trong 4 kiểu dữ liệu)
void Write_time_data(int* a, int numbers_of_array,string out_put_name,int option)
{
	int count = 0;
	// khởi tạo file
	fstream out_put;
	out_put.open(out_put_name,ios::app);

	// khởi tạo biến thời gian
	clock_t start, end;
	double time_use;
	
		if (option == 0)
		{
			out_put << "Random,";
			out_put << numbers_of_array << ",";
		}
		else if (option == 1)
		{
			out_put << "Sorted,";
			out_put << numbers_of_array << ",";
		}
		else if (option == 2)
		{
			out_put << "Reverse,";
			out_put << numbers_of_array << ",";
		}
		else if (option == 3)
		{
			out_put << "NearlySorted,";
			out_put << numbers_of_array << ",";
		}
		
		for (int j = 0; j < 7; j++)
		{
			count++;
			if (count == 1)
			{

				start = clock();
				Selection_Sort(a, numbers_of_array);
				end = clock();
				time_use = (double)(end - start) / CLOCKS_PER_SEC;
				out_put << time_use << ",";
			}
			if (count == 2)
			{
				start = clock();
				Heap_Sort(a, numbers_of_array);
				end = clock();
				time_use = (double)(end - start) / CLOCKS_PER_SEC;
				out_put << time_use << ",";
			}
			if (count == 3)
			{
				start = clock();
				mergeSort(a, 0, numbers_of_array - 1);
				end = clock();
				time_use = (double)(end - start) / CLOCKS_PER_SEC;
				out_put << time_use << ",";

			}
			if (count == 4)
			{
				//a = new int[numbers_of_array];
				start = clock();
				quickSort(a, 0, numbers_of_array - 1);
				end = clock();
				time_use = (double)(end - start) / CLOCKS_PER_SEC;
				out_put << time_use << ",";
			}
			if (count == 5)
			{
				start = clock();
				bubbleSort(a, numbers_of_array);
				end = clock();
				time_use = (double)(end - start) / CLOCKS_PER_SEC;
				out_put << time_use << ",";
			}
			if (count == 6)
			{
				start = clock();
				insertionSort(a, numbers_of_array);
				end = clock();
				time_use = (double)(end - start) / CLOCKS_PER_SEC;
				out_put << time_use << ",";

			}
			if (count == 7)
			{
				start = clock();
				radixSort(a, numbers_of_array);
				end = clock();
				time_use = (double)(end - start) / CLOCKS_PER_SEC;
				out_put << time_use << "," << endl;


				// đưa biến đếm về lại 0
				count = 0;
			}
		}
	

	out_put.close();
}


// khi muốn in kết quả file nào thì chỉ cần nhập số lượng phần tử, option (1 trong 4 kiểu dữ liệu), type : tên thuật toán sort 
void Write_State(int* a, int numbers_of_array, int option, string type)
{
	fstream out_put;
	//a = new int[numbers_of_array];

	if (option == 0)
	{
		
			if (numbers_of_array == 1000)
			{
				if (type == "selection")
				{
					out_put.open("SelectionSort_random_1000.txt", ios::out);
					GenerateData(a, numbers_of_array, 0);
					Selection_Sort(a, numbers_of_array);
					for (int i = 0; i < numbers_of_array; i++)
					{
						out_put << a[i] << " ";
					}
				}
				if (type == "heap")
				{
					out_put.open("HeapSort_random_1000.txt", ios::out);
					GenerateData(a, numbers_of_array, 0);
					Heap_Sort(a, numbers_of_array);
					for (int i = 0; i < numbers_of_array; i++)
					{
						out_put << a[i] << " ";
					}
				}
				if (type == "merge")
				{
					out_put.open("MergeSort_random_1000.txt", ios::out);
					GenerateData(a, numbers_of_array, 0);
					mergeSort(a, 0, numbers_of_array - 1);
					for (int i = 0; i < numbers_of_array; i++)
					{
						out_put << a[i] << " ";
					}
				}
				if (type == "quick")
				{

					out_put.open("QuickSort_random_1000.txt", ios::out);
					GenerateData(a, numbers_of_array, 0);
					quickSort(a, 0, numbers_of_array - 1);

					for (int i = 0; i < numbers_of_array; i++)
					{
						out_put << a[i] << " ";
					}
				}
				if (type == "bubble")
				{
					out_put.open("BubbleSort_random_1000.txt", ios::out);
					GenerateData(a, numbers_of_array, 0);
					bubbleSort(a, numbers_of_array);
					for (int i = 0; i < numbers_of_array; i++)
					{
						out_put << a[i] << " ";
					}
				}
				if (type == "insertion")
				{
					out_put.open("InsertionSort_random_1000.txt", ios::out);
					GenerateData(a, numbers_of_array, 0);
					insertionSort(a, numbers_of_array);
					for (int i = 0; i < numbers_of_array; i++)
					{
						out_put << a[i] << " ";
					}
				}
				if (type == "radix")
				{
					out_put.open("RadixSort_random_1000.txt", ios::out);
					GenerateData(a, numbers_of_array, 0);
					radixSort(a, numbers_of_array);
					for (int i = 0; i < numbers_of_array; i++)
					{
						out_put << a[i] << " ";
					}
				}
			}
			if (numbers_of_array == 3000)
			{
				if (type == "selection")
				{
					out_put.open("SelectionSort_random_3000.txt", ios::out);
					GenerateData(a, numbers_of_array, 0);
					Selection_Sort(a, numbers_of_array);
					for (int i = 0; i < numbers_of_array; i++)
					{
						out_put << a[i] << " ";
					}
				}
				if (type == "heap")
				{
					out_put.open("HeapSort_random_3000.txt", ios::out);
					GenerateData(a, numbers_of_array, 0);
					Heap_Sort(a, numbers_of_array);
					for (int i = 0; i < numbers_of_array; i++)
					{
						out_put << a[i] << " ";
					}
				}
				if (type == "merge")
				{
					out_put.open("MergeSort_random_3000.txt", ios::out);
					GenerateData(a, numbers_of_array, 0);
					mergeSort(a, 0, numbers_of_array - 1);
					for (int i = 0; i < numbers_of_array; i++)
					{
						out_put << a[i] << " ";
					}
				}
				if (type == "quick")
				{
					out_put.open("QuickSort_random_3000.txt", ios::out);
					GenerateData(a, numbers_of_array, 0);
					quickSort(a, 0, numbers_of_array - 1);
					for (int i = 0; i < numbers_of_array; i++)
					{
						out_put << a[i] << " ";
					}
				}
				if (type == "bubble")
				{
					out_put.open("BubbleSort_random_3000.txt", ios::out);
					GenerateData(a, numbers_of_array, 0);
					bubbleSort(a, numbers_of_array);
					for (int i = 0; i < numbers_of_array; i++)
					{
						out_put << a[i] << " ";
					}
				}
				if (type == "insertion")
				{
					out_put.open("InsertionSort_random_3000.txt", ios::out);
					GenerateData(a, numbers_of_array, 0);
					insertionSort(a, numbers_of_array);
					for (int i = 0; i < numbers_of_array; i++)
					{
						out_put << a[i] << " ";
					}
				}
				if (type == "radix")
				{
					out_put.open("RadixSort_random_3000.txt", ios::out);
					GenerateData(a, numbers_of_array, 0);
					radixSort(a, numbers_of_array);
					for (int i = 0; i < numbers_of_array; i++)
					{
						out_put << a[i] << " ";
					}
				}
			}
			if (numbers_of_array == 30000)
			{
				if (type == "selection")
				{
					out_put.open("SelectionSort_random_30000.txt", ios::out);
					GenerateData(a, numbers_of_array, 0);
					Selection_Sort(a, numbers_of_array);
					for (int i = 0; i < numbers_of_array; i++)
					{
						out_put << a[i] << " ";
					}
				}
				if (type == "heap")
				{
					out_put.open("HeapSort_random_30000.txt", ios::out);
					GenerateData(a, numbers_of_array, 0);
					Heap_Sort(a, numbers_of_array);
					for (int i = 0; i < numbers_of_array; i++)
					{
						out_put << a[i] << " ";
					}
				}
				if (type == "merge")
				{
					out_put.open("MergeSort_random_30000.txt", ios::out);
					GenerateData(a, numbers_of_array, 0);
					mergeSort(a, 0, numbers_of_array - 1);
					for (int i = 0; i < numbers_of_array; i++)
					{
						out_put << a[i] << " ";
					}
				}
				if (type == "quick")
				{
					out_put.open("QuickSort_random_30000.txt", ios::out);
					GenerateData(a, numbers_of_array, 0);
					quickSort(a, 0, numbers_of_array - 1);
					for (int i = 0; i < numbers_of_array; i++)
					{
						out_put << a[i] << " ";
					}
				}
				if (type == "bubble")
				{
					out_put.open("BubbleSort_random_30000.txt", ios::out);
					GenerateData(a, numbers_of_array, 0);
					bubbleSort(a, numbers_of_array);
					for (int i = 0; i < numbers_of_array; i++)
					{
						out_put << a[i] << " ";
					}
				}
				if (type == "insertion")
				{
					out_put.open("InsertionSort_random_30000.txt", ios::out);
					GenerateData(a, numbers_of_array, 0);
					insertionSort(a, numbers_of_array);
					for (int i = 0; i < numbers_of_array; i++)
					{
						out_put << a[i] << " ";
					}
				}
				if (type == "radix")
				{
					out_put.open("RadixSort_random_30000.txt", ios::out);
					GenerateData(a, numbers_of_array, 0);
					radixSort(a, numbers_of_array);
					for (int i = 0; i < numbers_of_array; i++)
					{
						out_put << a[i] << " ";
					}
				}
			}
			if (numbers_of_array == 10000)
			{
				if (type == "selection")
				{
					out_put.open("SelectionSort_random_10000.txt", ios::out);
					GenerateData(a, numbers_of_array, 0);
					Selection_Sort(a, numbers_of_array);
					for (int i = 0; i < numbers_of_array; i++)
					{
						out_put << a[i] << " ";
					}
				}
				if (type == "heap")
				{
					out_put.open("HeapSort_random_10000.txt", ios::out);
					GenerateData(a, numbers_of_array, 0);
					Heap_Sort(a, numbers_of_array);
					for (int i = 0; i < numbers_of_array; i++)
					{
						out_put << a[i] << " ";
					}
				}
				if (type == "merge")
				{
					out_put.open("MergeSort_random_10000.txt", ios::out);
					GenerateData(a, numbers_of_array, 0);
					mergeSort(a, 0, numbers_of_array - 1);
					for (int i = 0; i < numbers_of_array; i++)
					{
						out_put << a[i] << " ";
					}
				}
				if (type == "quick")
				{
					out_put.open("QuickSort_random_10000.txt", ios::out);
					GenerateData(a, numbers_of_array, 0);
					quickSort(a, 0, numbers_of_array - 1);
					for (int i = 0; i < numbers_of_array; i++)
					{
						out_put << a[i] << " ";
					}
				}
				if (type == "bubble")
				{
					out_put.open("BubbleSort_random_10000.txt", ios::out);
					GenerateData(a, numbers_of_array, 0);
					bubbleSort(a, numbers_of_array);
					for (int i = 0; i < numbers_of_array; i++)
					{
						out_put << a[i] << " ";
					}
				}
				if (type == "insertion")
				{
					out_put.open("InsertionSort_random_10000.txt", ios::out);
					GenerateData(a, numbers_of_array, 0);
					insertionSort(a, numbers_of_array);
					for (int i = 0; i < numbers_of_array; i++)
					{
						out_put << a[i] << " ";
					}
				}
				if (type == "radix")
				{
					out_put.open("RadixSort_random_10000.txt", ios::out);
					GenerateData(a, numbers_of_array, 0);
					radixSort(a, numbers_of_array);
					for (int i = 0; i < numbers_of_array; i++)
					{
						out_put << a[i] << " ";
					}
				}
			}
			if (numbers_of_array == 100000)
			{
				if (type == "selection")
				{
					out_put.open("SelectionSort_random_100000.txt", ios::out);
					GenerateData(a, numbers_of_array, 0);
					Selection_Sort(a, numbers_of_array);
					for (int i = 0; i < numbers_of_array; i++)
					{
						out_put << a[i] << " ";
					}
				}
				if (type == "heap")
				{
					out_put.open("HeapSort_random_100000.txt", ios::out);
					GenerateData(a, numbers_of_array, 0);
					Heap_Sort(a, numbers_of_array);
					for (int i = 0; i < numbers_of_array; i++)
					{
						out_put << a[i] << " ";
					}
				}
				if (type == "merge")
				{
					out_put.open("MergeSort_random_100000.txt", ios::out);
					GenerateData(a, numbers_of_array, 0);
					mergeSort(a, 0, numbers_of_array - 1);
					for (int i = 0; i < numbers_of_array; i++)
					{
						out_put << a[i] << " ";
					}
				}
				if (type == "quick")
				{
					out_put.open("QuickSort_random_100000.txt", ios::out);
					GenerateData(a, numbers_of_array, 0);
					quickSort(a, 0, numbers_of_array - 1);
					for (int i = 0; i < numbers_of_array; i++)
					{
						out_put << a[i] << " ";
					}
				}
				if (type == "bubble")
				{
					out_put.open("BubbleSort_random_100000.txt", ios::out);
					GenerateData(a, numbers_of_array, 0);
					bubbleSort(a, numbers_of_array);
					for (int i = 0; i < numbers_of_array; i++)
					{
						out_put << a[i] << " ";
					}
				}
				if (type == "insertion")
				{
					out_put.open("InsertionSort_random_100000.txt", ios::out);
					GenerateData(a, numbers_of_array, 0);
					insertionSort(a, numbers_of_array);
					for (int i = 0; i < numbers_of_array; i++)
					{
						out_put << a[i] << " ";
					}
				}
				if (type == "radix")
				{
					out_put.open("RadixSort_random_100000.txt", ios::out);
					GenerateData(a, numbers_of_array, 0);
					radixSort(a, numbers_of_array);
					for (int i = 0; i < numbers_of_array; i++)
					{
						out_put << a[i] << " ";
					}
				}
			}
		
	}
	if (option == 1)
	{

		if (numbers_of_array == 1000)
		{
			if (type == "selection")
			{
				out_put.open("SelectionSort_random_1000.txt", ios::out);
				GenerateData(a, numbers_of_array, 0);
				Selection_Sort(a, numbers_of_array);
				for (int i = 0; i < numbers_of_array; i++)
				{
					out_put << a[i] << " ";
				}
			}
			if (type == "heap")
			{
				out_put.open("HeapSort_random_1000.txt", ios::out);
				GenerateData(a, numbers_of_array, 0);
				Heap_Sort(a, numbers_of_array);
				for (int i = 0; i < numbers_of_array; i++)
				{
					out_put << a[i] << " ";
				}
			}
			if (type == "merge")
			{
				out_put.open("MergeSort_random_1000.txt", ios::out);
				GenerateData(a, numbers_of_array, 0);
				mergeSort(a, 0, numbers_of_array - 1);
				for (int i = 0; i < numbers_of_array; i++)
				{
					out_put << a[i] << " ";
				}
			}
			if (type == "quick")
			{

				out_put.open("QuickSort_random_1000.txt", ios::out);
				GenerateData(a, numbers_of_array, 0);
				quickSort(a, 0, numbers_of_array - 1);

				for (int i = 0; i < numbers_of_array; i++)
				{
					out_put << a[i] << " ";
				}
			}
			if (type == "bubble")
			{
				out_put.open("BubbleSort_random_1000.txt", ios::out);
				GenerateData(a, numbers_of_array, 0);
				bubbleSort(a, numbers_of_array);
				for (int i = 0; i < numbers_of_array; i++)
				{
					out_put << a[i] << " ";
				}
			}
			if (type == "insertion")
			{
				out_put.open("InsertionSort_random_1000.txt", ios::out);
				GenerateData(a, numbers_of_array, 0);
				insertionSort(a, numbers_of_array);
				for (int i = 0; i < numbers_of_array; i++)
				{
					out_put << a[i] << " ";
				}
			}
			if (type == "radix")
			{
				out_put.open("RadixSort_random_1000.txt", ios::out);
				GenerateData(a, numbers_of_array, 0);
				radixSort(a, numbers_of_array);
				for (int i = 0; i < numbers_of_array; i++)
				{
					out_put << a[i] << " ";
				}
			}
		}
		if (numbers_of_array == 3000)
		{
			if (type == "selection")
			{
				out_put.open("SelectionSort_random_3000.txt", ios::out);
				GenerateData(a, numbers_of_array, 0);
				Selection_Sort(a, numbers_of_array);
				for (int i = 0; i < numbers_of_array; i++)
				{
					out_put << a[i] << " ";
				}
			}
			if (type == "heap")
			{
				out_put.open("HeapSort_random_3000.txt", ios::out);
				GenerateData(a, numbers_of_array, 0);
				Heap_Sort(a, numbers_of_array);
				for (int i = 0; i < numbers_of_array; i++)
				{
					out_put << a[i] << " ";
				}
			}
			if (type == "merge")
			{
				out_put.open("MergeSort_random_3000.txt", ios::out);
				GenerateData(a, numbers_of_array, 0);
				mergeSort(a, 0, numbers_of_array - 1);
				for (int i = 0; i < numbers_of_array; i++)
				{
					out_put << a[i] << " ";
				}
			}
			if (type == "quick")
			{
				out_put.open("QuickSort_random_3000.txt", ios::out);
				GenerateData(a, numbers_of_array, 0);
				quickSort(a, 0, numbers_of_array - 1);
				for (int i = 0; i < numbers_of_array; i++)
				{
					out_put << a[i] << " ";
				}
			}
			if (type == "bubble")
			{
				out_put.open("BubbleSort_random_3000.txt", ios::out);
				GenerateData(a, numbers_of_array, 0);
				bubbleSort(a, numbers_of_array);
				for (int i = 0; i < numbers_of_array; i++)
				{
					out_put << a[i] << " ";
				}
			}
			if (type == "insertion")
			{
				out_put.open("InsertionSort_random_3000.txt", ios::out);
				GenerateData(a, numbers_of_array, 0);
				insertionSort(a, numbers_of_array);
				for (int i = 0; i < numbers_of_array; i++)
				{
					out_put << a[i] << " ";
				}
			}
			if (type == "radix")
			{
				out_put.open("RadixSort_random_3000.txt", ios::out);
				GenerateData(a, numbers_of_array, 0);
				radixSort(a, numbers_of_array);
				for (int i = 0; i < numbers_of_array; i++)
				{
					out_put << a[i] << " ";
				}
			}
		}
		if (numbers_of_array == 30000)
		{
			if (type == "selection")
			{
				out_put.open("SelectionSort_random_30000.txt", ios::out);
				GenerateData(a, numbers_of_array, 0);
				Selection_Sort(a, numbers_of_array);
				for (int i = 0; i < numbers_of_array; i++)
				{
					out_put << a[i] << " ";
				}
			}
			if (type == "heap")
			{
				out_put.open("HeapSort_random_30000.txt", ios::out);
				GenerateData(a, numbers_of_array, 0);
				Heap_Sort(a, numbers_of_array);
				for (int i = 0; i < numbers_of_array; i++)
				{
					out_put << a[i] << " ";
				}
			}
			if (type == "merge")
			{
				out_put.open("MergeSort_random_30000.txt", ios::out);
				GenerateData(a, numbers_of_array, 0);
				mergeSort(a, 0, numbers_of_array - 1);
				for (int i = 0; i < numbers_of_array; i++)
				{
					out_put << a[i] << " ";
				}
			}
			if (type == "quick")
			{
				out_put.open("QuickSort_random_30000.txt", ios::out);
				GenerateData(a, numbers_of_array, 0);
				quickSort(a, 0, numbers_of_array - 1);
				for (int i = 0; i < numbers_of_array; i++)
				{
					out_put << a[i] << " ";
				}
			}
			if (type == "bubble")
			{
				out_put.open("BubbleSort_random_30000.txt", ios::out);
				GenerateData(a, numbers_of_array, 0);
				bubbleSort(a, numbers_of_array);
				for (int i = 0; i < numbers_of_array; i++)
				{
					out_put << a[i] << " ";
				}
			}
			if (type == "insertion")
			{
				out_put.open("InsertionSort_random_30000.txt", ios::out);
				GenerateData(a, numbers_of_array, 0);
				insertionSort(a, numbers_of_array);
				for (int i = 0; i < numbers_of_array; i++)
				{
					out_put << a[i] << " ";
				}
			}
			if (type == "radix")
			{
				out_put.open("RadixSort_random_30000.txt", ios::out);
				GenerateData(a, numbers_of_array, 0);
				radixSort(a, numbers_of_array);
				for (int i = 0; i < numbers_of_array; i++)
				{
					out_put << a[i] << " ";
				}
			}
		}
		if (numbers_of_array == 10000)
		{
			if (type == "selection")
			{
				out_put.open("SelectionSort_random_10000.txt", ios::out);
				GenerateData(a, numbers_of_array, 0);
				Selection_Sort(a, numbers_of_array);
				for (int i = 0; i < numbers_of_array; i++)
				{
					out_put << a[i] << " ";
				}
			}
			if (type == "heap")
			{
				out_put.open("HeapSort_random_10000.txt", ios::out);
				GenerateData(a, numbers_of_array, 0);
				Heap_Sort(a, numbers_of_array);
				for (int i = 0; i < numbers_of_array; i++)
				{
					out_put << a[i] << " ";
				}
			}
			if (type == "merge")
			{
				out_put.open("MergeSort_random_10000.txt", ios::out);
				GenerateData(a, numbers_of_array, 0);
				mergeSort(a, 0, numbers_of_array - 1);
				for (int i = 0; i < numbers_of_array; i++)
				{
					out_put << a[i] << " ";
				}
			}
			if (type == "quick")
			{
				out_put.open("QuickSort_random_10000.txt", ios::out);
				GenerateData(a, numbers_of_array, 0);
				quickSort(a, 0, numbers_of_array - 1);
				for (int i = 0; i < numbers_of_array; i++)
				{
					out_put << a[i] << " ";
				}
			}
			if (type == "bubble")
			{
				out_put.open("BubbleSort_random_10000.txt", ios::out);
				GenerateData(a, numbers_of_array, 0);
				bubbleSort(a, numbers_of_array);
				for (int i = 0; i < numbers_of_array; i++)
				{
					out_put << a[i] << " ";
				}
			}
			if (type == "insertion")
			{
				out_put.open("InsertionSort_random_10000.txt", ios::out);
				GenerateData(a, numbers_of_array, 0);
				insertionSort(a, numbers_of_array);
				for (int i = 0; i < numbers_of_array; i++)
				{
					out_put << a[i] << " ";
				}
			}
			if (type == "radix")
			{
				out_put.open("RadixSort_random_10000.txt", ios::out);
				GenerateData(a, numbers_of_array, 0);
				radixSort(a, numbers_of_array);
				for (int i = 0; i < numbers_of_array; i++)
				{
					out_put << a[i] << " ";
				}
			}
		}
		if (numbers_of_array == 100000)
		{
			if (type == "selection")
			{
				out_put.open("SelectionSort_random_100000.txt", ios::out);
				GenerateData(a, numbers_of_array, 0);
				Selection_Sort(a, numbers_of_array);
				for (int i = 0; i < numbers_of_array; i++)
				{
					out_put << a[i] << " ";
				}
			}
			if (type == "heap")
			{
				out_put.open("HeapSort_random_100000.txt", ios::out);
				GenerateData(a, numbers_of_array, 0);
				Heap_Sort(a, numbers_of_array);
				for (int i = 0; i < numbers_of_array; i++)
				{
					out_put << a[i] << " ";
				}
			}
			if (type == "merge")
			{
				out_put.open("MergeSort_random_100000.txt", ios::out);
				GenerateData(a, numbers_of_array, 0);
				mergeSort(a, 0, numbers_of_array - 1);
				for (int i = 0; i < numbers_of_array; i++)
				{
					out_put << a[i] << " ";
				}
			}
			if (type == "quick")
			{
				out_put.open("QuickSort_random_100000.txt", ios::out);
				GenerateData(a, numbers_of_array, 0);
				quickSort(a, 0, numbers_of_array - 1);
				for (int i = 0; i < numbers_of_array; i++)
				{
					out_put << a[i] << " ";
				}
			}
			if (type == "bubble")
			{
				out_put.open("BubbleSort_random_100000.txt", ios::out);
				GenerateData(a, numbers_of_array, 0);
				bubbleSort(a, numbers_of_array);
				for (int i = 0; i < numbers_of_array; i++)
				{
					out_put << a[i] << " ";
				}
			}
			if (type == "insertion")
			{
				out_put.open("InsertionSort_random_100000.txt", ios::out);
				GenerateData(a, numbers_of_array, 0);
				insertionSort(a, numbers_of_array);
				for (int i = 0; i < numbers_of_array; i++)
				{
					out_put << a[i] << " ";
				}
			}
			if (type == "radix")
			{
				out_put.open("RadixSort_random_100000.txt", ios::out);
				GenerateData(a, numbers_of_array, 0);
				radixSort(a, numbers_of_array);
				for (int i = 0; i < numbers_of_array; i++)
				{
					out_put << a[i] << " ";
				}
			}
		}

	}
	if (option == 2)
	{

		if (numbers_of_array == 1000)
		{
			if (type == "selection")
			{
				out_put.open("SelectionSort_random_1000.txt", ios::out);
				GenerateData(a, numbers_of_array, 0);
				Selection_Sort(a, numbers_of_array);
				for (int i = 0; i < numbers_of_array; i++)
				{
					out_put << a[i] << " ";
				}
			}
			if (type == "heap")
			{
				out_put.open("HeapSort_random_1000.txt", ios::out);
				GenerateData(a, numbers_of_array, 0);
				Heap_Sort(a, numbers_of_array);
				for (int i = 0; i < numbers_of_array; i++)
				{
					out_put << a[i] << " ";
				}
			}
			if (type == "merge")
			{
				out_put.open("MergeSort_random_1000.txt", ios::out);
				GenerateData(a, numbers_of_array, 0);
				mergeSort(a, 0, numbers_of_array - 1);
				for (int i = 0; i < numbers_of_array; i++)
				{
					out_put << a[i] << " ";
				}
			}
			if (type == "quick")
			{

				out_put.open("QuickSort_random_1000.txt", ios::out);
				GenerateData(a, numbers_of_array, 0);
				quickSort(a, 0, numbers_of_array - 1);

				for (int i = 0; i < numbers_of_array; i++)
				{
					out_put << a[i] << " ";
				}
			}
			if (type == "bubble")
			{
				out_put.open("BubbleSort_random_1000.txt", ios::out);
				GenerateData(a, numbers_of_array, 0);
				bubbleSort(a, numbers_of_array);
				for (int i = 0; i < numbers_of_array; i++)
				{
					out_put << a[i] << " ";
				}
			}
			if (type == "insertion")
			{
				out_put.open("InsertionSort_random_1000.txt", ios::out);
				GenerateData(a, numbers_of_array, 0);
				insertionSort(a, numbers_of_array);
				for (int i = 0; i < numbers_of_array; i++)
				{
					out_put << a[i] << " ";
				}
			}
			if (type == "radix")
			{
				out_put.open("RadixSort_random_1000.txt", ios::out);
				GenerateData(a, numbers_of_array, 0);
				radixSort(a, numbers_of_array);
				for (int i = 0; i < numbers_of_array; i++)
				{
					out_put << a[i] << " ";
				}
			}
		}
		if (numbers_of_array == 3000)
		{
			if (type == "selection")
			{
				out_put.open("SelectionSort_random_3000.txt", ios::out);
				GenerateData(a, numbers_of_array, 0);
				Selection_Sort(a, numbers_of_array);
				for (int i = 0; i < numbers_of_array; i++)
				{
					out_put << a[i] << " ";
				}
			}
			if (type == "heap")
			{
				out_put.open("HeapSort_random_3000.txt", ios::out);
				GenerateData(a, numbers_of_array, 0);
				Heap_Sort(a, numbers_of_array);
				for (int i = 0; i < numbers_of_array; i++)
				{
					out_put << a[i] << " ";
				}
			}
			if (type == "merge")
			{
				out_put.open("MergeSort_random_3000.txt", ios::out);
				GenerateData(a, numbers_of_array, 0);
				mergeSort(a, 0, numbers_of_array - 1);
				for (int i = 0; i < numbers_of_array; i++)
				{
					out_put << a[i] << " ";
				}
			}
			if (type == "quick")
			{
				out_put.open("QuickSort_random_3000.txt", ios::out);
				GenerateData(a, numbers_of_array, 0);
				quickSort(a, 0, numbers_of_array - 1);
				for (int i = 0; i < numbers_of_array; i++)
				{
					out_put << a[i] << " ";
				}
			}
			if (type == "bubble")
			{
				out_put.open("BubbleSort_random_3000.txt", ios::out);
				GenerateData(a, numbers_of_array, 0);
				bubbleSort(a, numbers_of_array);
				for (int i = 0; i < numbers_of_array; i++)
				{
					out_put << a[i] << " ";
				}
			}
			if (type == "insertion")
			{
				out_put.open("InsertionSort_random_3000.txt", ios::out);
				GenerateData(a, numbers_of_array, 0);
				insertionSort(a, numbers_of_array);
				for (int i = 0; i < numbers_of_array; i++)
				{
					out_put << a[i] << " ";
				}
			}
			if (type == "radix")
			{
				out_put.open("RadixSort_random_3000.txt", ios::out);
				GenerateData(a, numbers_of_array, 0);
				radixSort(a, numbers_of_array);
				for (int i = 0; i < numbers_of_array; i++)
				{
					out_put << a[i] << " ";
				}
			}
		}
		if (numbers_of_array == 30000)
		{
			if (type == "selection")
			{
				out_put.open("SelectionSort_random_30000.txt", ios::out);
				GenerateData(a, numbers_of_array, 0);
				Selection_Sort(a, numbers_of_array);
				for (int i = 0; i < numbers_of_array; i++)
				{
					out_put << a[i] << " ";
				}
			}
			if (type == "heap")
			{
				out_put.open("HeapSort_random_30000.txt", ios::out);
				GenerateData(a, numbers_of_array, 0);
				Heap_Sort(a, numbers_of_array);
				for (int i = 0; i < numbers_of_array; i++)
				{
					out_put << a[i] << " ";
				}
			}
			if (type == "merge")
			{
				out_put.open("MergeSort_random_30000.txt", ios::out);
				GenerateData(a, numbers_of_array, 0);
				mergeSort(a, 0, numbers_of_array - 1);
				for (int i = 0; i < numbers_of_array; i++)
				{
					out_put << a[i] << " ";
				}
			}
			if (type == "quick")
			{
				out_put.open("QuickSort_random_30000.txt", ios::out);
				GenerateData(a, numbers_of_array, 0);
				quickSort(a, 0, numbers_of_array - 1);
				for (int i = 0; i < numbers_of_array; i++)
				{
					out_put << a[i] << " ";
				}
			}
			if (type == "bubble")
			{
				out_put.open("BubbleSort_random_30000.txt", ios::out);
				GenerateData(a, numbers_of_array, 0);
				bubbleSort(a, numbers_of_array);
				for (int i = 0; i < numbers_of_array; i++)
				{
					out_put << a[i] << " ";
				}
			}
			if (type == "insertion")
			{
				out_put.open("InsertionSort_random_30000.txt", ios::out);
				GenerateData(a, numbers_of_array, 0);
				insertionSort(a, numbers_of_array);
				for (int i = 0; i < numbers_of_array; i++)
				{
					out_put << a[i] << " ";
				}
			}
			if (type == "radix")
			{
				out_put.open("RadixSort_random_30000.txt", ios::out);
				GenerateData(a, numbers_of_array, 0);
				radixSort(a, numbers_of_array);
				for (int i = 0; i < numbers_of_array; i++)
				{
					out_put << a[i] << " ";
				}
			}
		}
		if (numbers_of_array == 10000)
		{
			if (type == "selection")
			{
				out_put.open("SelectionSort_random_10000.txt", ios::out);
				GenerateData(a, numbers_of_array, 0);
				Selection_Sort(a, numbers_of_array);
				for (int i = 0; i < numbers_of_array; i++)
				{
					out_put << a[i] << " ";
				}
			}
			if (type == "heap")
			{
				out_put.open("HeapSort_random_10000.txt", ios::out);
				GenerateData(a, numbers_of_array, 0);
				Heap_Sort(a, numbers_of_array);
				for (int i = 0; i < numbers_of_array; i++)
				{
					out_put << a[i] << " ";
				}
			}
			if (type == "merge")
			{
				out_put.open("MergeSort_random_10000.txt", ios::out);
				GenerateData(a, numbers_of_array, 0);
				mergeSort(a, 0, numbers_of_array - 1);
				for (int i = 0; i < numbers_of_array; i++)
				{
					out_put << a[i] << " ";
				}
			}
			if (type == "quick")
			{
				out_put.open("QuickSort_random_10000.txt", ios::out);
				GenerateData(a, numbers_of_array, 0);
				quickSort(a, 0, numbers_of_array - 1);
				for (int i = 0; i < numbers_of_array; i++)
				{
					out_put << a[i] << " ";
				}
			}
			if (type == "bubble")
			{
				out_put.open("BubbleSort_random_10000.txt", ios::out);
				GenerateData(a, numbers_of_array, 0);
				bubbleSort(a, numbers_of_array);
				for (int i = 0; i < numbers_of_array; i++)
				{
					out_put << a[i] << " ";
				}
			}
			if (type == "insertion")
			{
				out_put.open("InsertionSort_random_10000.txt", ios::out);
				GenerateData(a, numbers_of_array, 0);
				insertionSort(a, numbers_of_array);
				for (int i = 0; i < numbers_of_array; i++)
				{
					out_put << a[i] << " ";
				}
			}
			if (type == "radix")
			{
				out_put.open("RadixSort_random_10000.txt", ios::out);
				GenerateData(a, numbers_of_array, 0);
				radixSort(a, numbers_of_array);
				for (int i = 0; i < numbers_of_array; i++)
				{
					out_put << a[i] << " ";
				}
			}
		}
		if (numbers_of_array == 100000)
		{
			if (type == "selection")
			{
				out_put.open("SelectionSort_random_100000.txt", ios::out);
				GenerateData(a, numbers_of_array, 0);
				Selection_Sort(a, numbers_of_array);
				for (int i = 0; i < numbers_of_array; i++)
				{
					out_put << a[i] << " ";
				}
			}
			if (type == "heap")
			{
				out_put.open("HeapSort_random_100000.txt", ios::out);
				GenerateData(a, numbers_of_array, 0);
				Heap_Sort(a, numbers_of_array);
				for (int i = 0; i < numbers_of_array; i++)
				{
					out_put << a[i] << " ";
				}
			}
			if (type == "merge")
			{
				out_put.open("MergeSort_random_100000.txt", ios::out);
				GenerateData(a, numbers_of_array, 0);
				mergeSort(a, 0, numbers_of_array - 1);
				for (int i = 0; i < numbers_of_array; i++)
				{
					out_put << a[i] << " ";
				}
			}
			if (type == "quick")
			{
				out_put.open("QuickSort_random_100000.txt", ios::out);
				GenerateData(a, numbers_of_array, 0);
				quickSort(a, 0, numbers_of_array - 1);
				for (int i = 0; i < numbers_of_array; i++)
				{
					out_put << a[i] << " ";
				}
			}
			if (type == "bubble")
			{
				out_put.open("BubbleSort_random_100000.txt", ios::out);
				GenerateData(a, numbers_of_array, 0);
				bubbleSort(a, numbers_of_array);
				for (int i = 0; i < numbers_of_array; i++)
				{
					out_put << a[i] << " ";
				}
			}
			if (type == "insertion")
			{
				out_put.open("InsertionSort_random_100000.txt", ios::out);
				GenerateData(a, numbers_of_array, 0);
				insertionSort(a, numbers_of_array);
				for (int i = 0; i < numbers_of_array; i++)
				{
					out_put << a[i] << " ";
				}
			}
			if (type == "radix")
			{
				out_put.open("RadixSort_random_100000.txt", ios::out);
				GenerateData(a, numbers_of_array, 0);
				radixSort(a, numbers_of_array);
				for (int i = 0; i < numbers_of_array; i++)
				{
					out_put << a[i] << " ";
				}
			}
		}

	}
	if (option == 3)
	{

		if (numbers_of_array == 1000)
		{
			if (type == "selection")
			{
				out_put.open("SelectionSort_random_1000.txt", ios::out);
				GenerateData(a, numbers_of_array, 0);
				Selection_Sort(a, numbers_of_array);
				for (int i = 0; i < numbers_of_array; i++)
				{
					out_put << a[i] << " ";
				}
			}
			if (type == "heap")
			{
				out_put.open("HeapSort_random_1000.txt", ios::out);
				GenerateData(a, numbers_of_array, 0);
				Heap_Sort(a, numbers_of_array);
				for (int i = 0; i < numbers_of_array; i++)
				{
					out_put << a[i] << " ";
				}
			}
			if (type == "merge")
			{
				out_put.open("MergeSort_random_1000.txt", ios::out);
				GenerateData(a, numbers_of_array, 0);
				mergeSort(a, 0, numbers_of_array - 1);
				for (int i = 0; i < numbers_of_array; i++)
				{
					out_put << a[i] << " ";
				}
			}
			if (type == "quick")
			{

				out_put.open("QuickSort_random_1000.txt", ios::out);
				GenerateData(a, numbers_of_array, 0);
				quickSort(a, 0, numbers_of_array - 1);

				for (int i = 0; i < numbers_of_array; i++)
				{
					out_put << a[i] << " ";
				}
			}
			if (type == "bubble")
			{
				out_put.open("BubbleSort_random_1000.txt", ios::out);
				GenerateData(a, numbers_of_array, 0);
				bubbleSort(a, numbers_of_array);
				for (int i = 0; i < numbers_of_array; i++)
				{
					out_put << a[i] << " ";
				}
			}
			if (type == "insertion")
			{
				out_put.open("InsertionSort_random_1000.txt", ios::out);
				GenerateData(a, numbers_of_array, 0);
				insertionSort(a, numbers_of_array);
				for (int i = 0; i < numbers_of_array; i++)
				{
					out_put << a[i] << " ";
				}
			}
			if (type == "radix")
			{
				out_put.open("RadixSort_random_1000.txt", ios::out);
				GenerateData(a, numbers_of_array, 0);
				radixSort(a, numbers_of_array);
				for (int i = 0; i < numbers_of_array; i++)
				{
					out_put << a[i] << " ";
				}
			}
		}
		if (numbers_of_array == 3000)
		{
			if (type == "selection")
			{
				out_put.open("SelectionSort_random_3000.txt", ios::out);
				GenerateData(a, numbers_of_array, 0);
				Selection_Sort(a, numbers_of_array);
				for (int i = 0; i < numbers_of_array; i++)
				{
					out_put << a[i] << " ";
				}
			}
			if (type == "heap")
			{
				out_put.open("HeapSort_random_3000.txt", ios::out);
				GenerateData(a, numbers_of_array, 0);
				Heap_Sort(a, numbers_of_array);
				for (int i = 0; i < numbers_of_array; i++)
				{
					out_put << a[i] << " ";
				}
			}
			if (type == "merge")
			{
				out_put.open("MergeSort_random_3000.txt", ios::out);
				GenerateData(a, numbers_of_array, 0);
				mergeSort(a, 0, numbers_of_array - 1);
				for (int i = 0; i < numbers_of_array; i++)
				{
					out_put << a[i] << " ";
				}
			}
			if (type == "quick")
			{
				out_put.open("QuickSort_random_3000.txt", ios::out);
				GenerateData(a, numbers_of_array, 0);
				quickSort(a, 0, numbers_of_array - 1);
				for (int i = 0; i < numbers_of_array; i++)
				{
					out_put << a[i] << " ";
				}
			}
			if (type == "bubble")
			{
				out_put.open("BubbleSort_random_3000.txt", ios::out);
				GenerateData(a, numbers_of_array, 0);
				bubbleSort(a, numbers_of_array);
				for (int i = 0; i < numbers_of_array; i++)
				{
					out_put << a[i] << " ";
				}
			}
			if (type == "insertion")
			{
				out_put.open("InsertionSort_random_3000.txt", ios::out);
				GenerateData(a, numbers_of_array, 0);
				insertionSort(a, numbers_of_array);
				for (int i = 0; i < numbers_of_array; i++)
				{
					out_put << a[i] << " ";
				}
			}
			if (type == "radix")
			{
				out_put.open("RadixSort_random_3000.txt", ios::out);
				GenerateData(a, numbers_of_array, 0);
				radixSort(a, numbers_of_array);
				for (int i = 0; i < numbers_of_array; i++)
				{
					out_put << a[i] << " ";
				}
			}
		}
		if (numbers_of_array == 30000)
		{
			if (type == "selection")
			{
				out_put.open("SelectionSort_random_30000.txt", ios::out);
				GenerateData(a, numbers_of_array, 0);
				Selection_Sort(a, numbers_of_array);
				for (int i = 0; i < numbers_of_array; i++)
				{
					out_put << a[i] << " ";
				}
			}
			if (type == "heap")
			{
				out_put.open("HeapSort_random_30000.txt", ios::out);
				GenerateData(a, numbers_of_array, 0);
				Heap_Sort(a, numbers_of_array);
				for (int i = 0; i < numbers_of_array; i++)
				{
					out_put << a[i] << " ";
				}
			}
			if (type == "merge")
			{
				out_put.open("MergeSort_random_30000.txt", ios::out);
				GenerateData(a, numbers_of_array, 0);
				mergeSort(a, 0, numbers_of_array - 1);
				for (int i = 0; i < numbers_of_array; i++)
				{
					out_put << a[i] << " ";
				}
			}
			if (type == "quick")
			{
				out_put.open("QuickSort_random_30000.txt", ios::out);
				GenerateData(a, numbers_of_array, 0);
				quickSort(a, 0, numbers_of_array - 1);
				for (int i = 0; i < numbers_of_array; i++)
				{
					out_put << a[i] << " ";
				}
			}
			if (type == "bubble")
			{
				out_put.open("BubbleSort_random_30000.txt", ios::out);
				GenerateData(a, numbers_of_array, 0);
				bubbleSort(a, numbers_of_array);
				for (int i = 0; i < numbers_of_array; i++)
				{
					out_put << a[i] << " ";
				}
			}
			if (type == "insertion")
			{
				out_put.open("InsertionSort_random_30000.txt", ios::out);
				GenerateData(a, numbers_of_array, 0);
				insertionSort(a, numbers_of_array);
				for (int i = 0; i < numbers_of_array; i++)
				{
					out_put << a[i] << " ";
				}
			}
			if (type == "radix")
			{
				out_put.open("RadixSort_random_30000.txt", ios::out);
				GenerateData(a, numbers_of_array, 0);
				radixSort(a, numbers_of_array);
				for (int i = 0; i < numbers_of_array; i++)
				{
					out_put << a[i] << " ";
				}
			}
		}
		if (numbers_of_array == 10000)
		{
			if (type == "selection")
			{
				out_put.open("SelectionSort_random_10000.txt", ios::out);
				GenerateData(a, numbers_of_array, 0);
				Selection_Sort(a, numbers_of_array);
				for (int i = 0; i < numbers_of_array; i++)
				{
					out_put << a[i] << " ";
				}
			}
			if (type == "heap")
			{
				out_put.open("HeapSort_random_10000.txt", ios::out);
				GenerateData(a, numbers_of_array, 0);
				Heap_Sort(a, numbers_of_array);
				for (int i = 0; i < numbers_of_array; i++)
				{
					out_put << a[i] << " ";
				}
			}
			if (type == "merge")
			{
				out_put.open("MergeSort_random_10000.txt", ios::out);
				GenerateData(a, numbers_of_array, 0);
				mergeSort(a, 0, numbers_of_array - 1);
				for (int i = 0; i < numbers_of_array; i++)
				{
					out_put << a[i] << " ";
				}
			}
			if (type == "quick")
			{
				out_put.open("QuickSort_random_10000.txt", ios::out);
				GenerateData(a, numbers_of_array, 0);
				quickSort(a, 0, numbers_of_array - 1);
				for (int i = 0; i < numbers_of_array; i++)
				{
					out_put << a[i] << " ";
				}
			}
			if (type == "bubble")
			{
				out_put.open("BubbleSort_random_10000.txt", ios::out);
				GenerateData(a, numbers_of_array, 0);
				bubbleSort(a, numbers_of_array);
				for (int i = 0; i < numbers_of_array; i++)
				{
					out_put << a[i] << " ";
				}
			}
			if (type == "insertion")
			{
				out_put.open("InsertionSort_random_10000.txt", ios::out);
				GenerateData(a, numbers_of_array, 0);
				insertionSort(a, numbers_of_array);
				for (int i = 0; i < numbers_of_array; i++)
				{
					out_put << a[i] << " ";
				}
			}
			if (type == "radix")
			{
				out_put.open("RadixSort_random_10000.txt", ios::out);
				GenerateData(a, numbers_of_array, 0);
				radixSort(a, numbers_of_array);
				for (int i = 0; i < numbers_of_array; i++)
				{
					out_put << a[i] << " ";
				}
			}
		}
		if (numbers_of_array == 100000)
		{
			if (type == "selection")
			{
				out_put.open("SelectionSort_random_100000.txt", ios::out);
				GenerateData(a, numbers_of_array, 0);
				Selection_Sort(a, numbers_of_array);
				for (int i = 0; i < numbers_of_array; i++)
				{
					out_put << a[i] << " ";
				}
			}
			if (type == "heap")
			{
				out_put.open("HeapSort_random_100000.txt", ios::out);
				GenerateData(a, numbers_of_array, 0);
				Heap_Sort(a, numbers_of_array);
				for (int i = 0; i < numbers_of_array; i++)
				{
					out_put << a[i] << " ";
				}
			}
			if (type == "merge")
			{
				out_put.open("MergeSort_random_100000.txt", ios::out);
				GenerateData(a, numbers_of_array, 0);
				mergeSort(a, 0, numbers_of_array - 1);
				for (int i = 0; i < numbers_of_array; i++)
				{
					out_put << a[i] << " ";
				}
			}
			if (type == "quick")
			{
				out_put.open("QuickSort_random_100000.txt", ios::out);
				GenerateData(a, numbers_of_array, 0);
				quickSort(a, 0, numbers_of_array - 1);
				for (int i = 0; i < numbers_of_array; i++)
				{
					out_put << a[i] << " ";
				}
			}
			if (type == "bubble")
			{
				out_put.open("BubbleSort_random_100000.txt", ios::out);
				GenerateData(a, numbers_of_array, 0);
				bubbleSort(a, numbers_of_array);
				for (int i = 0; i < numbers_of_array; i++)
				{
					out_put << a[i] << " ";
				}
			}
			if (type == "insertion")
			{
				out_put.open("InsertionSort_random_100000.txt", ios::out);
				GenerateData(a, numbers_of_array, 0);
				insertionSort(a, numbers_of_array);
				for (int i = 0; i < numbers_of_array; i++)
				{
					out_put << a[i] << " ";
				}
			}
			if (type == "radix")
			{
				out_put.open("RadixSort_random_100000.txt", ios::out);
				GenerateData(a, numbers_of_array, 0);
				radixSort(a, numbers_of_array);
				for (int i = 0; i < numbers_of_array; i++)
				{
					out_put << a[i] << " ";
				}
			}
		}

	}
	out_put.close();

}

