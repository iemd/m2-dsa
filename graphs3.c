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

struct lledge
{
    int v1, v2;
    float cost;
    struct lledge *next;
};

int stree[5];    /* Holds the information about the vertex and its parent */
int count[5];    /* Indicates whether the vertex is included in the tree or not */
float mincost;   /* Counts the total minimum cost of the spanning tree */

struct lledge * kminstree(struct lledge *, int);

int getrval(int);
void combine(int, int);

void del(struct lledge *);

int main()
{
    /* Kruskal's Algorithm (One method to determine a "minimum cost spanning tree" has been given by Kruskal) */

    struct lledge *temp, *root;
    int i;

    system("clear");

    root = (struct lledge *)malloc(sizeof(struct lledge));

    root->v1 = 4;
    root->v2 = 3;
    root->cost = 1;
    temp = root->next = (struct lledge *)malloc(sizeof(struct lledge));

    temp->v1 = 4;
    temp->v2 = 2;
    temp->cost = 2;
    temp->next = (struct lledge *)malloc(sizeof(struct lledge));

    temp = temp->next;
    temp->v1 = 3;
    temp->v2 = 2;
    temp->cost = 3;
    temp->next = (struct lledge *)malloc(sizeof(struct lledge));

    temp = temp->next;
    temp->v1 = 4;
    temp->v2 = 1;
    temp->cost = 4;
    temp->next = NULL;

    root = kminstree(root, 5);

    for(i=1; i<=4; i++)
        printf("stree[%d]->%d\n", i, stree[i]);

    printf("The minimum cost of spanning tree is %f\n", mincost);

    del(root);

    printf("\n");

    return 0;
}

/* Forms the minimum cost spanning tree */
struct lledge * kminstree(struct lledge *root, int n)
{
    struct lledge *temp = NULL;
    struct lledge *p, *q;
    int noofedges = 0;
    int i, p1, p2;

    for(i=0; i<n; i++)
        stree[i] = i;    /* The root vertex holds itself as parent */

    for(i=0; i<n; i++)
        count[i] = 0;

    while((noofedges < (n-1)) && (root != NULL))
    {
        p = root;

        root = root->next;

        p1 = getrval(p->v1);
        p2 = getrval(p->v2);
        
        if(p1 != p2)
        {
            combine(p->v1, p->v2);

            noofedges++;
            mincost += p->cost;

            if(temp == NULL)
            {
                temp = p;
                q = temp;
            }
            else
            {
                q->next = p;
                q = q->next;
            }

            q->next = NULL;
        }
    }

    return temp;
}

/* Returns the parent of a particular vertex */
int getrval(int i)
{
    int j, k, temp;
    k = i;

    while(stree[k] != k)
        k = stree[k];

    j = i;

    while(j != k)
    {
        temp = stree[j];
        stree[j] = k;
        j = temp;
    }

    return k;
}

/* Inserts the edges and establishes the relation between the vertices */
void combine(int i, int j)
{
    if(count[i] < count[j])
        stree[i] = j;
    else
    {
        stree[j] = i;

        if(count[i] == count[j])
            count[j]++;
    }
}

/* De-allocates the dynamically allocated memory */
void del(struct lledge *root)
{
    struct lledge *temp;

    while(root != NULL)
    {
        temp = root->next;

        free(root);

        root = temp;
    }
}
