class Solution {
public:
    vector<int> parent, rankv;

    int find(int x) {
        if (parent[x] == x)
            return x;

        return parent[x] = find(parent[x]);
    }

    void unite(int a, int b) {
        a = find(a);
        b = find(b);

        if (a == b)
            return;

        if (rankv[a] < rankv[b]) {
            parent[a] = b;
        }
        else if (rankv[a] > rankv[b]) {
            parent[b] = a;
        }
        else {
            parent[b] = a;
            rankv[a]++;
        }
    }

    vector<vector<string>> accountsMerge(
        vector<vector<string>>& accounts) {

        int n = accounts.size();

        // Initialize DSU
        parent.resize(n);
        rankv.resize(n, 0);

        for (int i = 0; i < n; i++) {
            parent[i] = i;
        }

        unordered_map<string, int> mp;

        // Connect accounts using common emails
        for (int i = 0; i < n; i++) {

            for (int j = 1; j < accounts[i].size(); j++) {

                string mail = accounts[i][j];

                if (mp.find(mail) == mp.end()) {
                    mp[mail] = i;
                }
                else {
                    unite(i, mp[mail]);
                }
            }
        }

        // Store emails according to their root
        vector<vector<string>> mergemail(n);

        for (auto it : mp) {

            string mail = it.first;

            int node = find(it.second);

            mergemail[node].push_back(mail);
        }

        vector<vector<string>> ans;

        for (int i = 0; i < n; i++) {

            if (mergemail[i].empty())
                continue;

            sort(mergemail[i].begin(), mergemail[i].end());

            vector<string> temp;

            temp.push_back(accounts[i][0]);

            for (auto mail : mergemail[i]) {
                temp.push_back(mail);
            }

            ans.push_back(temp);
        }

        return ans;
    }
};