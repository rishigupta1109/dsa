#include<iostream>
using namespace std;
int swap(int A[],int i){
    int temp=A[i];
    A[i]=A[i+1];
    A[i+1]=temp;
    return (A[i+1]-A[i]);
}
int search(int B[],int N,int key){
    for(int i=0;i<N;i++){
        if(B[i]==key){
            return i;
        }
    }
    return -1;
}
int main(){
int t;
cin>>t;
while(t--){
    int N;
    cin>>N;
    int A[N],B[N];
    for(int i=0;i<N;i++){
        cin>>A[i];
    }
    for(int i=0;i<N;i++){
        cin>>B[i];
    }
    int idx=0;
    int points=0;
    for(int i=N-1;i>0;i--){
        int posn=search(B,N,A[i]);
        for(int j=posn;j<i;j++){
            points+=swap(A,j);
        }
    }
    cout<<points<<endl;
} 
}