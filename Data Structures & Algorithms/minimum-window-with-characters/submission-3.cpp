class Solution {
public:
    string minWindow(string s, string t) {

        //Early exit condition
        if(t.size() > s.size()) return "";

        //Create s & t map
        unordered_map<char, int> t_map;
        unordered_map<char, int> s_map;
        int matched = 0;
        for(char c : t) {
            ++t_map[c];
        }
        for(int i = 0; i < t.size() - 1; ++i) {
            char c = s[i];
            if(t_map.contains(c)) {
                if(++s_map[c] == t_map[c]) ++matched;
            }
        }

        //Store index of result
        pair<int, int> result = {0, s.size() - 1};
        bool found = false;

        //Window can begin with the size of t
        //Dynamic sliding window
        for(int i = 0, j = i + t.size() - 1; j < s.size(); ++j) {

            char c = s[j];
            if(t_map.contains(c)) {
                if(++s_map[c] == t_map[c]) ++matched;
            }
            
            //Check for matched condition
            while(matched == t_map.size()) {

                //Update found flag
                found = true;

                //Compute better result
                int res_len = result.second - result.first + 1;
                int curr_len = j - i + 1;
                if(curr_len < res_len) result = {i, j};

                //Current left char
                char c = s[i++];

                //Move left forward
                if(t_map.contains(c)) {
                    if(--s_map[c] < t_map[c]) --matched;
                }
            }
        }

        return found ? s.substr(result.first, result.second - result.first + 1) : "";
    }
};
