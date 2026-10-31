class Solution {
public:
    int mini=INT_MAX;
    void dfs(vector<vector<pair<int,int>>>&adj,int node,int n,vector<int> &vis){
        vis[node]=1;
        // if(node==n) return;
        for(auto iter : adj[node]){
            mini=min(mini,iter.second);
            if(!vis[iter.first]) dfs(adj,iter.first,n,vis);
        }
    }
    int minScore(int n, vector<vector<int>>& roads) {
        vector<vector<pair<int,int>>> adj(n+1);
        vector<int> vis(n+1,0);
        for(auto it : roads){
            int u=it[0];
            int v=it[1];
            int w=it[2];
            adj[u].push_back({v,w});
            adj[v].push_back({u,w});
        }
        dfs(adj,1,n,vis);
        return mini;
    }
};