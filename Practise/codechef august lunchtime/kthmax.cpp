#include<bits/stdc++.h>
using namespace std;
int main(){
int T;
cin>>T;
while(T--){
    deque<pair<long long int,long long int>> dq;
    long long int N,k;
    cin>>N>>k;
    long long int array[N];
    long long int max=INT_MIN;
    long long int maxi=INT_MIN;
    for(int i=0;i<N;i++){
        cin>>array[i];
        if(array[i]>max){
            max=array[i];
            maxi=i;
        }
    }
    dq.push_front({max,maxi});
    for(int i=k-1;i<N;i++){
        if(i==maxi){
            continue;
        }
        if(array[i]>dq.front().first){
            while(!dq.empty()){
                dq.pop_front();
            }
             dq.push_front({array[i],i});
        }
        else if(array[i]==dq.front().first){
            dq.push_front({array[i],i});
        }
    }
    if(maxi<k-1){
        dq.pop_back();
    }
    long long int total=dq.size();
    while(!dq.empty()){
        long long int y=dq.front().second;
        dq.pop_front();
        total += N-y-1;
    }
    cout<<total<<endl;
} 
}