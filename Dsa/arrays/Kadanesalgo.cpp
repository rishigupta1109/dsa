#include<bits/stdc++.h>
using namespace std;
 int maxSubarraySum(int arr[], int n){
        int max=0;
        int ultimax=INT_MIN;
       for(int i=0;i<n;i++){
           
           max=max+arr[i];
           if(max>ultimax){
               ultimax=max;
           }
           if(max<0){
               max=0;
           }
           
       }
       return ultimax;
        
    }
int main(){
 
}