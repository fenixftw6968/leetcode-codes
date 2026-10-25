class Solution {
public:
    bool bipartite(vector<vector<int>>& adj,int node,vector<int> & color){
        queue<int> q;
        q.push(node);
        color[node]=1;
        while(!q.empty()){
            int top=q.front();
            q.pop();
            for(auto it : adj[top]){
                if(color[it]==-1){
                    color[it]=1-color[top];
                    q.push(it);
                }
                else if(color[it]==color[top]) return false;
            }
        }
        return true;
    }
    bool possibleBipartition(int n, vector<vector<int>>& dislikes) {
        vector<vector<int>> adj(n+1);
        for(auto & it : dislikes){
            int u=it[0];
            int v=it[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        vector<int> color(n+1,-1);
        for(int i=1;i<=n;i++){
            if(color[i]==-1){
                if(!bipartite(adj,i,color)) return false;
            }
        }
        return true;
    }
};