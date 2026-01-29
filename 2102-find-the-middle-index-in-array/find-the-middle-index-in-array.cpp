class Solution {
public:
    int findMiddleIndex(vector<int>& nums) {
        int total=0;
        for(int x : nums){
            total+=x;
        }
        int prefix=0;
        for(int i=0;i<nums.size();i++){
            int leftsum=prefix;
            int rightsum=total-leftsum-nums[i];
            if(leftsum==rightsum) return i;
            prefix+=nums[i];
        }
        return -1;
    }
};