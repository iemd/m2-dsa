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

struct btreenode
{
    struct btreenode *leftchild;
    int data;
    struct btreenode *rightchild;
};

void insert(struct btreenode **, int);

void inorder(struct btreenode *);
void preorder(struct btreenode *);
void postorder(struct btreenode *);

int main()
{
    /* Binary Search Tree:
     * Many "algorithms" that use "binary trees" proceed in "two phases".
     * The "first phase builds a binary tree", and the "second traverses the tree".
    */
    
    struct btreenode *bt;
    int req, i = 1, num;

    bt = NULL;  /* empty tree */

    system("clear");

    printf("Specify the number of items to be inserted:");
    scanf("%d", &req);

    while(i++ <= req)
    {
        printf("Enter the data:");
        scanf("%d", &num);

        insert(&bt, num);
    }

    printf("\n");
    printf("In-order Traversal:\n");
    inorder(bt);

    printf("\n");
    printf("Pre-order Traversal:\n");
    preorder(bt);

    printf("\n");
    printf("Post-order Traversal:\n");
    postorder(bt);

    printf("\n");
        
    return 0;
}

/* Inserts a new node in a binary search tree */
void insert(struct btreenode **sr, int num)
{
    if(*sr == NULL)
    {
        *sr = (struct btreenode *)malloc(sizeof(struct btreenode));

        (*sr)->leftchild = NULL;
        (*sr)->data = num;
        (*sr)->rightchild = NULL;

        return;
    }
    else    /* search the node to which new node will be attached */
    {
        /* if new data is less, traverse to left */
        if(num < (*sr)->data)
            insert(&((*sr)->leftchild), num);
        else
            /* else traverse to right */
            insert(&((*sr)->rightchild), num);
    }

    return;
}

/* Traverse a binary search tree in a LDR (Left-Data-Right) fashion */
void inorder(struct btreenode *sr)
{
    if(sr != NULL)
    {
        inorder(sr->leftchild);
        /* print the data of the node whose leftchild is NULL or the path has already been traversed */
        printf("%d ", sr->data);
        inorder(sr->rightchild);
    }
    else
        return;
}

/* Traverse a binary search tree in a DLR (Data-Left-Right) fashion */
void preorder(struct btreenode *sr)
{
    if(sr != NULL)
    {
        /* print the data of a node */
        printf("%d ", sr->data);
        /* traverse till leftchild is not NULL */
        preorder(sr->leftchild);
        /* traverse till rightchild is not NULL */
        preorder(sr->rightchild);
    }
    else
        return;
}

/* Traverse a binary search tree in LRD (Left-Right-Data) fashion */
void postorder(struct btreenode *sr)
{
    if(sr != NULL)
    {       
        postorder(sr->leftchild);        
        postorder(sr->rightchild);
        printf("%d ", sr->data);
    }
    else
        return;
}
