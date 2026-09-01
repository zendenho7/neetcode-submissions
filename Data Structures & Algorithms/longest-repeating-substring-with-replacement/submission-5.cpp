class Solution {
public:
    int characterReplacement(string s, int k) {
        if(s.empty()) return 0;
        if(s.size() == 1) return 1;
        unordered_map<char, int> occurence;

        char maxElement;
        ++occurence[s[0]];
        int maxLength = 0;
        for(int left = 0, right = 1; right < s.size(); ++right) {

            maxElement = occurence[maxElement] > ++occurence[s[right]] ? maxElement : s[right];
            int win_length = right - left + 1;

            while(win_length - occurence[maxElement] > k && left < right) {
                --occurence[s[left]];
                maxElement = occurence[maxElement] > occurence[s[++left]] ? maxElement : s[left];
                maxElement = occurence[maxElement] > occurence[s[right]] ? maxElement : s[right];
                win_length = right - left + 1;
            }
            
            
            maxLength = max(maxLength, win_length);
        }

        return maxLength;
    }
};
