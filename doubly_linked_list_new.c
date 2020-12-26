#include<stdio.h>
#include<stdlib.h>
struct node{
	struct node *prev;
	int data;
	struct node *next;
}*head=NULL;
int count=0;
void count_length()
{
	struct node *temp=head;
	int c=0;
	while(temp!=NULL)
	{
		c++;
		temp=temp->next;
	}
	count=c;
}
void Insertion_At_front(int data)
{
	struct node *newNode=NULL;
	newNode=malloc(sizeof(struct node));
	newNode->prev=NULL;
	newNode->data=data;
	newNode->next=NULL;
	if(head==NULL)
	{
		head=newNode;
	}
	else
	{
		head->prev=newNode;
		newNode->next=head;
		head=newNode;
	}
}
void Insertion_At_end(int data)
{
	struct node *newNode=NULL,*temp=head;
	newNode=malloc(sizeof(struct node));
	newNode->prev=NULL;
	newNode->data=data;
	newNode->next=NULL;
	if(head==NULL)
	{
		head=newNode;
	}
	else
	{
		while(temp->next!=NULL)
		{
			temp=temp->next;
		}
		temp->next=newNode;
		newNode->prev=temp;
	}
}
void Insertion_At_Specific_location(int data,int loc)
{
	struct node *newNode=NULL,*temp;
	int c=1;
	newNode=(struct node *)malloc(sizeof(struct node));
	newNode->prev=NULL;
	newNode->data=data;
	newNode->next=NULL;
	temp=head;
	count_length();
	if(loc>count)
	{
		printf("\nIndex out of range (0 to %d)\n",count);
		return;
	}
	while(c!=loc)
	{
		temp=temp->next;
		c++;
	}
	newNode->next=temp->next;
	newNode->prev=temp;
	temp->next=newNode;
}

void Deletion_at_front()
{
	struct node *temp=NULL;
	temp=head;
	if(temp==NULL)
	{
		puts("List is already Empty");
	}
	else
	{
		temp=temp->next;
	}
	head=temp;
	temp=NULL;
	free(temp);
}
void Deletion_at_end()
{
	struct node *temp=NULL,*prev=NULL;
	temp=head;
	if(temp==NULL)
	{
		puts("List is Already Empty");
	}
	else if(temp->next==NULL)
	{
		head=temp->next;
		free(temp);
		temp=NULL;
	}
	else
	{
		while(temp->next!=NULL)
		{
			prev=temp;
			temp=temp->next;
		}
		prev->next=temp->next;
		free(temp);
		temp=NULL;
	}
}
void Deletion_at_specific_location(int loc)
{
	int c=0;
	struct node *temp=NULL,*temp2=NULL,*temp3=NULL;
	temp=head;
	if(temp==NULL)
	{
		puts("List is already Empty");
	}
	elseif
	{
		temp=temp->next;
	}
	head=temp;
	temp=NULL;
	free(temp);
	while(c!=loc)
	{
		temp2=temp;
		temp=temp->next;
		c++;
	}
	if(temp->next==NULL)
	{
		puts("true");
		temp2=temp->prev;
		temp->prev=NULL;
		temp2->next=NULL;
	}
	else{
		temp->next->prev=temp2;
		temp2->next=temp->next;
		free(temp);
		
	}
	
//	temp2->next=temp->next->next;
//	temp->next=NULL;
//	temp2->prev=temp2;
//	temp->prev=NULL;
//	temp=NULL;
//	free(temp);
}


void display()
{
	struct node *temp=head;
	if(temp==NULL)
	{
		puts("List is Empty");
	}
	else
	{
		while(temp!=NULL)
		{
			printf("%d\t",temp->data);
			temp=temp->next;
		}
		printf("\n");
	}
	
}
int main()
{
	int n,val,loc;
	while(1)
	{
		puts("1.Insertion");
		puts("2.Deletion");
		puts("3.Display");
		puts("4.Exit");
		scanf("%d",&n);
		switch(n)
		{
			case 1:
				puts("-----Insertion Operation-----------");
				puts("1.At front");
				puts("2.At End");
				puts("3.at any location");
				scanf("%d",&n);
				switch(n)
				{
					case 1:
						puts("Enter a data (Integer type only)");
						scanf("%d",&val);
						Insertion_At_front(val);
						break;
					case 2:
						puts("Enter a data (Integer type only)");
						scanf("%d",&val);
						Insertion_At_end(val);
						break;
					case 3:
						puts("------Location by Index/postion----");
						puts("Enter a data (Integer type only)");
						scanf("%d",&val);
						puts("Enter the location");
						scanf("%d",&loc);
						Insertion_At_Specific_location(val,loc);
						break;
					default:
						puts("Invalid Input");
						break;
				}
				break;
			case 2:
				puts("---------- Deletion Operation --------------");
				puts("1.Deletion at Front");
				puts("2.Deletion at End");
				puts("3.Deletion at Specific Location");
				scanf("%d",&n);
				switch(n)
				{
					case 1:
						Deletion_at_front();
						break;
					case 2:
						Deletion_at_end();
						break;
					case 3:
						count_length();
						printf("Enter the location (start index 0 to %d)\n",count);
						scanf("%d",&loc);
						
						if(count-1<loc)
						{
							printf("\nIndex out of range (0 to %d)\n",count);
						}
						else if(loc < 0)
						{
							printf("\nIndex out of range (0 to %d)\n",count);
						}
						else
						{
							Deletion_at_specific_location(loc);
						}
						break;
					default:
						puts("Invalid Option");
						break;
				}
				break;
			case 3:
				display();
				break;
			case 4:
				exit(1);
			default:
				puts("Invalid input");
		}
	}
	
	display();
	return 0;
}
