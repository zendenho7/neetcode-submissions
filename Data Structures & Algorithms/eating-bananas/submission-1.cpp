class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {

        //Define result var
        int result = INT_MAX;
        
        //Identify the max element within piles for right range
        int r = 0;
        for(int i : piles) {
            r = max(r, i);
        }

        int l = 1;
        int mid = 0;
        while(l <= r) {

            //Compute the middle
            mid = l + (r-l) / 2;

            //Compute the h for selected k
            int val = 0;
            for(int pile : piles) {
                val += ceil(static_cast<double>(pile) / mid);
            }

            //Check value
            if(val > h) {
                l = mid + 1;
            }
            else {
                r = mid - 1;
                result = min(result, mid);
            }
        }

        return result;
    }
};
