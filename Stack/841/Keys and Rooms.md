# 01 ����
## ��Ŀ
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

## ���
### �㷨����
1. ʹ�������������������visited[rooms.size()]���ڴ洢�����Ƿ񱻷��ʹ�������ʼ��Ϊfalse
2. ����һ����Ϊ���ʹ�visited[0]=true
3. ����ջroomStack���ڴ洢�����ʵķ�����б�����0�ŷ�����ջ
4. ����ջֱ��Ϊ�գ���ջջ��Ԫ�ط����i
5. �����÷���Ŷ�Ӧ���������Կ�ף��ж�Կ�׶�Ӧ�ķ�����Ƿ���ʹ�
6. ���δ���ʹ�����visited[i]��Ϊtrue������i��ջ
7. ������visited���飬�������δ���ʹ��򷵻�false�����򷵻�true
### ���Ӷȷ���
+ ʱ�临�Ӷȣ�O(n+m)��n��ʾ��������m��ʾԿ������
+ �ռ临�Ӷȣ�O(2n)�������ջ���õĿռ�
### Դ��
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