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

            //Calculate new window & max element after expanding right
            maxElement = occurence[maxElement] > ++occurence[s[right]] ? maxElement : s[right];
            int win_length = right - left + 1;

            while(win_length - occurence[maxElement] > k && left < right) {

                //reduce previous left element
                --occurence[s[left]];

                //increment left index
                ++left;

                //find max element from left or right
                maxElement = occurence[maxElement] > occurence[s[left]] ? maxElement : s[left];
                maxElement = occurence[maxElement] > occurence[s[right]] ? maxElement : s[right];

                //Update new window length
                win_length = right - left + 1;
            }
            
            
            maxLength = max(maxLength, win_length);
        }

        return maxLength;
    }
};
