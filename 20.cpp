// 0ms, 8.6MB

class Solution {
public:
    bool isValid(string s) {
        stack<int> parenthesStack;
        parenthesStack.push(-1);
        for (char c:s) {
            int k;
            switch (c) {
                case '(':
                    parenthesStack.push(0);
                    break;
                case '[':
                    parenthesStack.push(1);
                    break;
                case '{':
                    parenthesStack.push(2);
                    break;
                case ')':
                    k = parenthesStack.top();
                    if (k != 0)
                        return false;
                    parenthesStack.pop();
                    break;
                case ']':
                    k = parenthesStack.top();
                    if (k != 1)
                        return false;
                    parenthesStack.pop();
                    break;
                case '}':
                    k = parenthesStack.top();
                    if (k != 2)
                        return false;
                    parenthesStack.pop();
                    break;
            }
        }
        if (parenthesStack.size() > 1)
            return false;
        return true;
    } 
};