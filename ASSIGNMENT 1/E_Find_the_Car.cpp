#include<iostream>
#include<fstream>
#include<string>
#include<string>
#include<sstream>
#include<vector>
#include<map>
#include<set>
#include<queue>
#include<stack>
#include<algorithm>
#define MAX 1000000
using namespace std;
#define ll long long
#define ld long double
int main (){
    ll t;
    cin>>t;
    while(t--){
      ll n,k,q;
        cin>>n>>k>>q;
      ld a[k+1],b[k+1];
      a[0]=0;
      b[0]=0;
      for(ll i=1;i<=k;i++){
        cin>>a[i];
      }
        for(ll i=1;i<=k;i++){
            cin>>b[i];
        }
        vector<pair<ll,ll> > vp;
        for(ll i=0;i<q;i++){
            ll x;
            cin>>x;
            vp.push_back(make_pair(x,i+1));   
        }
        sort(vp.begin(),vp.end());  
        vector<ll> vs1;
        vector<ll> vs2;
        vector<ll> vd;
        for(ll i=0;i<k;i++){
            vs1.push_back((a[i+1]-a[i]));
            vs2.push_back((b[i+1]-b[i]));

        }
        ll i1=0;
        ll sumt=0;
        ll flag=0;
        vector<pair<ll,ll> > anst;
        for(ll i=0;i<q;i++){ // correct
            ll w=vp[i].first; // correct
            while(i1<k&&a[i1]<=w){ 
               i1++;
               flag=1;
            }
      sumt=b[i1-1]+(w-a[i1-1])*vs2[i1-1]/vs1[i1-1];
            anst.push_back(make_pair(vp[i].second,sumt));   
        }
sort(anst.begin(),anst.end());
for(ll i=0;i<q;i++){
    cout<<anst[i].second<<" ";
}
    cout<<endl;

    }
}
