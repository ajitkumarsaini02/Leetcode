class Solution {
public:
    using ll = long long;
    vector<vector<int>> adj;
    vector<ll> w;
    vector<ll> sz;
    ll maxGain = 0;

    void getSize(int p, int u) {
        sz[u] = 1;
        for (auto v : adj[u]) {
            if (v != p) {
                getSize(u, v);
                sz[u] += sz[v];
            }
        }
    }

    ll dfs(int p, int u) {
        ll curr = w[u];
        for (auto v : adj[u]) {
            if (v != p) {
                ll childGain = dfs(u, v);
                if (childGain > 0) {
                    curr += childGain;
                }
            }
        }
        maxGain = max(maxGain, curr);
        return curr;
    }

    ll minCost(int n, string colors, vector<vector<int>>& edges) {
        adj.assign(n, vector<int>());
        for (auto& edge : edges) {
            adj[edge[0]].push_back(edge[1]);
            adj[edge[1]].push_back(edge[0]);
        }

        sz.assign(n, 0);
        getSize(-1, 0);

        ll baseCost = 0;
        w.assign(n, 0);

        for (int i = 0; i < n; i++) {
            if (colors[i] == 'R') {
                baseCost += sz[i];
                w[i] = sz[i];
            } else {
                w[i] -= sz[i];
            }
        }

        dfs(-1, 0);
        return baseCost - maxGain;
    }
};