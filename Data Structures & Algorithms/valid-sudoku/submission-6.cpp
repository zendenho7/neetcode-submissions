class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        array<unordered_set<char>, 9> row_set;
        array<unordered_set<char>, 9> col_set;
        array<unordered_set<char>, 9> sub_set;

        for(int i = 0; i < board.size(); ++i){ 
            for(int j = 0; j < board[i].size(); ++j) {

                //Get character
                char character = board[i][j];
                if(character == '.') continue;

                //Get sub index
                int sub_index = (i/3) * 3 + (j/3);

                //Col, row & sub checks
                if(col_set[i].contains(character) || row_set[j].contains(character) || sub_set[sub_index].contains(character)) return false;
                else {
                    col_set[i].insert(character);
                    row_set[j].insert(character);
                    sub_set[sub_index].insert(character);
                }
            }
        }

        return true;
    }
};
