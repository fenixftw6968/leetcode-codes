class Solution {
public:
    bool sumGame(string num) {
        int n=num.size();
        int t1=0;
        int t2=0;
        int cnt1=0;
        int cnt2=0;
        for(int i=0;i<n/2;i++){
            if(num[i]=='?') cnt1++;
            else t1+=num[i]-'0';

        }
        for(int i=n/2;i<n;i++){
            if(num[i]=='?') cnt2++;
            else t2+=num[i]-'0';
        }
        int diff=t1-t2;
        int count=cnt1-cnt2;
        if((cnt1+cnt2)%2!=0) return true;
        return 2 * (t1 - t2) != 9 * (cnt2 - cnt1);
    }
};