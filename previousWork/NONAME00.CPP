#include<conio.h>
#include<stdio.h>
#include<string.h>
struct loukik
{
	int a,b;
	char ch[100];
};
void main()
{
	clrscr();
	loukik i;
	i.a=20;
	i.b=35;
	strcpy(i.ch,"hello my name is loukik raina");
	printf("%d, %d, %s",i.a,i.b,i.ch);
	getch();
}