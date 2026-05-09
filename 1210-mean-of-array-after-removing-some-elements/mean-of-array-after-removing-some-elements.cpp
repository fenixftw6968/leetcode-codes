class Solution {
public:
    double trimMean(vector<int>& arr) {
        sort(arr.begin(),arr.end());
        int n=arr.size();
        int k=n/20;
        double cnt=0;
        double sum=0;
        for(int i=k;i<n-k;i++){
            sum+=arr[i];cnt++;
        }
        return sum/cnt;
    }
};