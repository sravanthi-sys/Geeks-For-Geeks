class Solution {
  public:
    vector<int> findOrder(int n, vector<vector<int>> &prerequisites) {
        vector<vector<int>> adj(n, vector<int>());
        vector<int> indegree(n);
        for(int i = 0 ; i < prerequisites.size() ; i ++){
            adj[prerequisites[i][1]].push_back(prerequisites[i][0]);
            indegree[prerequisites[i][0]] ++;
        }
        vector<int> ans;
        queue<int> q;
        for(int i = 0 ; i < n ; i ++){
            if(indegree[i] == 0)q.push(i);
        }
        while(!q.empty()){
            int node = q.front();
            ans.push_back(node);
            q.pop();
            for(auto it : adj[node]){
                indegree[it] --;
                if(indegree[it] == 0){
                    q.push(it);
                }
            }
        }
        if(ans.size() != n)return {};
        return ans;
    }
};