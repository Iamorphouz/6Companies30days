#include <vector>
using namespace std;

class Solution
{
public:
    int CountLessEqualGoal(vector<int> &nums, int k)
    {
        int l = 0, sum = 0, count = 0;

        for (int r = 0; r < nums.size(); r++)
        {
            sum += nums[r];

            while (sum > k)
            {
                sum -= nums[l];
                l++;
            }

            count += (r - l + 1);
        }
        return count;
    }
    int numberOfSubarrays(vector<int> &nums, int k)
    {
        int n = nums.size();

        for (int i = 0; i < n; i++)
        {
            if (nums[i] % 2)
            {
                nums[i] = 1;
            }
            else
            {
                nums[i] = 0;
            }
        }

        return CountLessEqualGoal(nums, k) - CountLessEqualGoal(nums, k - 1);
    }
};