/*
 * Data Structures: Linear Data Structures (Queues)
 * Queue is a linear data structure that permits "insertion of new element" "at one end" and
   "deletion of an element" "at the other end".
 * The end at which the "deletion" of an element "take place" is called "front", and the end
   at which "insertion" of a new element "can take place" is called "rear".
 * Applications of queue as a data structure are even more common than applications of stacks.
 * While performing tasks on a computer, it is "often necessary to wait one’s turn"
   before having access to some device or process.
*/
#include<stdio.h>
#include<stdlib.h>

struct node
{
    int data;
    struct node *link;
};

struct queue
{
    struct node *front;
    struct node *rear;
};

void initqueue(struct queue *);
void addq(struct queue *, int);
int delq(struct queue *);
void delqueue(struct queue *);

int main()
{
    /* Queue As A Linked List */

    struct queue a;
    int i;

    system("clear");

    initqueue(&a);

    addq(&a, 11);
    addq(&a, -8);
    addq(&a, 23);
    addq(&a, 19);
    addq(&a, 15);
    addq(&a, 16);
    addq(&a, 28);

    i = delq(&a);
    if(i != -1)
        printf("Item extracted:%d\n", i);

    i = delq(&a);
    if(i != -1)
        printf("Item extracted:%d\n", i);

    i = delq(&a);
    if(i != -1)
        printf("Item extracted:%d\n", i);

    delqueue(&a);

    return 0;
}

/* Initialises data member */
void initqueue(struct queue *q)
{
    q->front = q->rear = NULL;
}

/* Adds an element to the queue */
void addq(struct queue *q, int item)
{
    struct node *temp;
    
    temp = (struct node *)malloc(sizeof(struct node));
    
    if(temp == NULL)
        printf("Queue is full.\n");
    
    temp->data = item;
    temp->link = NULL;

    if(q->front == NULL)
    {
        q->rear = q->front = temp;
        return;
    }

    q->rear->link = temp;
    q->rear = q->rear->link;
}

/* Removes an element from the queue */
int delq(struct queue *q)
{
    struct node * temp;
    int item;

    if(q->front == NULL)
    {
        printf("Queue is empty.\n");
        return -1;
    }

    item = q->front->data;
    temp = q->front;
    q->front = q->front->link;
    free(temp);

    return item;
}

/* Deallocates memory */
void delqueue(struct queue *q)
{
    struct node *temp;

    if(q->front == NULL)
        return;
    
    while(q->front != NULL)
    {
        temp = q->front;
        q->front = q->front->link;
        free(temp);
    }
}
