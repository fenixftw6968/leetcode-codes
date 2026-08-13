class Solution {
public:
    int change(int amount, vector<int>& coins) {

        vector<unsigned long long> dp(amount + 1, 0); 
        dp[0] = 1;

        for (int c : coins) {
            for (int amt = c; amt <= amount; amt++) {
                dp[amt] += dp[amt - c];
            }
        }
        return dp[amount];
    }
};