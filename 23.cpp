// 24ms, 11.8MB

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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        vector<int> resultVec;
        for (int i = 0; i < lists.size(); ++i) {
            ListNode* p = lists[i];
            while (p != NULL) {
                resultVec.push_back(p->val);
                p = p->next;
            }
        }
        sort(resultVec.begin(), resultVec.end());
        ListNode *result = new ListNode(0);
        ListNode *p = result;
        for (int i = 0; i < resultVec.size(); ++i) {
            result->next = new ListNode(resultVec[i]);
            result = result->next;
        }
        return p->next;
    }
};