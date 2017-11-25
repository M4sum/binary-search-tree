#include<stdio.h>
#include<stdlib.h>
typedef struct node
{
	int a;
	struct node *lptr;
	struct node *rptr;
}tree;
tree *tr, *trs, *temp, *head;
void insert(tree *root,int i)
{
	temp=(tree *)malloc(sizeof(tree));
	temp->a=i;
	temp->lptr=NULL;
	temp->rptr=NULL;
	if(head==NULL)
	{
		head=temp;
	}
	else
	{
		if(i>root->a)
		{
			if(root->rptr==NULL)
			{
			root->rptr=temp;
			}
			else 
			insert(root->rptr,i);
		}
		else
		{
			if(root->lptr==NULL)
			{
			root->lptr=temp;
			}
			else
			insert(root->lptr,i);
		}
	}
}
void pre(tree *t)
{
	if(t!=NULL)
   {
    printf("%d ",t->a);
    pre(t->lptr);
    pre(t->rptr);
   }
}
void in(tree *t)
{
	if(t!=NULL)
   {
   	in(t->lptr);
    printf("%d ",t->a);
    in(t->rptr);
   }
}
void post(tree *t)
{
	if(t!=NULL)
   {
    printf("%d ",t->a);
    post(t->lptr);
    post(t->rptr);
   }
}
deletes(tree *root,int i)
{
	int c=0;
	if(i==root->a)
	{
		if(root->lptr==NULL)
		{
			if(c==1)
				trs->rptr=NULL;
			else
				trs->lptr=NULL;
			free(root);
			return;
		}
		temp=root;
		root=root->lptr;
		if(root->rptr==NULL)
		{
			temp->a=root->a;
			free(root);
			temp->lptr=NULL;
		}
		else
		{
			while(root->rptr->rptr!=NULL)
			{
				root=root->rptr;
			}
			tr=root->rptr;
			temp->a=root->rptr->a;
			root->rptr=root->rptr->lptr;
			free(tr);
		}
	}
	else if(i>root->a)
	{
		trs=root;
		c=1;
		deletes(root->rptr,i);
	}
	else if(i<root->a)
	{
		trs=root;
		deletes(root->lptr,i);
	}
}
int main()
{
	int c,i;
	head=NULL;
	while(1)
	{
	printf("enter a choice:\n1.insert\n2.delete");
	scanf("%d",&c);
	switch(c)
	{
		case 1: printf("enter value:");
				scanf("%d",&i);
				insert(head,i);
				break;
		case 2: printf("enter the value to be deleted");
				scanf("%d",&i);
				deletes(head,i);
				break;
		case 3://in(head);
				pre(head);
			//	post(head);
				break;
		case 4: exit(0);
		default: return 0;
	}
	}
}
