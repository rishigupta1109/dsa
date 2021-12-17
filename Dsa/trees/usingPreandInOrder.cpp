#include<bits/stdc++.h>
using namespace std;
typedef struct node* NODE;
struct node{
    int data;
    NODE left;
    NODE right;
    node(int value){
        data=value;
    }
};
class BT{
    public:
    NODE Root;
    BT(){Root=NULL;}
    int posnFinder(int A[],int key,int s,int e){
        for(int i=s;i<=e;i++){
            if(A[i]==key){
                return i;
            }
        }
        return -1;
    }
    //Using static variable in recursive function makes it non reusable;
    NODE PreNInORderInsert(int Pre[],int In[],int s,int e){
        static int idx=0;                                         
        if(s>e){
            return NULL;
        }
        NODE child =new node(Pre[idx]);
        
        if(Root==NULL){
            Root=child;
        }
       
        int pos=posnFinder(In,Pre[idx],s,e);
        idx++;
        child->left=PreNInORderInsert(Pre,In,s,pos-1);
        
        child->right=PreNInORderInsert(Pre,In,pos+1,e);

        return child;
    }
    NODE PostNInORderInsert(int Post[],int In[],int s,int e){
        static int idx=e;
        if(s>e){
            return NULL;
        }
      
        NODE child =new node(Post[idx]);
        
        if(Root==NULL){
            Root=child;
        }
       
        int pos=posnFinder(In,Post[idx],s,e);
        idx--;
        child->right=PostNInORderInsert(Post,In,pos+1,e);
        child->left=PostNInORderInsert(Post,In,s,pos-1);
        

        return child;
    }
    

};
void preorder(node* root){
    if(root!=NULL){
        cout<<(root->data)<<" ";
        preorder(root->left);
        preorder(root->right);
    }
}
void postorder(node* root){
    if(root!=NULL){
        postorder(root->left);
        postorder(root->right);
        cout<<(root->data)<<" ";
    }
}
void Inorder(node* root){
    if(root!=NULL){
        Inorder(root->left);
        cout<<(root->data)<<" ";
        Inorder(root->right);
    }
}
int main(){
    BT* tree=new BT();
    int pre[5]={1,2,4,3,5};
    int In[5]={4,2,1,5,3};
    int post[5]={4,2,5,3,1};
    // tree->PreNInORderInsert(pre,In,0,4);
    // preorder(tree->Root);
    tree->PostNInORderInsert(post,In,0,4);
    postorder(tree->Root);
    cout<<endl;
    Inorder(tree->Root);
}