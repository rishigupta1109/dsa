#include<bits/stdc++.h>
using namespace std;
class node{
public:
int data;
node* previous;
node* next;
node(int val,node* prev=NULL){
    data=val;
    next=NULL;
    previous=prev;
}
};
void insert_at_tail(node* &head,int val){
    if(head==NULL){
    node* child=new node(val);
    head=child;
    }
    else{
        node* temp=head;
        while(temp->next!=NULL){
            temp=temp->next;
        }
        node* child=new node(val,temp);
        temp->next=child;
    }
}
void insert_at_head(node* &head,int val){
    node* child=new node(val);
    child->next=head;
    head->previous=child;
    head=child;
}
void insert_at_index(node* &head,int index,int value){
    if(index==0){
        insert_at_head(head,value);
        return;
    }
    int k=0;
    node* temp=head;
   while(k!=index-1){
       ++k;
       temp=temp->next;
   }
    node* child=new node(value,temp);
    child->next=temp->next;
    temp->next=child;
    if(child->next!=NULL){
    child->next->previous=child;
    }
    
}
void delete_at_tail(node* head){
        node* temp=head;
    while(head->next!=NULL){
        temp=head;
        head=head->next;
    }
    temp->next=NULL;
    delete head;
}
void delete_at_head(node* &head){   
    node* temp=head;
    head=head->next;
    head->previous=NULL;
    delete temp;
}
void delete_at_index(node* &head,int index){
int k=0;
if(index==0){
    delete_at_head(head);
}
node* temp=head;
while(k!=index-1){
    temp=temp->next;
    ++k;
}
node* target=temp->next;
temp->next=target->next;
if(target->next!=NULL){target->next->previous=temp;}

delete target;
}
void print(node* head){
    node* temp;
    while(head!=NULL){
        cout<<head->data<<"->";
        temp=head;
        head=head->next;
    }
    cout<<"NULL"<<endl;
    while(temp!=NULL){
        cout<<temp->data<<"->";
        temp=temp->previous;
    }
     cout<<"NULL"<<endl;
}
int length(node* head){
    int length=1;
    if(head==NULL){
        return 0;
    }
    while(head->next!=NULL){
        length++;
        head=head->next;
    }
    return length;
}


int main(){
 node* head=NULL;
 insert_at_tail(head,1);
 insert_at_tail(head,5);
 insert_at_tail(head,8);
 insert_at_tail(head,19);
//  print(head);
 insert_at_head(head,22);
//  print(head);
 insert_at_index(head,5,32);
//  print(head);
 delete_at_tail(head);
//  print(head);
 delete_at_head(head);
//  print(head);
 delete_at_index(head,3);
 print(head);
 cout<<length(head);

}