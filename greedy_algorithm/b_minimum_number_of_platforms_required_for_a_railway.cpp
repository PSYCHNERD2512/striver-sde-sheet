#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;
    vector<int> arr(n);
    vector<int> dept(n);
    for (int i = 0; i < n; i++)
    {
        int t1, t2;
        cin >> t1 >> t2;
        arr[i] = t1;
        dept[i] = t2;
    }
    sort(arr.begin(), arr.end());
    sort(dept.begin(), dept.end());
    int i = 0, j = 0;
    int platform = 0;
    int maxPlatform = 0;
    while (i < n || j < n)
    {
        if (i < n && j < n)
        {
            if (arr[i] < dept[j])
            {
                platform += 1;
                i++;
            }
            else
            {
                platform -= 1;
                j++;
            }
            maxPlatform = max(platform, maxPlatform);
        }
        else if (i < n)
        {
            platform += 1;
            maxPlatform = max(platform, maxPlatform);
            i++;
        }
        else if (j < n)
        {
            platform -= 1;
            maxPlatform = max(platform, maxPlatform);
            j++;
        }
    }
    cout << "platform required are " << maxPlatform << endl;
}