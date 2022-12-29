#include <bits/stdc++.h>
using namespace std;

// recursive
int frogJump(int n, vector<int> &heights)
{
    if (n == 1)
        return 0;
    if (n == 2)
        return abs(heights[1] - heights[0]);
    int op1 = frogJump(n - 1, heights) + abs(heights[n - 1] - heights[n - 2]);
    int op2 = frogJump(n - 2, heights) + abs(heights[n - 1] - heights[n - 3]);
    return min(op1, op2);
}

// memoization
int frogJumpmem(int n, vector<int> &heights, vector<int> &dp)
{
    if (n == 1)
        return dp[n] = 0;
    if (n == 2)
        return dp[n] = abs(heights[1] - heights[0]);
    if (dp[n] != -1)
        return dp[n];
    int op1 = frogJumpmem(n - 1, heights, dp) + abs(heights[n - 1] - heights[n - 2]);
    int op2 = frogJumpmem(n - 2, heights, dp) + abs(heights[n - 1] - heights[n - 3]);
    return dp[n] = min(op1, op2);
}

int frogJump(int n, vector<int> &heights)
{
    vector<int> dp(n + 1, -1);
    return frogJumpmem(n, heights, dp);
}

// tabulation
int frogJump(int n, vector<int> &heights)
{
    vector<int> dp(n + 1, 0);
    dp[1] = 0;
    dp[2] = abs(heights[1] - heights[0]);
    for (int i = 3; i <= n; i++)
    {
        int op1 = dp[i - 1] + abs(heights[i - 1] - heights[i - 2]);
        int op2 = dp[i - 2] + abs(heights[i - 1] - heights[i - 3]);
        dp[i] = min(op1, op2);
    }
    return dp[n];
}

int main()
{
    int n{0};
    cin >> n;
    vector<int> heights(n);
    for (int i = 0; i < n; i++)
    {
        cin >> heights[i];
    }
    cout << frogJump(n, heights) << endl;
}