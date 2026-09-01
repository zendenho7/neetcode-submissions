class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        stack<int> fleets;
        vector<int> descIndex(position.size());
        iota(descIndex.begin(), descIndex.end(), 0);
        sort(descIndex.begin(), descIndex.end(), [&](int a, int b) {
            return position[a] > position[b]; 
        });

        fleets.push(descIndex[0]);

        for(int i = 1; i < descIndex.size(); ++i) {

            if(!fleets.empty()) {
                int top = fleets.top();
                int curr = descIndex[i];

                float topTurn = static_cast<float>(target - position[top]) / speed[top];
                float currTurn = static_cast<float>(target - position[curr]) / speed[curr];

                if(currTurn > topTurn) fleets.push(curr);
            }
        }

        return fleets.size();
    }
};
