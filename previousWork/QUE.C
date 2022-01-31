#include<stdio.h>
void sum(int a[50][50])
{
	printf("%d",a[0][0]);
}
void main()
{
	int a[50][50],b,c;
	clrscr();
	for(b=0;b<2;b++)
	for(c=0;c<3;c++)
	scanf("%d",&a[b][c]);
	sum(a);
	getch();
}