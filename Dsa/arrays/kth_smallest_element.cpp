#include<bits/stdc++.h>
using namespace std;

int kthSmallest(int arr[], int l, int r, int k) {
    map<int,int> m;
        for(int i=0;i<=r;i++){
            m[arr[i]]=i;  
        }
       
        
        map<int,int> ::iterator iter=m.begin();
        for(int i=0;i<k-1;i++){
            iter++;
        }
        int x=(*iter).first;
        return x;
    }

int main(){
 int arr[6]={7 ,10 ,4 ,3 ,20 ,15};
 cout<<kthSmallest(arr,0,5,3);
}

