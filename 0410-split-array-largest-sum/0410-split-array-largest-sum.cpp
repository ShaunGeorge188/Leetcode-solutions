class Solution {
public:

    int countSubarr(vector<int> nums, int maxSum){
        int n = nums.size();
        int partition = 1;
        int subarrSum = 0;

        for(int i =0; i < n; i++){
            if(subarrSum + nums[i] <= maxSum){
                subarrSum += nums[i];
            }else{
                partition++;
                subarrSum = nums[i];
            }
        }
        return partition;
    }
    int splitArray(vector<int>& nums, int k) {
        int n = nums.size();
        int low = *max_element(nums.begin(), nums.end());
        int high = accumulate(nums.begin(), nums.end(), 0);

        while(low <= high){
            int mid = low + (high - low) / 2;

            int partitions = countSubarr(nums, mid);

            if(partitions > k){
                low = mid + 1;
            }else{
                high = mid - 1;
            }
        }
        return low;
    }
};