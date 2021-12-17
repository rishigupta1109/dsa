#include<bits/stdc++.h>
using namespace std;
int main(){
int t;
cin>>t;
while(t--){
    int n;
    cin>>n;
    vector<int> arr(n);
    for(int i=0;i<=n-1;i++){
        cin>>arr[i];
    }
    sort(arr.begin(),arr.end(),greater<int>());
    bool duplicates=false;
    if(arr[0]==arr[1]){
        cout<<-1<<endl;
    }
    else{
        for(int i=0;i<n-1;i++){
            if(arr[i]==arr[i+1]){
                duplicates=true;
                break;
            }
        }
        if(!duplicates){
            for(int i=0;i<n;i++){
                cout<<arr[i]<<" ";
            }
            cout<<endl;
        }
        else{
            map<int,int> m;
            for(int i=0;i<n;i++){
                m[arr[i]]++;
            }
            vector<int> ans;
            bool eject=false;
            for(auto k:m){
                ans.push_back(k.first);
                m[k.first]--;
                k.second--;
               
                
                if(k.second>1){
                    cout<<-1<<endl;
                    eject=true;
                    break;
                }
            }
            if(!eject){
            vector<int> anst;
            for(auto k:m){
                if(k.second!=0)
                { anst.push_back(k.first);}
            }
            for(int i=anst.size()-1;i>=0;i--){
                ans.push_back(anst[i]);
            }
           
            for(int i=ans.size()-1;i>=0;i--){
                cout<<ans[i]<<" ";
            }
            cout<<endl;}
        }
    }
} 
}