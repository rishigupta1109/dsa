#include<bits/stdc++.h>
using namespace std;
template<class t>
class Q{
public:
t *Queue;
int top;
int bottom;
int size;
 Q(int s){
    size=s;
    Queue=new t[s];
    top=-1;
    bottom=-1;
}
void enqueue(t value){
    if(top!=size-1){
    Queue[++top]=value;
    }
}
void dequeue(){
    if(top!=bottom){
        bottom++;
    }
    else{
        top=bottom=-1;
    }
}
bool isEmpty(){
    return (top==bottom);
}
void print(){
    for(int i=bottom+1;i<=top;i++){
        cout<<Queue[i]<<" ";
    }
}
t peek(int position){
    return Queue[position+bottom];
}

};

int main(){
    Q<int>* line=new Q<int>(5);
    //4 3 2 1
    line->enqueue(4);
    line->enqueue(3);
    line->enqueue(2);
    line->enqueue(1);
    line->enqueue(5);
    line->enqueue(6);
    
    line->dequeue();
    line->dequeue();
    line->dequeue();
    line->dequeue();
    line->dequeue();
    line->dequeue();
    line->print();
    line->enqueue(5);
    cout<<line->peek(1);


}