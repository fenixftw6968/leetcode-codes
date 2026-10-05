class Solution {
public:
    int n, m;
    int dx[4] = {-1, 1, 0, 0};
    int dy[4] = {0, 0, -1, 1};

    int dfs(int i, int j, vector<vector<int>>& mat, vector<vector<int>>& dp) {
        if(dp[i][j] != 0) return dp[i][j];
        dp[i][j] = 1;
        for(int k = 0; k < 4; k++) {
            int ni = i + dx[k];
            int nj = j + dy[k];

            if(ni >= 0 && ni < n && nj >= 0 && nj < m &&
               mat[ni][nj] > mat[i][j]) {
                dp[i][j] = max(dp[i][j], 1 + dfs(ni, nj, mat, dp));
            }
        }

        return dp[i][j];
    }

    int longestIncreasingPath(vector<vector<int>>& matrix) {
        n = matrix.size();
        m = matrix[0].size();
        vector<vector<int>> dp(n, vector<int>(m, 0));
        int ans = 0;
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                ans = max(ans, dfs(i, j, matrix, dp));
            }
        }
        return ans;
    }
};