#include<iostream>
#include<cstdlib>
#include<ctime>
#include<string>
using namespace std;
#define ll long long
int main(){
ll t;
cin>>t;
while(t--){
ll n,k;
cin>>n>>k;
ll l=(n+k-1)/k;
cout<<(k*l+n-1)/n<<endl;
}
}