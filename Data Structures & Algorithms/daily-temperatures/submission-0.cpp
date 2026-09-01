class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        stack<int> temp_index;
        vector<int> result(temperatures.size());

        int index = 0;
        for(int temp : temperatures) {

            if(!temp_index.empty()) {
                int top = temp_index.top();
                while(temperatures[top] < temp) {

                    result[top] = index - top;

                    temp_index.pop();
                    if(temp_index.empty()) break;
                    top = temp_index.top();
                }
            }

            temp_index.push(index);
            ++index;
        }

        return result;
    }
};
