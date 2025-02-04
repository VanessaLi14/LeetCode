// LeetCode URL : https://leetcode.com/problems/maximum-ascending-subarray-sum/submissions/1531165638/?envType=daily-question&envId=2025-02-04

class Solution {
public:
    int maxAscendingSum(vector<int>& nums) {
        int max_sum = nums[0];
        int temp_sum = nums[0];
        for (int i = 1 ; i < nums.size() ; i++)
        {
            if (nums[i] > nums[i-1])
                temp_sum += nums[i];
            else
                temp_sum = nums[i];

            max_sum = std::max(max_sum, temp_sum);
        }
        return max_sum;
    }
};
