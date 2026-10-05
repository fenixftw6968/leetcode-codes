class Solution {
public:
    vector<int> ans;
    vector<vector<int>> adj;
    vector<vector<pair<int,int>>> path;

    void dfs(int u, int parent, int depth, vector<int>& nums) {
        int bestNode = -1;
        int bestDepth = -1;

        for (int x = 1; x <= 50; x++) {
            if (!path[x].empty() && gcd(nums[u], x) == 1) {
                auto [node, dep] = path[x].back();

                if (dep > bestDepth) {
                    bestDepth = dep;
                    bestNode = node;
                }
            }
        }

        ans[u] = bestNode;

        path[nums[u]].push_back({u, depth});

        for (int v : adj[u]) {
            if (v != parent) {
                dfs(v, u, depth + 1, nums);
            }
        }

        path[nums[u]].pop_back();
    }

    vector<int> getCoprimes(vector<int>& nums, vector<vector<int>>& edges) {
        int n = nums.size();

        ans.assign(n, -1);
        adj.resize(n);
        path.resize(51);

        for (auto& e : edges) {
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
        }

        dfs(0, -1, 0, nums);

        return ans;
    }
}; 