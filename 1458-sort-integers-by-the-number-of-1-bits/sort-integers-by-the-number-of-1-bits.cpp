class Solution {
public:
    vector<int> sortByBits(vector<int>& arr) {
        sort(arr.begin(),arr.end(),[](int a,int b){
            int bitsa=__builtin_popcount(a);
            int bitsb=__builtin_popcount(b);
            if(bitsa==bitsb) return a<b;
            return bitsa<bitsb;
        });
        return arr;
    }
};