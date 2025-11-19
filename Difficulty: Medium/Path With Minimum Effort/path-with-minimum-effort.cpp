class Solution {
  public:
    int minCostPath(vector<vector<int>>& mat) {
        int n = mat.size(), m = mat[0].size();
        vector<vector<int>> dist(n, vector<int>(m, 1e9));
        vector<int> dr = {-1, 0, 1, 0}, dc = {0, 1, 0, -1};
        priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, 
        greater<>> pq;
        dist[0][0] = 0;
        pq.push({0, {0, 0}});
        while(!pq.empty()){
            int d = pq.top().first, i = pq.top().second.first, j = pq.top().second.second;
            pq.pop();
            if(i == n - 1 && j == m - 1)return d;
            for(int ind = 0 ; ind < 4 ; ind ++){
                int nr = i + dr[ind], nc = j + dc[ind];
                if(nr >= 0 && nr < n && nc >= 0 && nc < m && dist[nr][nc] > max(d, 
                abs(mat[i][j] - mat[nr][nc]))){
                    dist[nr][nc] = max(d, abs(mat[i][j] - mat[nr][nc]));
                    pq.push({max(d, abs(mat[i][j] - mat[nr][nc])), {nr, nc}});
                }
            }
        }
        return -1;
    }
};
