class Solution {
public:
    int trap(vector<int>& height) {

        if(height.empty()) return 0;
        
        int max_l = 0;
        int max_r = 0;
        int amount = 0;

        for(int l = 0, r = height.size() - 1; l < r;) {

            max_l = max(max_l, height[l]);
            max_r = max(max_r, height[r]);

            if(max_l <= max_r) {
                amount += max(0, min(max_l, max_r) - height[l]);
                ++l;
            }
            else {
                amount += max(0, min(max_l, max_r) - height[r]);
                --r;
            }
        }

        return amount;
    }
};
