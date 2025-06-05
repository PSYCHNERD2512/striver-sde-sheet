#include <bits/stdc++.h>
using namespace std;
int main()
{
    vector<int> coins = {1, 2, 5, 10, 20, 50, 100, 500, 1000};
    int v;
    cin >> v;
    int val = 0;
    int coin = 0;
    int i = coins.size() - 1;
    while (i >= 0 && val != v)
    {
        if (coins[i] <= v - val)
        {
            coin++;
            val += coins[i];
        }
        else
        {
            i--;
        }
    }
    cout<<"coins needed are "<<coin<<endl;
}