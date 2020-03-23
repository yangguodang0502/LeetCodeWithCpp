# ��ǰ��������������й��������
## ��Ŀ
Given preorder and inorder traversal of a tree, construct the binary tree.

Note:
You may assume that duplicates do not exist in the tree.

For example, given

preorder = [3,9,20,15,7]
inorder = [9,3,15,20,7]
Return the following binary tree:

    3
   / \
  9  20
    /  \
   15   7

## ���
### �㷨����
1. ����ǰ������ĸ��ڵ��±꣬��ʼ��Ϊͷλ��
2. �����������飬����map���ڲ���val��Ӧ�����������±�
3. ����ݹ麯�������ڵݹ鹹���������ݵ�ǰ���ڵ�λ�ý����������Ϊ����������
4. ���õݹ麯�����������leftIndex = 0, rightIndex = postorder.size() - 1
5. ���leftIndex > rightIndex����NULL
6. ��ȡ���ڵ��ֵval���������ڵ㲢��ֵval
7. ���ڵ��±����һ��λ��
8. ��ȡval��Ӧ����������λ��index
9. ���õݹ麯��������root����ڵ㣬�������leftIndex, rightIndex = index - 1
10. ���õݹ麯��������root���ҽڵ㣬�������leftIndex = index + 1, rightIndex
11. ��󷵻ظ��ڵ�
### ���Ӷȷ���
+ ʱ�临�Ӷȣ�O(n), nΪ���ڵ����
+ �ռ临�Ӷȣ�O(n)���ݹ����ջ��mapռ�ö���ռ�
### Դ��
```C++ []
class Solution {
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int preRootIndex = 0;

        map<int, int> inorderMap;
        int index = 0;
        for (auto &&val : inorder)
        {
            inorderMap.insert(make_pair(val, index++));
        }
        
        return buildTreeRecursive(0, preorder.size() - 1, preRootIndex, preorder, inorderMap);
    }

    TreeNode* buildTreeRecursive(int leftIndex, int rightIndex
        , int& preorderIndex, vector<int>& preorder, map<int, int>& inorderMap) {
            if (leftIndex > rightIndex)
                return NULL;

            int val = preorder[preorderIndex];
            TreeNode* root = new TreeNode(val);

            ++preorderIndex;
            int index = inorderMap[val];
            root->left = buildTreeRecursive(leftIndex, index - 1, preorderIndex, preorder, inorderMap);
            root->right = buildTreeRecursive(index + 1, rightIndex, preorderIndex, preorder, inorderMap);
            
            return root;
    }
};