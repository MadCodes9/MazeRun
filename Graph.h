#pragma once
#include <iostream>
#include<vector>
using namespace std;
struct Edge{
	int src, dest;
};
class Graph{
private:
	vector<vector<int>> adjList;	// a vector of vectors to represent an adjacency list
	int cheese;
	bool foundCheese = false;
	int countDFS = 0;
	int countBFS = 0;
public:
	void setCheese(const int cheese) {
		this->cheese = cheese;
	}
	int getCheese() const {
		return cheese;
	}
	Graph(vector<Edge> const& edges, int N);	//create graph
	void DFS(Graph const& graph, int v, vector<bool>& discovered);
	void BFS(Graph const& graph, int v, vector<bool>& discovered);
	void printGraph(Graph const& graph, int N);
};

