#include<bits/stdc++.h>
using namespace std;
void rotate(int arr[], int n)
{
    int a[n];
    a[0]=arr[n-1];
    for(int i=1;i<n;i++){
        a[i]=arr[i-1];
    }
    
    for(int i=0;i<n;i++){
        arr[i]=a[i];
    }
    
}
int main(){
    int n;
    cin>>n;
 int arr[n];
 rotate(arr,n);
 for (int i = 0; i < n; i++)
 {
     cout<<arr[i];
 }
 
}