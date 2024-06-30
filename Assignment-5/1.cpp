//                    didnt got on my own saw solution
void dstra(int start, vector<int> &dist, vector<vector<pair<int, int>>> &adj){
    set<vector<int>> s;
    vector<int> visited(dist.size(), 0);
    visited[start]=0;
    s.insert({0, start});
    dist[start]=0;
    while(!s.empty()){
        vector<int> top = *s.begin();
        s.erase(s.begin());
        int u = top[1];
        int d = top[0];
        visited[u]=1;
        for(auto it: adj[u] ){
            if(!visited[it.first]){
                if(d+it.second<dist[it.first]){
                    dist[it.first] = d+it.second;
                    s.insert({dist[it.first], it.first}); 
                }
            }
        }
    }
    return;
}
int Solution::solve(int A, vector<vector<int> > &B, int C, int D, vector<vector<int> > &E) {


vector<int> distC(A+1, INT_MAX);
vector<int> distD(A+1, INT_MAX);


vector<vector<pair<int, int>>> adj(A+1);
for(int i=0; i<B.size(); i++){
    adj[B[i][0]].push_back({B[i][1], B[i][2]});
    adj[B[i][1]].push_back({B[i][0], B[i][2]});
}
dstra(C, distC, adj);
dstra(D, distD, adj);
int minDis = INT_MAX;
for(int i=1; i<=A; i++){
    if(distC[i]!=INT_MAX && distD[i]!=INT_MAX)
        minDis = min(minDis, distC[i]+distD[i]);
}


for(int i=0; i<E.size(); i++){

   if(distC[E[i][0]]!=INT_MAX && distD[E[i][1]]!=INT_MAX)
       minDis = min(minDis, distC[E[i][0]]+distD[E[i][1]]+E[i][2]);
   if(distC[E[i][1]]!=INT_MAX && distD[E[i][0]]!=INT_MAX)
       minDis = min(minDis, distC[E[i][1]]+distD[E[i][0]]+E[i][2]);

}


if(minDis==INT_MAX) return -1;

return minDis;
}