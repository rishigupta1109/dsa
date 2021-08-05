#include<iostream>
using namespace std;
int main(){
 int n;
 cin>>n;
 int Array[n];
 for (int i = 0; i < n; i++)
 {
     cin>>Array[i];
 }
 int max=INT_MIN;
 int min=INT_MAX;
 int i=0;
if(n%2!=0){
    max=Array[0];
    min=Array[0];
    i=1;
}
else{
    if(Array[0]>Array[1]){
        max=Array[0];
        min=Array[1];
    }
    else{
         max=Array[1];
         min=Array[0];
    }
    i=2;
}

    for( i;i<n-1;i=i+2){
     if(Array[i]>Array[i+1]){
        if(Array[i]>max){
            max=Array[i];
        }
        if(Array[i+1]<min){
            min=Array[i+1];
        }

     }
     else{
            if(Array[i+1]>max){
            max=Array[i+1];
        }
        if(Array[i]<min){
            min=Array[i];
        }
     }
    
    
    }

 cout<<max<<" "<<min;
 
}