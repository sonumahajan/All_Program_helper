#include <stdio.h>
#define MAX 100

struct stack
{
    int a[MAX];
    int top;
} stk;

//function to push to stack
void push(struct stack *stk, int x)
{
    if (stk->top == MAX)
    {
        printf("Stack Overflow\n");
        return;
    }
    stk->a[++stk->top] = x;
}

//function to pop from stack
int pop(struct stack *stk)
{
    if (stk->top == -1)
    {
        printf("Stack Underflow\n");
        return -1;
    }
    return stk->a[stk->top--];
}

//function to pop top n elements from stack
void npop(struct stack *stk, int n)
{
    for (int i = 0; i < n; i++)
    {
        int r = pop(stk);
        // printf("r:%d\n",r);
        if(r < 0)
        {
            return;
        }

    }
}

//function to get nth value from top of stack without disturbing stack
int ntop(struct stack *stk, int n)
{
    int i = 0;
    struct stack stk1;
    stk1.top = -1;
    for(int i = 0; i < n - 1; i++)
    {
        int r = pop(stk);
        if(r < 0)
        {
            return -1;
        }
        push(&stk1,r);
    }
    int q = pop(stk);
    if(q < 0)
    {
        return -1;
    }
    push(&stk1,q);
    for(int i = 0; i < n; i++)
    {
        int r = pop(&stk1);
        if(r < 0)
        {
            return -1;
        }
        push(stk,r);
    }
    return q;
}

int nbottom(struct stack *stk, int n)
{
    int i = 0;
    struct stack stk1;
    stk1.top = -1;
    int max = stk->top;
    for(int i = 0; i < max - n + 1; i++)
    {
        int r = pop(stk);
        if(r < 0)
        {
            return -1;
        }
        push(&stk1,r);
    }
    int q = pop(stk);
    if(q < 0)
    {
        return -1;
    }
    push(&stk1,q);
    int max2 = stk1.top;
    for(int i = 0; i < max2 + 1; i++)
    {
        int r = pop(&stk1);
        if(r < 0)
        {
            return -1;
        }
        push(stk,r);
    }
    return q;
}

//print stack
void print(struct stack *stk)
{
    int i;
    if (stk->top == -1)
    {
        printf("Stack is empty\n");
        return;
    }
    for (i = stk->top; i >= 0; i--)
    {
        printf("%d\n", stk->a[i]);
    }
}

int main()
{
    stk.top = -1;
    for(int i = 1; i <= 10; i++)
    {
        push(&stk,i);
    }
    printf("Printing stack:\n");
    print(&stk);
    printf("\n");
    int y;
    y = ntop(&stk, 3);
    printf("Here Y will hold the value of the third element from the top\n");
    printf("value of Y is: %d\n", y);
    printf("\n");
    printf("Printing the stack after performing operation to show stack is undisturbed\n");
    print(&stk);
    printf("\n");
    int Y = nbottom(&stk, 3);
    printf("Here Y will hold the value of the third element from the bottom\n");
    printf("value of Y is: %d\n", Y);
    printf("\n");
    printf("Printing the stack after performing operation to show stack is undisturbed\n");
    print(&stk);
    printf("\n");
    int n;
    printf("How many elements do you want to pop from the stack: ");
    scanf("%d", &n);
    printf("\npopping %d values from the stack\n",n);
    npop(&stk, n);
    printf("Printing stack:\n");
    print(&stk);
}
