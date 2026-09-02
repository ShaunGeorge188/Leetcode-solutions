class Solution {
public:
    int minMoves(vector<string>& classroom, int energy) {
        int m = classroom.size();
        int n = classroom[0].size();
        
        int litter_idx = 0;
        vector<vector<int>> litter_id(m, vector<int>(n, -1));
        int start_r = -1, start_c = -1;
        
        // 1. Identify starting position and assign a unique bit index to each 'L'
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (classroom[i][j] == 'S') {
                    start_r = i;
                    start_c = j;
                } else if (classroom[i][j] == 'L') {
                    litter_id[i][j] = litter_idx++;
                }
            }
        }
        
        int target_mask = (1 << litter_idx) - 1;
        // If there is no litter to collect, 0 moves are required
        if (target_mask == 0) return 0;
        
        // max_energy[r][c][mask] stores the max energy remaining at this state
        vector<vector<vector<int>>> max_energy(m, 
            vector<vector<int>>(n, vector<int>(1 << litter_idx, -1)));
        
        // Queue stores: {row, col, collected_mask, current_energy}
        queue<array<int, 4>> q;
        q.push({start_r, start_c, 0, energy});
        max_energy[start_r][start_c][0] = energy;
        
        int moves = 0;
        int dirs[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
        
        // 2. BFS Traversal
        while (!q.empty()) {
            int sz = q.size();
            while (sz--) {
                auto [r, c, mask, cur_en] = q.front();
                q.pop();
                
                // If energy is 0 here, the student cannot move anywhere else
                if (cur_en == 0) continue; 
                
                for (auto& d : dirs) {
                    int nr = r + d[0];
                    int nc = c + d[1];
                    
                    // Out of bounds or hit an obstacle
                    if (nr < 0 || nr >= m || nc < 0 || nc >= n || classroom[nr][nc] == 'X') {
                        continue;
                    }
                    
                    int nxt_en = cur_en - 1;
                    int nxt_mask = mask;
                    
                    // Handle special cells
                    if (classroom[nr][nc] == 'L') {
                        nxt_mask |= (1 << litter_id[nr][nc]);
                    } else if (classroom[nr][nc] == 'R') {
                        nxt_en = energy; // Restore energy to max capacity
                    }
                    
                    // State Pruning: Only proceed if this path yields strictly better energy 
                    // for this specific location and collection state.
                    if (nxt_en > max_energy[nr][nc][nxt_mask]) {
                        max_energy[nr][nc][nxt_mask] = nxt_en;
                        
                        // Check if we have collected all litter
                        if (nxt_mask == target_mask) {
                            return moves + 1;
                        }
                        
                        q.push({nr, nc, nxt_mask, nxt_en});
                    }
                }
            }
            moves++;
        }
        
        return -1; // Impossible to collect all litter
    }
};