#include<bits/stdc++.h>
using namespace std;
vector<int> pallindromicnumbers(){
    vector<int> nums;
    for(int i=1;i<=1000;i++){
        int decimal=i;
        string binary="";
        while(decimal!=0){
            int remainder=decimal%2;
            decimal=decimal/2;
            binary=to_string(remainder)+binary;
        }
        bool isPallindromic=true;
        for(int j=0;j<binary.length()/2;j++){
            if(binary[j]!=binary[binary.length()-1-j]){
                isPallindromic=false;
            }
        }
        if(isPallindromic){
            nums.push_back(i);
        }
    }
    return nums;
}
int justSmall(int x,vector<int> v){
    int s=0;
    int e=v.size()-1;
    int num,mid;
    while(s<e){
        mid=(s+e)/2;
        if(v[s]==x){
            return v[s];
        }
        else if(v[e]==x){
            return v[e];
        }
        else if(v[mid]==x){
            return x;
        }
        else {
            if(v[s]<x){
                num=v[s];
            }
            if(v[mid]<x){
                num=v[mid];
            }
            if(v[e]<x){
                num=v[e];
            }
            if(v[mid]<x){
                num=v[mid];
                s=mid+1;
            }
            else{
                e=mid-1;
            }
            
        }
    }
    return num;
}
int main(){
vector<int> Nums;
Nums=pallindromicnumbers();
int t;
cin>>t;
while(t--){
    int n;
    cin>>n;
    int count=0;
    vector<int> numbers;
    while(n!=0){
        int x=justSmall(n,Nums);
        count++;
        numbers.push_back(x);
        n=n-x;
    }
    cout<<count<<endl;
    for(auto j:numbers){
        cout<<j<<" ";
    }
    cout<<endl;
}
}