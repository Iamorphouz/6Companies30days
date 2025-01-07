
#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    void matchPairs(int n, char nuts[], char bolts[])
    {
        // code here
        string order = "!#$%&*?@^";
        unordered_set<char> nutSet(nuts, nuts + n);

        int i = 0;
        for (char ch : order)
        {

            if (nutSet.count(ch))
            {
                nuts[i] = ch;
                bolts[i] = ch;
                i++;
            }
        }
    }
};
