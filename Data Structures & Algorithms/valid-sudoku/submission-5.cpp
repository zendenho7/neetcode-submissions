class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        array<unordered_set<char>, 9> row_set;
        array<unordered_set<char>, 9> col_set;
        array<unordered_set<char>, 9> sub_set;

        for(int i = 0; i < board.size(); ++i){ 
            for(int j = 0; j < board[i].size(); ++j) {

                char character = board[i][j];
                if(character == '.') continue;

                //Column check
                if(col_set[i].find(character) != col_set[i].end()) return false;
                else {
                    col_set[i].insert(character);
                }

                //Row Check
                if(row_set[j].find(character) != row_set[j].end()) return false;
                else {
                    row_set[j].insert(character);
                }

                //Sub set check
                int sub_index = (i/3) * 3 + (j/3);
                if(sub_set[sub_index].find(character) != sub_set[sub_index].end()) return false;
                else {
                    sub_set[sub_index].insert(character);
                }
            }
        }

        return true;
    }
};
