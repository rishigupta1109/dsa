#include<iostream>
using namespace std;
int main(){
    int n;
    cin>>n;
    int reverse=0;
    int counter=n;
    while(counter!=0){
        int remainder=counter%10;
        reverse=reverse*10+remainder;
        counter=counter/10;
    }
    if(reverse==n){
        cout<<"number is pallindrome";
    }
    else{
        cout<<"number is not pallindrome";
    }
}