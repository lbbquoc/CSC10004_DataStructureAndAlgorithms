#include<string>
#include<fstream>
#include<iostream>
#include<vector>
#include <queue>
using namespace std;
#include"Header.h"
#include <list>
#include <stack>
#define V 6
// init graph
void init_garph(Graph  g, int n)
{
	g.num_vertices = n;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			g.adjacency_matrix[i][j] = 0;
		}
	}
}

void add_edge(Graph* g, int vertex, int x , int y)
{
	g->adjacency_matrix[x][vertex] = 1;
	g->adjacency_matrix[y][vertex] = 1;
}

vector<string> read_line(string line_info)
{
	vector<string> list_element;
	string  element;
	for (int i = 0; i < line_info.length(); i++)
	{
		if (line_info[i] != ' ')
		{
			element += line_info[i];
		}
		else
		{
			list_element.push_back(element);
			element = "";
		}
	}

	return list_element;
}

Graph ReadGraph(string file_name)
{
	vector<string> list_data;
	Graph G;
	int num_vertices;
	fstream file;
	file.open(file_name, ios::in);

	// init graph with num_vertices
	file >> num_vertices;
	G.num_vertices = num_vertices;
	
	string temp;
	getline(file, temp);
	
	init_garph(G, num_vertices);

	// read data from file
	string line_info;
	int count = 0;
	while (!file.eof())
	{
		getline(file, line_info);
		list_data = read_line(line_info);
		for (int i = count; i < num_vertices; )
		{
			for (int j = 0; j < num_vertices; j++)
			{
				G.adjacency_matrix[count][j] = stoi(list_data[j]);
			}
			break;
		}
		count++;
	}
	file.close();

	return G;
}

void DisplayGraph(Graph g)
{
	for (int i = 0; i < g.num_vertices; i++)
	{
		for (int j = 0; j < g.num_vertices; j++)
		{
			cout << g.adjacency_matrix[i][j] << " ";
			if (j == g.num_vertices-1)
				cout << endl;
		}
	}
}

bool IsValidGraph(Graph g)
{
	if (g.num_vertices < 0)
		return false;
	bool flag_1 = false;
	bool flag_2 = false;
	for (int i = 0; i < g.num_vertices; i++)
	{
		for (int j = 0; j < g.num_vertices; j++)
		{
			if (i == j)
			{
				if (g.adjacency_matrix[i][j] == 0)
					flag_1 = true;
			}
			
			if (g.adjacency_matrix[i][j] >= 0)
				flag_2 = true;
		}
	}
	if (flag_1 == false || flag_2 == false)
		return false;

	return true;
}

bool IsScalarGraph(Graph g)
{
	int key = g.adjacency_matrix[0][0];
	bool flag = false;

	for (int i = 0; i < g.num_vertices; i++)
	{

		for (int j = 0; j < g.num_vertices; j++)
		{
			if (i == j)
			{
				if (g.adjacency_matrix[i][j] == key)
					flag = true;
			}
		}
	}

	if (flag == false)
		return false;
	else
	{
		return true;
	}
}

int CountEdge(Graph g)
{
	int count = 0;
	for (int i = 0; i < g.num_vertices; i++)
	{
		for (int j = 0; j < g.num_vertices; j++)
		{
			if (g.adjacency_matrix[i][j] != 0)
				count++;
		}
	}

	if (IsScalarGraph(g) == true)
	{
		return count / 2;
	}
	else
	{
		return count;
	}
}


int CountVertice(Graph g, int flag)
{
	int count_in_row = 0;
	int count_odd_vertices = 0;
	int count_even_vertices = 0;
	for (int i = 0; i < g.num_vertices; i++)
	{
		if (count_in_row % 2 == 0)
		{
			count_even_vertices++;
			count_in_row = 0;
		}
		else
		{
			count_odd_vertices++;
			count_in_row = 0;
		}

		for (int j = 0; j < g.num_vertices; j++)
		{
			if (g.adjacency_matrix[i][j] != 0)
			{
				count_in_row++;
			}
		}
	}

	if (flag == 0)
	{
		return count_even_vertices - 1;
	}
	else if(flag == 1)
	{
		return count_odd_vertices;
	}
	
	// phai lay gia tri even -1 boi vi : ban dau dong 182 da dua vao thua 1
}


