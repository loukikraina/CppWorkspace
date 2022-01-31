#include<conio.h>
#include<stdio.h>
void main()
{
	clrscr();
	int a,b;
	char c[200];
	for(a=0;a<=127;a++)
	{
		printf("%c",a);
	}
	clrscr();
	b=0;
	do
	{
		c[b]=getch();
		if(c[b]!='\r')
		printf("%c",1);
		b++;
	}while(c[b-1]!='\r');
	c[b-1]='\0';
	printf("\n%s",c);
	getch();
}


