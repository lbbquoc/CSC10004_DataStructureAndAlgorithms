#pragma once
#include <string>
using namespace std;
#define MAX 100
struct Graph
{
	int num_vertices; // number of vertices
	int adjacency_matrix[MAX][MAX]; // adjacency matrix
};

//1. Hàm đọc thông tin đồ thị từ tập tin :
Graph ReadGraph(string file_name);
// 2. Hàm hiển thị đồ thị
void DisplayGraph(Graph g);

//3. Hàm kiểm tra đồ thị có hợp lệ không :
bool IsValidGraph(Graph g);

//4. Kiểm tra một đồ thị có phải là đồ thị vô hướng :
bool IsScalarGraph(Graph g);

//5. Đếm số lượng cạnh trong đồ thị :
int CountEdge(Graph g);

//6. Đếm số lượng đỉnh có yêu cầu :
int CountVertice(Graph g, int flag);

//7. Duyệt đồ thị theo chiều rộng :
void BFS(Graph g, int begin_vertex);

//8. Duyệt đồ thị theo chiều sâu :
void DFS(Graph g, int begin_vertex);

//9. Kiểm tra đồ thị có liên thông không :
bool IsConnectedGraph(Graph g);


//10. Đếm số thành phần liên thông của đồ thị :
int CountConnectedComponents(Graph g);

//11. Tìm đường đi ngắn nhất từ một đỉnh đến tất cả các đỉnh còn lại theo thuật toán Dijkstra :
void FindShortestPath_Dijkstra(Graph g, int begin_vertex);
