// 4ms, 8.7MB

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
    ListNode* swapPairs(ListNode* head) {
        ListNode *result = new ListNode(0);
        ListNode *p = result;
        int k=0;
        vector<int> tmp(2, 0);
        while (head != NULL) {
            if (k == 2) {
                result->next = new ListNode(tmp[1]);
                result->next->next = new ListNode(tmp[0]);
                result = result->next->next;
                k = 0;
            }
            tmp[k] = head->val; k++;
            head = head->next;
        }
        if (k == 2) {
            result->next = new ListNode(tmp[1]);
            result->next->next = new ListNode(tmp[0]);
            result = result->next->next;
            k = 0;
        }
        else if (k == 1)
            result->next = new ListNode(tmp[0]);
        return p->next;
    }
};