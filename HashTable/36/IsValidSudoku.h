#include <vector>
#include <unordered_set>

using namespace std;

class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        unordered_set<char> rows[9];
        unordered_set<char> cols[9];
        unordered_set<char> boxes[9];

        for (int i = 0; i < board.size(); i++)
        {
            for (int j = 0; j < board[i].size(); j++)
            {
                char ch = board[i][j];
                if (ch == '.')
                    continue;

                if (rows[i].count(ch))
                    return false;

                if (cols[j].count(ch))
                    return false;

                int boxIndex = (i / 3) * 3 + j / 3;
                if (boxes[boxIndex].count(ch))
                    return false;

                rows[i].insert(ch);
                cols[j].insert(ch);
                boxes[boxIndex].insert(ch);
            }            
        }
        
        return true;
    }
};