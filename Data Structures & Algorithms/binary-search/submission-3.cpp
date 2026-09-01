class Solution {
public:
    int search(vector<int>& nums, int target) {
        
        for(int left = 0, right = nums.size() - 1, mid = 0; left <= right;) {
            mid = left + (right - left) / 2;
            if(target == nums[mid]) return mid;
            else if(target > nums[mid]) left = mid + 1;
            else right = mid - 1;
        }

        return -1;
    }
};
