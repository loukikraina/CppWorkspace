#include<stdio.h>
#include<conio.h>
//#define N 5
// int queue[N];
// int front =-1;
// int rear=-1;

void enqueue();
void dequeue();
void peek();
void display();

struct queue
{
	int data;
	struct queue *next;
};
struct queue *start=NULL;


void enqueue(){

 //   if(rear==N-1){
	// printf("\n Queue Overflow");
 //    }
 	struct queue *new_node,*ptr;
 	int val;
 	ptr=start;
 	printf("\nEnter the value you want to enter:  ");
 	scanf("%d",&val);
	new_node=(struct queue *)malloc(sizeof(struct queue));
	new_node->data=val;
    new_node->next=NULL;
    if(ptr==NULL)
    	start=new_node;
	//printf("\nEnter the value you want to enter:  ");
	//scanf("%d",&queue[rear]);
	else
    {
    	while(ptr->next!=NULL)
    	{
    		ptr=ptr->next;
    	}
    	ptr->next=new_node;
	}
    
}

void dequeue(){

	struct queue *ptr;
	ptr=start;
    if (start==NULL)
    {
	printf("\n Queue Underflow");
    }
    else
    {
	printf("\nThe Value you removed is:  %d",start->data);
	start=start->next;
	free(ptr);
	}
}

void peek(){
    if(start==NULL){
	printf("\nThe queue is empty");
    }
    else{
	printf("\nThe element at the front of queue is: %d",start->data);
    }
}
void display(){
	struct queue *ptr;
	ptr=start;
	printf("\n");
    while(ptr!=NULL)
    {
    	printf("%d\t",ptr->data);
    	ptr=ptr->next;
    }	
}

// todo main Functions
void main(){
    int option;
    clrscr();
    do
    {
	printf("\n-------Main Menu-------");
	printf("\n 1. Enqueue");
	printf("\n 2. Dequeue");
	printf("\n 3. Peek");
	printf("\n 4. Display");
	printf("\n 5. Exit");
	printf("\n Enter your option: ");
	scanf("%d", &option);
	switch (option)
	{
	case 1: enqueue();
		break;

	case 2: dequeue();
		break;

	case 3: peek();
		break;

	case 4: display();
		break;

	}
    } while (option != 5);

}