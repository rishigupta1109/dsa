#include<bits/stdc++.h>
using namespace std;
 int findDuplicate(vector<int>& nums) {
        int repeated_num;
        for(int i=0;i<nums.size();i++){
            for(int j=i+1;j<nums.size();j++){
                if(nums[i]==nums[j]){
                    repeated_num=nums[i];
                    break;
                }
            }
        }
        return repeated_num;
    }
int main(){
 int n;
 cin>>n;
 vector<int> array;
 for (int i = 0; i < n; i++)
 {
     int x;
     cin>>x;
     array.push_back(x);
 }
 cout<<findDuplicate(array);
 
}