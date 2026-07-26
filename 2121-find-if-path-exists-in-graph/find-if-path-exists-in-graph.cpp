class Solution {
public:
    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
        vector<vector<int>> adj(n);
        for(auto &it : edges){
            int u=it[0];
            int v=it[1];
            adj[u].push_back(v); 
            adj[v].push_back(u);
        }
        queue<int> q;
        q.push(source);
        vector<bool> visited(n,false);
        visited[source]=true;
        while(!q.empty()){
            int it=q.front();
            q.pop();
            if(it==destination) return true;
            for(int i : adj[it]){
                if(!visited[i]){
                    visited[i]=true;
                    q.push(i);
                }
            }
        }
        return false;
    }
};