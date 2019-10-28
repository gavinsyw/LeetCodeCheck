// 4ms, 8.5MB

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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* p = head;
        ListNode* mark[10000];
        int total_cnt = 0;
        while (p != NULL) {
            mark[total_cnt] = p;
            p = p -> next;
            total_cnt += 1;
        }
        if (n == total_cnt) {
            return head->next;
        }
        else {
            p = mark[total_cnt-n];
            ListNode* q = mark[total_cnt-n-1];
            q->next = p->next;
            return head;
        }
    }
};