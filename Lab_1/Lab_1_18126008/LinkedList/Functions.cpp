#include <iostream>
using namespace std;
#include "Header.h"

NODE* CreateNode(int data)
{
	NODE* p = new NODE;
	if (p == NULL)
	{
		cout << "not enough  memory !!!";
		return NULL;
	}
	p->key = data;
	p->p_next = NULL;
	return p;

}

void CreateList(List& l)
{
	l.p_head = l.p_tail = NULL;
}

bool AddHead(List* L, int data)
{
	NODE* p = CreateNode(data);
	
	if (L->p_head == NULL)
	{
		L->p_head = L->p_tail = p;
	}
	else
	{
		p->p_next = L->p_head;
		L->p_head = p;
	}

	return true;
}

bool AddTail(List* L, int data)
{
	NODE* p = CreateNode(data);
	if (L->p_tail == NULL)
	{
		L->p_head = L->p_tail = p;
	}
	else
	{
		L->p_tail->p_next = p;
		L->p_tail = p;
	}
	return true;
}


void RemoveHead(List* L)
{
	if (L->p_head == NULL)
	{
		return;
	}
	NODE* p = L->p_head;
	L->p_head = L->p_head->p_next;
	delete p;
}

void RemoveTail(List* L)
{
	if (L->p_tail == NULL)
	{
		return;
	}
	NODE* p = L->p_tail;
	for (NODE* k = L->p_head; k != NULL; k = k->p_next)
	{
		if (k->p_next == p)
		{
			delete p;
			k->p_next = NULL;
			L->p_tail = k;
		}
	}
}

void RemoveAll(List*& L)
{
	NODE* temp1 = L->p_head->p_next;
	while (temp1 != NULL) // as I am considering tail->next = NULL
	{
		L->p_head->p_next = temp1->p_next;
		temp1->p_next = NULL;
		free(temp1);
		temp1 = L->p_head->p_next;
	}
	L->p_head = NULL;
	delete L->p_head;
	
	
}

void PrintList(List* L)
{
	for (NODE* k = L->p_head; k != NULL; k = k->p_next)
	{
		cout << k->key << "  ";
	}

	cout << "\n";
}

int CountElements(List* L)
{
	int count = 0;
	for (NODE* k = L->p_head; k != NULL; k = k->p_next)
	{
		count++;
	}

	return count;
}

List* ReverseList(List* L)
{
	NODE* prev = NULL; // node luôn nằm phía trước của p_head
	NODE* next = NULL; // node lưu giá trị đằng sau của p_head
	NODE* current = L->p_head; // p_head hiện tại, để sử dụng trong mỗi lần lặp
	while (current != NULL)
	{
		next = current->p_next; // ở đây ta lưu lại giá trị node phía sau của p_head 

		current->p_next = prev; // tạo mối liên kết giữa p_head và prev 


		prev = current; // gán địa chỉ của p_head hiện tại cho prev ( tức là khi truy xuất giá trị thì giá trị của current đang dùng cũng là prev vì cả 2 đang dùng chung địa chỉ
		current = next; // cập nhật lại vị trí của p_head
	}

	 L->p_head = prev; // vì cứ sau mỗi lần lặp current sẽ dần dần tụt lui sau , do đang mang địa chỉ của những node ở phía sau của p_head khi vòng lặp mới bắt đầu 

	 return L;
}


bool RemoveElement(List*& L, int key)
{
	NODE* k;
	for (NODE* p = L->p_head; p != NULL; p = p->p_next)
	{
		if (p->p_next->key == key)
		{
			k = p->p_next;
			p->p_next = k->p_next;
			delete k;
			return true;
		}
	}

	return false;
}

void RemoveDuplicate(List*& L)
{
	NODE* p1, * p2, * dup;
	p1 = L->p_head;
	while (p1 != NULL && p1->p_next != NULL)
	{
		p2 = p1;
		while (p2->p_next!=NULL)
		{
			if (p1->key == p2->p_next->key)
			{
				dup = p2->p_next;
				p2->p_next = p2->p_next->p_next;
				delete(dup);
			}
			else
			{
				p2 = p2->p_next;

			}

		}
		p1 = p1->p_next;
	}
}
