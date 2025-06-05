#include <bits/stdc++.h>
using namespace std;

void helper(vector<int> &arr, vector<vector<int>> &ans, vector<int> &currArr, int t, int i = 0, int s = 0)
{
    if (s == t)
    {
        ans.push_back(currArr);
    }
    else if (s > t || i >= arr.size())
    {
    }
    else
    {
        currArr.push_back(arr[i]);
        helper(arr, ans, currArr, t, i + 1, s + arr[i]);
        currArr.pop_back();
        while (i + 1 < arr.size() && arr[i + 1] == arr[i])
        {
            i++;
        }
        helper(arr, ans, currArr, t, i + 1, s);
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
    sort(arr.begin(), arr.end());
    vector<vector<int>> ans;
    vector<int> currArr;
    helper(arr, ans, currArr, t);
    cout << "all subsets with sum equal to target are" << endl;
    for (auto &a : ans)
    {
        for (auto &it : a)
        {
            cout << it << " ";
        }
        cout << endl;
    }
}