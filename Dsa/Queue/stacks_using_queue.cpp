#include<bits/stdc++.h>
using namespace std;
class Queue{
public:
int* queue;
int front;
int rear;
int size=100;
Queue(){
    front=-1;
    rear=-1;
    queue=new int[100];
}
int enqueue(int val){
if(front==-1){
++front;
}
return queue[++rear]=val;
}
int dequeue(){
    if(rear==front){
        rear=front=-1;
        return -1;
    }
    return queue[front++];
}
bool empty(){
    return rear==-1;
}
};
class MyStack {
public:
    Queue* Q;
    MyStack() {
        Q=new Queue();
    }
    
    /** Push element x onto stack. */
    void push(int x) {
        Q->enqueue(x);
    }
    
    /** Removes the element on top of the stack and returns that element. */
    int pop() {
        Queue* newq= new Queue();
        int x=Q->queue[Q->rear];
        while(Q->front!=Q->rear){
            int x=Q->dequeue();
            newq->enqueue(x);
        }
        Queue* target=Q;
        Q=newq;
        delete target;
        return x;
    }
    int pop_using_oneQ(){
        vector<int> v;
        while(!Q->empty()){
            int x=Q->dequeue();
            v.push_back(x);
        }
        for(int i=0;i<v.size()-1;i++){
            Q->enqueue(v[i]);
        }

    }
    
    /** Get the top element. */
    int top() {
        return Q->queue[Q->rear];
    }
    
    /** Returns whether the stack is empty. */
    bool empty() {
        return Q->empty();
    }
};

int main(){
 MyStack Stacky;
Stacky.push(1);
Stacky.push(2);
cout<<Stacky.pop();
cout<<Stacky.top();

 
}
