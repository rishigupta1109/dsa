#include<bits/stdc++.h>
using namespace std;
class Stack{
public:
int* Array;
int size;
int top;
Stack(int s){
    size=s;
    top=-1;
    Array=new int[s];
}
void push(int value){
    Array[++top]=value;
}
int pop(){
    return Array[top--];
}
bool isEmpty(){
    if(top==-1){
        return true;
    }
    return false;
}
int peek(int position){
    int index=top-position+1;
    return Array[index];
}

};
int main(){
 int T;
  vector<string> Answer; 
 cin>>T;
 while(T--){
     int N;
     cin>>N;
    
      Stack storage(N);
      Stack Ans(N);
     for(int i=0;i<N;i++){
         int x;
         cin>>x;
         storage.push(x);   
     }
     map<int,int> m;
     
     for(int i=0;i<N;i++){
             
         int a=storage.pop();
         int count=0;
         if(m.find(a)!=m.end()){ count=m[a];}
         else{
             count=0;
         for(int j=1;j<=(storage.top+1);j++){
             if(storage.peek(j)==a){
                 ++count;
             }
             else if(storage.peek(j)>a){
                 break;
             }

         }
         } 
        
         m[a]=count;
         vector<int> tobeerased;
        for(auto x:m){
            
            if(x.first<a){
                tobeerased.push_back(x.first);
            }
        }
        for(int j=0;j<tobeerased.size();j++){
            m.erase(tobeerased[i]);
        }
        
         Ans.push(count);
     }
    
     string s;
    int y=Ans.top;
     for(int i=0;i<=y;i++){
         string x=to_string(Ans.pop());
       
         if(i==Ans.top){
            s=s+x;
         }
         else{
            s=s+x+" ";
         }
     }
   
     Answer.push_back(s);
 }
 
 for(int i=0;i<Answer.size();i++){
     cout<<Answer[i]<<endl;
     
 }

 
}