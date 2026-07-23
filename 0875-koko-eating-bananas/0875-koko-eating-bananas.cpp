class Solution {
public:

    int calcHours(vector<int> &piles, int hourly){
        int totalhours = 0;
        for(int pile : piles){
            totalhours += (pile + hourly - 1) / hourly;
        }
        return totalhours;
    }
    int minEatingSpeed(vector<int>& piles, int h) {
        int lo = 1;
        int hi = *max_element(piles.begin(), piles.end());

        while(lo < hi){
            int mid = lo + (hi - lo) / 2;
            int hours = calcHours(piles, mid);

            if(hours <= h){
                hi = mid;
            }else{
                lo = mid + 1;
            }
        }
        return lo;
    }
};