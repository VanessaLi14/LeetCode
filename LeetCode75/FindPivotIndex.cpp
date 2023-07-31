/* Given an array of integers nums, calculate the pivot index of this array.
 * 
 * The pivot index is the index where the sum of all the numbers strictly to the left
 * of the index is equal to the sum of all the numbers strictly to the index's right.
 * 
 * If the index is on the left edge of the array, then the left sum is 0 because 
 * there are no elements to the left. This also applies to the right edge of the array.
 * 
 * Return the leftmost pivot index. If no such index exists, return -1.
 */

class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        int nums_sum = 0;
        for (auto num : nums) nums_sum += num;

        int left_sum = 0;
        for (int i = 0 ; i < nums.size () ; i++)
        {
            if (left_sum == nums_sum - left_sum - nums[i]) return i;
            left_sum += nums[i];
        }
        
        return -1;
    }
};

#if 0
思路 : 
先把全部的加起來，然後再從頭開始檢查。
只要左邊的總和 == 所有的總和-左邊的總和-pivot (這個就是右邊總和)
就取得答案了。
____ _ _______
left ^  right = (sum-left-pivot)
   pivot
#endif
