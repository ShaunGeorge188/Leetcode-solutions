class Solution {
public:
    vector<int> resultArray(vector<int>& nums) {
        int n = nums.size();
        vector<int> arr1;
        vector<int> arr2;
        vector<int> res;

        arr1.push_back(nums[0]);
        arr2.push_back(nums[1]);

        int i = 2;
        while(i < n){
            if(arr1.back() > arr2.back()){
                arr1.push_back(nums[i]);
            }else{
                arr2.push_back(nums[i]);
            }
            i++;
        }

        res = arr1;
        res.insert(res.end(), arr2.begin(), arr2.end());
        return res;
    }
};