class Solution {
public:
    int m, n;
    vector<vector<vector<int>>> dp;

    bool dfs(int i, int j, int bal, vector<vector<char>>& grid) {
        bal += (grid[i][j] == '(' ? 1 : -1);

        if (bal < 0) return false;

        if (i == m - 1 && j == n - 1)
            return bal == 0;

        if (dp[i][j][bal] != -1)
            return dp[i][j][bal];

        bool ans = false;

        if (i + 1 < m)
            ans = dfs(i + 1, j, bal, grid);

        if (!ans && j + 1 < n)
            ans = dfs(i, j + 1, bal, grid);

        return dp[i][j][bal] = ans;
    }

    bool hasValidPath(vector<vector<char>>& grid) {
        m = grid.size();
        n = grid[0].size();

        if ((m + n) % 2 == 0)
            return false;

        dp.resize(m, vector<vector<int>>(n, vector<int>(m + n, -1)));

        return dfs(0, 0, 0, grid);
    }
};