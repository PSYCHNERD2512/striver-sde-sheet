#include <bits/stdc++.h>
using namespace std;

void helper(vector<int> &arr, vector<int> &currArr, vector<vector<int>> &ans, int t, int s = 0, int i = 0)
{
    if (s == t)
    {
        ans.push_back(currArr);
        return;
    }
    else if (i == arr.size() || s > t)
        return;
    else
    {
        currArr.push_back(arr[i]);
        helper(arr, currArr, ans, t, s + arr[i], i);
        currArr.pop_back();
        helper(arr, currArr, ans, t, s, i + 1);
    }
    return;
}
int main()
{
    int n, t;
    cin >> n >> t;
    vector<int> arr(n);
    for (auto &it : arr)
        cin >> it;
    vector<vector<int>> ans;
    vector<int> currArr;
    sort(arr.begin(),arr.end());
    helper(arr, currArr, ans, t);
    cout << "arrays with sum equal to target are" << endl;
    for (auto &a : ans)
    {
        for (auto &it : a)
        {
            cout << it << " ";
        }
        cout << endl;
    }
}