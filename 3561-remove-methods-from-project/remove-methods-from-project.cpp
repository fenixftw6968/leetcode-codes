class Solution {
public:
    vector<int> remainingMethods(int n, int k,
                                 vector<vector<int>>& invocations) {
        vector<vector<int>> adj(n);
        for (auto& it : invocations) {
            int u = it[0];
            int v = it[1];
            adj[u].push_back(v);
        }
        vector<int> vis(n, 0);
        vis[k] = 1;
        queue<int> q;
        q.push(k);
        while (!q.empty()) {
            int it = q.front();
            q.pop();
            for (int i = 0; i < adj[it].size(); i++) {
                int neighbor = adj[it][i];
                if (!vis[neighbor]) {
                    vis[neighbor] = 1;
                    q.push(neighbor);
                }
            }
        }
        // Check whether removal is possible
        for (auto& e : invocations) {
            int u = e[0];
            int v = e[1];

            if (!vis[u] && vis[v]) {
                vector<int> ans;
                for (int i = 0; i < n; i++)
                    ans.push_back(i);
                return ans;
            }
        }

        // Otherwise return all non-suspicious methods
        vector<int> ans;
        for (int i = 0; i < n; i++) {
            if (!vis[i])
                ans.push_back(i);
        }

        return ans;
    }
};