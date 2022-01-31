#include<stdio.h>
#include <time.h>
#include<conio.h>

 int A[20];

void main()
{
    clock_t t;
    int n,i,j,swape=0;
    double time_taken;
    int comparisons = 0, swapping = 0;
    clrscr();
    printf("WELCOME TO THE SLECTION SORT PROGRAM\n");
    printf("Enter size of array:- ");
    scanf("%d",&n);
    printf("Enter %d numbers to be stored in array:\n",n);


    for(i = 0; i < n; i++)
    {
	scanf("%d",&A[i]);
    }
    t = clock();
    for(i = 0; i < n-1; i++)
    {
	int min = i;
	comparisons += 1;
	for(j = i+1; j < n; j++)
	{
	    if(A[j] < A[min])
	    {
		min = j;
	    }

     }
	if (i != min)
	{
	    int temp;
	    temp = A[i];
	    A[i] = A[min];
	    A[min] = temp;
	    swapping += 1;
	}

	swape=swapping-swape;
	printf("No. of swappings : %d\n",swape);
	for(j = 0; j < n; j++)
	    {
		printf("%d\t",A[j]);
	    }
	printf("\n");
    }
    printf("\nTotal no. of swapping : %d\nno. of iterations : %d\n",swapping,comparisons);

     t = clock() - t;


    for(i = 0; i < n; i++)
    {
    printf("%d\t",A[i]);
    }

    time_taken = ((double)t)/CLOCKS_PER_SEC;
    printf("\n Time_taken:- %f \n",time_taken);
    getch();
}