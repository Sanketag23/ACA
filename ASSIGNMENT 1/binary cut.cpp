#include<iostream>
using namespace std;
#include<set>
#include<algorithm>
#include<vector>
#include<numeric>
#include<deque>
#include<cmath>
#define ll long long
#define arrin(a,n) for(int i=0;i<n;i++) cin>>a[i];
int main(){
   int t;
   cin>>t;
   while(t--){
      string s;
      cin>>s;
      int n=s.length();
      char a[n];
      set<char> st;

      for(int i=0;i<n;i++){
         a[i]=s[i];
         st.insert(a[i]);
      }
      if(st.size()==1){
         cout<<1<<endl;
         continue;
      }
      int count=1;
      int flag=0;
     for(int i=0;i<n;i++){
      if(a[i]=='1'&&i<n){
         while(a[i]=='1'&&i<n){
            i++;
         }
        
        if(i!=n){
         count++;
        }
       
      }
      if(flag==0){

       if(a[i]=='0'&&i<n){
        while(a[i]=='0'&&i<n){
          i++;
        }
      
        while(a[i]!='0'&&i<n){
          i++;
        }
       
        flag=1;
        if(i!=n){

         count++;
        }
        
       }
      }
      
       if(flag==1){
         if(a[i]=='0'&&i<n){
            while(a[i]=='0'&&i<n){
               i++;
            }
            
          i--;
          if(i!=n-1){
            count++;
          }
          
           
         }
      }

     }
       cout<<count<<endl;
}
}
