#include <iostream>
using namespace std;

#include "Header.h"

int main()
{
	List *l=new List;
	CreateList(*l);
	int n_of_list;
	cout << " Enter the numbers of List: ";
	cin >> n_of_list;
	for (int i = 0; i < n_of_list; i++)
	{
		int value;
		cout << "Enter the value of integer: ";
		cin >> value;

		NODE* p = CreateNode(value);
		AddTail(l, value);
		//AddHead(l, value);
		
	}
	//RemoveHead(l);
	//RemoveTail(l);
	//RemoveAll(l);
	/*ReverseList(l);
	cout << " the number of element : " << CountElements(l) <<endl;*/

	int key_remove;
	//cout << " enter the key which you wanna remove : ";
	//cin >> key_remove;
	//RemoveElement(l, key_remove);
	//RemoveDuplicate(l);
	RemoveDuplicate(l);

	cout << "\n\n\t The list of Linked List :  ";
	PrintList(l);
	system("pause");
	return 0;

}