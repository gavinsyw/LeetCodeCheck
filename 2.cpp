// 16ms, 10.2MB

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* sum = new ListNode(0);
        ListNode* p = sum;
        int carrier = 0;
        while (l1 != NULL && l2 != NULL) {
            p = p->next = new ListNode((l1->val + l2->val + carrier) % 10);
            carrier = (l1->val + l2->val + carrier) / 10;
            l1 = l1->next;
            l2 = l2->next;
        } 
        while (l1 != NULL) {
            p = p->next = new ListNode((l1->val + carrier) % 10);
            carrier = (l1->val + carrier) / 10;
            l1 = l1->next;
        }
        while (l2 != NULL) {
            p = p->next = new ListNode((l2->val + carrier) % 10);
            carrier = (l2->val + carrier) / 10;
            l2 = l2->next;
        }
        if (carrier == 1) {
            p->next = new ListNode(1);
        }
        return sum->next;
    }
};