void BFS(Graph g, int begin_vertex)
{
	vector<bool> visited(g.num_vertices, false);
	vector <int> que;
	que.push_back(begin_vertex);

	visited[begin_vertex] = true;

	int visitation;

	while (!que.empty())
	{
		visitation = que[0];

		cout << visitation << " ";
		que.erase(que.begin());

		for (int i = 0; i < g.num_vertices; i++)
		{
			if (g.adjacency_matrix[visitation][i] != 0 && !visited[i])
			{
				que.push_back(i);

				visited[i] = true;
			}
		}
	}
}

void ImplementDFS(Graph g, int begin_vertex, vector<bool>& visited)
{
	cout << begin_vertex << " ";

	visited[begin_vertex] = true;

	for (int i = 0; i < g.num_vertices; i++)
	{
		if (g.adjacency_matrix[begin_vertex][i] != 0 && !visited[i])
			ImplementDFS(g, i, visited);
	}
}

void DFS(Graph g, int begin_vertex)
{
	vector<bool> visited(g.num_vertices, false);
	ImplementDFS(g, begin_vertex, visited);
}







void traverse(int s, bool visited[], Graph g) {
	visited[s] = true; //mark v as visited
	queue<int> que;
	que.push(s);//insert s into queue
	while (!que.empty()) {
		int u = que.front(); //delete from queue and print
		que.pop();
		for (int i = 0; i < g.num_vertices; i++) {
			if (g.adjacency_matrix[i][u]) {
				//when the node is non-visited
				if (!visited[i]) {
					visited[i] = true;
					que.push(i);
				}
			}
		}
	}
}

bool IsConnectedGraph(Graph g)
{

	bool* vis = new bool[g.num_vertices];
	//for all vertex u as start point, check whether all nodes are visible or not
	for (int u = 0; u < g.num_vertices; u++) {
		for (int i = 0; i < g.num_vertices; i++)
			vis[i] = false; //initialize as no node is visited
		traverse(u, vis, g);
		for (int i = 0; i < g.num_vertices; i++) {
			if (!vis[i]) //if there is a node, not visited by traversal, graph is not connected
				return false;
		}
	}
	return true;
}

/////////////////

int CountConnectedComponents(Graph g)
{
	if (IsConnectedGraph(g))
		return 1;

	int count = 1;
	queue<int> que;
	int* connection = new int[g.num_vertices];
	for (int i = 0; i < g.num_vertices; i++)
		connection[i] = 0;

	que.push(0);
	for (int i = 0; i < g.num_vertices; i++)
	{
		while (!que.empty())
		{
			int visited = que.front();
			connection[visited] = count;
			que.pop();
			for (int j = 0; j < g.num_vertices; j++)
			{
				if (connection[j] == 0 && g.adjacency_matrix[visited][j] != 0)
				{
					connection[j] = count;
					que.push(j);
				}
			}
		}

		if (connection[i] == 0)
		{
			que.push(i);
			count++;
		}
	}

	return count;
}




int minDistance(int dist[], bool sptSet[],Graph g)
{
	// Initialize min value 
	int min = INT_MAX, min_index;

	for (int v = 0; v < g.num_vertices; v++)
		if (sptSet[v] == false && dist[v] <= min)
			min = dist[v], min_index = v;

	return min_index;
}


void printSolution(int dist[],Graph g)
{
	printf("Vertex \t\t Distance from Source\n");
	for (int i = 0; i < g.num_vertices; i++)
		printf("%d \t\t %d\n", i, dist[i]);
}

void FindShortestPath_Dijkstra(Graph g, int begin_vertex)
{
	int *dist=new int [V]; 
	

	bool sptSet[V];
	


	for (int i = 0; i < V; i++)
		dist[i] = INT_MAX, sptSet[i] = false;


	dist[begin_vertex] = 0;


	for (int count = 0; count < V - 1; count++) {
	
		int u = minDistance(dist, sptSet,g);

		
		sptSet[u] = true;

		
		for (int v = 0; v < V; v++)

			
			if (!sptSet[v] && g.adjacency_matrix[u][v] && dist[u] != INT_MAX
				&& dist[u] + g.adjacency_matrix[u][v] < dist[v])
				dist[v] = dist[u] + g.adjacency_matrix[u][v];
	}


	printSolution(dist,g);
}







