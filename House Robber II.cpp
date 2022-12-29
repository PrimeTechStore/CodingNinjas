#include <bits/stdc++.h>
using namespace std;

// // recursive
// long long int houseRobberrec(int n, vector<int> &nums)
// {
//     if (n == 0)
//         return 0;
//     if (n == 1)
//         return nums[0];
//     long long int op1 = houseRobberrec(n - 1, nums);
//     long long int op2 = houseRobberrec(n - 2, nums) + nums[n - 1];
//     return max(op1, op2);
// }

// long long int houseRobber(vector<int> &nums)
// {
//     if (nums.size() == 0)
//         return 0;
//     if (nums.size() == 1)
//         return nums[0];
//     vector<int> temp1, temp2;
//     for (int i = 0; i < nums.size(); i++)
//     {
//         cout << i;
//         if (i != 0)
//             temp1.push_back(nums[i]);
//         if (i != nums.size() - 1)
//             temp2.push_back(nums[i]);
//     }
//     long long int op1 = houseRobberrec(temp1.size(), temp1);
//     cout << "op1: " << temp1.size() << endl;
//     long long int op2 = houseRobberrec(temp2.size(), temp2);
//     cout << "op2: " << op2 << endl;
//     return max(op1, op2);
// }

// // memoization
// long long int houseRobberMemo(int n, vector<int> &nums, vector<long long int> &dp)
// {
//     if (n == 0)
//         return 0;
//     if (n == 1)
//         return nums[0];
//     if (dp[n] != -1)
//         return dp[n];
//     long long int op1 = houseRobberMemo(n - 1, nums, dp);
//     long long int op2 = houseRobberMemo(n - 2, nums, dp) + nums[n - 1];
//     return dp[n] = max(op1, op2);
// }

// long long int houseRobber(vector<int> &nums)
// {
//     if (nums.size() == 0)
//         return 0;
//     if (nums.size() == 1)
//         return nums[0];
//     vector<int> temp1, temp2;
//     for (int i = 0; i < nums.size(); i++)
//     {
//         if (i != 0)
//             temp1.push_back(nums[i]);
//         if (i != nums.size() - 1)
//             temp2.push_back(nums[i]);
//     }
//     vector<long long int> dp1(temp1.size() + 1, -1);
//     vector<long long int> dp2(temp2.size() + 1, -1);
//     long long int op1 = houseRobberMemo(temp1.size(), temp1, dp1);
//     long long int op2 = houseRobberMemo(temp2.size(), temp2, dp2);
//     return max(op1, op2);
// }

// // tabulation
// long long int houseRobber(vector<int> &nums)
// {
//     if (nums.size() == 0)
//         return 0;
//     if (nums.size() == 1)
//         return nums[0];
//     vector<int> temp1, temp2;
//     for (int i = 0; i < nums.size(); i++)
//     {
//         if (i != 0)
//             temp1.push_back(nums[i]);
//         if (i != nums.size() - 1)
//             temp2.push_back(nums[i]);
//     }
//     vector<long long int> dp1(temp1.size() + 1, -1);
//     vector<long long int> dp2(temp2.size() + 1, -1);
//     dp1[0] = 0;
//     dp1[1] = temp1[0];
//     dp2[0] = 0;
//     dp2[1] = temp2[0];
//     for (int i = 2; i <= temp1.size(); i++)
//     {
//         dp1[i] = max(dp1[i - 1], dp1[i - 2] + temp1[i - 1]);
//     }
//     for (int i = 2; i <= temp2.size(); i++)
//     {
//         dp2[i] = max(dp2[i - 1], dp2[i - 2] + temp2[i - 1]);
//     }
//     return max(dp1[temp1.size()], dp2[temp2.size()]);
// }

// tabulation space optimized

long long int houseRobber(vector<int> &nums)
{
    if (nums.size() == 0)
        return 0;
    if (nums.size() == 1)
        return nums[0];
    vector<int> temp1, temp2;
    for (int i = 0; i < nums.size(); i++)
    {
        if (i != 0)
            temp1.push_back(nums[i]);
        if (i != nums.size() - 1)
            temp2.push_back(nums[i]);
    }
    long long int dp1[2] = {0, temp1[0]};
    long long int dp2[2] = {0, temp2[0]};
    for (int i = 2; i <= temp1.size(); i++)
    {
        dp1[i % 2] = max(dp1[(i - 1) % 2], dp1[(i - 2) % 2] + temp1[i - 1]);
    }
    for (int i = 2; i <= temp2.size(); i++)
    {
        dp2[i % 2] = max(dp2[(i - 1) % 2], dp2[(i - 2) % 2] + temp2[i - 1]);
    }
    return max(dp1[temp1.size() % 2], dp2[temp2.size() % 2]);
}

int main()
{
    int n;
    cin >> n;
    vector<int> nums(n);
    for (int i = 0; i < n; i++)
        cin >> nums[i];
    cout << houseRobber(nums);
    return 0;
}