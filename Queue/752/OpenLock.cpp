#include <vector>
#include <string>
#include <set>
#include <queue>

using namespace std;

class Solution {
public:
    int openLock(vector<string>& deadends, string target) {
        set<string> ends;
        for (auto end : deadends)
        {
            ends.insert(end);
        }       

        string startNode = "0000";
        if (ends.find(startNode) != ends.end())
            return -1;

        set<string> visited;
        int num = 0;

        queue<string> queue;
        queue.push(startNode);
        queue.push("");

        while (!queue.empty())
        {
            string node = queue.front();
            queue.pop();
            
            if (node == "")
            {
                ++num; 

                if (!queue.empty())
                    queue.push("");
            }
            else if (node == target)
            {
                return num;
            }
            else if (ends.find(node) == ends.end())
            {
                for (int i = 0; i < 4; i++)
                {
                    for (int j = -1; j <= 1; j += 2)
                    {
                        int val = ((node.at(i) - '0') + j + 10) % 10;
                        string str = node;
                        str[i] = '0' + val;

                        if (visited.find(str) == visited.end())
                        {
                            visited.insert(str);
                            queue.push(str);
                        }
                    }
                }               
            }            
        }
        
        return -1;
    }
};