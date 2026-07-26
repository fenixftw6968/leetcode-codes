class Solution {
public:
    int edgeScore(vector<int>& edges) {
        vector<vector<int>> adj(edges.size());
        for(int i=0;i<edges.size();i++){
            int u=i;
            int v=edges[i];
            adj[u].push_back(v);
        }
        vector<long long> score(edges.size(),0);
        for(int i=0;i<edges.size();i++){
            score[adj[i][0]]+=i;
        }
        int maxi=0;
        for(int i=1;i<edges.size();i++){
            if(score[i]>score[maxi]){
                maxi=i;
            }
        }
        return maxi;

    }
};