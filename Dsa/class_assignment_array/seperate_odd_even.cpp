#include<iostream>
using namespace std;

int main(){
    int n;
    cin>>n;
    int Array[n];
    for(int i=0;i<n;i++){
        cin>>Array[i];
    }
    int seperated_array[n];
    int s=0;
    int e=n-1;
    for(int i=0;i<n;i++){
      if(Array[i]%2==0){
          seperated_array[s]=Array[i];
          ++s;
      }
      else{
          seperated_array[e]=Array[i];
          --e;
      }
    }
    for(int i=0;i<n;i++){
       cout<<seperated_array[i]<<" ";
    }
 
}