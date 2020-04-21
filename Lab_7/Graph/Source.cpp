#include <iostream>
#include "Header.h"
#include <queue>

using namespace std;



int main()
{
	string file_name;
	cout << "enter the file_name : " << endl;
	cin >> file_name;
	
	
	Graph g = ReadGraph(file_name);
	DisplayGraph(g);
	//cout << IsValidGraph(g) << endl;
	cout << IsScalarGraph(g) << endl;
	//cout << CountEdge(g) << endl;
	//cout << CountVertice(g, 0) << endl;
	BFS(g, 1);
	cout << endl;
	cout << IsConnectedGraph(g);

	cout << CountConnectedComponents(g);

	FindShortestPath_Dijkstra(g, 0);
	
	
	
	return 0;
}