#pragma once
#include <iostream>
using namespace std;
struct NODE {
	int key;
	NODE* p_left;
	NODE* p_right;
	int height;
};

//1. Khởi tạo 1 NODE:
NODE* CreateNode(int data);
//2. Thêm 1 NODE có giá trị cho trước vào cây AVL(Thông báo nếu như giá trị cho trước đã có trong cây AVL) :
void Insert(NODE*& p_root, int x);
//3. Xoá 1 NODE có giá trị cho trước khỏi cây AVL(Thông báo nếu giá trị đó không có trong cây AVL) :
void Remove(NODE*& p_root, int x);
	//4. Thực hiện thao tác duyệt trước(bao gồm key và height) :
void NLR(NODE* p_root);
	//5. Thực hiện thao tác duyệt giữa(bao gồm key và height) :
void LNR(NODE* p_root);
	//6. Thực hiện thao tác duyệt sau(bao gồm key và height) :
void LRN(NODE* p_root);
	//7. Thực hiện thao tác duyệt theo tầng(bao gồm key và height) :
void LevelOrder(NODE* p_root);
	//8. * Kiểm tra xem 1 cây nhị phân cho trước có phải là 1 cây AVL hay không :
bool IsAVL(NODE* p_root);
