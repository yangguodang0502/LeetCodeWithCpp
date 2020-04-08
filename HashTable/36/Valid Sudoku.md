#  有效的数独
## 题目
Determine if a 9x9 Sudoku board is valid. Only the filled cells need to be validated according to the following rules:

Each row must contain the digits 1-9 without repetition.
Each column must contain the digits 1-9 without repetition.
Each of the 9 3x3 sub-boxes of the grid must contain the digits 1-9 without repetition.

![](https://upload.wikimedia.org/wikipedia/commons/thumb/f/ff/Sudoku-by-L2G-20050714.svg/250px-Sudoku-by-L2G-20050714.svg.png)

A partially filled sudoku which is valid.

The Sudoku board could be partially filled, where empty cells are filled with the character '.'.

Example 1:

Input:
[
  ["5","3",".",".","7",".",".",".","."],
  ["6",".",".","1","9","5",".",".","."],
  [".","9","8",".",".",".",".","6","."],
  ["8",".",".",".","6",".",".",".","3"],
  ["4",".",".","8",".","3",".",".","1"],
  ["7",".",".",".","2",".",".",".","6"],
  [".","6",".",".",".",".","2","8","."],
  [".",".",".","4","1","9",".",".","5"],
  [".",".",".",".","8",".",".","7","9"]
]
Output: true
Example 2:

Input:
[
  ["8","3",".",".","7",".",".",".","."],
  ["6",".",".","1","9","5",".",".","."],
  [".","9","8",".",".",".",".","6","."],
  ["8",".",".",".","6",".",".",".","3"],
  ["4",".",".","8",".","3",".",".","1"],
  ["7",".",".",".","2",".",".",".","6"],
  [".","6",".",".",".",".","2","8","."],
  [".",".",".","4","1","9",".",".","5"],
  [".",".",".",".","8",".",".","7","9"]
]
Output: false
Explanation: Same as Example 1, except with the 5 in the top left corner being 
    modified to 8. Since there are two 8's in the top left 3x3 sub-box, it is invalid.
Note:

A Sudoku board (partially filled) could be valid but is not necessarily solvable.
Only the filled cells need to be validated according to the mentioned rules.
The given board contain only digits 1-9 and the character '.'.
The given board size is always 9x9.

## 题解
### 算法分析
1. 定义哈希表数组<int, int>[9] rows、cols、boxes
2. rows用于存储每行对应的哈希表，其中哈希表存储字符对应的计数，
   cols用于存储每列对应的哈希表，boxes用于存储每个3x3区间对应的哈希表
3. 按行和列遍历矩阵，填充上述哈希表数组
4. 如果字符已存在其中任意一个哈希表中，返回false
5. 遍历结束返回true
### 复杂度分析
+ 时间复杂度：O(n^2)，n为矩阵行数
+ 空间复杂度：O(n^2*3)，哈希表占用额外空间
### 源码
```C++ []
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