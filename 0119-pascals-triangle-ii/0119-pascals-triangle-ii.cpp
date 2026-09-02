class Solution {
public:
    vector<int> getRow(int rowIndex) {
        // Initialize a vector of size (rowIndex + 1) with all zeros, starting with 1 at the edge
        vector<int> row(rowIndex + 1, 0);
        row[0] = 1;
        
        // Build the triangle row by row up to the target rowIndex
        for (int i = 1; i <= rowIndex; ++i) {
            // Update backwards from i down to 1
            for (int j = i; j >= 1; --j) {
                row[j] += row[j - 1];
            }
        }
        
        return row;
    }
};