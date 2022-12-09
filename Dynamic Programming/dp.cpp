#include <iostream>
#include <vector>
#include <algorithm>
#include <limits.h>

using namespace std;

int fibbonacciNo(int n, vector<int> &dp)
{
    if (n <= 1)
        return n;
    if (dp[n] != -1)
        return dp[n];
    return dp[n] = fibbonacciNo(n - 1, dp) + fibbonacciNo(n - 2, dp);
}

int fibbonacciNoTabulation(int n)
{
    int prev = 0, prev2 = 1;
    int curr = 0;
    for (int i = 0; i < n - 1; ++i)
    {
        curr = prev2 + prev;
        prev = prev2;
        prev2 = curr;
    }
    return curr;
}

int frogJump(int ind, vector<int> &v, vector<int> dp)
{

    if (ind == 0)
    {
        return 0;
    }

    if (dp[ind] != -1)
        return dp[ind];

    int left = frogJump(ind - 1, v, dp) + abs(v[ind] - v[ind - 1]);

    int right = INT_MAX;

    if (ind > 1)
        right = frogJump(ind - 2, v, dp) + abs(v[ind] - v[ind - 2]);

    return dp[ind] = min(left, right);
}

int frogJumpTabulation(vector<int> &v, vector<int> dp)
{

    dp[0] = 0;
    int n = v.size();
    for (int i = 1; i < n; ++i)
    {
        int left = dp[i - 1] + abs(v[i] - v[i - 1]);

        int right = INT_MAX;

        if (i > 1)
            right = dp[i - 2] + abs(v[i] - v[i - 2]);

        dp[i] = min(left, right);
    }

    return dp[n - 1];
}

int main()
{
    int n = 10;
    vector<int> dp(n + 1, -1);
    cout << n << "th fibbonacciNo using memoization " << fibbonacciNo(n, dp) << "\n\n";

    cout << n << "th fibbonacciNo using tabulation " << fibbonacciNoTabulation(n) << "\n\n";

    vector<int> v{30, 10, 60, 10, 60, 50};
    int m = v.size();
    vector<int> dp1(m + 1, -1);
    cout << "minimum energy for frog jump (memoization): " << frogJump(m - 1, v, dp1) << "\n\n";
    cout << "minimum energy for frog jump (tabulation): " << frogJumpTabulation(v, dp1) << "\n\n";

    return 0;
}