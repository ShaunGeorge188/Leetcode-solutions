class Solution {
public:
    vector<int> busiestServers(int k, vector<int>& arrival, vector<int>& load) {
        set<int> available;

        for (int i = 0; i < k; i++) {
            available.insert(i);
        }

        // {finish_time, server_id}
        priority_queue<pair<long long, int>,
                       vector<pair<long long, int>>,
                       greater<pair<long long, int>>> busy;

        vector<int> count(k, 0);

        for (int i = 0; i < arrival.size(); i++) {

            // Release all servers whose requests have finished
            while (!busy.empty() && busy.top().first <= arrival[i]) {
                available.insert(busy.top().second);
                busy.pop();
            }

            // If no server is available, drop the request
            if (available.empty()) {
                continue;
            }

            // Find the first available server >= (i % k)
            int target = i % k;

            auto it = available.lower_bound(target);

            // Wrap around if necessary
            if (it == available.end()) {
                it = available.begin();
            }

            int server = *it;

            // Assign request to this server
            available.erase(it);

            count[server]++;

            // Mark server as busy until arrival[i] + load[i]
            busy.push({
                (long long)arrival[i] + load[i],
                server
            });
        }

        // Find maximum number of requests handled
        int maxi = *max_element(count.begin(), count.end());

        vector<int> ans;

        for (int i = 0; i < k; i++) {
            if (count[i] == maxi) {
                ans.push_back(i);
            }
        }

        return ans;
    }
};