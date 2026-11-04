class Solution {
public:
    int numSimilarGroups(vector<string>& s) {
        int n = s.size();
        int m = s[0].size();

        vector<int> vis(n, 0);
        int cnt = 0;

        for(int i = 0; i < n; i++) {
            if(vis[i]) continue;

            queue<int> q;
            q.push(i);
            vis[i] = 1;

            while(!q.empty()) {
                int idx = q.front();//tars outer
                q.pop();

                for(int j = 0; j < n; j++) {//comparing with others
                    if(vis[j]) continue;

                    int diff = 0;

                    for(int k = 0; k < m; k++) {
                        if(s[idx][k] != s[j][k]) {
                            diff++;
                        }
                    }

                    if(diff == 0 || diff == 2) {
                        vis[j] = 1;
                        q.push(j);
                    }
                }
            }

            cnt++;
        }

        return cnt;
    }
};