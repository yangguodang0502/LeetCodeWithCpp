# 01 矩阵
## 题目
There are N rooms and you start in room 0.  Each room has a distinct number in 0, 1, 2, ..., N-1, and each room may have some keys to access the next room. 

Formally, each room i has a list of keys rooms[i], and each key rooms[i][j] is an integer in [0, 1, ..., N-1] where N = rooms.length.  A key rooms[i][j] = v opens the room with number v.

Initially, all the rooms start locked (except for room 0). 

You can walk back and forth between rooms freely.

Return true if and only if you can enter every room.

Example 1:

Input: [[1],[2],[3],[]]
Output: true
Explanation:  
We start in room 0, and pick up key 1.
We then go to room 1, and pick up key 2.
We then go to room 2, and pick up key 3.
We then go to room 3.  Since we were able to go to every room, we return true.
Example 2:

Input: [[1,3],[3,0,1],[2],[0]]
Output: false
Explanation: We can't enter the room with number 2.
Note:

1 <= rooms.length <= 1000
0 <= rooms[i].length <= 1000
The number of keys in all rooms combined is at most 3000.

## 题解
### 算法分析
1. 使用深度优先搜索，定义visited[rooms.size()]用于存储房间是否被访问过，并初始化为false
2. 将第一间设为访问过visited[0]=true
3. 定义栈roomStack用于存储待访问的房间号列表，并将0号房间入栈
4. 遍历栈直到为空，出栈栈顶元素房间号i
5. 遍历该房间号对应房间的所有钥匙，判断钥匙对应的房间号是否访问过
6. 如果未访问过，将visited[i]置为true，并将i入栈
7. 最后遍历visited数组，如果存在未访问过则返回false，否则返回true
### 复杂度分析
+ 时间复杂度：O(n+m)，n表示房间数，m表示钥匙数量
+ 空间复杂度：O(2n)，数组和栈暂用的空间
### 源码
```C++ []
class Solution {
public:
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        vector<bool> visited(rooms.size(), false);
        visited[0] = true;

        stack<int> roomStack;
        roomStack.push(0);

        while (!roomStack.empty())
        {
            int num = roomStack.top();
            roomStack.pop();

            for (auto &&i : rooms[num])
            {
                if (!visited[i])
                {
                    visited[i] = true;
                    roomStack.push(i);
                }
            }            
        }
        
        for (auto &&val : visited)
        {
            if (!val)
            {
                return false;
            }            
        }

        return true;        
    }
};