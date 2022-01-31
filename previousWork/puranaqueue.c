#include<stdio.h>
#define N 5
int queue[N];
int front =-1;
int rear=-1;

void enqueue();
void dequeue();
void peek();
void display();


void enqueue(){

   if(rear==N-1){
	printf("\n Queue Overflow");
    }

    else if(rear==-1 && front==-1 ){
	front++;
	rear++;
	printf("\nEnter the value you want to enter:  ");
	scanf("%d",&queue[rear]);
    }
    else{
	rear++;
	printf("\nEnter the value you want to enter:  ");
	scanf("%d", &queue[rear]);
    }
}

void dequeue(){

    if (rear == - 1 && front == -1)
    {
	printf("\n Queue Underflow");
    }
     else if (rear == front)
    {
	printf("\nThe Value you removed is:  %d",queue[front]);
	front = -1;
	rear = -1;

    }
    else
    {
	printf("\nThe Value you removed is:  %d", queue[front]);
	front++;
    }
}

void peek(){
    if(front==-1){
	printf("\nThe queue is empty");
    }
    else{
	printf("\nThe element at the front of queue is: %d",queue[front]);
    }
}

// todo display Function
void display(){
	int i;
    for(i=0;i<N;i++){
	if(queue[i]==0)
	break;
	printf("\n%d",queue[i]);
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