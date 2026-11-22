class Solution {
public:
    bool checkString(string s) {
        int k;
        for(int i=0;i<s.size();i++){
            if(s[i]=='b') {
                k=i;break;
            }

        }
        for(int j=k;j<s.size();j++){
            if(s[j]=='a') return false;
        }
        return true;
    }
};