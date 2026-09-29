class Solution {
    bool visited[100][100][101];
    int m, n;

public:
    bool hasValidPath(vector<vector<char>>& grid) {
        m = grid.size();
        n = grid[0].size();

        // 1. Path length must be even for valid parentheses balance
        if ((m + n - 1) % 2 != 0) return false;

        // 2. Start must be '(' and end must be ')'
        if (grid[0][0] == ')' || grid[m - 1][n - 1] == '(') return false;

        memset(visited, 0, sizeof(visited));
        return dfs(0, 0, 0, grid);
    }

private:
    bool dfs(int r, int c, int balance, const vector<vector<char>>& grid) {
        // Update balance for current cell
        if (grid[r][c] == '(') {
            balance++;
        } else {
            balance--;
        }

        // Invalid path if balance drops below 0
        if (balance < 0) return false;

        // Pruning: maximum possible remaining '(' cannot exceed remaining steps
        int remainingSteps = (m - 1 - r) + (n - 1 - c);
        if (balance > remainingSteps) return false;

        // Base Case: Reached bottom-right cell
        if (r == m - 1 && c == n - 1) {
            return balance == 0;
        }

        // Memoization check
        if (visited[r][c][balance]) return false;
        visited[r][c][balance] = true;

        // Move Down
        if (r + 1 < m && dfs(r + 1, c, balance, grid)) {
            return true;
        }

        // Move Right
        if (c + 1 < n && dfs(r, c + 1, balance, grid)) {
            return true;
        }

        return false;
    }
};