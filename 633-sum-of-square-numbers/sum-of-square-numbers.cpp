class Solution {
public:
    bool judgeSquareSum(int c) {
        long long low=0;
        long long high=sqrt(c);
        while(low<=high){
            long long mid=low*low+high*high;
            if(mid==c) return true;
            else if(mid>c) high--;
            else low++;
        }
        return false;
    }
};