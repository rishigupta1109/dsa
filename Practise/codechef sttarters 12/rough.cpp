#include<bits/stdc++.h>
using namespace std;
bool sorted(int a,int b){
    return a%2!=0;
}
int main(){
vector<pair<int,int>> p={{5,5},{6,6},{7,7}}; 
sort(p.begin(),p.end(),[](pair<int,int> a,pair<int,int> b){return a.first%2!=0;});
for(int i=0;i<3;i++){
    cout<<p[i].first<<" ";
}

}