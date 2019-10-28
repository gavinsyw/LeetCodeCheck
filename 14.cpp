// 4ms, 11MB
class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        return longestPrefix(strs, 0, strs.size());
    }
    
    string longestPrefix(vector<string>& strs, int startP, int endP) {
        if (endP <= startP)
            return "";
        if (endP == startP + 1)
            return strs[startP];
        string leftPrefix = longestPrefix(strs, startP, (startP+endP)/2), rightPrefix = longestPrefix(strs, (startP+endP)/2, endP);
        string longPrefix = "";
        for (int i = 0; i < leftPrefix.length() && i < rightPrefix.length(); ++i)
            if (leftPrefix[i] == rightPrefix[i])
                longPrefix += leftPrefix[i];
            else
                break;
        return longPrefix;
    }
};