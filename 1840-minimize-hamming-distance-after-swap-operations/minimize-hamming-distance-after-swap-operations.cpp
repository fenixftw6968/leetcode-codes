class Solution {
public:
    vector<int> parent, sz;

    int find(int x) {
        if (parent[x] == x)
            return x;
        return parent[x] = find(parent[x]);
    }

    void unite(int x, int y) {
        x = find(x);
        y = find(y);

        if (x == y) return;

        if (sz[x] < sz[y])
            swap(x, y);

        parent[y] = x;
        sz[x] += sz[y];
    }

    int minimumHammingDistance(vector<int>& source,
                               vector<int>& target,
                               vector<vector<int>>& allowedSwaps) {
        int n = source.size();
        parent.resize(n);
        sz.assign(n, 1);
        for (int i = 0; i < n; i++)
            parent[i] = i;

        for (auto& s : allowedSwaps)
            unite(s[0], s[1]);

    
        unordered_map<int, unordered_map<int, int>> freq;

        for (int i = 0; i < n; i++)
            freq[find(i)][source[i]]++;

        // Step 3: Match target values
        int ans = 0;

        for (int i = 0; i < n; i++) {
            int root = find(i);
            int val = target[i];

            if (freq[root][val] > 0) {
                freq[root][val]--;
            } else {
                ans++;
            }
        }

        return ans;
    }
};