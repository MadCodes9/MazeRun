# MazeRun
Compares how many vertices are tansversed in the maze for the mouse to get to the cheese or target vertex using depth first search(DFS) and breadth first search(BFS).
## General Information 
This project utilizes the depth-first search and breadth-first search algorithms. 
This project, reads a graph from a file, which represent a maze. In this maze, there is a starting 
vertex at which a mouse will start its search for a piece of cheese (located at another vertex).
Depth-first search and breadth-first search is used to determine the path to the cheese. When each 
search is executed, the number of undiscovered edges that are used to visit a vertex are to be counted.
For depth-first search, the path that is traveled is to be output to the screen and for breadth-first 
search, the vertices that are visited during the search are to be output to the screen. Once the 
cheese has been reached, the search can stop.

**Depth First Search Function**
```C++
void Graph::DFS(Graph const& graph, int v, vector<bool>& discovered) {
   int cheese = getCheese();
   discovered[v] = true;   // mark the current node as discovered
   
   if (foundCheese != true) {
       cout << v << "-> ";   // print the current node
       for (int u : graph.adjList[v]) { // do for every edge v > u
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
```

**Breadth First Search Function**
```C++
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
           for (int u : graph.adjList[v]) { // do for every edge v > u
               if (!discovered[u] && u != cheese) {   // mark it as discovered and enqueue it
                   countBFS++;
                   discovered[u] = true;
                   q.push(u);
               }
           }
       }
    }
}
```
## Technologies
Project is created with 
* IDE: Microsoft Visual Studio 2019
* Version: 16.11.10
* Language: C++20
## Setup
To run this project use Microsoft Visual Studio or an IDE that supports C++20 and download the files.
The  file is located in the Debug Folder and can be changed to different .
The user will be prompt to enter 

**Sample Output**

![image]()
## Status 
This is a project created by @MadCodes9 :grinning:

Source: *Data Structures and Algorithms in C++ 2nd Edition*
