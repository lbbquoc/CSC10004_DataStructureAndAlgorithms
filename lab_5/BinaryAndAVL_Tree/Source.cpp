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
	cout << endl;
	int height = Height(tree);
	cout << height << endl;

	/*LNR(tree);
	cout << endl;
	LRN(tree);
	cout << endl;*/
	
	/*int key;
	cout << "enter key which u wanna search :" << endl;
	cin >> key;
	if (Search(tree, key) == true)
		cout << " x is existed !" << endl;
	else
	{
		cout << "x is not exist !" << endl;
	}

	NLR(tree);
	cout << endl;
	LNR(tree);
	cout << endl;
	LRN(tree);
	cout << endl;

	cout << "height of tree is : " << Height(tree) << endl;*/

	/*NLR(tree);
	int element_r;
	cout << "enter the element which you want to remove : " << endl;
	cin >> element_r;
	Remove(tree, element_r);
	NLR(tree);*/

	//LevelOrder(tree);
	//cout << "\nThe numbers of node : " << CountNode(tree) << endl;
	/*int p_check_level;
	cout << "enter the node which u wanna check level:" << endl;
	cin >> p_check_level;
	if (Search(tree, p_check_level) == false)
	{
		cout << "node just has entered is no exist !"
		return 0;
	 }
	NODE* p_check = CreateNode(p_check_level);
	
	cout << "\nThe level of node " << p_check->key << " is :" << Level(tree, p_check);*/

//	cout << "the numbers of leaf node is : " << CountLeaf(tree) <<endl;
	/*cout << " enter value u wanna check in function COUNTLESS:" << endl;
	int x_check_less;
	cin >> x_check_less;
	cout << "the numbers element less than " << x_check_less << " is :" <<CountLess(tree, x_check_less) << endl;*/

	//cout << " enter value u wanna check in function COUNTLESS:" << endl;
	//int x_check_greater;
	//cin >> x_check_greater;
	//cout << "the numbers element greater than " << x_check_greater << " is :" << CountGreater(tree, x_check_greater) << endl; 
	/*cout << boolalpha;
	cout << "Is tree: Binary Search Tree?  :  " << IsBST(tree);*/

	return 0;

}

/*
		8
	4		10
   3 5	   9   12
	  6          15
				14  16
						18
*/