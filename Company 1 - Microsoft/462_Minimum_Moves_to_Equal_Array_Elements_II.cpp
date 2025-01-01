#include <vector>
#include <algorithm>
#include <ranges>

using namespace std;

class Solution
{
public:
    int minMoves2(vector<int> &nums)
    {
        // int sum = accumulate(nums.begin(), nums.end(), 0);
        sort(nums.begin(), nums.end());
        int n = nums.size();
        // int ideal = sum / n;
        int median = nums[n / 2]; // median --> two way inc / dec
        int ans = 0;
        for (int i = 0; i < n; i++)
            ans += abs(nums[i] - median);
        return ans;
    }
};