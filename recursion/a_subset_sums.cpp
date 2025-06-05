#include <bits/stdc++.h>
using namespace std;
void helper(vector<int> &arr, vector<int> &ans, int i = 0, int sum = 0)
{
    if (i == arr.size())
    {
        ans.push_back(sum);
    }
    else
    {
        helper(arr, ans, i + 1, sum + arr[i]);
        helper(arr, ans, i + 1, sum);
    }
}
int main()
{
    int n;
    cin >> n;
    vector<int> arr(n);
    for (auto &it : arr)
        cin >> it;
    vector<int> ans;
    helper(arr, ans);
    cout << "all possible sums are" << endl;
    for (auto &it : ans)
        cout << it << endl;
}