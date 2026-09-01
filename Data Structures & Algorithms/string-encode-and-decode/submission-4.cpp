class Solution {
public:

    string encode(vector<string>& strs) {
        string res = "";

        for(auto const& str : strs) {
            res += (to_string(str.size()) + "#" + str);
        }

        return res;
    }

    vector<string> decode(string s) {
        vector<string> result;

        char delim = '#';

        for(size_t delim_pos = s.find(delim), start_pos = 0; delim_pos != string::npos; delim_pos = s.find(delim, start_pos)){ 

            int count = stoi(s.substr(start_pos, delim_pos - start_pos));

            result.push_back(s.substr(delim_pos + 1, count));

            start_pos = delim_pos + 1 + count;
        }

        return result;
    }
};
