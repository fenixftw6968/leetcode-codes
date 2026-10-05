class Solution {
public:
    double frogPosition(int n, vector<vector<int>>& edges, int t, int target) {
        vector<vector<int>>adj(n+1);
        for(auto it : edges){
            int u=it[0];
            int v=it[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        // node, parent, time, probability
        queue<tuple<int,int,int,double>>q;
        q.push({1,-1,0,1.0});
        while(!q.empty()){
            auto [node,parent,time,probability]=q.front();
            q.pop();
            int children=0;
            for(int neighbor : adj[node]){
                if(neighbor!=parent){
                    children++;
                }
            }
            if(node==target){
                if(time==t){
                    return probability;
                }
                if(children==0){
                    return probability;
                }
                continue;
            }
            if(time==t) continue;
            for(int neigh : adj[node]){
                if(neigh==parent) continue;
                q.push({neigh,node,time+1,probability/children});
            }
        }
        return 0.0;
    }
};