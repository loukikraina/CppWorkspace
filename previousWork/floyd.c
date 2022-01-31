#include<stdio.h>
#include<conio.h>

int n,graph[20][20],d[20][20],pi[20][20],i,j,z,source,end;
char names[20];


void floyd(){
	for(i=0;i<n;i++)
			for(j=0;j<n;j++)
				if(graph[i][j]!=9999)
					pi[i][j]=i;
				else
					pi[i][j]=-1;

	for(z=0;z<n;z++){
		
		for(i=0;i<n;i++)
			for(j=0;j<n;j++)
			{
				if(!(i==j || i==z || j==z))
				{
					if(graph[i][j]>graph[i][z]+graph[z][j]){
						graph[i][j]=graph[i][z]+graph[z][j];
						pi[i][j]=pi[z][j];
					}
				}

			}
		printf("D^%d :- \n",z);
		for(i=0;i<n;i++)
			{
				for(j=0;j<n;j++)
					printf(" %d ",graph[i][j]);
				printf("\n");
			}

		printf("Pi^%d :- \n",z);
		for(i=0;i<n;i++)
			{
				for(j=0;j<n;j++)
					printf(" %d ",pi[i][j]);
				printf("\n");
			}
			getch();
	}

}

void printPath(){
	int sum=0,k,temp;
	// printf("\tPair\t|    Paths    |\tShort Dist.\n");
	printf("\nPaths from %c to %c:- \n",names[source],names[end]);
	printf("Distance:- %d\n",graph[source][end]);
	printf("Full path:- %c->",names[end]);
	while(1){
		end = pi[source][end];
		if(end==source)
			break;
		printf("%c->",names[end]);
	}
	printf("%c",names[source]);
		
}


int main(){
	int tag=1;
	printf("Floyd Warshall Algorithm\n");
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
	
// 	printf("\n\n");
	floyd();
	// printf("\nHere is the final distance matrix:-\n");
	// for(i=0;i<=n;i++)
	// 		for(j=0;j<=n;j++){
	// 			if(i==0 &&j==0)
	// 			{
	// 				printf("")
	// 			}
	// 		}
	do{
		printf("Enter the source vertex and destination vertex\nenter 0 for first and so on:- ");
		scanf("%d %d",&source,&end);
		printPath();
		printf("\nPress 1 to insert other source and destination\nPress any other no. to exit.\n");
		scanf("%d",&tag);
	}while(tag==1);
	return 0;
}

