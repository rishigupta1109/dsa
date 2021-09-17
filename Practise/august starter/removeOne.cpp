#include<bits/stdc++.h>
using namespace std;
int main(){
int T;
cin>>T;
while(T--){
    int N;
    cin>>N;
    int array1[N];
    int array2[N-1];
    for(int i=0;i<N;i++){
        cin>>array1[i];
    }
    for(int i=0;i<N-1;i++){
        cin>>array2[i];
    }
    sort(array1,array1+N);
    sort(array2,array2+N-1);
    for(int i=0;i<N;i++){
        int a1=0;
        unordered_map<int,int> m;
        for(int j=0;j<N-1;j++){
            if(a1==i){
                ++a1;
            }
            m[abs(array1[a1]-array2[j])]++;
            a1++;
        }
        if(m.size()==1){
            auto it=m.begin();
            cout<<it->first<<endl;
            break;
        }
    }
} 
}