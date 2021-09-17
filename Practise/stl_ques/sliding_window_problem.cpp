#include<bits/stdc++.h>
using namespace std;
void print(deque<int> &i){
    for(auto x:i){
        cout<<x<<" ";
    }
    cout<<endl;
}
int main(){
    vector<int> nums={9,10,9,-7,-4,-8,2,-6};
    int k=5;
    deque<int> dq;
      vector<int> v;
      for(int i=0;i<nums.size();i++){
          while(!dq.empty()&&i-dq.front()>=k){
              dq.pop_front();
          }
          while(!dq.empty()&&nums[dq.back()]<nums[i]){
              dq.pop_back();
          }
          dq.push_back(i);
          if(i>=k-1){
              v.push_back(nums[dq.front()]);
          }
      }
     
        for(auto &x:v){
            cout<<x<<" ";
        }
      

}