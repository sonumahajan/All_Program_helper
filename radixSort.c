
Skip to content
Pull requests
Issues
Marketplace
Explore
@esh04
esh04 /
C-Codes
Private

1
0

    0

Code
Issues
Pull requests
Actions
Projects
Wiki
Security
Insights

    Settings

C-Codes/sorting/radixsort.c
@esh04
esh04 added files
Latest commit d13df6d on 21 May
History
1 contributor
87 lines (76 sloc) 1.64 KB
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <string.h>
#include <stdbool.h>
typedef struct Node
{
    long long int token;
    struct Node *next;
} Node;

void enqueue(Node *p, long long int x)
{
    Node *temp = (Node *)malloc(sizeof(Node));
    assert(temp);
    temp->token = x;
    temp->next = NULL;
    Node *t = p;
    while (t->next)
    {
        t = t->next;
    }
    t->next = temp;
}

int main()
{
    int n;
    long long int max = 0;
    scanf("%d", &n);
    long long int S[n];

    for (int i = 0; i < n; i++)
    {
        long long int temptoken = 0;

        scanf("%lld", &temptoken);
        if (temptoken > max)
            max = temptoken;

        S[i] = temptoken;
    }
////////////////////////////////////////////////////////
    Node *radix = (Node *)malloc(10 * (sizeof(Node)));
    assert(radix);
    for (int i = 0; i < 10; i++)
    {
        (radix + i)->token = 0;
        (radix + i)->next = NULL;
    }

    //printf("%lld\n", max);
    int temp = 0, index = 1;
    while (max != 0)
    {

        for (int i = 0; i < n; i++)
        {
            enqueue(radix + (S[i] / index) % 10, S[i]);
            S[i] = 0;
        }


          int counter = 0;
        for (int j = 0; j < 10; j++)
        {
            while ((radix + j)->next)
            {
                Node *temp = (radix + j)->next;
                (radix + j)->next = temp->next;
                S[counter] = temp->token;
                free(temp);
                counter++;
            }
        }

        max /= 10;
        temp++;
        index *= 10;
    }

    for (int i = 0; i < n; i++)
    {
        printf("%lld\n", S[i]);
    }
    return 0;
}

    © 2021 GitHub, Inc.
    Terms
    Privacy
    Security
    Status
    Docs

    Contact GitHub
    Pricing
    API
    Training
    Blog
    About

Loading complete
