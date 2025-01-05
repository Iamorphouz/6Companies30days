class Solution
{
public:
    long long minimumCost(string source, string target, vector<char> &original, vector<char> &changed, vector<int> &cost)
    {
        const int INF = 1 << 29;                               //
        vector<vector<int>> convert(26, vector<int>(26, INF)); // O - 26 * 26
        for (int i = 0; i < 26; i++)
            convert[i][i] = 0;

        // min cost for direct convert
        for (int i = 0; i < original.size(); i++)
        { // O (original.size())  -> 2000
            int o = original[i] - 'a';
            int c = changed[i] - 'a';
            convert[o][c] = min(convert[o][c], cost[i]);
        }

        // ** Floyd-Warshall algorithm
        // min cost for indirect or multiple intermediate

        for (int k = 0; k < 26; k++) // 26 * 26 * 26 -> 17576
            for (int i = 0; i < 26; i++)
                for (int j = 0; j < 26; j++)
                    convert[i][j] = min(convert[i][j], convert[i][k] + convert[k][j]);
        // k -> i -> j bcz less access calls are made to [i][k]
        // cache effective than i -> j -> k

        long long ans = 0;
        for (int i = 0; i < source.size(); i++)
        { // O (source.size())  10^5
            int o = source[i] - 'a';
            int c = target[i] - 'a';

            if (o != c)
            { // not match
                if (convert[o][c] == INF)
                    return -1;
                ans += convert[o][c];
            }
        }

        // O(N)
        return ans;
    }
};