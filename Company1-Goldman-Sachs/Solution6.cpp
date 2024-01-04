// Problem:https://leetcode.com/problems/letter-combinations-of-a-phone-number/

class Solution
{
public:
    void f(string digits, string ans, int idx, string *st, vector<string> &res)
    {
        if (idx >= digits.length())
        {
            res.push_back(ans);
            return;
        }
        int digIndex = digits[idx] - '0';
        string value = st[digIndex];
        for (int i = 0; i < value.length(); i++)
        {
            ans.push_back(value[i]);
            f(digits, ans, idx + 1, st, res);
            ans.pop_back();
        }
    }
    vector<string> letterCombinations(string digits)
    {
        vector<string> res;
        if (digits == "")
            return res;
        string st[10] = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
        string ans = "";
        f(digits, ans, 0, st, res);
        return res;
    }
};