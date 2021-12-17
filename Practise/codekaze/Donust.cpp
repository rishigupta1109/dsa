#include<bits/stdc++.h>
using namespace std;
int main(){
int t;
cin>>t;
while(t--){
    int n;
    cin>>n;
    int arr[n+1];
    for(int i=1;i<=n;i++){
        cin>>arr[i];
    }
    sort(arr+1,arr+n+1);
    int i=1;
    int j=n;
    int weight=0;
    while(j!=i){
        j=n-2;
        n=j-1;
        weight+=arr[j];
        i++;
    }
    cout<<weight<<endl;
} 
}