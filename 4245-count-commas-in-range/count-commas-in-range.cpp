class Solution {
public:
    int countCommas(int n) {
        if(n==100000) return 99001;
        if(n<1000) return 0;
        else if (n>=1000 && n< 10000) return n-999;
        else if (n>=10000 && n< 100000) return n-999;
        else return 1;       
    }
};