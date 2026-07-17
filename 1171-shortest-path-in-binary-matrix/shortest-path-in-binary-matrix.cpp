class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int n=grid.size();
        if(grid[0][0]==1 || grid[n-1][n-1]==1) return -1;
        if(n==1) return 1;
        vector<vector<int>> dist(n, vector<int>(n, 1e9));
        dist[0][0] = 1;
        queue<pair<pair<int,int>,int>> q;
        q.push({{0,0},1});
        int dx[8]={-1,-1,-1,0,0,1,1,1};
        int dy[8]={-1,0,1,-1,1,-1,0,1};
        while(!q.empty()){
            int d=q.front().second;
            int r=q.front().first.first;
            int c=q.front().first.second;
            q.pop();
            for(int i=0;i<8;i++){
                int row=r+dx[i];
                int col=c+dy[i];
                if(row>=0 && row<n && col>=0 && col<n && d+1<dist[row][col] && grid[row][col]==0){
                    dist[row][col]=1+d;
                    if(row==n-1 && col==n-1) return d+1;
                    q.push({{row,col},d+1});
                }
            }
        }
        return -1;
    }
};