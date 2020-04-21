#include <iostream>
#include "Header.h"
using namespace std;

int main()
{
	NODE* tree = NULL;

	int x;
	cout << "enter x ultill (x = 0) - then stop: " << endl;
	cin >> x;

	if (x == 0)
	{
		cout << "invalid !" << endl;
		return 0;
	}
	Insert(tree, x);
	while (true)
	{
		cout << "enter x until (x = 0) - then stop: " << endl;
		cin >> x;
		if (x == 0) break;
		Insert(tree, x);
	}
	NLR(tree);

	int x_remove;
	cout << "enter the node which you wanna remove : " << endl;
	cin >> x_remove;
	Remove(tree, x_remove);

	NLR(tree);
	
}