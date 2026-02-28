class Solution {
public:
    const int MOD=1e9+7;
    int concatenatedBinary(int n) {
        long long ans=0;
        for(int i=1;i<=n;i++){
            int temp=i;
            int bits=0;
            while(temp>0){
                bits++;
                temp/=2;
            }
            ans=((ans<<bits)%MOD+i)%MOD;
        }
        return ans;
    }
};