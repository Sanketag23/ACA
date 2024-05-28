#include<iostream>
#include<cmath>
#include<stack>
#include<vector>
#include<algorithm>
using namespace std;
// defination of the tree

int main (){
    int t;
    cin>>t;
    while(t--){
        
         int n;
         cin>>n;
         int hash[n+5];
         for(int i=0;i<n+5;i++){
             hash[i]=0;
         }
         for(int i=0;i<2*n-2;i++){
                int x;
                cin>>x;
                hash[x]++;
         }
         int cnt=0;
for(int i=1;i<n+5;i++){
if(hash[i]==1){
    cnt++;
}
}
cout<<(cnt+1)/2<<endl;
    }
}