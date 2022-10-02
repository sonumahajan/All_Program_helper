#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>
#include <assert.h>

struct node
{
    int a;
    struct node *next;
};

typedef struct node node;
void initialise(node *queue);
void display(node *first);
void push(node *p, int x);
int pop(node *first);
int top(node *first);
bool isEmpty(struct node *first);

void initialise(node *queue)
{
    queue->next = NULL;
    queue->a = 0;
}

void display(struct node *first)

{
    struct node *temp;
    temp = first->next;
    while (temp)
    {
        printf("%d  ", temp->a);
        temp = temp->next;
    }
    printf("\n");
}

bool isEmpty(struct node *first)
{
    if (first->next)
        return 0;
    else
        return 1;
}

void push(node *p, int x)
{
    node *temp = (node *)malloc(sizeof(node));
    assert(temp);
    temp->a = x;
    //printf("blah:%p\n",temp->address);
    temp->next = p->next;
    p->next = temp;
    //printf("blahh:%p\n",(p->next)->address);
}
int pop(node *p)
{

    node *temp = p->next;
    p->next = (p->next)->next;
    int r = temp->a;
    free(temp);
    return r;
}

int top(struct node *first)
{
    node *p = first->next;
    if (p == NULL)
        return -1;
    else
    {
        return p->a;
    }
}

int main()
{
    node *q = (node *)malloc(sizeof(node));
    initialise(q);
    int n = 15;
    int A[] = {3,8,4,9,1,5,2,6,0,43,54,38,82,21,7};
    push(q, A[0]);

    for (int i = 0; i < n; i++)
    {

        if (top(q) < A[i])
        {
            push(q, A[i]);
        }

        else if (top(q) > A[i])
        {
            while ((top(q) > A[i]) && !(isEmpty(q)))
            {
               
                printf("%d -> %d\n", pop(q), A[i]);
            }

            push(q, A[i]);
        }
    }

    while (!isEmpty(q))
    {
        printf("%d -> -1\n", pop(q));
        
    }
   
}
