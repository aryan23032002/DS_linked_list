#include<stdio.h>
//#include<conio.h>
#include<process.h>

typedef struct node
	{
	int data;
	struct node *next;
	}node;

node *start=NULL, *head, *temp;
int count1=0, c;

void create()
{
head=(node *)malloc(sizeof(node));

printf("Enter Data : ");
scanf("%d",&head->data);
head->next=NULL;

if(start==NULL)

	{
	start=head;
	temp=head;
	}
else

	{
	temp->next=head;
	temp=head;
	}
}

/*void sort()
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
}  */
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
		   printf("%d->",temp2->data);
		   temp2=temp2->next;
		   pp++;
		   }
		   printf("\nTotal Node %d",pp);
		   }

}

       void insert_at_front()
       {

       head=(node *)malloc(sizeof(node));
       printf("Enter data : ");
       scanf("%d",&head->data);

	if(start==NULL)
		{
		head->next=start;
		start=head;
		}

		else
		{
		head->next=start;
		start=head;
		}
       }

void insert_at_last()
       {
       head = (node *)malloc(sizeof(node));
       printf("Enter Next Data : ");
       scanf("%d",&head->data);
       head->next=NULL;

       if(head==NULL)

       {
       printf("Unable to allocate memory");
       }

       else
       {
       temp->next=head;
       temp=head;
       }
       }


void count()
       {
	node *temp2;
	temp2=start;
	int pp=0;
		if(start==NULL)
		{
		printf("\nLinkedlist is Empty");
		}
	else
		   {
		   
	   while(temp2!=NULL)
		   {
		   temp2=temp2->next;
		   pp++;
		   }
		   printf("\nTotal Node %d\n",pp);
		   }
		   return pp;
       }
void insert_at_specific()
{
       int i, size=0, p;
       head = (node *)malloc(sizeof(node));
       printf("Enter Data : ");
       scanf("%d",&head->data);
       head->next=NULL;
       if(start==NULL)
       {
       printf("There is No Linkedlist");
       }
       else
       {        //size=count();
		printf("Enter Position for the : ");
		scanf("%d",&p);
		if((p==1))
		 {
			head->next=start;
			start=head;
		 }
		 else if(p==2)
		 {
		 head->next=start->next;
		 start->next=head;
		 }
			else
			{
			node *temp1=start;
				for(i=1;i<p-1;i++)
				{
				temp1=temp1->next;
				}
				head->next=temp1->next;
				temp1->next=head;
			}




	}

}

void del()
	{
	node *k;
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


void del_specific()
	{
	 int pos,i,size=0;
	 node *temp=NULL,*ptr=NULL;
		if(start==NULL)
		{
		printf("\nLinkList is empty");
		}
		else
		//size=count();
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



void del_at_last()
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


/*int reverse()
{
node *head
node *prev, *ptr, *next;
	prev = NULL;
	ptr = head->link;

	while(ptr!=NULL)
		{
		next = ptr->link;
		ptr->link=prev;
		prev=ptr;
		ptr=next;
		}
	head->link=prev;
	return head;
} */
   void main()
	{
	int ch;
	char choice;
	//clrscr();
		 printf("<----------- Singly Linked List ----------->");
	do
	{
	printf("\n        1. Create");
	printf("\n        2. Display");
	printf("\n        3. Insert At Front");
	printf("\n        4. count");
	printf("\n        5. Insert At last");
	printf("\n        6. Insert At specific");
	printf("\n        7. Delete of first");
	printf("\n        8. Delete at last");
	printf("\n        9. Delete Specific");
     //	printf("\n10. Sort");
    //	printf("\n11. Reverse");
	printf("\n------------------------------------------");
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
	count();
	//c=count();
       //	printf("\n total no. of nodes %d",c);
	break;

case 5:
	insert_at_last();
	break;

case 6:
	insert_at_specific();
	break;

case 7:
	del();
	break;

case 8:
	del_at_last();
	break;

case 9:
	del_specific();
	break; 

//case 10:
  //	sort();
//	break;

/*case 11:
	reverse();
	break;  */

	default:

	printf("\nWrong choice\n");
}

	printf("\n Do You Want to Continue (Y/N) : ");
	fflush(stdin);
	scanf("%c",&choice);
}

	while(choice=='y' ||  choice=='Y');
	//getch();
	}
