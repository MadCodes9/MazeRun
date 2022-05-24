#include <iostream>
#include <vector>
#include <queue>
#include "Graph.h"
using namespace std;
Graph::Graph(vector<Edge> const& edges, int N) {
    adjList.resize(N);  // resize the vector to hold N elements of type vector<int>

    // add edges to the undirected graph
    for (auto& edge : edges)   { //for ( range_declaration : range_expression ) 
        adjList[edge.src].push_back(edge.dest);
        adjList[edge.dest].push_back(edge.src);
    }
}
void Graph::DFS(Graph const& graph, int v, vector<bool>& discovered) {
   int cheese = getCheese();
   discovered[v] = true;   // mark the current node as discovered
   
   if (foundCheese != true) {
       cout << v << "-> ";   // print the current node
       for (int u : graph.adjList[v]) { // do for every edge v —> u
           if (!discovered[u]) {   // if u is not yet discovered
               countDFS++;
               if (u == cheese) {
                   countDFS++;
                   foundCheese = true;  //function is finished
                   cout << u;
                   cout << "\n\tNumber of vertices visitied by mouse: " << countDFS << endl;
               }
               else {
                   DFS(graph, u, discovered);
               } 
           }  
       }
   }
}
void Graph::BFS(Graph const& graph, int v, vector<bool>& discovered) {
    int cheese = getCheese();
    queue<int> q;  // create a queue for doing BFS
    discovered[v] = true;   // mark the source vertex as discovered
    q.push(v);    // enqueue source vertex

    while (!q.empty()){ // loop till queue is empty
       if (q.front() == cheese) {    //get out of loop when exisit is reached
           v = q.front();   
           q.pop();
           countBFS++;

           cout << v; 
           cout << "\n\tNumber of vertex visitied by mouse: " << countBFS << endl;
           break;
       }
       else {
           v = q.front();   // dequeue front node and print it
           q.pop();
           cout << v << "-> ";   // print the current node
           for (int u : graph.adjList[v]) { // do for every edge v —> u
               if (!discovered[u] && u != cheese) {   // mark it as discovered and enqueue it
                   countBFS++;
                   discovered[u] = true;
                   q.push(u);
               }
           }
       }
    }
}
void Graph::printGraph(Graph const& graph, int N){
    for (int i = 1; i < N; i++) {
        cout << "\t" << i << " --> ";   //current vertex 
        for (int v : graph.adjList[i]) {    // print all adjacent vertices of a vertex i
            cout << v << " ";
        }
        cout << endl;
    }
}