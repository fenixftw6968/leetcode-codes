class Solution {
public:
    int maxAscendingSum(vector<int>& nums) {
        if(nums.size()==1) return nums[0];
        int sum=nums[0];
        int k=INT_MIN;
        for(int i=1;i<nums.size();i++){
            if(nums[i]>nums[i-1]) sum+=nums[i];
            else{
                k=max(k,sum);
                sum=nums[i];
            }
            k=max(k,sum);
        }
        return k;
    }
};