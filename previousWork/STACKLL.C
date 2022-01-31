#include <stdio.h>
#include <stdlib.h>
#include<conio.h>
//#define MAX 25

struct stack
{
    int data; //data of the node that needs to be stored
    struct stack *next; //address of the next node
};

struct stack *top = NULL;

void push()
{
     int num;
     struct stack *new_element;
     printf("Enter the number to be added in the stack:\n");
     scanf("%d",&num);

    new_element = (struct stack*)malloc(sizeof(struct stack));
    new_element -> data = num;
    if(top == NULL)
    {
	new_element -> next = NULL;
	top = new_element;
    }
    else
    {
	new_element -> next = top;
	top = new_element;
    }
}

void pop()
{
    struct stack *node;
    node = top;
    if(top == NULL)
    {
	printf("Stack underflow condition: please enter elements by pressing 1\n");
    }
    else
    {
	node = top;
	top = top -> next;
        printf("The number at the top that is %d has been deleted\n",node->data);
        free(node);
    }
}

void peek()
{
    if(top == NULL)
    {
	printf("\nNO element present to peek upon");
    }
    else
    {
      printf("%d \n",top->data);
    }
}

void display()
{
    struct stack *node;
    printf("The elements in the stack are: \n");
    node = top;
    if(top == NULL)
    {
	printf("stack is empty, nothing to display\n");
    }
    else
    {
	while(node != NULL)
	{
	    printf("%d \n",node->data);
	    node = node->next;

	}
    }
   // return top;
}

void main()
    {
	int val, option;
	clrscr();
	// printf("______________________\n");
	do
	{
	    printf("***************MENU***************\n");
	    printf("1-push \n");
	    printf("2-pop \n");
	    printf("3-peek \n");
	    printf("4-display \n");
	    printf("5-exit \n");
	    printf("Enter the operation you want to perform: \n");
	    scanf("%d", &option);

	    switch(option)
	    {
		case 1:
		{
		    push();
		    break;
		}

		case 2:
		{
		    pop();
		    break;
		}
		case 3:
		{
		    peek();
		    break;
		}
		case 4:
		{
		    display();
		    break;
                }
            } 
            
        }while(option != 5); 
           // return 0; 
}