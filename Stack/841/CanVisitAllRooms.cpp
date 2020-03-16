#include <vector>
#include <stack>

using namespace std;

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