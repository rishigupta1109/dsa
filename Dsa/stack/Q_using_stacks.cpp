#include<bits/stdc++.h>
using namespace std;
class MyQueue {
public:
    stack<int>* queue;
    MyQueue() {
        queue=new stack<int>();
    }
    
    /** Push element x to the back of queue. */
    void push(int x) {
       queue->push(x); 
    }
    
    /** Removes the element from in front of queue and returns that element. */
    int pop() {
        vector<int> v;
        while(!queue->empty()){
            int x=queue->top();
            v.push_back(x);       
            queue->pop();
        }
        for(int i=v.size()-2;i>=0;i--){
            queue->push(v[i]);
        }
        return v[v.size()-1];
        
    }
    int pop_using_funcCallStack(){
        int x=queue->top();
     
        queue->pop();
        if(queue->empty()){
            return x;
        }
        int y=pop_using_funcCallStack();
        queue->push(x);
       
        return y;
    }
    
    /** Get the front element. */
    int peek() {
        vector<int> v;
        while(!queue->empty()){
            int x=queue->top();
            v.push_back(x);       
            queue->pop();
        }
        for(int i=v.size()-1;i>=0;i--){
            queue->push(v[i]);
        }
        return v[v.size()-1];
    }
    
    /** Returns whether the queue is empty. */
    bool empty() {
       return queue->empty(); 
    }
};

int main(){
    MyQueue MYQ;
    MYQ.push(1);
    MYQ.push(2);
    MYQ.push(3);
    MYQ.push(4);
    cout<<MYQ.pop_using_funcCallStack();
    cout<<MYQ.pop_using_funcCallStack();
    cout<<MYQ.pop_using_funcCallStack();
}