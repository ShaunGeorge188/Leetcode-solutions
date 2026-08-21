class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& mat) {
        int rows = mat.size();
        int cols = mat[0].size();

        // group elements by diagonal index (row + col)
        vector<vector<int>> diagonals(rows + cols - 1);

        for (int r = 0; r < rows; r++) {
            for (int c = 0; c < cols; c++) {
                int d = r + c;
                diagonals[d].push_back(mat[r][c]);
            }
        }

        vector<int> res;
        for (int d = 0; d < diagonals.size(); d++) {
            if (d % 2 == 0) {
                // even diagonals go bottom-to-top, so reverse them
                reverse(diagonals[d].begin(), diagonals[d].end());
            }
            // odd diagonals are already top-to-bottom order, keep as-is
            for (int val : diagonals[d]) {
                res.push_back(val);
            }
        }

        return res;
    }
};