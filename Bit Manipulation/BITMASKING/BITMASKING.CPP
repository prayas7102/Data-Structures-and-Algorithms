#include <iostream>
#include <vector>
using namespace std;

// Question available at:: https://codeforces.com/blog/entry/73558
//  Bitmasking

int main()
{
    int n;
    cin >> n;
    vector<int> masks(n, 0);
    for (int i = 0; i < n; ++i)
    {
        int workers;
        cin >> workers;
        int mask = 0;
        for (int j = 0; j < workers; j++)
        {
            int day;
            cin >> day;
            mask = (mask | 1 << day);
        }
        masks[i] = mask;
    }
    int max_days = 0;
    for (int i = 0; i < n; ++i)
    {
        for (int j = i + 1; j < n; ++j)
        {
            int intersection = masks[i] & masks[j];
            int commondays = __builtin_popcount(intersection); // count no. of ones
            max_days = max(max_days, commondays);
        }
    }
    cout << max_days;
    return 0;
}