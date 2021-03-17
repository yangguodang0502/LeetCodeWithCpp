# Find Duplicate Subtrees
## 题目
Given the root of a binary tree, return all duplicate subtrees.

For each kind of duplicate subtrees, you only need to return the root node of any one of them.

Two trees are duplicate if they have the same structure with the same node values. 

Example 1:

![](https://assets.leetcode.com/uploads/2020/08/16/e1.jpg)


Input: root = [1,2,3,4,null,2,4,null,null,4]
Output: [[2,4],[4]]

Example 2:

![](https://assets.leetcode.com/uploads/2020/08/16/e2.jpg)

Input: root = [2,1,1]
Output: [[1]]

Example 3:

![](https://assets.leetcode.com/uploads/2020/08/16/e3.jpg)

Input: root = [2,2,2,3,null,3,null]
Output: [[2,3],[3]]
 

Constraints:

The number of the nodes in the tree will be in the range [1, 10^4]
-200 <= Node.val <= 200

## 题解
### 算法分析
1. 使用后序遍历
2. 序列化每个子树：str = left,right,root.val，空节点用#表示
3. 使用map<str, count>记录子树出现的次数
4. 如果map是否存在次数为1，将节点加入结果数组
5. 返回结果数组
+ 时间复杂度：O(n)
+ 空间复杂度：O(n)
### 源码
```C++ []
class Solution {
public:
    vector<TreeNode*> findDuplicateSubtrees(TreeNode* root) {
        vector<TreeNode*> res;
        unordered_map<string, int> trees;
        traverseTree(root, trees, res);
        return res;
    }

    string traverseTree(TreeNode* root, unordered_map<string, int>& trees, vector<TreeNode*>& res) {
        if (root == nullptr) {
            return "#";
        }

        string left = traverseTree(root->left, trees, res);
        string right = traverseTree(root->right, trees, res);
        string str = left + "," + right + ',' + to_string(root->val);

        if (trees[str] == 1) {
            res.push_back(root);
        }
        trees[str]++;

        return str;
    }
};