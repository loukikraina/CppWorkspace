#include<conio.h>
#include<stdio.h>
#include<time.h>
int arr[100],tag,sarr[100];
void sort(){
	int a,b,c;
	for(a=0;a<tag;a++)
		sarr[a]=arr[a];
	for(a=0;a<tag;a++)
	{
		for(b=a+1;b<tag;b++)
		{
			if(sarr[a]>sarr[b])
			{
				c=sarr[a];
				sarr[a]=sarr[b];
				sarr[b]=c;
			}
		}
	}
}
void linear(int n){
	int a,b=0;
	for(a =0;a<tag;a++)
	{
		if(arr[a]==n){
			printf("NUMBER FOUND !! AT INDEX :- %d\n",a);
			b++;
		}
	}
	if(b==0)
		printf("NUMBER NOT FOUND!!!\n");
}
void binary(int n){
	int a=0,m,e=(tag-1),t=0;
	while(a<=e)
	{
		m=(a+e)/2;
		if(sarr[m]==n)
		{
			printf("NUMBER FOUND !! AT INDEX :- %d\n",m);
			t++;
			break;
		}
		else if(sarr[m]>n)
			e=m-1;
		else
			a=m+1;
	}
	if(t==0)
		printf("NUMBER NOT FOUND!!!\n");
}
void main(){
	int a=1,b,c=0,d=0,e=0,start,end,incre,z;
	clock_t t;
	double time_taken;
	clrscr();
	printf("If you want a series press 1 and if not press any other number:- ");
	scanf("%d",&e);
	if(e==1){
		printf("Enter the starting number and the ending number and then the increment repectively :- ");
		scanf("%d %d %d",&start,&end,&incre);
		for(z=start;z<=end;z+=incre)
		{
			arr[c]=z;
			c++;
		}
		
	}
	else{
	printf("Enter the numbers you want to insert in the array and \nenter '1234' to exit the insertion sequence.\n");
	while(a!=1234){
		printf("Enter the %d number\n",c+1);
		scanf("%d",&a);
		arr[c]=a;
		c++;
	}
}
	tag=c;
	while(d==0){
		printf("\n\tMAIN\tMENU\n");
		printf("1. LINEAR SEARCH\n2. BINARY SEARCH\n3. ENTER ANY NUMBER EXCEPT 1 AND 2 TO EXIT. \nEnter the option number\n");
		scanf("%d",&b);
		sort();
		printf("Enter the number to search:- ");
		scanf("%d",&a);
		if(b==1){
			t=clock();
			linear(a);
			t=clock()-t;
			time_taken=((double)t)/CLOCKS_PER_SEC;
			printf("Time-taken to do this search is :- %lf",time_taken);
		}
		if(b==2){
			t=clock();
			binary(a);
			t=clock()-t;
			time_taken=((double)t)/CLOCKS_PER_SEC;
			printf("Time-taken to do this search is :- %lf",time_taken);
		}
		else
			d=1;
	}
	getch();
}