#include<iostream>
#include<cmath>
#include<stack>
#include<vector>
#include<algorithm>
using namespace std;
#define ll long long
// defination of the tree

int main (){
    ll t;
    cin>>t;
    while(t--){
        ll n;
        cin>>n;
        ll sum=0;

        while(n!=0){
          sum+=n;
            n=n/2;
        }
        cout<<sum<<endl;
    }
    }