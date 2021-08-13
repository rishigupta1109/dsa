#include<iostream>
using namespace std;

int main(){
    int n;
    cin>>n;
    int Array[n];
    for(int i=0;i<n;i++){
        cin>>Array[i];
    }
    int sum=0;
    for(int i=0;i<n;i++){
        sum+=Array[i];
    }
    cout<<sum;
}