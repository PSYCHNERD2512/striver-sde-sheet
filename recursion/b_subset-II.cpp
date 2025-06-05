#include <bits/stdc++.h>
using namespace std;
void helper(vector<int> &arr, vector<vector<int>> &ans, vector<int> &currArr, int i = 0)
{
    if (i >= arr.size())
        ans.push_back(currArr);
    else
    {
        currArr.push_back(arr[i]);
        helper(arr, ans, currArr, i + 1);
        currArr.pop_back();
        while (i + 1 < arr.size() && arr[i + 1] == arr[i])
        {
            i++;
        }
        helper(arr, ans, currArr, i + 1);
    }
}
int main()
{
    int n;
    cin >> n;
    vector<int> arr(n);
    for (auto &it : arr)
        cin >> it;
    vector<vector<int>> ans;
    vector<int> currArr;
    sort(arr.begin(), arr.end());
    helper(arr, ans, currArr);
    cout << "all subsets are" << endl;
    for (auto &a : ans)
    {
        for (auto &it : a)
        {
            cout << it << " ";
        }
        cout << endl;
    }
}