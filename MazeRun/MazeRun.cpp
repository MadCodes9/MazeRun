/*
* Program: MazeRun.cpp
* Author: Ceiara Madrigal
* Course: CSCI 230
* Date: 6/08/2021
* Description: This project utilizes the depth-first search and breadth-first search algorithms. 
* This project, reads a graph from a file, which represent a maze. In this maze, there is a starting 
* vertex at which a mouse will start its search for a piece of cheese (located at another vertex).
* Depth-first search and breadth-first search is used to determine the path to the cheese. When each 
* search is executed, the number of undiscovered edges that are used to visit a vertex are to be counted.
* For depth-first search, the path that is traveled is to be output to the screen and for breadth-first 
* search, the vertices that are visited during the search are to be output to the screen. Once the 
* cheese has been reached, the search can stop.
*
* I certify that the following code is my own work.
*
* Exception(s): N/A
*/
#include <iostream>
#include<vector>
#include<fstream>
#include<iomanip>
#include"Graph.h"
using namespace std;
void testDFS(vector<Edge> edges, int N, int cheese) {
    Graph graph(edges, N);  
    vector<bool> discovered(N); // to keep track of whether a vertex is discovered or not
    graph.setCheese(cheese);
    cout << "\n\t= Print of Maze =" << endl;
    graph.printGraph(graph, N);
    // Perform DFS traversal from all undiscovered nodes to
    // cover all unconnected components of a graph
    cout << "\n\t= Cheese is at vertex " << cheese << " =";
    cout << "\n\tMouse 1 uses the DFS method to transverse maze " << endl;
    cout << "\t";
    for (int i = 1; i < N; i++) {
        if (discovered[i] == false) {
            graph.DFS(graph, i, discovered);
        }
    }
}
void testBFS(vector<Edge> edges, int N, int cheese) {
    Graph graph(edges, N);
    vector<bool> discovered(N); // to keep track of whether a vertex is discovered or not
    graph.setCheese(cheese);
    cout << "\n\t= Cheese is at vertex " << cheese << " =";
    cout << "\n\tMouse 2 uses the BFS method to transverse maze " << endl;
    cout << "\t";
    for (int i = 1; i < N; i++) {
        if (discovered[i] == false) {
            graph.BFS(graph, i, discovered);
        }
    }
}
int main(){
    int N1 = 26;    //(0-25)
    int N2 = 101;   //(0-100)
    int cheese1 = 25;
    int cheese2 = 100;
    int src;
    int dest;
    vector<Edge> edges1;
    vector<Edge> edges2;
    ifstream inFile; 
    Edge inputEdge;

    inFile.open("Cheese1.txt");
    if (!inFile.is_open()) {
        cout << "Could not open file" << endl;
        return 1;
    }
    while (inFile >> src >> dest) { //read text file
       inputEdge.src = src;
       inputEdge.dest = dest;
       edges1.push_back(inputEdge);
    }
    cout << setw(30) << "================" << endl;
    cout << setw(30) << "= Mouse Maze 1 =" << endl;
    cout << setw(30) << "================" << endl;
    testDFS(edges1, N1, cheese1);
    testBFS(edges1, N1, cheese1);
    inFile.close(); //close test file

    inFile.open("Cheese2.txt");
    if (!inFile.is_open()) {
        cout << "Could not open file" << endl;
        return 1;
    }
    while (inFile >> src >> dest) {
        inputEdge.src = src;
        inputEdge.dest = dest;
        edges2.push_back(inputEdge);
    }
    cout << endl;
    cout << setw(30) << "================" << endl;
    cout << setw(30) << "= Mouse Maze 2 =" << endl;
    cout << setw(30) << "================" << endl;
    testDFS(edges2, N2, cheese2);
    testBFS(edges2, N2, cheese2);
    inFile.close();
    cin.get();
    return 0;
}

