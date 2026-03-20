class Solution {
public:
    int sumOfSquares(vector<int>& nums) {
        long long sum=0;
        long long n=nums.size();
        for(long long i=1;i<=nums.size();i++){
            if(n%i==0) {
                long long j=nums[i-1]*nums[i-1];
                sum+=j;
            }
        }
        return sum;
    }
};