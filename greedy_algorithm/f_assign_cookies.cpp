#include <bits/stdc++.h>
using namespace std;

int main()
{
    int g, s;
    cin >> g >> s;
    vector<int> greed(g);
    vector<int> sizeOfCookies(s);
    for (auto &it : greed)
        cin >> it;
    for (auto &it : sizeOfCookies)
        cin >> it;
    sort(greed.begin(), greed.end());
    sort(sizeOfCookies.begin(), sizeOfCookies.end());
    int i = 0, j = 0;
    int satisfied = 0;
    while (i < g && j < s)
    {
        if (sizeOfCookies[j] >= greed[i])
        {
            satisfied++;
            i++;
            j++;
        }
        else
        {
            j++;
        }
    }
    cout << "number of children satisfied with cookies are " << satisfied << endl;
}