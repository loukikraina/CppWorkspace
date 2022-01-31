#include <stdio.h>
int n;
int call=0;
int binarySearch(int arr[], int start, int end, int key)
{
    int z;
    call++;
    for(z=start;z<=end;z++)
        printf("%d\t",arr[z]);
    printf("\n");
    printf("Call: %d\n",call);

    if (start <= end )
    {
        int mid = start + (end - start) / 2;

        if (arr[mid] == key)
        {
            return mid;
        }


        if (arr[mid] > key)
        {
             return binarySearch(arr, start, mid - 1, key);
        }
        return binarySearch(arr, mid + 1, end, key);
    }

    else
    return -1;
}

int main()
{
    int i;
    printf("BINARY SEARCH\n");
    printf("Enter number of elements\n");
    scanf("%d",&n);
    int arr[n];
    printf("Enter %d integers\n", n);
    for( i=0;i<n;i++){
        scanf("%d",&arr[i]);
    }

    int key ;
    printf("\nEnter a Number you want to search in the array\n");
    scanf("%d",&key);
    int result = binarySearch(arr, 0, n - 1, key);
    if(result == -1)
    printf("\nElement is not present in array\n");
    else
    printf("\nElement is present at index %d\n",result);
    printf("\n No of Calls : %d\n",call);
    return 0;
}