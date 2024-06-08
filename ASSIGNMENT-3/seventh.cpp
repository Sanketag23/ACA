#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cmath>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <deque>
using namespace std;
//                              didnt got on my own so saw the solution.
int main(){
    int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, 1, 0, -1};
// upar niche afge piche.
string step = "URDL";
    
    int n, m;
    cin >> n >> m;
   pair<int,int > start,end;
   int visited[n][m];
   char grid[n][m];
    for(int i=0;i<n;i++){
         for(int j=0;j<m;j++){
            visited[i][j] = 0;
              cin >> grid[i][j];
              if(grid[i][j]=='A'){
                start.first = i;
                start.second = j;
              }
              if(grid[i][j]=='B'){
                end.first = i;
                end.second = j;
              }
         }
    }
    visited[start.first][start.second] = 1;
    int prevstep[n][m];
    queue<pair<int,int> > q;
    q.push(start);
    while(!q.empty()){
        pair<int,int> p = q.front();
        q.pop();
for(int i=0;i<4;i++){
    pair<int,int> newp = make_pair(p.first+dx[i],p.second+dy[i]);
   if(newp.first<0 || newp.first>=n || newp.second<0 || newp.second>=m){
       continue;
   }
    if (grid[newp.first][newp.second] == '#')
                continue;
   if (visited[newp.first][newp.second])
                continue;
     visited[newp.first][newp.second] = true;
            prevstep[newp.first][newp.second] = i;
            q.push(newp);
}
    }
    if (visited[end.first][end.second]){
        cout << "YES" << endl;
        vector<int> steps;
        while (end != start){
            int p = prevstep[end.first][end.second];
            steps.push_back(p);
            end = make_pair(end.first - dx[p], end.second - dy[p]);
        }
        reverse(steps.begin(), steps.end());
        cout << steps.size() << endl;
        for (char c : steps){
            cout << step[c];
        }
    }
    else{
        cout << "NO" << endl;
    }

    return 0;
    

}