# 二叉树的序列化与反序列化
## 题目
Serialization is the process of converting a data structure or object into a sequence of bits so that it can be stored in a file or memory buffer, or transmitted across a network connection link to be reconstructed later in the same or another computer environment.

Design an algorithm to serialize and deserialize a binary tree. There is no restriction on how your serialization/deserialization algorithm should work. You just need to ensure that a binary tree can be serialized to a string and this string can be deserialized to the original tree structure.

Example: 

You may serialize the following tree:

    1
   / \
  2   3
     / \
    4   5

as "[1,2,3,null,null,4,5]"
Clarification: The above format is the same as how LeetCode serializes a binary tree. You do not necessarily need to follow this format, so please be creative and come up with different approaches yourself.

Note: Do not use class member/global/static variables to store states. Your serialize and deserialize algorithms should be stateless.

## 题解
### 算法分析
1. 序列化时使用树的层次遍历，借助队列存储每层节点，遍历队列构建字符串
2. 反序列化通过分割字符串为字符串数组，借助队列存储存储每层节点并遍历该层节点
   通过数组的下标递增构造树节点
### 复杂度分析
+ 时间复杂度：O(n), n为树节点个数
+ 空间复杂度：O(n)，队列占用空间
### 源码
```C++ []
class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        string result;

        if (root == NULL)
            return result;

        queue<TreeNode*>  nodes;
        nodes.push(root);
        
        while (!nodes.empty())
        {
            TreeNode* node = nodes.front();
            nodes.pop();

            if (node != NULL)
            {
                result += to_string(node->val);
                
                nodes.push(node->left);
                nodes.push(node->right);
            }
            else
            {
                result += "#";
            }                        

            if (!nodes.empty())
                result += ',';
        }

        return result;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        if (data.empty())
            return NULL;

        vector<string> datas = split(data, ",");
        int index = 0;
        TreeNode* root = new TreeNode(stoi(datas[index++]));
        queue<TreeNode*> nodes;
        nodes.push(root);

        while (index < datas.size() && !nodes.empty())
        {
           TreeNode* node = nodes.front();
           nodes.pop();

           if (datas[index] != "#")
           {
                node->left = new TreeNode(stoi(datas[index]));
                nodes.push(node->left);
           }

            if (datas[++index] != "#")
            {
                node->right = new TreeNode(stoi(datas[index]));
                nodes.push(node->right);
            }

            ++index;
        }        

        return root;
    }

    vector<string> split(const string& in, const string& delim)
    {
        regex re {delim};
        return vector<string> {
            sregex_token_iterator(in.begin(), in.end(), re, -1),
            sregex_token_iterator()
        };
    }
};