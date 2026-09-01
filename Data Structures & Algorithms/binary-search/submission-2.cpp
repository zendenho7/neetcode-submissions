class Solution {
public:
    int search(vector<int>& nums, int target) {
        
        for(int left = 0, right = nums.size() - 1, mid = (right - left) / 2; left <= right;) {
            if(target == nums[mid]) return mid;
            else if(target > nums[mid]) left = mid + 1;
            else right = mid - 1;

            mid = left + (right - left) / 2;
        }

        return -1;
    }
};
