class Solution {
public:
    long long maximumSumOfHeights(vector<int>& heights) {
        int n=heights.size();
        long long ans=0;
        for(int i=0;i<n;i++){
            long long sum=heights[i];
            int h=heights[i];
            for(int j=i-1;j>=0;j--){
                h=min(h,heights[j]);
                sum+=h;
            }
            h=heights[i];
            for(int k=i+1;k<n;k++){
                h=min(h,heights[k]);
                sum+=h;
            }
            ans=max(ans,sum);

        }
        return ans;
        

    }
};