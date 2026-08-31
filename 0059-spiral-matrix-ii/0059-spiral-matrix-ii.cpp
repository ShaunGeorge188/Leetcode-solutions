#include <vector>

class Solution {
public:
    std::vector<std::vector<int>> generateMatrix(int n) {
        // Initialize an n x n matrix with zeros
        std::vector<std::vector<int>> matrix(n, std::vector<int>(n, 0));
        
        int top = 0;
        int bottom = n - 1;
        int left = 0;
        int right = n - 1;
        
        int val = 1;
        
        while (val <= n * n) {
            // 1. Move left to right across the top row
            for (int i = left; i <= right; ++i) {
                matrix[top][i] = val++;
            }
            top++; // Shrink top boundary
            
            // 2. Move top to bottom down the right column
            for (int i = top; i <= bottom; ++i) {
                matrix[i][right] = val++;
            }
            right--; // Shrink right boundary
            
            // 3. Move right to left across the bottom row
            // (The if-check prevents duplicate processing in non-square matrices, 
            // though n x n guarantees this is mostly safe, it's good practice)
            if (top <= bottom) {
                for (int i = right; i >= left; --i) {
                    matrix[bottom][i] = val++;
                }
                bottom--; // Shrink bottom boundary
            }
            
            // 4. Move bottom to top up the left column
            if (left <= right) {
                for (int i = bottom; i >= top; --i) {
                    matrix[i][left] = val++;
                }
                left++; // Shrink left boundary
            }
        }
        
        return matrix;
    }
};