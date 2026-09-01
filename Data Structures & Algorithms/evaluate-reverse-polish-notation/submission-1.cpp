class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> numbers;
        int answer = 0;
        for(auto const& token : tokens) {
            if(token == "+" || token == "-" || token == "*" || token == "/") {
                //extract top 2 from stack
                if(numbers.size() < 2) return 0;
                int first = numbers.top();
                numbers.pop();
                int second = numbers.top();
                numbers.pop();

                //Perform arithmetic and push
                if(token == "+") {
                    answer = second + first;
                }
                else if(token == "-") {
                    answer = second - first;
                }
                else if(token == "*") {
                    answer = second * first;
                }
                else if(token == "/") {
                    answer = second / first;
                }
                else {
                    return 0;
                }

                numbers.push(answer);
            }
            else {
                answer = stoi(token);
                numbers.push(answer);
            }
        }
        return answer;
    }
};
