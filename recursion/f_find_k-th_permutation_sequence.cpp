#include <bits/stdc++.h>
using namespace std;

void helper(vector<int> &checklist, int n, int k, int &ans, int number = 0, int digits = 0, int &count = *(new int(1)))
{
    if (digits == n)
    {
        if (count == k)
        {
            ans = number;
        }
        count++;
        return;
    }

    for (int i = 1; i <= n; i++)
    {
        if (checklist[i] == 0)
        {
            checklist[i] = 1;
            helper(checklist, n, k, ans, number * 10 + i, digits + 1, count);
            checklist[i] = 0;
        }
    }
}

int main()
{
    int n, k;
    cin >> n >> k;
    int ans = -1;
    vector<int> checklist(n + 1, 0);
    int count = 1;
    helper(checklist, n, k, ans, 0, 0, count);
    cout << ans << endl;
}
