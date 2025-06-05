#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, w;
    cin >> n >> w;
    vector<int> values;
    vector<int> weight;
    for (int i = 0; i < n; i++)
    {
        int v, wi;
        cin >> v >> wi;
        values.push_back(v);
        weight.push_back(wi);
    }
    vector<int> density;
    for (int i = 0; i < n; i++)
    {
        int d = values[i] / weight[i];
        density.push_back(d);
    }
    vector<pair<int, int>> obj;
    for (int i = 0; i < n; i++)
    {
        obj.push_back({density[i], weight[i]});
    }
    sort(obj.begin(), obj.end(), [](pair<int, int> a, pair<int, int> b)
         { return a.first > b.first; });
    int weightUsed = 0;
    int o = 0;
    int val = 0;
    while (o < n && weightUsed < w)
    {
        int weightAdd = min(w - weightUsed, obj[o].second);
        val += (weightAdd * obj[o].first);
        weightUsed += weightAdd;
        o++;
    }
    cout << "maximum profit is " << val << endl;
}