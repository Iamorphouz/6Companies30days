class Solution
{
public:
    void wiggleSort(vector<int> &nums)
    {
        vector<int> sorted = nums;
        ranges::sort(sorted);
        // for(int i = 0, j = 0, k = (nums.size() + 1) / 2; i < nums.size(); i++){
        //     nums[i] = sorted[(i & 1) ? k++:j++];
        // }  fails at case  [4,5,5,6]
        int n = nums.size();
        for (int i = n - 1, j = 0, k = (n + 1) / 2; i >= 0; i--)
        {
            nums[i] = sorted[(i & 1) ? k++ : j++];
        }
    }
};