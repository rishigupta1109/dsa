#include<bits/stdc++.h>
using namespace std;
class node{
    public:
    int* data;
    node* left;
    node* right;   
    node(int val){
        data=new int(val);
        left=NULL;
        right=NULL;
    }
};
void preorder(node* root){
    if(root!=NULL){
        cout<<*(root->data)<<" ";
        preorder(root->left);
        preorder(root->right);
    }
}
void postorder(node* root){
    if(root!=NULL){
        postorder(root->left);
        postorder(root->right);
        cout<<*(root->data)<<" ";
    }
}
void Inorder(node* root){
    if(root!=NULL){
        Inorder(root->left);
        cout<<*(root->data)<<" ";
        Inorder(root->right);
    }
}
int height(node* root){
    if(root==NULL) return 0;

    return height(root->left)+height(root->right)+1;
}
//this check balance takes o(N^2) because of usage of height func which takes O(N);
bool checkBalance(node* root){
    if(root==NULL) return true;

    if(!checkBalance(root->left)) return false;
    if(!checkBalance(root->right))return false;

    return abs(height(root->right)-height(root->left))<=1;
}
bool checkBalancewithHeight(node* root,int* height){
    if(root==NULL) return true;
    int rh=0,lh=0;
    if(!checkBalancewithHeight(root->left,&lh)) return false;
    if(!checkBalancewithHeight(root->right,&rh)) return false;
    *height=rh+lh+1;
    return abs(rh-lh)<=1;
}
void rightview(node* root){
    if(root==NULL) return ;
    queue<node*> Q;
    Q.push(root);
    Q.push(NULL);
    while(!Q.empty()){
        node* temp1=Q.front();
        Q.pop();
        node* temp2=NULL;
        if(!Q.empty())
        temp2=Q.front();

        if(!Q.empty()&&temp2==NULL){
            cout<<*temp1->data<<" ";
        }
        if(!Q.empty()&&temp1==NULL){
            Q.push(NULL);
        }
        else if(!Q.empty()&&temp1!=NULL){
           if(temp1->left!=NULL) Q.push(temp1->left);
            if(temp1->right!=NULL)Q.push(temp1->right);
        }
    }
}
void leftView(node* root){
     if(root==NULL) return ;
    queue<node*> Q;
    Q.push(root);
    Q.push(NULL);
    cout<<*root->data<<" ";
    while(!Q.empty()){
        node* temp1=Q.front();
        Q.pop();
        node* temp2=NULL;
        if(!Q.empty())
        temp2=Q.front();

        if(!Q.empty()&&temp1==NULL&&temp2!=NULL){
            cout<<*temp2->data<<" ";
        }
        if(!Q.empty()&&temp1==NULL){
            Q.push(NULL);
        }
        else if(!Q.empty()&&temp1!=NULL){
           if(temp1->left!=NULL) Q.push(temp1->left);
            if(temp1->right!=NULL)Q.push(temp1->right);
        }
    }
}

