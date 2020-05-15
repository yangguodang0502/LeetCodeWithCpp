#  寻找比目标字母大的最小字母
## 题目
Given a list of sorted characters letters containing only lowercase letters, and given a target letter target, find the smallest element in the list that is larger than the given target.

Letters also wrap around. For example, if the target is target = 'z' and letters = ['a', 'b'], the answer is 'a'.

Examples:
Input:
letters = ["c", "f", "j"]
target = "a"
Output: "c"

Input:
letters = ["c", "f", "j"]
target = "c"
Output: "f"

Input:
letters = ["c", "f", "j"]
target = "d"
Output: "f"

Input:
letters = ["c", "f", "j"]
target = "g"
Output: "j"

Input:
letters = ["c", "f", "j"]
target = "j"
Output: "c"

Input:
letters = ["c", "f", "j"]
target = "k"
Output: "c"
Note:
letters has a length in range [2, 10000].
letters consists of lowercase letters, and contains at least 2 unique letters.
target is a lowercase letter.

## 题解
### 算法分析
1. 初始条件：left = 02,right = letters.size() - 1,mid = left + (right - left) / 2
2. 终止条件：left == right => rerturn letters[0]
            letters[mid] > target and letters[mid - 1] <= target => return letters[mid]
            letters[mid] <= target and letters[mid + 1] > target => return letters[mid + 1]
3. 向左查找：right = mid - 1
4. 向右查找：left = mid + 1
### 复杂度分析
+ 时间复杂度：O(logn)
+ 空间复杂度：O(1)
### 源码
```C++ []
class Solution {
public:
    char nextGreatestLetter(vector<char>& letters, char target) {
        int left = 0;
        int right = letters.size() - 1;

        while (left < right)
        {
            int mid = left + (right - left) / 2;
            if (letters[mid] > target)
            {
                if (mid >= 1 && letters[mid - 1] > target)
                {
                    right = mid - 1;
                }
                else
                {
                    return letters[mid];
                }                
            }
            else
            {
                if (mid <= letters.size() - 2 && letters[mid + 1] > target)
                {
                    return letters[mid + 1];
                }
                else
                {
                    left = mid + 1;
                }   
            }            
        }

        return letters[0];
    }
};