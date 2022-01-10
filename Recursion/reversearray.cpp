#include <iostream>
#include <bits/stdc++.h>



void change(int arr[],int n,int i){
    if(i>=n-i-1)
        return;
    std::swap(arr[i],arr[n-i-1]);
    change(arr,n,i+1);
}


int main() {
    int arr[] = {1,2,3,4,5,6};
    change(arr,6,0);
    for(int i=0;i<6;i++){
        std::cout<<arr[i]<<" ";
    }

    return 0;
}