/*
 * Description :
 * Given an array of integers nums and an integer target, return indices of the two numbers such that they add up to target.
 * You may assume that each input would have exactly one solution, and you may not use the same element twice.
 * You can return the answer in any order.
 */

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        map<int,int> dictionary; // <num, index>
        map<int,int>::iterator it;
        vector<int> ans;
        
        for (int index = 0 ; index < nums.size () ; index++){
            it = dictionary.find (target - nums[index]);
            
            if (it != dictionary.end ()) {
                ans.push_back (it->second);
                ans.push_back (index);
                return ans;
            }
            else{ // didn't find then put <num, index> into dictionary
                dictionary.insert({nums[index], index});
            }
        }
        return ans;
    }
};
