#include <string>
#include <queue>
#include <vector>
#include <regex>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Codec {
public:
    const string SEP = ",";
    const string NULLSTR = "#";

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        string ret;
        if (root == nullptr) {
            return ret;
        }
        queue<TreeNode*> nodes;
        nodes.push(root);
        while (!nodes.empty())
        {
            TreeNode* node = nodes.front();
            nodes.pop();
            if (node == nullptr) {
                ret += NULLSTR;
                ret += SEP;
                continue;
            }
            ret += to_string(node->val);
            ret += SEP;
            nodes.push(node->left);
            nodes.push(node->right);
        }        
        return ret;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        if (data.empty()) {
            return nullptr;
        }
        vector<string> strNodes = split(data, SEP);
        int i = 0;
        TreeNode* root = new TreeNode(stoi(strNodes[i++]));
        queue<TreeNode*> nodes;
        nodes.push(root);
        while (i < strNodes.size())
        {
            TreeNode* node = nodes.front();
            nodes.pop();
            string str = strNodes[i++];
            if (str != NULLSTR) {
                node->left = new TreeNode(stoi(str));
                nodes.push(node->left);
            } else {
                node->left = nullptr;
            }
            str = strNodes[i++];
            if (str != NULLSTR) {
                node->right = new TreeNode(stoi(str));
                nodes.push(node->right);
            } else {
                node->right = nullptr;
            }
        }
        return root;
    }

    vector<string> split(const string& in, const string& delim) {
        regex re {delim};
        return vector<string> {
            sregex_token_iterator(in.begin(), in.end(), re, -1),
            sregex_token_iterator()
        };
    }
};