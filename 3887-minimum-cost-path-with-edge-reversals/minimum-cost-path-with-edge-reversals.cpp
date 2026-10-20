class Solution {
public:
    int minCost(int n, vector<vector<int>>& edges) {
        vector<vector<pair<int, int>>> adj(n);

        for (auto &e : edges) {
            int u = e[0], v = e[1], w = e[2];

            adj[u].push_back({v, w});
            adj[v].push_back({u, 2 * w});
        }
        vector<int> dist(n, INT_MAX);
        priority_queue<
            pair<int, int>,
            vector<pair<int, int>>,
            greater<pair<int, int>>
        > pq;
        dist[0]=0;
        pq.push({0,0});
        while(!pq.empty()){
            auto [cost,u]=pq.top();
            pq.pop();
            if(cost>dist[u]) continue;
            if(u==n-1) return cost;
            for(auto [v,w]: adj[u]){
                if(cost+w<dist[v]){
                    dist[v]=cost+w;
                    pq.push({dist[v],v});
                }
            }
        }
        return -1;

    }
};