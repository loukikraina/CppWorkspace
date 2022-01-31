#include<stdio.h>
#include<conio.h>
void main()
{
	clrscr();
	int a,b;
	char c;
	for(a=0;a<4;a++)
	{
		for(b=0;b<4;b++)
		{
			if(b<a)
			printf(" ");
			else
			printf("*");
		}
		printf("\n");
	}
	getch();
	clrscr();
	for(a=3;a>=0;a--)
	{
		c='A';
		for(b=0;b<4;b++)
		{
			if(b<a)
			printf(" ");
			else
			{
				printf("%c",c);
				c++;
			}
		}
		printf("\n");
	}
	getch();
	clrscr();
	for(a=0;a<4;a++)
	{
		c='A';
		for(b=0;b<7;b++)
		{
			if(b<4)
			{
				if(3-a>b)
				printf(" ");
				else
				{
					printf("%c",c);
					c++;
				}
			}
			else
			{
				if(3+a>=b)
				{
					c--;
					printf("%c",c-1);
				}
				else
				printf(" ");
			}
		}
		printf("\n");
	}
getch();
}


