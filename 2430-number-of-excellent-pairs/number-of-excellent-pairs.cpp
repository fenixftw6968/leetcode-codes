class Solution {
public:
    long long countExcellentPairs(vector<int>& nums, int k) {
        long long cnt=0;
        set<int> st(nums.begin(),nums.end());
        vector<int> v(st.begin(),st.end());
        int n=v.size();
        for(int i=0;i<n;i++) v[i]=__builtin_popcount(v[i]);
        sort(v.begin(),v.end());
        int l=0;
        int r=v.size()-1;
        while(l<n && r>=0){
            if(v[l]+v[r]>=k){
                cnt+=(n-l);
                r--;
            }
            else if(v[l]+v[r]<k) l++;
        }

        return cnt;
    }
};