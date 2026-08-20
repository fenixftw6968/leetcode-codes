class Solution {
public:
    vector<int> resultArray(vector<int>& nums) {
        vector<int> res;
        vector<int> a1;
        vector<int> b1;
        a1.push_back(nums[0]);
        b1.push_back(nums[1]);
        for(int i=2;i<nums.size();i++){
            if(a1[a1.size()-1]>b1[b1.size()-1]) a1.push_back(nums[i]);
            else b1.push_back(nums[i]);
        }
        // if(a1[a1.size()-1]>b1[b1.size()-1]) a1.push_back(nums[nums.size()-1]);
        // else b1.push_back(nums[nums.size()-1]);

        for(int i=0;i<a1.size();i++){
            res.push_back(a1[i]);
        }
        for(int i=0;i<b1.size();i++){
            res.push_back(b1[i]);
        }
        return res;
    }
};