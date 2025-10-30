class Solution {
  public:
    void fill(vector<vector<char>>& grid) {
        int n = grid.size(), m = grid[0].size();
        vector<vector<int>> vis(n, vector<int>(m, 0));
        queue<pair<int, int>> q;
        for(int i = 0 ; i < n ; i ++){
            for(int j = 0 ; j < m ; j ++){
                if((i == 0 || j == 0 || i == n - 1 || j == m - 1) && !vis[i][j]
                && grid[i][j] == 'O' ){
                    q.push({i, j});
                    vis[i][j] = 1;
                }
            }
        }
        vector<int> dr = {-1, 0, 1 , 0}, dc = {0, 1, 0, -1};
        while(!q.empty()){
            int i = q.front().first;
            int j = q.front().second;
            q.pop();
            for(int ind = 0 ; ind < 4 ; ind ++){
                int nr = i + dr[ind], nc = j + dc[ind];
                if(nr >= 0 && nr < n && nc >= 0 && nc < m && !vis[nr][nc] &&
                grid[nr][nc] == 'O'){
                    q.push({nr, nc});
                    vis[nr][nc] = 1;
                }
            }
        }
        for(int i = 0 ; i < n ; i ++){
            for(int j = 0 ; j < m ; j ++){
                if(vis[i][j] == 0 && grid[i][j] == 'O'){
                    grid[i][j] = 'X';
                }
            }
        }
    }
};