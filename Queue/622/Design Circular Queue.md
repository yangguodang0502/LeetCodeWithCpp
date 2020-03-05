# ��ת����
## ��Ŀ
Design your implementation of the circular queue. The circular queue is a linear data structure in which the operations are performed based on FIFO (First In First Out) principle and the last position is connected back to the first position to make a circle. It is also called "Ring Buffer".

One of the benefits of the circular queue is that we can make use of the spaces in front of the queue. In a normal queue, once the queue becomes full, we cannot insert the next element even if there is a space in front of the queue. But using the circular queue, we can use the space to store new values.

Your implementation should support following operations:

MyCircularQueue(k): Constructor, set the size of the queue to be k.
Front: Get the front item from the queue. If the queue is empty, return -1.
Rear: Get the last item from the queue. If the queue is empty, return -1.
enQueue(value): Insert an element into the circular queue. Return true if the operation is successful.
deQueue(): Delete an element from the circular queue. Return true if the operation is successful.
isEmpty(): Checks whether the circular queue is empty or not.
isFull(): Checks whether the circular queue is full or not.
 

Example:

MyCircularQueue circularQueue = new MyCircularQueue(3); // set the size to be 3
circularQueue.enQueue(1);  // return true
circularQueue.enQueue(2);  // return true
circularQueue.enQueue(3);  // return true
circularQueue.enQueue(4);  // return false, the queue is full
circularQueue.Rear();  // return 3
circularQueue.isFull();  // return true
circularQueue.deQueue();  // return true
circularQueue.enQueue(4);  // return true
circularQueue.Rear();  // return 4
 
Note:

All values will be in the range of [0, 1000].
The number of operations will be in the range of [1, 1000].
Please do not use the built-in Queue library.

## ���
### �㷨����
1. ʹ������洢Ԫ�أ�����size��ʾ�����С��head��ʾ��ͷ�±꣬tail��ʾ��β�±�
2. ��ʼʱhead = tail = -1
3. ��head==-1ʱ����Ϊ��
4. ��(tail + 1) % size == headʱ����Ϊ��
5. ȡ����Ԫ�أ�data[head]��ȡ��βԪ�أ�data[tail]
6. ��ӣ��ж��Ƿ�����tail = (tail + 1) % size��data[tail]=val�����head==-1��head=0
7. ���ӣ��ж��Ƿ�ǿգ����head==tail��head=tail=-1������head = (head + 1) % size
### ���Ӷȷ���
+ ʱ�临�Ӷȣ�O(1)
+ �ռ临�Ӷȣ�O(1)
### Դ��
```C++ []
class MyCircularQueue {
public:
    /** Initialize your data structure here. Set the size of the queue to be k. */
    MyCircularQueue(int k) {
        data.resize(k);
        size = k;
        head = tail = -1;
    }
    
    /** Insert an element into the circular queue. Return true if the operation is successful. */
    bool enQueue(int value) {
        if (isFull())
            return false;

        tail = (tail + 1) % size;
        data[tail] = value;

        if (head == -1)
            head = 0;
        
        return true;
    }
    
    /** Delete an element from the circular queue. Return true if the operation is successful. */
    bool deQueue() {
        if (isEmpty())
            return false;
        
        if (head == tail)
        {
            head = tail = -1;
        }
        else
        {
            head = (head + 1) % size;
        }      

        return true;  
    }
    
    /** Get the front item from the queue. */
    int Front() {
        if (isEmpty())
            return -1;

        return data[head];
    }
    
    /** Get the last item from the queue. */
    int Rear() {
        if (isEmpty())
            return -1;

        return data[tail];
    }
    
    /** Checks whether the circular queue is empty or not. */
    bool isEmpty() {
        return head == -1;
    }
    
    /** Checks whether the circular queue is full or not. */
    bool isFull() {
        return (tail + 1) % size == head;
    }
private:
    vector<int> data;
    int size;
    int head;
    int tail;
};