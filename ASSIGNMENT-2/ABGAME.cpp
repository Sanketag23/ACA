#include<iostream>
#include<cmath>
#include<stack>
#include<vector>
#include<algorithm>
using namespace std;
int main (){
    int n;
    cin>>n;
    vector<int> a;
     vector<int> b;
    for(int i=0;i<n;i++){
        int x;
        cin>>x;
      a.push_back(x);
    }  
    // copy
    for(int i=0;i<n;i++){
      b.push_back(a[i]);
    }
    reverse(a.begin(),a.end());

    while(a.size()!=0&&b.size()!=0){
      if(a[a.size()-1]<b[b.size()-1]){
        cout<<2<<" ";
        a.pop_back();
      }
      else if( b[b.size()-1]<a[a.size()-1]){
        cout<<1<<" ";
        b.pop_back();
      }
        else{
            cout<<0<<" ";
            a.pop_back();
            b.pop_back();
        }

      
    }



}