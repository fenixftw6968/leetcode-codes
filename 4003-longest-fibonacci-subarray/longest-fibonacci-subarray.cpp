class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        if(nums.size()==1) return 1;
        int max_len=2;
        int maxi=INT_MIN;
        for(int i=2;i<nums.size();i++){
            if(nums[i]==nums[i-1]+nums[i-2]){
                max_len+=1;
                maxi=max(maxi,max_len);

            }
            else{
                max_len=2;
                maxi=max(maxi,2);
            }
            
        }
        return maxi;
    }
};