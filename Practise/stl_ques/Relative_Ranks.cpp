#include<bits/stdc++.h>
using namespace std;
int binary_search(vector<int> scores,int element){
    vector<int> score(scores);
    auto it=find(score.begin(),score.end(),element);
    return it-score.begin();
   
}
int main(){
    vector <int> score={10,3,8,9,4};
//     vector<string> ans(score.size(),"0");
// priority_queue<int> pq(score.begin(),score.end());
// for(int i=0;i<score.size();i++){
//     auto it=find(score.begin(),score.end(),pq.top());
//     int pos=it-score.begin();
//     string s;
//     switch (i+1)
//     {
//     case 1:
//         s="Gold Medal";
//         break;
//     case 2:
//         s="Silver  Medal";
//         break;
//     case 3:
//         s="Bronze Medal";
//         break;
    
//     default:
//     s= to_string(i+1);  
//         break;
//     }
//     ans[pos]=s;
//     pq.pop();
    
// }
 vector<string> ans(score.size(),"0");
priority_queue<pair <int,int>> pq;
        for(int i=0;i<score.size();i++){
            pq.push((make_pair(score[i],i)));
        }
for(int i=0;i<score.size();i++){
   int pos=pq.top().second;
   
    string s;
    switch (i+1)
    {
    case 1:
        s="Gold Medal";
        break;
    case 2:
        s="Silver  Medal";
        break;
    case 3:
        s="Bronze Medal";
        break;
    
    default:
    s= to_string(i+1);  
        break;
    }
    ans[pos]=s;
    pq.pop();
}
      


for(auto x:ans){
    cout<<x<<" ";
}
}