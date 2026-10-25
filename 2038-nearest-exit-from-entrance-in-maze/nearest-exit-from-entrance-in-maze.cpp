class Solution {
public:
    int nearestExit(vector<vector<char>>& maze, vector<int>& entrance) {
        int n=maze.size();
        int m=maze[0].size();
        queue<pair<int,int>> q;
        q.push({entrance[0],entrance[1]});
        vector<vector<bool>> visited(n,vector<bool>(m,false));
        visited[entrance[0]][entrance[1]]=true;
        int dx[4]={-1,0,1,0};
        int dy[4]={0,1,0,-1};
        int steps=0;
        while(!q.empty()){
            int sz=q.size();
            while(sz--){
                auto [x,y]=q.front();
                q.pop();
                if (!(x == entrance[0] && y == entrance[1])) {
                    if (x == 0 || y == 0 || x == n-1 || y == m-1) return steps;
                }
                for(int k=0;k<4;k++){
                    int x_new=x+dx[k];
                    int y_new=y+dy[k];
                    if(x_new>=0 && y_new>=0 && x_new<n && y_new<m && maze[x_new][y_new]=='.' && !visited[x_new][y_new]){
                        q.push({x_new,y_new});
                        visited[x_new][y_new]=true;
                    }
                }
            }
            steps++;
        }
        return -1;
    }
};