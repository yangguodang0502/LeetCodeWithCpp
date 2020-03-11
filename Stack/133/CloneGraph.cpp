#include <vector>
#include <map>

using namespace std;

// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};

class Solution {
public:
    Node* cloneGraph(Node* node) {
        map<Node*, Node*> visited;

        return cloneRecursive(node, visited);
    }

    Node* cloneRecursive(Node* node, map<Node*, Node*>& visited)
    {
        if (node == NULL)
            return NULL;

        map<Node*, Node*>::iterator iter = visited.find(node);
        if (iter != visited.end())
            return iter->second;

        Node* cloneNode = new Node(node->val);
        visited.insert(pair<Node*, Node*>(node, cloneNode));

        for (int i = 0; i < node->neighbors.size(); i++)
        {
            Node* neighborNode = node->neighbors[i];
            cloneNode->neighbors.push_back(cloneRecursive(neighborNode, visited));
        }

        return cloneNode;
    }
};