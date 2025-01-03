class Solution
{
public:
    vector<string> findRepeatedDnaSequences(string s)
    {
        if (s.size() < 10)
            return {};
        unordered_map<string, int> mp;
        vector<string> ans;
        for (int i = 0; i <= s.length() - 10; i++)
        {
            string key = "";
            for (int j = 0; j < 10; j++)
            {
                key += s[i + j];
            }
            mp[key] += 1;
            if (mp[key] == 2)
                ans.push_back(key);
        }

        return ans;
    }
};