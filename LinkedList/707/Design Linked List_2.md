# 设计链表
## 题目
Design your implementation of the linked list. You can choose to use the singly linked list or the doubly linked list. A node in a singly linked list should have two attributes: val and next. val is the value of the current node, and next is a pointer/reference to the next node. If you want to use the doubly linked list, you will need one more attribute prev to indicate the previous node in the linked list. Assume all nodes in the linked list are 0-indexed.

Implement these functions in your linked list class:

get(index) : Get the value of the index-th node in the linked list. If the index is invalid, return -1.
addAtHead(val) : Add a node of value val before the first element of the linked list. After the insertion, the new node will be the first node of the linked list.
addAtTail(val) : Append a node of value val to the last element of the linked list.
addAtIndex(index, val) : Add a node of value val before the index-th node in the linked list. If index equals to the length of linked list, the node will be appended to the end of linked list. If index is greater than the length, the node will not be inserted.
deleteAtIndex(index) : Delete the index-th node in the linked list, if the index is valid.
 

Example:

Input: 
["MyLinkedList","addAtHead","addAtTail","addAtIndex","get","deleteAtIndex","get"]
[[],[1],[3],[1,2],[1],[1],[1]]
Output:  
[null,null,null,null,2,null,3]

Explanation:
MyLinkedList linkedList = new MyLinkedList(); // Initialize empty LinkedList
linkedList.addAtHead(1);
linkedList.addAtTail(3);
linkedList.addAtIndex(1, 2);  // linked list becomes 1->2->3
linkedList.get(1);            // returns 2
linkedList.deleteAtIndex(1);  // now the linked list is 1->3
linkedList.get(1);            // returns 3
 

Constraints:

0 <= index,val <= 1000
Please do not use the built-in LinkedList library.
At most 2000 calls will be made to get, addAtHead, addAtTail,  addAtIndex and deleteAtIndex.

## 题解
### 算法分析
1. 使用双链表节点，使用length记录链表长度，使用head哨兵节点作为头节点的前置节点，使用tail哨兵作为尾节点的后置节点
2. 添加节点的时候++length，移除节点的时候--length
### 复杂度分析
+ 时间复杂度
1. get(index)：O(index/2)
2. addAtHead(val)：O(1)
3. addAtTail(val)：O(1)
4. addAtIndex(index, val)：O(index/2)
5. deleteAtIndex(index)：O(index/2)
+ 空间复杂度：都是O(1)
### 源码
```C++ []
struct DoubleNode
{
    int val;
    DoubleNode* pre;
    DoubleNode* next;
    DoubleNode(int x) : val(x), pre(NULL), next(NULL) {}
};

class MyLinkedList {
public:
    /** Initialize your data structure here. */
    MyLinkedList() {
        mHead = new DoubleNode(-1);
        mTail = new DoubleNode(-1);
        mLenth = 0;

        mHead->next = mTail;
        mTail->pre = mHead;
    }
    
    /** Get the value of the index-th node in the linked list. If the index is invalid, return -1. */
    int get(int index) {
        if (index < 0 || index >= mLenth)
            return -1;

        DoubleNode* node;
        if (index + 1 < mLenth - index)
        {
            node = mHead;
            for (int i = 0; i < index + 1; i++)
            {
                node = node->next;
            }   
        }
        else
        {
            node = mTail;
            for (int i = 0; i < mLenth - index; i++)
            {
                node = node->pre;
            }
        }        

        return node->val;
    }
    
    /** Add a node of value val before the first element of the linked list. After the insertion, the new node will be the first node of the linked list. */
    void addAtHead(int val) {
        DoubleNode* node = new DoubleNode(val);
        DoubleNode* preNode = mHead;
        DoubleNode* nextNode = preNode->next;

        node->pre = preNode;
        node->next = nextNode;
        preNode->next = node;
        nextNode->pre = node;

        ++mLenth;
    }
    
    /** Append a node of value val to the last element of the linked list. */
    void addAtTail(int val) {
        DoubleNode* node = new DoubleNode(val);
        DoubleNode* nextNode = mTail;
        DoubleNode* preNode = nextNode->pre;

        node->pre = preNode;
        node->next = nextNode;
        preNode->next = node;
        nextNode->pre = node;

        ++mLenth;
    }
    
    /** Add a node of value val before the index-th node in the linked list. If index equals to the length of linked list, the node will be appended to the end of linked list. If index is greater than the length, the node will not be inserted. */
    void addAtIndex(int index, int val) {
        if (index > mLenth)
            return;
            
        if (index < 0)
            index = 0;
        
        DoubleNode* preNode;
        DoubleNode* nextNode;
        if (index < mLenth - index)
        {
            preNode = mHead;
            for (int i = 0; i < index; i++)
            {
                preNode = preNode->next;
            }   
            nextNode = preNode->next;
        }
        else
        {
            nextNode = mTail;
            for (int i = 0; i < mLenth - index; i++)
            {
                nextNode = nextNode->pre;
            }
            preNode = nextNode->pre;
        }     

        DoubleNode* node = new DoubleNode(val);
        preNode->next = node;
        node->pre = preNode;
        node->next = nextNode;
        nextNode->pre = node;

        ++mLenth;
    }
    
    /** Delete the index-th node in the linked list, if the index is valid. */
    void deleteAtIndex(int index) {
        if (index < 0 || index >= mLenth)
            return;

        DoubleNode* preNode;
        DoubleNode* nextNode;
        if (index < mLenth - index)
        {
            preNode = mHead;
            for (int i = 0; i < index; i++)
            {
                preNode = preNode->next;
            }   
            nextNode = preNode->next->next;
        }
        else
        {
            nextNode = mTail;
            for (int i = 0; i < mLenth - index - 1; i++)
            {
                nextNode = nextNode->pre;
            }
            preNode = nextNode->pre->pre;
        }     

        preNode->next = nextNode;
        nextNode->pre = preNode;

        --mLenth;
    }

private:
    DoubleNode* mHead;
    DoubleNode* mTail;
    int mLenth;
};

/**
 * Your MyLinkedList object will be instantiated and called as such:
 * MyLinkedList* obj = new MyLinkedList();
 * int param_1 = obj->get(index);
 * obj->addAtHead(val);
 * obj->addAtTail(val);
 * obj->addAtIndex(index,val);
 * obj->deleteAtIndex(index);
 */