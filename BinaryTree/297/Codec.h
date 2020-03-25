#include <string>
#include <queue>
#include <vector>
#include <regex>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
 
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

// Your Codec object will be instantiated and called as such:
// Codec codec;
// codec.deserialize(codec.serialize(root));