const int N=1e5+5;
vector<int> g[N];
vector<int> height(N);
class Solution {
public:
    void dfs(int src,int depth,vector<int> & visited,int &longestcycle){
        if(visited[src]==1){
            longestcycle=max(longestcycle,depth-height[src]);
            return;
        }
        if(visited[src]==2) return;
        visited[src]=1;
        height[src]=depth;
        for(auto i : g[src]){
            dfs(i,depth+1,visited,longestcycle);
        }
        visited[src]=2;
    }
    int longestCycle(vector<int>& edges) {
        int n=edges.size();
        for(int j=0;j<n;j++){
            if(edges[j]!=-1){
                g[j].push_back(edges[j]);
            }
        }
        int result=-1;
        vector<int>visited(n,0);
        for(int j=0;j<n;j++){
            dfs(j,1,visited,result);
        }
        for(int j=0;j<n;j++){
            height[j]=0;
            g[j].clear();
        }
        return result;
    }
};