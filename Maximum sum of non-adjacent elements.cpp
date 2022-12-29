#include <bits/stdc++.h>
using namespace std;

// recursive
int maximumNonAdjacentSumrec(int n, vector<int> &nums)
{
    if (n == 0)
        return 0;
    if (n == 1)
        return nums[0];
    int op1 = maximumNonAdjacentSumrec(n - 1, nums);
    int op2 = maximumNonAdjacentSumrec(n - 2, nums) + nums[n - 1];
    return max(op1, op2);
}

int maximumNonAdjacentSum(vector<int> &nums)
{
    int n = nums.size();
    return maximumNonAdjacentSumrec(n, nums);
}

// memoization
int maximumNonAdjacentSummem(int n, vector<int> &nums, vector<int> &dp)
{
    if (n == 0)
        return dp[n] = 0;
    if (n == 1)
        return dp[n] = nums[0];
    if (dp[n] != -1)
        return dp[n];
    int op1 = maximumNonAdjacentSummem(n - 1, nums, dp);
    int op2 = maximumNonAdjacentSummem(n - 2, nums, dp) + nums[n - 1];
    return dp[n] = max(op1, op2);
}

int maximumNonAdjacentSum(vector<int> &nums)
{
    int n = nums.size();
    vector<int> dp(n + 1, -1);
    return maximumNonAdjacentSummem(n, nums, dp);
}

// tabulation
int maximumNonAdjacentSum(vector<int> &nums)
{
    int n = nums.size();
    vector<int> dp(n + 1, 0);
    dp[0] = 0;
    dp[1] = nums[0];
    for (int i = 2; i <= n; i++)
    {
        int op1 = dp[i - 1];
        int op2 = dp[i - 2] + nums[i - 1];
        dp[i] = max(op1, op2);
    }
    return dp[n];
}

// space optimized tabulation
int maximumNonAdjacentSum(vector<int> &nums)
{
    int n = nums.size();
    int a = 0;
    int b = nums[0];
    for (int i = 2; i <= n; i++)
    {
        int c = max(b, a + nums[i - 1]);
        a = b;
        b = c;
    }
    return b;
}

int main()
{
    int n;
    cin >> n;
    vector<int> nums(n);
    for (int i = 0; i < n; i++)
    {
        cin >> nums[i];
    }
    cout << maximumNonAdjacentSum(nums) << endl;
}