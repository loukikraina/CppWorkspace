#include<stdio.h>
#include <time.h>

int A[20];//declaring array

 void main()
 {
     clock_t t;
     int n,i,j;
     int swap_var= 0,comparisons= 0;
     double time_taken;

     clrscr();

    printf("WELCOME TO THE INSERTION SORT PROGRAM\n");
    printf("Enter size of array:- ");
    scanf("%d",&n);
    printf("Enter %d numbers to be stored in array:\n",n);

     for(i = 0; i < n; i++)//scanning the array
     {
	 scanf("%d",&A[i]);
     }
     //scanned the array

    //now the sorting begins
    t = clock();
    for(i = 1; i < n ; i++)
    {
	j = i;
	comparisons = comparisons + 1;
	while(A[j-1] > A[j] && j > 0)//j cannot be 0 as there is no index such as '-1'
	{
		int temp;
		temp = A[j-1];
		A[j-1]= A[j];
		A[j] = temp;
		j--;
		swap_var++;
	}//swapping done here


	printf("swappings done: %d \n",swap_var) ;
	printf("Array : \t");
	for(j = 0; j < n; j++)
	{
	    printf("%d \t",A[j]);
	}
	printf("\n");
    }
    t = clock() - t;

    printf("\n");
    for(i = 0; i < n; i++)
	{
	    printf("%d \t",A[i]);
	}


    time_taken = ((double)t)/CLOCKS_PER_SEC;
    printf("\n Time taken:- %f \n",time_taken);
    getch();

 }