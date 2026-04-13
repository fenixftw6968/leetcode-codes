class Solution {
public:
    int islandPerimeter(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        bool flag=true;
        queue<pair<int,int>> q;
        vector<vector<int>> vis(n,vector<int> (m,0));
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==1 && flag){
                    q.push({i,j});
                    vis[i][j]=1;
                    flag=false;
                }
            }
        }
      
        int dcols[]={1,0,-1,0};
        int drows[]={0,-1,0,1};
        int perimeter=0;
        
        while(!q.empty()){
            auto top=q.front();

            q.pop();
            int r=top.first;
            int c=top.second;
            int adjacent=0;
            for(int i=0;i<4;i++){
                int nrow=r+drows[i];
                int ncol=c+dcols[i];
                if(nrow>=0 && nrow<n && ncol>=0 && ncol<m && grid[nrow][ncol]==1 ){
                    adjacent++;
                    if(vis[nrow][ncol]==0){
                        q.push({nrow,ncol});
                        vis[nrow][ncol]=1;
                    }
                }
            }
            perimeter+=4-adjacent;
        }
        return perimeter;
    }
};