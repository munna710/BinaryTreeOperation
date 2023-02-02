#include<stdio.h>
#include<conio.h>
#include<alloc.h>
typedef struct treenode* treepointer;
struct treenode
{
	int data;
	treepointer leftchild,rightchild;
};
void create();
treepointer root='\0';
void search(int);
void main()
{
	int choice,n;
	do
	{
		clrscr();
		printf("\n\tbinary tree operations\n");
		printf("\n\t\t1.create");
		printf("\n\t\t2.search");
		printf("\n\t\t3.exit");
		printf("\n\t\tenter your choice(1-3): ");
		scanf("%d",&choice);
		switch(choice)
		{
			case 1:create();
				break;
			case 2:if(root=='\0')printf("\ntree is empty... ");
			       else
			       {
					printf("\nenter the element: ");
					scanf("%d",&n);
					search(n);
			       }
			       break;

			default:continue;
		}
		getch();
	}
	while(choice!=3);

}
void create()
{
	int i,n=0,left;
	treepointer node,temp,p;
	if(root!='\0')
	{
		printf("\ntree altready exists");
		return;
	}

	printf("\nenter the number of nodes:");
	scanf("%d",&n);

	root=(treepointer)malloc(sizeof(*root));
	printf("enter %d nodes for binary search tree:\n",n);
	scanf("%d",&root->data);
	root->leftchild=root->rightchild=NULL;
	for(i=0;i<n-1;i++)
	{
		temp=(treepointer)malloc(sizeof(*temp));
		scanf("%d",&temp->data) ;
		temp->leftchild=temp->rightchild=NULL;
		node=root;
		while(node!='\0')
		{
			left=0;
			p=node;
			if(temp->data<node->data)
			{
				left=1;
				node=node->leftchild;
			}
			else
			node=node->rightchild;
		}
		if(left)
		p->leftchild=temp;
		else
		p->rightchild=temp;
	}
	printf("\n\nbinary search tree created with %d nodes...",n);
}
void search(int x)
{
	treepointer node;
	node=root;
	while(node!='\0')
	{
		if(node->data==x)
		{
			printf("\nelement is found");
			return;
		}
		if(x<node->data)
		node=node->leftchild;
		else
		node=node->rightchild;
	}
	printf("\nelement not found");
}

