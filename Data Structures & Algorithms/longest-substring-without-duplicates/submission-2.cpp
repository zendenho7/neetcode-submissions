class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        if(s.empty()) return 0;
        string sub_str = {s[0]};
        int longest_length = sub_str.size();
        for(int i = 0, j = 0; j < s.size();) {

            while(sub_str.find(s[j + 1]) != string::npos) {
                if(++i > j) j = i;
                sub_str = s.substr(i, j - i + 1);
            }

            ++j;
            sub_str = s.substr(i, j - i + 1);
            longest_length = max(longest_length, static_cast<int>(sub_str.size()));
        }

        return longest_length;
    }
};
