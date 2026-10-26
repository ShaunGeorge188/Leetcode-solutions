#include <vector>
#include <queue>

class Solution {
public:
    int countIslands(std::vector<std::vector<int>>& grid, int k) {
        int m = grid.size();
        if (m == 0) return 0;
        int n = grid[0].size();
        
        int ans = 0;
        // Direction vectors for moving up, down, left, right
        int dirs[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
        
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                // If we find an unvisited land cell
                if (grid[i][j] > 0) {
                    long long current_sum = 0;
                    std::queue<std::pair<int, int>> q;
                    
                    q.push({i, j});
                    current_sum += grid[i][j];
                    grid[i][j] = 0; // Mark as visited by sinking the land
                    
                    // Traverse the entire island
                    while (!q.empty()) {
                        auto [r, c] = q.front();
                        q.pop();
                        
                        for (auto& d : dirs) {
                            int nr = r + d[0];
                            int nc = c + d[1];
                            
                            // Check bounds and if the adjacent cell is land
                            if (nr >= 0 && nr < m && nc >= 0 && nc < n && grid[nr][nc] > 0) {
                                current_sum += grid[nr][nc];
                                grid[nr][nc] = 0; // Mark visited immediately to prevent duplicates in queue
                                q.push({nr, nc});
                            }
                        }
                    }
                    
                    // Verify if the island's total value is divisible by k
                    if (current_sum % k == 0) {
                        ans++;
                    }
                }
            }
        }
        
        return ans;
    }
};