class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        
        //identify size of window
        int size = s1.size();

        //Create s1 & s2 map
        unordered_map<char, int> s1_map;
        unordered_map<char, int> s2_map;
        for(char c = 'a'; c <= 'z'; ++c) {
            s1_map[c] = 0;
            s2_map[c] = 0;
        }
        for(char c : s1) {
            ++s1_map[c];
        }
        for(int i = 0; i < size - 1; ++i) {
            ++s2_map[s2[i]];
        }

        //Fixed sliding window
        for(int i = 0, j = i + size - 1; j < s2.size(); ++i, ++j) {

            ++s2_map[s2[j]];

            if(s1_map == s2_map) return true;

            --s2_map[s2[i]];
        }

        return false;
    }
};
