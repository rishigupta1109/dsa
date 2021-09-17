#include<bits/stdc++.h>
using namespace std;
class DQ{
    public:
    int* Queue;
    int front;
    int rear;
    int size;
    DQ(int s){
        size=s;
        front=rear=-1;
        Queue=new int[s];
    }
    void enqueueF(int value){
        if(front!=0){
            Queue[--front]=value;
        }
    }
    void enqueueR(int value){
        if(rear!=size-1){
            Queue[++rear]=value;
            if(front==-1){
                front++;
            }
        }
    }
    void dequeueF(){
        if(front==rear){
            front=rear=-1;
        }
        else if(front!=(size-1)){
            front++;
        }
    }
    void dequeueR(){
         if(front==rear){
            front=rear=-1;
        }
        else if(rear!=-1){
            rear--;
        }
    }
    bool isEmpty(){
        return front==-1;
    }
    void print(){
        for(int i=front;i<=rear;i++){
            cout<<Queue[i]<<" ";
        }
        cout<<endl;
    }
};
int main(){
    DQ* hybridLine=new DQ(5);
    hybridLine->enqueueR(5);
    hybridLine->enqueueR(4);
    hybridLine->enqueueR(3);
    hybridLine->enqueueR(2);
    hybridLine->enqueueR(1);
    cout<<hybridLine->isEmpty()<<endl;
    hybridLine->print();
    hybridLine->dequeueR();
    hybridLine->dequeueR();
    hybridLine->dequeueF();
    hybridLine->dequeueF();
    hybridLine->print();
    hybridLine->enqueueF(4);
    hybridLine->enqueueF(5);
    hybridLine->print();
    hybridLine->enqueueR(5);
    hybridLine->enqueueR(5);
    hybridLine->print();

}