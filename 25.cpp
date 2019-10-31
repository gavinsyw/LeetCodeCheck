// 24ms, 10.6MB

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
    ListNode* reverseKGroup(ListNode* head, int k) {
        vector<int> tmp(k, 0);
        int cnt = 0;
        ListNode *result, *p;
        result = new ListNode(0); p = result;
        while (head != NULL) {
            if (cnt == k) {
                for (int i = k-1; i >= 0; --i) {
                    result->next = new ListNode(tmp[i]);
                    result = result->next;
                }
                cnt = 0;
            }
            tmp[cnt] = head->val; cnt++;
            head = head->next;
        }
        if (cnt == k) {
            for (int i = k-1; i >= 0; --i) {
                result->next = new ListNode(tmp[i]);
                result = result->next;
            }
        }
        else for (int i = 0; i < cnt; ++i) {
            result->next = new ListNode(tmp[i]);
            result = result->next;
        }
        return p->next;
    }
};