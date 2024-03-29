#define NULL nullptr

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