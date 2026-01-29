class Solution {
public:
    bool checkStraightLine(vector<vector<int>>& c) {
        int x0=c[0][0],y0=c[0][1];
        int x1=c[1][0],y1=c[1][1];
        int dx=x1-x0;
        int dy=y1-y0;
        for(int i=2;i<c.size();i++){
            int dx2=c[i][0]-x0;
            int dy2=c[i][1]-y0;
            if(dy*dx2!=dy2*dx) return false;
        }
        return true;
    }
};