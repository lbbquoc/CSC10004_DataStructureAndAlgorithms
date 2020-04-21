#include "Header.h"
#include<iostream>
#include <queue>
#include <algorithm>

using namespace std;

NODE* CreateNode(int data)
{
	NODE* p = new NODE;
	p->key = data;
	p->p_left = p->p_right = NULL;
	p->height = 1;

	return p;
}
int Height(NODE* p_root)
{
	int count_left;
	int count_right;
	if (p_root == NULL)
		return 0;
	else
	{
		count_left = Height(p_root->p_left);
		count_right = Height(p_root->p_right);
		if (count_left > count_right)
			return count_left + 1;
		else
		{
			return count_right + 1;
		}
	}
}
void Right_Rotate(NODE*& root)
{
	NODE* temp = root->p_left->p_right;
	root->p_left->p_right = root;
	root = root->p_left;

	root->p_right->p_left = temp;

	root->height = max(Height(root->p_left), Height(root->p_right)) + 1;
	root->p_right->height = max(Height(root->p_right->p_left), Height(root->p_right->p_right)) + 1;

}

void Left_Rotate(NODE*& root)
{
	
		NODE* temp = root->p_right->p_left;

		root->p_right->p_left = root;
		root = root->p_right;

		root->p_left->p_right = temp;

		root->height = max(Height(root->p_left), Height(root->p_right)) + 1;
		root->p_left->height = max(Height(root->p_left->p_left), Height(root->p_left->p_right)) + 1;
	
}

void Check_Balance(NODE*& p_root)
{
	int balance = Height(p_root->p_right) - Height(p_root->p_left);
	if (balance <= -2)
	{
		if (Height(p_root->p_left->p_left) < Height(p_root->p_left->p_right))
		{
			Left_Rotate(p_root->p_left);
			Right_Rotate(p_root);
		}
		else
		{
			Right_Rotate(p_root);
		}
	}
	else if (balance >= 2)
	{
		if (Height(p_root->p_right->p_left) > Height(p_root->p_right->p_right))
		{
			Right_Rotate(p_root->p_right);
			Left_Rotate(p_root);
		}
		else
		{
			Left_Rotate(p_root);
		}
	}
}

void Insert(NODE*& p_root, int x)
{
	if (p_root == NULL)
	{
		p_root = CreateNode(x);
	}
	else
	{
		if (x < p_root->key)
		{
			Insert(p_root->p_left, x);
		}
		else if (x > p_root->key)
		{
			Insert(p_root->p_right, x);
		}
		else
		{
			cout << "\nDupplicate !!!\n";
		}
		Check_Balance(p_root);
	}
}

void find_leftes_node(NODE*& X, NODE*& Y)
{
	if (Y->p_left != NULL)
		return find_leftes_node(X, Y->p_left);
	else
	{
		X->key = Y->key;
		X = Y;
		Y = Y->p_right;
	}
}

void Remove(NODE*& p_root, int x)
{
	Check_Balance(p_root);
	if (p_root == NULL)
	{
		return;
	}
	else
	{
		if (x < p_root->key)
		{
			Remove(p_root->p_left, x);
		}
		else if (x > p_root->key)
		{
			Remove(p_root->p_right, x);
		}
		else
		{
			NODE* temp = p_root;
			if (p_root->p_left == NULL)
			{
				p_root = p_root->p_right;
			}
			else if (p_root->p_right == NULL)
			{
				p_root = p_root->p_left;
			}
			else
			{
				find_leftes_node(temp, p_root->p_right);
			}
			delete temp;
		}
		
	}	
}

void NLR(NODE* p_root)
{
	if (p_root != NULL)
	{
		cout << p_root->key << "  ";
		NLR(p_root->p_left);
		NLR(p_root->p_right);
	}
}

void LNR(NODE* p_root)
{
	if (p_root != NULL)
	{
		LNR(p_root->p_left);
		cout << p_root->key << " ";
		LNR(p_root->p_right);
	}
}

void LRN(NODE* p_root)
{
	if (p_root!=NULL)
	{
		LRN(p_root->p_left);
		LRN(p_root->p_right);
		cout << p_root->key << " ";
	}
}

void LevelOrder(NODE* p_root)
{
	queue<NODE*> Q;
	if (p_root == NULL)
		return;
	else
	{
		Q.push(p_root);
		while (!Q.empty())
		{
			NODE* current = Q.front();
			cout << current->key << " ";
			if (current->p_left != NULL)
			{
				Q.push(current->p_left);
			}
			if (current->p_right != NULL)
			{
				Q.push(current->p_right);
			}
			Q.pop();
		}
	}
}

bool IsAVL(NODE* p_root)
{
	if (p_root == NULL)
	{
		return true;
	}
	else
	{
		if (abs(Height(p_root->p_left) - Height(p_root->p_right)) >= 2)
			return false;
		else
		{
			return true;
		}
	}

	return false;
}