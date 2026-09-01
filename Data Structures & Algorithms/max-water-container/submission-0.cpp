class Solution {
public:
    int maxArea(vector<int>& heights) {
        
        int max_area = 0;

        for(int l = 0, r = heights.size() - 1; l < r;) {

            int curr_area = (r - l) * min(heights[l], heights[r]);

            max_area = max(max_area, curr_area);

            if(heights[l] >= heights[r]) --r;
            else ++l;
        }

        return max_area;
    }
};
