#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
typedef struct Tree{
	int data;
	struct Tree *left;
	struct Tree *right;
}node;
	
node *root=NULL;
node* createnode()
{
	node *n;
	n=(node*)malloc(sizeof(node));
	printf("\n\t\tEnter a value:- ");
	scanf("%d",&n->data);
	n->left=NULL;
	n->right=NULL;
	return(n);
}

node* insert(node *temp,node *h)
{
	if(h==NULL)
	{
		h=temp;
		printf("\n\t\tElement inserted : %d\n",h->data);
	}
	else if(temp->data==h->data)
	{
		return h;
	}
	else if(temp->data>h->data)
	{
		h->right=insert(temp,h->right);
	}
	else if(temp->data<h->data)
	{
		h->left=insert(temp,h->left);
	}
	return h;
}

void inorder(node *h)
{
	if(h!=NULL)
	{
		inorder(h->left);
		printf("%d   ",h->data);
		inorder(h->right);
	}
}

void preorder(node *h)
{
	if(h!=NULL)
	{
		
		printf("%d   ",h->data);
		preorder(h->left);
		preorder(h->right);
	}
}
void postorder(node *h)
{
	if(h!=NULL)
	{
		postorder(h->left);
		postorder(h->right);
		printf("%d   ",h->data);
	}
}
int menu()
{
	int choice;
	printf("\n\t\tENTER YOUR CHOICE:- ");
	scanf("%d",&choice);
	return(choice);
}

main()
{
	printf("\n1: Insert \n");
	printf("\n0: Traverse the Tree\n");
	while(1)
	{
		switch(menu())
		{
			case 1:
				node *temp;
				temp=createnode();
				node *h;
				h=root;
				root=insert(temp,h);
				break;
			case 0:
				
				if(root==NULL)
				{
					printf("\n\t\tNo node present in the tree\n");
				}
				else
				{
					printf("\n\t\tIn-Order traversal:- \n\n\t\t");
					inorder(root);
					printf("\n\t\tPre-Order traversal:- \n\n\t\t");
					preorder(root);
					printf("\n\t\tPost-Order traversal:- \n\n\t\t");
					postorder(root);
				}
				break;
			default:
				printf("\nPlease put a valid choice\n");
				break;
		}
	}
}