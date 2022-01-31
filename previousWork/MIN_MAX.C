#include<conio.h>
#include<stdio.h>
int n;
int call=0;
int comp=0;
struct pair
{
    int min;
    int max;
};

struct pair getMinMax(int arr[], int low, int high)
{
    struct pair minmax, mml, mmr;
    int mid;
    

    if (low == high)
    {
        comp++;
        minmax.max = arr[low];
        minmax.min = arr[low];
        call++;
            printf("\nCall : %d: \n",call);
	    printf("From %d to %d index, Max: %d\tMin: %d\n",low,low,minmax.max,minmax.min);

        return minmax;
    }


    if (high == low + 1)
    {

        if (arr[low] > arr[high])
        {
            comp++;
            minmax.max = arr[low];
            minmax.min = arr[high];
        }
        else
        {
            comp++;
            minmax.max = arr[high];
            minmax.min = arr[low];
        }
        call++;
            printf("\nCall : %d: \n",call);
	    printf("From %d to %d index, Max: %d\tMin: %d\n",low,high,minmax.max,minmax.min);

        return minmax;
    }


    mid = (low + high)/2;

    mml = getMinMax(arr, low, mid);
    mmr = getMinMax(arr, mid+1, high);


    if (mml.min < mmr.min)
        minmax.min = mml.min;
    else
        minmax.min = mmr.min;
    comp++;


    if (mml.max > mmr.max)
        minmax.max = mml.max;
    else
        minmax.max = mmr.max;
    comp++;
    call++;
    printf("\nCall : %d: \n",call);
	printf("From %d to %d index, Max: %d\tMin: %d\n",low,high,minmax.max,minmax.min);

    return minmax;
}

int main()
{
    int i;
    printf("\nMIN MAX PROGRAM\n");
    printf("\nEnter number of elements:- \n");
    scanf("%d",&n);
    int arr[n];
    printf("Enter %d integers:- \n", n);
    for( i=0;i<n;i++){
        scanf("%d",&arr[i]);
    }
    struct pair minmax = getMinMax(arr, 0, n-1);
    // printf("\nMinimum element is %d", minmax.min);
    // printf("\nMaximum element is %d", minmax.max);
    // printf("\nNo Of Calls : %d",call);
    // printf("\nNo. Of Comparisons: %d",comp);
    return 0;
}