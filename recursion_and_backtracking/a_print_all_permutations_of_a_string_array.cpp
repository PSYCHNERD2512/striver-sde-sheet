#include <bits/stdc++.h>
using namespace std;

void helper(vector<int> &nums, vector<int> &currArr, vector<vector<int>> &ans, vector<int> &tracker, int s = 0)
{
    if (s == nums.size())
    {
        ans.push_back(currArr);
        return;
    }
    else
    {
        for (int i = 0; i < nums.size(); i++)
        {
            if (!tracker[i])
            {
                currArr.push_back(nums[i]);
                tracker[i] = 1;
                helper(nums, currArr, ans, tracker, s + 1);
                tracker[i] = 0;
                currArr.pop_back();
            }
        }
    }
}
int main()
{
    int n;
    cin >> n;
    vector<int> nums(n);
    for (auto &it : nums)
        cin >> it;
    vector<vector<int>> ans;
    vector<int> currArr;
    vector<int> tracker(n);
    helper(nums, currArr, ans, tracker);
    for (auto &a : ans)
    {
        for (auto &it : a)
        {
            cout << it << " ";
        }
        cout << endl;
    }
}