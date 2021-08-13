#include<bits/stdc++.h>
using namespace std;
int getMinDiff(int arr[], int n, int k) {
        int max=arr[0],min=arr[0];
        for(int i=0;i<n;i++){
            if(arr[i]-k>0){
                arr[i]=arr[i]-k;
                if(arr[i]<min){
                    min=arr[i];
                }
            }
            else{
                arr[i]=arr[i]+k;
                if(arr[i]>max){
                    max=arr[i];
                }
            }
        }
        
        return max-min;
    }
int main(){
 
}