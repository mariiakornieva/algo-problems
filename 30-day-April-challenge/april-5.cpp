/*
*   The Best Time to Buy and Sell Stock
*/

// Can buy/sell only once
class SolutionOneTransaction {
public:
    int maxProfit(vector<int>& prices) {
        int curProfit = 0;
        int maxProfit = 0;
        for (int i = 1; i < prices.size(); ++i) {
            int diff = prices[i] - prices[i-1];
            curProfit = std::max(curProfit + diff, diff);
            maxProfit = std::max(maxProfit, curProfit);
        }
        return maxProfit;
    }
};

// Can buy/sell multiple times
class SolutioniMultipleTransactions {
private:

public:
    int maxProfit(vector<int>& prices) {
        int maxProfit = 0;
        for (int i = 1; i < prices.size(); ++i) {
            int diff = prices[i] - prices[i-1];
            maxProfit += std::max(0, diff);
        }
        return maxProfit;
    }
};