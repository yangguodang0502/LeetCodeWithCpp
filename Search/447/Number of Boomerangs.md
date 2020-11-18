# 四数之和
## 题目
Given n points in the plane that are all pairwise distinct, a "boomerang" is a tuple of points (i, j, k) such that the distance between i and j equals the distance between i and k (the order of the tuple matters).

Find the number of boomerangs. You may assume that n will be at most 500 and coordinates of points are all in the range [-10000, 10000] (inclusive).

Example:

Input:
[[0,0],[1,0],[2,0]]

Output:
2

Explanation:
The two boomerangs are [[1,0],[0,0],[2,0]] and [[1,0],[2,0],[0,0]]

## 题解
### 算法分析
1. 定义ret用于记录结果
2. 遍历所有点，使用哈希表记录每两个点距离对应的个数
3. 遍历哈希表，如果个数n大于等于2则ret+=n*(n-1)
4. 返回ret
### 复杂度分析
+ 时间复杂度：O(n^2)
+ 空间复杂度：O(m)，m为不同距离的个数
### 源码
```C++ []
class Solution {
public:
    int distance(vector<int>& l, vector<int>& r) {
        return (l[0] - r[0]) * (l[0] - r[0]) + (l[1] - r[1]) * (l[1] - r[1]);
    }

    int numberOfBoomerangs(vector<vector<int>>& points) {
        int ret = 0;
        for (int i = 0; i < points.size(); i++)
        {
            unordered_map<int, int> hashMap;
            for (int j = 0; j < points.size(); j++)
            {
                if (j == i)
                    continue;
                int dist = distance(points[i], points[j]);
                hashMap[dist]++;
            }
            for (auto &&kv : hashMap)
            {
                int n = kv.second;
                if (n >= 2)
                {
                    ret += n*(n-1);
                }
            }            
        }
        return ret;
    }
};