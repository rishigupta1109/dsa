#include<bits/stdc++.h>
using namespace std;
class node{
    public:
int data ;
node* next;
node(int value){
    data=value;
    next=NULL;
}
};
void insert_at_tail(node* &head,int value){
    node* child=new node(value);
    if(head==NULL){
        head=child;
        child->next=head;
    }
    else{
        node* temp=head;
        while(temp->next!=head){
            temp=temp->next;
        }
        temp->next=child;
        child->next=head;
    }

}
void print(node* head){
    node* temp=head;
do{      
    cout<<temp->data<<"->";
    temp=temp->next;
}
while(temp!=head);
 
cout<<"NULL"<<endl;
}
void insert_at_head(node* &head,int value){
    node* child=new node(value);
    if(head==NULL){
        head=child;
        head->next=head;
        return;
    }
    node* temp=head;
    child->next=head;
    do{
        temp=temp->next;
    }
    while(temp->next!=head);
    head=child;
    temp->next=head;

}
int length(node* head){
    node* temp=head;
    int length=1;
    do{
        temp=temp->next;
        length++;
    }
    while(temp->next!=head);
    return length;
}
void insert_at_index(node* &head,int index,int value){
if(index==0){
    insert_at_head(head,value);
}
else if(index==(length(head)-1)){
 insert_at_tail(head,value);
}
else{
    int k=0;
    node* temp=head;
    while(k!=(index-1)){
        temp=temp->next;
        k++;
    }
    node* child=new node(value);
    node* next=temp->next;
    temp->next=child;
    child->next=next;
}
}

int main(){
    node* head=NULL;
    insert_at_tail(head,1);
    insert_at_tail(head,3);
    insert_at_tail(head,7);
    insert_at_tail(head,8);
    insert_at_tail(head,11);
    insert_at_head(head,0);
    print(head);
    insert_at_index(head,2,5);
    print(head);
    cout<<length(head);
}