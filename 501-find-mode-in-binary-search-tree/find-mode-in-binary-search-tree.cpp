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
    map<int,int> freq;
    void inorder(TreeNode* root){
        if(root==NULL) return ;
        inorder(root->left);
        freq[root->val]++;
        inorder(root->right);
    }
    vector<int> findMode(TreeNode* root) {
        if(root==NULL) return {};
        inorder(root);
        int maxi=0;
        for(auto it : freq){
            maxi=max(maxi, it.second);
        }
        vector<int> res;
        for(auto it : freq){
            if(it.second==maxi) res.push_back(it.first);
        }
        return res;
    }
};