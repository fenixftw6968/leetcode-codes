class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {
        vector<vector<int>> adj(n+1);
        vector<int> trustedby(n+1,0);
        for(auto &it : trust){
            int u=it[0];
            int v=it[1];
            adj[u].push_back(v);
            trustedby[v]++;
        }
        
        for(int i=1;i<=n;i++){
            if(adj[i].size()==0 && trustedby[i]==n-1) return i;
        }
        return -1;
    }
};