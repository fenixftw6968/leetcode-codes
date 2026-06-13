class Solution {
public:
    string mapWordWeights(vector<string>& words, vector<int>& weights) {
        string ans;

        for (string &w : words) {
            int sum = 0;

            for (char c : w) {
                sum = (sum + weights[c - 'a']) % 26;
            }

            ans.push_back('a' + (25 - sum));
        }

        return ans;
    }
};