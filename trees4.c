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

#define TRUE 1
#define FALSE 0

struct btreenode
{
    struct btreenode *leftchild;
    int data;
    struct btreenode *rightchild;
};

void insert(struct btreenode **, int);

void del(struct btreenode **, int);
void search(struct btreenode **, int, struct btreenode **, struct btreenode **, int *);

void inorder(struct btreenode *);

int main()
{
    /* Operations On A Binary Search Tree */

    struct btreenode *bt;
    int i = 0, a[] = {11,9,13,8,10,12,14,15,7};

    bt = NULL;  /* empty tree */

    system("clear");

    while(i <= 8)
    {
        insert(&bt, a[i]);
        i++;
    }

    printf("Binary tree before deletion:\n");
    inorder(bt);

    del(&bt, 10);
    printf("\n");
    printf("Binary tree after deletion:\n");
    inorder(bt);

    del(&bt, 14);
    printf("\n");
    printf("Binary tree after deletion:\n");
    inorder(bt);

    del(&bt, 8);
    printf("\n");
    printf("Binary tree after deletion:\n");
    inorder(bt);

    del(&bt, 13);
    printf("\n");
    printf("Binary tree after deletion:\n");
    inorder(bt);

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
}

/* Deletes a node from the binary search tree */
void del(struct btreenode **root, int num)
{
    int found;
    struct btreenode *parent, *x, *xsucc;

    /* if tree is empty */
    if(*root == NULL)
    {
        printf("Tree is empty.\n");
        return;
    }

    parent = x = NULL;

    /* call to search function to find the node to be deleted */
    search(root, num, &parent, &x, &found);

    /* if the node to be deleted is not found */
    if(found == FALSE)
    {
        printf("Data to be deleted, not found.\n");
        return;
    }

    /* if the node to be deleted has two children */
    if(x->leftchild != NULL && x->rightchild != NULL)
    {
        parent = x;
        xsucc = x->rightchild;

        while(xsucc->leftchild != NULL)
        {
            parent = xsucc;
            xsucc = xsucc->leftchild;
        }

        x->data = xsucc->data;
        x = xsucc;
    }

    /* if the node to be deleted has no child */
    if(x->leftchild == NULL && x->rightchild == NULL)
    {
        if(parent->rightchild == x)
            parent->rightchild = NULL;
        else
            parent->leftchild = NULL;
        
        free(x);
        return;
    }

    /* if the node to be deleted has only rightchild */
    if(x->leftchild == NULL && x->rightchild != NULL)
    {
        if(parent->leftchild == x)
            parent->leftchild = x->rightchild;
        else
            parent->rightchild = x->rightchild;
        
        free(x);        
        return;
    }

    /* if the node to be deleted has only leftchild */
    if(x->leftchild != NULL && x->rightchild == NULL)
    {
        if(parent->leftchild == x)
            parent->leftchild = x->leftchild;
        else
            parent->rightchild = x->leftchild;
        
        free(x);        
        return;
    }
}

/* Returns the address of the node to be deleted, address of its parent and
   whether the node is found or not */
void search(struct btreenode **root, int num, struct btreenode **par, struct btreenode **x, int *found)
{
    struct btreenode *q;

    q = *root;
    *found = FALSE;
    *par = NULL;

    while(q != NULL)
    {
        /* if the node to be deleted is found */
        if(q->data == num)
        {
            *found = TRUE;
            *x = q;
            return;
        }

        *par = q;

        if(q->data > num)
            q = q->leftchild;
        else
            q = q->rightchild;
    }
}

/* Traverse a binary search tree in a LDR (Left-Data-Right) fashion */
void inorder(struct btreenode *sr)
{
    if(sr != NULL)
    {
        inorder(sr->leftchild);
        /* print the data of the node whose leftchild is NULL or the path has already been traversed */
        printf("%d\t", sr->data);
        inorder(sr->rightchild);
    }
}
