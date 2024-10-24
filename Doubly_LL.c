#include<stdio.h>
//#include<conio.h>
#include<process.h>
typedef struct node
{
int data;
struct node *prev;

struct node *next , *temp;
}node;

	node *start=NULL, *rear, *head, *temp2;

	void create()
	{
	node *prev;
	head = (node *)malloc(sizeof(node));
	printf("Enter data : ");
	scanf("%d",&head->data);

	head->prev=NULL;
	head->next=NULL;

	if(start==NULL)
		{
		start=head;
		rear=head;
		}
	else
		{
		head->prev=rear;
		rear->next=head;
		rear=head;
		}
	}

void insert_at_front()
	{
	node *newnode;
	newnode=(node *)malloc(sizeof(node));
	printf("Enter the data :");
	scanf("%d",&newnode->data);

	newnode->prev=NULL;
		if(start==NULL)
		{
		printf("Linked List is Empty");
		}
	else
		{
		newnode->next=start;
		start=newnode;
		}
		}

void insert_at_end()
	{
	node *endnode;
	 endnode=(node *)malloc(sizeof(node));
	 printf("Enter the data : ");
	 scanf("%d",&endnode->data);

	 endnode->next=NULL;

	 if(start==NULL)
		{
		 printf("Linked list is Empty");
		}

	 else
		{
		while(head->next==NULL)
		head->next=endnode;
		endnode->prev=head;
		}

	}

void Delete_at_first()
	{
	node *k , *temp;
	if(start==NULL)
		{
		printf("Linkedlist is Empty");
		}

	else
		{
		temp=start->next;
		k = start;
		start = temp;
		free(k);
	}
	}

void Delete_at_end()
	{
	node *last,*ptr;
	last=start;

	if(start==NULL)
		{
		printf("ERROR");
		}

      else if(last->next==NULL)
		{
		ptr=start;
		start=NULL;
		free(ptr);
		}
	else
	{
		while(last->next->next!=NULL)
			{
			last=last->next;
			}
	ptr=last->next;
	last->next=NULL;
	free(ptr);

	}
	}

void Delete_at_specific()
	{
	 int pos,i;
	 node *temp=NULL,*ptr=NULL;
		if(start==NULL)
			{
			printf("\nLinkList is empty");
			}
		else
			{
			printf("\nEnter position : ");
			scanf("%d",&pos);

				if(pos==1)
					{
					temp=start;
					start=start->next;
					free(temp);
					}

			else
			      {
				 temp=start;

			      for(i=1;i<pos-1;i++)
				  {
				  temp=temp->next;
				  }
				   ptr=temp->next;
				   temp->next=temp->next->next;
				   free(ptr);
			      }
		}
	 }




void display()
{
	node *temp2;
	temp2=start;
		if(start==NULL)
		{
		printf("\nLinkedlist is Empty");
		}

	  else
		   {
		   int pp=0;
		   while(temp2!=NULL)
			{
			printf("%d->\n",temp2->data);
			temp2=temp2->next;
			pp++;
			}
			printf("\nTotal Node %d",pp);
		   }

}


void sort()
{
node *i, *j;
int temp;
	for(i=start; i->next!=NULL; i=i->next)
	{
		for(j=i->next; j!=NULL; j=j->next)
		{
		if(i->data > j->data)
			{
			 temp = i -> data;
			 i -> data = j -> data;
			 j -> data = temp;
			}
		}
	}
}

	     int main()
	     {
	     int ch;
	     char choice;
	     //clrscr();
printf("******************** DOUBLY LINKED LIST *********************");
	     do
	     {
	     printf("\n1. Create");
	     printf("\n2. Display");
	     printf("\n3. Insert at front");
	     printf("\n4. Insert at End");
	     printf("\n5. Delete at first");
	     printf("\n6. Delete at End");
	     printf("\n7. Delete at specific");
	     printf("\n8. Sort");
	     printf("\n-------------------------------------");
	     printf("\n Enter Your Choice : ");
	     scanf("%d",&ch);

	switch(ch)
    {
	case 1:
		create();
		break;

	case 2:
		display();
		break;

	case 3:
		insert_at_front();
		break;

	case 4:
		insert_at_end();
		break;

	case 5:
		Delete_at_first();
		break;

	case 6:
		Delete_at_end();
		break;

	case 7:
		Delete_at_specific();
		break;

	case 8:
		sort();
		break;

		default:

	printf("\n Wrong Choice");

	     }
	     printf("\n Do You Want To Continue (Y/N) : ");
	     fflush(stdin);
	     scanf("%c",&choice);
	     }
	     while(choice=='y' || choice=='Y');
		//getch();
		return 0;
	 }