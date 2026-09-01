class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        set<int> num_set(nums.begin(), nums.end());

        int max_count = 0;
        int count = 0;
        for(auto it = num_set.begin(); it != num_set.end(); ++it) {
            max_count = max_count < ++count ? count : max_count;
            auto next_it = next(it);
            if(next_it == num_set.end() || abs(*next_it - *it) != 1) count = 0;
        }

        return max_count;
    }
};
