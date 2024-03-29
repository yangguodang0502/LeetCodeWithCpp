/** 
 * Forward declaration of guess API.
 * @param  num   your guess
 * @return 	     -1 if num is lower than the guess number
 *			      1 if num is higher than the guess number
 *               otherwise return 0
 * ;
 */

class Solution {
public:
    int guessNumber(int n) {
        int left = 1;
        int right = n;

        while (left <= right)
        {
            int mid = left + (right - left) / 2;
            int val = guess(mid);
            if (val == 0)
            {
                return mid;
            }
            else if (val < 0)
            {
                right = mid - 1;
            }
            else
            {
                left = mid + 1;
            }            
        }
        
        return -1;
    }
};