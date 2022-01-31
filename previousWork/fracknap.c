#include<stdio.h>
#define MAX 20

struct item{
	int x;
	int v;
	int w;
	float cost;
} arr[MAX];

int n, m;

void sort();

int main(){
	int s[MAX], i, k = 0;
	float fract = 1, sw=0, sp=0;
	printf("Enter number of items: ");
	scanf("%d", &n);
	
	for(i = 0; i < n; i++){
		arr[i].x = i+1;
		printf("\n\nItem no %d:", i+1);
		printf("\nEnter profit: ");
		scanf("%d", &arr[i].v);
		printf("Enter weight: ");
		scanf("%d", &arr[i].w);
		arr[i].cost = (float)arr[i].v/arr[i].w;
	}
	
	printf("\n\nEnter capacity of knapsack: ");
	scanf("%d", &m);
	
	sort();
	
	printf("\n\nItem order after sorting by cost - ");
	for(i = 0; i < n; i++){
	    printf("\nItem %d, Cost %.2f", arr[i].x, arr[i].cost);
	}
	printf("\n");
	printf("\nITEM CHOSEN FOR INCLUSION  WEIGHT  REMAINING SPACE IN M  PROFIT\n");

	for(i = 0; i < n; i++){
		if(sw == m) 
			break;
		s[k++] = arr[i].x;
		if(sw+arr[i].w <= m){
			sw += arr[i].w;
			sp += arr[i].v;
		} else {
			fract = (m-sw)/(float)arr[i].w;
			sw += arr[i].w * fract;
			sp += arr[i].v * fract;
		}
		printf("\t%d\t\t  |  %.2f\t|  %.2f\t|  %.2f\n", arr[i].x,arr[i].w*fract,(float)m-sw,arr[i].v*fract);
		if(fract != 1) printf("\nFract is %f", fract);
	}
	
	printf("\n\nItems in knapsack - ");
	for(i=0; i < k; i++){
		printf("%d ", s[i]);
	}
	printf("\nTotal profit = %.2f \tTotal Weight = %.2f", sp, sw);
	
	return 0;
}

void sort(){
	int i, j, max;
	struct item temp;
	
	for(i = 0; i < n; i++){
		max = i;
		for(j = i+1; j < n; j++){
			if(arr[max].cost < arr[j].cost){
				max = j;
			}
		}
		temp = arr[i];
		arr[i] = arr[max];
		arr[max] = temp;
	}
}