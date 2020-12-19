#include<stdio.h>
struct node{
	int data;
	struct node *link;
};
void SRS_with_single_link(){
	struct node n1,n2;
//	initialization
	n1.data=10;
	n1.link=NULL;
	n2.data=20;
	n2.link=NULL;
	
//	linking n1 with n2
	n1.link=&n2;
	printf("%d",n1.link->data);
}
struct linknode{
	int data;
	struct linknode *prev_link;
	struct linknode *next_link;
};
void SRS_with_multiple_links(){
	struct linknode n1,n2,n3;
//	Initialization
	n1.data=10;
	n1.next_link=NULL;
	n1.prev_link=NULL;
	n2.data=20;
	n2.next_link=NULL;
	n2.prev_link=NULL;
	n3.data=30;
	n3.next_link=NULL;
	n3.prev_link=NULL;
	
//	Linking n1,n2,n3 by n1
	n1.next_link=&n2;
//	linking n1,n2,n3 by n2
	n2.next_link=&n3;
	n2.prev_link=&n1;
//	linking n1,n2,n3 by n3
	n3.prev_link=&n2;
	
//	printing values of n1,n2,n3 by n1;
	printf("%d\t",n1.data);
	printf("%d\t",n1.next_link->data);
	printf("%d\t",n1.next_link->next_link->data);
	//	printing values of n1,n2,n3 by n2;
	printf("\n%d\t",n2.prev_link->data);
	printf("%d\t",n2.data);
	printf("%d\t",n2.next_link->data);
	//	printing values of n1,n2,n3 by n3;
	printf("\n%d\t",n3.prev_link->prev_link->data);
	printf("%d\t",n3.prev_link->data);
	printf("%d\t",n3.data);
}
int main(){
	SRS_with_single_link();
	printf("\n\n");
	SRS_with_multiple_links();
	return 0;
}
