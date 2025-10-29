class Solution {
    int ans;
    int solve(vector<vector<int>>& adj, int node, vector<int>& vis){
        vis[node] = 1;
        int max1 = 0, max2 = 0; 
        for (auto it : adj[node]) {
            if (!vis[it]) {
                int h = 1 + solve(adj, it, vis);
                if (h > max1) {
                    max2 = max1;
                    max1 = h;
                } else if (h > max2) {
                    max2 = h;
                }
            }
        }
        ans = max(ans, max1 + max2);
        return max1;
    }
  public:
    int diameter(int V, vector<vector<int>>& edges) {
        vector<vector<int>> adj(V, vector<int>());
        vector<int> vis(V, 0);
        for(int i = 0 ; i < edges.size() ; i ++){
            adj[edges[i][0]].push_back(edges[i][1]);
            adj[edges[i][1]].push_back(edges[i][0]);
        }
        ans = 0;
        solve(adj, 0, vis);
        return ans;
        
    }
};
