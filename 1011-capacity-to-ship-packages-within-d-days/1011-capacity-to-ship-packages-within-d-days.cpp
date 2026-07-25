class Solution {
public:
    int daysNeeded(vector<int> weights, int capacity){
        int days = 1;
        int currentLoad = 0;

        for(int weight: weights){
            if(currentLoad + weight > capacity){
                days++;
                currentLoad = weight;
            }
            else{
                currentLoad += weight;
            }
        }
        return days;
    }
    int shipWithinDays(vector<int>& weights, int days) {

        int low = *max_element(weights.begin(), weights.end());

        int high = accumulate(weights.begin(), weights.end(), 0);

        while(low < high){
            int mid = low + (high - low) / 2;
            int needed = daysNeeded(weights, mid);

            if(needed <= days){
                high = mid;
            }else{
                low = mid + 1;
            }
        }
        return low;
    }
};