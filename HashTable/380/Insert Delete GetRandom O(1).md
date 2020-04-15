#  常数时间插入、删除和获取随机元素
## 题目
Design a data structure that supports all following operations in average O(1) time.

insert(val): Inserts an item val to the set if not already present.
remove(val): Removes an item val from the set if present.
getRandom: Returns a random element from current set of elements. Each element must have the same probability of being returned.
Example:

// Init an empty set.
RandomizedSet randomSet = new RandomizedSet();

// Inserts 1 to the set. Returns true as 1 was inserted successfully.
randomSet.insert(1);

// Returns false as 2 does not exist in the set.
randomSet.remove(2);

// Inserts 2 to the set, returns true. Set now contains [1,2].
randomSet.insert(2);

// getRandom should return either 1 or 2 randomly.
randomSet.getRandom();

// Removes 1 from the set, returns true. Set now contains [2].
randomSet.remove(1);

// 2 was already in the set, so return false.
randomSet.insert(2);

// Since 2 is the only number in the set, getRandom always return 2.
randomSet.getRandom();

## 题解
### 算法分析
1. 使用动态数组存储元素，实现O(1)的插入和获取随机元素
2. 使用哈希表存储元素对应的下标，实现O(1)的删除
3. 获取待删除元素的下标将数组末尾元素替换到该位置，并更新哈希表该元素对应的下标
4. 删除数组末尾元素，删除待删除元素对应的哈希表值
### 复杂度分析
+ 时间复杂度：O(1)
+ 空间复杂度：O(n)，n为数组个数，哈希表和动态数组占用空间
### 源码
```C++ []
class RandomizedSet {
public:
    /** Initialize your data structure here. */
    RandomizedSet() {

    }
    
    /** Inserts a value to the set. Returns true if the set did not already contain the specified element. */
    bool insert(int val) {
        if (mHashMap.count(val))
            return false;
            
        mVector.push_back(val);
        mHashMap[val] = mVector.size() - 1;
        return true;
    }
    
    /** Removes a value from the set. Returns true if the set contained the specified element. */
    bool remove(int val) {
        if (mHashMap.count(val))
        {
            int index = mHashMap[val];
            int endIndex = mVector.size() - 1;

            if (index != endIndex)
            {
                mVector[index] = mVector[endIndex];
                mHashMap[mVector[index]] = index;
            }

            mVector.pop_back();
            mHashMap.erase(val);

            return true;
        }

        return false;
    }
    
    /** Get a random element from the set. */
    int getRandom() {
        int index = rand() % mVector.size();
        return mVector[index];
    }

private:
    vector<int> mVector;
    unordered_map<int, int> mHashMap;
};