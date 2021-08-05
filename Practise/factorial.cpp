#include<iostream>
using namespace std;
int main(){
    int n;
    cout<<"write a number to find its factorial :";
    cin>>n;
    int factorial=n;
    for(int i=1;i<n;i++){
        factorial=factorial*i;
    }
    cout<<"factorial of "<<n<<" is : "<<
    factorial;
    
}