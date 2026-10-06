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
    int sum=0;
    vector<int> res;
    void dfs(TreeNode* root,int targetSum,vector<vector<int>> & ans){
        if(!root) return;
        sum+=root->val;
        res.push_back(root->val);
        if(!root->left && !root->right && sum==targetSum){
            ans.push_back(res);
        }
        if(root->left){
            dfs(root->left,targetSum,ans);
        }
        if(root->right){
            dfs(root->right,targetSum,ans);
        }
        sum-=root->val;
        res.pop_back();
        
    }
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<vector<int>> ans;
        if(!root) return ans;
        dfs(root,targetSum,ans);
        return ans;
    }
};