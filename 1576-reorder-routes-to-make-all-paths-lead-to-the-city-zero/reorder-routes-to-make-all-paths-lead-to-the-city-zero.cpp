class Solution {
public:
    int cnt=0;
    void dfs(vector<vector<pair<int,int>>>&adj,int node,vector<int>&vis){
        vis[node]=1;
        for(auto iter : adj[node]){
            if(vis[iter.first]==0){
                if(iter.second==1) cnt++;
                dfs(adj,iter.first,vis);
            }
        }
    }
    int minReorder(int n, vector<vector<int>>& connections) {
        vector<vector<pair<int,int>>> adj(n);
        for(auto &it : connections){
            int u=it[0];
            int v=it[1];
            adj[u].push_back({v,1});
            adj[v].push_back({u,0});
        }
        vector<int>vis(n,0);
        vis[0]=1;
        dfs(adj,0,vis);
        return cnt;
    }
};