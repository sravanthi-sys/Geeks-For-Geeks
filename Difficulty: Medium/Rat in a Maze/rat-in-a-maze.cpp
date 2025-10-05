class Solution {
    void solve(int i, int j, int n, string curr, vector<vector<int>>& maze,
    vector<vector<int>>& vis){
        if(i >= n || j >= n)return ;
        if(i == n - 1 && j == n - 1){
            ans.push_back(curr);
            return ;
        }
        if(i + 1 < n && maze[i + 1][j] && !vis[i + 1][j]){
            vis[i + 1][j] = 1;
            solve(i + 1, j, n, curr + "D", maze, vis);
            vis[i + 1][j] = 0;
        }
        if(i - 1 >= 0 && maze[i - 1][j] && !vis[i - 1][j]){
            vis[i- 1][j] = 1;
            solve(i - 1, j, n, curr + "U", maze, vis);
            vis[i - 1][j] = 0;
        }
        if(j + 1 < n && maze[i][j + 1] && !vis[i][j + 1]){
            vis[i][j + 1] = 1;
            solve(i, j + 1, n, curr + "R", maze, vis);
            vis[i][j + 1] = 0;
        }
        if(j - 1 >= 0 && maze[i][j - 1] && !vis[i][j - 1]){
            vis[i][j - 1] = 1;
            solve(i, j - 1, n, curr + "L", maze, vis);
            vis[i][j - 1] = 0;
        }
    }
  public:
    vector<string> ans;
    vector<string> ratInMaze(vector<vector<int>>& maze) {
        int n = maze.size();
        if (maze[0][0] == 0) return {};  
        vector<vector<int>> vis(n, vector<int>(n, 0));
        vis[0][0] = 1;
        solve(0, 0, n, "", maze, vis);
        sort(ans.begin(), ans.end());
        return ans;
    }
};