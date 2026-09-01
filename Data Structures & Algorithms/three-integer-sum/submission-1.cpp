class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {

        vector<vector<int>> result;
        
        sort(nums.begin(), nums.end());

        for(int i = 0; i < nums.size() - 2; ++i) {

            //Skip duplicates
            if(i > 0 && nums[i] == nums[i - 1]) continue;

            //Compute 2 sum target
            int target = 0 - nums[i];

            //Using 2 pointers to find 2 sum  of target
            for(int j = i + 1, k = nums.size() - 1; j < k;) {

                if(nums[k] + nums[j] > target) --k;
                else if (nums[k] + nums[j] < target) ++j;
                else {
                    result.push_back({nums[i], nums[j], nums[k]});
                    ++j;
                    while(nums[j] == nums[j - 1] && j < k) ++j;
                }
            }
        }

        return result;
    }
};
