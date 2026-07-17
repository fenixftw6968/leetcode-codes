class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& heights) {
        int n=heights.size();
        int m=heights[0].size();
        vector<vector<int>> dist(n,vector<int>(m,1e9));
        dist[0][0]=0;
          priority_queue<pair<int, pair<int, int>>,
                       vector<pair<int, pair<int, int>>>,
                       greater<pair<int, pair<int, int>>>>
            q;
        q.push({0,{0,0}});
        int dx[4]={-1,0,1,0};
        int dy[4]={0,1,0,-1};
        while(!q.empty()){
            auto it =q.top();
            q.pop();
            int d=it.first;
            int r=it.second.first;
            int c=it.second.second;
            if(r==n-1 && c==m-1) return d;
            if (d > dist[r][c]) continue;
            for(int i=0;i<4;i++){
                int nr=r+dx[i];
                int nc=c+dy[i];
                if(nr>=0 && nr<n && nc>=0 && nc<m){
                    int nd=max(abs(heights[r][c]-heights[nr][nc]),d);
                    if(nd<dist[nr][nc]){
                        dist[nr][nc]=nd;
                        q.push({nd,{nr,nc}});
                    }
                }
            }
        }
        return 0;
    }
};