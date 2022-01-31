#include<stdio.h>
#include<conio.h>
void main()
{
	int a;
	char ch[20];
	clrscr();
	gets(ch);
	a=0;
	while(ch[a]!='\0')
	{

		printf("%c",ch[a]);
		a++;
	}
	getch();
}