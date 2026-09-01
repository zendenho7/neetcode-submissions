class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        if(s.empty()) return 0;
        unordered_map<char, int> lastSeen;

        int max_length = 0;
        int left = 0;
        int right = 0;

        for(;right < s.size();++right) {

            char new_right = s[right];

            if(lastSeen.contains(new_right) && lastSeen[new_right] >= left) {
                left = lastSeen.at(new_right) + 1;
                if(left > right) right = left;
            }

            lastSeen[new_right] = right;

            max_length = max(max_length, right - left + 1);
        }

        return max_length;
    }
};
