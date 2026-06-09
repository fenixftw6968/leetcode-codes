class Solution {
public:
    vector<int> limitOccurrences(vector<int>& nums, int k) {
        unordered_map<int,int> freq;
        for(int x : nums) {
            freq[x]++;
            if(freq[x]>k) freq[x]--;
        }
        vector<int> res;
        for(auto & p : freq){
            for(int j=0;j<p.second;j++){
                res.push_back(p.first);
            }
        }
        sort(res.begin(),res.end());
        return res;
        
    }
};