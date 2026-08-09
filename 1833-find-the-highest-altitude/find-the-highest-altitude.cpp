class Solution {
public:
    int largestAltitude(vector<int>& gain) {
        int altitude=0;
        int maxheight=0;
        for(int x : gain){
            altitude+=x;
            maxheight=max(maxheight,altitude);
        }
        return maxheight;
    }
};