// MERGE(A, p, q, r)
// 1. n1 ← q - p + 1
// 2. n2 ← r - q
// 3. create arrays L[1 - n1 + 1] and R[1 - n2 + 1]
// 4. for i ← 1 to n1
// 5. do L[i] ← A[p + i - 1]
// 6. for j ← 1 to n2
// 7. do R[j] ← A[q + j]
// 8. L[n1 + 1] ← ∞
// 9. R[n2 + 1] ← ∞
// 10. i ← 1
// 11. j ← 1
// 12. for k ← p to r
// 13. do if L[i] ≤ R[j]
// 14. then A[k] ← L[i]
// 15. i ← i + 1
// 16. else A[k] ← R[j]
// 17. j ← j + 1
#include<stdio.h>
#include <time.h>
#include <conio.h>
#define m 5
int a[m];

void merge(p,q,r)
{
	int i,j,k,temp;
	int n1= q-p+1;
	int n2 = r-q;
	int *ptr1 = (int*) malloc((1-n1+1) * sizeof(int));
	int *ptr2 = (int*) malloc((1-n2+1) * sizeof(int));
	for(i=0;i<n1;i++)
	{
		ptr1[i] = a[p+i-1];
	}
	for(j=0;j<n2;j++)
	{
		ptr2[j] = a[q+j];
	}
	ptr1[n1] = 9999;
	ptr2[n2] = 9999;
	i=1;j=1;
	for(k=p;k<r;k++)
	{
		if(ptr1[i]<=ptr2[j])
			{a[k]=ptr1[i]          ;
						i++;}
		else
			{a[k] = ptr2[j];
						j++;}

	}

}

// MERGE-SORT(A, p, r)
// 1. if p < r
// 2. then q ← ⌊(p + r)/2⌋
// 3. MERGE-SORT(A, p, q)
// 4. MERGE-SORT(A, q + 1, r)
// 5. MERGE(A, p, q, r)

void merge_sort(int p,int r)
{
	int q;
	if(p<r)
	{
		q = (p+r)/2;
	}
	merge_sort(p,q);
	merge_sort(p,q);
	merge(p,q,r);
}


void main(){
	int b,c,d;
	clrscr();
	printf("enter the array of size 5\n");
	for(b=0;b<m;b++)
	{
		scanf("%d",&a[b]);
	}
	printf("\nhere is your original array:- \n");
	for(b=0;b<m;b++)
	{
		printf("%d\t",a[b]);
	}
	printf("\nhere is your merge-sorted array:- \n");
	for(b=0;b<m;b++)
	{
		scanf("%d\t",a[b]);
	}
	getch();
}