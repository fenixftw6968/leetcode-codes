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
    // bool uni(TreeNode* root,int vals){
    //     // if(!root) return false;
    //     if(root->val!=vals) return false;
    //     if(root->left) uni(root->left,vals);
    //     if(root->right) uni(root->right,vals);
    //     return true;
    // }
    bool isUnivalTree(TreeNode* root) {
        if(!root) return true;
        // return uni(root,root->val);
        queue<TreeNode*> q;
        q.push(root);
        int target=root->val;
        while(!q.empty()){
            TreeNode* node=q.front();
            q.pop();
            if(node->val!=target) return false;
            if(node->left) q.push(node->left);
            if(node->right) q.push(node->right);

        }
        return true;
    }
};