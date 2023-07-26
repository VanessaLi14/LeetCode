/*
 * Given two sorted arrays nums1 and nums2 of size m and n respectively, return the median of the two sorted arrays.
 * The overall run time complexity should be O(log (m+n)).
 */
class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        vector<int> merged_vector;
        vector<int>::iterator nums1_iter = nums1.begin();
        vector<int>::iterator nums2_iter = nums2.begin();
        int merged_vector_size = 0;

        while (nums1_iter != nums1.end() && nums2_iter != nums2.end())
        {
            if (*nums1_iter < *nums2_iter)
            {
                merged_vector.push_back(*nums1_iter);
                nums1_iter ++;
                merged_vector_size ++;
            }
            else if (*nums1_iter == *nums2_iter)
            {
                merged_vector.push_back(*nums1_iter);
                nums1_iter ++;
                merged_vector_size ++;
                merged_vector.push_back(*nums2_iter);
                nums2_iter ++;
                merged_vector_size ++;
            }
            else if (*nums1_iter > *nums2_iter)
            {
                merged_vector.push_back(*nums2_iter);
                nums2_iter ++;
                merged_vector_size ++;
            }
        }

        if (nums1_iter != nums1.end())
        {
            for (; nums1_iter != nums1.end() ; nums1_iter ++)
            {
                merged_vector.push_back(*nums1_iter);
                merged_vector_size ++;
            }
        }

        if (nums2_iter != nums2.end())
        {
            for (; nums2_iter != nums2.end() ; nums2_iter ++)
            {
                merged_vector.push_back(*nums2_iter);
                merged_vector_size ++;
            }
        }

        return merged_vector_size%2? merged_vector[merged_vector_size/2]:(merged_vector[merged_vector_size/2-1] + merged_vector[merged_vector_size/2])/2.0;

    }
};
