#include<bits/stdc++.h>
using namespace std;
class node{
    public:
    int data;
    node* left;
    node* right;
    int height;
    node(int val){
        data=val;
        left=NULL;
        right=NULL;
        height=1;
    }
};
int getHeight(node* n){
    return n?n->height:0;
}
int getBalanceFactor(node* n){
    return getHeight(n->left)-getHeight(n->right);
}
node* leftRotate(node* x){
    node* y=x->left;
        node* T2=y->right;
        x->left=T2;
        y->right=x;
        x->height=max(getHeight(x->left),getHeight(x->right))+1;
        y->height=max(getHeight(y->left),getHeight(y->right))+1;


    return y;
}
node* rightRotate(node* y){
    cout<<"right rotate"<<endl;
    node* x=y->right;
    
        node* T2=x->left;
        y->right=T2;
    x->left=y;
        y->height=max(getHeight(y->left),getHeight(y->right))+1;
         x->height=max(getHeight(x->left),getHeight(x->right))+1;
        cout<<y->data<<" "<<x->height<<" "<<y->height<<endl;
    return x;
}
node* insert(node* &root,int key){
    if(root==NULL){
        return new node(key);
    }
    if(root->data>key){
        root->left=insert(root->left,key);
    }
    else{
        root->right=insert(root->right,key);
    }
    root->height=max(getHeight(root->left),getHeight(root->right))+1;
    cout<<" "<<getHeight(root->left)<<"  "<<getHeight(root->right)<<endl;
    cout<<"height of"<<root->data<<" is :"<<root->height<<endl;
    int bf=getBalanceFactor(root);
    cout<<"bf of"<<root->data<<" is :"<<bf<<endl;
    if(bf>1&&root->left->data>key){
        root=leftRotate(root);
    }
    else if(bf>1&&root->left->data<key){
        root->left=leftRotate(root->left);
        root=rightRotate(root);
    }
    else if(bf<-1&&root->right->data>key){
        root->right=rightRotate(root->right);
        root=leftRotate(root);
    }
    else if(bf<-1&&root->right->data<key){
        root=rightRotate(root);
    }
    return root;
}
void preOrder(node* root){
    if(root!=NULL){
    cout<<root->data<<" ";
    preOrder(root->left);
    preOrder(root->right);}
}
void levelorder(node* root){
    if(root==NULL){
        return;
    }
    queue<struct node*> Q;
    Q.push(root);
    Q.push(NULL);
    while(!Q.empty()){
        node* temp=Q.front();
        Q.pop();
        if(temp!=NULL){
            cout<<temp->data<<" ";
            if(temp->left!=NULL){
                Q.push(temp->left);
            }
           
            if(temp->right!=NULL){
                Q.push(temp->right);
            }
        }
        else if(!Q.empty()){
            Q.push(NULL);
            cout<<endl;
        }
    }
}
int main(){
    node* root=NULL;
    root=insert(root,1);
    insert(root,2);
    insert(root,3);
    insert(root,4);
    insert(root,5);
    insert(root,6);
    insert(root,7);
    levelorder(root);
   cout<<endl;
    preOrder(root);
}