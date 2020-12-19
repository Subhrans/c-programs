#include<stdio.h>
#include<stdlib.h>

struct node{
	int data;
	struct node *addr;
}*head=NULL;
int c=0;
void display()
{
	struct node *temp;
	temp=head;
	if(head==NULL)
	{
		puts("list is empty");
	}
	else{
		while(temp)
		{
			printf("%d\t",temp->data);
			temp=temp->addr;
		}
		free(temp);
		temp=NULL;
		printf("\n");
	}
	
}
void Insertion_at_begining(int data)
{
	struct node *newNode;
	newNode=(struct node *)malloc(sizeof(struct node));
	newNode->data=data;
	if(head==NULL)
	{
		newNode->addr=NULL;
		head=newNode;
	}
	else
	{
		newNode->addr=head;
		head=newNode;
	}
	
}
void Insertion_at_end(int data)
{
	struct node *newNode;
   newNode = (struct node*)malloc(sizeof(struct node));
   newNode->data = data;
   newNode->addr = NULL;
   if(head == NULL)
   {
		head = newNode;
   }
   else
   {
      struct node *temp = head;
      while(temp->addr != NULL)
	  {
	  	temp = temp->addr;
	  }
      temp->addr = newNode;
   }
   printf("\nOne node inserted!!!\n");
}
void Insertion_at_specific_pos(pos,data)
{
	if(pos<=0)
	{
		puts("negetive indexing not allowed");
	}
	else if(pos>c+1)
	{
		printf("\nIndex out of Range! Range should be 1 to %d\n",c);
	}
	else
	{
		int count=1;
		struct node *temp=head,*temp1;
		temp1=(struct node *)malloc(sizeof(struct node));
		if(pos!=1)
		{
			count++;	
		}
		while(count!=pos)
		{
			temp=temp->addr;
			count++;
		}
//		temp1=temp->addr;
//		temp=temp->addr;
		temp1->data=data;
		
		temp1->addr=temp->addr;
		temp->addr=temp1;
	}
		
}
void Deletion_at_beg()
{
	struct node *temp;
	if(head==NULL)
	{
		puts("list is already Empty");
	}
	else if(head->addr==NULL)
	{
		free(head);
		head=NULL;
	}
	else
	{
		temp=head;
		head=head->addr;
		free(temp);	
	}
}
void Deletion_at_end()
{
//	puts("soon");
	struct node *temp;
	if(head==NULL)
	{
		puts("list is already Empty");
	}
	else if(head->addr==NULL)
	{
		free(head);
		head=NULL;
	}
	else
	{
		temp=head;
		while(temp->addr->addr!=NULL)
		{
			temp=temp->addr;
		
		}	
		free(temp->addr);
		temp->addr=NULL;
	}
	
}
void Deletion_at_pos(int pos)
{
	int count=1;
	struct node *temp=head,*temp1;
	if(pos==1 && head!=NULL)
	{
		if(pos==1 && temp->addr!=NULL)
		{
			temp=temp->addr;
			head=temp;
		}
		else if(pos==1 && temp->addr==NULL)
		{
			free(head);
			head=NULL;
			c=0;	
		}
		
	}
	else if(head==NULL)
	{
		printf("List is already Empty");
	}
	else
	{
		while(count!=pos)
		{
			temp1=temp;
			temp=temp->addr;	
			count++;
			c--;
		}
		temp1->addr=temp->addr;
		free(temp);
		temp=NULL;
	}
	
//	printf("%d %d",temp->data,temp1->data);
	
	
}
void Deletion_entire_list(){
	struct node *temp;
	temp=head;
	while(temp!=NULL)
	{
		temp=temp->addr;
		free(head);
		head=temp;
	}
	temp=NULL;
	head=NULL;
}
void Reversed_list()
{
	struct node *temp=head,*temp1=NULL;

	while(temp!=NULL)
	{
		temp=temp->addr;
		head->addr=temp1;
		temp1=head;
		head=temp;	
	}
	head=temp1;
}
void Reversed_list_byValue()
{
	struct node *temp;
	temp=head;
	int swap1,swap2;
	while(temp->addr!=NULL)
	{
		swap1=temp->data;
		temp->data=temp->addr->data;
		temp->addr->data=swap1;
		temp=temp->addr;
	}
}
void Reversed_list_byRecursive(struct node *temp)
{
	if(temp==NULL)
	{
		return;
	}
	else
	{
		Reversed_list_byRecursive(temp->addr);
		printf("%d\t",temp->data);
	}
}
int counts()
{
	struct node *temp=NULL;
	temp=head;
	while(temp!=NULL)
	{
		c++;
		temp=temp->addr;
	}
	free(temp);
	temp=NULL;
	return c;
}
int main()
{
	int i,n,d,c,m,pos,dele,x;
	struct node *temp=NULL;
	while(1)
	{
		puts("1.Insertion");
		puts("2.Deletion");
		puts("3.display");
		puts("4.exit");
		puts("5.count number of nodes");
		puts("6.Reversed list");
		puts("7.Reversed List using value");
		puts("8.Reversed List using Recursive");
		scanf("%d",&n);
		switch(n)
		{
			case 1:
				puts("1.Insertion at Begining");
				puts("2.Insertion at end");
				puts("3.Insertion at specific location");
				puts("4.back to main menu");
				scanf("%d",&m);
				switch(m)
				{
					case 1:
						puts("enter the value");
						scanf("%d",&d);
						Insertion_at_begining(d);
						break;
					case 2:
						puts("enter the value");
						scanf("%d",&d);
						Insertion_at_end(d);
						break;
					case 3:
						c=counts();
						puts("enter the value");
						scanf("%d",&d);
						puts("enter the position ");
						scanf("%d",&pos);
						Insertion_at_specific_pos(pos,d);
						break;
				}
				break;
			case 2:
				puts("1.Deletion_at_begining");
				puts("2.Deletion_at_end");
				puts("3.Deletion_at_specific position");
				puts("4.Delete whole list");
				scanf("%d",&dele);
				switch(dele)
				{
					case 1:
						Deletion_at_beg();
						break;
					case 2:
						Deletion_at_end();
						break;
					case 3:
						puts("Enter the position");
						scanf("%d",&pos);
						Deletion_at_pos(pos);
						break;
					case 4:
						Deletion_entire_list();
						break;
					default:
						puts("Invalid option");
						break;
				}
				
				break;
			case 3:
				display();
				break;
			case 4:
				exit(1);
			case 5:
				c=counts();
				printf("\ntotal number of nodes is: %d\n",c);
				break;
			case 6:
				Reversed_list();
				break;
			case 7:
				Reversed_list_byValue();
				break;
			case 8:
				temp=head;
				Reversed_list_byRecursive(temp);
//				printf("%d\t",x);
				temp=NULL;
				break;
			default:
				puts("Invalid input");
				break;
		}
	}
}
