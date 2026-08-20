class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        int n = nums.size();
        long sum = 0;
        for(int i = 0; i < k; i++){
            sum += nums[i];
        }

        long maxSum = sum;

        int left = 0;
        int right = k;
        while(right < n){
            sum += nums[right];
            sum -= nums[left];

            if(sum > maxSum){
                maxSum = sum;
            }

            left++;
            right++;
        }

        return (double)maxSum / k;
    }
};