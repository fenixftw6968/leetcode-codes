class Solution {
public:
    int climbStairs(int n, vector<int>& costs) {
        int m=costs.size();
        vector<long long> dp(m+1,1e15);
        vector<int> k=costs;
        dp[0]=0;
        for(int i=0;i<m;i++){
            for(int jump=1;jump<=3;jump++){\
                int j=i+jump;
                if(j<=m){
                    long long stepcost=k[j-1]+1LL*jump*jump;
                    dp[j]=min(dp[j],dp[i]+stepcost);
                }
            }
        }
        return (int)dp[m];
    }
};