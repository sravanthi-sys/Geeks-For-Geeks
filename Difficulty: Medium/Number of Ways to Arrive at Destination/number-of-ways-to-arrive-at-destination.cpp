class Solution {
  public:
    int countPaths(int V, vector<vector<int>>& edges) {
        vector<int> cnt(V, 0), dist(V, 1e9);
        vector<vector<pair<int, int>>> adj(V, vector<pair<int, int>>());
        for(int i = 0 ; i < edges.size() ; i ++){
            int u = edges[i][0], v = edges[i][1], d = edges[i][2];
            adj[u].push_back({v, d});
            adj[v].push_back({u, d});
        }
        dist[0] = 0;
        cnt[0] = 1;
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;
        pq.push({0, 0});
        while(!pq.empty()){
            int node = pq.top().second, d = pq.top().first;
            pq.pop();
            for(auto it : adj[node]){
                if(it.second + d < dist[it.first]){
                    dist[it.first] = it.second + d;
                    cnt[it.first] = cnt[node];
                    pq.push({it.second + d, it.first});
                }
                else if(it.second + d == dist[it.first]){
                    cnt[it.first] += cnt[node];
                }
            }
        }
        return cnt[V - 1];
    }
};