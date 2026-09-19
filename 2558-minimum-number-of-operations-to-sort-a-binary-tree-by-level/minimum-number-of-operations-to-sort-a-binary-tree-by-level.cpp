class Solution {
public:
    int minimumOperations(TreeNode* root) {

        if (!root) return 0;

        queue<TreeNode*> q;
        q.push(root);

        int cnt = 0;

        while (!q.empty()) {

            int n = q.size();

            vector<int> vec;

            // Process one level
            for (int i = 0; i < n; i++) {

                TreeNode* top = q.front();
                q.pop();

                vec.push_back(top->val);

                if (top->left)
                    q.push(top->left);

                if (top->right)
                    q.push(top->right);
            }

            // Original level
            vector<int> original = vec;

            // Sorted level
            sort(vec.begin(), vec.end());

            // value -> correct index
            unordered_map<int, int> mpp;

            for (int i = 0; i < n; i++) {
                mpp[vec[i]] = i;
            }

            // Minimum swaps
            for (int i = 0; i < n; i++) {

                while (original[i] != vec[i]) {

                    int correctIndex = mpp[original[i]];

                    swap(original[i], original[correctIndex]);

                    cnt++;
                }
            }
        }

        return cnt;
    }
};