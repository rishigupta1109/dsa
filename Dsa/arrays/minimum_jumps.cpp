#include<bits/stdc++.h>

using namespace std;
int minJumps(int arr[], int n){
       
       int position=0;
       int min_jumps=0;
       while(true){
           if(arr[position]==0){
               min_jumps=-1;
               break;
           }
           position=position+arr[position];
           min_jumps++;
           if(position>=n){
               break;
           }
           
       }
       return min_jumps;
    }
int main(){
 
}