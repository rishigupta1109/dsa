#include<iostream>
using namespace std;
int linearSearch(int arr[],int n,int key){
    for(int i=0;i<n;i++){
        if(arr[i]==key){
            return i;
        }
    }
    return -1;
}
int BinarySearch(int arr[],int n,int key){
    int s=0;
    int e=n-1;
    for(int i=s;i<=e;i++){
        int mid=(s+e)/2;
        if(arr[s]==key) return s;
        else if(arr[e]==key) return e;
        else if(arr[mid]==key) return mid;

        if(mid>key) e=mid-1;
        else s=mid+1;
    }
    return -1;
}
int recursiveBinarySearch(int arr[],int s,int e,int key){
    int m=(s+e)/2;
    if (arr[s]==key) return s;
    else if(arr[e]==key) return e;
    else if(arr[m]==key) return m;

    if(arr[m]>key){
        return recursiveBinarySearch(arr,s,m-1,key);
    }
    else{
         return recursiveBinarySearch(arr,m+1,e,key);
    }
}
int main(){
    int arr[7]={1,5,7,9,11,13,15};
    cout<<BinarySearch(arr,7,7);
    cout<<linearSearch(arr,7,15);
    cout<<recursiveBinarySearch(arr,0,6,5);
}