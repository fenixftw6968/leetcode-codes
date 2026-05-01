class Solution {
public:
    vector<vector<int>> findDifference(vector<int>& nums1, vector<int>& nums2) {
        unordered_set<int> s1(nums1.begin(),nums1.end());
        unordered_set<int> s2(nums2.begin(),nums2.end());
        vector<int> diff1;
        vector<int> diff2;
        for(int i : s1){
            if(s2.find(i)==s2.end()) diff1.push_back(i);
        }
        for(int i : s2){
            if(s1.find(i)==s1.end()) diff2.push_back(i);
        }
        return {diff1,diff2};
    }
};