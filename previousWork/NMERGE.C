#include <stdio.h>
#include<conio.h>


void print(int Arr[], int n)
{
	int i;
    for ( i = 0; i < n; i++)
    {
	printf("%d ", Arr[i]);
    }
    printf("\n");
}


void merge(int A[], int mid, int low, int high)
{
    int i, j, k, B[100];
    i = low;
    j = mid + 1;
    k = low;

    while (i <= mid && j <= high)
    {
	if (A[i] < A[j])
	{
	    B[k] = A[i];
	    i++;
	    k++;
	}
	else
	{
	    B[k] = A[j];
	    j++;
	    k++;
	}
    }
    while (i <= mid)
    {
	B[k] = A[i];
	k++;
	i++;
    }
    while (j <= high)
    {
	B[k] = A[j];
	k++;
	j++;
    }
    for (i = low; i <= high; i++)
    {
        A[i] = B[i];
    }
}

void mergeSort(int A[], int low, int high, int n)
{
    int mid;
    printf("\nthe low index : %d the high index: %d\n", low, high);
    if (low < high)
    {
	mid = (low + high) / 2;
	mergeSort(A, low, mid, n);
	mergeSort(A, mid + 1, high, n);
	merge(A, mid, low, hig/******************************************************************************

                            Online C Compiler.
                Code, Compile, Run and Debug C program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include<stdio.h>
#include<conio.h>

int m=1;
int s;

void merge(int ar[],int p,int q,int r )
{
    int i,j,k;
    int n1=q-p+1;
    int n2=r-q;

    int L[n1],R[n2];

    for(i=0;i<n1;i++)
    {
     L[i]=ar[p+i];
    }
    printf("subarray 1:\t");
    for (i=0; i<n1; i++)
        printf("%d ", L[i]);
         printf("\n");
    for(j=0;j<n2;j++)
    {
        R[j]=ar[q+j+1];
    }
    printf("subarray 2:\t");
    for (i=0; i<n2; i++)
        printf("%d ", R[i]);
         printf("\n");


    i=0;
    j=0;
    k=p;

   while(i<n1 && j<n2)
    {
        if(L[i]<=R[j])
        {
            ar[k]=L[i];
            i++;
        }
        else
        {
            ar[k]=R[j];
            j++;
        }
        k++;
    }

       while (i < n1)
    {
        ar[k] = L[i];
        i++;
        k++;
    }

    while (j < n2)
    {
        ar[k] = R[j];
        j++;
        k++;
    }

    printf("MERGE %d:\t",m);
    for (i=p; i<r+1; i++)
        printf("%d ", ar[i]);
         printf("\n");
    m++;
    printf("\n\n");
    }

void merge_sort(int ar[],int p,int r)
{
    int i;
    int q;
    if(p<r)
    {
        q=(p+r)/2;
        merge_sort(ar,p,q);
        merge_sort(ar,q+1,r);

        merge(ar,p,q,r);

    }
}

void print(int A[], int size)
{
    int i;
    for (i=0; i < size; i++)
        printf("%d ", A[i]);
    printf("\n");
}

int main()
{
    int i;
    printf("MERGE SORT\n");
    printf("Enter number of elements\n");
    scanf("%d",&s);
    int ar[s];
    printf("Enter %d numbers\n", s);
    for(i=0;i<s;i++)
    {
        scanf("%d",&ar[i]);
    }

    printf("ARRAY:\n");
    print(ar,s);
    merge_sort(ar,0,s-1);

    printf("\nAFTER SORTING:\n");
    print(ar,s);
    return 0;
}
h);
    }
//    print(A, n);

}
void main()
{
    int n;
    int A[20];
    int i;
    clrscr();
    printf("\nThe Merge Sort:- \n");
    printf("\nEnter the size of array : ");

    scanf("%d", &n);



    for (i = 0; i < n; i++)
    {
	printf("\nEnter the Element no %d : ", i + 1);
	scanf("%d", &A[i]);
    }
    printf("\nBefore sorting : ");
    print(A, n);

    printf("\nDoing Merge Sort: ---- \n");

    mergeSort(A, 0, n - 1, n);
    printf("\n\nAfter sorting : \n");
    print(A, n);
    getch();
}

