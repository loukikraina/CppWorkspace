#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<conio.h>
#include<ctype.h>
const int size=50;
char infix[size],postfix[size],stack[size];
int top=-1;
int precedence(char ch)
{
	switch(ch)
	{
		case'^':
		return 5;
		case'/':
		return 4;
		case'*':
		return 4;
		case'+':return 3;
		case'-':return 3;
		default:return 0;
	}
}
char pop()
{
	char r;
	if(top!=-1)
	{
		r=stack[top];
		top--;
		return r;
	}
	else
	return '#';
}
char telement()
{
	char ch;
	if(top==-1)
	ch='#';
	else
	ch=stack[top];
	return ch;
}
void push(char ch)
{
	if(top==size-1)
	printf("stack overflow\n");
	else
	{
		top++;
		stack[top]=ch;
	}
}
int braces(char *s)
{
	int lb=0,rb=0;
	for(int i=0;i<strlen(s);i++)
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
	char ele,elem;
	int prep,pre,popped,j=0,chk=0;
	clrscr();
	strcpy(postfix," ");
	printf("Enter infix exp.\n");
	gets(infix);
	chk=braces(infix);
	if(chk!=0)
	{
		printf("Unbalanced braces\n");
		if(chk==-1)
		printf("right braces are more\n");
		else
		printf("left braces are more\n");
	}
	for(int i=0;i<strlen(infix);i++)
	{
		if(infix[i]!='('&&infix[i]!=')'&&infix[i]!='^'&&infix[i]!='*'&&infix[i]!='/'&&infix[i]!='+'&&infix[i]!='-')
		postfix[j++]=infix[i];
		else if(infix[i]=='(')
		{
			push(infix[i]);
		}
		else if(infix[i]==')')
		{
			while((popped=pop())!='(')
			postfix[j++]=popped;
		}
		else
		{
			elem=infix[i];
			pre=precedence(elem);
			ele=telement();
			prep=precedence(ele);
			if(pre>prep)
			push(elem);
			else
			{
				while(prep>=pre)
				{
					if(ele=='#') break;
					popped=pop();
					ele=telement();
					postfix[j++]=popped;
					prep=precedence(ele);
				}
				push(elem);
			}
		}
	}
	while((popped=pop())!='#')
	postfix[j++]=popped;
	postfix[j]='\0';
	printf("\nHere is the postfix of the infix --->\n\n");
	textcolor(11);
	//puts(postfix);
	cprintf("%s",postfix);
	getch();
}

