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









int main()
{

	string out_put_name;
	cout << "Enter the out put name : " << endl;
	cin >> out_put_name;
	// khởi tạo file
	fstream out_put;
	out_put.open(out_put_name, ios::app);

	// số lượng phần tử
	int numbers_of_array;
	string line_info = "Input State,Input Size,Selection,Heap,Merge,Quick,Bubble,Insertion,Radix ";
	out_put << line_info << endl;

		

	





	// ------- TIME TO SORT ----------- //
		// random state
	
	int* a;



			a = new int[1000];
			GenerateData(a, 1000, 0);
			Write_time_data(a, 1000, out_put_name, 0);
			delete[]a;

			a = new int[3000];
			GenerateData(a, 3000, 0);
			Write_time_data(a, 3000, out_put_name, 0);
			delete[]a;

			a = new int[10000];
			GenerateData(a, 10000, 0);
			Write_time_data(a, 10000, out_put_name, 0);
			delete[]a;

			a = new int[30000];
			GenerateData(a, 30000, 0);
			Write_time_data(a, 30000, out_put_name, 0);
			delete[]a;

			a = new int[100000];
			GenerateData(a, 100000, 0);
			Write_time_data(a, 100000, out_put_name, 0);
			delete[]a;


			// sorted data
			a = new int[1000];
			GenerateData(a, 1000, 1);
			Write_time_data(a, 1000, out_put_name, 1);
			delete[]a;

			a = new int[3000];
			GenerateData(a, 3000, 1);
			Write_time_data(a, 3000, out_put_name, 1);
			delete[]a;

			a = new int[10000];
			GenerateData(a, 10000, 1);
			Write_time_data(a, 10000, out_put_name, 1);
			delete[]a;

			a = new int[30000];
			GenerateData(a, 30000, 1);
			Write_time_data(a, 30000, out_put_name, 1);
			delete[]a;

			a = new int[100000];
			GenerateData(a, 100000, 1);
			Write_time_data(a, 100000, out_put_name, 1);
			delete[]a;


			// reverse data

			a = new int[1000];
			GenerateData(a, 1000, 2);
			Write_time_data(a, 1000, out_put_name, 2);
			delete[]a;

			a = new int[3000];
			GenerateData(a, 3000, 2);
			Write_time_data(a, 3000, out_put_name, 2);
			delete[]a;

			a = new int[10000];
			GenerateData(a, 10000, 2);
			Write_time_data(a, 10000, out_put_name, 2);
			delete[]a;

			a = new int[30000];
			GenerateData(a, 30000, 2);
			Write_time_data(a, 30000, out_put_name, 2);
			delete[]a;

			a = new int[100000];
			GenerateData(a, 100000, 2);
			Write_time_data(a, 100000, out_put_name, 2);
			delete[]a;

			//nearly sorted 

			a = new int[1000];
			GenerateData(a, 1000, 3);
			Write_time_data(a, 1000, out_put_name, 3);
			delete[]a;

			a = new int[3000];
			GenerateData(a, 3000, 3);
			Write_time_data(a, 3000, out_put_name, 3);
			delete[]a;

			a = new int[10000];
			GenerateData(a, 10000, 3);
			Write_time_data(a, 10000, out_put_name, 3);
			delete[]a;

			a = new int[30000];
			GenerateData(a, 30000, 3);
			Write_time_data(a, 30000, out_put_name, 3);
			delete[]a;

			a = new int[100000];
			GenerateData(a, 100000, 3);
			Write_time_data(a, 100000, out_put_name, 3);
			delete[]a;


		out_put.close();
		system("pause");

		return 0;
	
}


		



	
	
	
	
	
