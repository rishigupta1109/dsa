#include<bits/stdc++.h>
using namespace std;
int main(){
  int t;
  cin>>t;
  while(t--){
      int n;
      cin>>n;
      int arr[n];
      for(int i=0;i<n;i++){
          cin>>arr[i];
      }
      for(int i=0;i<n;i++){
          int max=INT_MIN;
          for(int j=0;j<=i;j++){
              int value=arr[j];
              for(int l=j+1;j<n;j++)
              for(int k=j+1;k<=l;k++){
                  value=value&arr[k];
              }
              if(max<value) max=value;
          }
          cout<<max<<" ";
      }
      cout<<endl;
  }
}