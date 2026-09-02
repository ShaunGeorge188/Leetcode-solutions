class Solution {
public:
    vector<int> luckyNumbers (vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();
        vector<int> result;
        
        for (int i = 0; i < m; ++i) {
            // 1. Find the minimum element in the current row
            int rowMin = matrix[i][0];
            int colIndex = 0;
            for (int j = 1; j < n; ++j) {
                if (matrix[i][j] < rowMin) {
                    rowMin = matrix[i][j];
                    colIndex = j;
                }
            }
            
            // 2. Check if this row minimum is the maximum in its column
            bool isMaxInCol = true;
            for (int k = 0; k < m; ++k) {
                if (matrix[k][colIndex] > rowMin) {
                    isMaxInCol = false;
                    break;
                }
            }
            
            // 3. If it satisfies both conditions, it is a lucky number
            if (isMaxInCol) {
                result.push_back(rowMin);
            }
        }
        
        return result;
    }
};