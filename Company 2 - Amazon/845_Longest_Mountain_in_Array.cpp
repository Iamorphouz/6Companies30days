class Solution
{
public:
    int longestMountain(vector<int> &arr)
    {
        int n = arr.size();
        int ans = 0;
        int up, down;
        int i = 1; // to cmp with i - 1;

        while (i < n)
        {
            up = 0, down = 0;
            while (i < n && arr[i - 1] == arr[i])
                i++;

            while (i < n && arr[i - 1] < arr[i])
                up++, i++;

            while (i < n && arr[i - 1] > arr[i])
                down++, i++;

            if (up && down)
            {
                ans = max(ans, up + down + 1);
            }
        }

        return ans;
    }
};