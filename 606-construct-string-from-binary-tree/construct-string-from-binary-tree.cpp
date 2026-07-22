class Solution {
public:
    void convert(TreeNode* root, string& ans) {
        if (!root) return;

        // Append root value as a formatted string
        ans += to_string(root->val);

        // Process left child (required if left exists OR if right exists to maintain structure)
        if (root->left || root->right) {
            ans.push_back('(');
            convert(root->left, ans);
            ans.push_back(')');
        }

        // Process right child (only needed if right exists)
        if (root->right) {
            ans.push_back('(');
            convert(root->right, ans);
            ans.push_back(')');
        }
    }

    string tree2str(TreeNode* root) {
        string ans = "";
        convert(root, ans);
        return ans;
    }
};