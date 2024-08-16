class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        
        ListNode* dummy = new ListNode(-1);
        ListNode* curr = dummy;
        int carry = 0, val1 = 0, val2 = 0, sum = 0;

        while(l1 || l2 || carry){

            val1 = l1 ? l1->val : 0;
            val2 = l2 ? l2->val : 0;

            sum = val1 + val2 + carry;
            carry = sum/10;
            sum = sum%10;

            ListNode* node = new ListNode(sum);
            curr->next = node;
            curr = node;

            if(l1){
                l1 = l1->next;
            }

            if(l2){
                l2 = l2->next;
            }
        }

        return dummy->next;
    }
};