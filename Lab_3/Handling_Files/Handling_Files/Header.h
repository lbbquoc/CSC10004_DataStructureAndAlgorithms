#pragma once
#include <string>
#include<vector>

struct Examinee
{
	string id;
	float math, literture, physic, chemistry, biology, history, geography, civic_education, natural_science, social_science, foreign_language;

};

Examinee ReadExaminee(string line_info);

vector<Examinee> ReadExamineeList(string file_name);

void WriteSumOfScore(vector<Examinee> examinee_list, string out_file_name);

