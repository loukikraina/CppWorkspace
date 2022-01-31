#include<stdio.h>
#include<ctype.h>
#include<stdlib.h>
#include<conio.h>
#define MAX 100

int stack[MAX];
int top = -1;

void push(int value)
{
    top++;
    stack[top]=value;
}

int pop()
{
    int m;
    m = stack[top];
    top--;
    return m;
}

void main()
{
    char postfix[MAX], temp;
    int num1, num2, result,n;
    int i = 0;
    clrscr();
    printf("enter the postfix expression ---> \n");
    gets(postfix);
    while(postfix[i] != '\0')
    {
	temp = postfix[i];
	if(isdigit(postfix[i])) //the statement only accepts numbers //
	{
	    temp = postfix[i] - '0';
	    push(temp);
	}
	else
	{
	    num2=pop();
	    num1=pop();
	    switch(temp)
	    {
		case '+':
		result = num1 + num2;
		break;

		case '-':
		result = num1 - num2;
		break;

		case '*':
		result = num1 * num2;
		break;

		case'/':
		result = num1 / num2;
		break;

		default:
		{
			printf("Wrong operator");
			exit(1);
		}


	    }
	    push(result);
	}
	i++;
    }
   result = pop();
    printf("the result is ----> %d",result);
    getch();
}