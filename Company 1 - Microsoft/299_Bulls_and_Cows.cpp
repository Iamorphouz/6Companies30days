class Solution
{
public:
    string getHint(string secret, string guess)
    {
        vector<int> fs(10, 0), fg(10, 0);

        int bull = 0, cow = 0;
        for (int i = 0; i < guess.length(); i++)
            if (secret[i] == guess[i])
            {
                bull += 1;
            }
            else
            {
                fs[secret[i] - '0'] += 1;
                fg[guess[i] - '0'] += 1;
            }

        for (int i = 0; i < 10; i++)
            cow += min(fs[i], fg[i]);

        string ans = to_string(bull) + "A" + to_string(cow) + "B";
        return ans;
        /*
        vector<int> freq(10, 0);
        for(char &ch: secret)
            freq[ch - '0'] += 1;

        int bull = 0, cow = 0;
        for(int i = 0; i < guess.length(); i++)
            if(secret[i] == guess[i]){
                bull += 1;
                freq[guess[i] - '0'] -= 1;
            }

        for(int i = 0; i < guess.length(); i++)
            if(secret[i] != guess[i] && freq[guess[i] - '0'] > 0){
                    cow += 1;
                    freq[guess[i] - '0'] -= 1;
            }

        string ans = to_string(bull) + "A" + to_string(cow) + "B";
        return ans;
        */
    }
};