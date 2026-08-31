class Solution {
public:
    bool validMountainArray(vector<int>& arr) {

        //look out for edge cases.
        if(arr.size() < 3){
            return false;
        }

        //size of arr.
        int n = arr.size();
        
        //climb the array till peak.
        int i = 0;

        while(i + 1 < n && arr[i] < arr[i + 1]){
            i++;
        }

        if(i == 0 || i == n - 1){
            return false;
        }

        //climb down the peak.
        while(i + 1 < n && arr[i] > arr[i + 1]){
            i++;
        }

        //now that we have reached end return true.
        return i == n-1;
        
    }
};