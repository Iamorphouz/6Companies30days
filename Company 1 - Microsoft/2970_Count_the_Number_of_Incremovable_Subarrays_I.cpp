class Solution
{
public:
    int incremovableSubarrayCount(vector<int> &nums)
    {
        int n = nums.size();
        // vector<vector<int>> subs;
        int ans = 0;
        for (int i = 0; i < n; i++)
        {
            for (int j = i; j < n; j++)
            {

                int last = -1;
                bool flag = 1;

                for (int k = 0; k < n; k++)
                {

                    if (k >= i && k <= j)
                    {
                        // skip
                        continue;
                    }
                    else
                    {
                        if (last < nums[k])
                        {
                            last = nums[k];
                        }
                        else
                        {
                            flag = 0;
                            break;
                        }
                    }
                }

                ans += flag;
            }
        }
        return ans;
    }
};