#include "Header.h"
#include<iostream>
#include <vector>
#include<string>
#include <fstream>
using namespace std;
void print(string line)
{
	cout << ReadCompany(line).name << endl;
	cout << ReadCompany(line).profit_tax << endl;
	cout << ReadCompany(line).address << endl;
}
int main()
{
	string file_name;
	cout << "enter file_name :" << endl;
	cin >> file_name;
	Company* hash_table = new Company;
	hash_table = CreateHashTable(ReadCompanyList(file_name));

	
	

	// đang xử lí tràn số 
}



