// LeetCode URL : https://leetcode.com/problems/longest-strictly-increasing-or-strictly-decreasing-subarray/description/?envType=daily-question&envId=2025-02-03

class Solution {
public:
    int longestMonotonicSubarray(vector<int>& nums) {
        int max_subarray_length = 1;
        int increase_subarray_length = 1;
        int decrease_subarray_length = 1;
        for (int i = 1 ; i < nums.size() ; i++)
        {
            if(nums[i] > nums[i-1])
            {
                increase_subarray_length++;
                decrease_subarray_length = 1;
            }
            else if (nums[i] < nums[i-1])
            {
                decrease_subarray_length++;
                increase_subarray_length = 1;
            }
            else // nums[i] == nums[i-1]
            {
                decrease_subarray_length = 1;
                increase_subarray_length = 1;
            }
            max_subarray_length = std::max({max_subarray_length, increase_subarray_length, decrease_subarray_length});
        }

        return max_subarray_length;
    }
};
