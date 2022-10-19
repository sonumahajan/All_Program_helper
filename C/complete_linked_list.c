#include <process.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct linked_list
{
    /* data */
    int data;
    struct linked_list *next;
} node;

int num = 0;
node *start, *last, *temp;

void linked_list();
void insertion_first();
void insertion_mid();
void insertion_end();
void deletion_first();
void deletion_mid();
void deletion_end();
void display();
void create_node()
{
    temp = (node *)malloc(sizeof(node));
    printf("\nEnter a element in link list\n");
    scanf("%d", &temp->data);
    temp->next = NULL;
    num++;
}

int main(int argc, char const *argv[])
{
    while (1)
    {
        int n;
        printf("Enter a number: \n1->Normal Link List\n2-> Insertion At First\n3-> Insertion At Mid\n4->Insertion At Last\n5-> Deletion At First\n6-> Deletion At Mid\n7-> Deletion At Last\n8-> Display Numbers\n9->Exit The Program\n");
        scanf("%d", &n);
        /* code */
        switch (n)
        {
        case 1:
            /* code */
            linked_list();
            break;

        case 2:
            /* code */
            insertion_first();
            break;

        case 3:
            /* code */
            insertion_mid();
            break;

        case 4:
            /* code */
            insertion_end();
            break;
        case 5:
            /* code */
            deletion_first();
            break;
        case 6:
            /* code */
            deletion_mid();
            break;
        case 7:
            /* code */
            deletion_end();
            break;

        case 8:
            /* code */
            display();
            break;
        case 9:
            /* code */
            exit(0);
            break;

        default:
            printf("\nError\n");
            break;
        }
    }
    return 0;
}

void linked_list()
{

    int i, n;
    printf("Enter how many node do you want to make \n");
    scanf("%d", &n);
    for (i = 1; i <= n; i++)
    {
        create_node();
        if (start == NULL)
        {
            start = temp;
            last = temp;
        }
        else
        {
            last->next = temp;
            last = temp;
        }
    }
}

void insertion_first()
{
    create_node();
    if (start == NULL)
    {
        start = temp;
        last = temp;
    }
    else
    {
        temp->next = start;
        start = temp;
    }
}

void insertion_mid()
{
    create_node();
    if (start == NULL)
    {
        start = temp;
        last = temp;
    }
    else
    {
        int pos;
        printf("\nEnter a position to enter an element:\n");
        scanf("%d", &pos);
        if (num < pos)
        {
            /* code */
            printf("\nNot possible\n");
        }
        else
        {
            if (num == pos)
            {
                /* code */
                last->next = temp;
                last = temp;
            }
            else
            {
                node *p, *q;
                p = start;
                for (int i = 1; i < pos - 1; i++)
                {
                    /* code */
                    p = p->next;
                }
                q = p->next;
                p->next = temp;
                temp->next = q;
                /*By using single pointer
                temp->next=p->next;
                p->next=temp;*/
            }
        }
    }
}

void insertion_end()
{
    create_node();
    if (start == NULL)
    {
        start = temp;
        last = temp;
    }
    else
    {
        last->next = temp;
        last = temp;
    }
}

void deletion_first()
{
    if (start == NULL)
    {
        /* code */
        printf("Not possible");
    }
    else
    {
        temp = start;
        start = start->next;
        free(temp);
        temp = NULL;
        num--;
    }
    if (start == NULL)
    {
        /* code */
        last = NULL;
    }
}

void deletion_mid()
{
    if (start == NULL)
    {
        /* code */
        printf("Not possible \n");
    }
    else
    {
        int pos;
        node *w, *x;
        printf("Enter a position to delete value");
        scanf("%d", &pos);
        w = start;
        for (int i = 1; i < pos - 1; i++)
        {
            /* code */
            w = w->next;
            x = w->next;
        }
        w->next = x->next;
        free(x);
        x = NULL;
    }
}

void deletion_end()
{
    if (start == NULL)
    {
        /* code */
        printf("Underflow");
    }
    else
    {
        if (start == last)
        {
            /* code */
            free(start);
            start = NULL;
            last = NULL;
            num--;
        }
        else
        {
            node *v;
            v = start;
            while (v->next != last)
            {
                /* code */
                v = v->next;
            }
            free(last);
            last = v;
            last->next = NULL;
            v = NULL;
            num--;
        }
    }
}

void display()
{
    temp = start;
    while (temp != NULL)
    {
        printf("\n %d \n", temp->data);
        temp = temp->next;
    }
    temp == NULL;
    free(temp);
}
