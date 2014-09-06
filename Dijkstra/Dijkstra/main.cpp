//
//  main.cpp
//  Dijkstra
//  http://www.geeksforgeeks.org/greedy-algorithms-set-6-dijkstras-shortest-path-algorithm/
//
//  Created by Vladimir Kuzmov on 7/4/14.
//  Copyright (c) 2014 Vladimir Kuzmov. All rights reserved.
//

#include <iostream>
#include <limits.h>

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

void dijkstra(int graph[V][V], int src)
{
    int dist[V];
    bool sptSet[V];
    
    for (int i = 0; i < V; i++)
    {
        dist[i] = INT_MAX;
        sptSet[i] = false;
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
            }
        }
    }
    
    printSolution(dist);
}

int main(int argc, const char * argv[])
{
    /* Let us create the example graph discussed above */
//    int graph[V][V] = {
//        {0, 4, 0, 0, 0, 0, 0, 8, 0},
//        {4, 0, 8, 0, 0, 0, 0, 11, 0},
//        {0, 8, 0, 7, 0, 4, 0, 0, 2},
//        {0, 0, 7, 0, 9, 14, 0, 0, 0},
//        {0, 0, 0, 9, 0, 10, 0, 0, 0},
//        {0, 0, 4, 0, 10, 0, 2, 0, 0},
//        {0, 0, 0, 14, 0, 2, 0, 1, 6},
//        {8, 11, 0, 0, 0, 0, 1, 0, 7},
//        {0, 0, 2, 0, 0, 0, 6, 7, 0}
//    };
    
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
    
    dijkstra(graph, 0);
    
    return 0;
}

