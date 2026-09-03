class Solution {
public:
    int f(vector<int> & prices,int n,int idn,int buy,int cap,vector<vector<vector<int>>> &dp){
        if(idn==n || cap==0) return 0;
        if(dp[idn][buy][cap]!=-1) return dp[idn][buy][cap];
        if(buy==1){
            return dp[idn][buy][cap]=max(-prices[idn]+f(prices,n,idn+1,0,cap,dp),0+f(prices,n,idn+1,1,cap,dp));
        }
        return dp[idn][buy][cap]=max(prices[idn]+f(prices,n,idn+1,1,cap-1,dp),0+f(prices,n,idn+1,0,cap,dp));
    }
    int maxProfit(vector<int>& prices) {
        int n=prices.size();
        vector<vector<vector<int>>> dp(n, vector<vector<int>>(2, vector<int>(3, -1)));
        return f(prices,n,0,1,2,dp);
    }
};