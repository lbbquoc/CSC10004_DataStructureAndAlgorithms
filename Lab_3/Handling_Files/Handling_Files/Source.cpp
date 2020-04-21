#include <iostream>
#include <fstream>
#include <string>
#include <vector>
using namespace std;
#include "Header.h"
void Print_info(string line_info) // it use to print each score of suiject 
{
	cout << ReadExaminee(line_info).id << endl;
	cout << ReadExaminee(line_info).math << endl;
	cout << ReadExaminee(line_info).literture << endl;
	cout << ReadExaminee(line_info).physic << endl;
	cout << ReadExaminee(line_info).chemistry << endl;
	cout << ReadExaminee(line_info).biology << endl;
	cout << ReadExaminee(line_info).geography << endl;
	cout << ReadExaminee(line_info).history << endl;
	cout << ReadExaminee(line_info).civic_education << endl;
	cout << ReadExaminee(line_info).natural_science << endl;
	cout << ReadExaminee(line_info).social_science << endl;
	cout << ReadExaminee(line_info).foreign_language << endl;
}
int main()
{
	string file_name;
	cout << "enter the name of file you want to read :" << endl;
	cin >> file_name;

	string line_info;
	
	ifstream file;
	file.open(file_name);
	if (file.fail())
		cout << " failed ! "; 
	else
	{
		
																					//getline(file, line_info);
																					//cout << line_info << endl; // do ban đầu hàm readexaminee  bị lỗi ngay dòng đầu tiên của file text ( dòng đầu mang ký tự đặc biệt )
																					//						  // vậy nên phải đọc cái dòng đó thủ công trước ( lần tiếp theo sẽ được Readexaminee đọc  =>> không lỗi )
																					//
																					//cout << endl;

																					//while (getline(file,line_info))
																					//{
																					//	ReadExaminee(line_info);
																					//	Print_info(line_info); 
																					//	/*cout << line_info << endl;*/
																					//}


		/*cout << "success!" << endl;

		vector <Examinee> list = ReadExamineeList("Text.txt");
		for (int i = 0; i < list.size(); i++)
		{
			cout << list[i].id << "  ";
			cout << list[i].math << "  ";
			cout << list[i].literture << "  ";
			cout << list[i].physic << "  ";
			cout << list[i].chemistry << "  ";
			cout << list[i].biology << "  ";
			cout << list[i].history << "  ";
			cout << list[i].geography << "  ";
			cout << list[i].civic_education << "  ";
			cout << list[i].natural_science << "  ";
			cout << list[i].social_science << "  ";
			cout << list[i].foreign_language << "  ";

			cout << "\n\n";*/

		string out_file_name;
		cout << "Enter the file output which you want to write down : " << endl;
		cin >> out_file_name;

		WriteSumOfScore(ReadExamineeList("Text.txt"), out_file_name);

			

		

	}


	file.close();

	system("pause");
	return 0;

}