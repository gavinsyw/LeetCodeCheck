// 4ms, 9.6MB

class Solution {
public:
    int longestValidParentheses(string s)  {
        stack<int> stk;
        int maxLength = 0;
        stk.push(-1);
        for (int i=0; i < s.size(); ++i) {
            if (s[i] == '(')
                stk.push(i);
            else {
                stk.pop();
                if (!stk.empty())
                    maxLength = max(maxLength, i-stk.top());
                else
                    stk.push(i);
            }
        }
        return maxLength;
    }
};