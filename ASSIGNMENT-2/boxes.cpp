#include<iostream>
#include<cmath>
#include<stack>
#include<vector>
using namespace std;
int main (){
    int n;
    cin>>n;
    int a[n];
    stack<int> stck;
    vector<int> ans;
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    for(int i=0;i<n;i++){
        if(a[i]!=0){
            stck.push(a[i]);
        }
        else{
            ans.push_back(stck.top());
            stck.pop();
        }
    }
    for(int i=0;i<ans.size();i++){
        cout<<ans[i]<<" ";
    }
}