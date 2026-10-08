class Solution {
public:
    int N,M,K;
    int MOD=1e9+7;
    int dp[51][51][101];
    int solve(int idx,int searchcost,int maxi){
        if(idx==N){
            if(searchcost==K) return 1;
            return 0;
        }
        if(dp[idx][searchcost][maxi]!=-1){
            return dp[idx][searchcost][maxi];
        }
        int result=0;
        for(int i=1;i<=M;i++){
            if(i>maxi){
                result=(result+solve(idx+1,searchcost+1,i))%MOD;
            }
            else{
                result=(result+solve(idx+1,searchcost,maxi))%MOD;
            }
        }
        return dp[idx][searchcost][maxi]=result%MOD;

    }
    int numOfArrays(int n, int m, int k) {
        N=n;
        M=m;
        K=k;
        memset(dp,-1,sizeof(dp));
        return solve(0,0,0);
    }
};