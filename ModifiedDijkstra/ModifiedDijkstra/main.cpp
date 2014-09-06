//
//  main.cpp
//  ModifiedDijkstra
//
//  http://www.geeksforgeeks.org/greedy-algorithms-set-6-dijkstras-shortest-path-algorithm/
//
//  Created by Vladimir Kuzmov on 7/7/14.
//  Copyright (c) 2014 Vladimir Kuzmov. All rights reserved.
//

#include <iostream>
#include <limits.h>
#include <queue>

using namespace std;

// Number of vertices in the graph
#define V 8

int minDistance(int * dist, bool * sptSet)
{
    int min = INT_MAX, min_index;
    
    for (int i = 0; i < V; i++)
    {
        if ( ! sptSet[i] and dist[i] <= min)
        {
            min = dist[i];
            min_index = i;
        }
    }
    
    return min_index;
}

void printSolution(int * dist)
{
    printf("Vertex   Distance from source\n");
    
    for (int i = 0; i < V; i++)
    {
        printf("%d \t\t %d\n", i, dist[i]);
    }
}

int * dijkstra(int graph[V][V], int src)
{
    int * dist = new int[V];
    bool sptSet[V];
    
    queue<int> q[V];

    for (int i = 0; i < V; i++)
    {
        dist[i] = INT_MAX;
        sptSet[i] = false;
//        q[i] = new queue<int>;
    }
    
    dist[src] = 0;
    
    for (int count = 0; count < V-1; count++)
    {
        int u = minDistance(dist, sptSet);
        sptSet[u] = true;
        
        for (int v = 0; v < V; v++)
        {
            if ( ! sptSet[v] and graph[u][v] and dist[u] != INT_MAX
                and dist[u] + graph[u][v] < dist[v])
            {
                dist[v] = dist[u] + graph[u][v];
                q[v].push(v);
            }
        }
    }
    
    for (int i=0; i < V; i++)
    {
        while ( ! q[i].empty())
        {
            cout << q[i].front() << " -> ";
            q[i].pop();
        }
        cout << endl << endl;
    }
    
    return dist;
}

int shortestPath(int graph[V][V], int source, int destination)
{
    int * dist = dijkstra(graph, source);
    printSolution(dist);
    
    cout << endl << source << " -> " << destination << " : " << dist[destination] << endl;
    
    return dist[destination];
}

int main(int argc, const char * argv[])
{
    int graph[V][V] = {
        {0, 4, 0, 0, 0, 0, 0, 0},
        {0, 0, 8, 2, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 1, 3, 0},
        {0, 0, 3, 0, 7, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 3, 0},
        {0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 7},
        {0, 0, 0, 0, 0, 0, 0, 0}
    };
    
    shortestPath(graph, 0, 5);
    
    return 0;
}
