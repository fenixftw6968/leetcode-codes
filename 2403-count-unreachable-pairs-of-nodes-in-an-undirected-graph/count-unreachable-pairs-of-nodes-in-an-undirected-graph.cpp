class Solution {
public:
    using ll = long long;
    void dfs(vector<vector<ll>>& adj,vector<ll>& vis,ll node,ll& count){
        vis[node]=1;
        count++;
        for(auto & iter : adj[node]){
            if(vis[iter]==0){
                dfs(adj,vis,iter,count);
            }
        }
    }
    long long countPairs(int n, vector<vector<int>>& edges) {
        vector<vector<ll>>adj(n);
        for(auto it : edges){
            int u=it[0];
            int v=it[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        // int cnt=0;
        vector<ll> cnt;
        vector<ll> vis(n,0);
        ll count=0;
        for(int i=0;i<n;i++){
            if(vis[i]==0){
                dfs(adj,vis,i,count);
                cnt.push_back(count);
            }
            count=0;
        }
        ll ans = 1LL * n * (n - 1) / 2;

for(auto x : cnt) {
    ans -= 1LL * x * (x - 1) / 2;
}

return ans;
    }
};