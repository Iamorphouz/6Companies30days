class Solution
{
public:
    map<vector<int>, int> state;
    int shoppingOffers(vector<int> &price, vector<vector<int>> &special, vector<int> &needs)
    {
        if (state[needs])
            return state[needs];
        int bestPrice = priceWOOffers(price, needs);
        for (auto &sp : special)
        {
            applyOffer(sp, needs);
            if (noExcessBuy(needs))
            {
                int withOffer = sp.back() + shoppingOffers(price, special, needs);
                bestPrice = min(bestPrice, withOffer);
            }
            removeOffer(sp, needs);
        }

        state[needs] = bestPrice;
        return state[needs];
    }
    int priceWOOffers(vector<int> &price, vector<int> &needs)
    {
        int p = 0;
        for (int i = 0; i < price.size(); i++)
            p += price[i] * needs[i];

        return p;
    }
    // dec needs
    void applyOffer(vector<int> &special, vector<int> &needs)
    {
        for (int i = 0; i < needs.size(); i++)
            needs[i] -= special[i];
    }

    // inc needs
    void removeOffer(vector<int> &special, vector<int> &needs)
    {
        for (int i = 0; i < needs.size(); i++)
            needs[i] += special[i];
    }

    bool noExcessBuy(vector<int> &needs)
    {
        for (int x : needs)
            if (x < 0)
                return false;
        return true;
    }
};