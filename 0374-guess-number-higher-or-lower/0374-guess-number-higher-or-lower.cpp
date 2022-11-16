/** 
 * Forward declaration of guess API.
 * @param  num   your guess
 * @return 	     -1 if num is higher than the picked number
 *			      1 if num is lower than the picked number
 *               otherwise return 0
 * int guess(int num);
 */

class Solution {
public:
    int guessNumber(int n) {
        int i = 0, j = n;
        while(i <= j){
            int mid = (i + j*1LL) >> 1;
            int k = guess(mid);
            if(k==-1)j = mid - 1;
            else if(k == 1)i = mid + 1;
            else return mid;
        }
        return 0;
    }
};