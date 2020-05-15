#include <vector>

using namespace std;

class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        vector<int> ret;
        if (x <= arr[0])
        {
            ret.assign(arr.begin(), arr.begin() + k);
            return ret;
        }
        else if (x >= arr[arr.size() - 1])
        {
            ret.assign(arr.end() - k, arr.end());
            return ret;
        }
        else
        {
            int low = 0;
            int high = arr.size() - 1;
            int index = 0;
            while (low < high)
            {
                int mid = (low + high) / 2;
                if (arr[mid] == x)
                {
                    index = mid;
                    break;
                }
                else if (arr[mid] < x)
                {
                    if (arr[mid + 1] == x)
                    {
                        index = mid + 1;
                        break;
                    }
                    else if (arr[mid + 1] > x)
                    {
                        index = (arr[mid + 1] - x) < (x - arr[mid]) ? mid + 1 : mid;
                        break;
                    }
                    else
                    {
                        low = mid + 1;
                    }
                }
                else
                {
                    if (arr[mid - 1] == x)
                    {
                        index = mid - 1;
                        break;
                    }
                    else if (arr[mid - 1] < x)
                    {
                        index = (arr[mid] - x) <= (x - arr[mid - 1]) ? mid : mid - 1;
                        break;
                    }
                    else
                    {
                        high = mid - 1;
                    }
                }
            }
            
            int left = index - 1;
            int right = index + 1;
            while (right - left - 1 < k)
            {
                if (left < 0)
                {
                    right++;
                }
                else if (right >= arr.size())
                {
                    left--;
                }
                else if (x - arr[left] > arr[right] - x)
                {
                    right++;
                }
                else
                {
                    left--;
                }                
            }

            ret.assign(arr.begin() + left + 1, arr.begin() + right);
        }
        return ret;
    }
};