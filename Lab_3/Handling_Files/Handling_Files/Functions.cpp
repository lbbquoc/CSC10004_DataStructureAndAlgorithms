#include <iostream>
#include <string>
#include <vector>
#include <fstream>
using namespace std;
#include "Header.h"

Examinee ReadExaminee(string line_info)
{
	Examinee ex;

	
	string element;

	vector<string> list_element;
	
	for (int i = 0; i < line_info.length(); i++)
	{
		if (line_info[i] != ',')
			element += line_info[i];
		else
		{
			list_element.push_back(element);
			element = "";
		}
	}


	for (int i = 0; i < 13; i++)
	{
		if (list_element[i] == "")
			list_element[i] = "0";
	}
	
	
	ex.id = list_element[0];

	ex.math = stof(list_element[2]);
	ex.literture = stof(list_element[3]);
	ex.physic = stof(list_element[4]);
	ex.chemistry= stof(list_element[5]);
	ex.biology = stof(list_element[6]);
	ex.history = stof(list_element[7]);
	ex.geography = stof(list_element[8]);

	ex.civic_education = stof(list_element[9]);
	ex.foreign_language = stof(list_element[12]);

	ex.natural_science = (ex.biology + ex.physic + ex.chemistry);
	ex.social_science = (ex.history + ex.geography + ex.civic_education);

	return ex;
}

vector<Examinee> ReadExamineeList(string file_name)
{

	vector<Examinee> list;

	string line_info;
	fstream infile;
	infile.open(file_name, ios::in);

	getline(infile, line_info);
	

	
	while (getline(infile,line_info))
	{
		list.push_back(ReadExaminee(line_info));
		
	}

	infile.close();

	
	return list;
}



void WriteSumOfScore(vector<Examinee> examinee_list, string out_file_name)
{
	string file_in;
	
	ofstream out_file;
	out_file.open(out_file_name);

	float sum;
	for (int i = 0; i < examinee_list.size(); i++)
	{
		sum = examinee_list[i].math + examinee_list[i].literture + examinee_list[i].foreign_language + examinee_list[i].natural_science + examinee_list[i].social_science;
		out_file << examinee_list[i].id << " ";
		out_file << sum << endl;
	}

}
