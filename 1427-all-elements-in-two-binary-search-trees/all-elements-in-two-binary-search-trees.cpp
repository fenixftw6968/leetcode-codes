/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    vector<int> bfs(TreeNode* root){
        queue<TreeNode*> q;
        vector<int> res;
        if(!root) return res;
        q.push(root);
        while(!q.empty()){
            int sz=q.size();
            for(int i=0;i<sz;i++){
                TreeNode* node=q.front();
                q.pop();
                res.push_back(node->val);
                if(node->left) q.push(node->left);
                if(node->right) q.push(node->right);
            }
        }
        return res;
    }
    vector<int> getAllElements(TreeNode* root1, TreeNode* root2) {
        vector<int> ans=bfs(root1);
        vector<int> ans2=bfs(root2);
        vector<int> result;
        result.insert(result.end(), ans.begin(), ans.end());
        result.insert(result.end(), ans2.begin(), ans2.end());
        sort(result.begin(), result.end());
        return result;
    }
};