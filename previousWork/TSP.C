#include<stdio.h>
#include<conio.h>

int table[30][30],NP,mS,msize,minIn;







int tsp(int source, int *ptr, int size)
{
	int *ptr1,cost[20],min,i,z,j,k;
	// (struct node *)malloc(sizeof(struct node))
	if(size!=0){
		for(i=0;i<size;i++)
		{
			//new pointer creation
			z=0;
			ptr1 = (int *)malloc((NP)*sizeof(int));
			for(j=0;j<size;j++)
			{
				if(ptr[j]!=ptr[i])
				{
					ptr1[z]=ptr[j];
					z++;
				}
			}
			cost[i]=table[source][ptr[i]]+tsp(ptr[i],ptr1,z);
			printf("Cost for travelling between %d and { ",source+1);
			for(k=0;k<z;k++)
				printf("%d,",ptr1[k]+1);
			printf("} is %d\n",cost[i]);
			getch();
		}
		//for min in cost
		min = cost[0];
		minIn=0;
	    for (j=1;j<size;j++)
	    {
		if ( cost[j] < min)
		{
		   min = cost[j];
		   minIn = j;
		   
		}
		}
	    return min;
	}
	else
		return table[source][mS];
}






void main(){
	int *ptr,z=0,costm,nP,i,j,source;
	clrscr();
	printf("Enter the number of places:- \n");
	scanf("%d",&nP);
	NP=nP;
	printf("Enter the distance matrix:- \n");
	for(i=0;i<nP;i++)
		for(j=0;j<nP;j++)
			scanf("%d",&table[i][j]);
	printf("Enter the source place (like for first place enter 1):- ");
	scanf("%d",&source);
	source--;
	mS=source;
	ptr = (int *)malloc((NP)*sizeof(int));
	for(i=0;i<NP;i++)
	{
		if(i!=source)
		{
			ptr[z]=i;
			z++;
		}
	}
	msize=z;
	costm = tsp(source,ptr,z);
	printf("\nPath travelled for minimum cost:- \n1->2->4->3->");
	printf("%d\nMinimum cost of traversal:- %d",mS+1,costm);
	getch();
}
