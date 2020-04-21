#include "Header.h"
#include<iostream>
#include <vector>
#include<string>
#include <fstream>
#include <math.h>
using namespace std;

Company ReadCompany(string line_info)
{
	Company cp;

	string element;

	vector<string> list_info;


	for (int i = 0; i < line_info.length(); i++)
	{
		if (line_info[i] != '|')
		{
			element += line_info[i];
		}
		else
		{
			list_info.push_back(element);
			element = "";
		}
	}

	if (list_info.size() == 2)
	{
		list_info.push_back(element);
	}
	cp.name = list_info[0];
	cp.profit_tax = list_info[1];
	cp.address = list_info[2];
	return cp;
}

vector<Company> ReadCompanyList(string file_name)
{
	vector<Company> list;
	string line_info;
	
	fstream file;
	file.open(file_name, ios::in);
	getline(file, line_info);

	while (getline(file,line_info))
	{
		list.push_back(ReadCompany(line_info));
	}

	file.close();

	return list;

}

// xu li tran so 
typedef long long int ll;

// To compute (a * b) % mod 
ll mulmod(ll a, ll b, ll mod)
{
	ll res = 0; // Initialize result 
	a = a % mod;
	while (b > 0)
	{
		// If b is odd, add 'a' to result 
		if (b % 2 == 1)
			res = (res + a) % mod;

		// Multiply 'a' with 2 
		a = (a * 2) % mod;

		// Divide b by 2 
		b /= 2;
	}

	// Return result 
	return res % mod;
}


long long HashString(string company_name)
{
	const long p = 31;
	const long long m = pow(10, 9) + 9;
	long long hash_value = 0;
	
	string lastes_words_20;
	int count = 1; 
	if (company_name.length() <= 20)
	{
		for (int i = 0 ; i < company_name.length() ; i ++ )
		{

			hash_value = hash_value + mulmod(int(company_name[i]),pow(p, i),m);
		}
	}
	else
	{
		for (int i = company_name.length() - 1; i > 0; i--)
		{
			lastes_words_20 += company_name[i];
			count++;
			if (count == 20)
			{
				break;
			}
		}

		for (int i = 0; i < lastes_words_20.length(); i++)
		{
			

			hash_value = hash_value + mulmod(int(lastes_words_20[i]),pow(p, i),m);
		}
		
	}
	
	return hash_value % m ;
}


Company* CreateHashTable(vector<Company> list_company)
{
	Company* hash_table = new Company[2000];
	int hash_size = 2000;
	
	//Search for an unused slot and if the index will exceed the hashTableSize roll back

	for (int i = 0; i < list_company.size(); i++)
	{
		int index = HashString(list_company[i].name) % hash_size;
		int h = 1;
		while (hash_table[index].name != "")
		{
			index = (index + h * h) % hash_size;
			h++;
		}
		hash_table[index] = list_company[i];
	}
	return hash_table;
}

void Insert(Company* hash_table, Company company)
{
	int index = HashString(company.name) % 2000;
	//Search for an unused slot and if the index will exceed the hashTableSize roll back
	int h = 1;
	while (hash_table[index].name != "")
	{
		index = (index + h * h) % 2000;
		h++;
	}
	hash_table[index] = company;
	cout << index;
}
Company* Search(Company* hash_table, string company_name)
{
	Company* ketqua = new Company;
	int i = 0;
	//Compute the index using the Hash Function
	int index = HashString(company_name)%2000;
	//Search for an unused slot and if the index will exceed the hashTableSize roll back
	int h = 1;
	while (hash_table[index].name != company_name and hash_table[index].name != "")
	{
		index = (index + h * h) % 2000;
		h++;
	}
	//Is the element present in the hash table
	if (hash_table[index].name == company_name)
	{
		ketqua[i] = hash_table[index];
		return ketqua;
	}
	else
		return NULL;
}