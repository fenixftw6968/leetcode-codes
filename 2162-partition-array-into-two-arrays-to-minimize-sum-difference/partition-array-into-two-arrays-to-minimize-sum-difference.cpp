class Solution {
public:
    int minimumDifference(vector<int>& nums) {
        int N = nums.size();
        int n = N / 2;

        vector<vector<int>> left(n + 1);
        vector<vector<int>> right(n + 1);

        for (int mask = 0; mask < (1 << n); mask++) {
            int cnt = 0;
            int sum1 = 0, sum2 = 0;

            for (int i = 0; i < n; i++) {
                if (mask & (1 << i)) {
                    cnt++;
                    sum1 += nums[i];
                    sum2 += nums[i + n];
                }
            }

            left[cnt].push_back(sum1);
            right[cnt].push_back(sum2);
        }

        for (int i = 0; i <= n; i++)
            sort(right[i].begin(), right[i].end());

        int total = accumulate(nums.begin(), nums.end(), 0);
        int ans = INT_MAX;

        for (int cnt = 0; cnt <= n; cnt++) {
            int need = n - cnt;

            for (int x : left[cnt]) {
                int target = total / 2 - x;

                auto it = lower_bound(
                    right[need].begin(),
                    right[need].end(),
                    target
                );

                if (it != right[need].end()) {
                    int sum = x + *it;
                    ans = min(ans, abs(total - 2 * sum));
                }

                if (it != right[need].begin()) {
                    --it;
                    int sum = x + *it;
                    ans = min(ans, abs(total - 2 * sum));
                }
            }
        }

        return ans;
    }
};