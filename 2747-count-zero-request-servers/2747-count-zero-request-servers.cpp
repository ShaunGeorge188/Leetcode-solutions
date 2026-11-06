
class Solution {
public:
    vector<int> countServers(int n, vector<vector<int>>& logs, int x, vector<int>& queries) {
        
        int m = queries.size();

        // Sort logs by time
        sort(logs.begin(), logs.end(), [](const vector<int>& a, const vector<int>& b) {
            return a[1] < b[1];
        });

        // Store query time and original index
        vector<pair<int, int>> q;

        for (int i = 0; i < m; i++) {
            q.push_back({queries[i], i});
        }

        sort(q.begin(), q.end());

        vector<int> ans(m, 0);
        vector<int> cnt(n + 1, 0);

        int left = 0, right = 0;
        int active = 0;

        for (auto& [t, idx] : q) {

            int start = t - x;

            // Add logs whose time <= query time
            while (right < logs.size() && logs[right][1] <= t) {
                int id = logs[right][0];

                if (cnt[id] == 0) {
                    active++;
                }

                cnt[id]++;
                right++;
            }

            // Remove logs whose time < start
            while (left < right && logs[left][1] < start) {
                int id = logs[left][0];

                cnt[id]--;

                if (cnt[id] == 0) {
                    active--;
                }

                left++;
            }

            // Servers without requests
            ans[idx] = n - active;
        }

        return ans;
    }
};
