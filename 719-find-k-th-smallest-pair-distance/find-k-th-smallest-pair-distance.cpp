class Solution {
public:
    int smallestDistancePair(vector<int>& nums, int k) {
        int n=nums.size();
        sort(nums.begin(),nums.end());
        int maxDiff=nums[n-1]-nums[0];
        int l=0;
        int r=maxDiff;
        while(l<r){
            int mid=(l+r)/2;
            int left=0;
            int cnt=0;
            for(int right=0;right<n;right++){
                while(nums[right]-nums[left]>mid) left++;
                cnt+=right-left;
            }
            if(cnt>=k) r=mid;
            else l=mid+1;
        }
        return l;
    }
};