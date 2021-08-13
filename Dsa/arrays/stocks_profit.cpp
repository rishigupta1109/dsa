#include<bits/stdc++.h>
using namespace std;
pair <int,int> max_finder(int prices[],int n,int start){
    cout<<"enterd max finder"<<endl;
    pair<int,int> p;
    p.first=INT_MIN;
    p.second=0;
    for (int i = start; i < n; i++)
    {
        if(prices[i]>p.first&&i!=0){
            p.first=prices[i];
            p.second=i;
        }
       
    }
    return p;
}
pair <int,int> min_finder(int prices[],int n,int max_index){
     cout<<"enterd min finder"<<endl;
    pair<int,int> p;
    p.first=INT_MAX;
    p.second=0;
    bool min_found=false;
    for (int i = 0; i < max_index; i++)
    {
        if(prices[i]<p.first){
            p.first=prices[i];
            p.second=i;
            min_found=true;
        }
    }
    if(!min_found){
        pair <int,int> p;
        p.first=-1;
        p.second=-1;
        if(max_index==n){
            return p;
        }
        pair <int,int> maxno=max_finder(prices,n,max_index+1);
        int max_index=maxno.second;
        return min_finder(prices,n,max_index);
    }
    return p;
}
int main(){
    int n;
    cin>>n;
    int prices[n];
    for (int i = 0; i < n; i++)
    {
    cin>>prices[i];
    }
    int min=prices[0];
    int min_index=0;
    int max=prices[0];
    int max_index=0;
    
    pair <int,int> maxno=max_finder(prices,n,0);
    max=maxno.first;
    max_index=maxno.second;
    pair <int,int> minno=min_finder(prices,n,max_index);
    min=minno.first;
    min_index=minno.second;
    if(min==-1){
        cout<<0;
    }
    else{
        cout<<"max :"<<max<<"min:"<<min<<endl<<max-min;
    }
    

    
}