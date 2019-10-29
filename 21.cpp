// 8ms, 9.2MB

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
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        ListNode* p = new ListNode(0);
        ListNode* p1=l1, *p2=l2;
        ListNode* head = p;
        while (p1 != NULL && p2 != NULL) {
            if (p1->val > p2->val) {
                p->next = new ListNode(p2->val);
                p2 = p2->next;
            }
            else{
                p->next = new ListNode(p1->val);
                p1 = p1->next;
            }
            p = p->next;
        }
        while (p1 != NULL) {
            p->next = new ListNode(p1->val);
            p1 = p1->next;
            p = p->next;
        }
        while (p2 != NULL) {
            p->next = new ListNode(p2->val);
            p2 = p2->next;
            p = p->next;
        }
        return head->next;
    }
};