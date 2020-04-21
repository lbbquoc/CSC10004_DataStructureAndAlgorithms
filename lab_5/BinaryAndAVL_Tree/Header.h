#pragma once
struct NODE {
	int key;
	NODE* p_left;
	NODE* p_right;
};


// 1. Khởi tạo 1 NODE từ một giá trị cho trước :
NODE* CreateNode(int data);

//2. Thực hiện thao tác duyệt trước :
void NLR(NODE* p_root);

//3. Thực hiện thao tác duyệt giữa :
void LNR(NODE* p_root);

//4. Thực hiện thao tác duyệt sau :
void LRN(NODE* p_root);

//5. Thực hiện thao tác duyệt theo tầng :
void LevelOrder(NODE* p_root);

//6. Tìm và trả về 1 NODE có giá trị cho trước trên cây nhị phân tìm kiếm :
bool Search(NODE* p_root, int x);

//7. Thêm 1 NODE có giá trị cho trước vào cây nhị phân tìm kiếm :
void Insert(NODE*& p_root, int x);

//8. Xoá 1 NODE có giá trị cho trước trên cây :
void Remove(NODE*& p_root, int x);

//9. Tính chiều cao của 1 cây nhị phân cho trước :
int Height(NODE* p_root);

//10. Đếm số NODE trên 1 cây nhị phân cho trước :
int CountNode(NODE* p_root);

//11. * Tính mức của một NODE cho trước :
int Level(NODE* p_root, NODE* p);

//12. * Đếm số NODE lá trên 1 cây nhị phân cho trước :
int CountLeaf(NODE* p_root);

//13. * Đếm số NODE có khoá nhỏ hơn giá trị x cho trước :
int CountLess(NODE* p_root, int x);

//14. * Đếm số NODE có khoá lớn hơn giá trị x cho trước :
int CountGreater(NODE* p_root, int x);

//15. * Kiểm tra xem 1 cây nhị phân cho trước có phải là 1 cây nhị phân tìm kiếm hay không :
bool IsBST(NODE* p_root);



