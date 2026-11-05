class Solution {
public:
    unordered_map<string, vector<pair<string, double>>> adj;

    double dfs(string src, string dest,
               unordered_set<string>& vis) {

        if (src == dest) return 1.0;

        vis.insert(src);

        for (auto &it : adj[src]) {
            string node = it.first;
            double wt = it.second;

            if (vis.count(node)) continue;

            double ans = dfs(node, dest, vis);

            if (ans != -1.0) {
                return wt * ans;
            }
        }

        return -1.0;
    }

    vector<double> calcEquation(
        vector<vector<string>>& equations,
        vector<double>& values,
        vector<vector<string>>& queries
    ) {
        // Build graph
        for (int i = 0; i < equations.size(); i++) {
            string u = equations[i][0];
            string v = equations[i][1];

            adj[u].push_back({v, values[i]});
            adj[v].push_back({u, 1.0 / values[i]});
        }

        vector<double> result;

        for (auto &q : queries) {
            string src = q[0];
            string dest = q[1];

            if (!adj.count(src) || !adj.count(dest)) {
                result.push_back(-1.0);
                continue;
            }

            unordered_set<string> vis;

            result.push_back(dfs(src, dest, vis));
        }

        return result;
    }
};