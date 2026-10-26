class Solution {
public:
    int cnt;

    int dfs(int node, vector<vector<int>>& adj, string& s) {
        char label = s[node];
        int longest = 0, secondLongest = 0;

        for (auto& neigh : adj[node]) {
            int len = dfs(neigh, adj, s);

            if (s[neigh] == label)
                continue;

            if (len > longest) {
                secondLongest = longest;
                longest = len;
            } else if (len > secondLongest) {
                secondLongest = len;
            }
        }

        cnt = max(cnt, 1 + longest + secondLongest);

        return 1 + longest;
    }

    int longestPath(vector<int>& parent, string s) {
        int n = parent.size();
        cnt = 1;

        vector<vector<int>> adj(n);

        for (int i = 1; i < n; i++) {
            adj[parent[i]].push_back(i);
        }

        dfs(0, adj, s);

        return cnt;
    }
};