#include<conio.h>
#include<stdio.h>
void main()
{
	int a,b;
	char ch='A';
	clrscr();
	for(a=1;a<=4;a++)
	{
		for(b=1;b<=4;b++)
		{
			if(b<=(5-a))
			{
				printf("%c ",ch);
				ch++;
			}
			else
			printf(" ");
		}
		printf("\n");
		ch='A';
	}
	getch();
	clrscr();
	for(a=1;a<=4;a++)
	{
		for(b=1;b<=4;b++)
		{
			if(b<=4-a)
			printf("  ");
			else
			printf("%d ",5-b);
		}
		printf("\n");
	}
	getch();
}


