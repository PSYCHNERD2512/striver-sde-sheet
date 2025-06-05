#include <bits/stdc++.h>
using namespace std;
void helper(int n, vector<vector<int>> &used, vector<int> &col, vector<vector<string>> &ans, vector<string> &currArr, int q = 0)
{
    if (q == n)
    {
        ans.push_back(currArr);
        return;
    }
    else
    {
        for (int i = 0; i < n; i++)
        {
            string s(n, '.');
            int x = i;
            int y = q;
            if (col[x] == 0)
            {
                int possible = 1;
                for (int j = 0; j < used.size(); j++)
                {

                    if (abs(x - used[j][0]) == abs(y - used[j][1]))
                    {
                        possible = 0;
                        break;
                    }
                }
                if (possible)
                {
                    used.push_back({x, y});
                    s[x] = 'q';
                    currArr.push_back(s);
                    col[x] = 1;
                    helper(n, used, col, ans, currArr, q + 1);
                    used.pop_back();
                    currArr.pop_back();
                    col[x] = 0;
                }
            }
        }
    }
}
int main()
{
    int n;
    cin >> n;
    vector<vector<string>> ans;
    vector<string> currArr;
    vector<int> col(n);
    vector<vector<int>> used;
    helper(n, used, col, ans, currArr);
    for (auto &a : ans)
    {
        for (auto &it : a)
        {
            cout << it << " ";
        }
        cout << endl;
    }
}