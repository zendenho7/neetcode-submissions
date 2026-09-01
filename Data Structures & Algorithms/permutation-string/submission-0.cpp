class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        
        //identify size of window
        int size = s1.size();

        //Fixed sliding window
        for(int i = 0, j = i + size - 1; j < s2.size(); ++i, ++j) {

            unordered_map<char, int> counts;

            for(int k = 0; k < s1.size(); ++k) {
                ++counts[s1[k]];
            }

            for(int k = i; k <= j; ++k) {
                if(!counts.contains(s2[k])) continue;
                if(--counts[s2[k]] == 0) counts.erase(s2[k]);
            }

            if(counts.empty()) return true;
        }

        return false;
    }
};
