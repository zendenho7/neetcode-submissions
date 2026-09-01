class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {

        deque<int> dq;
        vector<int> result;

        for (int right = 0; right < nums.size(); ++right) {

            // Remove elements outside the window
            while (!dq.empty() && dq.front() <= right - k) {
                dq.pop_front();
            }

            // Maintain decreasing order
            while (!dq.empty() && nums[dq.back()] <= nums[right]) {
                dq.pop_back();
            }

            dq.push_back(right);

            // Window has reached size k
            if (right >= k - 1) {
                result.push_back(nums[dq.front()]);
            }
        }

        return result;
    }
};
