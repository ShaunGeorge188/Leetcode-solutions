class Solution {
public:
    vector<int> remainingMethods(int n, int k, vector<vector<int>>& invocations) {
        // Step 1: Build the adjacency list for the directed graph
        vector<vector<int>> adj(n);
        for (const auto& inv : invocations) {
            adj[inv[0]].push_back(inv[1]);
        }
        
        // Step 2: Find all suspicious methods using BFS
        vector<bool> isSuspicious(n, false);
        queue<int> q;
        
        q.push(k);
        isSuspicious[k] = true;
        
        while (!q.empty()) {
            int curr = q.front();
            q.pop();
            
            for (int neighbor : adj[curr]) {
                if (!isSuspicious[neighbor]) {
                    isSuspicious[neighbor] = true;
                    q.push(neighbor);
                }
            }
        }
        
        // Step 3: Check if any non-suspicious method invokes a suspicious method
        bool canRemove = true;
        for (const auto& inv : invocations) {
            int u = inv[0];
            int v = inv[1];
            if (!isSuspicious[u] && isSuspicious[v]) {
                canRemove = false;
                break;
            }
        }
        
        // Step 4: Collect and return the remaining methods
        vector<int> result;
        if (canRemove) {
            // Remove the suspicious ones
            for (int i = 0; i < n; ++i) {
                if (!isSuspicious[i]) {
                    result.push_back(i);
                }
            }
        } else {
            // Cannot remove anything, return all methods
            for (int i = 0; i < n; ++i) {
                result.push_back(i);
            }
        }
        
        return result;
    }
};