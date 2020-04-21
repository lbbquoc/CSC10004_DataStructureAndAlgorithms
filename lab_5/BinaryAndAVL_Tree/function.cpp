#include <iostream>
#include "Header.h"
#include <queue>

using namespace std;

NODE* CreateNode(int data)
{
	NODE* p = new NODE;
	p->p_left = p->p_right = NULL;
	p->key = data;

	return p;
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
			Insert(p_root->p_right,x);
		}
		else
		{
			cout << "duplicate !" << endl;
		}
	}

}

bool Search(NODE* p_root, int x)
{
	if (p_root == NULL)
		return false;
	if (p_root->key == x)
	{
		return true;
	}
	if (p_root->key > x)
		return Search(p_root->p_left, x);
	if (p_root->key < x)
		return Search(p_root->p_right, x);
	if (p_root->p_left == NULL && p_root->p_right == NULL)
		return false;
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
		cout << p_root->key << "  ";
		LNR(p_root->p_right);
	}
}

void LRN(NODE* p_root)
{
	if (p_root != NULL)
	{
		LRN(p_root->p_left);
		LRN(p_root->p_right);
		cout << p_root->key << "  ";
		
	}
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
//
//int min_of_left(NODE* tree)
//{
//	int min = tree->key;
//	if (tree->p_left->key < min)
//		min = min_of_left(tree->p_left);
//	if (tree->p_left == NULL)
//		return min;
//
//}
void find_node_leftest(NODE* &X, NODE* &Y)
{
	
	if (Y->p_left != NULL)
	{
		find_node_leftest(X, Y->p_left);
	}
	else
	{
		X->key = Y->key;
		X = Y;
		Y = Y->p_right;
	}
}
void Remove(NODE*& p_root, int x)
{
	if (p_root == NULL)
		return;
	else
	{
		if (x < p_root->key)
			Remove(p_root->p_left, x);
		else if (x > p_root->key)
			Remove(p_root->p_right, x);
		else
		{
			NODE* temp = p_root; // tao 1 node tam
			if (p_root->p_left == NULL)
				p_root = p_root->p_right;
			else if (p_root->p_right == NULL)
			{
				p_root = p_root->p_left;
			}
			else
			{ // cach 1 : tim cay con trai nhat
				find_node_leftest(temp, p_root->p_right);
			}
			delete temp;
			

		}
	}
}
void LevelOrder(NODE* p_root)
{
	queue<NODE*> Q;
	if (p_root == NULL)
	{
		return;
	}
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

int CountNode(NODE* p_root)
{
	if(p_root==NULL)	return 0;
	return CountNode(p_root->p_left) + CountNode(p_root->p_right) + 1;
}

int Level(NODE* p_root, NODE* p)
{

	int depth = 0;

	if (p_root == NULL) {
		return 0;
	}
	

	else
	{
		
		if (p_root->key == p->key)
		{
			return depth +1;
		}
		
		depth += 1;
		
		 if (p->key < p_root->key && p_root->p_left !=NULL)
		{
			return depth + Level(p_root->p_left, p);
		}
		else if(p->key > p_root->key && p_root->p_right !=NULL)
		{
			return depth + Level(p_root->p_right, p);
		}
		
		
	}
}

int CountLeaf(NODE* p_root)
{
	int count_leaf = 0;
	
	if (p_root != NULL)
	{
		if (p_root->p_left == NULL && p_root->p_right == NULL)
		{
			count_leaf += 1;
		}
		else
		{
			if (p_root->p_left != NULL && p_root->p_right != NULL)
			{
				return count_leaf + CountLeaf(p_root->p_left) + CountLeaf(p_root->p_right);
			}
			else if (p_root->p_left != NULL && p_root->p_right == NULL)
			{
				return count_leaf + CountLeaf(p_root->p_left) + 0;
			}
			else if (p_root->p_left == NULL && p_root->p_right != NULL)
			{
				return count_leaf + CountLeaf(p_root->p_right) + 0;
			}
		}
	}
}

int CountLess(NODE* p_root, int x)
{
	int count = 0;
	if (p_root != NULL)
	{
		if (x > p_root->key)
		{
			count += 1;
		}
		if (x < p_root->key)
		{
			return count + CountLess(p_root->p_left, x) + CountLess(p_root->p_right, x);
			
		}
		else if(x > p_root->key)
		{
			return count + CountLess(p_root->p_left, x) + CountLess(p_root->p_right, x);
		}
	}
	return count;
}

int CountGreater(NODE* p_root, int x)
{
	int count = 0;
	if (p_root!=NULL)
	{
		if (x < p_root->key)
		{
			count += 1;
		}
		if (x < p_root->key)
		{
			return count + CountGreater(p_root->p_left, x) + CountGreater(p_root->p_right, x);
		}
		else if (x > p_root->key)
		{
			return count + CountGreater(p_root->p_left, x) + CountGreater(p_root->p_right, x);
		}
	}
	return count;
}

bool IsBST(NODE* p_root)
{
	if (p_root == NULL)
		return true;
	if (p_root->p_left != NULL && p_root->p_left->key > p_root->key)
		return false;
	if (p_root->p_right != NULL && p_root->p_right->key < p_root->key)
		return false;
	if (!IsBST(p_root->p_left) || IsBST(p_root->p_right))
		return false;
	return true;
}


/*
		8
	4		10 (temp vs X)
   3 5	   9   12 (Y)
	  6          15
				14  16
						18
*/