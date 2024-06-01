/* Data Structures: Non-Linear Data Structures (Graphs)
 * A graph consists of two sets v and e where, v is a finite, non-empty "set of vertices"
   and e is a "set of pairs of vertices".
 * The pairs of vertices are called "edges".
 * A graph can be of two types: "Undirected graph" and "Directed graph".
 * The most commonly used representations for graphs are "Adjacency matrices" and "Adjacency lists".
 * Given the "root node" of a binary tree, one of the most common operations performed is "visiting every node
   of the tree in some order".
 * Similarly, given a "vertex" in a directed or undirected graph "we may wish to visit all vertices
   in the graph that are reachable from this vertex".
 * This can be done in two ways—using the "Depth First Search" and the "Breadth First Search" algorithm.
*/
#include<stdio.h>
#include<stdlib.h>

#define INF 9999

int main()
{
    /* Dijkstra's Algorithm (The algorithm to find a "shortest path" was first proposed by E.W.Dijkstra) */

    int arr[4][4];
    int cost[4][4] = {
                        7, 5, 0, 0,
                        7, 0, 0, 2,
                        0, 3, 0, 0,
                        4, 0, 1, 0
                    };
    int i, j, k, n = 4;

    system("clear");

    for(i=0; i<n; i++)
    {
        for(j=0; j<n; j++)
        {
            if(cost[i][j] == 0)
                arr[i][j] = INF;
            else
                arr[i][j] = cost[i][j];
        }
    }

    printf("Adjacency matrix of cost of edges:\n");
    for(i=0; i<n; i++)
    {
        for(j=0; j<n; j++)
            printf("%d\t", arr[i][j]);
        printf("\n");
    }

    for(k=0; k<n; k++)
    {
        for(i=0; i<n; i++)
        {
            for(j=0; j<n; j++)
            {
                if(arr[i][j] > arr[i][k] + arr[k][j])
                    arr[i][j] = arr[i][k] + arr[k][j];
            }
        }
    }

    printf("\n");
    
    printf("Adjacency matrix of lowest cost between the vertices:\n");
    for(i=0; i<n; i++)
    {
        for(j=0; j<n; j++)
            printf("%d\t", arr[i][j]);
        printf("\n");
    }

    printf("\n");

    return 0;
}
