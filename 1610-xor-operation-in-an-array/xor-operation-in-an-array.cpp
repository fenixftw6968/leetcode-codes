class Solution {
public:
    int xorOperation(int n, int start) {
        vector<int> nums(n);
        for(int i=0;i<nums.size();i++){
            nums[i]=start+2*i;
        }
        int total=0;
        for(int i=0;i<n;i++){
            total^=nums[i];
        }
        return total;
    }
};