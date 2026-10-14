class Solution {
public:
    bool hasValidPath(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        vector<vector<int>> dirs[7];

        dirs[1] = {{0, -1}, {0, 1}};  
        dirs[2] = {{-1, 0}, {1, 0}};  
        dirs[3] = {{0, -1}, {1, 0}};  
        dirs[4] = {{0, 1}, {1, 0}};   
        dirs[5] = {{0, -1}, {-1, 0}}; 
        dirs[6] = {{0, 1}, {-1, 0}};  

        // int dx[4]={-1,0,1,0};
        // int dy[4]={0,1,0,-1};

        vector<vector<bool>> vis(n,vector<bool>(m,false));
        queue<pair<int,int>> q;
        q.push({0,0});
        vis[0][0]=true;
        while(!q.empty()){
            auto[r,c]=q.front();
            q.pop();
            if(r==n-1 && c==m-1) return true;
            for(auto d : dirs[grid[r][c]]){
                int nr=r+d[0];
                int nc=c+d[1];
bool connected=false;
                if(nr>=0 && nr<n && nc>=0 && nc<m && !vis[nr][nc]){
                    
                    for(auto d1 : dirs[grid[nr][nc]]){
                        if(nr+d1[0]==r && nc+d1[1]==c){
                            connected=true;
                            break;
                        }
                    }
                }
                if(connected) {
                    vis[nr][nc]=true;
                    q.push({nr,nc});
                }
            }
        }
        return false;
    }
};