class Solution {
public:
    vector<int> deckRevealedIncreasing(vector<int>& deck) {

        vector<int>ans(deck.size(),0);

        sort(deck.begin(),deck.end());

        bool skip = false;
        int indexInDeck = 0;
        int indexInAns = 0;

        while(indexInDeck < deck.size())
        {
            if(ans[indexInAns] == 0)
            {
                if(!skip)
                {
                    ans[indexInAns] = deck[indexInDeck];
                    indexInDeck++;
                }
                skip = !skip;
            }
            indexInAns = (indexInAns + 1)%deck.size();
        }
        return ans;
        

    }
};