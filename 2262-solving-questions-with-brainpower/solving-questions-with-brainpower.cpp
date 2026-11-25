
class Solution {
public:
    long long mostPoints(vector<vector<int>>& questions) {
        int n = questions.size();

        vector<long long> dp(n + 1, 0);

        for (int i = n - 1; i >= 0; i--) {

            int points = questions[i][0];
            int brainpower = questions[i][1];

            int next = i + brainpower + 1;

            long long solve = points + dp[min(n, next)];

            long long skip = dp[i + 1];

            dp[i] = max(solve, skip);
        }

        return dp[0];
    }
};
