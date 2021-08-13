#include<bits/stdc++.h>
using namespace std;
class node{
public:
pair<char,int> p;
node* next;
node(pair<char,int> value){
    next=NULL;
    p=value;
}
};
class Stack{
public:
node* top;
node* bottom;
int used_size;
Stack(){
    top=NULL;
    bottom=NULL;
    used_size=0;
}
void push(pair<char,int> p){
    node* child=new node(p);
    if(top==NULL){
        top=child;
        bottom=child;
    }
    else{
        top->next=child;
        top=child;
    }

    used_size++;
}
pair<char,int> pop(){
    pair<char,int> p;
     if(top!=bottom){
           node* tail=bottom;
        while(tail->next->next!=NULL){
            tail=tail->next;
        }
         top=tail;
         tail=tail->next;
        top->next=NULL;
        p=tail->p;
        delete tail;
    }
    else {
        node* tail=top;
        p=tail->p;
         top=NULL;
        bottom=NULL;
        delete tail;
     }
     used_size--;
            return p;
}
bool isEmpty(){
    if(top==NULL){  return true;}
   
    else {return false;}
    }
};
int main(){
    string s;
    Stack sa;
    vector<char> answer;
    getline(cin,s);
    for(int i=0;i<s.length();i++){
        if(s[i]=='*'||s[i]=='/'){
       
                pair<char,int> p;
                p.first=s[i];
                p.second=2;
            if(sa.isEmpty()){
                sa.push(p);
            }
            else{
                if(sa.top->p.second>=p.second){
                    for(int i=0;i<sa.used_size;i++){
                        answer.push_back((sa.pop()).first);
                    }
                    sa.push(p);
                }
                else{
                    sa.push(p);
                }
            }
        }
        else if(s[i]=='+'||s[i]=='-'){
          
            pair<char,int> p;
                p.first=s[i];
                p.second=1;
            if(sa.isEmpty()){
                sa.push(p);
            }
            else{
                if(sa.top->p.second>=p.second){
                    int x=sa.used_size;
                    for(int i=0;i<x;i++){
                        auto pa=(sa.pop()).first;
                        
                        answer.push_back(pa);
                    }
                    sa.push(p);
                }
                 else{
                    sa.push(p);
                }
            }
        }
        else if(s[i]=='^'){
          
            pair<char,int> p;
                p.first=s[i];
                p.second=3;
            if(sa.isEmpty()){
                sa.push(p);
            }
            else{
                if(sa.top->p.second>=p.second){
                    int x=sa.used_size;
                    for(int i=0;i<x;i++){
                        auto pa=(sa.pop()).first;
                        
                        answer.push_back(pa);
                    }
                    sa.push(p);
                }
                 else{
                    sa.push(p);
                }
            }
        }
        else if(s[i]==')'){
             int x=sa.used_size;
              for(int i=0;i<x;i++){
                        auto pa=(sa.pop()).first;
                        if(pa=='('){
                            break;
                        }
                        answer.push_back(pa);
                    }
        }
        else if(s[i]=='('){

        }
        else{
            answer.push_back(s[i]);
        }
    }
  int x=sa.used_size;
    for(int i=0;i<x;i++){
        answer.push_back((sa.pop()).first);
    }
    for(int i=0;i<answer.size();i++){
        cout<<answer[i];
    }
}