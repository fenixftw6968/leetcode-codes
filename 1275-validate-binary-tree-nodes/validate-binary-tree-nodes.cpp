class Solution {
public:
    bool validateBinaryTreeNodes(int n, vector<int>& leftChild, vector<int>& rightChild) {
        // if(leftChild[0]!=-1 || rightChild[0]!=-1) return false;
        vector<int> parent(n,-3);
        for(int i=0;i<n;i++){
        
            if(leftChild[i]!=-1){
                if(parent[leftChild[i]]==-3){
                    parent[leftChild[i]]=i;
                }
                else return false;
            }
        }
        for(int i=0;i<n;i++){
            if(rightChild[i]!=-1){
                if(parent[rightChild[i]]==-3){
                    parent[rightChild[i]]=i;
                }
                else return false;
            }
        }
        //for root detection how many roots
        int root=-1;
        int cnt=0;
        for(int i=0;i<n;i++){
            if(parent[i]==-3){
                root=i;
                cnt++;
            }
        }
        if(cnt!=1) return false;

        //for finding disconneted components
        queue<int> q;
        vector<bool> vis(n,false);
        q.push(root);
        vis[root]=true;
        int count=0;

        while(!q.empty()){
            auto node=q.front();
            q.pop();
            count++;
            int left=leftChild[node];
            int right=rightChild[node];
            
            if(left!=-1){
                if(vis[left]==true) return false;
                vis[left]=true;
                q.push(left);

            }
            if(right!=-1){
                if(vis[right]==true) return false;
                vis[right]=true;
                q.push(right);
            }

        }
        return count==n;
    }
};