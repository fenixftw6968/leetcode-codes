class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int len=INT_MAX;
        int sum=0;
        int left=0;
        bool flag=false;
        for(int right=0;right<nums.size();right++){
            sum+=nums[right];
            while(sum>=target){
                flag=true;
                len=min(len,right-left+1);
                sum-=nums[left];
                left++;
            }
        }
        if(!flag) return 0;
        return len;
        
    }
};