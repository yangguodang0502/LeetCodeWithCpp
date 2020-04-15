#include <vector>
#include <unordered_map>

using namespace std;

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

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */