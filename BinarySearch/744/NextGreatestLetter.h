#include <vector>

using namespace std;

class Solution {
public:
    char nextGreatestLetter(vector<char>& letters, char target) {
        int left = 0;
        int right = letters.size() - 1;

        while (left < right)
        {
            int mid = left + (right - left) / 2;
            if (letters[mid] > target)
            {
                if (mid >= 1 && letters[mid - 1] > target)
                {
                    right = mid - 1;
                }
                else
                {
                    return letters[mid];
                }                
            }
            else
            {
                if (mid <= letters.size() - 2 && letters[mid + 1] > target)
                {
                    return letters[mid + 1];
                }
                else
                {
                    left = mid + 1;
                }   
            }            
        }

        return letters[0];
    }
};