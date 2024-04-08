/*
 * Data Structures: Non-Linear Data Structures (Trees)
 * In a "linked list" "each node" has a "link" which points to "another node".
 * In a "tree" structure, however, "each node" may point to "several other nodes"
   (which may then point to several other nodes, etc.).
 * Although the nodes in a "general tree" may contain "any number of pointers" to
   the "other tree nodes", "a large number of data structures" have "at the most two pointers" to
   the "other tree nodes".
 * This type of a tree is called a "binary tree".
*/
#include<stdio.h>
#include<stdlib.h>

struct node
{
    struct node *left;
    char data;
    struct node *right;
};

struct node * buildtree(int);
void inorder(struct node *);

char arr[] = {'A','B','C','D','E','F','G','\0','\0','H'};
int lc[] = {1,3,5,-1,9,-1,-1,-1,-1,-1};
int rc[] = {2,4,6,-1,-1,-1,-1,-1,-1,-1};

int main()
{
    /* Binary Tree (Using Three Arrays):
     * A "binary tree" is a "finite set of elements" that is either "empty" or is partitioned into "three
       disjoint sub-sets".
     * The "first sub-set" contains a "single element" called the "root" of the tree.
     * The other "two sub-sets" are "themselves binary trees", called the "left and right sub-trees" of
       the original tree.
     * A "left or right sub-tree" can be empty.
    */

    struct node *root;

    system("clear");

    root = buildtree(0);

    printf("In-order Traversal:\n");
    inorder(root);
    printf("\n");

    return 0;
}

/* Recall that a "binary tree" is "recursive" in that "each sub-tree" is really a "binary tree" itself. */
struct node * buildtree(int index)
{
    struct node *temp = NULL;

    if(index != -1)
    {
        temp = (struct node *)malloc(sizeof(struct node));
        temp->left = buildtree(lc[index]);
        temp->data = arr[index];
        temp->right = buildtree(rc[index]);
    }

    return temp;
}

/* Recall that a "binary tree" is "recursive" in that "each sub-tree" is really a "binary tree" itself. */
void inorder(struct node *root)
{
    if(root != NULL)
    {
        inorder(root->left);
        printf("%c ", root->data);
        inorder(root->right);
    }
}
