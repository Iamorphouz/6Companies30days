class Solution
{
public:
    int solve(int day, int buy, int cap, int n, vector<int> &prices, vector<vector<vector<int>>> &dp)
    {
        if (cap == 0)
            return 0;
        if (day == n)
            return 0;

        if (dp[day][buy][cap] != -1)
            return dp[day][buy][cap];

        int profit = 0;
        if (buy)
        {
            profit = max(-prices[day] + solve(day + 1, 0, cap, n, prices, dp),
                         0 + solve(day + 1, 1, cap, n, prices, dp));
        }
        else
        {
            profit = max(prices[day] + solve(day + 1, 1, cap - 1, n, prices, dp),
                         0 + solve(day + 1, 0, cap, n, prices, dp));
        }

        return dp[day][buy][cap] = profit;
    }
    int maxProfit(int k, vector<int> &prices)
    {
        int n = prices.size();
        vector<vector<vector<int>>> dp(n, vector<vector<int>>(2, vector<int>(k + 1, -1)));
        return solve(0, 1, k, n, prices, dp);
    }
};