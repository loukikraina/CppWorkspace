#include<conio.h>
#include<stdio.h>

int table[30][30],nJ,capacity,w[30],p[30];


void main(){
	int i,j,max;
	clrscr();
	printf("Enter number of jobs and capacity of kanpsack.\n");
	scanf("%d %d",&nJ,&capacity);
	for(i=0;i<nJ;i++){
		printf("Enter weight and profit for job %d:- ",i+1);
		scanf("%d %d",&w[i],&p[i]);
	}
	//continue with table rows=nJ columns=capacity
	for(i=0;i<=nJ;i++){
		for(j=0;j<=capacity;j++){
			if(i==0 || j==0)
				table[i][j]=0;
			else if(j-w[i-1]>=0){
				if(table[i-1][j]>p[i-1]+table[i-1][j-w[i-1]])
					table[i][j]=table[i-1][j];
				else
					table[i][j]=p[i-1]+table[i-1][j-w[i-1]];

			}
			else
				table[i][j]=table[i-1][j];
		}
	}
	printf("The final table having all values of profits:- \n");
	for(i=0;i<=nJ;i++){
		for(j=0;j<=capacity;j++)
			printf("%d ",table[i][j]);
		printf("\n");
	}
	printf("\nTherefore by looking at the table we get that\nMax profit:- %d\n",table[nJ][capacity]);
	printf("Now the jobs that can be performed for max profit:- \n");
	max = table[nJ][capacity];
	for(i=nJ;i>=0;i--){
		if(max>table[i][capacity])
		{
			printf("Job %d with weight %d and profit %d\n",i+1,w[i+1],p[i+1]);
			max = table[i][capacity];
		}
	}
	getch();

}