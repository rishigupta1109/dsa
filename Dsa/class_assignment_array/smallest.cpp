#include<iostream>
using namespace std;

int main(){
        int n;
    cin>>n;
    int Array[n];
    for(int i=0;i<n;i++){
        cin>>Array[i];
    }
   int smallest_element=INT_MAX;
   for(int i=0;i<n;i++){
       if(Array[i]<smallest_element){
           smallest_element=Array[i];
       }
   }
   cout<<smallest_element;
}