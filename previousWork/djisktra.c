#include<stdio.h>
#include<conio.h>
#define nd 999999
#define max 100
 int arr[max][max];
int n;
int Start;
int u;

 
void DJ()
{
 
	int cost[max][max],distance[max],predecessor[max],z,temp,temp1[max];
	int visited[max],count,mis_dis,successor,i,j;
	
	
	for(i=0;i<n;i++)
		for(j=0;j<n;j++)
			if(arr[i][j]==0)
				cost[i][j]=nd;
			else
				cost[i][j]=arr[i][j];
	

	for(i=0;i<n;i++)
	{
		distance[i]=cost[Start][i];
		predecessor[i]=Start;
		visited[i]=0;
	}
	
	distance[Start]=0;
	visited[Start]=1;
	count=1;
	
	while(count<n-1)
	{
		mis_dis=nd;
		
		for(i=0;i<n;i++)
			if(distance[i]<mis_dis&&!visited[i])
			{
				mis_dis=distance[i];
				successor=i;
			}
			
			visited[successor]=1;
			for(i=0;i<n;i++)
				if(!visited[i])
					if(mis_dis+cost[successor][i]<distance[i])
					{
						distance[i]=mis_dis+cost[successor][i];
						predecessor[i]=successor;
					}
		count++;
	}
 
	for(i=0;i<n;i++)
		if(i!=Start)
		{
			printf("\nDistance of node from starting node %d = %d",i+1,distance[i]);
			printf("\nPath= %d",i+1);
			
			j=i;
			do
			{
				j=predecessor[j];
				printf(" <-  %d",j+1);
			}while(j!=Start);
	    }
	   printf("\nThe shortest path:- \n");
	   //z = distance[0];
	   	for(i=0;i<n;i++)
	   	temp1[i]=distance[i];
	for(i=0;i<n;i++)
	{
	    for(j=0;j<n-i-1;j++)
	    {
	        if (distance[j] > distance[j+1])
	        {
	            temp = distance[j];
	            distance[j]=distance[j+1];
	            distance[j+1]=temp;
	        }
	    }
	}
	for(i=0;i<n;i++)
	{
	   // printf("%d\t",distance[i]);
	    for(j=0;j<n;j++)
	    {
	        if(temp1[j]==distance[i])
	        printf("--> %d ",j+1);
	    }
	}
// 	printf("\n");
// 	for(i=0;i<n;i++)
// 	{
// 	    printf("%d\t",temp1[i]);
// 	   // for(j=0;j<n;j++)
// 	   // {
// 	   //     if(temp1[j]==distance[i])
// 	   //     printf("--> %d ",j+1);
// 	   // }
// 	}
	
	
}

 
int main()
{
	int i,j;
	printf("DIJKSTRA'S ALGORITHM\n");
	printf("Enter no. of vertices:\n");
	scanf("%d",&n);
	printf("\nEnter the adjacency matrix:\n");
	
	for(i=0;i<n;i++)
		for(j=0;j<n;j++)
			scanf("%d",&arr[i][j]);
	
	printf("\nEnter the starting node:\n");
	scanf("%d",&u);
	u--;
	DJ();
	
	return 0;
}