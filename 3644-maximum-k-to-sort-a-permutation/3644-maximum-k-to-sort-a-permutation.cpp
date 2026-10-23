class Solution {
public:
    int sortPermutation(vector<int>& nums) {
        int k = -1; // this is an accumulator for AND operations remember this.

        for(int i = 0; i < (int)nums.size(); i++){
            if(nums[i] != i) k &= nums[i];    //calculating the misplaced and also accumulating it in k;
        }
        return k == -1 ? 0 : k;
    }
};