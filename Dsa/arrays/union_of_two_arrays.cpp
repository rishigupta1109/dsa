#include<bits/stdc++.h>
using namespace std;
int doUnion(int a[], int n, int b[], int m)  {
        map<int,int> maps;
        for(int i=0;i<n;i++){
            maps.insert(make_pair(a[i],i));
        }
        for(int i=0;i<m;i++){
            maps.insert(make_pair(b[i],i));
        }
        return maps.size();
        
    }
int main(){
 
}