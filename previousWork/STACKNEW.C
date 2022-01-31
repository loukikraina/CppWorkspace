#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<string.h>
int top=-1;
void push(int arr[],int v,int s,char sf[5])
{
	char e=v;
	if(top==s-1)     	
	{
		printf("\nStack overflow");
	}
	else
	{
		top++;
		if(strcmp(sf,"True")==0)
		arr[top]=e;
		else
		arr[top]=v;
	}
}
int pop(int arr[],char s[5])
{
	char v;
	int value,v1;
	if(top==-1)
	{
		printf("\nStack Underflow");
		return -1;
	}
	else
	{
		if(strcmp(s,"True")==0)
		{
			v=arr[top];
			v1=v;
		}
		else
		value=arr[top];
		top--;
		if(strcmp(s,"True")==0)
		return v1;
		else
		return value;
	}
}
int peek(int arr[])
{
	if(top==-1)
	{
		printf("\nStack is empty");
		return -1;
	}
	else
	return arr[top];
}
void display(int arr[])
{
	int a;
	if(top==-1)
	printf("\nStack is empty");
	else
	{
		for(a=top;a>=0;a--)
		printf("%d  ",arr[a]);
	}
}
void secondpro(int arr[],int s)
{
	int a,b,flag=1;
	char st[]="True";
	char str[100],val;
	printf("Enter the string\n");
	getch();
	scanf("%s",&str);
	for(a=0;a<strlen(str);a++)
	{
		if(str[a]=='('||str[a]=='{'||str[a]=='[')
		push(arr,str[a],s,st);
		if(str[a]==')'||str[a]=='}'||str[a]==']')
		{
			if(top==-1)
			flag=0;
			else
			{
				if(str[a]==')'&&arr[top]!='(')
				flag=0;
				if(str[a]=='}'&&arr[top]!='{')
				flag=0;
				if(str[a]==']'&&arr[top]!='[')
				flag=0;
				val=pop(arr,st);
				printf("\nLast popped-> %c\n",val);
			}
		}
	}
		if(flag==0)
		printf("\nUnbalanaced eq.");
		if(flag==1)
		printf("\nBalanced eq.");
		getch();
}
void main()
{	int value,op,arr[100],size,pro;
	clrscr();
	printf("Enter the size of your stack\n");
	scanf("%d",&size);
	printf("Value accepted, cannot be changed now.\nIt is -> %d\nPress enter now\n",size);
	getch();
	clrscr();
	printf("press 1 for 1st program and 2 for 2nd one\n");
	scanf("%d",&pro);
	if(pro==2)
	secondpro(arr,size);
	else if(pro==1){
	do
	{
		printf("\nEnter the option of your choice\n");
		printf("\n 1 for push");
		printf("\n 2 for pop");
		printf("\n 3 for peek");
		printf("\n 4 for display");
		printf("\n Any other no. to exit\n");
		scanf("%d",&op);
		switch(op)
		{
			case 1:
			printf("\n Enter number to be pushed in\n");
			scanf("%d",&value);
			push(arr,value,size,"False");
			break;
			case 2:
			value=pop(arr,"False");
			if(value!=-1)
			printf("\n The value deleted is -> %d\n",value);
			break;
			case 3:
			value=peek(arr);
			if(value!=-1)
			printf("\n The top value is -> %d\n",value);
			break;
			case 4:
			display(arr);
			break;
			default:op=0;
		}
		getch();
		clrscr();
	}while(op!=0);
	clrscr();
	printf("thanks for using the program");
	getch();
	}
	else
	printf("\nWrong option entered");
	getch();
}


