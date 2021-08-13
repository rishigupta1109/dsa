#include<iostream>
using namespace std;

int main(){
    int n;
    cin>>n;
    int Array[n];
    for(int i=0;i<n;i++){
        cin>>Array[i];
    }
   
   for(int i=0;i<n;i++){
      for(int j=i+1;j<n;j++){
          if(Array[j]<Array[i]){
              int temp=Array[j];
              Array[j]=Array[i];
              Array[i]=temp;
          }
      }
   }
   cout<<Array[n-1]<<" "<<Array[n-2]<<" "<<Array[n-3];
 
}