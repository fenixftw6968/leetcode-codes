class Solution {
public:
    vector<int> getMaximumXor(vector<int>& nums, int maximumBit) {

        vector<int> ans;

        int mask = (1 << maximumBit) - 1;
        int curr = 0;

        for (int x : nums) {
            curr ^= x;
        }

        for (int i = nums.size() - 1; i >= 0; i--) {

            int k = curr ^ mask;

            ans.push_back(k);

            curr ^= nums[i];
        }

        return ans;
    }
};