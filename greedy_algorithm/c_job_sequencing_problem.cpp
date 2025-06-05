#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;
    vector<vector<int>> jobs;
    for (int i = 0; i < n; i++)
    {
        int id, d, p;
        cin >> id >> d >> p;
        jobs.push_back({id, d, p});
    }
    sort(jobs.begin(), jobs.end(), [](const vector<int> &a, const vector<int> &b)
         { return a[2] > b[2]; });
    int maxDeadline = 0;
    for (int i = 0; i < n; i++)
    {
        maxDeadline = max(maxDeadline, jobs[i][1]);
    }
    vector<int> days(maxDeadline + 1);
    int profit = 0;
    int jobsDone = 0;
    for (int i = 0; i < n; i++)
    {
        int day = jobs[i][1];
        for (int j = day; j > 0; j--)
        {
            if (days[j] == 0)
            {
                days[j] = jobs[i][0];
                jobsDone++;
                profit += jobs[i][2];
                break;
            }
        }
    }
    cout << "maximum profit is " << profit << ", " << "jobs done are " << jobsDone << endl;
}