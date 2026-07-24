class Solution {
public:
    bool possible(vector<int>& arr, int day, int m, int k) {
        int n = arr.size();         // Total number of flowers
        int cnt = 0;                // Counter for consecutive bloomed flowers
        int bouquets = 0;           // Count of bouquets made

        for (int i = 0; i < n; i++) {
            if (arr[i] <= day) {
                // Flower bloomed, increment consecutive count
                cnt++;
                if (cnt == k) {
                    // We have k consecutive bloomed flowers — make 1 bouquet
                    bouquets++;
                    cnt = 0; // reset for next bouquet
                }
            } else {
                // Flower not bloomed, reset consecutive count
                cnt = 0;
            }
        }

        // Check if at least m bouquets can be made
        return bouquets >= m;
    }
    int minDays(vector<int>& bloomDay, int m, int k) {
        long long total = 1LL * k * m; // Total flowers required

        // If total required flowers > available flowers, it's impossible
        if (total > bloomDay.size()) return -1;

        // Find minimum and maximum bloom days from array
        int mini = *min_element(bloomDay.begin(), bloomDay.end());
        int maxi = *max_element(bloomDay.begin(), bloomDay.end());

        // Apply binary search on number of days
        int low = mini, high = maxi;
        int result = -1;

        while (low <= high) {
            int mid = (low + high) / 2;

            if (possible(bloomDay, mid, m, k)) {
                // If it's possible to make bouquets on this day, try to find an earlier day
                result = mid;
                high = mid - 1;
            } else {
                // Otherwise, try with a later day
                low = mid + 1;
            }
        }

        return result;
    }
};