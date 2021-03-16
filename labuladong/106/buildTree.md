# Construct Binary Tree from Inorder and Postorder Traversal
## 题目
Given two integer arrays preorder and inorder where preorder is the preorder traversal of a binary tree and inorder is the inorder traversal of the same tree, construct and return the binary tree.

 

Example 1:

![](https://assets.leetcode.com/uploads/2021/02/19/tree.jpg)


Input: inorder = [9,3,15,20,7], postorder = [9,15,7,20,3]
Output: [3,9,20,null,null,15,7]

Example 2:

Input: preorder = [-1], inorder = [-1]
Output: [-1]
 

Constraints:

1 <= preorder.length <= 3000
inorder.length == preorder.length
-3000 <= preorder[i], inorder[i] <= 3000
preorder and inorder consist of unique values.
Each value of inorder also appears in preorder.
preorder is guaranteed to be the preorder traversal of the tree.
inorder is guaranteed to be the inorder traversal of the tree.

## 题解
### 算法分析
1. build(inorder, inStart, inEnd, postorder, postStart, postEnd)
2. val = postorder[postEnd]
   index = indexOfVal(inorder, inStart, inEnd, val)
   leftSize = index - inStart
3. root = new TreeNode(val)
4. root.left = build(inorder, inStart, index-1, postorder, postStart, postStart + leftSize)
5. root.right = build(inorder, index+1, inEnd, postorder, postStart + leftSize + 1, postEnd - 1)
6. return root
+ 时间复杂度：O(n)
+ 空间复杂度：O(n)
### 源码
```C++ []
class Solution {
public:
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        return build(inorder, 0, inorder.size() - 1, postorder, 0, postorder.size() - 1);
    }

    TreeNode* build(vector<int>& inorder, int inStart, int inEnd
        , vector<int>& postorder, int postStart, int postEnd) {
            if (inStart > inEnd) {
                return nullptr;
            }

            int val = postorder[postEnd];
            int index = 0;
            for (int i = inStart; i <= inEnd; i++) {
                if (val == inorder[i]) {
                    index = i;
                    break;
                }
            }
            int leftSize = index - inStart;
            
            TreeNode* root = new TreeNode(val);
            root->left = build(inorder, inStart, index-1, postorder, postStart, postStart+leftSize-1);
            root->right = build(inorder, index+1, inEnd, postorder, postStart+leftSize, postEnd-1);

            return root;
    }
};