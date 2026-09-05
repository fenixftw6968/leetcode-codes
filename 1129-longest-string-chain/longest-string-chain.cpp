class Solution {
public:
    bool checkpossible(string cur,string prev){
        if(cur.size()-prev.size()!=1) return false;
        int i=0,j=0;
        int cnt=0;
        while(i<prev.size() && j<cur.size()){
            if(prev[i]==cur[j]){
                i++;j++;
            }
            else{
                j++;
                cnt++;
            }
        }
        if(cnt==1) return true;
        if(j<cur.size()) cnt++;
        return cnt==1;
    }
    int f(int ind,int prevind,vector<string> & words,int n,vector<vector<int>> &dp){
        if(ind==n) return 0;
        if(dp[ind][prevind+1]!=-1) return dp[ind][prevind+1];
        //not take
        int len=0+f(ind+1,prevind,words,n,dp);
        //take

        if(prevind==-1 || (words[ind].size()-words[prevind].size()==1 && checkpossible(words[ind],words[prevind])==1)) len=max(len,1+f(ind+1,ind,words,n,dp));
        return dp[ind][prevind+1]=len;
    }
    int longestStrChain(vector<string>& words) {
        int n=words.size();
         sort(words.begin(), words.end(),
             [](string& a, string& b) {
                 return a.size() < b.size();
             });
        vector<vector<int>> dp(n,vector<int> (n+1,-1));
        return f(0,-1,words,n,dp);
    }
};