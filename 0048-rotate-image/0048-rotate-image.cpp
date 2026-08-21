class Solution {
public:
    vector<vector<int>> transpose(vector<vector<int>>& matrix, int n){

        for(int i = 0; i < n; i++){
            for(int j =i + 1; j < n; j++){
                swap(matrix[i][j], matrix[j][i]);
                
            }
        }
        return matrix;
    }
    void rotate(vector<vector<int>>& matrix) {

        int n = matrix.size();
        transpose(matrix, n);
        for(int i = 0; i < n; i++){
            reverse(matrix[i].begin(), matrix[i].end());
        }
    }
};