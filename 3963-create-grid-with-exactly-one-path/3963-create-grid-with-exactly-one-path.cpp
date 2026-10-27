#include <vector>
#include <string>

class Solution {
public:
    std::vector<std::string> createGrid(int m, int n) {
        // Initialize the grid with all obstacles '#'
        std::vector<std::string> grid(m, std::string(n, '#'));
        
        // 1. Clear the path along the top row
        for (int j = 0; j < n; ++j) {
            grid[0][j] = '.';
        }
        
        // 2. Clear the path along the last column
        for (int i = 0; i < m; ++i) {
            grid[i][n - 1] = '.';
        }
        
        return grid;
    }
};