class Solution {
public:
    int binarySearch(vector<int>& nums, int target, bool findLeft){
        int start = 0; 
        int end = nums.size() - 1;
        int res = -1;

        while(start <= end){
            int mid = start + (end - start ) / 2;

            if(nums[mid] == target){
                res = mid;
                if(findLeft){
                    end = mid - 1;
                }
                else{
                    start = mid + 1;
                }
            }
            else if(nums[mid] < target){
                start = mid + 1;
            }
            else{
                end = mid - 1;
            }
        }
        return res;
    }
    vector<int> searchRange(vector<int>& nums, int target) {
       int leftIdx = binarySearch(nums, target, true);

       if(leftIdx == -1) return {-1, -1};

       int rightIdx = binarySearch(nums, target, false);
       return {leftIdx, rightIdx};
    }
};