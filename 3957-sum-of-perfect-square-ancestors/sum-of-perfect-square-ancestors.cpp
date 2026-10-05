class Solution {
public:

    int squareFree(int x, vector<int>& spf) {

        int result = 1;

        while (x > 1) {

            int p = spf[x];
            int cnt = 0;

            while (x % p == 0) {
                x /= p;
                cnt++;
            }

            
            if (cnt % 2 == 1)
                result *= p;
        }

        return result;
    }

    long long sumOfAncestors(int n,
                             vector<vector<int>>& edges,
                             vector<int>& nums) {

        
        
        

        vector<vector<int>> adj(n);

        for (auto& edge : edges) {

            int u = edge[0];
            int v = edge[1];

            adj[u].push_back(v);
            adj[v].push_back(u);
        }


        
        
        

        int maxNum = *max_element(nums.begin(), nums.end());


        
        
        

        vector<int> spf(maxNum + 1);

        for (int i = 0; i <= maxNum; i++)
            spf[i] = i;

        for (int i = 2; i * i <= maxNum; i++) {

            if (spf[i] == i) {

                for (int j = i * i; j <= maxNum; j += i) {

                    if (spf[j] == j)
                        spf[j] = i;
                }
            }
        }


        
        
        

        vector<int> value(n);

        for (int i = 0; i < n; i++) {
            value[i] = squareFree(nums[i], spf);
        }


        
        
        

        unordered_map<int, int> freq;

        long long ans = 0;

       

        stack<tuple<int, int, int>> st;

        st.push({0, -1, 0});

        while (!st.empty()) {

            auto [node, parent, state] = st.top();
            st.pop();


            
            if (state == 0) {

                
                ans += freq[value[node]];

                
                freq[value[node]]++;

                
                st.push({node, parent, 1});

                
                for (int i = adj[node].size() - 1; i >= 0; i--) {

                    int nei = adj[node][i];

                    if (nei == parent)
                        continue;

                    st.push({nei, node, 0});
                }
            }


            
            else {

                freq[value[node]]--;
            }
        }

        return ans;
    }
};