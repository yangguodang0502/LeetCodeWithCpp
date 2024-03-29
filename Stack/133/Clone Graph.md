# 克隆图
## 题目
Given a reference of a node in a connected undirected graph.

Return a deep copy (clone) of the graph.

Each node in the graph contains a val (int) and a list (List[Node]) of its neighbors.

class Node {
    public int val;
    public List<Node> neighbors;
}
 

Test case format:

For simplicity sake, each node's value is the same as the node's index (1-indexed). For example, the first node with val = 1, the second node with val = 2, and so on. The graph is represented in the test case using an adjacency list.

Adjacency list is a collection of unordered lists used to represent a finite graph. Each list describes the set of neighbors of a node in the graph.

The given node will always be the first node with val = 1. You must return the copy of the given node as a reference to the cloned graph.

 

Example 1:
![](https://assets.leetcode.com/uploads/2019/11/04/133_clone_graph_question.png)

Input: adjList = [[2,4],[1,3],[2,4],[1,3]]
Output: [[2,4],[1,3],[2,4],[1,3]]
Explanation: There are 4 nodes in the graph.
1st node (val = 1)'s neighbors are 2nd node (val = 2) and 4th node (val = 4).
2nd node (val = 2)'s neighbors are 1st node (val = 1) and 3rd node (val = 3).
3rd node (val = 3)'s neighbors are 2nd node (val = 2) and 4th node (val = 4).
4th node (val = 4)'s neighbors are 1st node (val = 1) and 3rd node (val = 3).
Example 2:
![](https://assets.leetcode.com/uploads/2020/01/07/graph.png)

Input: adjList = [[]]
Output: [[]]
Explanation: Note that the input contains one empty list. The graph consists of only one node with val = 1 and it does not have any neighbors.
Example 3:

Input: adjList = []
Output: []
Explanation: This an empty graph, it does not have any nodes.
Example 4:
![](https://assets.leetcode.com/uploads/2020/01/07/graph-1.png)

Input: adjList = [[2],[1]]
Output: [[2],[1]]
 

Constraints:

1 <= Node.val <= 100
Node.val is unique for each node.
Number of Nodes will not exceed 100.
There is no repeated edges and no self-loops in the graph.
The Graph is connected and all nodes can be visited starting from the given node.

## 题解
### 算法分析
1. 定义一个哈希表存储克隆过的节点
2. 递归调用node节点
3. 当node为空返回空
4. 当克隆过返回node节点对应的克隆节点
5. 否则克隆node节点cloneNode，并将<node, cloneNode>插入到哈希表中
6. 遍历node节点的neighbors节点，递归调用每个neighborNode，并将返回值加入cloneNode->neighbors中
7. 最后返回cloneNode
### 复杂度分析
+ 时间复杂度：O(n)，n表示节点个数
+ 空间复杂度：O(n+h)，n是哈希表需要的空间，大小为节点个数，h是递归调用栈的空间，大小为递归深度
### 源码
```C++ []
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