class Solution {
    vector<int> parent;
    vector<int> rank;
    int findPar(int node){
        if(parent[node] == node)return node;
        return parent[node] = findPar(parent[node]);
    }
    bool unionEdges(int u, int v){
        int pu = findPar(u), pv = findPar(v);
        if(pu == pv)return true;
        if(rank[pu] > rank[pv]){
            parent[pv] = pu;
        }
        else if(rank[pv] > rank[pu]){
            parent[pu] = pv;
        }
        else{
            parent[pu] = pv;
            rank[pv] += 1;
        }
        return false;
    }
  public:
    int minConnect(int V, vector<vector<int>>& edges) {
        vector<vector<int>> adj(V, vector<int>());
        parent.resize(V);
        rank.resize(V, 0);
        for(int i = 0 ; i < V ; i ++){
            parent[i] = i;
        }
        int extra = 0;
        for(int i = 0 ; i < edges.size() ; i ++){
            int u = edges[i][0], v = edges[i][1];
            if(unionEdges(u, v))extra ++;
        }
        int components = 0;
        for(int i = 0 ; i < V ; i ++){
            if(findPar(i) == i)components ++;
        }
        int req = components - 1;
        if(extra >= req)return req;
        return -1;
    }
};
