//08/03/2021

#include<conio.h>
#include<stdio.h>
int r=-1,f=0;
int np,ps[30],ma[10],ms;

void pop()
{
	if(f==r)
	f=0;
	else
	f++;
}


void push(int a){

	if(r==(ms-1) && f!=r)
	{
		pop();
		ma[f-1]=a;
	}
	else if(r==(ms-1) && f==r)
	{
		pop();
		ma[r]=a;
	}
	else
	{
		r++;
		ma[r]=a;
	}
}

void show(){
	int a;
	for(a=0;a<ms;a++)
		printf("%d\t",ma[a]);
	printf("\n");

}
int search(){

	int a,c,b=0,tHit=0;
	for(a=0;a<np;a++)
	{
		b=0;
		for(c=0;c<ms;c++)
		{
			if( ps[a]==ma[c] )
				b++;
		}
		printf("For page frame '%d':- ",ps[a]);

		if(b!=0){
			printf("Hit\t");
			tHit++;
		}
		else{
			printf("Miss\t");
			push(ps[a]);
		}
		show();

	}
	return tHit;

}
void main(){
	int a,c,tHit;
	clrscr();
	printf("Enter the number of pages:- ");
	scanf("%d",&np);
	printf("Enter page sequence:- \n");
	for(a=0;a<np;a++)
		scanf("%d",&ps[a]);
	printf("Enter the memory array size:- \n");
		scanf("%d",&ms);
		for(c=0;c<ms;c++)
		{
			ma[c]=0;
		}
	tHit=search();
	printf("Total hits: %d\tHit Ratio: %d/%d = %f\n",tHit,tHit,np,((float)tHit/(float)np));
	printf("Total misses: %d\tMiss Ratio: %d/%d = %f\n",np-tHit,np-tHit,np,((float)(np-tHit)/(float)np));



	getch();
}