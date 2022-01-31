#include<stdio.h>
#include<conio.h>

int n,graph[20][20],d[20],pi[20],i,j,z,source;
char names[20];

int bellman(){
	for(i=0;i<n;i++)
	{
		d[i]=9999;
		pi[i]=-1;
	}
	d[source]=0;
	for(z=1;z<n;z++)
	{
		for(i=0;i<n;i++)
			for(j=0;j<n;j++)
			{
				if(graph[i][j]!=0)
				{
					if(d[j]>d[i]+graph[i][j])
					{
						d[j]=d[i]+graph[i][j];
						pi[j]=i;
					}
				}
			}

			printf("\nD^%d :- \n",z);
		for(i=0;i<n;i++)
			{
				
					printf(" %d ",d[i]);
				
			}

		printf("\nPi^%d :- \n",z);
		for(i=0;i<n;i++)
			{
				printf(" %d ",pi[i]);
			}
			getch();
	}
	printf("\n");

	for(i=0;i<n;i++)
		for(j=0;j<n;j++)
			{
				if(graph[i][j]!=0)
				{
					if(d[j]>d[i]+graph[i][j])
						{
							return 0;
						}
				}
			}
	return 1;
}

void printPath(){
	int sum=0,k,temp;
	printf("\tPair\t|    Paths    |\tShort Dist.\n");
	for(j=1;j<n;j++)
	{
		sum=0;
		printf("\t%c->%c\t|    ",names[0],names[j]);
		k=j;
		while(1){
			printf("%c->",names[k]);
			temp=pi[k];
			sum+=graph[temp][k];
			k=temp;
			if(k==0)
				break;
		}
		printf("A    |");
		printf("\t%d\t\n",sum);
	}
		
}


int main(){
	printf("Bellman-Ford Algorithm\n");
	printf("Enter the number of vertices:- ");
	scanf("%d",&n);
	printf("Enter the adjacency matrix\nlike for vertex a:- 0 2 4 0 0, 5 vertices.\n(enter 0 for no connection):- \n");
	for(i=0;i<n;i++)
	{
		names[i]=(65+i);
		for(j=0;j<n;j++)
			{
				scanf("%d",&graph[i][j]);
				if(graph[i][j]==0)
					graph[i][j]=9999;
			}
	}
	//taken the weigths
	printf("Enter the source vertex\nenter 0 for first and so on:- ");
	scanf("%d",&source);
	printf("\n\n");
	if(bellman())
		printPath();
	else
		printf("NO SHORTEST PATH EXISTS !\n");
	return 0;
}
