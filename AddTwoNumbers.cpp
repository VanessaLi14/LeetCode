/**
 * Description :
 * You are given two non-empty linked lists representing two non-negative integers.
 * The digits are stored in reverse order, and each of their nodes contains a single digit.
 * Add the two numbers and return the sum as a linked list.

 * You may assume the two numbers do not contain any leading zero, except the number 0 itself.
 */

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode *ans = new ListNode ();
        ListNode *list1Ptr = l1, *list2Ptr = l2, *currentAns = ans;
        int carry = 0;
        
        while (list1Ptr != NULL || list2Ptr != NULL){
            // get num
            int x = (list1Ptr != NULL) ? list1Ptr->val : 0;                
            int y = (list2Ptr != NULL) ? list2Ptr->val : 0;
            
            // calculate sum and carry
            int sum = x + y + carry;
            carry = sum / 10;
            
            // put sum into ans list
            currentAns->next = new ListNode(sum % 10);
            currentAns = currentAns->next;                      
            
            // ptr to next
            if (list1Ptr != NULL) list1Ptr = list1Ptr->next; 
            if (list2Ptr != NULL) list2Ptr = list2Ptr->next;
            
            // add carry to list in case of one at the end
            if (carry > 0)
                currentAns->next = new ListNode (carry);     
        }
        return ans->next; 
    }
};
