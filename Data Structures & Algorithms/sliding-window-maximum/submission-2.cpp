class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {

        vector<int> result;
        int curr_max = INT_MIN;

        for(int i = 0; i < k; ++i) {
            curr_max = max(curr_max, nums[i]);
        }

        for(int i = 0, j = i + k - 1; j < nums.size();++j, ++i) {
            curr_max = max(curr_max, nums[j]);
            result.push_back(curr_max);
            if(nums[i] == curr_max) {
                curr_max = INT_MIN;
                for(int l = i + 1; l <= j; ++l) {
                    curr_max = max(curr_max, nums[l]);
                }
            }
        }

        return result;
    }
};
