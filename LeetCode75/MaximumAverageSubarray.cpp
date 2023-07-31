/* You are given an integer array nums consisting of n elements, and an integer k.
 * 
 * Find a contiguous subarray whose length is equal to k that has the maximum average value 
 * and return this value. Any answer with a calculation error less than 10-5 will be accepted.
 */

class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        double max_value = 0;
        for (int i = 0 ; i < k ; i++)
            max_value += nums[i];

        double temp_value = max_value;
        for (int i = k ; i < nums.size() ; i++)
        {
            temp_value = temp_value - nums[i-k] + nums[i];
            if (temp_value > max_value) max_value = temp_value;
        }

        return max_value/k;
    }
};

#if 0 
思路 :
  [0 1 2 3 4 5 6 7 8] , k = 4
  --------  > 加起來前四個當作目前最大值
    -------- > 減頭加尾後，和目前最大值比較
#endif
