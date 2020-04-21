#pragma once
#include <string>
#include <iostream>
#include <fstream>
#include <cmath>
#include <time.h>
#include <string>
#include <stdlib.h>
#include <time.h>
#include <fstream>
#include <string>
#include <vector>
#include "Header.h"
using namespace std;


void GenerateRandomData(int a[], int n);
void GenerateSortedData(int a[], int n);
void GenerateReverseData(int a[], int n);
void GenerateNearlySortedData(int a[], int n);
void GenerateData(int a[], int n, int dataType);


void Input_Array(int* a, int n);
void print_Array(int* a, int n);

void Selection_Sort(int* arr, int n);

void Heap_Sort(int* a, int n);

void mergeSort(int* a, int l, int r);

void quickSort(int* arr, int left_index, int right_index);

void bubbleSort(int* arr, int n);

void insertionSort(int* a, int n);

void radixSort(int* a, int n);

void Write_time_data(int* a, int numbers_of_array, string out_put_name, int option);

void Write_State(int* a, int numbers_of_array, int option, string type);

