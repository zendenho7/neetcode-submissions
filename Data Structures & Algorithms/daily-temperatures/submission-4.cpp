class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        vector<int> result(temperatures.size());
        stack<int> stack_index;

        for(int i = 0; i < temperatures.size(); ++i) {

            if(stack_index.empty()) stack_index.push(i);
            else {
                while(!stack_index.empty()) {
                    int index = stack_index.top();
                    if(temperatures[index] >= temperatures[i]) break;
                    stack_index.pop();
                    result[index] = i - index;
                }
                stack_index.push(i);
            }
        }

        return result;
    }
};
