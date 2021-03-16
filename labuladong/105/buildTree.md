# Construct Binary Tree from Preorder and Inorder Traversal
## 题目
Given two integer arrays preorder and inorder where preorder is the preorder traversal of a binary tree and inorder is the inorder traversal of the same tree, construct and return the binary tree.

 

Example 1:

![](https://assets.leetcode.com/uploads/2021/02/19/tree.jpg)


Input: preorder = [3,9,20,15,7], inorder = [9,3,15,20,7]
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
1. build(preoder, preStart, preEnd, inorder, inStart, inEnd)
2. val = preoder[prestart]
   index = indexOfVal(inorder, inStart, inEnd, val)
   leftSize = index - inStart
3. root = new TreeNode(val)
4. root.left = build(preoder, preStart + 1, preStart + leftSize, inorder, inStart, index-1)
5. root.right = build(preoder, preStart + leftSize + 1, preEnd, inorder, index+1, inEnd)
6. return root
+ 时间复杂度：O(n)
+ 空间复杂度：O(n)
### 源码
```C++ []
class Solution {
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        return build(preorder, 0, preorder.size() - 1, inorder, 0, inorder.size() - 1);
    }

    TreeNode* build(vector<int>& preorder, int preStart, int preEnd
        , vector<int>& inorder, int inStart, int inEnd) {
            if (preStart > preEnd) {
                return nullptr;
            }

            int val = preorder[preStart];
            int index = 0;
            for (int i = inStart; i <= inEnd; i++) {
                if (val == inorder[i]) {
                    index = i;
                    break;
                }
            }
            int leftSize = index - inStart;
            
            TreeNode* root = new TreeNode(val);
            root->left = build(preorder, preStart+1, preStart+leftSize, inorder, inStart, index-1);
            root->right = build(preorder, preStart+leftSize+1, preEnd, inorder, index+1, inEnd);

            return root;
    }
};