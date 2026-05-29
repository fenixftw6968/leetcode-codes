class Solution {
public:
    int sum(int n){
        int s=0;
        while(n>0){
            int temp=n%10;
            s+=temp;
            n=n/10;
        }
        return s;
    }
    int minElement(vector<int>& nums) {
        vector<int> ans;
        for(int i=0;i<nums.size();i++){
            int x=sum(nums[i]);
            ans.push_back(x);
        }
        sort(ans.begin(),ans.end());
        return ans[0];
    }
};