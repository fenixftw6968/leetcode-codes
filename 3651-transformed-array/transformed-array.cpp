class Solution {
public:
    vector<int> constructTransformedArray(vector<int>& nums) {
        vector<int> res(nums.size());
        int n=nums.size();
        for(int i=0;i<n;i++){
            int j=(i+nums[i])%n;
            if(j<0){
                j=j+n;
            }
            res[i]=nums[j];
        }
        return res;
    }
};