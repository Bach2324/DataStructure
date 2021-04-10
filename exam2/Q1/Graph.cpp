#include "Graph.hpp"
#include <vector>
#include <queue>
using namespace std;

/*
 * adds a vertex to the graph
 */
void Graph::addVertex(int n){
    bool found = false;
    for(int i = 0; i < vertices.size(); i++){
        if(vertices[i]->key == n){
            found = true;
        }
    }
    if(found == false){
        vertex * v = new vertex;
        v->key = n;
        vertices.push_back(v);
    }
}

/*
 * adds an edge between two vertices (directed graph)
 */
void Graph::addEdge(int src, int dest){
    for(int i = 0; i < vertices.size(); i++) {
        if(vertices[i]->key == src) {
            for(int j = 0; j < vertices.size(); j++) {
                if(vertices[j]->key == dest && i != j) {
                    adjVertex av;
                    av.v = vertices[j];
                    vertices[i]->adj.push_back(av);
                }
            }
        }
    }
}

/*
 * Complete the following function which checks if vert is a boss vertex
 */
bool Graph::isVertexABoss(vertex *vert)
{
    // ***** USING CODE FROM RECITATION 9 FindShortestPath function *****
    // Use the queue to keep track of visited vertices
    queue<vertex*> q;
    // Enqueue the source vertex
    q.push(vert);
    vertex *n;
    // standard BFS
    while(!q.empty())
    {
        n = q.front();
        q.pop();
        // go to all the adjacent vertices of n
        for( int x = 0; x < n->adj.size(); x++)
        {   // If a adjacent has not been visited, then mark it visited and enqueue it
            if(!(n->adj[x].v->visited))
            {
                // Update the distance of the adjacent vertices along the way
                n->adj[x].v->visited = true;
                q.push(n->adj[x].v);
                // Stop when you reach the destination vertex and return the needful
            }
        }
    }
    for (int i = 1; i < vertices.size(); i++)               // For loop to traverse the vertices
    {
        if (!(vertices[i]->visited)){return false;}         // Return false if visited is false (not a boss vertex)
    }
    return true;                                            // Return true other wise (vertex is a boss)
}
/*
 * Complete the following function which checks if the graph is a Boss
 */
bool Graph::isGraphABoss()                                 
{
    for (int i = 0; i < vertices.size(); i++)                   // For loop to traverse the vertices
    {
        if (isVertexABoss(vertices[i]) == true){return true;}   // If we find a boss vertex, then the graph is a boss (return true)
    }
    return false;                                               // Otherwise, return false (graph is not a boss)
}
