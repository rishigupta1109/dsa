#include<bits/stdc++.h>
using namespace std;
 vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        deque<int> d;
        vector<int> ans;
        for(int i=0;i<nums.size();i++){
          
                while(!d.empty()&&nums[d.back()]<nums[i]){
                    d.pop_back();
                }
            
            if(!d.empty()&&(d.front()==i-k)){
                d.pop_front();
            }
                d.push_back(i);
            if(i>=k-1){
                ans.push_back(nums[d.front()]);
            }
           
        }
        return ans;
    }
int main(){
    vector<int> v;
    v.push_back(1);
    v.push_back(3);
    v.push_back(-1);
    v.push_back(-3);
    v.push_back(5);
    v.push_back(3);
    v.push_back(6);
    v.push_back(7);
    vector<int> ans=maxSlidingWindow(v,3);
    for(auto i:ans){
        cout<<i<<" ";
    }
 
}