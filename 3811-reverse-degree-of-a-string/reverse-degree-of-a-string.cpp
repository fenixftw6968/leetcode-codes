class Solution {
public:
    int reverseDegree(string s) {
        int sum=0;
        for(int i=0;i<s.size();i++){
            char ch = s[i];
            sum+=(26-(ch-'a'))*(i+1);
        }
        return sum;
    }
};