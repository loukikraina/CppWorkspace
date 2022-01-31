#include<conio.h>
#include<stdio.h>
void main()
{
	int a,b,sum=0,d,rev=0,c;
	clrscr();
	printf("Enter the no.:\n");
	scanf("%d",&a);
	d=a;
	while(d!=0)
	{
		b=d%10;
		d=d/10;
		sum=sum+b;
		rev=(rev*10)+b;
	}
	printf("Num: %d, Sum: %d, Rev: %d",a,sum,rev);
	getch();
	clrscr();
	a=0;
	switch (a)
	{
		case 0:
		printf("hello");
		break;
		default: printf("bye");
	}
	getch();
}