class Solution
{
	public:
	int nodeLevel(int V, vector<int> adj[], int X) {
    int count = 0;
    int vis[V] = {0};
    queue<int> q;
    q.push(0);
    vis[0] = 1;
    
    while (!q.empty()) {
        int levelSize = q.size();
        
        while (levelSize--) { 
            int node = q.front();
            q.pop();
            if (node == X) {
                return count;
            }
            for (auto it : adj[node]) {
                if (!vis[it]) {
                    vis[it] = 1;
                    q.push(it);
                }
            }
        }
        count++;
    }
    return -1;
}

};