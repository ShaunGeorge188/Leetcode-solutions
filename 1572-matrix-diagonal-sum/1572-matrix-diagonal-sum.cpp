class Solution {
public:
    int diagonalSum(vector<vector<int>>& mat) {
        int s = 0;
        int r = mat.size();
        int c = mat[0].size();

        for(int i =0; i < r; i++){
            for(int j = 0; j < r; j++){
                if(i == j){
                    s = s + mat[i][j];

                }else if(i + j == r - 1){
                    s = s + mat[i][j];
                }
            }
        }
        return s;
    }
};