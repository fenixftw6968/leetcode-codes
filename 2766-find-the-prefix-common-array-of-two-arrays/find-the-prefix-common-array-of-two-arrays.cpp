class Solution {
public:
    vector<int> findThePrefixCommonArray(vector<int>& A, vector<int>& B) {
        vector<int> c(A.size());
        for(int i=0;i<A.size();i++){
            int cnt=0;
            unordered_map<int,int> freq;
            for(int j=0;j<=i;j++){
                freq[A[j]]++;
                freq[B[j]]++;
            }
            for(auto & p : freq){
                if(p.second>=2) cnt++;
            }
            c[i]=cnt;
        }
        return c;
    }
};