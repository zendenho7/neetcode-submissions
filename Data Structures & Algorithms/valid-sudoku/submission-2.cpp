class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        array<unordered_set<int>, 9> row_set;
        array<unordered_set<int>, 9> col_set;
        array<unordered_set<int>, 9> sub_set;

        for(int i = 0; i < board.size(); ++i){ 
            for(int j = 0; j < board[i].size(); ++j) {

                string character = {board[i][j]};
                if(character == ".") continue;

                //Extract integer value from board
                int val = stoi(character);

                //Ensure val is within range
                if(val < 1 || val > 9) return false;

                //Column check
                if(col_set[i].find(val) != col_set[i].end()) return false;
                else {
                    col_set[i].insert(val);
                }

                //Row Check
                if(row_set[j].find(val) != row_set[j].end()) return false;
                else {
                    row_set[j].insert(val);
                }

                //Sub set check
                int sub_index = static_cast<int>(i/3) * 3 + static_cast<int>(j/3);
                if(sub_set[sub_index].find(val) != sub_set[sub_index].end()) return false;
                else {
                    sub_set[sub_index].insert(val);
                }
            }
        }

        return true;
    }
};
