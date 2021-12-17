#include <iostream>
using namespace std;
void print (int arr[],int n){
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";

    }
    cout<<endl;
}
void insert(int arr[],int element,int n){
    if(arr[n-1]<element||n==0){
        arr[n]=element;
        return;
    }
    arr[n]=arr[n-1];
    insert(arr,element,n-1);
}
void sort(int arr[],int n){
    if(n==0){
        return;
    }
    sort(arr,n-1);
    insert(arr,arr[n],n);
}
int main(){
    int array[]={5,2,1,3,4};
    print(array,5);
    sort(array,5);
    print(array,5);
}