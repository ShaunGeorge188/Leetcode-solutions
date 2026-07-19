class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int n = nums.size();
        for(int i = 1;  i  < n; i+=2){
            if(nums[i] != nums[i-1]){
                return nums[i-1];
            }
            else{
                continue;
            }
        }

        if(n % 2 != 0){
            return nums[n-1];
        }

        return -1;
    }
};