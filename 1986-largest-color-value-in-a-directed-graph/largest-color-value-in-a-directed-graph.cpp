class Solution {
public:
    int largestPathValue(string colors, vector<vector<int>>& edges) {
        int n = colors.size();

        vector<vector<pair<int,int>>> adj(n);
        vector<int> indegree(n, 0);

        for(auto &iter : edges) {
            int u = iter[0];
            int v = iter[1];

            adj[u].push_back({v, colors[v]});
            indegree[v]++;
        }

        vector<vector<int>> dp(n, vector<int>(26, 0));

        queue<int> q;

        for(int i = 0; i < n; i++) {
            if(indegree[i] == 0) {
                q.push(i);
                dp[i][colors[i] - 'a'] = 1;
            }
        }

        int ans = 0;
        int cnt = 0;

        while(!q.empty()) {
            int node = q.front();
            q.pop();

            cnt++;

            ans = max(ans, dp[node][colors[node] - 'a']);

            for(auto &it : adj[node]) {
                int v = it.first;
                char ch = it.second;

                for(int c = 0; c < 26; c++) {
                    dp[v][c] = max(dp[v][c],
                                   dp[node][c] + (ch - 'a' == c));
                }

                indegree[v]--;

                if(indegree[v] == 0) {
                    q.push(v);
                }
            }
        }

        if(cnt != n) return -1;

        return ans;
    }
};