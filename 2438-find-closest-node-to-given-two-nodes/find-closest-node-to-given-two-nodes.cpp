class Solution {
public:
    int closestMeetingNode(vector<int>& edges, int node1, int node2) {
        int n=edges.size();
        queue<int> q;
        q.push(node1);
        vector<int> dist1(n,-1);
        dist1[node1]=0;

        int prev1=0;
        while(!q.empty()){
            auto node=q.front();
            q.pop();
            int iter = edges[node];
            if (iter != -1 && dist1[iter] == -1) {
                dist1[iter] = dist1[node] + 1;
                q.push(iter);
            }
        }
        queue<int> q1;
        q1.push(node2);
        vector<int> dist2(n,-1);
        dist2[node2]=0;
        int prev2=0;
        while(!q1.empty()){
            auto node=q1.front();
            q1.pop();
            // for(auto iter : edges[node]){
            //     dist2[iter]=1+prev2;
            //     prev2=dist2[iter];
            //     q.push(iter);
            // }
            int iter = edges[node];

            if (iter != -1 && dist2[iter] == -1) {
                dist2[iter] = dist2[node] + 1;
                q1.push(iter);
            }
        }
        int maxi=INT_MAX;
        int ans=-1;
        for(int i=0;i<n;i++){
            // if(dist1[i]+dist2[i]<maxi){
            //     maxi=dist1[i]+dist2[i];
            //     ans=i
            // }
            if (dist1[i] != -1 && dist2[i] != -1) {
                int curr = max(dist1[i], dist2[i]);
                if (curr < maxi) {
                    maxi = curr;
                    ans = i;
                }
            }
        }
        return ans;
    }
};