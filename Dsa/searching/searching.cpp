#include<bits/stdc++.h>
using namespace std;

int linearSearch(int arr[],int n,int key){

    for(int i=0;i<n;i++){
        if(arr[i]==key){
            return i;
        }
    }
    return -1;
}
int binarySearch(int arr[],int n,int key){
    int start=0;
    int end=n-1;
    for(int i=start;i<=end;i++){
        int mid=(start+end)/2;
        if(arr[start]==key){
            return start;
        }
        else if(arr[end]==key){
            return end;
        }
        else if(arr[mid]==key){
            return mid;
        }
        
        else{
            if(key>mid){
            start=mid+1;
        }
        else{
            end=mid-1;
        }
        }
        
    }
    return -1;
}
int main(){
int array[10]={1,2,3,4,5,6,7,8,9,10};
cout<<linearSearch(array,10,4);
 cout<<binarySearch(array,10,1);
}