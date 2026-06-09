class Solution {
public:
    int passwordStrength(string password) {
        set<char> st(password.begin(),password.end());
        vector<char> s(st.begin(),st.end());
        int ans=0;
        for(int i=0;i<s.size();i++){
            if(s[i]>=65 && s[i]<=90) ans+=2;
            else if(s[i]>=97 && s[i]<=122) ans+=1;
            else if(s[i]=='!' || s[i]=='@' || s[i]=='#' || s[i]=='$') ans+=5;
            else ans+=3;
        }
        return ans;
    }
};