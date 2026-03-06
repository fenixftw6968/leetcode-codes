class Solution {
public:
    bool checkOnesSegment(string s) {
        int i=0;
        bool flag=true;
        while(i<s.size() && s[i]!='0'){
            i++;
        }
        for(int k=i;k<s.size();k++){
            if(s[k]=='1'){
                flag=false;
                break;
            }
        }
        if(!flag) return false;
        return true;
    }
};