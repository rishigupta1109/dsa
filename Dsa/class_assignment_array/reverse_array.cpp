#include<iostream>
using namespace std;

int main(){
    int n;
    cin>>n;
    int Array[n];
    for(int i=0;i<n;i++){
        cin>>Array[i];
    }
   
   for(int i=0;i<n/2;i++){
             int temp=Array[n-i-1];
              Array[n-i-1]=Array[i];
              Array[i]=temp;
   }
   for(int i=0;i<n;i++){
           cout<<Array[i];
   }
 
}