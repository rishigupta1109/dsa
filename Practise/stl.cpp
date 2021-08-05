#include<bits/stdc++.h>
using namespace std;
void showList(list <int> &x)
       {for (auto i : x)
       {
           cout<<i;
       }
       }
void showMap(map <int,string> &x)
       {for (auto i : x)
       {
           cout<<i.first<<" "<<i.second<<endl;
       }
       }
int main(){  


    //   //VECTOR

    // vector<int> v;
    // v.push_back(2);
    // v.push_back(8);
    // v.push_back(5);
    // v.push_back(1);
    // // for(it=v.begin();it!=v.end();it++){
    // //     cout<<*it;
    // // }

    // // for(auto pr:v){
    // //     cout<<pr;
    // // }
    // // cout<<endl;

    // v.pop_back();

    // // for(auto pr:v){
    // //     cout<<pr;
    // // }
    // // cout<<endl;

    // // vector<int>::iterator it;

    // it=v.begin()+1;
    // // cout<<*it;
    // // cout<<endl;

    // v.insert(it,9,5);

    // // cout<<endl;

    // vector<int> vf (6,13);

    // // for(auto pr:vf){
    // //     cout<<pr<<" ";
    // // }


    //LISTS
    // list<int> l1(4);
    // list<int> l2;
    // l1.push_back(5);
    // l2.push_back(5);
    // l1.push_front(8);
    // l2.push_front(8);
    // l1.sort();
    // l1.merge(l2);
    // l1.reverse();
    // showList(l1);


    //MAPS

    map<int,string> m;
    m.insert(make_pair(2,"ramesh"));
    m[0]="rishi";
    m.insert({1,"piyush"});
    showMap(m);
     map<int,string>::iterator it=m.find(0);
    
   
    
}