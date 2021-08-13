#include<iostream>
using namespace std;

int main(){
        int n;
    cin>>n;
    int Array[n];
    for(int i=0;i<n;i++){
        cin>>Array[i];
    }
   int largest_element=INT_MIN;
   for(int i=0;i<n;i++){
       if(Array[i]>largest_element){
           largest_element=Array[i];
       }
   }
   cout<<largest_element;
}