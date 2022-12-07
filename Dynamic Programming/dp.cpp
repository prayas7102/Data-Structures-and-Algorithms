#include <iostream>
#include <vector>
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

int main()
{
    int n = 10;
    vector<int> dp(n + 1, -1);
    cout << n << "th fibbonacciNo using memoization " << fibbonacciNo(n, dp) << "\n\n";

    cout << n << "th fibbonacciNo using tabulation " << fibbonacciNoTabulation(n) << "\n\n";
    return 0;
}