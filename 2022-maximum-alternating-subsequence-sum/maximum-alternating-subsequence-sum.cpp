class Solution {
public:
    typedef long long ll;
    ll dp[1000001][2];
    ll solve(ll idx, bool flag, vector<int>& nums) {
        if (idx >= nums.size())
            return 0;
        if (dp[idx][flag] != -1)
            return dp[idx][flag];
        ll skip = solve(idx + 1, flag, nums);
        ll val = nums[idx];
        if (flag == false) {
            val = -val;
        }
        ll take = solve(idx + 1, !flag, nums) + val;
        return dp[idx][flag] = max(take, skip);
    }
    long long maxAlternatingSum(vector<int>& nums) {
        ll n = nums.size();
        memset(dp, -1, sizeof(dp));
        return solve(0, true, nums);
    }
};