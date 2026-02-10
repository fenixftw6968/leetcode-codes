class Solution {
public:
    int maxAbsoluteSum(vector<int>& nums) {
        int currsum=0;
        int presum=0;
        int maxi=INT_MIN;
        int mini=INT_MAX;
        for(int i=0;i<nums.size();i++){
            currsum+=nums[i];
            maxi=max(maxi,currsum);
            if(currsum<0) currsum=0;
        }
        for(int i=0;i<nums.size();i++){
            presum+=nums[i];
            mini=min(mini,presum);
            if(presum>0) presum=0;
        }
        return max(maxi,abs(mini));
    }
};