/******************************************************************************

                            Online C Compiler.
                Code, Compile, Run and Debug C program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <stdio.h>
 int size;
void quicksort (int [], int, int);
 
int main()
{
    int list[50];
    int  i;
    printf("QUICK SORT \n");
    printf("Enter the number of elements: ");
    scanf("%d", &size); 
    printf("Enter the elements to be sorted:\n");
    for (i = 0; i < size; i++)
    {
        scanf("%d", &list[i]);
    } 
    quicksort(list, 0, size - 1);
    printf("After applying quick sort\n");
    for (i = 0; i < size; i++)
    {
        printf("%d ", list[i]);
    }
    printf("\n");
 
    return 0;
}
void quicksort(int list[], int low, int high)
{
    int pivot, i, j, temp;
    
    if (low < high)
    {
        printf("\npass: \n ");
    for (i = 0; i < size; i++)
    {
        printf("%d ", list[i]);
    }
    printf("\n");
        pivot = low;
        i = low;
        j = high;
        while (i < j) 
        {
            while (list[i] <= list[pivot] && i <= high)
            {
                i++;
            }
            while (list[j] > list[pivot] && j >= low)
            {
                j--;
            }
            if (i < j)
            {
                temp = list[i];
                list[i] = list[j];
                list[j] = temp;
            }
        }
        temp = list[j];
        list[j] = list[pivot];
        list[pivot] = temp;
    //      printf("\npass: \n ");
    // for (i = 0; i < size; i++)
    // {
    //     printf("%d ", list[i]);
    // }
    // printf("\n");
        quicksort(list, low, j - 1);
        
        quicksort(list, j + 1, high);
       
    }
    
}