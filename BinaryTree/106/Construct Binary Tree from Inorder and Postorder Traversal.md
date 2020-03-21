# �����������������й��������
## ��Ŀ
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

## ���
### �㷨����
1. �����������ĸ��ڵ��±꣬��ʼ��Ϊ��ĩλ��
2. �����������飬����map���ڲ���val��Ӧ�����������±�
3. ����ݹ麯�������ڵݹ鹹���������ݵ�ǰ���ڵ�λ�ý����������Ϊ����������
4. ���õݹ麯�����������leftIndex = 0, rightIndex = postorder.size() - 1
5. ���leftIndex > rightIndex����NULL
6. ��ȡ���ڵ��ֵval���������ڵ㲢��ֵval
7. ���ڵ��±�ǰ��һ��λ��
8. ��ȡval��Ӧ����������λ��index
9. ���õݹ麯��������root���ҽڵ㣬�������leftIndex = index + 1, rightIndex
10. ���õݹ麯��������root����ڵ㣬�������leftIndex, rightIndex = index - 1
11. ��󷵻ظ��ڵ�
### ���Ӷȷ���
+ ʱ�临�Ӷȣ�O(n), nΪ���ڵ����
+ �ռ临�Ӷȣ�O(n)���ݹ����ջ��mapռ�ö���ռ�
### Դ��
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