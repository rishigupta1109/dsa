#include<iostream>
using namespace std;
int main(){
 int arr[] = { -1, 2, -3, 4, 5, 6, -7, 8, 9 }; 
 int s=0,l=8;
 int newarr[9];
 for(int i=0;i<9;i++){
     if(arr[i]<0){
         newarr[s]=arr[i];
         s++;
     }
     else if(arr[i]>=0){
         newarr[l]=arr[i];
         l--;
     }
 }
 for (int i = 0; i < 9; i++)
 {
     cout<<newarr[i]<<" ";
 }
 
}