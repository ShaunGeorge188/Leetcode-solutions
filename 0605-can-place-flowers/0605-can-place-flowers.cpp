class Solution {
public:
    bool canPlaceFlowers(vector<int>& flowerbed, int n) {
        int size = flowerbed.size();
        
        for (int i = 0; i < size; ++i) {
            // If the current spot is empty, check its neighbors
            if (flowerbed[i] == 0) {
                bool leftEmpty = (i == 0) || (flowerbed[i - 1] == 0);
                bool rightEmpty = (i == size - 1) || (flowerbed[i + 1] == 0);
                
                // If both sides are clear, plant a flower here
                if (leftEmpty && rightEmpty) {
                    flowerbed[i] = 1; // Mark as planted
                    n--;              // Reduce our remaining target count
                }
            }
            
            // Optimization: If we've already planted enough flowers, exit early
            if (n <= 0) {
                return true;
            }
        }
        
        return n <= 0;
    }
};