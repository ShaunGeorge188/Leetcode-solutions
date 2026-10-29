
#include <bits/stdc++.h>
using namespace std;

class Solution {
    struct Fenwick {
        int n;
        vector<int> bit;

        Fenwick(int n) : n(n), bit(n + 2, 0) {}

        void update(int i, int val) {
            for (; i <= n; i += i & -i) {
                bit[i] ^= val;
            }
        }

        int query(int i) {
            int res = 0;
            for (; i > 0; i -= i & -i) {
                res ^= bit[i];
            }
            return res;
        }

        void rangeUpdate(int l, int r, int val) {
            update(l, val);
            update(r + 1, val);
        }
    };

public:
    vector<bool> palindromePath(
        int n,
        vector<vector<int>>& edges,
        string s,
        vector<string>& queries
    ) {
        vector<vector<int>> adj(n);

        for (const auto& e : edges) {
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
        }

        vector<int> tin(n), tout(n), depth(n), parent(n);
        vector<int> base(n, 0);
        int timer = 0;

        // Iterative DFS: avoids recursion and invalid references.
        vector<array<int, 3>> st;
        st.push_back({0, -1, 0});

        while (!st.empty()) {
            int u = st.back()[0];
            int p = st.back()[1];
            int state = st.back()[2];

            if (state == 0) {
                st.back()[2] = 1;

                parent[u] = p;
                tin[u] = ++timer;

                base[u] = (p == -1 ? 0 : base[p])
                          ^ (1 << (s[u] - 'a'));

                for (int v : adj[u]) {
                    if (v == p) continue;

                    depth[v] = depth[u] + 1;
                    st.push_back({v, u, 0});
                }
            } else {
                tout[u] = timer;
                st.pop_back();
            }
        }

        // Binary lifting table for LCA.
        int LOG = 1;
        while ((1 << LOG) <= n) {
            LOG++;
        }

        vector<vector<int>> up(LOG, vector<int>(n, -1));

        for (int u = 0; u < n; u++) {
            up[0][u] = parent[u];
        }

        for (int k = 1; k < LOG; k++) {
            for (int u = 0; u < n; u++) {
                int prev = up[k - 1][u];

                if (prev != -1) {
                    up[k][u] = up[k - 1][prev];
                }
            }
        }

        auto lca = [&](int a, int b) {
            if (depth[a] < depth[b]) {
                swap(a, b);
            }

            int diff = depth[a] - depth[b];

            for (int k = 0; k < LOG; k++) {
                if (diff & (1 << k)) {
                    a = up[k][a];
                }
            }

            if (a == b) {
                return a;
            }

            for (int k = LOG - 1; k >= 0; k--) {
                if (up[k][a] != up[k][b]) {
                    a = up[k][a];
                    b = up[k][b];
                }
            }

            return parent[a];
        };

        Fenwick fw(n + 1);

        auto pathMask = [&](int u, int v) {
            int w = lca(u, v);

            int pu = base[u] ^ fw.query(tin[u]);
            int pv = base[v] ^ fw.query(tin[v]);

            return pu ^ pv ^ (1 << (s[w] - 'a'));
        };

        vector<bool> ans;

        for (const string& q : queries) {
            stringstream ss(q);
            string type;
            int u;

            ss >> type >> u;

            if (type == "update") {
                char c;
                ss >> c;

                if (s[u] != c) {
                    int delta = (1 << (s[u] - 'a'))
                              ^ (1 << (c - 'a'));

                    fw.rangeUpdate(tin[u], tout[u], delta);
                    s[u] = c;
                }
            } else {
                int v;
                ss >> v;

                int mask = pathMask(u, v);

                ans.push_back((mask & (mask - 1)) == 0);
            }
        }

        return ans;
    }
};
