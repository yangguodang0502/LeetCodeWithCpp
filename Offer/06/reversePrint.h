#include <vector>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};
 
class Solution {
public:
    void recursiveNode(ListNode* node, vector<int>& ret) {
        if (node != NULL) {
            recursiveNode(node->next, ret);
            ret.push_back(node->val);
        }
    }

    vector<int> reversePrint(ListNode* head) {
        vector<int> ret;
        recursiveNode(head, ret);
        return ret;
    }
};