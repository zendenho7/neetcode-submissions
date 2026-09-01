class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        stack<pair<int, int>> active;
        active.push({0, heights[0]});
        int maxArea = 0;

        for(int i = 1; i < heights.size(); ++i) {
            if(!active.empty()) {
                pair<int, int> top = active.top();

                if(heights[i] >= top.second) {
                    active.push({i, heights[i]});
                }
                else {
                    int right = i - 1;
                    int left = top.first;

                    while(heights[i] < top.second) {
                        left = top.first;
                        active.pop();

                        //Calculating the popped area
                        maxArea = max(maxArea, (right - left + 1) * top.second);

                        if(active.empty()) break;
                        top = active.top();
                    }
                    active.push({left, heights[i]});
                }
            }
        }

        pair<int, int> top = active.top();
        int right = heights.size() - 1;
        while(!active.empty()) {
            active.pop();

            //Calculating the popped area
            maxArea = max(maxArea, (right - top.first + 1) * top.second);

            if(active.empty()) break;
            top = active.top();
        }

        return maxArea;
    }
};
