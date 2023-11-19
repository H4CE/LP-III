#include <bits/stdc++.h>
using namespace std;
using intl = long long int;
int dp[1001][1001];
int foo(int ind, int capacity, vector<int> &value, vector<int> &weight)
{
    if (ind >= value.size())
        return 0;
    if (capacity <= 0)
        return 0;
    int take = -1e9, noTake = -1e9;
    if (capacity >= weight[ind])
    {
        take = value[ind] + foo(ind + 1, capacity - weight[ind], value, weight);
    }
    noTake = foo(ind + 1, capacity, value, weight);
    return max(take, noTake);
}
int fooMemo(int ind, int capacity, vector<int> &value, vector<int> &weight)
{
    if (ind >= value.size())
        return 0;
    if (capacity <= 0)
        return 0;
    if (dp[ind][capacity] != -1)
        return dp[ind][capacity];
    int take = -1e9, noTake = -1e9;
    if (capacity >= weight[ind])
    {
        take = value[ind] + foo(ind + 1, capacity - weight[ind], value, weight);
    }
    noTake = foo(ind + 1, capacity, value, weight);
    return dp[ind][capacity] = max(take, noTake);
}
int fooTabuluated(vector<int> &value, vector<int> &weight, int capacity)
{
    int n = value.size();
    vector<vector<int>> dp1(n + 1, vector<int>(capacity + 1, 0));

    for (int i = n - 1; i >= 0; i--)
    {
        for (int j = 0; j <= capacity; j++)
        {
            int take = -1e9;
            if (j >= weight[i])
            {
                take = value[i] + dp1[i + 1][j - weight[i]];
            }
            int noTake = dp1[i + 1][j];
            dp1[i][j] = max(take, noTake);
        }
    }
    return dp1[0][capacity];
}
int knapsack(vector<int> &value, vector<int> &weight, int capacity)
{
    // memset(dp, -1, sizeof(dp));
    // return fooMemo(0, capacity, value, weight);
    return fooTabuluated(value, weight, capacity);
}
int main()
{
    vector<int> value = {60, 100, 120};
    vector<int> weight = {10, 20, 30};
    int capacity = 50;
    cout << knapsack(value, weight, capacity);
    return 0;
}