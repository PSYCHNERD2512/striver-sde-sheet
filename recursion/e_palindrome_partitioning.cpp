#include <bits/stdc++.h>
using namespace std;
bool isPalindrome(string s)
{
    if (s.size() == 0)
        return false;
    int l = 0, r = s.size() - 1;
    while (l <= r)
    {
        if (s[l] == s[r])
        {
            l++;
            r--;
        }
        else
        {
            return false;
        }
    }
    return true;
}
void helper(string s, vector<string> &currArr, vector<vector<string>> &ans, int i = 0)
{
    if (i == s.size())
        ans.push_back(currArr);
    else
    {
        for (int id = i; id < s.size(); id++)
        {
            if (isPalindrome(s.substr(i, id - i + 1)))
            {
                currArr.push_back(s.substr(i, id - i + 1));
                helper(s, currArr, ans, id + 1);
                currArr.pop_back();
            }
        }
    }
}
int main()
{
    string s;
    cin >> s;
    vector<vector<string>> ans;
    vector<string> currArr;
    helper(s, currArr, ans);
    for (auto &a : ans)
    {
        for (auto &it : a)
        {
            cout << it << " ";
        }
        cout << endl;
    }
}