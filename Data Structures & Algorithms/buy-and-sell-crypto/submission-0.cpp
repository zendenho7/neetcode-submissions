class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int max_profit = 0;

        for(int i = 0, j = i + 1; j < prices.size();) {
            max_profit = max(max_profit, prices[j] - prices[i]);

            if(prices[j] < prices[i]) {
                i = j;
                j = i + 1;
            }
            else {
                ++j;
            }
        }

        return max_profit;
    }
};
