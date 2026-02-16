class Solution {
public:
    int getLeastFrequentDigit(int n) {
        string s=to_string(n);
        vector<int> freq(10,0);
        for(char c : s){
            freq[c-'0']++;
        }
        int mini=INT_MAX;
        int res=9;
        for(int i=0;i<10;i++){
            if(freq[i]>0){
                if(freq[i]<mini){
                mini=freq[i];
                res=i;
            }
            }
            
        }
        return res;;
    }
};