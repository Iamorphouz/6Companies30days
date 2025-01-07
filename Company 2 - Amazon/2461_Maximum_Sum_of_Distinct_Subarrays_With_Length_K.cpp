class Solution
{
public:
    long long maximumSubarraySum(vector<int> &nums, int k)
    {
        long long sum = 0, ans = 0;
        unordered_map<int, int> mp;
        if (k > nums.size())
            return 0;

        for (int i = 0; i < k; i++)
        {
            sum += nums[i];
            mp[nums[i]]++;
        }

        if (k == mp.size())
            ans = sum;

        for (int i = k; i < nums.size(); i++)
        {
            mp[nums[i]]++;
            mp[nums[i - k]]--;

            if (mp[nums[i - k]] == 0)
                mp.erase(nums[i - k]);

            sum += nums[i];
            sum -= nums[i - k];

            if (k == mp.size())
                ans = max(ans, sum);
        }

        return ans;
    }
};