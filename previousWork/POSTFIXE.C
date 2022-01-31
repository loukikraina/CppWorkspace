#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<conio.h>
#include<math.h>
int top=-1;
char stack[100],postfix[100];
void push(int a,int size)
{
	if(top==size-1)
	{
		printf("stack overflow\n");
		getch();
		exit(1);
	}
	else
	{
		top++;
		stack[top]=a;
	}
}
float pop()
{
	int r;
	if(top!=-1)
	{
		r=stack[top];
		top--;
		return r;
	 }
	else
	{
	printf("\nStack underflow!!!!");
	getch();
	exit(1);
	return 1;
	}

}
int op(int a,int b,char ch)
{

	printf("\nCase ---> %d, %d, %c\n",a,b,ch);
	switch(ch)
	{
		case'^':
		return pow(a,b);
		case'/':
		return a/b;
		case'*':return a*b;
		case'+':return a+b;
		case'-':return a-b;
		default:
		{
		printf("\nWrong operator added");
		getch();
		exit(1);
		return 1;
		}
	}
}
int braces(char s[100])
{
	int lb=0,rb=0,i;
	for(i=0;i<strlen(s);i++)
	{
		if(s[i]=='(')
		lb++;
		else if(s[i]==')')
		rb++;
	}
	if(lb==rb)
	return 0;
	else if(lb<rb)
	return 1;
	else
	return -1;
}

void main()
{
	int chk,w=0,size,tag,x;
	int y,z,a;
	//char num[5];
	//const char *str1;
	clrscr();
	printf("Enter the size of postfix exp \n");
	scanf("%d",&size);
	printf("Enter the postfix expression\nPress ')' at the end of exp\n");
	while(1)
	{
		scanf("%c",&postfix[w]);
		if(postfix[w]==')')
		break;
		if(postfix[w]!='^'&&postfix[w]!='*'&&postfix[w]!='/'&&postfix[w]!='+'&&postfix[w]!='-')
		{
			//sscanf(postfix[w],"%d",&x);
			//str1=postfix[w];
			//x=atoi(str1);
			x=(int)postfix[w];
			printf("\n the value of x is ---- > %d",x-48);
			push((int)postfix[w]-48,size);
		}
		else
		{
			y=pop();
			z=pop();
			a=op(z,y,postfix[w]);
			push(a,size);
		}
	}
	printf("\nThe result is  ----- > %f",pop());
	getch();
}/*



	gets(postfix);
	chk=braces(postfix);
	if(chk!=0)
	{
		printf("Unbalanced braces\n");
		if(chk==-1)
		printf("right braces are more\n");
		else
		printf("left braces are more\n");
	}
	for(i=0;i<strlen(postfix);i++)
	{
		if(postfix[i]!=' '&&postfix[i]!='('&&postfix[i]!=')'&&postfix[i]!='^'&&postfix[i]!='*'&&postfix[i]!='/'&&postfix[i]!='+'&&postfix[i]!='-')
		c++;
	}
	for(i=0;i<strlen(postfix);i++)
	{
		if(postfix[i]!='('&&postfix[i]!=')')
		continue;
		if(postfix[i]==' ')
		{
			tag++;
			if(tag==2)
			tag=0;
		}
		else if(postfix[i]!='^'&&postfix[i]!='*'&&postfix[i]!='/'&&postfix[i]!='+'&&postfix[i]!='-')
		{
		       /*	if(tag==1)
			{
				strncat(num,&postfix[i],1);
			}
			x=postfix[i]-'0';
			printf("\naaaa---->  %f\n",x);
			push(x,c);
		}
		else
		{
			y=pop();
			z=pop();
			a=op(z,y,postfix[i]);
		}
	}
	printf("\nThe result is ---> %f",a);
	getch();
}                         */