bool getpath(node* root,int n,vector<int> &v){
    if(root==NULL){
        return false;
    }
    v.push_back(*root->data);
    if(*root->data==n){
        return true;
    }
    if(!getpath(root->left,n,v)&&!getpath(root->right,n,v)){
        v.pop_back();
        return false;
    }
    return true;
}
int LAC(node *root,int n1,int n2){
    vector<int> path1,path2;
    bool p1=getpath(root,n1,path1);
    bool p2=getpath(root,n2,path2);
   
    if(!p1||!p2){
        return -1;
    }
    int pc;
    for(pc=0;pc<path1.size()&&path2.size();pc++){
        if(path1[pc]!=path2[pc]){
            break;
        }
    }
    return path1[pc-1];
}
int minimumDistance(node *root,int n1,int n2){
     vector<int> path1,path2;
    bool p1=getpath(root,n1,path1);
    bool p2=getpath(root,n2,path2);
   
    if(!p1||!p2){
        return -1;
    }
    int pc;
    for(pc=0;pc<path1.size()&&path2.size();pc++){
        if(path1[pc]!=path2[pc]){
            break;
        }
    }
    int distance=0;
    bool found=false;
    for(int i=pc;i<path1.size()-1;i++){
        distance++;
    }
    for(int i=pc;i<path2.size()-1;i++){
        distance++;
    }
    return distance+1;
}
void preOrderIteratively(node* root){
    if(root==NULL){
        return ;
    }
    stack<node* > s;
    cout<<*root->data<<" ";
    s.push(root->right);
    s.push(root->left);
    while(!s.empty()){
        node* temp=s.top();
        cout<<*temp->data<<" ";
        s.pop();
        if(temp->right!=NULL)
        s.push(temp->right);
        if(temp->left!=NULL)
        s.push(temp->left);
    }
}
void inOrderiteratively(node* root){
    if(root==NULL) return;
    stack<node*> s;
    s.push(root);
    node* temp=root->left;

    while(!s.empty()){
        if(temp){
            s.push(temp);
        }
        else{
            temp=s.top();
            s.pop();
            cout<<*temp->data<<" ";
            temp=temp->right;
            if(temp!=NULL)
                s.push(temp);
        }   
            if(temp!=NULL)
                 temp=temp->left;
    }
}
void postOrderIteratively(node* root){
    if(root==NULL){return;}
    stack<node*> s1;
    stack<node*> s2;
    s1.push(root);
    node* temp=NULL;
    while(!s1.empty()){
        temp=s1.top();
        s1.pop();
        s2.push(temp);
        if(temp->left!=NULL){
            s1.push(temp->left);
        }
        if(temp->right!=NULL){
            s1.push(temp->right);
        }
    }
    while(!s2.empty()){
        temp=s2.top();
        cout<<*temp->data<<" ";
        s2.pop();
    }
}
void postOrderTraversalIterativelyUsingoneStack(node* root){
    node* curr=root;
    node* temp;
    stack<node*> s;
    while(curr!=NULL||!s.empty()){
        if(curr!=NULL){
            s.push(curr);
            curr=curr->left;
        }
        else{
            temp=s.top()->right;
            if(temp==NULL){
                temp=s.top();
                s.pop();
                cout<<*temp->data<<" ";
                while(!s.empty()&&temp==s.top()->right){
                    temp=s.top();
                    s.pop();
                    cout<<*temp->data<<" ";
                }
            }
            else{
                curr=temp;
            }
        }

    }
}
void allOrderUsingoneStack(node* root){
    vector<int> pre,post,in;
    stack<pair<node*,int>> s;
    s.push({root,1});
    while(!s.empty()){
        pair<node*,int> x=s.top();
        if(x.second==1){
            pre.push_back(*x.first->data);
            s.top().second++;
            if(x.first->left){
                s.push({x.first->left,1});
            }
        }
        else if(x.second==2){
            in.push_back(*x.first->data);
            s.top().second++;
            if(x.first->right){
                s.push({x.first->right,1});
            }
        }
        else{
            post.push_back(*x.first->data);
            s.pop();
        }
    }
    for(int i=0;i<pre.size();i++){
        cout<<pre[i]<<" ";
    }
    cout<<endl;
    for(int i=0;i<pre.size();i++){
        cout<<in[i]<<" ";
    }
    cout<<endl;
    for(int i=0;i<pre.size();i++){
        cout<<post[i]<<" ";
    }
    

}
int maximumPathSum(node* root,int &maxi){
    if(root==NULL){return 0;}
    int leftSum=max(0,maximumPathSum(root->left,maxi));
    int rightSum=max(0,maximumPathSum(root->right,maxi));
    maxi=max(maxi,leftSum+rightSum+*root->data);
    
    return max(leftSum,rightSum)+*root->data;

}
bool isIdenticle(node* n1,node* n2){
    if(!n1||!n2){
        return n1==n2;
    }
    return (*n1->data==*n2->data)&&isIdenticle(n1->left,n2->left)&&isIdenticle(n1->right,n2->right);
}
void zigzagTraversal(node* root){
    vector<int> result;
    queue<node*> q;
    q.push(root);
    bool flag=true;
    while(!q.empty()){
        int size=q.size();
        vector<int> v(size);
        for(int i=0;i<size;i++){
            node* temp=q.front();
            if(temp->left){
                q.push(temp->left);
            }
            if(temp->right){
                q.push(temp->right);
            }
            q.pop();
            if(flag){
                v[i]=*temp->data;
            }
            else{
                v[size-1-i]=*temp->data;
            }
        }
        flag=!flag;

        for(int i=0;i<size;i++){
            result.push_back(v[i]);
        }
    }
    for(int i=0;i<result.size();i++){
        cout<<result[i]<<" ";
    }
    cout<<endl;
}
bool isLeafNode(node* root){
    return !root->left&&!root->right;
}
void addLeftBoundary(node* root,vector<int> &v){
    node* curr=root;
    while(!isLeafNode(curr)){
        if(!isLeafNode(curr)){
            v.push_back(*curr->data);
        }
        if(curr->left){
            curr=curr->left;
        }
        else{
            curr=curr->right;
        }
    }
}
void addLeafNodes(node* root,vector<int> &v){
    if(isLeafNode(root)){
        v.push_back(*root->data);
        return;
    }
    addLeafNodes(root->left,v);
    addLeafNodes(root->right,v);

}
void addRightBoundary(node* root,vector<int> &v){
    vector<int> temp;
    node* curr=root;
    while(!isLeafNode(curr)){
        if(!isLeafNode(curr)){
            temp.push_back(*curr->data);
        }
        if(curr->right){
            curr=curr->right;
        }
        else{
            curr=curr->left;
        }
    }
    for(int i=temp.size()-1;i>=0;i--){
        v.push_back(temp[i]);
    }
}
void boundaryTraversal(node* root){
    if(root==NULL) return;
    vector<int> v;
    if(!isLeafNode(root)){v.push_back(*root->data);}
    addLeftBoundary(root->left,v);
    addLeafNodes(root,v);
    addRightBoundary(root->right,v);
    for(int i=0;i<v.size();i++){
        cout<<v[i]<<" ";
    }
} 
void verticleTraversal(node* root){
    if(!root)return;
    queue<pair<node* ,pair<int,int>>> q;
    map<int,map<int,multiset<int>>> m;
    q.push({root,{0,0}});
    while(!q.empty()){
        node* temp=q.front().first;
        int x=q.front().second.first;
        int y=q.front().second.second;
        m[x][y].insert(*temp->data);
        if(temp->left)
        q.push({temp->left,{x-1,y+1}});
        if(temp->right)
        q.push({temp->right,{x+1,y+1}});
        q.pop();
    }
 
    for(auto p:m){
       for(auto q:p.second){
           for(auto r:q.second){
               cout<<r<<" ";
           }
       }
       cout<<endl;
    }

}
void bottomView(node* root){
    if(root==NULL) return;
    queue<pair<node* ,int>> q;
    map<int,int> m;
    q.push({root,0});
    while(!q.empty()){
        node* temp=q.front().first;
        int x=q.front().second;
        m[x]=*temp->data;
        if(temp->left)
        q.push({temp->left,x-1});
        if(temp->right)
        q.push({temp->right,x+1});
        q.pop();
    }
    for(auto p:m){
        cout<<p.second<<" ";
    }
}
void topView(node* root){
     if(root==NULL) return;
    queue<pair<node* ,int>> q;
    map<int,int> m;
    q.push({root,0});
    while(!q.empty()){
        node* temp=q.front().first;
        int x=q.front().second;
        if(m.find(x)==m.end())
        m[x]=*temp->data;
        if(temp->left)
        q.push({temp->left,x-1});
        if(temp->right)
        q.push({temp->right,x+1});
        q.pop();
    }
    for(auto p:m){
        cout<<p.second<<" ";
    }
}
bool symmetricHelp(node* Left,node* Right){
    if(!Left||!Right){
        return Left==Right;
    }
    if(*Left->data!=*Right->data){
        return false;
    }
    return symmetricHelp(Left->left,Right->right)&&symmetricHelp(Left->right,Right->left);
}
bool isSymmetric(node* root){
    return root==NULL||symmetricHelp(root->left,root->right);
}
void maxWidth(node* root){
    if(root==NULL)return ;
    queue<pair<node*,int>> q;
    q.push({root,0});
    int width=0;
    while(!q.empty()){
        int size=q.size();
        int last,first;
        for(int i=0;i<size;i++){
            if(i==0) first=q.front().second;
            if(i==size-1) last=q.front().second;
            int curridx=q.front().second-1;
            node* temp=q.front().first;
            q.pop();
            if(temp->left) q.push({temp->left,2*curridx+1});
            if(temp->right) q.push({temp->right,2*curridx+2});
        }
            width=max(width,last-first+1);
    }
    cout<<width;

}
map<node*,node*> parents(node* root){
    queue<node*> q;
    map<node*,node*> parent;
    q.push(root);
    while(!q.empty()){
        node* temp=q.front();
        q.pop();
        if(temp->left){
            q.push(temp->left);
            parent[temp->left]=temp;
        }
        if(temp->right){
            q.push(temp->right);
            parent[temp->right]=temp;
        }
    }
    return parent;
}
node* findNode(node* root,int value){
    if(root==NULL) return NULL;
    if(*root->data==value){
        return root;
    }
    if(findNode(root->left,value)){
        return findNode(root->left,value);
    }
    if(findNode(root->right,value)){
        return findNode(root->right,value);
    }   
    return NULL;
}
void nodesAtdistanceK(node* root,int start,int distance){
    map<node*,node*> m=parents(root);
    set<node*> visited;
    node* startPt=findNode(root,start);
    int count=0;
    queue<node*> q;
    q.push(startPt);
    while(count!=distance){
        int size=q.size();
        for(int i=0;i<size;i++){
            node* temp=q.front();
            q.pop();
            visited.insert(temp);
            if(temp->left&&visited.find(temp->left)==visited.end()){
                q.push(temp->left);
            }
            if(temp->right&&visited.find(temp->right)==visited.end()){
                q.push(temp->right);
            }
            if(m.find(temp)!=m.end()&&visited.find(m[temp])==visited.end()){
                q.push(m[temp]);
            }   
        }
        count++;
    }
    while(!q.empty()){
        cout<<*q.front()->data<<" ";
        q.pop();
    }
}
void BurningTree(node* root,int start){
     map<node*,node*> m=parents(root);
    set<node*> visited;
    node* startPt=findNode(root,start);
    int count=0;
    queue<node*> q;
    q.push(startPt);
    while(!q.empty()){
        int size=q.size();
        for(int i=0;i<size;i++){
            node* temp=q.front();
            q.pop();
            visited.insert(temp);
            if(temp->left&&visited.find(temp->left)==visited.end()){
                q.push(temp->left);
            }
            if(temp->right&&visited.find(temp->right)==visited.end()){
                q.push(temp->right);
            }
            if(m.find(temp)!=m.end()&&visited.find(m[temp])==visited.end()){
                q.push(m[temp]);
            }   
        }
        count++;
        cout<<count<<" ";
    }
    cout<<count-1;
}
int LeftHeight(node* root){
    int count=0;
    while(root!=NULL){
        root=root->left;
        count++;
    }
    return count;
}
int RightHeight(node* root){
    int count=0;
    while(root!=NULL){
        root=root->right;
        count++;
    }
    return count;
}
int completeTreeNodes(node* root){
    if(!root)return 0;
    int lh=LeftHeight(root);
    int rh=RightHeight(root);
    if(lh==rh){
        return pow(2,lh)-1;
    } 
    return completeTreeNodes(root->left)+completeTreeNodes(root->right)+1;
}
string serialize(node* root){
    string s;
    queue<node* > q;
    q.push(root);
        s+=to_string(*root->data)+',';
    while(!q.empty()){
        node* temp=q.front();
        q.pop();
        if(temp->left){ q.push(temp->left); s+=to_string(*temp->left->data)+',';}
        else{s+="N,";}
        if(temp->right){ q.push(temp->right); s+=to_string(*temp->right->data)+',';}
        else{s+="N,";}
    }
    return s;
}
void deserialize(string s){
    int idx;
    queue<string> q;
    for(idx=0;idx<s.size()-1;){
        string x="";
        if(s[idx]==',')idx++;
        while(idx<s.size()&&s[idx]!=',')
           { x+=s[idx]; idx++;}
       q.push(x);
    }
   
    queue<node*> q2;
    node* root=new node(stoi(q.front()));
    q2.push(root);
    q.pop();
    while(!q.empty()){
     
        node* temp=q2.front();
        q2.pop();
        string left=q.front();
        q.pop();
        if(left!="N"){
            node* lchild=new node(stoi(left));
            q2.push(lchild);
            temp->left=lchild;
        }
        else{
            temp->left=NULL;
        }
         string right=q.front();
        q.pop();
        if(right!="N"){
            node* rchild=new node(stoi(right));
            q2.push(rchild);
            temp->right=rchild;
        }
        else{
            temp->right=NULL;
        }
      
    }

    preorder(root);
    cout<<endl;
    Inorder(root);
}
void MorrisTraversalInorder(node* root){
    if(root==NULL)return;
    node* curr=root;
    while(curr!=NULL){
        if(curr->left==NULL){
            cout<<*curr->data<<" ";
            curr=curr->right;
        }
        else{
            node* prev=curr->left;
            while(prev->right&&prev->right!=curr){
                prev=prev->right;
            }
            if(!prev->right){
                prev->right=curr;
                curr=curr->left;
            }
            else{
                prev->right=NULL;
                cout<<*curr->data<<" ";
                curr=curr->right;
            }
        }
    }
}
void MorrisTraversalPreorder(node* root){
    if(root==NULL)return;
    node* curr=root;
    while(curr!=NULL){
        if(curr->left==NULL){
            cout<<*curr->data<<" ";
            curr=curr->right;
        }
        else{
            node* prev=curr->left;
            while(prev->right&&prev->right!=curr){
                prev=prev->right;
            }
            if(!prev->right){
                prev->right=curr;
                cout<<*curr->data<<" ";
                curr=curr->left;
            }
            else{
                prev->right=NULL;
                curr=curr->right;
            }
        }
    }
}
node* flatTheTree(node* root){
    if(root==NULL)return root;
    node* left=flatTheTree(root->left);
    node* right=flatTheTree(root->right);
    if(!left&&!right){
        return root;
    }
    else{
        if(left&&!right){
            root->left=NULL;
            root->right=left;
        }
        else if(left&&right){
            root->left=NULL;
            root->right=left;
            while(left->right!=NULL){
                    left=left->right;
             }
            left->right=right;
        }
    }
    return root; 
} 
node* flatThereesuingMorrisTraversal(node* root){
    if(root==NULL) return NULL;
    node* cur=root;
    while(cur->right!=NULL){
        if(cur->left){
            node* prev=cur->left;
            while(prev->right!=NULL) prev=prev->right;
            prev->right=cur->right;
            cur->right=cur->left;
            cur->left=NULL;
        }
        cur=cur->right; 
    }
    return root;
}
void printLL(node *root){
    while(root!=NULL){
        cout<<*root->data<<" ";
        root=root->right;
    }
}
bool isBST(node* root,int lb=INT_MIN,int ub=INT_MAX){
    if(root==NULL) return true;
    if(isBST(root->left,lb,*root->data)&&isBST(root->right,*root->data,ub)){
        return *root->data>lb&&*root->data<ub;
    }
    return  false;
}
int main(){
    node* n=new node(30);
    node* n1=new node(15);
    node* n2=new node(50);
    node* n3=new node(7);
    node* n4=new node(18);
    node* n5=new node(45);
    node* n6=new node(55);
    node* n7=new node(5);
    node* n8=new node(3);

    n->left=n1;
    n->right=n2;
    n1->left=n3;
    n1->right=n4;
    n2->left=n5;
    n2->right=n6;
    n6->left=n7;
    n6->right=n8;
    node* nn=new node(30);
    node* nn1=new node(15);
    node* nn2=new node(15);
    node* nn3=new node(7);
    node* nn4=new node(18);
    node* nn5=new node(18);
    node* nn6=new node(7);
    // node* nn7=new node(5);
    // node* nn8=new node(3);

    nn->left=nn1;
    nn->right=nn2;
    nn1->left=nn3;
    nn1->right=nn4;
    nn2->left=nn5;
    nn2->right=nn6;
    // nn6->left=nn7;
    // nn6->right=nn8;
    // preorder(n);
    // cout<<endl;
    // postorder(n);
    // cout<<endl;
    // Inorder(n);
    // cout<<checkBalance(n);
    // int height=0;
    //  cout<<checkBalancewithHeight(n,&height);
    //  rightview(n);
    // leftView(n);
    // cout<<LAC(n,3,7);
    // cout<<minimumDistance(n,3,7);
    // preorder(n);
    // cout<<endl;
    // preOrderIteratively(n);
    //  Inorder(n);
    // cout<<endl;
    // inOrderiteratively(n);
    // postorder(n);
    // cout<<endl;
    // allOrderUsingoneStack(n);
    // postOrderIteratively(n);
    // postOrderTraversalIterativelyUsingoneStack(n);
    // int maxi=INT_MIN;
    // maximumPathSum(n,maxi);
    // cout<<maxi;
    // cout<<isIdenticle(n,nn);
    // zigzagTraversal(n);
    // boundaryTraversal(n);
    // verticleTraversal(n);
    // bottomView(n);
    // topView(n);
    // cout<<isSymmetric(nn);
    // maxWidth(n);
    // BurningTree(n,15);
//    nodesAtdistanceK(n,50,1);
// cout<<completeTreeNodes(n);
// deserialize(serialize(n));
// MorrisTraversalInorder(n);
// MorrisTraversalPreorder(n);
// printLL(flatTheTree(n));
// printLL(flatThereesuingMorrisTraversal(n));
cout<<isBST(n);

   
    
}