# 从中序与后序遍历序列构造二叉树
## 题目
Given inorder and postorder traversal of a tree, construct the binary tree.

Note:
You may assume that duplicates do not exist in the tree.

For example, given

inorder = [9,3,15,20,7]
postorder = [9,15,7,20,3]
Return the following binary tree:

    3
   / \
  9  20
    /  \
   15   7

## 题解
### 算法分析
1. 定义后序数组的根节点下标，初始化为最末位置
2. 遍历中序数组，构造map用于查找val对应的中序数组下标
3. 定义递归函数，用于递归构造树，根据当前根节点位置将中序数组分为左右子区间
4. 调用递归函数，传入参数leftIndex = 0, rightIndex = postorder.size() - 1
5. 如果leftIndex > rightIndex返回NULL
6. 获取根节点的值val，创建根节点并赋值val
7. 根节点下标前移一个位置
8. 获取val对应的中序数组位置index
9. 调用递归函数，构造root的右节点，传入参数leftIndex = index + 1, rightIndex
10. 调用递归函数，构造root的左节点，传入参数leftIndex, rightIndex = index - 1
11. 最后返回根节点
### 复杂度分析
+ 时间复杂度：O(n), n为树节点个数
+ 空间复杂度：O(n)，递归调用栈和map占用额外空间
### 源码
```C++ []
class Solution {
public:
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        int postRootIndex = postorder.size() - 1;

        map<int, int> inorderMap;
        int index = 0;
        for (auto &&val : inorder)
        {
            inorderMap.insert(make_pair(val, index++));
        }
        
        return buildTreeRecursive(0, postorder.size() - 1, postRootIndex, postorder, inorderMap);
    }

    TreeNode* buildTreeRecursive(int leftIndex, int rightIndex
        , int& postorderIndex, vector<int>& postorder, map<int, int>& inorderMap) {
            if (leftIndex > rightIndex)
                return NULL;

            int val = postorder[postorderIndex];
            TreeNode* root = new TreeNode(val);

            --postorderIndex;
            int index = inorderMap[val];
            root->right = buildTreeRecursive(index + 1, rightIndex, postorderIndex, postorder, inorderMap);
            root->left = buildTreeRecursive(leftIndex, index - 1, postorderIndex, postorder, inorderMap);

            return root;
    }
};