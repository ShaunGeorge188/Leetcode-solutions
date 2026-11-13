
class Solution {
public:
    using ll = long long;

    static const int LOG = 20;

    int n;
    vector<int> nxt;
    vector<vector<int>> up;
    vector<vector<ll>> sum;
    vector<ll> pref;
    vector<int> a;

    void build() {
        n = a.size();

        nxt.assign(n, n);
        pref.assign(n + 1, 0);

        for (int i = 0; i < n; i++) {
            pref[i + 1] = pref[i] + a[i];
        }

        // Next strictly greater element
        stack<int> st;

        for (int i = n - 1; i >= 0; i--) {
            while (!st.empty() && a[st.top()] <= a[i]) {
                st.pop();
            }

            if (!st.empty()) {
                nxt[i] = st.top();
            }

            st.push(i);
        }

        // Binary lifting tables
        up.assign(LOG, vector<int>(n, n));
        sum.assign(LOG, vector<ll>(n, 0));

        for (int i = 0; i < n; i++) {
            up[0][i] = nxt[i];

            sum[0][i] =
                1LL * a[i] * (nxt[i] - i)
                - (pref[nxt[i]] - pref[i]);
        }

        for (int j = 1; j < LOG; j++) {
            for (int i = 0; i < n; i++) {
                int mid = up[j - 1][i];

                if (mid == n) {
                    up[j][i] = n;
                    sum[j][i] = sum[j - 1][i];
                } else {
                    up[j][i] = up[j - 1][mid];

                    sum[j][i] =
                        sum[j - 1][i] + sum[j - 1][mid];
                }
            }
        }
    }

    // Minimum operations needed for subarray [l, r]
    ll getCost(int l, int r) {
        ll cost = 0;
        int p = l;

        for (int j = LOG - 1; j >= 0; j--) {
            if (up[j][p] <= r) {
                cost += sum[j][p];
                p = up[j][p];
            }
        }

        // Process the final segment
        cost += 1LL * a[p] * (r + 1 - p)
                - (pref[r + 1] - pref[p]);

        return cost;
    }

    long long countNonDecreasingSubarrays(
        vector<int>& nums, int k
    ) {
        a = nums;
        build();

        ll ans = 0;

        for (int r = 0; r < n; r++) {
            int lo = 0;
            int hi = r;

            // Binary search for the smallest valid left endpoint
            while (lo < hi) {
                int mid = lo + (hi - lo) / 2;

                if (getCost(mid, r) <= k) {
                    hi = mid;
                } else {
                    lo = mid + 1;
                }
            }

            ans += (r - lo + 1);
        }

        return ans;
    }
};
