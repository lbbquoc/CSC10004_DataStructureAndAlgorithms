#pragma once
#include <string>
#include <vector>
#include <iostream>
using namespace std;

struct Company
{
	string name;
	string profit_tax;
	string address;
};
Company ReadCompany(string line_info);
vector<Company> ReadCompanyList(string file_name);

long long HashString(string company_name);
Company* CreateHashTable(vector<Company> list_company);
void Insert(Company* hash_table, Company company);
Company* Search(Company* hash_table, string company_name);

