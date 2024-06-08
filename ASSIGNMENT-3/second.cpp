/**
 * @input A : Integer
 * @input B : 2D integer array 
 * @input n21 : Integer array's ( B ) rows
 * @input n22 : Integer array's ( B ) columns
 * 
 * @Output Integer
 */
 int Solution::solve(int A,  vector<vector<int> > &B) {
    	  int n = B.size();
  int  visited[A+1];
  for(int i=0;i<A+1;i++){
      visited[i]=0;
  }
   vector<int> adj[A+1];
for (int i = 0; i < n; ++i) {
    int u = B[i][0];
    int v = B[i][1];
    adj[u].push_back(v); 
}

    visited[1]=1;
    visited[0]=1;
    queue <int> q;
    q.push(1);
    while(!q.empty()){
    int node = q.front();
    q.pop();
    for(auto it : adj[node]){
        if(!visited[it]){
           
           if(it==A){
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
