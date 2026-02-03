class Solution {
public:
    bool isTrionic(vector<int>& nums) {
        int cnt = 0;
        int p=0;
        int q=0;
        if(nums[nums.size()-1]==nums[nums.size()-2]) return false;
        for (int i = 1; i < nums.size() - 1; i++) {
            if (nums[i] > nums[i - 1] && nums[i] > nums[i + 1]) {
                cnt++;
                p=i;
            }
            if(nums[i]==nums[i-1]) return false;
        }
        for (int j = 1; j < nums.size() - 1; j++) {
            if (nums[j] < nums[j + 1] && nums[j] < nums[j - 1]) {
                cnt++;
                q=j;
            }
            if(nums[j]==nums[j-1]) return false;
        }

        if (cnt == 2 && p<q)
            return true;
        return false;
    }
};