class Solution {
public:
    int findMin(vector<int> &nums) {
        int l = 0;
        int r = nums.size() - 1;
        int mid = 0;
        int minVal = INT_MAX;
        while(l <= r) {
            mid = l + (r - l) / 2;
            minVal = min(minVal, nums[mid]);

            if(nums.back() < nums[mid]) l = mid + 1;
            else r = mid - 1; 
        }
        return minVal;
    }
};
