#pragma once

struct NODE
{
	int key;
	NODE* p_next;
};

struct List
{
	NODE* p_head;
	NODE* p_tail;
};

NODE* CreateNode(int data);
//List* CreateList(NODE* p_node);
void CreateList(List& l);
bool AddHead(List* L, int data);
bool AddTail(List* L, int data);
void RemoveHead(List* L);
void RemoveTail(List* L); 
void RemoveAll(List*& L);
void PrintList(List* L);
int CountElements(List* L);
List* ReverseList(List* L);
void RemoveDuplicate(List*& L);
bool RemoveElement(List*& L, int key);
