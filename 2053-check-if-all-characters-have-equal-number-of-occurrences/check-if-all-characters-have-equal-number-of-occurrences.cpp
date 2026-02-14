class Solution {
public:
    bool areOccurrencesEqual(string s) {
        unordered_map<char,int> freq;
        for(char c : s){
            freq[c]++;
        }
        int a=freq.begin()->second;
        for(auto & p : freq){
            if(p.second!=a) return false;
        }
        return true;
    }
};