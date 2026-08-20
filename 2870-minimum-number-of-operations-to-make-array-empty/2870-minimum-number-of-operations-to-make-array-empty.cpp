class Solution {
public:
    int minOperations(vector<int>& nums) {
        unordered_map<int, int> freq;

        for(int num : nums){
            freq[num]++;
        }

        int c = 0;
        for(auto& [key, val] : freq){
            if(val == 1){
                return -1;
            }else{
                c = c + (val + 2) / 3;
            }
        }
        return c;
    } 
};