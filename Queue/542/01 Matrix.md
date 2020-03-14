# 01 ����
## ��Ŀ
Given a matrix consists of 0 and 1, find the distance of the nearest 0 for each cell.

The distance between two adjacent cells is 1.

 

Example 1:

Input:
[[0,0,0],
 [0,1,0],
 [0,0,0]]

Output:
[[0,0,0],
 [0,1,0],
 [0,0,0]]
Example 2:

Input:
[[0,0,0],
 [0,1,0],
 [1,1,1]]

Output:
[[0,0,0],
 [0,1,0],
 [1,2,1]]
 

Note:

The number of elements of the given matrix will not exceed 10,000.
There are at least one 0 in the given matrix.
The cells are adjacent in only four directions: up, down, left and right.

## ���
### �㷨����
1. ʹ�ù�������������������que���ڴ洢�������Ľڵ�<i,j>�������ά����result���ڴ洢�������ʼ��Ϊ0
2. ����matrix��i = 0 : matrix.size()-1, j = 0 : matrix[i].size()-1
3. ���matrix[i][j]==0����<i,j>���
4. ����result[i][j]��ֵΪIntMax
5. ��������ֱ��Ϊ�գ����Ӷ���Ԫ��<i,j>
6. ����<i,j>������Ԫ��<next_i,next_j>�����result<new_i,next_j> > result<i,j> + 1
   ����result<next_i,next_j> =  result<i,j> + 1������<next_i,next_>���
7. ��󷵻�result
### ���Ӷȷ���
+ ʱ�临�Ӷȣ�O(n), n=i*j
+ �ռ临�Ӷȣ�O(n)������ʹ�õĿռ�
### Դ��
```C++ []
class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& matrix) {
        int rowCount = matrix.size();
        if (rowCount == 0)
            return matrix;

        int colCount = matrix[0].size();        
        vector<vector<int>> result(rowCount, vector<int>(colCount, 0));
        queue<pair<int,int>> que;

        for (int i = 0; i < rowCount; i++)
        {
            for (int j = 0; j < colCount; j++)
            {
                if (matrix[i][j] == 0)
                {
                    que.push(make_pair(i, j));
                }
                else
                {
                    result[i][j] = INT_MAX;
                }
            }            
        }

        int diff[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
        
        while (!que.empty())
        {
            pair<int,int> pos = que.front();
            int i = pos.first;
            int j = pos.second;
            que.pop();

            for (int index = 0; index < 4; index++)
            {
                int diff_i = diff[index][0];
                int diff_j = diff[index][1];
                int new_i = i + diff_i;
                int new_j = j + diff_j;

                if (new_i >= 0 && new_i < rowCount && new_j >= 0 && new_j < colCount
                    && result[new_i][new_j] > result[i][j] + 1)
                {
                    result[new_i][new_j] = result[i][j] + 1;
                    que.push(make_pair(new_i, new_j));
                }
            }
        }   

        return result;     
    }
};