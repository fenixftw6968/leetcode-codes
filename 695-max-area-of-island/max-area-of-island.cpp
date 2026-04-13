class Solution {
private:
    int islandPerimeter(vector<vector<int>> &grid,vector<vector<int>> &vis,int row,int col) {
        int n=grid.size();
        int m=grid[0].size();
        bool flag=true;
        queue<pair<int,int>> q;
        q.push({row,col});
        vis[row][col]=1;
        int dcols[]={1,0,-1,0};
        int drows[]={0,-1,0,1};
        int area=1;
        while(!q.empty()){
            auto top=q.front();
            q.pop();
            int r=top.first;
            int c=top.second;
            for(int i=0;i<4;i++){
                int nrow=r+drows[i];
                int ncol=c+dcols[i];
                if(nrow>=0 && nrow<n && ncol>=0 && ncol<m && grid[nrow][ncol]==1 && vis[nrow][ncol]==0){
                    area++;
                    q.push({nrow,ncol});
                    vis[nrow][ncol]=1;
                }
            }
        }
        return area;
    }
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        int maxi=0;
        vector<vector<int>> vis(n,vector<int> (m,0));
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==1 && vis[i][j]==0){
                    maxi=max(maxi,islandPerimeter(grid,vis,i,j));
                }
            }
        }
        return maxi;
    }
};