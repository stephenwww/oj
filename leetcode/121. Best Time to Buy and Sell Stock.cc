// Copyright 2017 Qi Wang
// Date: 2017-11-06
// Case 1: [1, 2, 3]
// Case 2: [2, 2, 1, 3]
class Solution {
 public:
  int maxProfit(vector<int>& prices) {
    if (prices.size() < 2) return 0;
    int cheapest_price = prices.front();
    int result = 0;
    for (int i = 1; i < prices.size(); ++i) {
      cheapest_price = min(cheapest_price, prices[i]);
      result = max(result, prices[i] - cheapest_price);
    }
    return result;
  }
};

// Date: 2017-07-21
class Solution {
 public:
  int maxProfit(vector<int>& prices) {
    if (prices.empty()) return 0;
    int result = 0;
    int lowest_price = prices.front();
    for (size_t i = 1; i < prices.size(); ++i) {
      result = max(result, prices[i] - lowest_price);
      lowest_price = min(lowest_price, prices[i]);
    }
    return result;
  }
};

// Date: 2016-10-06
class Solution {
 public:
  int maxProfit(vector<int>& prices) {
    if (prices.size() <= 1) return 0;
    int res = 0, highestSellPrice = 0;
    for (int i = prices.size() - 1; i >= 0; --i) {
      highestSellPrice = max(prices[i], highestSellPrice);
      res = max(res, highestSellPrice - prices[i]);
    }
    return res;
  }
};

// Date: 2014-08
class Solution 
{
public:
    int maxProfit(vector<int> &prices) 
    {
      if(prices.empty())
      {
        return 0;
      }

        int max_price = prices.back();
        int max_profit = 0;
        for (int i = int(prices.size())-1; i >= 0; -- i)
        {
          max_price = max(max_price, prices[i]);
          max_profit = max(max_profit, max_price-prices[i]);
        }
        return max_profit;
    }
};