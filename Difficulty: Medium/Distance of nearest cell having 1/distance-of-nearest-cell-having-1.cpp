class Solution {
  public:
    vector<vector<int>> nearest(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size();
        vector<vector<int>> ans(n, vector<int>(m, INT_MAX));
        vector<int> dr = {-1, 0, 1, 0}, dc = {0, 1, 0, -1};
        queue<vector<int>> q;
        for(int i = 0 ; i < n ; i ++){
            for(int j = 0 ; j < m ; j ++){
                if(grid[i][j] == 1){
                    q.push({0, i, j});
                }
                
            }
        }
        while(!q.empty()){
            int dist = q.front()[0], r = q.front()[1], c = q.front()[2];
            q.pop();
            ans[r][c] = dist;
            for(int ind = 0 ; ind < 4 ; ind ++){
                int nr = r + dr[ind], nc = c + dc[ind];
                if(nr >= 0 && nr < n && nc >= 0 && nc < m && 
                grid[nr][nc] != 1 && ans[nr][nc] > 1 + dist){
                    ans[nr][nc] = 1 + dist;
                    q.push({1 + dist, nr, nc});
                }
            }
            
        }
        return ans;
    }
};