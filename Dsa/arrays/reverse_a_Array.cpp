#include<iostream>
using namespace std;

void Reverser (int x[],int n){
int temp[n];
for(int i=0;i<=(n-1)/2;i++){
    temp[i]=x[i];
    x[i]=x[(n-1)-i];
    x[(n-1)-i]=temp[i];

}

}

int main(){
    int n;
    cin>>n;
    int array[n];
    for(int i=0;i<n;i++){
        cin>>array[i];
    }
    Reverser(array,n);
    for(int i=0;i<n;i++){
        cout<<array[i];
    }
    
    
}