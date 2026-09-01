class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> num_set(nums.begin(), nums.end());

        int max_count = 0;
        for(auto const& val : num_set) {
            //Check left
            if(num_set.contains(val - 1)) continue;

            //Check right to form sequence
            int next_val = val + 1;
            int count = 1;
            while(num_set.contains(next_val)){ 
                ++count;
                ++next_val;
            }
            max_count = count > max_count ? count : max_count;
        }
        return max_count;
    }
};
