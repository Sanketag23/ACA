class Solution {
public:
    bool validPath(int A, vector<vector<int>>& B, int se, int dn) {
        int n = B.size();
        
  int  visited[A];
  for(int i=0;i<A;i++){
      visited[i]=0;
  }
  if(B.empty()){
    return true;
  }
  if(se==dn){
    return true;
  }
   vector<int> adj[A];
for (int i = 0; i < n; i++) {
    int u = B[i][0];
    int v = B[i][1];
    adj[u].push_back(v); 
     adj[v].push_back(u); 

}

    
    visited[se]=1;
    queue <int> q;
    q.push(se);
    while(!q.empty()){
    int node = q.front();
    q.pop();
    for(auto it : adj[node]){
        if(!visited[it]){
           
           if(it==dn){
               return 1;
           }
           else{
               
                visited[it]=1;
                q.push(it);
           }
          
        }
    }
    }
    
    return 0;
    }
};