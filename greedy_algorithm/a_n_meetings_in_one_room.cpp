#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    vector<int> start;
    vector<int> end;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        int x, y;
        cin >> x >> y;
        start.push_back(x);
        end.push_back(y);
    }
    vector<vector<int>> meetings;
    for (int i = 0; i < n; i++)
    {
        meetings.push_back({start[i], end[i], i + 1});
    }
    sort(meetings.begin(), meetings.end(), [](vector<int> a, vector<int> b)
         { return (b[1] >= a[1]); });
    int lastMeeting = -1;
    vector<int> meetsPossible;
    for (int i = 0; i < n; i++)
    {
        if (lastMeeting <= meetings[i][0])
        {
            lastMeeting = meetings[i][1];
            meetsPossible.push_back(meetings[i][2]);
        }
    }
    cout << "possible meetings are" << endl;
    for (int i = 0; i < meetsPossible.size(); i++)
    {
        cout << meetsPossible[i] << endl;
    }
}