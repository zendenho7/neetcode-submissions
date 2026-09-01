class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int> result;

        int prefix = 1;
        int postfix = 1;

        for(auto const& num : nums) {
            result.push_back(prefix);
            prefix *= num;
        }

        for(int i = nums.size() - 1; i >= 0; --i) {
            result[i] *= postfix;
            postfix *= nums[i];
        }

        return result;
    }
};
