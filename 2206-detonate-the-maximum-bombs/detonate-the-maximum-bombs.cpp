class Solution {
public:
    using ll=long long;
    int maximumDetonation(vector<vector<int>>& bombs) {
        ll n=bombs.size();
        vector<vector<ll>> adj(n);
        for(ll i=0;i<n;i++){
            ll x=bombs[i][0];
            ll y=bombs[i][1];
            ll r=bombs[i][2];
            for(ll j=0;j<n;j++){
                if(i==j) continue;
                ll x2=bombs[j][0];
                ll y2=bombs[j][1];
                if((x2-x)*(x2-x)+(y2-y)*(y2-y)<=r*r) adj[i].push_back(j);
            }
        }

        int ans=0;
        for(ll i=0;i<n;i++){
            vector<ll> vis(n,0);
            queue<ll> q;
            q.push(i);
            vis[i]=1;
            int cnt=0;
            while(!q.empty()){
                ll node=q.front();
                q.pop();
                cnt++;
                for(auto it : adj[node]){
                    if(!vis[it]){
                        vis[it]=1;
                        q.push(it);
                    }
                }
            }
            ans=max(ans,cnt);
        }
        return ans;
    }
};