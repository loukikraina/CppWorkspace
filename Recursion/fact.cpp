// Online C++ compiler to run C++ program online
#include <iostream>

int print(int n){
    if(n==0)
        return 1;
    return n*print(n-1);
}


int main() {
    // Write C++ code here
    std::cout << "Hello world!\n";
    std::cout<<print(7);
    return 0;
}