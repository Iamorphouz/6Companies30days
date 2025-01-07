class Solution
{
public:
    string convertToTitle(int n)
    {
        string s;
        while (n > 0)
        {
            n--; // bcz we need value to be from 0 to 25 & not 1 to 26;
            s = char('A' + n % 26) + s;
            n /= 26;
        }
        return s;
    }
};
