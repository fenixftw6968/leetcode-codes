class Solution {
public:
    string maximumOddBinaryNumber(string s) {
        int cnt=0;
        for(char c : s){
            if(c=='1') cnt++;
        }
        int cnt0=s.size()-cnt;
        return string(cnt-1,'1')+string(cnt0,'0')+'1';
    }
};