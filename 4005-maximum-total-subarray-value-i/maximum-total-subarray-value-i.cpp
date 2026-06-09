class Solution {
public:
    long long maxTotalValue(vector<int>& nums, int k) {
        int global_max=*max_element(nums.begin(),nums.end());
        int global_min=*min_element(nums.begin(),nums.end());
        long long best=(long long) global_max-global_min;
        return best*k;
    }
};