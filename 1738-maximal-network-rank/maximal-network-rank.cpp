class Solution {
public:
    int maximalNetworkRank(int n, vector<vector<int>>& roads) {
        vector<vector<int>> adj(n);
        vector<int> indegree(n);
        vector<vector<bool>> vis(n, vector<bool>(n, false));
        for(auto it : roads){
            int u=it[0];
            int v=it[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
            vis[u][v]=true;
            vis[v][u]=true;
            indegree[u]++;
            indegree[v]++;
        }
        int ans=0;
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                int cnt=0;
                if(vis[i][j]==true){
                    cnt+=indegree[i]+indegree[j]-1;
                }
                else{
                    cnt+=indegree[i]+indegree[j];
                }
                ans=max(ans,cnt);
            }
            
        }
        return ans;
    }
};