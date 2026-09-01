class Solution {
public:
    bool isValid(string s) {
        stack<char> openbrackets;

        for(char c : s) {

            //Insert open brackets
            if(c == '(' || c == '[' || c == '{') {
                openbrackets.push(c);
            }

            //Pop open brackets & close them
            if(c == ')' || c == ']' ||  c == '}') {
                if(openbrackets.empty()) return false;
                char top = openbrackets.top();
                if(c == ')' && top != '(') return false;
                else if(c == ']' && top != '[') return false;
                else if(c == '}' && top != '{') return false;
                openbrackets.pop();
            }
        }

        return openbrackets.empty();
    }
};
