#include "Graph.hpp"
#include <vector>
#include <queue>
#include <iostream>

using namespace std;

void Graph::addEdge(string v1, string v2)               // Using addEdge function from rec9 (Change parameter argument)
{
    for(int i = 0; i < vertices.size(); i++)            // For loop to traverse the vertices
    {
        if(vertices[i]->name == v1)                     // If we find a node containing v1 string
        {
            for(int j = 0; j < vertices.size(); j++)    // Enter in a nested loop
            {
                if(vertices[j]->name == v2 && i != j)   // If we found v2 but it's not at the same position as v1
                {
                    adjVertex av;                       // Create adjVertex variable
                    av.v = vertices[j];                 // Store j-th node in there
                    vertices[i]->adj.push_back(av);     // Push it onto the stack
                    adjVertex av2;                      // Create adjVertex variable
                    av2.v = vertices[i];                // store i-th node in there
                    vertices[j]->adj.push_back(av2);    // push it onto the back/end of the vector
                }
            }
        }
    }
}
void Graph::addVertex(string name)                      // Using addVertext function from rec9 (Change parameter argument)
{
    bool found = false;                                 // Declare a checker variable and set it to false
    for(int i = 0; i < vertices.size(); i++){           // Traverse the vertices
        if(vertices[i]->name == name){                  // If we found node containing the string name we passed through
            found = true;                               // We turn the checker variable to be true (node found)
        }
    }
    if(!found)                                          // If the loop above finished and found is still false
    { 
        vertex * v = new vertex;                        // Then we allocate a new node
        v->name = name;                                 // Store the string name data into it
        vertices.push_back(v);                          // push it onto the back/end of the vector
    }
}
void Graph::displayEdges()                              // Function to print the edges of the graph
{
    for (int i = 0; i < vertices.size();i++)            // Traverse the vertices
    {
        cout << vertices[i]->name << " --> ";           // print the name at each vertex
        for (int j = 0; j < vertices[i]->adj.size();j++)// traverse the adjacent vertices
        {
            cout << vertices[i]->adj[j].v->name << " "; // Print the adjacent nodes
        }
        cout << endl;                                   // end line
    }
}
void Graph::breadthFirstTraverse(string sourceVertex)   // BFS algorithm for graph (with string parameter)
{
    vertex *vStart, *n;                                 // Declare the pointers we are going to use
    for (int i = 0; i < vertices.size(); i++)           // Traverse the vertices
    {                                                   // If we found the node that contain the string we are passing through
        if (vertices[i]->name == sourceVertex){vStart = vertices[i];} // Then assign vStart as it
    }
    vStart->visited = true;                             // We turn visited to true
    queue<vertex*> q;                                   // Declare a queue pointer
    q.push(vStart);                                     // push vStart into the queue
    cout << "Starting vertex (root): " << vStart->name << "-> ";
    while (!q.empty())                                  // While loop to run until q is empty
    {
        n = q.front();                                  // set pointer n to the the front node
        q.pop();                                        // pop (in this case, dequeue)
        for (int x = 0; x < n->adj.size();x++)          // traverse the adjacent nodes
        {
            if ((!n->adj[x].v->visited))                // If we find an adjacent node that has not been visited
            {
                n->adj[x].v->distance = n->distance + 1;// set it's distance + 1
                n->adj[x].v->visited = true;            // turn visted to true
                cout << n->adj[x].v->name << "(" << n->adj[x].v->distance << ")" << " ";
                q.push(n->adj[x].v);                    // Push it onto the queue
            }
        }
    }
    cout << endl;                                       // End line
}
int Graph::getConnectedBuildings()                      // Function to get (return) the connected component
{
    int count = 0;                                      // Declare a counter variable and set it to start from zero

    for (int x = 0; x < vertices.size();x++)            // Traverse the vertices
    {
        vertices[x]->visited = false;                   // Set each visited of each node to be false
    }
    for (int x = 0; x < vertices.size();x++)            // Traverse the vertices
    {
        if (!(vertices[x]->visited))                    // If we come across a node that has not been visited
        {               
            vertices[x]->visited = true;                // Set it to true since we are not visiting that node
            queue<vertex*> q;                           // Declare a queue pointer
            q.push(vertices[x]);                        // Push node at x
            vertex * n;                                 // Declare a vertex pointer n
            while (!(q.empty()))                        // While loop will run until queue is empty
            {                                           // BFS to find connected component
                n = q.front();                          // Assign pointer n to q front
                q.pop();                                // (pop, dequeue)
                for (int x = 0; x < n->adj.size();x++)  // Traverse the adjacent side
                {
                    if ((!n->adj[x].v->visited))        // If we find an adjacent node haven't been visited
                    {                                   // Set it's distance to + 1
                        n->adj[x].v->distance = n->distance + 1;
                        n->adj[x].v->visited = true;    // Turn it to true
                        q.push(n->adj[x].v);            // Push it onto the queue
                    }
                }
            }
            count++;                                    // Increment the count of connected component
        }
    }
    return count;                                       // return count
}
