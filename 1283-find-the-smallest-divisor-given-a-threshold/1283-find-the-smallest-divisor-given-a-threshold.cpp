class Solution {
public:
    int computeSum(vector<int>& nums, int div){
        int sum = 0;
        for(int num : nums){
            sum += ceil(double(num)/div);
        }
        return sum;
    }
    int smallestDivisor(vector<int>& nums, int threshold) {
        int n = nums.size();

        int low = 1;
        int high = *max_element(nums.begin(), nums.end());

        while(low < high){
            int mid = (low + high ) / 2;

            if(computeSum(nums, mid) <= threshold){
                high = mid;
            }else{
                low = mid + 1;
            }
        }
        return low;
    }
};